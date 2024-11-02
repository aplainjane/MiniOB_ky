/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_YACC_SQL_HPP_INCLUDED
# define YY_YY_YACC_SQL_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SEMICOLON = 258,               /* SEMICOLON  */
    BY = 259,                      /* BY  */
    CREATE = 260,                  /* CREATE  */
    DROP = 261,                    /* DROP  */
    GROUP = 262,                   /* GROUP  */
    ORDER = 263,                   /* ORDER  */
    TABLE = 264,                   /* TABLE  */
    TABLES = 265,                  /* TABLES  */
    UNIQUE = 266,                  /* UNIQUE  */
    INDEX = 267,                   /* INDEX  */
    CALC = 268,                    /* CALC  */
    SELECT = 269,                  /* SELECT  */
    ASC = 270,                     /* ASC  */
    DESC = 271,                    /* DESC  */
    SHOW = 272,                    /* SHOW  */
    SYNC = 273,                    /* SYNC  */
    INSERT = 274,                  /* INSERT  */
    DELETE = 275,                  /* DELETE  */
    UPDATE = 276,                  /* UPDATE  */
    LBRACE = 277,                  /* LBRACE  */
    RBRACE = 278,                  /* RBRACE  */
    COMMA = 279,                   /* COMMA  */
    TRX_BEGIN = 280,               /* TRX_BEGIN  */
    TRX_COMMIT = 281,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 282,            /* TRX_ROLLBACK  */
    INT_T = 283,                   /* INT_T  */
    STRING_T = 284,                /* STRING_T  */
    DATE_T = 285,                  /* DATE_T  */
    TEXT_T = 286,                  /* TEXT_T  */
    FLOAT_T = 287,                 /* FLOAT_T  */
    VECTOR_T = 288,                /* VECTOR_T  */
    HELP = 289,                    /* HELP  */
    EXIT = 290,                    /* EXIT  */
    DOT = 291,                     /* DOT  */
    INTO = 292,                    /* INTO  */
    VALUES = 293,                  /* VALUES  */
    FROM = 294,                    /* FROM  */
    WHERE = 295,                   /* WHERE  */
    HAVING = 296,                  /* HAVING  */
    AND = 297,                     /* AND  */
    SET = 298,                     /* SET  */
    ON = 299,                      /* ON  */
    LOAD = 300,                    /* LOAD  */
    DATA = 301,                    /* DATA  */
    INFILE = 302,                  /* INFILE  */
    EXPLAIN = 303,                 /* EXPLAIN  */
    STORAGE = 304,                 /* STORAGE  */
    FORMAT = 305,                  /* FORMAT  */
    NOT = 306,                     /* NOT  */
    LIKE = 307,                    /* LIKE  */
    IN = 308,                      /* IN  */
    IS = 309,                      /* IS  */
    EXIST = 310,                   /* EXIST  */
    NULL_KY = 311,                 /* NULL_KY  */
    INNER = 312,                   /* INNER  */
    JOIN = 313,                    /* JOIN  */
    EQ = 314,                      /* EQ  */
    LT = 315,                      /* LT  */
    GT = 316,                      /* GT  */
    LE = 317,                      /* LE  */
    GE = 318,                      /* GE  */
    NE = 319,                      /* NE  */
    I2_DISTANCE_T = 320,           /* I2_DISTANCE_T  */
    COSINE_DISTANCE_T = 321,       /* COSINE_DISTANCE_T  */
    INNER_PRODUCT_T = 322,         /* INNER_PRODUCT_T  */
    SUM = 323,                     /* SUM  */
    AVG = 324,                     /* AVG  */
    COUNT = 325,                   /* COUNT  */
    MAX = 326,                     /* MAX  */
    MIN = 327,                     /* MIN  */
    NUMBER = 328,                  /* NUMBER  */
    FLOAT = 329,                   /* FLOAT  */
    ID = 330,                      /* ID  */
    SSS = 331,                     /* SSS  */
    SUB_QUERY = 332,               /* SUB_QUERY  */
    VECTOR_LIST = 333,             /* VECTOR_LIST  */
    UMINUS = 334                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 141 "yacc_sql.y"

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
  std::vector<std::unique_ptr<Expression>> * expression_list;
  std::vector<Value> *                       value_list;
  std::vector<ConditionSqlNode> *            condition_list;
  std::vector<RelAttrSqlNode> *              rel_attr_list;
  std::vector<std::string> *                 relation_list;
  char *                                     string;
  int                                        number;
  float                                      floats;
  bool                                       boolean;

#line 169 "yacc_sql.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner);


#endif /* !YY_YY_YACC_SQL_HPP_INCLUDED  */
