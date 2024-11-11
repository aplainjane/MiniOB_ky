/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/11/22.
//

#include <string.h>
#include <vector>

#include "common/io/io.h"
#include "common/log/log.h"
#include "event/session_event.h"
#include "session/session.h"
#include "net/buffered_writer.h"
#include "net/mysql_communicator.h"
#include "sql/operator/string_list_physical_operator.h"
#include "storage/db/db.h"
#include "storage/index/ivfflat_index.h"
#include <float.h>

/**
 * @brief MySQL协议相关实现
 * @defgroup MySQLProtocol
 */

// https://dev.mysql.com/doc/dev/mysql-server/latest/group__group__cs__capabilities__flags.html
// the flags below are negotiate by handshake packet
const uint32_t CLIENT_PROTOCOL_41 = 512;
// const uint32_t CLIENT_INTERACTIVE   = 1024;  // This is an interactive client
const uint32_t CLIENT_TRANSACTIONS  = 8192;         // Client knows about transactions.
const uint32_t CLIENT_SESSION_TRACK = (1UL << 23);  // Capable of handling server state change information
const uint32_t CLIENT_DEPRECATE_EOF = (1UL << 24);  // Client no longer needs EOF_Packet and will use OK_Packet instead
const uint32_t CLIENT_OPTIONAL_RESULTSET_METADATA =
    (1UL << 25);  // The client can handle optional metadata information in the resultset.
// Support optional extension for query parameters into the COM_QUERY and COM_STMT_EXECUTE packets.
// const uint32_t CLIENT_QUERY_ATTRIBUTES = (1UL << 27);

// https://dev.mysql.com/doc/dev/mysql-server/latest/group__group__cs__column__definition__flags.html
// Column Definition Flags
// const uint32_t NOT_NULL_FLAG  = 1;
// const uint32_t PRI_KEY_FLAG   = 2;
// const uint32_t UNIQUE_KEY_FLAG   = 4;
// const uint32_t MULTIPLE_KEY_FLAG = 8;
// const uint32_t NUM_FLAG          = 32768; // Field is num (for clients)
// const uint32_t PART_KEY_FLAG     = 16384; // Intern; Part of some key.

/**
 * @brief Resultset metadata
 * @details 这些枚举值都是从MySQL的协议中抄过来的
 * @ingroup MySQLProtocol
 */
enum ResultSetMetaData
{
  RESULTSET_METADATA_NONE = 0,
  RESULTSET_METADATA_FULL = 1,
};

/**
 * @brief Column types for MySQL
 * @details 枚举值类型是从MySQL的协议中抄过来的
 * @ingroup MySQLProtocol
 */
enum enum_field_types
{
  MYSQL_TYPE_DECIMAL,
  MYSQL_TYPE_TINY,
  MYSQL_TYPE_SHORT,
  MYSQL_TYPE_LONG,
  MYSQL_TYPE_FLOAT,
  MYSQL_TYPE_DOUBLE,
  MYSQL_TYPE_NULL,
  MYSQL_TYPE_TIMESTAMP,
  MYSQL_TYPE_LONGLONG,
  MYSQL_TYPE_INT24,
  MYSQL_TYPE_DATE,
  MYSQL_TYPE_TIME,
  MYSQL_TYPE_DATETIME,
  MYSQL_TYPE_YEAR,
  MYSQL_TYPE_NEWDATE, /**< Internal to MySQL. Not used in protocol */
  MYSQL_TYPE_VARCHAR,
  MYSQL_TYPE_BIT,
  MYSQL_TYPE_TIMESTAMP2,
  MYSQL_TYPE_DATETIME2,   /**< Internal to MySQL. Not used in protocol */
  MYSQL_TYPE_TIME2,       /**< Internal to MySQL. Not used in protocol */
  MYSQL_TYPE_TYPED_ARRAY, /**< Used for replication only */
  MYSQL_TYPE_INVALID     = 243,
  MYSQL_TYPE_BOOL        = 244, /**< Currently just a placeholder */
  MYSQL_TYPE_JSON        = 245,
  MYSQL_TYPE_NEWDECIMAL  = 246,
  MYSQL_TYPE_ENUM        = 247,
  MYSQL_TYPE_SET         = 248,
  MYSQL_TYPE_TINY_BLOB   = 249,
  MYSQL_TYPE_MEDIUM_BLOB = 250,
  MYSQL_TYPE_LONG_BLOB   = 251,
  MYSQL_TYPE_BLOB        = 252,
  MYSQL_TYPE_VAR_STRING  = 253,
  MYSQL_TYPE_STRING      = 254,
  MYSQL_TYPE_GEOMETRY    = 255
};

/**
 * @brief 根据MySQL协议的描述实现的数据写入函数
 * @defgroup MySQLProtocolStore
 * @note 当前仅考虑小端模式，所以当前的代码仅能运行在小端模式的机器上，比如Intel。
 */

/**
 * @brief 将数据写入到缓存中
 *
 * @param buf  数据缓存
 * @param value 要写入的值
 * @return int 写入的字节数
 * @ingroup MySQLProtocolStore
 */
int store_int1(char *buf, int8_t value)
{
  *buf = value;
  return 1;
}

/**
 * @brief 将数据写入到缓存中
 *
 * @param buf  数据缓存
 * @param value 要写入的值
 * @return int 写入的字节数
 * @ingroup MySQLProtocolStore
 */
int store_int2(char *buf, int16_t value)
{
  memcpy(buf, &value, sizeof(value));
  return 2;
}

/**
 * @brief 将数据写入到缓存中
 *
 * @param buf  数据缓存
 * @param value 要写入的值
 * @return int 写入的字节数
 * @ingroup MySQLProtocolStore
 */
int store_int3(char *buf, int32_t value)
{
  memcpy(buf, &value, 3);
  return 3;
}

/**
 * @brief 将数据写入到缓存中
 *
 * @param buf  数据缓存
 * @param value 要写入的值
 * @return int 写入的字节数
 * @ingroup MySQLProtocolStore
 */
int store_int4(char *buf, int32_t value)
{
  memcpy(buf, &value, 4);
  return 4;
}

/**
 * @brief 将数据写入到缓存中
 *
 * @param buf  数据缓存
 * @param value 要写入的值
 * @return int 写入的字节数
 * @ingroup MySQLProtocolStore
 */
int store_int6(char *buf, int64_t value)
{
  memcpy(buf, &value, 6);
  return 6;
}

/**
 * @brief 将数据写入到缓存中
 *
 * @param buf  数据缓存
 * @param value 要写入的值
 * @return int 写入的字节数
 * @ingroup MySQLProtocolStore
 */
int store_int8(char *buf, int64_t value)
{
  memcpy(buf, &value, 8);
  return 8;
}

/**
 * @brief 将数据写入到缓存中
 * @details 按照MySQL协议的描述，这是一个变长编码的整数，最大可以编码8个字节的整数。不同大小的数字，第一个字节的值不同。
 * @param buf  数据缓存
 * @param value 要写入的值
 * @return int 写入的字节数
 * @ingroup MySQLProtocolStore
 */
int store_lenenc_int(char *buf, uint64_t value)
{
  if (value < 251) {
    *buf = (int8_t)value;
    return 1;
  }

  if (value < (2UL << 16)) {
    *buf = 0xFC;
    memcpy(buf + 1, &value, 2);
    return 3;
  }

  if (value < (2UL << 24)) {
    *buf = 0xFD;
    memcpy(buf + 1, &value, 3);
    return 4;
  }

  *buf = 0xFE;
  memcpy(buf + 1, &value, 8);
  return 9;
}

/**
 * @brief 将以'\0'结尾的字符串写入到缓存中
 *
 * @param buf  数据缓存
 * @param s 要写入的字符串
 * @return int 写入的字节数
 * @ingroup MySQLProtocolStore
 */
int store_null_terminated_string(char *buf, const char *s)
{
  if (nullptr == s || s[0] == 0) {
    return 0;
  }

  const int len = strlen(s) + 1;
  memcpy(buf, s, len);
  return len;
}

/**
 * @brief 将指定长度的字符串写入到缓存中
 *
 * @param buf  数据缓存
 * @param s 要写入的字符串
 * @param len 字符串的长度
 * @return int 写入的字节数
 * @ingroup MySQLProtocolStore
 */
int store_fix_length_string(char *buf, const char *s, int len)
{
  if (len == 0) {
    return 0;
  }

  memcpy(buf, s, len);
  return len;
}

/**
 * @brief 按照带有长度标识的字符串写入到缓存，长度标识以变长整数编码
 *
 * @param buf  数据缓存
 * @param s 要写入的字符串
 * @return int 写入的字节数
 * @ingroup MySQLProtocolStore
 */
int store_lenenc_string(char *buf, const char *s)
{
  int len = static_cast<int>(strlen(s));
  int pos = store_lenenc_int(buf, len);
  store_fix_length_string(buf + pos, s, len);
  return pos + len;
}

/**
 * @brief 每个包都有一个包头
 * @details [MySQL Basic Packet](https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_basic_packets.html)
 * [MariaDB Packet](https://mariadb.com/kb/en/0-packet/)
 * @ingroup MySQLProtocol
 */
struct PacketHeader
{
  int32_t payload_length : 24;  //! 当前packet的除掉头的长度
  int8_t  sequence_id = 0;      //! 当前packet在当前处理过程中是第几个包
};

/**
 * @brief 所有的包都继承自BasePacket
 * @details 所有的包都有一个包头，所以BasePacket中包含了一个 @ref PacketHeader
 * @ingroup MySQLProtocol
 */
class BasePacket
{
public:
  PacketHeader packet_header;

  BasePacket(int8_t sequence = 0) { packet_header.sequence_id = sequence; }

  virtual ~BasePacket() = default;

  /**
   * @brief 将当前包编码成网络包
   *
   * @param[in] capabilities MySQL协议中的capability标志
   * @param[out] net_packet 编码后的网络包
   */
  virtual RC encode(uint32_t capabilities, vector<char> &net_packet) const = 0;
};

/**
 * @brief 握手包
 * @ingroup MySQLProtocol
 * @details 先由服务端发送到客户端。
 * 这个包会交互capability与用户名密码。
 * [MySQL
 * Handshake]https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_connection_phase_packets_protocol_handshake_v10.html
 */
struct HandshakeV10 : public BasePacket
{
  int8_t  protocol          = 10;
  char    server_version[7] = "5.7.25";
  int32_t thread_id         = 21501807;  // conn id
  char    auth_plugin_data_part_1[9] =
      "12345678";  // first 8 bytes of the plugin provided data (scramble) // and the filler
  int16_t capability_flags_1          = 0xF7DF;  // The lower 2 bytes of the Capabilities Flags
  int8_t  character_set               = 83;
  int16_t status_flags                = 0;
  int16_t capability_flags_2          = 0x0000;
  int8_t  auth_plugin_data_len        = 0;
  char    reserved[10]                = {0};
  char    auth_plugin_data_part_2[13] = "bbbbbbbbbbbb";

  HandshakeV10(int8_t sequence = 0) : BasePacket(sequence) {}
  virtual ~HandshakeV10() = default;

  /**
   * https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_connection_phase_packets_protocol_handshake_v10.html
   */
  virtual RC encode(uint32_t capabilities, vector<char> &net_packet) const override
  {
    net_packet.resize(100);

    char *buf = net_packet.data();
    int   pos = 0;
    pos += 3; // skip packet length

    pos += store_int1(buf + pos, packet_header.sequence_id);
    pos += store_int1(buf + pos, protocol);

    pos += store_null_terminated_string(buf + pos, server_version);
    pos += store_int4(buf + pos, thread_id);
    pos += store_null_terminated_string(buf + pos, auth_plugin_data_part_1);
    pos += store_int2(buf + pos, capability_flags_1);
    pos += store_int1(buf + pos, character_set);
    pos += store_int2(buf + pos, status_flags);
    pos += store_int2(buf + pos, capability_flags_2);
    pos += store_int1(buf + pos, auth_plugin_data_len);
    pos += store_fix_length_string(buf + pos, reserved, 10);
    pos += store_null_terminated_string(buf + pos, auth_plugin_data_part_2);

    int payload_length = pos - 4;
    store_int3(buf, payload_length);
    net_packet.resize(pos);
    LOG_TRACE("encode handshake packet with payload length=%d", payload_length);

    return RC::SUCCESS;
  }
};

/**
 * @brief 响应包，在很多场景中都会使用
 * @ingroup MySQLProtocol
 */
struct OkPacket : public BasePacket
{
  int8_t      header         = 0;  // 0x00 for ok and 0xFE for EOF
  int32_t     affected_rows  = 0;
  int32_t     last_insert_id = 0;
  int16_t     status_flags   = 0x22;
  int16_t     warnings       = 0;
  string      info;  // human readable status information

  OkPacket(int8_t sequence = 0) : BasePacket(sequence) {}
  virtual ~OkPacket() = default;

  /**
   * https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_basic_ok_packet.html
   */
  RC encode(uint32_t capabilities, vector<char> &net_packet) const override
  {
    net_packet.resize(100);
    char *buf = net_packet.data();
    int   pos = 0;

    pos += 3; // skip packet length
    pos += store_int1(buf + pos, packet_header.sequence_id);
    pos += store_int1(buf + pos, header);
    pos += store_lenenc_int(buf + pos, affected_rows);
    pos += store_lenenc_int(buf + pos, last_insert_id);

    if (capabilities & CLIENT_PROTOCOL_41) {
      pos += store_int2(buf + pos, status_flags);
      pos += store_int2(buf + pos, warnings);
    } else if (capabilities & CLIENT_TRANSACTIONS) {
      pos += store_int2(buf + pos, status_flags);
    }

    if (capabilities & CLIENT_SESSION_TRACK) {
      pos += store_lenenc_string(buf + pos, info.c_str());
    }

    int32_t payload_length = pos - 4;
    LOG_TRACE("encode ok packet with length=%d", payload_length);
    store_int3(buf, payload_length);
    net_packet.resize(pos);
    return RC::SUCCESS;
  }
};

/**
 * @brief EOF包
 * @ingroup MySQLProtocol
 * @details [basic_err_packet](https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_basic_err_packet.html)
 */
struct EofPacket : public BasePacket
{
  int8_t  header       = 0xFE;
  int16_t warnings     = 0;
  int16_t status_flags = 0x22;

  EofPacket(int8_t sequence = 0) : BasePacket(sequence) {}
  virtual ~EofPacket() = default;

  RC encode(uint32_t capabilities, vector<char> &net_packet) const override
  {
    net_packet.resize(10);
    char *buf = net_packet.data();
    int   pos = 0;

    pos += 3;
    store_int1(buf + pos, packet_header.sequence_id);
    pos += 1;
    store_int1(buf + pos, header);
    pos += 1;

    if (capabilities & CLIENT_PROTOCOL_41) {
      store_int2(buf + pos, warnings);
      pos += 2;
      store_int2(buf + pos, status_flags);
      pos += 2;
    }

    int payload_length = pos - 4;
    store_int3(buf, payload_length);
    net_packet.resize(pos);

    return RC::SUCCESS;
  }
};

/**
 * @brief ERR包，出现错误时返回
 * @details [eof_packet](https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_basic_eof_packet.html)
 * @ingroup MySQLProtocol
 */
struct ErrPacket : public BasePacket
{
  int8_t      header              = 0xFF;
  int16_t     error_code          = 0;
  char        sql_state_marker[1] = {'#'};
  string sql_state{"HY000"};
  string error_message;

  ErrPacket(int8_t sequence = 0) : BasePacket(sequence) {}
  virtual ~ErrPacket() = default;

  virtual RC encode(uint32_t capabilities, vector<char> &net_packet) const override
  {
    net_packet.resize(1000);
    char *buf = net_packet.data();
    int   pos = 0;

    pos += 3;

    store_int1(buf + pos, packet_header.sequence_id);
    pos += 1;
    store_int1(buf + pos, header);
    pos += 1;
    store_int2(buf + pos, error_code);
    pos += 2;
    if (capabilities & CLIENT_PROTOCOL_41) {
      pos += store_fix_length_string(buf + pos, sql_state_marker, 1);
      pos += store_fix_length_string(buf + pos, sql_state.c_str(), 5);
    }

    pos += store_fix_length_string(buf + pos, error_message.c_str(), error_message.length());

    int payload_length = pos - 4;
    store_int3(buf, payload_length);
    net_packet.resize(pos);
    return RC::SUCCESS;
  }
};

/**
 * @brief MySQL客户端发过来的请求包
 * @ingroup MySQLProtocol
 * @details [MySQL Protocol Command
 * Phase](https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_command_phase.html) [MariaDB Text
 * Protocol](https://mariadb.com/kb/en/2-text-protocol/)
 */
struct QueryPacket
{
  PacketHeader packet_header;
  int8_t       command;  // 0x03: COM_QUERY
  string  query;    // the text of the SQL query to execute
};

/**
 * @brief decode query packet
 * @details packet_header is not included in net_packet
 * [MySQL Protocol COM_QUERY](https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_com_query.html)
 */
RC decode_query_packet(vector<char> &net_packet, QueryPacket &query_packet)
{
  // query field is a null terminated string
  query_packet.query.assign(net_packet.data() + 1, net_packet.size() - 1);
  query_packet.query.append(1, ';');
  return RC::SUCCESS;
}

/**
 * @brief MySQL客户端连接时会发起一个"select @@version_comment"的查询，这里对这个查询进行特殊处理
 * @param[out] sql_result 生成的结果
 * @ingroup MySQLProtocol
 */
RC create_version_comment_sql_result(SqlResult *sql_result)
{
  TupleSchema   tuple_schema;
  TupleCellSpec cell_spec("", "", "@@version_comment");
  tuple_schema.append_cell(cell_spec);

  sql_result->set_return_code(RC::SUCCESS);
  sql_result->set_tuple_schema(tuple_schema);

  const char *version_comments = "MiniOB";

  StringListPhysicalOperator *oper = new StringListPhysicalOperator();
  oper->append(version_comments);
  sql_result->set_operator(unique_ptr<PhysicalOperator>(oper));
  return RC::SUCCESS;
}

/**
 * @brief MySQL链接做初始化，需要进行握手和一些预处理
 * @ingroup MySQLProtocol
 * @param fd 连接描述符
 * @param session 当前的会话
 * @param addr 对端地址
 */
RC MysqlCommunicator::init(int fd, unique_ptr<Session> session, const string &addr)
{
  // https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_connection_phase.html
  // 按照协议描述，服务端在连接建立后需要先向客户端发送握手信息
  RC rc = Communicator::init(fd, std::move(session), addr);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to init communicator: %s", strrc(rc));
    return rc;
  }

  HandshakeV10 handshake_packet;
  rc = send_packet(handshake_packet);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to send handshake packet to client. addr=%s, error=%s", addr.c_str(), strerror(errno));
    return rc;
  }

  writer_->flush();

  return rc;
}

/**
 * @brief MySQL客户端连接时会发起一个"select @@version_comment"的查询，这里对这个查询进行特殊处理
 *
 * @param[out] need_disconnect 连接上如果出现异常，通过这个标识来判断是否需要断开连接
 */
RC MysqlCommunicator::handle_version_comment(bool &need_disconnect)
{
  SessionEvent session_event(this);

  RC rc = create_version_comment_sql_result(session_event.sql_result());
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to handle version comment. rc=%s", strrc(rc));
    return rc;
  }

  rc = write_result(&session_event, need_disconnect);
  return rc;
}

/**
 * @brief 读取客户端发过来的请求
 *
 * @param[out] event 如果有新的请求，就会生成一个SessionEvent
 */
RC MysqlCommunicator::read_event(SessionEvent *&event)
{
  RC rc = RC::SUCCESS;

  /// 读取一个完整的数据包
  PacketHeader packet_header;

  int ret = common::readn(fd_, &packet_header, sizeof(packet_header));
  if (ret != 0) {
    LOG_WARN("failed to read packet header. length=%d, addr=%s. error=%s",
             sizeof(packet_header), addr_.c_str(), strerror(errno));
    return RC::IOERR_READ;
  }

  LOG_TRACE("read packet header. length=%d, sequence_id=%d, payload_length=%d, fd=%d",
            sizeof(packet_header), packet_header.sequence_id, packet_header.payload_length, fd_);
  sequence_id_ = packet_header.sequence_id + 1;

  vector<char> buf(packet_header.payload_length);
  ret = common::readn(fd_, buf.data(), packet_header.payload_length);
  if (ret != 0) {
    LOG_WARN("failed to read packet payload. length=%d, addr=%s, error=%s", 
             packet_header.payload_length, addr_.c_str(), strerror(errno));
    return RC::IOERR_READ;
  }

  event = nullptr;
  if (!authed_) {
    /// 还没有做过认证，就先需要完成握手阶段
    uint32_t client_flag = *(uint32_t *)buf.data();  // TODO should use decode (little endian as default)
    LOG_INFO("client handshake response with capabilities flag=%d", client_flag);
    /// 经过测试sysbench 虽然发出的鉴权包中带了CLIENT_DEPRECATE_EOF标记，但是在接收row result set 时，
    //  不能识别最后一个OK Packet。强制清除该标识，表现正常
    client_capabilities_flag_ = (client_flag & (~CLIENT_DEPRECATE_EOF));
    // send ok packet and return
    OkPacket ok_packet;
    ok_packet.packet_header.sequence_id = sequence_id_;

    rc = send_packet(ok_packet);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to send ok packet while auth");
    }
    writer_->flush();
    authed_ = true;
    LOG_INFO("client authed. addr=%s. rc=%s", addr_.c_str(), strrc(rc));
    return rc;
  }

  int8_t command_type = buf[0];
  LOG_TRACE("recv command from client =%d", command_type);

  /// 已经做过握手，接收普通的消息包
  if (command_type == 0x03) {  // COM_QUERY，这是一个普通的文本请求
    QueryPacket query_packet;
    rc = decode_query_packet(buf, query_packet);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to decode query packet. packet length=%ld, addr=%s, error=%s", buf.size(), addr(), strrc(rc));
      return rc;
    }
    LOG_INFO("query command: %s", query_packet.query.c_str());

    LOG_TRACE("query command: %s", query_packet.query.c_str());
    if (query_packet.query.find("select @@version_comment") != string::npos) {
      bool need_disconnect;
      return handle_version_comment(need_disconnect);
    }
    LOG_TRACE("query command: %s", query_packet.query.c_str());
    if (query_packet.query.find("SET NAME") != string::npos) {
      bool need_disconnect = false;
      SessionEvent session_event(this);
      session_event.sql_result()->set_return_code(RC::SUCCESS);
      rc = write_result(&session_event, need_disconnect);
      return rc;
    }

    event = new SessionEvent(this);
    event->set_query(query_packet.query);
  } else {
    /// 其它的非文本请求，暂时不支持
    OkPacket ok_packet(sequence_id_);
    rc = send_packet(ok_packet);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to send ok packet. command=%d, addr=%s, error=%s", command_type, addr(), strrc(rc));
      return rc;
    }
    writer_->flush();
  }
  return rc;
}

RC MysqlCommunicator::write_state(SessionEvent *event, bool &need_disconnect)
{
  SqlResult *sql_result = event->sql_result();

  const int          buf_size     = 2048;
  char              *buf          = new char[buf_size];
  const string &state_string = sql_result->state_string();
  if (state_string.empty()) {
    const char *result = strrc(sql_result->return_code());
    snprintf(buf, buf_size, "%s", result);
  } else {
    snprintf(buf, buf_size, "%s > %s", strrc(sql_result->return_code()), state_string.c_str());
  }

  RC rc = RC::SUCCESS;
  if (sql_result->return_code() == RC::SUCCESS) {

    OkPacket ok_packet;
    ok_packet.packet_header.sequence_id = sequence_id_++;
    ok_packet.info.assign(buf);
    rc = send_packet(ok_packet);
  } else {
    ErrPacket err_packet;
    err_packet.packet_header.sequence_id = sequence_id_++;
    err_packet.error_code                = static_cast<int>(sql_result->return_code());
    err_packet.error_message             = buf;
    rc                                   = send_packet(err_packet);
  }
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to send ok packet to client. addr=%s, error=%s", addr(), strrc(rc));
    need_disconnect = true;
  } else {
    need_disconnect = false;
  }

  delete[] buf;
  writer_->flush();
  return rc;
}

RC MysqlCommunicator::write_result(SessionEvent *event, bool &need_disconnect)
{
  RC rc = RC::SUCCESS;

  need_disconnect       = true;
  SqlResult *sql_result = event->sql_result();
  if (nullptr == sql_result) {

    const char *response = "Unexpected error: no result";
    const int   len      = strlen(response);
    OkPacket    ok_packet;  // TODO if error occurs, we should send an error packet to client
    ok_packet.info.assign(response, len);
    rc = send_packet(ok_packet);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to send ok packet to client. addr=%s, rc=%s", addr(), strrc(rc));
      return rc;
    }

    need_disconnect = false;
  } else {
    if (RC::SUCCESS != sql_result->return_code() || !sql_result->has_operator()) {
      return write_state(event, need_disconnect);
    }

    // send result set
    // https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_com_query_response_text_resultset.html
    RC rc = sql_result->open();
    if (rc != RC::SUCCESS) {
      sql_result->set_return_code(rc);
      return write_state(event, need_disconnect);
    }

    const TupleSchema &tuple_schema = sql_result->tuple_schema();
    const int          cell_num     = tuple_schema.cell_num();
    if (cell_num == 0) {
      // maybe a dml that send nothing to client
    } else {

      // send metadata : Column Definition
      rc = send_column_definition(sql_result, need_disconnect);
      if (rc != RC::SUCCESS) {
        sql_result->close();
        return rc;
      }
    }

    rc = send_result_rows(event, sql_result, cell_num == 0, need_disconnect);
  }

  RC close_rc = sql_result->close();
  if (rc == RC::SUCCESS) {
    rc = close_rc;
  }
  writer_->flush();
  return rc;
}

RC MysqlCommunicator::send_packet(const BasePacket &packet)
{
  vector<char> net_packet;

  RC rc = packet.encode(client_capabilities_flag_, net_packet);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to encode ok packet. rc=%s", strrc(rc));
    return rc;
  }

  rc = writer_->writen(net_packet.data(), net_packet.size());
  if (OB_FAIL(rc)) {
    LOG_WARN("failed to send packet to client. addr=%s, error=%s", addr(), strerror(errno));
    return rc;
  }

  LOG_TRACE("send ok packet success. packet length=%d", net_packet.size());
  return rc;
}

/**
 * 发送列定义信息
 *  https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_com_query_response_text_resultset.html
 *  https://mariadb.com/kb/en/result-set-packets/#column-definition-packet
 *
 * 先发送当前有多少个列
 * 然后发送N个包，告诉客户端每个列的信息
 */
RC MysqlCommunicator::send_column_definition(SqlResult *sql_result, bool &need_disconnect)
{
  RC rc = RC::SUCCESS;

  const TupleSchema &tuple_schema = sql_result->tuple_schema();
  const int          cell_num     = tuple_schema.cell_num();

  if (cell_num == 0) {
    return rc;
  }

  vector<char> net_packet;
  net_packet.resize(1024);
  char *buf = net_packet.data();
  int   pos = 0;

  pos += 3;
  store_int1(buf + pos, sequence_id_++);
  pos += 1;

  if (client_capabilities_flag_ & CLIENT_OPTIONAL_RESULTSET_METADATA) {
    store_int1(buf + pos, static_cast<int>(ResultSetMetaData::RESULTSET_METADATA_FULL));
    pos += 1;
    LOG_TRACE("client with optional resultset metadata");
  } else {
    LOG_TRACE("client without optional resultset metadata");
  }

  pos += store_lenenc_int(buf + pos, cell_num);

  int payload_length = pos - 4;
  store_int3(buf, payload_length);
  net_packet.resize(pos);

  rc = writer_->writen(net_packet.data(), net_packet.size());
  if (OB_FAIL(rc)) {
    LOG_WARN("failed to send column count to client. addr=%s, error=%s", addr(), strerror(errno));
    need_disconnect = true;
    return rc;
  }

  for (int i = 0; i < cell_num; i++) {
    net_packet.resize(1024);
    buf = net_packet.data();
    pos = 0;

    pos += 3;
    store_int1(buf + pos, sequence_id_++);
    pos += 1;

    const TupleCellSpec &spec      = tuple_schema.cell_at(i);
    const char          *catalog   = "def";  // The catalog used. Currently always "def"
    const char          *schema    = "sys";  // schema name
    const char          *table     = spec.table_name();
    const char          *org_table = spec.table_name();
    const char          *name      = spec.alias();
    // const char *org_name = spec.field_name();
    const char *org_name         = spec.alias();
    int         fixed_len_fields = 0x0c;
    int         character_set    = 33;
    int         column_length    = 16384;
    int         type             = MYSQL_TYPE_VAR_STRING;
    int16_t     flags            = 0;
    int8_t      decimals         = 0x1f;

    pos += store_lenenc_string(buf + pos, catalog);
    pos += store_lenenc_string(buf + pos, schema);
    pos += store_lenenc_string(buf + pos, table);
    pos += store_lenenc_string(buf + pos, org_table);
    pos += store_lenenc_string(buf + pos, name);
    pos += store_lenenc_string(buf + pos, org_name);
    pos += store_lenenc_int(buf + pos, fixed_len_fields);
    store_int2(buf + pos, character_set);
    pos += 2;
    store_int4(buf + pos, column_length);
    pos += 4;
    store_int1(buf + pos, type);
    pos += 1;
    store_int2(buf + pos, flags);
    pos += 2;
    store_int1(buf + pos, decimals);
    pos += 1;
    store_int2(buf + pos, 0);  // 按照mariadb的文档描述，最后还有一个unused字段int<2>，不过mysql的文档没有给出这样的描述
    pos += 2;

    payload_length = pos - 4;
    store_int3(buf, payload_length);
    net_packet.resize(pos);

    rc = writer_->writen(net_packet.data(), net_packet.size());
    if (OB_FAIL(rc)) {
      LOG_WARN("failed to write column definition to client. addr=%s, error=%s", addr(), strerror(errno));
      need_disconnect = true;
      return rc;
    }
  }

  if (!(client_capabilities_flag_ & CLIENT_DEPRECATE_EOF)) {
    EofPacket eof_packet;
    eof_packet.packet_header.sequence_id = sequence_id_++;
    eof_packet.status_flags              = 0x02;
    rc                                   = send_packet(eof_packet);
    if (rc != RC::SUCCESS) {
      need_disconnect = true;
      LOG_WARN("failed to send eof packet to client. addr=%s, error=%s", addr(), strerror(errno));
    }
  } else {
    LOG_TRACE("client use CLIENT_DEPRECATE_EOF");
  }

  LOG_TRACE("send column definition to client done");
  need_disconnect = false;
  return RC::SUCCESS;
}

/**
 * 发送每行数据
 * 一行一个包
 * @param no_column_def 为了特殊处理没有返回值的语句，比如insert/delete，需要做特殊处理。
 *                      这种语句只需要返回一个ok packet即可
 */
RC MysqlCommunicator::send_result_rows(SessionEvent *event, SqlResult *sql_result, bool no_column_def, bool &need_disconnect)
{
  RC rc = RC::SUCCESS;

  vector<char> packet;
  packet.resize(4 * 1024 * 1024);  // TODO warning: length cannot be fix

  int    affected_rows = 0;
  if (event->session()->get_execution_mode() == ExecutionMode::CHUNK_ITERATOR
      && event->session()->used_chunk_mode()) {
    LOG_INFO("send chunk result to client");
    rc = write_chunk_result(sql_result, packet, affected_rows, need_disconnect);  
  } else {
    LOG_INFO("send tuple result to client");
    rc = write_tuple_result(sql_result, packet, affected_rows, need_disconnect);
  }

  // 所有行发送完成后，发送一个EOF或OK包
  if ((client_capabilities_flag_ & CLIENT_DEPRECATE_EOF) || no_column_def) {
    LOG_TRACE("client has CLIENT_DEPRECATE_EOF or has empty column, send ok packet");
    OkPacket ok_packet;
    ok_packet.packet_header.sequence_id = sequence_id_++;
    ok_packet.affected_rows             = affected_rows;
    rc                                  = send_packet(ok_packet);
  } else {
    LOG_TRACE("send eof packet to client");
    EofPacket eof_packet;
    eof_packet.packet_header.sequence_id = sequence_id_++;
    rc                                   = send_packet(eof_packet);
  }

  LOG_TRACE("send rows to client done");
  need_disconnect = false;
  return rc;
}

RC MysqlCommunicator::write_tuple_result(SqlResult *sql_result, vector<char> &packet, int &affected_rows, bool &need_disconnect)
{
  Tuple *tuple         = nullptr;
  RC rc = RC::SUCCESS;
  int min_size = 0;
  std::vector<std::vector<Value>> tuple_set;
  
  const TupleSchema &schema = sql_result->tuple_schema();
  int cell_num = schema.cell_num();

  // 增加bitmap列后，如果是联表查询，那么结果会出现多个bitmap列
  // 存储每个bitmap的索引，后续投影时忽略
  std::vector<int> ignored_index;
  int bit_map_null = 0;

  for (int i = 0; i < cell_num; i++) {
    const TupleCellSpec &spec = schema.cell_at(i);
    const char *alias = spec.alias();
    // std::cout  << spec.table_name() << " & " << spec.field_name() << " & " << spec.alias() << std::endl;

    if (strcmp(alias, NULL_FIELD_NAME.c_str()) == 0 || strcmp(spec.field_name(), NULL_FIELD_NAME.c_str()) == 0){
      ignored_index.push_back(i);
      bit_map_null +=1;
    }

    if(sql_result->get_having_stmt().size()!=0)
    {
      if( i >= cell_num - sql_result->get_having_stmt().size() - bit_map_null )
      {
        ignored_index.push_back(i);
      }
    }   
  }

  auto order_rules = sql_result->get_order_rules();
  auto vec_order_rules = sql_result->get_vec_order_rules();


  if (vec_order_rules.type != NO_Func)
  {
    // 获得排序列的索引与标识
    int order_index = -1;
    FuncOp order_op;

    order_op = vec_order_rules.type;
    bool have_index =false;
    Index * idx =nullptr;

    Table * table = nullptr;
    Db *db = session_->get_current_db();

    for(long unsigned int i = 0; i < cell_num; i++){
      const TupleCellSpec &spec = schema.cell_at(i);
      if(  (strlen(spec.table_name()) == 0 && strcmp(spec.alias(), vec_order_rules.first_attr.attribute_name.c_str()) == 0 )
        || ((strcmp(spec.table_name(), vec_order_rules.first_attr.relation_name.c_str()) == 0) && strcmp(spec.field_name(), vec_order_rules.first_attr.attribute_name.c_str()) == 0)
        
      )
      {
        order_index = i;
        if(vec_order_rules.first_attr.relation_name != "")
          table = db->find_table(vec_order_rules.first_attr.relation_name.c_str());
        else
        {
          break;
        }
        if (nullptr == table) {
          LOG_WARN("no such table for vec search.");
          return RC::SCHEMA_TABLE_NOT_EXIST;
        }
        idx = table->find_vec_index_by_fields(vec_order_rules.first_attr.attribute_name.c_str()); 
        if (nullptr != idx) {
          have_index = true;
        }
        break;
      }
    }

    //std::cout<<have_index<<endl;
    IvfflatIndex * ivf_idx = nullptr;    
    if (nullptr!= idx){
      ivf_idx = dynamic_cast<IvfflatIndex*>(idx);
      if (ivf_idx->distance_name() != vec_order_rules.type) have_index = false;
    }

    if (have_index) {
      // use ann search
      //std::cout<<"1"<<endl;

      std::vector<Value> vec_result;
      vec_result = ivf_idx->ann_search(vec_order_rules.value, vec_order_rules.limit);

      LOG_INFO("5 \n");

      // 取出全部Tuple
      std::vector<std::vector<Value>> tuple_set_all;
      while (RC::SUCCESS == (rc = sql_result->next_tuple(tuple))) {
        std::vector<Value> temp;
        int num_cell = tuple->cell_num();
        for(long unsigned int i = 0; i < num_cell; i++){
          Value cell;
          tuple->cell_at(i, cell);
          temp.push_back(cell);
        }
        tuple_set_all.push_back(temp);    
      }

      LOG_INFO("6 \n");
      std::vector<int> havepush(vec_result.size(), 0);
      // 使用哈希表来加速查找
      std::unordered_map<std::string, int> tuple_map;
      for (int i = 0; i < tuple_set_all.size(); i++) {
        const std::string &key = tuple_set_all[i][order_index].to_string();
        tuple_map[key] = i;
      }

      for (const Value &vec_val : vec_result) {
        const std::string &key = vec_val.to_string();
        if (tuple_map.find(key) != tuple_map.end() && havepush[tuple_map[key]] == 0) {
            havepush[tuple_map[key]] = 1;
            tuple_set.push_back(tuple_set_all[tuple_map[key]]);
        }
      }

      LOG_INFO("7 \n");
      if(rc==RC::INTERNAL)
      {
        sql_result->set_return_code(rc);
      }

      min_size = (tuple_set.size() > vec_order_rules.limit) ? vec_order_rules.limit : tuple_set.size();
      
    } else {
      
      LOG_INFO("8 \n");
      //std::cout<<"2"<<endl;
      // search with function result
      // 取出全部Tuple
      Value cmp_value = vec_order_rules.value;
      std::vector<std::vector<Value>> tuple_set;
      while (RC::SUCCESS == (rc = sql_result->next_tuple(tuple))) {
        std::vector<Value> temp;
        int num_cell = tuple->cell_num();
        for(int i = 0; i < num_cell; i++){
          Value cell;
          tuple->cell_at(i, cell);
          temp.push_back(cell);
        }
        tuple_set.push_back(temp);    
      }
      if(rc==RC::INTERNAL)
      {
        sql_result->set_return_code(rc);
      }

      LOG_INFO("debug:9 \n");
      // 获取函数结果
      // 排序
      std::sort(tuple_set.begin(), tuple_set.end(), 
        [order_index, order_op, cmp_value](const std::vector<Value>& t1, const std::vector<Value>& t2) {

          int target_index = order_index;
          const Value& v1 = t1[target_index];
          const Value& v2 = t2[target_index];
          LOG_INFO("debug:9.1 \n");

          Value v1_float;
          v1_float.set_float(FLT_MAX);
          Value v2_float;
          v2_float.set_float(FLT_MAX);
          LOG_INFO("debug:9.2 \n");

          switch (order_op)
          {
            case I2_DISTANCE:
            {
              LOG_INFO("debug:9.3 \n");
              float v1_tmp = FLT_MAX;
              float v2_tmp = FLT_MAX;
              
              LOG_INFO("debug:9.3.0.1 \n");
              vector<std::variant<int, float>> left_vec1 = v1.get_vector();
              vector<std::variant<int, float>> right_vec1 = cmp_value.get_vector();
              LOG_INFO("debug:9.3.0.2 \n");


              if (left_vec1.size() != right_vec1.size()) {
                  LOG_WARN("Vector sizes do not match: left_vec1.size() = %lu, right_vec1.size() = %lu\n",
                          left_vec1.size(), right_vec1.size());
                  return false;
              }
              
              LOG_INFO("debug:9.3.1 \n");

              float result = 0.0f;
              for (int i = 0; i < left_vec1.size(); i++) {
                std::visit([&result, &right_vec1, i](auto&& left_val) {
                  float left_float = static_cast<float>(left_val);
                  float right_float = static_cast<float>(std::visit([](auto&& right_val) {
                    return static_cast<float>(right_val);
                  }, right_vec1[i]));
                
                  result += pow(left_float - right_float, 2);
                }, left_vec1[i]);
              }
              LOG_INFO("debug:9.3.2 \n");
              result = sqrt(result);
              v1_tmp = result;

              vector<std::variant<int, float>> left_vec2 = v2.get_vector();
              vector<std::variant<int, float>> right_vec2 = cmp_value.get_vector();

              if (left_vec2.size() != right_vec2.size()) {
                  LOG_WARN("Vector sizes do not match: left_vec1.size() = %lu, right_vec1.size() = %lu\n",
                          left_vec2.size(), right_vec2.size());
                  return false;
              }

              LOG_INFO("debug:9.3.4 \n");

              result = 0.0f;
              for (int i = 0; i < left_vec2.size(); i++) {
                std::visit([&result, &right_vec2, i](auto&& left_val) {
                  float left_float = static_cast<float>(left_val);
                  float right_float = static_cast<float>(std::visit([](auto&& right_val) {
                    return static_cast<float>(right_val);
                  }, right_vec2[i]));
                
                  result += pow(left_float - right_float, 2);
                }, left_vec2[i]);
              }

              LOG_INFO("debug:9.3.5 \n");

              result = sqrt(result);
              v2_tmp = result;

              LOG_INFO("debug:9.3.6 \n");

              v1_float.set_float(v1_tmp);
              v2_float.set_float(v2_tmp);
            } break;
            case COSINE_DISTANCE:
            {
              LOG_INFO("debug:9.4 \n");
              float v1_tmp = FLT_MAX;
              float v2_tmp = FLT_MAX;
              
              vector<std::variant<int, float>> left_vec1 = v1.get_vector();
              vector<std::variant<int, float>> right_vec1 = cmp_value.get_vector();

              if (left_vec1.size() != right_vec1.size()) {
                  LOG_WARN("Vector sizes do not match: left_vec1.size() = %lu, right_vec1.size() = %lu\n",
                          left_vec1.size(), right_vec1.size());
                  return false;
              }

              float result = 0.0f;
              float sumA2 = 0.0f;
              float sumB2 = 0.0f;
              float sumAB = 0.0f;
              for (long unsigned int i = 0; i < left_vec1.size(); i++) {
                std::visit([&sumA2, &sumB2, &sumAB, &right_vec1, i](auto&& left_val) {
                  float left_float = static_cast<float>(left_val);
                  float right_float = static_cast<float>(std::visit([](auto&& right_val) {
                    return static_cast<float>(right_val);
                  }, right_vec1[i]));
                
                  sumA2 += left_float * left_float;
                  sumB2 += right_float * right_float;
                  sumAB += left_float * right_float;
                }, left_vec1[i]);
              }
              result = 1 - sumAB / (sqrt(sumA2) * sqrt(sumB2));
              v1_tmp = result;

              vector<std::variant<int, float>> left_vec2 = v2.get_vector();
              vector<std::variant<int, float>> right_vec2 = cmp_value.get_vector();

              if (left_vec2.size() != right_vec2.size()) {
                  LOG_WARN("Vector sizes do not match: left_vec1.size() = %lu, right_vec1.size() = %lu\n",
                          left_vec2.size(), right_vec2.size());
                  return false;
              }

              result = 0.0f;
              sumA2 = 0.0f;
              sumB2 = 0.0f;
              sumAB = 0.0f;
              for (long unsigned int i = 0; i < left_vec2.size(); i++) {
                std::visit([&sumA2, &sumB2, &sumAB, &right_vec2, i](auto&& left_val) {
                  float left_float = static_cast<float>(left_val);
                  float right_float = static_cast<float>(std::visit([](auto&& right_val) {
                    return static_cast<float>(right_val);
                  }, right_vec2[i]));
                
                  sumA2 += left_float * left_float;
                  sumB2 += right_float * right_float;
                  sumAB += left_float * right_float;
                }, left_vec2[i]);
              }
              result = 1 - sumAB / (sqrt(sumA2) * sqrt(sumB2));
              v2_tmp = result;

              v1_float.set_float(v1_tmp);
              v2_float.set_float(v2_tmp);
            } break;
            case INNER_PRODUCT:
            {
              LOG_INFO("debug:9.5 \n");
              float v1_tmp = FLT_MAX;
              float v2_tmp = FLT_MAX;
              
              vector<std::variant<int, float>> left_vec1 = v1.get_vector();
              vector<std::variant<int, float>> right_vec1 = cmp_value.get_vector();

              if (left_vec1.size() != right_vec1.size()) {
                  LOG_WARN("Vector sizes do not match: left_vec1.size() = %lu, right_vec1.size() = %lu\n",
                          left_vec1.size(), right_vec1.size());
                  return false;
              }

              float result = 0.0f;
              for (int i = 0; i < left_vec1.size(); i++) {
                std::visit([&result, &right_vec1, i](auto&& left_val) {
                  float left_float = static_cast<float>(left_val);
                  std::visit([&result, left_float](auto&& right_val) {
                    float right_float = static_cast<float>(right_val);
                    result += (left_float * right_float);
                  }, right_vec1[i]);
                }, left_vec1[i]);
              }
              v1_tmp = result;

              vector<std::variant<int, float>> left_vec2 = v2.get_vector();
              vector<std::variant<int, float>> right_vec2 = cmp_value.get_vector();

              if (left_vec2.size() != right_vec2.size()) {
                  LOG_WARN("Vector sizes do not match: left_vec1.size() = %lu, right_vec1.size() = %lu\n",
                          left_vec2.size(), right_vec2.size());
                  return false;
              }

              result = 0.0f;
              for (int i = 0; i < left_vec2.size(); i++) {
                std::visit([&result, &right_vec2, i](auto&& left_val) {
                  float left_float = static_cast<float>(left_val);
                  std::visit([&result, left_float](auto&& right_val) {
                    float right_float = static_cast<float>(right_val);
                    result += (left_float * right_float);
                  }, right_vec2[i]);
                }, left_vec2[i]);
              }
              v2_tmp = result;

              v1_float.set_float(v1_tmp);
              v2_float.set_float(v2_tmp);
            } break;
            default:
              break;
          }
          if (v1_float.get_float() == FLT_MAX || v2_float.get_float() == FLT_MAX){
            LOG_WARN("failed to cast to float");
            return false;
          }
          int ret = v1_float.compare(v2_float);
          if (ret != 0) {
            // 根据排序方向决定顺序    
            return ret < 0;
          }
      
          // 如果所有字段都相等，返回false表示保持当前顺序
          return false;
        }
      );
      LOG_INFO("debug:10 \n");
 
    }
  }

  for(long unsigned int i = 0; i < min_size; i++){
    LOG_INFO("debug:11 \n");
    affected_rows++;
    // https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_com_query_response_text_resultset.html
    // https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_com_query_response_text_resultset_row.html
    // note: if some field is null, send a 0xFB
    char *buf = packet.data();
    int   pos = 0;

    pos += 3;
    pos += store_int1(buf + pos, sequence_id_++);

    if (cell_num == 0) {
      continue;
    }

    for(long unsigned int j = 0; j < tuple_set[i].size(); j++){
      LOG_INFO("12 \n");
      Value cell = tuple_set[i][j];
      if (rc != RC::SUCCESS) {
        sql_result->set_return_code(rc);
        break;  // TODO send error packet
      }

      pos += store_lenenc_string(buf + pos, cell.to_string().c_str());
    }
    LOG_INFO("13 \n");
    int payload_length = pos - 4;
    store_int3(buf, payload_length);
    rc = writer_->writen(buf, pos);
    if (OB_FAIL(rc)) {
      LOG_WARN("failed to send row packet to client. addr=%s, error=%s", addr(), strerror(errno));
      need_disconnect = true;
      return rc;
    }
    LOG_INFO("14 \n");
  }
  return rc;
}
RC MysqlCommunicator::write_chunk_result(SqlResult *sql_result, vector<char> &packet, int &affected_rows, bool &need_disconnect)
{
  Chunk chunk;
  RC rc = RC::SUCCESS;
  while (RC::SUCCESS == (rc = sql_result->next_chunk(chunk))) {
    int column_num = chunk.column_num();
    if (column_num == 0) {
      continue;
    }
    for (int i = 0; i < chunk.rows(); i++) {
      affected_rows++;
      // https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_com_query_response_text_resultset.html
      // https://dev.mysql.com/doc/dev/mysql-server/latest/page_protocol_com_query_response_text_resultset_row.html
      // note: if some field is null, send a 0xFB
      char *buf = packet.data();
      int   pos = 0;

      pos += 3;
      pos += store_int1(buf + pos, sequence_id_++);

      for (int col_idx = 0; col_idx < column_num; col_idx++) {
        Value value = chunk.get_value(col_idx, i);
        pos += store_lenenc_string(buf + pos, value.to_string().c_str());
      }

      int payload_length = pos - 4;
      store_int3(buf, payload_length);
      rc = writer_->writen(buf, pos);
      if (OB_FAIL(rc)) {
        LOG_WARN("failed to send row packet to client. addr=%s, error=%s", addr(), strerror(errno));
        need_disconnect = true;
        return rc;
      }
    }
  }
  return rc;
}
