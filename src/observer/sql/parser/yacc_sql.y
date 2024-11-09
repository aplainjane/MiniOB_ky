
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"


using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}

UnboundAggregateExpr *create_aggregate_expression(const char *aggregate_name,
                                           std::vector<std::unique_ptr<Expression> >*child,
                                           const char *sql_string,
                                           YYLTYPE *llocp)
{
  UnboundAggregateExpr *expr = new UnboundAggregateExpr(aggregate_name, child);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}

%}

%define api.pure full
%define parse.error verbose
/** 启用位置标识 **/
%locations
%lex-param { yyscan_t scanner }
/** 这些定义了在yyparse函数中的参数 **/
%parse-param { const char * sql_string }
%parse-param { ParsedSqlResult * sql_result }
%parse-param { void * scanner }

//标识tokens
%token  SEMICOLON
        BY
        CREATE
        DROP
        GROUP
        ORDER
        TABLE
        TABLES
        UNIQUE
        INDEX
        CALC
        SELECT
        ASC
        DESC
        SHOW
        SYNC
        INSERT
        DELETE
        UPDATE
        LBRACE
        RBRACE
        COMMA
        TRX_BEGIN
        TRX_COMMIT
        TRX_ROLLBACK
        INT_T
        STRING_T
        DATE_T
        TEXT_T
        FLOAT_T
        VECTOR_T
        HELP
        EXIT
        DOT //QUOTE
        INTO
        VALUES
        FROM
        WHERE
        HAVING
        AND
        OR
        SET
        ON
        LOAD
        DATA
        INFILE
        EXPLAIN
        STORAGE
        FORMAT
        NOT
        LIKE
        IN
        IS
        EXIST
        NULL_KY
        INNER
        JOIN
        AS
        EQ
        LT
        GT
        LE
        GE
        NE
        I2_DISTANCE_T
        COSINE_DISTANCE_T
        INNER_PRODUCT_T
        WITH                                    
        DISTANCE                                
        TYPE                                 
        LISTS                                  
        PROBES  
        LIMIT
        SUM
        AVG
        COUNT
        MAX
        MIN


/** union 中定义各种数据类型，真实生成的代码也是union类型，所以不能有非POD类型的数据 **/
%union {
  ParsedSqlNode *                            sql_node;
  ConditionSqlNode *                         condition;
  JoinSqlNode *                              join_sql_node;
  Value *                                    value;  
  enum CompOp                                comp;
  enum OrderOp                               orderOp;
  enum FuncOp                                func;
  RelAttrSqlNode *                           rel_attr;
  AttrInfoSqlNode *                          attr_info;
  std::vector<AttrInfoSqlNode> *             attr_infos;
  Expression *                               expression;
  UpdateKV *                                 set_clause;
  std::vector<UpdateKV> *                    set_clause_list;
  std::vector<std::pair<RelAttrSqlNode, OrderOp>>* order_by_list;
  VecOrderByNode *                           vec_order_by;
  std::vector<std::unique_ptr<Expression>> * expression_list;
  std::vector<Value> *                       value_list;
  std::vector<ConditionSqlNode> *            condition_list;
  std::vector<RelAttrSqlNode> *              rel_attr_list;
  std::vector<std::pair<std::string,std::string>> *     relation_list;
  std::vector<std::string> *                 index_list;
  char *                                     string;
  int                                        number;
  float                                      floats;
  bool                                       boolean;
}

%token <number> NUMBER
%token <floats> FLOAT
%token <string> ID
%token <string> SSS
%token <string>  SUB_QUERY
%token <string>  VECTOR_LIST
//非终结符

/** type 定义了各种解析后的结果输出的是什么类型。类型对应了 union 中的定义的成员变量名称 **/
%type <number>              type
%type <string>              alias
%type <condition>           condition
%type <value>               value
%type <number>              number
%type <comp>                comp_op
%type <boolean>             isnull
%type <boolean>             as_option
%type <func>                func_op
%type <comp>                is_null_choice
%type <rel_attr>            rel_attr
%type <attr_infos>          attr_def_list
%type <attr_info>           attr_def
%type <value_list>          value_list
%type <condition_list>      where
%type <condition_list>      having
%type <join_sql_node>       join_list
%type <condition_list>      condition_list
%type <string>              storage_format
%type <relation_list>       rel_list
%type <index_list>          index_rel_list
%type <expression>          expression
%type <expression>          simple_expression
%type <expression>          arith_expr
%type <expression>          aggr_expr
%type <expression_list>     expression_list
%type <expression_list>     group_by
%type <set_clause_list>     set_clause_list
%type <set_clause>          set_clause
%type <orderOp>             order_op
%type <order_by_list>       order_by_list
%type <order_by_list>       order_by
%type <vec_order_by>        vec_order_by
%type <sql_node>            calc_stmt
%type <sql_node>            select_stmt
%type <sql_node>            insert_stmt
%type <sql_node>            update_stmt
%type <sql_node>            delete_stmt
%type <sql_node>            create_table_stmt
%type <sql_node>            drop_table_stmt
%type <sql_node>            show_tables_stmt
%type <sql_node>            desc_table_stmt
%type <sql_node>            create_index_stmt
%type <sql_node>            create_vec_index_stmt
%type <sql_node>            drop_index_stmt
%type <sql_node>            sync_stmt
%type <sql_node>            begin_stmt
%type <sql_node>            commit_stmt
%type <sql_node>            rollback_stmt
%type <sql_node>            load_data_stmt
%type <sql_node>            explain_stmt
%type <sql_node>            explain_vec_stmt
%type <sql_node>            set_variable_stmt
%type <sql_node>            help_stmt
%type <sql_node>            exit_stmt
%type <sql_node>            command_wrapper
// commands should be a list but I use a single command instead
%type <sql_node>            commands

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%%

commands: command_wrapper opt_semicolon  //commands or sqls. parser starts here.
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>($1);
    sql_result->add_sql_node(std::move(sql_node));
  }
  ;

command_wrapper:
    calc_stmt
  | select_stmt
  | insert_stmt
  | update_stmt
  | delete_stmt
  | create_table_stmt
  | drop_table_stmt
  | show_tables_stmt
  | desc_table_stmt
  | create_index_stmt
  | create_vec_index_stmt
  | drop_index_stmt
  | sync_stmt
  | begin_stmt
  | commit_stmt
  | rollback_stmt
  | load_data_stmt
  | explain_stmt
  | explain_vec_stmt
  | set_variable_stmt
  | help_stmt
  | exit_stmt
    ;

exit_stmt:      
    EXIT {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      $$ = new ParsedSqlNode(SCF_EXIT);
    };

help_stmt:
    HELP {
      $$ = new ParsedSqlNode(SCF_HELP);
    };

sync_stmt:
    SYNC {
      $$ = new ParsedSqlNode(SCF_SYNC);
    }
    ;

begin_stmt:
    TRX_BEGIN  {
      $$ = new ParsedSqlNode(SCF_BEGIN);
    }
    ;

commit_stmt:
    TRX_COMMIT {
      $$ = new ParsedSqlNode(SCF_COMMIT);
    }
    ;

rollback_stmt:
    TRX_ROLLBACK  {
      $$ = new ParsedSqlNode(SCF_ROLLBACK);
    }
    ;

drop_table_stmt:    /*drop table 语句的语法解析树*/
    DROP TABLE ID {
      $$ = new ParsedSqlNode(SCF_DROP_TABLE);
      $$->drop_table.relation_name = $3;
      free($3);
    };

show_tables_stmt:
    SHOW TABLES {
      $$ = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
    ;

desc_table_stmt:
    DESC ID  {
      $$ = new ParsedSqlNode(SCF_DESC_TABLE);
      $$->desc_table.relation_name = $2;
      free($2);
    }
    ;

create_index_stmt:    /*create index 语句的语法解析树*/
    CREATE INDEX ID ON ID LBRACE ID index_rel_list RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = $$->create_index;
      create_index.index_name = $3;
      create_index.relation_name = $5;
      if ($8 != nullptr) {
        create_index.attribute_names.swap(*$8);
      }
      create_index.attribute_names.emplace_back($7);

      create_index.unique = false;
      free($3);
      free($5);
      free($7);
      if ($8 != nullptr){
        delete($8);
      }
    }
    | CREATE UNIQUE INDEX ID ON ID LBRACE ID index_rel_list RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = $$->create_index;
      create_index.index_name = $4;
      create_index.relation_name = $6;
      // create_index.attribute_name = $8;
      if ($9 != nullptr){
        create_index.attribute_names.swap(*$9);
      }
      create_index.attribute_names.emplace_back($8);
      create_index.unique = true;
      free($4);
      free($6);
      free($8);
      if ($9 != nullptr){
        delete($9);
      }
    }
    ;

create_vec_index_stmt:
    CREATE VECTOR_T INDEX ID ON ID LBRACE ID RBRACE WITH LBRACE TYPE EQ ID COMMA DISTANCE EQ func_op COMMA LISTS EQ NUMBER COMMA PROBES EQ NUMBER RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_VEC_INDEX);
      CreateVecIndexSqlNode &create_vec_index = $$->create_vec_index;
      create_vec_index.index_name = $4;
      create_vec_index.relation_name = $6;
      create_vec_index.attribute_name = $8;
      create_vec_index.distance_name = $18;
      create_vec_index.type_name = $14;
      create_vec_index.nlist = $22;
      create_vec_index.probes = $26;
      free($4);
      free($6);
      free($8);
      free($14);
    }
    ;

index_rel_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA ID index_rel_list {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<std::string>;
      }
      $$->emplace_back($2);
      free($2);
    }
    ;

drop_index_stmt:      /*drop index 语句的语法解析树*/
    DROP INDEX ID ON ID
    {
      $$ = new ParsedSqlNode(SCF_DROP_INDEX);
      $$->drop_index.index_name = $3;
      $$->drop_index.relation_name = $5;
      free($3);
      free($5);
    }
    ;
create_table_stmt:    /*create table 语句的语法解析树*/
    CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format
    {
      $$ = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = $$->create_table;
      create_table.relation_name = $3;
      free($3);

      std::vector<AttrInfoSqlNode> *src_attrs = $6;

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
        delete src_attrs;
      }
      create_table.attr_infos.emplace_back(*$5);
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete $5;

      AttrInfoSqlNode null_field;
      null_field.type = AttrType::INTS;
      null_field.name = NULL_FIELD_NAME;
      null_field.length = 4;
      null_field.isnull = false;
      create_table.attr_infos.emplace_back(null_field);

      if ($8 != nullptr) {
        create_table.storage_format = $8;
        free($8);
      }
    }
    | CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE as_option select_stmt
    {
      $$ = $9;
      $$->flag = SCF_CREATE_TABLE;
      CreateTableSqlNode &create_table = $$->create_table;
      create_table.relation_name = $3;
      free($3);
      std::vector<AttrInfoSqlNode> *src_attrs = $6;
      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*$5);
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete $5;
    }
    | CREATE TABLE ID as_option select_stmt
    {
      $$ = $5;
      $$->flag = SCF_CREATE_TABLE;
      CreateTableSqlNode &create_table = $$->create_table;
      create_table.relation_name = $3;
      free($3);
    }
    ;
as_option:
    /* empty */
    {
      $$ = false;
    }
    | AS
    {
      $$ = false;
    }
    ;
attr_def_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA attr_def attr_def_list
    {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<AttrInfoSqlNode>;
      }
      $$->emplace_back(*$2);
      delete $2;
    }
    ;
    
attr_def:
    ID type LBRACE number RBRACE isnull
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      $$->length = $4;
      $$->isnull = $6;
      free($1);
    }
    | ID type isnull
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      $$->length = 4;
      $$->isnull = $3;
      free($1);
    }
    ;

isnull:
    /* empty */
    {
      $$ = true;
    }
    | NULL_KY
    {
      $$ = true;
    }
    | NOT NULL_KY
    {
      $$ = false;
    }
    ;
    
number:
    NUMBER {$$ = $1;}
    ;
type:
    INT_T      { $$ = static_cast<int>(AttrType::INTS); }
    | STRING_T { $$ = static_cast<int>(AttrType::CHARS); }
    | FLOAT_T  { $$ = static_cast<int>(AttrType::FLOATS); }
    | VECTOR_T { $$ = static_cast<int>(AttrType::VECTORS); }
    | DATE_T   { $$ = static_cast<int>(AttrType::DATES); }
    | TEXT_T   { $$ = static_cast<int>(AttrType::TEXTS); }
    ;
insert_stmt:        /*insert   语句的语法解析树*/
    INSERT INTO ID VALUES LBRACE value value_list RBRACE 
    {
      $$ = new ParsedSqlNode(SCF_INSERT);
      $$->insertion.relation_name = $3;
      if ($7 != nullptr) {
        $$->insertion.values.swap(*$7);
        delete $7;
      }
      $$->insertion.values.emplace_back(*$6);
      std::reverse($$->insertion.values.begin(), $$->insertion.values.end());
      delete $6;
      free($3);
    }
    ;

value_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA value value_list  { 
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<Value>;
      }
      $$->emplace_back(*$2);
      delete $2;
    }
    ;
value:
    NUMBER {
      $$ = new Value((int)$1);
      @$ = @1;
    }
    |FLOAT {
      $$ = new Value((float)$1);
      @$ = @1;
    }
    |SSS {
      char *tmp = common::substr($1,1,strlen($1)-2);
      $$ = new Value(tmp);
      free(tmp);
      free($1);
    }
    |VECTOR_LIST {
      char *tmp = common::substr($1,0,strlen($1)-1);
      $$ = new Value(tmp);
      free(tmp);
      free($1);
    }
    | NULL_KY {
      $$ = new Value(NULL_VALUE, 1);
    }
    ;
storage_format:
    /* empty */
    {
      $$ = nullptr;
    }
    | STORAGE FORMAT EQ ID
    {
      $$ = $4;
    }
    ;
    
delete_stmt:    /*  delete 语句的语法解析树*/
    DELETE FROM ID where 
    {
      $$ = new ParsedSqlNode(SCF_DELETE);
      $$->deletion.relation_name = $3;
      if ($4 != nullptr) {
        $$->deletion.conditions.swap(*$4);
        delete $4;
      }
      free($3);
    }
    ;
update_stmt:
    UPDATE ID SET set_clause_list where
    {
        $$ = new ParsedSqlNode(SCF_UPDATE);
        $$->update.relation_name = $2;
        int temp = 0;
        if (nullptr != $4) {
            for (UpdateKV kv : *$4) {
              $$->update.attribute_names.emplace_back(kv.attr_name);
              if(kv.is_subquery){
                $$->update.subquery_values.emplace_back(kv.subquery);
                $$->update.record.emplace_back(temp);
              }
              else{
                $$->update.values.emplace_back(kv.value);
              }
              temp++;
            }
            delete $4;  // $4 只需要在这里释放一次
        }
        if ($5 != nullptr) {
            $$->update.conditions.swap(*$5);
            delete $5;  // $5 在此处释放
        }
        free($2);  // 正确释放 $2
        // delete $5;  // 这里不需要再释放 $5，避免 double-free
    }
    ;


set_clause_list:
    set_clause
    {
        $$ = new std::vector<UpdateKV>();
        $$->emplace_back(*$1);
        delete $1;  // 确保 $1 是 new 出来的对象
    }
    | set_clause_list COMMA set_clause
    {
        $1->emplace_back(*$3);
        $$ = $1;
        delete $3;  // 确保 $3 是 new 出来的对象
    }
    ;


set_clause:
    ID EQ value
    {
        $$ = new UpdateKV();
        $$->attr_name = strdup($1);  // 使用 strdup 复制字符串，避免释放后使用问题
        $$->value = *$3;
        free($1);  // 确保在拷贝完成后再释放
    }
    | ID EQ SUB_QUERY
    {
      $$ = new UpdateKV();
      $$->is_subquery = true;
      $$->attr_name = strdup($1);
      $$->subquery = strdup($3);
      free($1);
      free($3);
    }
    ;


select_stmt:        /*  select 语句的语法解析树*/
    SELECT expression_list
    {
      $$ = new ParsedSqlNode(SCF_SELECT);
      if ($2 != nullptr) {
        $$->selection.expressions.swap(*$2);
        delete $2;
      }
    }
    | SELECT expression_list FROM ID alias rel_list join_list where group_by having order_by
    {
      $$ = new ParsedSqlNode(SCF_SELECT);
      if ($2 != nullptr) {
        $$->selection.expressions.swap(*$2);
        delete $2;
      }
      if ($6 != nullptr) {
        $$->selection.relations.swap(*$6);
        delete $6;
      }
      std::string temp = "";
      if (nullptr != $5) {
        temp = $5;
      }
      $$->selection.relations.emplace_back($4,temp);
      free($5);
      std::reverse($$->selection.relations.begin(), $$->selection.relations.end());

      if ($8 != nullptr) {
        $$->selection.conditions.swap(*$8);
        delete $8;
      }
      free($4);
      
      if ($7 != nullptr) {
        $$->selection.relations.insert($$->selection.relations.end(), $7->relations.begin(), $7->relations.end());
        $$->selection.conditions.insert($$->selection.conditions.end(), $7->conditions.begin(), $7->conditions.end());
        delete $7;
      }
      if ($9 != nullptr) {
        $$->selection.group_by.swap(*$9);
        delete $9;
      }
      if ($10 != nullptr) {
        $$->selection.having_conditions.swap(*$10);
        delete $10;
      }
      if ($11 != nullptr) {
        $$->selection.order_rules.swap(*$11);
        delete $11;
      }
    }
    ;
calc_stmt:
    CALC expression_list
    {
      $$ = new ParsedSqlNode(SCF_CALC);
      $$->calc.expressions.swap(*$2);
      delete $2;
    }
    ;
alias:
    /* empty */ {
      $$ = nullptr;
    }
    | ID {
      $$ = $1;
    }
    | AS ID {
      $$ = $2;
    }
expression_list:
    expression alias
    {
      $$ = new std::vector<std::unique_ptr<Expression>>;
      if (nullptr != $2) {
        $1->set_alias($2);
      }
      $$->emplace_back($1);
      free($2);
    }
    | expression alias COMMA expression_list
    {
      if ($4 != nullptr) {
        $$ = $4;
      } else {
        $$ = new std::vector<std::unique_ptr<Expression>>;
      }
      if (nullptr != $2) {
        $1->set_alias($2);
      }
      $$->emplace($$->begin(), $1);
      free($2);
    }
    ;
expression:
    LBRACE expression RBRACE {
      $$ = $2;
      $$->set_name(token_name(sql_string, &@$));
    }
    | expression '+' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $3, sql_string, &@$);
    }
    | expression '-' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $3, sql_string, &@$);
    }
    | expression '*' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $3, sql_string, &@$);
    }
    | expression '/' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $3, sql_string, &@$);
    }
    | value {
      $$ = new ValueExpr(*$1);
      $$->set_name(token_name(sql_string, &@$));
      delete $1;
    }
    | rel_attr {
      RelAttrSqlNode *node = $1;
      $$ = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      $$->set_name(token_name(sql_string, &@$));
      delete $1;
    }
    | '*' {
      $$ = new StarExpr();
    }
    | ID DOT '*'{
      $$ = new StarExpr($1);
    }
    | '-' expression %prec UMINUS {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), $2, sql_string, &@$);
    }
    | aggr_expr {
      $$ = $1;
    }
    | func_op LBRACE expression_list RBRACE {
      $$ = new FunctionExpr((FuncOp)$1,std::move(*$3));
      $$->set_name(token_name(sql_string, &@$));
      delete $3;
    }
    | func_op LBRACE RBRACE {
      $$ = new FunctionExpr((FuncOp)$1,std::vector<std::unique_ptr<Expression>>());
      $$->set_name(token_name(sql_string, &@$));
    }
    ;
simple_expression:
    value {
      $$ = new ValueExpr(*$1);
      $$->set_name(token_name(sql_string, &@$));
      delete $1;
    }
    | rel_attr {
      RelAttrSqlNode *node = $1;
      $$ = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      $$->set_name(token_name(sql_string, &@$));
      delete $1;
    }

arith_expr:
    LBRACE arith_expr RBRACE {
      $$ = $2;
    }
    | arith_expr '+' LBRACE simple_expression RBRACE {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $4, sql_string, &@$);
    }
    | arith_expr '-' LBRACE simple_expression RBRACE {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $4, sql_string, &@$);
    }
    | arith_expr '*' LBRACE simple_expression RBRACE {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $4, sql_string, &@$);
    }
    | arith_expr '/' LBRACE simple_expression RBRACE {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $4, sql_string, &@$);
    }
    | simple_expression '+' LBRACE simple_expression RBRACE {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $4, sql_string, &@$);
    }
    | simple_expression '-' LBRACE simple_expression RBRACE {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $4, sql_string, &@$);
    }
    | simple_expression '*' LBRACE simple_expression RBRACE {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $4, sql_string, &@$);
    }
    | simple_expression '/' LBRACE simple_expression RBRACE {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $4, sql_string, &@$);
    }
    | '-' arith_expr {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), $2, sql_string, &@$);
    }
    | '-' simple_expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), $2, sql_string, &@$);
    }
    | arith_expr '+' simple_expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $3, sql_string, &@$);
    }
    | arith_expr '-' simple_expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $3, sql_string, &@$);
    }
    | arith_expr '*' simple_expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $3, sql_string, &@$);
    }
    | arith_expr '/' simple_expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $3, sql_string, &@$);
    }
    | simple_expression '+' arith_expr {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $3, sql_string, &@$);
    }
    | simple_expression '-' arith_expr {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $3, sql_string, &@$);
    }
    | simple_expression '*' arith_expr {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $3, sql_string, &@$);
    }
    | simple_expression '/' arith_expr {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $3, sql_string, &@$);
    }
    | arith_expr '+' arith_expr {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $3, sql_string, &@$);
    }
    | arith_expr '-' arith_expr {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $3, sql_string, &@$);
    }
    | arith_expr '*' arith_expr {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $3, sql_string, &@$);
    }
    | arith_expr '/' arith_expr {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $3, sql_string, &@$);
    }
    | simple_expression '+' simple_expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $3, sql_string, &@$);
    }
    | simple_expression '-' simple_expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $3, sql_string, &@$);
    }
    | simple_expression '*' simple_expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $3, sql_string, &@$);
    }
    | simple_expression '/' simple_expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $3, sql_string, &@$);
    }
    ;
aggr_expr:
    SUM LBRACE expression_list RBRACE {
      $$ = create_aggregate_expression("SUM", $3, sql_string, &@$);
    }
    | AVG LBRACE expression_list RBRACE {
      $$ = create_aggregate_expression("AVG", $3, sql_string, &@$);
    }
    | MAX LBRACE expression_list RBRACE {
      $$ = create_aggregate_expression("MAX", $3, sql_string, &@$);
    }
    | MIN LBRACE expression_list RBRACE {
      $$ = create_aggregate_expression("MIN", $3, sql_string, &@$);
    }
    | COUNT LBRACE expression_list RBRACE {
      $$ = create_aggregate_expression("COUNT", $3, sql_string, &@$);
    }
    | SUM LBRACE RBRACE {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->emplace_back(std::make_unique<ValueExpr>());
      empty->emplace_back(std::make_unique<ValueExpr>());
      $$ = create_aggregate_expression("SUM", empty, sql_string, &@$);
    }
    | AVG LBRACE RBRACE {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->emplace_back(std::make_unique<ValueExpr>());
      empty->emplace_back(std::make_unique<ValueExpr>());
      $$ = create_aggregate_expression("AVG", empty, sql_string, &@$);
    }
    | MIN LBRACE RBRACE {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->emplace_back(std::make_unique<ValueExpr>());
      empty->emplace_back(std::make_unique<ValueExpr>());
      $$ = create_aggregate_expression("MIN", empty, sql_string, &@$);
    }
    | MAX LBRACE RBRACE {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->emplace_back(std::make_unique<ValueExpr>());
      empty->emplace_back(std::make_unique<ValueExpr>());
      $$ = create_aggregate_expression("MAX", empty, sql_string, &@$);
    }
    | COUNT LBRACE RBRACE {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->emplace_back(std::make_unique<ValueExpr>());
      empty->emplace_back(std::make_unique<ValueExpr>());
      $$ = create_aggregate_expression("COUNT", empty, sql_string, &@$);
    }
    ;

rel_attr:
    ID {
      $$ = new RelAttrSqlNode;
      $$->attribute_name = $1;
      free($1);
    }
    | ID DOT ID {
      $$ = new RelAttrSqlNode;
      $$->relation_name  = $1;
      $$->attribute_name = $3;
      free($1);
      free($3);
    }
    ;

rel_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA ID alias rel_list {
      if ($4 != nullptr) {
        $$ = $4;
      } else {
        $$ = new std::vector<std::pair<std::string,std::string>>;
      }
      std::string temp = "";
      if (nullptr != $3) {
        temp = $3;
      }
      $$->emplace_back($2,temp);
      free($2);
    }
    ;

join_list:
    {
      $$ = nullptr;
    }
    | INNER join_list {
      $$ = $2;
    }
    | JOIN ID alias ON condition_list join_list {
      $$ = new JoinSqlNode();

      if ($5 != nullptr) {
        $$->conditions.swap(*$5);
        delete $5;
      }
      std::string temp = "";
      if (nullptr != $3) {
        temp = $3;
      }
      $$->relations.emplace_back($2,temp);

      free($2);

      if ($6 != nullptr) {
        $$->relations.insert($$->relations.end(), $6->relations.begin(), $6->relations.end());
        $$->conditions.insert($$->conditions.end(), $6->conditions.begin(), $6->conditions.end());
        delete $6;
      }
    }
    
order_by:
  {
    $$ = nullptr;
  }
  | ORDER BY rel_attr order_op order_by_list
  {
    $$ = new std::vector<std::pair<RelAttrSqlNode, OrderOp>>;
    $$->emplace_back(std::make_pair(*$3, $4));
    delete $3;
    if ($5 != nullptr) {
      $$->insert($$->end(), $5->begin(), $5->end());
    }
  }
  ;

vec_order_by:
  ORDER BY func_op LBRACE rel_attr COMMA value RBRACE LIMIT number
  {
    $$ = new VecOrderByNode;
    $$->type = $3;
    $$->first_attr = *$5;
    $$->value = *$7;
    $$->limit = $10; 
  }
  | ORDER BY func_op LBRACE value COMMA rel_attr RBRACE LIMIT number
  {
    $$ = new VecOrderByNode;
    $$->type = $3;
    $$->first_attr = *$7;
    $$->value = *$5;
    $$->limit = $10;
  }
  ;

order_by_list:
  {
    $$ = nullptr;
  }
  | COMMA rel_attr order_op order_by_list
  {
    $$ = new std::vector<std::pair<RelAttrSqlNode, OrderOp>>;
    $$->emplace_back(std::make_pair(*$2, $3));
    delete $2;

    if ($4 != nullptr) {
      $$->insert($$->end(), $4->begin(), $4->end());
    }
  }
  ;

order_op:
  DESC { $$ = ORDER_DESC; }
| ASC  { $$ = ORDER_ASC;  }
|      { $$ = ORDER_DEFAULT; }
;


where:
    /* empty */
    {
      $$ = nullptr;
    }

    | WHERE condition_list {
      $$ = $2;  
    }
    ;
condition_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | condition {
      $$ = new std::vector<ConditionSqlNode>;
      $$->emplace_back(*$1);
      delete $1;
    }
    | condition AND condition_list {
      $$ = $3;
      $$->emplace_back(*$1);
      delete $1;
    }
    | condition OR condition_list {
      $1->conjunction="OR";
      $3[0][0].conjunction="OR";
      $$ = $3;
      $$->emplace_back(*$1);
      delete $1;
    }
    ;
condition:
     arith_expr comp_op value {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 5;
        $$->left_expr = $1;
        $$->right_is_attr = 0;
        $$->right_value = *$3;
        $$->comp = $2;
        delete $3;
    }
    | arith_expr comp_op rel_attr {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 5;
        $$->left_expr = $1;
        $$->right_is_attr = 1;
        $$->right_attr = *$3;
        $$->comp = $2;
        delete $3;
    }
    | value comp_op arith_expr {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 0;
        $$->left_value = *$1;
        $$->right_is_attr = 5;
        $$->right_expr = $3;
        $$->comp = $2;
        delete $1;
    }
    | rel_attr comp_op arith_expr {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 1;
        $$->left_attr = *$1;
        $$->right_is_attr = 5;
        $$->right_expr = $3;
        $$->comp = $2;
        delete $1;
    }
    | arith_expr comp_op arith_expr {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 5;
        $$->left_expr = $1;
        $$->right_is_attr = 5;
        $$->right_expr = $3;
        $$->comp = $2;
    }
    | rel_attr comp_op value    {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 1;
        $$->left_attr = *$1;
        $$->right_is_attr = 0;
        $$->right_value = *$3;
        $$->comp = $2;
        delete $1;
        delete $3;
    }
    | value comp_op value     {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 0;
        $$->left_value = *$1;
        $$->right_is_attr = 0;
        $$->right_value = *$3;
        $$->comp = $2;
        delete $1;
        delete $3;
    }
    | rel_attr comp_op rel_attr    {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 1;
        $$->left_attr = *$1;
        $$->right_is_attr = 1;
        $$->right_attr = *$3;
        $$->comp = $2;
        delete $1;
        delete $3;
    }
    | value comp_op rel_attr    {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 0;
        $$->left_value = *$1;
        $$->right_is_attr = 1;
        $$->right_attr = *$3;
        $$->comp = $2;
        delete $1;
        delete $3;
    }
    | rel_attr comp_op SUB_QUERY    {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 1;
        $$->left_attr = *$1;
        $$->right_is_attr = 2;
        $$->right_subquery = $3;
        $$->comp = $2;
        delete $1;
        free($3);
    }
    | SUB_QUERY comp_op rel_attr    {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 2;
        $$->left_subquery = $1;
        $$->right_is_attr = 1;
        $$->right_attr = *$3;
        $$->comp = $2;
        free($1);
        delete $3;
    }
    | SUB_QUERY comp_op SUB_QUERY    {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 2;
        $$->left_subquery = $1;
        $$->right_is_attr = 2;
        $$->right_subquery = $3;
        $$->comp = $2;
        free($1);
        free($3);
    }
    | value comp_op LBRACE value value_list RBRACE    {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 0;
        $$->left_value = *$1;
        $$->right_is_attr = 3;
        if ($5 != nullptr) {
            $$->right_list.swap(*$5);
            delete $5;
        }
        $$->right_list.emplace_back(*$4);
        std::reverse($$->right_list.begin(), $$->right_list.end());
        $$->comp = $2;
        delete $1;
        delete $4;
    }
    | rel_attr comp_op LBRACE value value_list RBRACE    {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 1;
        $$->left_attr = *$1;
        $$->right_is_attr = 3;
        if ($5 != nullptr) {
            $$->right_list.swap(*$5);
            delete $5;
        }
        $$->right_list.emplace_back(*$4);
        std::reverse($$->right_list.begin(), $$->right_list.end());
        $$->comp = $2;
        delete $1;
        delete $4;
    }
    | SUB_QUERY comp_op LBRACE value value_list RBRACE    {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 2;
        $$->left_subquery = $1;
        $$->right_is_attr = 3;
        if ($5 != nullptr) {
            $$->right_list.swap(*$5);
            delete $5;
        }
        $$->right_list.emplace_back(*$4);
        std::reverse($$->right_list.begin(), $$->right_list.end());
        $$->comp = $2;
        free($1);
        delete $4;
    }
    | LBRACE value value_list RBRACE comp_op value {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 3;
        if ($3 != nullptr) {
            $$->left_list.swap(*$3);
            delete $3;
        }
        $$->left_list.emplace_back(*$2);
        std::reverse($$->left_list.begin(), $$->left_list.end());
        $$->right_is_attr = 0;
        $$->right_value = *$6;
        $$->comp = $5;
        delete $2;
        delete $6;
    }
    | LBRACE value value_list RBRACE comp_op rel_attr {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 3;
        if ($3 != nullptr) {
            $$->left_list.swap(*$3);
            delete $3;
        }
        $$->left_list.emplace_back(*$2);
        std::reverse($$->left_list.begin(), $$->left_list.end());
        $$->right_is_attr = 1;
        $$->right_attr = *$6;
        $$->comp = $5;
        delete $2;
        delete $6;
    }
    | LBRACE value value_list RBRACE comp_op SUB_QUERY {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 3;
        if ($3 != nullptr) {
            $$->left_list.swap(*$3);
            delete $3;
        }
        $$->left_list.emplace_back(*$2);
        std::reverse($$->left_list.begin(), $$->left_list.end());
        $$->right_is_attr = 2;
        $$->right_subquery = $6;
        $$->comp = $5;
        delete $2;
        free($6);
    }
    | LBRACE value value_list RBRACE comp_op LBRACE value value_list RBRACE {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 3;
        if ($3 != nullptr) {
            $$->left_list.swap(*$3);
            delete $3;
        }
        $$->left_list.emplace_back(*$2);
        std::reverse($$->left_list.begin(), $$->left_list.end());
        $$->right_is_attr = 3;
        if ($8 != nullptr) {
            $$->right_list.swap(*$8);
            delete $8;
        }
        $$->right_list.emplace_back(*$7);
        std::reverse($$->right_list.begin(), $$->right_list.end());
        $$->comp = $5;
        delete $2;
        delete $7;
    }
    | aggr_expr comp_op value {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 4;     
        $$->left_expr = $1;
        $$->right_is_attr = 0;
        $$->right_value = *$3;
        $$->comp = $2;
        delete $3;
    }
    | aggr_expr comp_op rel_attr {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 4;     
        $$->left_expr = $1;
        $$->right_is_attr = 1;
        $$->right_attr = *$3;
        $$->comp = $2;
        delete $3;
    }
    | aggr_expr comp_op aggr_expr {
        $$ = new ConditionSqlNode;
        $$->left_is_attr = 4;
        $$->left_expr = $1;
        $$->right_is_attr = 4;
        $$->right_expr = $3;
        $$->comp = $2;  
    }
    | value is_null_choice {
      $$ = new ConditionSqlNode;
      Value val;
      val.set_null(0);
        
      $$->left_is_attr = 0;
      $$->left_value = *$1;  
      $$->right_is_attr = 0;
      $$->right_value = val;
      $$->comp = $2;
      delete $1;
    }
    | rel_attr is_null_choice {
      $$ = new ConditionSqlNode;
      Value val;
      val.set_null(0);

      $$->left_is_attr = 1;
      $$->left_attr = *$1;
      $$->right_is_attr = 0;
      $$->right_value = val;
      $$->comp = $2;
      delete $1;
    }
    ;

is_null_choice:
      IS NULL_KY { $$ =  OP_ISNULL; }
    | IS NOT NULL_KY { $$ = OP_ISNOTNULL; }
    ;
      
comp_op:
      EQ { $$ = EQUAL_TO; }
    | LT { $$ = LESS_THAN; }
    | GT { $$ = GREAT_THAN; }
    | LE { $$ = LESS_EQUAL; }
    | GE { $$ = GREAT_EQUAL; }
    | NE { $$ = NOT_EQUAL; }
    | LIKE { $$ = CLIKE; }
    | NOT LIKE { $$ = CNLIKE; }
    | IN { $$ = IN_LIST; }
    | NOT IN { $$ = NOTIN_LIST; }
    | EXIST { $$ = EXIST_LIST; }
    | NOT EXIST { $$ = NOTEXIST_LIST; }
    ;

func_op:
      I2_DISTANCE_T { $$ = I2_DISTANCE; }
    | COSINE_DISTANCE_T { $$ = COSINE_DISTANCE; }
    | INNER_PRODUCT_T { $$ = INNER_PRODUCT; }

// your code here
group_by:
    {
      $$ = nullptr;
    }
    | GROUP BY expression_list
	  {
        $$ = $3;
	  }
    ;

having:
    {
      $$ = nullptr;
    }
    | HAVING condition_list
    {
      $$ = $2;
    }
    ;
    
load_data_stmt:
    LOAD DATA INFILE SSS INTO TABLE ID 
    {
      char *tmp_file_name = common::substr($4, 1, strlen($4) - 2);
      
      $$ = new ParsedSqlNode(SCF_LOAD_DATA);
      $$->load_data.relation_name = $7;
      $$->load_data.file_name = tmp_file_name;
      free($7);
      free(tmp_file_name);
    }
    ;

explain_stmt:
    EXPLAIN ID
    {
      $$ = new ParsedSqlNode(SCF_EXPLAIN);
    }
    ;

explain_vec_stmt:
    EXPLAIN SELECT expression_list FROM ID where vec_order_by
    {
      $$ = new ParsedSqlNode(SCF_VEC_EXPLAIN);
      $$->vec_explain.table_name = $5;
      $$->vec_explain.inited = 1;
      $$->vec_explain.vec_order_by = *$7;
      free($5);
    }
    ;

set_variable_stmt:
    SET ID EQ value
    {
      $$ = new ParsedSqlNode(SCF_SET_VARIABLE);
      $$->set_variable.name  = $2;
      $$->set_variable.value = *$4;
      free($2);
      delete $4;
    }
    ;

opt_semicolon: /*empty*/
    | SEMICOLON
    ;
%%
//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}