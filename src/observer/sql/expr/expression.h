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
// Created by Wangyunlai on 2022/07/05.
//

#pragma once

#include <memory>
#include <string>

#include "common/value.h"
#include "storage/field/field.h"
#include "sql/expr/aggregator.h"
#include "storage/common/chunk.h"
#include "sql/expr/tuple_cell.h"


class Tuple;
class SqlResult;
class SQLStageEvent;
/**
 * @defgroup Expression
 * @brief 表达式
 */

/**
 * @brief 表达式类型
 * @ingroup Expression
 */
enum class ExprType
{
  NONE,
  STAR,                 ///< 星号，表示所有字段
  UNBOUND_FIELD,        ///< 未绑定的字段，需要在resolver阶段解析为FieldExpr
  UNBOUND_AGGREGATION,  ///< 未绑定的聚合函数，需要在resolver阶段解析为AggregateExpr

  FIELD,        ///< 字段。在实际执行时，根据行数据内容提取对应字段的值
  VALUE,        ///< 常量值
  SUBQUERY,
  CAST,         ///< 需要做类型转换的表达式
  COMPARISON,   ///< 需要做比较的表达式
  CONJUNCTION,  ///< 多个表达式使用同一种关系(AND或OR)来联结
  ARITHMETIC,   ///< 算术运算
  AGGREGATION,  ///< 聚合运算
  FUNCTION,     ///< 函数，这里只实现了vec的
};

/**
 * @brief 表达式的抽象描述
 * @ingroup Expression
 * @details 在SQL的元素中，任何需要得出值的元素都可以使用表达式来描述
 * 比如获取某个字段的值、比较运算、类型转换
 * 当然还有一些当前没有实现的表达式，比如算术运算。
 *
 * 通常表达式的值，是在真实的算子运算过程中，拿到具体的tuple后
 * 才能计算出来真实的值。但是有些表达式可能就表示某一个固定的
 * 值，比如ValueExpr。
 *
 * TODO 区分unbound和bound的表达式
 */
class Expression
{
public:
  Expression()          = default;
  virtual ~Expression() = default;

  virtual std::unique_ptr<Expression> deep_copy() const = 0; // 深拷贝

  /**
   * @brief 判断两个表达式是否相等
   */
  virtual bool equal(const Expression &other) const { return false; }
  /**
   * @brief 根据具体的tuple，来计算当前表达式的值。tuple有可能是一个具体某个表的行数据
   */
  virtual RC get_value(const Tuple &tuple, Value &value) const = 0;

  /**
   * @brief 在没有实际运行的情况下，也就是无法获取tuple的情况下，尝试获取表达式的值
   * @details 有些表达式的值是固定的，比如ValueExpr，这种情况下可以直接获取值
   */
  virtual RC try_get_value(Value &value) const { return RC::UNIMPLEMENTED; }

  /**
   * @brief 从 `chunk` 中获取表达式的计算结果 `column`
   */
  virtual RC get_column(Chunk &chunk, Column &column) { return RC::UNIMPLEMENTED; }

  /**
   * @brief 表达式的类型
   * 可以根据表达式类型来转换为具体的子类
   */
  virtual ExprType type() const = 0;

  /**
   * @brief 表达式值的类型
   * @details 一个表达式运算出结果后，只有一个值
   */
  virtual AttrType value_type() const = 0;

  /**
   * @brief 表达式值的长度
   */
  virtual int value_length() const { return -1; }

  /**
   * @brief 表达式的名字，比如是字段名称，或者用户在执行SQL语句时输入的内容
   */
  virtual const char *name() const { return name_.c_str(); }
  virtual const char *alias() const { return alias_.c_str(); }
  virtual void        set_name(std::string name) { name_ = name; }

  /**
   * @brief 表达式在下层算子返回的 chunk 中的位置
   */
  virtual int  pos() const { return pos_; }
  virtual void set_pos(int pos) { pos_ = pos; }

  /**
   * @brief 用于 ComparisonExpr 获得比较结果 `select`。
   */
  virtual RC eval(Chunk &chunk, std::vector<uint8_t> &select) { return RC::UNIMPLEMENTED; }
  virtual RC get(vector<Value>& temp){return RC::UNIMPLEMENTED;}
  virtual RC get_tuple_list(){return RC::UNIMPLEMENTED;};
  virtual bool is_tuple_list() { return true;}
  virtual  string getsqlresult(){return nullptr;}
  virtual  std::unordered_map<std::string, Table *> gettable( ){return {};}
  virtual void set_alias(std::string alias) { alias_ = alias; }
protected:
  /**
   * @brief 表达式在下层算子返回的 chunk 中的位置
   * @details 当 pos_ = -1 时表示下层算子没有在返回的 chunk 中计算出该表达式的计算结果，
   * 当 pos_ >= 0时表示在下层算子中已经计算出该表达式的值（比如聚合表达式），且该表达式对应的结果位于
   * chunk 中 下标为 pos_ 的列中。
   */
  int pos_ = -1;

private:
  std::string   name_;
  std::string   alias_;
};

class StarExpr : public Expression
{
public:
  StarExpr() : table_name_() {}
  StarExpr(const char *table_name) : table_name_(table_name) {}
  virtual ~StarExpr() = default;

  ExprType type() const override { return ExprType::STAR; }
  AttrType value_type() const override { return AttrType::UNDEFINED; }

  RC get_value(const Tuple &tuple, Value &value) const override { return RC::UNIMPLEMENTED; }  // 不需要实现

  const char *table_name() const { return table_name_.c_str(); }

  std::unique_ptr<Expression> deep_copy() const override
  {
    // 使用当前对象的 table_name_ 创建一个新的 StarExpr 对象
    return std::make_unique<StarExpr>(table_name_.c_str());
  }

private:
  std::string table_name_;
  std::string alias_;
};

class UnboundFieldExpr : public Expression
{
public:
  UnboundFieldExpr(const std::string &table_name, const std::string &field_name)
      : table_name_(table_name), field_name_(field_name)
  {}

  virtual ~UnboundFieldExpr() = default;

  ExprType type() const override { return ExprType::UNBOUND_FIELD; }
  AttrType value_type() const override { return AttrType::UNDEFINED; }

  RC get_value(const Tuple &tuple, Value &value) const override { return RC::INTERNAL; }

  const char *table_name() const { return table_name_.c_str(); }
  const char *field_name() const { return field_name_.c_str(); }

  // 实现 deep_copy 函数
  std::unique_ptr<Expression> deep_copy() const override
  {
    // 创建一个新的 UnboundFieldExpr 实例，并复制 table_name_ 和 field_name_
    return std::make_unique<UnboundFieldExpr>(table_name_, field_name_);
  }

private:
  std::string table_name_;
  std::string field_name_;
  std::string   alias_;
};

/**
 * @brief 字段表达式
 * @ingroup Expression
 */
class FieldExpr : public Expression
{
public:
  FieldExpr() = default;
  FieldExpr(const Table *table, const FieldMeta *field) : field_(table, field) {
    spec_ = TupleCellSpec(table_name(), field_name());
  }
  FieldExpr(const Field &field) : field_(field) { spec_ = TupleCellSpec(table_name(), field_name()); }


  virtual ~FieldExpr() = default;

  bool equal(const Expression &other) const override;

  ExprType type() const override { return ExprType::FIELD; }
  AttrType value_type() const override { return field_.attr_type(); }
  int      value_length() const override { return field_.meta()->len(); }

  Field &field() { return field_; }

  const Field &field() const { return field_; }

  const char *table_name() const { return field_.table_name(); }
  const char *field_name() const { return field_.field_name(); }

  RC get_column(Chunk &chunk, Column &column) override;

  RC get_value(const Tuple &tuple, Value &value) const override;

  FieldMeta get_field_meta() const { return *field_.meta(); }

  std::unique_ptr<Expression> deep_copy() const override
  {
    // 创建一个新的 FieldExpr 实例，拷贝 field_ 成员
    return std::make_unique<FieldExpr>(field_);
  }
private:
  Field field_;
  std::string   alias_;
  TupleCellSpec spec_;
};
class SubqueryExpr : public Expression
{
public:
  SubqueryExpr() = default;
  SubqueryExpr(const vector<Value> sql_result)  { 
    this->tuple_list = sql_result;
    this->is_tuple=true; 
  }
  SubqueryExpr(string sql_result,std::unordered_map<std::string, Table *> tables)
  {
    this->sql_result = sql_result;
    this->tables=tables;
  }

  SubqueryExpr(const std::vector<Value> &tuple_list, const std::string &sql_result, 
               const std::unordered_map<std::string, Table *> &tables)
      : tuple_list(tuple_list), sql_result(sql_result), tables(tables), is_tuple(!tuple_list.empty())
  {}

  virtual ~SubqueryExpr() = default;
  bool is_tuple_list(){return is_tuple;}
  
  bool equal(const Expression &other) const override ;

  ExprType type() const override { return ExprType::SUBQUERY; }
  RC get_value(const Tuple &tuple, Value &value) const override {return RC::UNIMPLEMENTED;}
  RC try_get_value(Value &value) const override { return RC::UNIMPLEMENTED; };
  AttrType value_type() const override 
  { 
    if(tuple_list.size()!=0){
      return tuple_list[0].attr_type(); 
    }
    else{
      return AttrType::FLOATS;
    }
  }
  // int   value_length() const override { return field_.meta()->len(); }
  RC get(vector<Value>& temp)
  {
     for(int i = 0;i<(int)tuple_list.size();i++){
      temp.emplace_back(tuple_list[i]);
     } 
     return RC::SUCCESS;
  }
  RC getsqlresult(string sql_result1){
    sql_result1=this->sql_result;
    return RC::SUCCESS;
  }
  string getsqlresult(){return sql_result;}
  std::unordered_map<std::string, Table *> gettable(){return tables;}
  std::unique_ptr<Expression> deep_copy() const override
  {
    // 拷贝 tuple_list 和 sql_result，tables 直接复制指针
    return std::make_unique<SubqueryExpr>(tuple_list, sql_result, tables);
  }
private:

  vector<Value> tuple_list;
  string sql_result="";
  std::unordered_map<std::string, Table *> tables;
  bool is_tuple=false;
};
/**
 * @brief 常量值表达式
 * @ingroup Expression
 */
class ValueExpr : public Expression
{
public:
  ValueExpr() = default;
  explicit ValueExpr(const Value &value) : value_(value) {}

  virtual ~ValueExpr() = default;

  bool equal(const Expression &other) const override;

  RC get_value(const Tuple &tuple, Value &value) const override;
  RC get_column(Chunk &chunk, Column &column) override;
  RC try_get_value(Value &value) const override
  {
    value = value_;
    return RC::SUCCESS;
  }

  ExprType type() const override { return ExprType::VALUE; }
  AttrType value_type() const override { return value_.attr_type(); }
  int      value_length() const override { return value_.length(); }

  void         get_value(Value &value) const { value = value_; }
  const Value &get_value() const { return value_; }
  std::unique_ptr<Expression> deep_copy() const override
  {
    return std::unique_ptr<ValueExpr>(new ValueExpr(*this));
  }

private:
  Value value_;
  std::string alias_;
};

/**
 * @brief 类型转换表达式
 * @ingroup Expression
 */
class CastExpr : public Expression
{
public:
  CastExpr(std::unique_ptr<Expression> child, AttrType cast_type);
  virtual ~CastExpr();

  ExprType type() const override { return ExprType::CAST; }

  RC get_value(const Tuple &tuple, Value &value) const override;

  RC try_get_value(Value &value) const override;

  AttrType value_type() const override { return cast_type_; }

  std::unique_ptr<Expression> &child() { return child_; }

  std::unique_ptr<Expression> deep_copy() const override
  {
    auto new_expr = std::make_unique<CastExpr>(child_->deep_copy(), cast_type_);
    new_expr->set_name(name());
    return new_expr;
  }

private:
  RC cast(const Value &value, Value &cast_value) const;

private:
  std::unique_ptr<Expression> child_;      ///< 从这个表达式转换
  AttrType                    cast_type_;  ///< 想要转换成这个类型
  std::string alias_;
};

/**
 * @brief 比较表达式
 * @ingroup Expression
 */
class ComparisonExpr : public Expression
{
public:
  ComparisonExpr(CompOp comp, std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);
  virtual ~ComparisonExpr();

  ExprType type() const override { return ExprType::COMPARISON; }
  RC       get_value(const Tuple &tuple, Value &value) const override;
  AttrType value_type() const override { return AttrType::BOOLEANS; }
  CompOp   comp() const { return comp_; }

  /**
   * @brief 根据 ComparisonExpr 获得 `select` 结果。
   * select 的长度与chunk 的行数相同，表示每一行在ComparisonExpr 计算后是否会被输出。
   */
  RC eval(Chunk &chunk, std::vector<uint8_t> &select) override;

  std::unique_ptr<Expression> &left() { return left_; }
  std::unique_ptr<Expression> &right() { return right_; }
  std::unique_ptr<Expression> deep_copy() const override
  {
    std::unique_ptr<Expression> new_left = left_ ->deep_copy();
    std::unique_ptr<Expression> new_right;
    if (right_) { // NOTE: not has_rhs
      new_right = right_->deep_copy();
    }
    auto new_expr = std::make_unique<ComparisonExpr>(comp_, std::move(new_left), std::move(new_right));
    new_expr->set_name(name());
    return new_expr;
  }

  /**
   * 尝试在没有tuple的情况下获取当前表达式的值
   * 在优化的时候，可能会使用到
   */
  RC try_get_value(Value &value) const override;

  /**
   * compare the two tuple cells
   * @param value the result of comparison
   */
  RC compare_value(const Value &left, const Value &right, bool &value) const;

  template <typename T>
  RC compare_column(const Column &left, const Column &right, std::vector<uint8_t> &result) const;

private:
  CompOp                      comp_;
  std::unique_ptr<Expression> left_;
  std::unique_ptr<Expression> right_;
  std::string alias_;
};

/**
 * @brief 联结表达式
 * @ingroup Expression
 * 多个表达式使用同一种关系(AND或OR)来联结
 * 当前miniob仅有AND操作
 */
class ConjunctionExpr : public Expression
{
public:
  enum class Type
  {
    AND,
    OR,
  };

public:
  ConjunctionExpr(Type type, std::vector<std::unique_ptr<Expression>> &children);
  virtual ~ConjunctionExpr() = default;

  ExprType type() const override { return ExprType::CONJUNCTION; }
  AttrType value_type() const override { return AttrType::BOOLEANS; }
  RC       get_value(const Tuple &tuple, Value &value) const override;

  Type conjunction_type() const { return conjunction_type_; }

  std::vector<std::unique_ptr<Expression>> &children() { return children_; }

  std::unique_ptr<Expression> deep_copy() const override
  {
    std::vector<std::unique_ptr<Expression>> new_children;
    for (auto& child : children_) {
      new_children.emplace_back(child->deep_copy());
    }
    auto new_expr = std::make_unique<ConjunctionExpr>(conjunction_type_, new_children);
    new_expr->set_name(name());
    return new_expr;
  }
private:
  Type                                     conjunction_type_;
  std::vector<std::unique_ptr<Expression>> children_;
  std::string alias_;
};

/**
 * @brief 算术表达式
 * @ingroup Expression
 */
class ArithmeticExpr : public Expression
{
public:
  enum class Type
  {
    ADD,
    SUB,
    MUL,
    DIV,
    NEGATIVE,
  };

public:

  // 拷贝构造函数
  ArithmeticExpr();
  ArithmeticExpr(Type type, Expression *left, Expression *right);
  ArithmeticExpr(Type type, std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);
  virtual ~ArithmeticExpr() = default;

  bool     equal(const Expression &other) const override;
  ExprType type() const override { return ExprType::ARITHMETIC; }

  AttrType value_type() const override;
  int      value_length() const override
  {
    if (!right_) {
      return left_->value_length();
    }
    return 4;  // sizeof(float) or sizeof(int)
  };

  std::unique_ptr<Expression> deep_copy() const override
  {
    std::unique_ptr<Expression> new_left = left_ ->deep_copy();
    std::unique_ptr<Expression> new_right;
    if (right_) { // NOTE: not has_rhs
      new_right = right_->deep_copy();
    }
    auto new_expr = std::make_unique<ArithmeticExpr>(arithmetic_type_, std::move(new_left), std::move(new_right));
    new_expr->set_name(name());
    return new_expr;
  }

  RC get_value(const Tuple &tuple, Value &value) const override;

  RC get_column(Chunk &chunk, Column &column) override;

  RC try_get_value(Value &value) const override;

  Type arithmetic_type() const { return arithmetic_type_; }

  std::unique_ptr<Expression> &left() { return left_; }
  std::unique_ptr<Expression> &right() { return right_; }

private:
  RC calc_value(const Value &left_value, const Value &right_value, Value &value) const;

  RC calc_column(const Column &left_column, const Column &right_column, Column &column) const;

  template <bool LEFT_CONSTANT, bool RIGHT_CONSTANT>
  RC execute_calc(const Column &left, const Column &right, Column &result, Type type, AttrType attr_type) const;

private:
  Type                        arithmetic_type_;
  std::unique_ptr<Expression> left_;
  std::unique_ptr<Expression> right_;
  std::string   alias_;
};

class UnboundAggregateExpr : public Expression
{
public:
  UnboundAggregateExpr(const char *aggregate_name, std::vector<std::unique_ptr<Expression> >*child);
  virtual ~UnboundAggregateExpr() = default;

  ExprType type() const override { return ExprType::UNBOUND_AGGREGATION; }

  const char *aggregate_name() const { return aggregate_name_.c_str(); }
  void set_aggregate_name(const char *aggregate_name)
  {
      aggregate_name_ = aggregate_name;
  }

  std::unique_ptr<Expression>  &child() { return child_; }

  RC       get_value(const Tuple &tuple, Value &value) const override { return RC::INTERNAL; }
  AttrType value_type() const override { return child_->value_type(); }
  
  bool is_error(){return error_;}
  
	std::unique_ptr<Expression> deep_copy() const override {
	   // Deep copy the aggregate name
	   std::string new_aggregate_name(aggregate_name_);
	   // Deep copy the children
	   std::vector<std::unique_ptr<Expression>> new_children;
	   if (childs_ && !childs_->empty()) { // Ensure childs_ is not null and not empty
	       for (const auto& child : *childs_) {
            if(child)
	            new_children.emplace_back(child->deep_copy());
            else
	            new_children.emplace_back(nullptr);
	       }
	   }
	   // Create a new UnboundAggregateExpr with the deep copied data
	   // Note: We pass the address of the new_children vector, but we need to ensure it remains valid
	   auto new_expr = std::make_unique<UnboundAggregateExpr>(new_aggregate_name.c_str(), &new_children);
	   // Manually set the child since the constructor moves the first child
	   if (!new_children.empty()) {
	       new_expr->child_ = std::move(child_->deep_copy());
	   }
	   // Copy the error state
	   new_expr->error_ = error_;
     new_expr->set_name(name());
     new_expr->set_aggregate_name(aggregate_name());
	   // Ensure the new_children vector is not used after this point
	   // to avoid dangling references
	   new_children.clear();
	   return new_expr;
	}

private:
  std::string                 aggregate_name_;
  std::vector<std::unique_ptr<Expression> >* childs_;
  std::unique_ptr<Expression> child_ = nullptr;
  bool                   error_ = false;
  std::string alias_;
};

class AggregateExpr : public Expression
{
public:
  enum class Type
  {
    COUNT,
    SUM,
    AVG,
    MAX,
    MIN,
  };

public:
  AggregateExpr(Type type, Expression *child);
  AggregateExpr(Type type, std::unique_ptr<Expression> child);
  virtual ~AggregateExpr() = default;

  bool equal(const Expression &other) const override;
  

  ExprType type() const override { return ExprType::AGGREGATION; }

  AttrType value_type() const override { return child_->value_type(); }
  int      value_length() const override { return child_->value_length(); }

  RC get_value(const Tuple &tuple, Value &value) const override;

  RC get_column(Chunk &chunk, Column &column) override;

  Type aggregate_type() const { return aggregate_type_; }

  std::unique_ptr<Expression> &child() { return child_; }

  const std::unique_ptr<Expression> &child() const { return child_; }

  std::unique_ptr<Aggregator> create_aggregator() const;

  std::unique_ptr<Expression> deep_copy() const override
  {
    auto new_expr = std::make_unique<AggregateExpr>(aggregate_type_,child_->deep_copy());
    new_expr->set_name(name());
    return new_expr;
  }

public:
  static RC type_from_string(const char *type_str, Type &type);

private:
  Type                        aggregate_type_;
  std::unique_ptr<Expression> child_;
  std::string alias_;
};

class FunctionExpr : public Expression {
public:
  FunctionExpr() = default;
  FunctionExpr(FuncOp func_type, std::vector<Expression*>& params) : func_type_(func_type)
  {
    for (auto expr: params) {
      params_.emplace_back(expr);
    }
  }
  FunctionExpr(FuncOp func_type, std::vector<std::unique_ptr<Expression>> params) : func_type_(func_type), params_(std::move(params)) {}
  
  virtual ~FunctionExpr() = default;
  
  AttrType value_type() const override;
  ExprType type() const override { return ExprType::FUNCTION; }
  
  FuncOp func_type() const { return func_type_; }
  std::vector<std::unique_ptr<Expression>> &children() { return params_; }

  RC get_I2_value(const Tuple &tuple, Value &value) const;
  RC get_COSINE_value(const Tuple &tuple, Value &value) const;
  RC get_INNER_value(const Tuple &tuple, Value &value) const;
  
  RC get_value(const Tuple &tuple, Value &value) const override;
  RC calc_value(const Value &left_value, const Value &right_value, Value &value) const;
  RC check_param() const;
  std::vector<std::unique_ptr<Expression>> get_params(){return std::move(this->params_);}

  // Deep copy constructor
	FunctionExpr(const FunctionExpr& other) : func_type_(other.func_type_) {
	  for (const auto& expr : other.params_) {
	    params_.emplace_back(expr->deep_copy()); // Assuming Expression has a virtual deep_copy method
	  }
	}
	 
	// Deep copy assignment operator
	FunctionExpr& operator=(const FunctionExpr& other) {
	  if (this != &other) {
	    func_type_ = other.func_type_;
	    params_.clear();
	    for (const auto& expr : other.params_) {
	      params_.emplace_back(expr->deep_copy()); // Assuming Expression has a virtual deep_copy method
	    }
	  }
	  return *this;
	}
	 
	// Method to create a deep copy of the current object
	std::unique_ptr<Expression> deep_copy() const override {
	  return std::make_unique<FunctionExpr>(*this);
	}
    
private:
  FuncOp func_type_;
  std::vector<std::unique_ptr<Expression>> params_; 
  std::string alias_;
};