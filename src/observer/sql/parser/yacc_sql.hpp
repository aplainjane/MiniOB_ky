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
<<<<<<< HEAD
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
    FLOAT_T = 286,                 /* FLOAT_T  */
    VECTOR_T = 287,                /* VECTOR_T  */
    HELP = 288,                    /* HELP  */
    EXIT = 289,                    /* EXIT  */
    DOT = 290,                     /* DOT  */
    INTO = 291,                    /* INTO  */
    VALUES = 292,                  /* VALUES  */
    FROM = 293,                    /* FROM  */
    WHERE = 294,                   /* WHERE  */
    HAVING = 295,                  /* HAVING  */
    AND = 296,                     /* AND  */
    SET = 297,                     /* SET  */
    ON = 298,                      /* ON  */
    LOAD = 299,                    /* LOAD  */
    DATA = 300,                    /* DATA  */
    INFILE = 301,                  /* INFILE  */
    EXPLAIN = 302,                 /* EXPLAIN  */
    STORAGE = 303,                 /* STORAGE  */
    FORMAT = 304,                  /* FORMAT  */
    NOT = 305,                     /* NOT  */
    LIKE = 306,                    /* LIKE  */
    IN = 307,                      /* IN  */
    IS = 308,                      /* IS  */
    EXIST = 309,                   /* EXIST  */
    NULL_KY = 310,                 /* NULL_KY  */
    INNER = 311,                   /* INNER  */
    JOIN = 312,                    /* JOIN  */
    EQ = 313,                      /* EQ  */
    LT = 314,                      /* LT  */
    GT = 315,                      /* GT  */
    LE = 316,                      /* LE  */
    GE = 317,                      /* GE  */
    NE = 318,                      /* NE  */
    SUM = 319,                     /* SUM  */
    AVG = 320,                     /* AVG  */
    COUNT = 321,                   /* COUNT  */
    MAX = 322,                     /* MAX  */
    MIN = 323,                     /* MIN  */
    NUMBER = 324,                  /* NUMBER  */
    FLOAT = 325,                   /* FLOAT  */
    ID = 326,                      /* ID  */
    SSS = 327,                     /* SSS  */
    SUB_QUERY = 328,               /* SUB_QUERY  */
    VECTOR_LIST = 329,             /* VECTOR_LIST  */
    UMINUS = 330                   /* UMINUS  */
=======
    TABLE = 263,                   /* TABLE  */
    TABLES = 264,                  /* TABLES  */
    UNIQUE = 265,                  /* UNIQUE  */
    INDEX = 266,                   /* INDEX  */
    CALC = 267,                    /* CALC  */
    SELECT = 268,                  /* SELECT  */
    DESC = 269,                    /* DESC  */
    SHOW = 270,                    /* SHOW  */
    SYNC = 271,                    /* SYNC  */
    INSERT = 272,                  /* INSERT  */
    DELETE = 273,                  /* DELETE  */
    UPDATE = 274,                  /* UPDATE  */
    LBRACE = 275,                  /* LBRACE  */
    RBRACE = 276,                  /* RBRACE  */
    COMMA = 277,                   /* COMMA  */
    TRX_BEGIN = 278,               /* TRX_BEGIN  */
    TRX_COMMIT = 279,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 280,            /* TRX_ROLLBACK  */
    INT_T = 281,                   /* INT_T  */
    STRING_T = 282,                /* STRING_T  */
    DATE_T = 283,                  /* DATE_T  */
    FLOAT_T = 284,                 /* FLOAT_T  */
    VECTOR_T = 285,                /* VECTOR_T  */
    HELP = 286,                    /* HELP  */
    EXIT = 287,                    /* EXIT  */
    DOT = 288,                     /* DOT  */
    INTO = 289,                    /* INTO  */
    VALUES = 290,                  /* VALUES  */
    FROM = 291,                    /* FROM  */
    WHERE = 292,                   /* WHERE  */
    HAVING = 293,                  /* HAVING  */
    AND = 294,                     /* AND  */
    SET = 295,                     /* SET  */
    ON = 296,                      /* ON  */
    LOAD = 297,                    /* LOAD  */
    DATA = 298,                    /* DATA  */
    INFILE = 299,                  /* INFILE  */
    EXPLAIN = 300,                 /* EXPLAIN  */
    STORAGE = 301,                 /* STORAGE  */
    FORMAT = 302,                  /* FORMAT  */
    NOT = 303,                     /* NOT  */
    LIKE = 304,                    /* LIKE  */
    IN = 305,                      /* IN  */
    IS = 306,                      /* IS  */
    EXIST = 307,                   /* EXIST  */
    NULL_KY = 308,                 /* NULL_KY  */
    INNER = 309,                   /* INNER  */
    JOIN = 310,                    /* JOIN  */
    EQ = 311,                      /* EQ  */
    LT = 312,                      /* LT  */
    GT = 313,                      /* GT  */
    LE = 314,                      /* LE  */
    GE = 315,                      /* GE  */
    NE = 316,                      /* NE  */
    I2_DISTANCE_T = 317,           /* I2_DISTANCE_T  */
    COSINE_DISTANCE_T = 318,       /* COSINE_DISTANCE_T  */
    INNER_PRODUCT_T = 319,         /* INNER_PRODUCT_T  */
    SUM = 320,                     /* SUM  */
    AVG = 321,                     /* AVG  */
    COUNT = 322,                   /* COUNT  */
    MAX = 323,                     /* MAX  */
    MIN = 324,                     /* MIN  */
    NUMBER = 325,                  /* NUMBER  */
    FLOAT = 326,                   /* FLOAT  */
    ID = 327,                      /* ID  */
    SSS = 328,                     /* SSS  */
    SUB_QUERY = 329,               /* SUB_QUERY  */
    VECTOR_LIST = 330,             /* VECTOR_LIST  */
    UMINUS = 331                   /* UMINUS  */
>>>>>>> 06e2e8a3bc1a8d8a816712cc6bede5bce36e2ae7
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
<<<<<<< HEAD
#line 137 "yacc_sql.y"
=======
#line 138 "yacc_sql.y"
>>>>>>> 06e2e8a3bc1a8d8a816712cc6bede5bce36e2ae7

  ParsedSqlNode *                            sql_node;
  ConditionSqlNode *                         condition;
  JoinSqlNode *                              join_sql_node;
  Value *                                    value;  
  enum CompOp                                comp;
<<<<<<< HEAD
  enum OrderOp                               orderOp;
=======
  enum FuncOp                                func;
>>>>>>> 06e2e8a3bc1a8d8a816712cc6bede5bce36e2ae7
  RelAttrSqlNode *                           rel_attr;
  std::vector<AttrInfoSqlNode> *             attr_infos;
  AttrInfoSqlNode *                          attr_info;
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

#line 164 "yacc_sql.hpp"

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
