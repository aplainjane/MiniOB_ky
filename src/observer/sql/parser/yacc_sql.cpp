/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


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


#line 126 "yacc_sql.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_BY = 4,                         /* BY  */
  YYSYMBOL_CREATE = 5,                     /* CREATE  */
  YYSYMBOL_DROP = 6,                       /* DROP  */
  YYSYMBOL_GROUP = 7,                      /* GROUP  */
  YYSYMBOL_ORDER = 8,                      /* ORDER  */
  YYSYMBOL_TABLE = 9,                      /* TABLE  */
  YYSYMBOL_TABLES = 10,                    /* TABLES  */
  YYSYMBOL_UNIQUE = 11,                    /* UNIQUE  */
  YYSYMBOL_INDEX = 12,                     /* INDEX  */
  YYSYMBOL_CALC = 13,                      /* CALC  */
  YYSYMBOL_SELECT = 14,                    /* SELECT  */
  YYSYMBOL_ASC = 15,                       /* ASC  */
  YYSYMBOL_DESC = 16,                      /* DESC  */
  YYSYMBOL_SHOW = 17,                      /* SHOW  */
  YYSYMBOL_SYNC = 18,                      /* SYNC  */
  YYSYMBOL_INSERT = 19,                    /* INSERT  */
  YYSYMBOL_DELETE = 20,                    /* DELETE  */
  YYSYMBOL_UPDATE = 21,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 22,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 23,                    /* RBRACE  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 25,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 26,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 27,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 28,                     /* INT_T  */
  YYSYMBOL_STRING_T = 29,                  /* STRING_T  */
  YYSYMBOL_DATE_T = 30,                    /* DATE_T  */
  YYSYMBOL_TEXT_T = 31,                    /* TEXT_T  */
  YYSYMBOL_FLOAT_T = 32,                   /* FLOAT_T  */
  YYSYMBOL_VECTOR_T = 33,                  /* VECTOR_T  */
  YYSYMBOL_HELP = 34,                      /* HELP  */
  YYSYMBOL_EXIT = 35,                      /* EXIT  */
  YYSYMBOL_DOT = 36,                       /* DOT  */
  YYSYMBOL_INTO = 37,                      /* INTO  */
  YYSYMBOL_VALUES = 38,                    /* VALUES  */
  YYSYMBOL_FROM = 39,                      /* FROM  */
  YYSYMBOL_WHERE = 40,                     /* WHERE  */
  YYSYMBOL_HAVING = 41,                    /* HAVING  */
  YYSYMBOL_AND = 42,                       /* AND  */
  YYSYMBOL_OR = 43,                        /* OR  */
  YYSYMBOL_SET = 44,                       /* SET  */
  YYSYMBOL_ON = 45,                        /* ON  */
  YYSYMBOL_LOAD = 46,                      /* LOAD  */
  YYSYMBOL_DATA = 47,                      /* DATA  */
  YYSYMBOL_INFILE = 48,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 49,                   /* EXPLAIN  */
  YYSYMBOL_STORAGE = 50,                   /* STORAGE  */
  YYSYMBOL_FORMAT = 51,                    /* FORMAT  */
  YYSYMBOL_NOT = 52,                       /* NOT  */
  YYSYMBOL_LIKE = 53,                      /* LIKE  */
  YYSYMBOL_IN = 54,                        /* IN  */
  YYSYMBOL_IS = 55,                        /* IS  */
  YYSYMBOL_EXIST = 56,                     /* EXIST  */
  YYSYMBOL_NULL_KY = 57,                   /* NULL_KY  */
  YYSYMBOL_INNER = 58,                     /* INNER  */
  YYSYMBOL_JOIN = 59,                      /* JOIN  */
  YYSYMBOL_AS = 60,                        /* AS  */
  YYSYMBOL_EQ = 61,                        /* EQ  */
  YYSYMBOL_LT = 62,                        /* LT  */
  YYSYMBOL_GT = 63,                        /* GT  */
  YYSYMBOL_LE = 64,                        /* LE  */
  YYSYMBOL_GE = 65,                        /* GE  */
  YYSYMBOL_NE = 66,                        /* NE  */
  YYSYMBOL_I2_DISTANCE_T = 67,             /* I2_DISTANCE_T  */
  YYSYMBOL_COSINE_DISTANCE_T = 68,         /* COSINE_DISTANCE_T  */
  YYSYMBOL_INNER_PRODUCT_T = 69,           /* INNER_PRODUCT_T  */
  YYSYMBOL_WITH = 70,                      /* WITH  */
  YYSYMBOL_DISTANCE = 71,                  /* DISTANCE  */
  YYSYMBOL_TYPE = 72,                      /* TYPE  */
  YYSYMBOL_LISTS = 73,                     /* LISTS  */
  YYSYMBOL_PROBES = 74,                    /* PROBES  */
  YYSYMBOL_LIMIT = 75,                     /* LIMIT  */
  YYSYMBOL_SUM = 76,                       /* SUM  */
  YYSYMBOL_AVG = 77,                       /* AVG  */
  YYSYMBOL_COUNT = 78,                     /* COUNT  */
  YYSYMBOL_MAX = 79,                       /* MAX  */
  YYSYMBOL_MIN = 80,                       /* MIN  */
  YYSYMBOL_NUMBER = 81,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 82,                     /* FLOAT  */
  YYSYMBOL_ID = 83,                        /* ID  */
  YYSYMBOL_SSS = 84,                       /* SSS  */
  YYSYMBOL_SUB_QUERY = 85,                 /* SUB_QUERY  */
  YYSYMBOL_VECTOR_LIST = 86,               /* VECTOR_LIST  */
  YYSYMBOL_87_ = 87,                       /* '+'  */
  YYSYMBOL_88_ = 88,                       /* '-'  */
  YYSYMBOL_89_ = 89,                       /* '*'  */
  YYSYMBOL_90_ = 90,                       /* '/'  */
  YYSYMBOL_UMINUS = 91,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 92,                  /* $accept  */
  YYSYMBOL_commands = 93,                  /* commands  */
  YYSYMBOL_command_wrapper = 94,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 95,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 96,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 97,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 98,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 99,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 100,            /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 101,          /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 102,         /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 103,          /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 104,        /* create_index_stmt  */
  YYSYMBOL_create_vec_index_stmt = 105,    /* create_vec_index_stmt  */
  YYSYMBOL_index_rel_list = 106,           /* index_rel_list  */
  YYSYMBOL_drop_index_stmt = 107,          /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 108,        /* create_table_stmt  */
  YYSYMBOL_as_option = 109,                /* as_option  */
  YYSYMBOL_attr_def_list = 110,            /* attr_def_list  */
  YYSYMBOL_attr_def = 111,                 /* attr_def  */
  YYSYMBOL_isnull = 112,                   /* isnull  */
  YYSYMBOL_number = 113,                   /* number  */
  YYSYMBOL_type = 114,                     /* type  */
  YYSYMBOL_insert_stmt = 115,              /* insert_stmt  */
  YYSYMBOL_value_list = 116,               /* value_list  */
  YYSYMBOL_value = 117,                    /* value  */
  YYSYMBOL_storage_format = 118,           /* storage_format  */
  YYSYMBOL_delete_stmt = 119,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 120,              /* update_stmt  */
  YYSYMBOL_set_clause_list = 121,          /* set_clause_list  */
  YYSYMBOL_set_clause = 122,               /* set_clause  */
  YYSYMBOL_select_stmt = 123,              /* select_stmt  */
  YYSYMBOL_calc_stmt = 124,                /* calc_stmt  */
  YYSYMBOL_alias = 125,                    /* alias  */
  YYSYMBOL_expression_list = 126,          /* expression_list  */
  YYSYMBOL_expression = 127,               /* expression  */
  YYSYMBOL_simple_expression = 128,        /* simple_expression  */
  YYSYMBOL_arith_expr = 129,               /* arith_expr  */
  YYSYMBOL_aggr_expr = 130,                /* aggr_expr  */
  YYSYMBOL_rel_attr = 131,                 /* rel_attr  */
  YYSYMBOL_rel_list = 132,                 /* rel_list  */
  YYSYMBOL_join_list = 133,                /* join_list  */
  YYSYMBOL_order_by = 134,                 /* order_by  */
  YYSYMBOL_vec_order_by = 135,             /* vec_order_by  */
  YYSYMBOL_order_by_list = 136,            /* order_by_list  */
  YYSYMBOL_order_op = 137,                 /* order_op  */
  YYSYMBOL_where = 138,                    /* where  */
  YYSYMBOL_condition_list = 139,           /* condition_list  */
  YYSYMBOL_condition = 140,                /* condition  */
  YYSYMBOL_is_null_choice = 141,           /* is_null_choice  */
  YYSYMBOL_comp_op = 142,                  /* comp_op  */
  YYSYMBOL_func_op = 143,                  /* func_op  */
  YYSYMBOL_group_by = 144,                 /* group_by  */
  YYSYMBOL_having = 145,                   /* having  */
  YYSYMBOL_load_data_stmt = 146,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 147,             /* explain_stmt  */
  YYSYMBOL_explain_vec_stmt = 148,         /* explain_vec_stmt  */
  YYSYMBOL_set_variable_stmt = 149,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 150             /* opt_semicolon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  82
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   815

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  208
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  432

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   342


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    89,    87,     2,    88,     2,    90,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    91
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   250,   250,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   283,   289,   294,   300,   306,
     312,   318,   325,   331,   339,   358,   380,   400,   403,   415,
     425,   454,   469,   480,   483,   490,   493,   506,   515,   528,
     531,   535,   542,   545,   546,   547,   548,   549,   550,   553,
     570,   573,   584,   588,   592,   598,   604,   610,   613,   620,
     632,   662,   668,   678,   685,   698,   706,   749,   789,   797,
     800,   803,   807,   816,   831,   835,   838,   841,   844,   847,
     852,   858,   861,   864,   867,   870,   875,   881,   886,   894,
     897,   900,   903,   906,   909,   912,   915,   918,   921,   924,
     927,   930,   933,   936,   939,   942,   945,   948,   951,   954,
     957,   960,   963,   966,   969,   972,   977,   980,   983,   986,
     989,   992,   998,  1004,  1010,  1016,  1025,  1030,  1041,  1044,
    1060,  1063,  1066,  1089,  1092,  1104,  1114,  1127,  1130,  1143,
    1144,  1145,  1151,  1155,  1161,  1164,  1169,  1174,  1183,  1192,
    1201,  1210,  1219,  1227,  1237,  1247,  1257,  1267,  1277,  1287,
    1297,  1312,  1327,  1342,  1357,  1372,  1387,  1407,  1416,  1425,
    1433,  1445,  1460,  1461,  1465,  1466,  1467,  1468,  1469,  1470,
    1471,  1472,  1473,  1474,  1475,  1476,  1480,  1481,  1482,  1486,
    1489,  1496,  1499,  1506,  1519,  1526,  1538,  1548,  1549
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "BY",
  "CREATE", "DROP", "GROUP", "ORDER", "TABLE", "TABLES", "UNIQUE", "INDEX",
  "CALC", "SELECT", "ASC", "DESC", "SHOW", "SYNC", "INSERT", "DELETE",
  "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN", "TRX_COMMIT",
  "TRX_ROLLBACK", "INT_T", "STRING_T", "DATE_T", "TEXT_T", "FLOAT_T",
  "VECTOR_T", "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE",
  "HAVING", "AND", "OR", "SET", "ON", "LOAD", "DATA", "INFILE", "EXPLAIN",
  "STORAGE", "FORMAT", "NOT", "LIKE", "IN", "IS", "EXIST", "NULL_KY",
  "INNER", "JOIN", "AS", "EQ", "LT", "GT", "LE", "GE", "NE",
  "I2_DISTANCE_T", "COSINE_DISTANCE_T", "INNER_PRODUCT_T", "WITH",
  "DISTANCE", "TYPE", "LISTS", "PROBES", "LIMIT", "SUM", "AVG", "COUNT",
  "MAX", "MIN", "NUMBER", "FLOAT", "ID", "SSS", "SUB_QUERY", "VECTOR_LIST",
  "'+'", "'-'", "'*'", "'/'", "UMINUS", "$accept", "commands",
  "command_wrapper", "exit_stmt", "help_stmt", "sync_stmt", "begin_stmt",
  "commit_stmt", "rollback_stmt", "drop_table_stmt", "show_tables_stmt",
  "desc_table_stmt", "create_index_stmt", "create_vec_index_stmt",
  "index_rel_list", "drop_index_stmt", "create_table_stmt", "as_option",
  "attr_def_list", "attr_def", "isnull", "number", "type", "insert_stmt",
  "value_list", "value", "storage_format", "delete_stmt", "update_stmt",
  "set_clause_list", "set_clause", "select_stmt", "calc_stmt", "alias",
  "expression_list", "expression", "simple_expression", "arith_expr",
  "aggr_expr", "rel_attr", "rel_list", "join_list", "order_by",
  "vec_order_by", "order_by_list", "order_op", "where", "condition_list",
  "condition", "is_null_choice", "comp_op", "func_op", "group_by",
  "having", "load_data_stmt", "explain_stmt", "explain_vec_stmt",
  "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-325)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-99)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     740,    23,    16,   513,   513,   -56,    21,  -325,     4,    12,
     -26,  -325,  -325,  -325,  -325,  -325,   -23,    15,    -2,    64,
      67,  -325,  -325,  -325,  -325,  -325,  -325,  -325,  -325,  -325,
    -325,  -325,  -325,  -325,  -325,  -325,  -325,  -325,  -325,  -325,
    -325,  -325,  -325,    29,    90,    48,   127,    78,    94,   513,
    -325,  -325,  -325,  -325,   161,   164,   165,   170,   173,  -325,
    -325,   160,  -325,  -325,   513,  -325,  -325,  -325,   -40,  -325,
    -325,   175,   171,  -325,  -325,   116,   118,   172,   179,   185,
     513,  -325,  -325,  -325,  -325,    -1,   159,   200,   177,  -325,
     219,   101,   240,   342,   375,   411,   444,   -53,  -325,   189,
    -325,   513,   513,   513,   513,   247,   480,   190,   242,   241,
     208,   666,   214,   257,   227,  -325,   301,   280,   244,   286,
     249,  -325,  -325,   312,  -325,   314,  -325,   315,  -325,   317,
    -325,   318,  -325,  -325,  -325,   -10,   -10,  -325,  -325,   513,
    -325,   320,   -38,   322,   528,  -325,   291,     0,  -325,  -325,
     310,   270,   225,   326,  -325,   279,   354,   296,  -325,  -325,
    -325,  -325,  -325,  -325,  -325,  -325,   356,   666,   543,   345,
     716,   543,   749,    -5,   453,   716,   749,  -325,    45,   184,
     208,  -325,   373,   241,  -325,  -325,  -325,  -325,  -325,  -325,
       1,   227,   360,   365,   306,   368,   308,    38,   369,   543,
      81,   115,  -325,   313,    19,  -325,  -325,  -325,  -325,  -325,
    -325,  -325,  -325,  -325,    -9,  -325,    44,    55,   -15,  -325,
     561,   576,   593,   606,   614,   626,   634,   644,   656,   543,
     714,  -325,   289,   528,   528,  -325,  -325,  -325,   319,   392,
     323,   344,  -325,  -325,   326,     5,   324,   379,   331,   -38,
      38,   332,   241,   666,   383,   393,  -325,  -325,  -325,  -325,
     666,  -325,  -325,   370,  -325,   543,   135,   188,   216,   543,
      44,    55,   543,    44,    55,   543,  -325,  -325,   543,  -325,
    -325,   543,    44,    55,   543,    44,    55,   543,  -325,  -325,
     543,  -325,  -325,   135,   188,   216,  -325,  -325,  -325,   543,
    -325,   135,   188,   216,  -325,  -325,  -325,   413,  -325,  -325,
     406,  -325,  -325,   384,   301,  -325,   379,   353,   414,   415,
     356,  -325,   -38,   432,   369,  -325,   716,   369,  -325,    81,
     119,   125,   131,   149,   162,   205,   212,   267,    81,    83,
     -13,   380,  -325,   417,   379,  -325,   376,  -325,   400,   443,
     408,  -325,   391,   427,   437,  -325,  -325,  -325,  -325,  -325,
    -325,  -325,  -325,   439,   447,  -325,   382,  -325,  -325,   448,
     528,   513,   528,   463,   666,  -325,  -325,  -325,  -325,  -325,
    -325,   277,  -325,   409,    38,  -325,  -325,   478,  -325,  -325,
     369,   459,   460,   424,  -325,   111,   473,   403,   666,   421,
     140,  -325,   475,   485,   486,  -325,  -325,   505,   456,   461,
     467,   403,  -325,   323,   323,   483,   140,  -325,  -325,    83,
     505,   510,  -325,   466,   484,   465,   527,   479,   491,   474,
     531,  -325
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    28,    29,    30,    26,    25,     0,     0,     0,     0,
     207,    24,    23,    15,    16,    17,    18,     9,    10,    11,
      12,    13,    14,     8,     5,     7,     6,     4,     3,    19,
      20,    21,    22,     0,     0,     0,     0,     0,     0,     0,
      66,   196,   197,   198,     0,     0,     0,     0,     0,    62,
      63,   136,    64,    65,     0,    91,    89,    78,    79,    94,
      90,     0,    75,    33,    32,     0,     0,     0,     0,     0,
       0,   204,     1,   208,     2,    43,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
      80,     0,     0,     0,     0,    82,     0,     0,     0,   152,
       0,     0,     0,     0,     0,    44,     0,     0,     0,     0,
       0,    84,   131,     0,   132,     0,   135,     0,   134,     0,
     133,     0,   137,    92,    81,    85,    86,    87,    88,     0,
      96,     0,    79,     0,   154,    69,     0,   152,    71,   206,
       0,     0,     0,    45,    42,     0,     0,     0,    39,   126,
     127,   130,   128,   129,    83,    95,   138,     0,     0,   136,
       0,     0,    97,     0,     0,     0,    98,   153,   155,     0,
       0,    70,     0,   152,    53,    54,    57,    58,    55,    56,
      49,     0,     0,     0,     0,     0,     0,   140,    60,     0,
      97,     0,    98,     0,     0,   190,   192,   194,   184,   185,
     186,   187,   188,   189,     0,    97,   109,   108,     0,   180,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,     0,   154,   154,    74,    73,    72,     0,     0,
       0,     0,    50,    48,    45,    67,     0,    37,     0,    79,
     140,     0,   152,     0,     0,     0,    99,   191,   193,   195,
       0,   169,   168,     0,   182,     0,   164,   160,   166,     0,
     122,   114,     0,   123,   115,     0,   124,   116,     0,   125,
     117,     0,   110,   118,     0,   111,   119,     0,   112,   120,
       0,   113,   121,   158,   162,   159,   177,   179,   178,     0,
     167,   163,   161,   165,   156,   157,   203,     0,   205,    52,
       0,    51,    46,     0,     0,    40,    37,     0,     0,     0,
     138,   141,    79,   199,    60,    59,     0,    60,   183,    97,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
      49,     0,    41,     0,    37,    34,     0,   139,     0,     0,
     201,    61,     0,     0,     0,   104,   105,   106,   107,   100,
     101,   102,   103,     0,     0,    47,     0,    35,    38,     0,
     154,     0,   154,   143,     0,   175,   173,   174,   172,   170,
     171,     0,    68,     0,   140,   200,   202,     0,    76,    77,
      60,     0,     0,     0,   142,     0,     0,     0,     0,     0,
     151,   176,     0,     0,     0,   150,   149,   147,     0,     0,
       0,     0,   144,     0,     0,     0,   151,   146,   145,     0,
     147,     0,   148,     0,     0,     0,     0,     0,     0,     0,
       0,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -325,  -325,  -325,  -325,  -325,  -325,  -325,  -325,  -325,  -325,
    -325,  -325,  -325,  -325,  -290,  -325,  -325,   327,   329,   385,
     231,  -254,  -325,  -325,  -192,    14,  -325,  -325,  -325,  -325,
     387,  -114,  -325,  -138,    34,   -35,    61,   -58,  -111,    -3,
     254,  -241,  -325,   202,   157,   163,  -131,  -223,  -325,   402,
    -169,  -324,  -325,  -325,  -325,  -325,  -325,  -325,  -325
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,   318,    32,    33,   116,   192,   153,
     243,   310,   190,    34,   254,   215,   315,    35,    36,   147,
     148,    37,    38,   105,    67,    68,   173,   201,    69,   202,
     197,   252,   388,   308,   412,   407,   145,   177,   178,   219,
     214,    71,   350,   373,    39,    40,    41,    42,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    70,   154,   220,   166,   229,   230,   232,   255,   321,
     304,   305,    80,   260,    91,   364,   181,    66,    66,   -43,
      99,   114,    99,   240,   180,    47,   343,    73,    48,    98,
     132,    74,    43,   175,    44,    45,   133,   263,    72,   241,
     144,    75,   264,   100,   242,   100,    70,   101,   102,   103,
     104,    76,   239,   241,   368,   313,    46,    77,   242,   115,
      78,    70,    79,    66,    82,   115,   135,   136,   137,   138,
      83,   364,   257,   258,   169,   259,   261,    70,    66,   103,
     104,    81,   221,   222,   223,   224,   174,   233,   234,    70,
      70,    70,    70,    70,    66,   421,   250,   251,    70,    70,
      70,    70,    86,    70,   -60,   253,    66,    66,    66,    66,
      66,   320,    85,   217,   113,    66,    66,    66,    66,   297,
      66,   323,   175,   175,   121,   149,   123,   125,   127,   129,
     131,    87,   351,   223,   224,   353,    70,   354,   256,    88,
     141,   176,   355,   394,   227,   228,   363,   384,   356,   386,
      51,    52,    53,    66,   357,   405,   406,   352,   172,   417,
     418,    89,   267,   271,   274,   277,   280,   283,   286,   289,
     292,   294,   358,   164,   302,   174,   174,    90,    51,    52,
      53,   198,   200,    92,   348,   359,    93,    94,   101,   102,
     103,   104,    95,   236,   169,    96,    97,   106,   396,   108,
     342,   109,   225,   226,   227,   228,   221,   222,   223,   224,
     107,   262,   221,   222,   223,   224,   110,   268,   221,   222,
     223,   224,   -97,   -97,   -97,   -97,   295,   298,   360,   303,
     176,   176,   216,   112,   266,   361,   221,   222,   223,   224,
     111,    50,   117,   293,   296,   118,   301,   172,   172,   221,
     222,   223,   224,   184,   185,   186,   187,   188,   189,   175,
     119,   175,    49,   122,   120,    59,    60,   324,    62,   235,
      63,   139,   134,   142,   327,   225,   226,   227,   228,   329,
     143,   144,   270,   273,   276,   279,   282,   285,   288,   291,
     362,   146,   221,   222,   223,   224,   151,    50,   150,   221,
     222,   223,   224,   -98,   -98,   -98,   -98,    51,    52,    53,
     152,   299,   174,   338,   174,     4,    54,    55,    56,    57,
      58,    59,    60,    61,    62,   155,    63,   156,    64,    65,
     330,   157,   158,   331,    50,   159,   332,   160,   161,   333,
     162,   163,   334,   165,   167,   335,    50,   182,   336,   377,
     191,   337,   179,   183,   221,   222,   223,   224,    59,    60,
     169,    62,   193,    63,    49,   124,   376,   176,    70,   176,
      59,    60,   169,    62,   300,    63,   194,   171,   392,   195,
     196,   203,   238,   245,   172,    66,   172,   246,   390,   247,
     248,   249,   400,   253,   402,   391,   132,    49,   126,    50,
     307,   311,   306,   317,   309,   385,   325,   316,   416,    51,
      52,    53,   403,   374,   319,   322,   326,   339,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   328,    63,   340,
      64,    65,    50,    49,   128,   341,   344,   345,   346,   349,
     367,   366,    51,    52,    53,   370,   369,   371,    50,   372,
     378,    54,    55,    56,    57,    58,    59,    60,    61,    62,
     379,    63,   380,    64,    65,   382,    49,   130,    50,   381,
     383,   387,    59,    60,   169,    62,   375,    63,    51,    52,
      53,   393,   395,   397,   398,   399,   169,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   401,    63,   408,    64,
      65,    50,    49,   140,   404,   204,   205,   206,   409,   207,
     410,    51,    52,    53,   208,   209,   210,   211,   212,   213,
      54,    55,    56,    57,    58,    59,    60,    61,    62,   411,
      63,   413,    64,    65,   423,    49,   414,    50,   415,   424,
     225,   226,   227,   228,   419,   425,   426,    51,    52,    53,
     168,   427,   429,   428,   431,   430,    54,    55,    56,    57,
      58,    59,    60,    61,    62,   199,    63,   237,    64,    65,
      50,   365,   314,   312,   347,   389,   244,   422,   231,   420,
      51,    52,    53,   265,     0,    50,     0,     0,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,   269,    63,
      50,    64,    65,     0,    54,    55,    56,    57,    58,    59,
      60,   169,    62,   170,    63,   272,   171,     0,    50,     0,
       0,     0,     0,     0,    59,    60,   169,    62,   275,    63,
       0,   171,     0,    50,     0,     0,   278,     0,     0,     0,
       0,     0,    59,    60,   169,    62,     0,    63,   281,   171,
      50,     0,     0,     0,     0,     0,   284,    59,    60,   169,
      62,     0,    63,    50,   171,     0,   287,     0,     0,     0,
       0,    50,     0,     0,    59,    60,   169,    62,   290,    63,
       0,   171,     0,    50,     0,     0,     0,    59,    60,   169,
      62,    50,    63,     0,   171,    59,    60,   169,    62,     0,
      63,    50,   171,     0,     0,     0,     0,    59,    60,   169,
      62,     0,    63,    50,   171,    59,    60,   169,    62,     0,
      63,     0,   171,    50,     0,    59,    60,   169,    62,     0,
      63,     0,   171,     0,     0,     0,     0,    59,    60,   169,
      62,     0,    63,     0,   171,     1,     2,    59,    60,     0,
      62,     0,    63,     3,     4,     0,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,   204,   205,
     206,    50,   207,     0,    14,    15,     0,   208,   209,   210,
     211,   212,   213,     0,    16,     0,    17,     0,     0,    18,
      54,    55,    56,    57,    58,    59,    60,   169,    62,     0,
      63,   204,   205,   206,   218,   207,     0,     0,     0,     0,
     208,   209,   210,   211,   212,   213
};

static const yytype_int16 yycheck[] =
{
       3,     4,   116,   172,   142,   174,   175,   176,   200,   250,
     233,   234,    14,    22,    49,   339,   147,     3,     4,    14,
      60,    22,    60,    22,    24,     9,   316,    83,    12,    64,
      83,    10,     9,   144,    11,    12,    89,    52,     4,    52,
      40,    37,    57,    83,    57,    83,    49,    87,    88,    89,
      90,    39,   183,    52,   344,    50,    33,    83,    57,    60,
      83,    64,    47,    49,     0,    60,   101,   102,   103,   104,
       3,   395,    53,    54,    83,    56,    85,    80,    64,    89,
      90,    83,    87,    88,    89,    90,   144,    42,    43,    92,
      93,    94,    95,    96,    80,   419,    58,    59,   101,   102,
     103,   104,    12,   106,    23,    24,    92,    93,    94,    95,
      96,   249,    83,   171,    80,   101,   102,   103,   104,   230,
     106,   252,   233,   234,    23,   111,    92,    93,    94,    95,
      96,    83,   324,    89,    90,   327,   139,   329,    23,    12,
     106,   144,    23,   384,    89,    90,   338,   370,    23,   372,
      67,    68,    69,   139,    23,    15,    16,   326,   144,   413,
     414,    83,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,    23,   139,   232,   233,   234,    83,    67,    68,
      69,   167,   168,    22,   322,    23,    22,    22,    87,    88,
      89,    90,    22,   179,    83,    22,    36,    22,   390,    83,
     314,    83,    87,    88,    89,    90,    87,    88,    89,    90,
      39,   214,    87,    88,    89,    90,    44,   220,    87,    88,
      89,    90,    87,    88,    89,    90,   229,   230,    23,   232,
     233,   234,   171,    48,   220,    23,    87,    88,    89,    90,
      61,    57,    83,   229,   230,    45,   232,   233,   234,    87,
      88,    89,    90,    28,    29,    30,    31,    32,    33,   370,
      83,   372,    22,    23,    45,    81,    82,   253,    84,    85,
      86,    24,    83,    83,   260,    87,    88,    89,    90,   265,
      38,    40,   221,   222,   223,   224,   225,   226,   227,   228,
      23,    83,    87,    88,    89,    90,    39,    57,    84,    87,
      88,    89,    90,    87,    88,    89,    90,    67,    68,    69,
      83,    22,   370,   299,   372,    14,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    45,    86,    83,    88,    89,
     269,    45,    83,   272,    57,    23,   275,    23,    23,   278,
      23,    23,   281,    23,    22,   284,    57,    37,   287,   352,
      24,   290,    61,    83,    87,    88,    89,    90,    81,    82,
      83,    84,    83,    86,    22,    23,   352,   370,   371,   372,
      81,    82,    83,    84,    85,    86,    22,    88,   381,    83,
      24,    36,     9,    23,   370,   371,   372,    22,   374,    83,
      22,    83,   395,    24,   397,   381,    83,    22,    23,    57,
       8,    57,    83,    24,    81,   371,    23,    83,   411,    67,
      68,    69,   398,    22,    83,    83,    23,     4,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    57,    86,    23,
      88,    89,    57,    22,    23,    51,    83,    23,    23,     7,
      23,    61,    67,    68,    69,    45,    70,     4,    57,    41,
      23,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      23,    86,    23,    88,    89,    83,    22,    23,    57,    22,
      22,     8,    81,    82,    83,    84,    85,    86,    67,    68,
      69,    72,     4,    24,    24,    61,    83,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    23,    86,    23,    88,
      89,    57,    22,    23,    83,    52,    53,    54,    23,    56,
      24,    67,    68,    69,    61,    62,    63,    64,    65,    66,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    24,
      86,    75,    88,    89,    24,    22,    75,    57,    71,    73,
      87,    88,    89,    90,    61,    61,    81,    67,    68,    69,
      22,    24,    61,    74,    23,    81,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    22,    86,   180,    88,    89,
      57,   340,   245,   244,   320,   373,   191,   420,   176,   416,
      67,    68,    69,    22,    -1,    57,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    22,    86,
      57,    88,    89,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    22,    88,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    22,    86,
      -1,    88,    -1,    57,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    -1,    86,    22,    88,
      57,    -1,    -1,    -1,    -1,    -1,    22,    81,    82,    83,
      84,    -1,    86,    57,    88,    -1,    22,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    81,    82,    83,    84,    22,    86,
      -1,    88,    -1,    57,    -1,    -1,    -1,    81,    82,    83,
      84,    57,    86,    -1,    88,    81,    82,    83,    84,    -1,
      86,    57,    88,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    -1,    86,    57,    88,    81,    82,    83,    84,    -1,
      86,    -1,    88,    57,    -1,    81,    82,    83,    84,    -1,
      86,    -1,    88,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    -1,    86,    -1,    88,     5,     6,    81,    82,    -1,
      84,    -1,    86,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    26,    27,    52,    53,
      54,    57,    56,    -1,    34,    35,    -1,    61,    62,    63,
      64,    65,    66,    -1,    44,    -1,    46,    -1,    -1,    49,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    13,    14,    16,    17,    18,    19,    20,
      21,    25,    26,    27,    34,    35,    44,    46,    49,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   107,   108,   115,   119,   120,   123,   124,   146,
     147,   148,   149,     9,    11,    12,    33,     9,    12,    22,
      57,    67,    68,    69,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    86,    88,    89,   117,   126,   127,   130,
     131,   143,   126,    83,    10,    37,    39,    83,    83,    47,
      14,    83,     0,     3,   150,    83,    12,    83,    12,    83,
      83,   127,    22,    22,    22,    22,    22,    36,   127,    60,
      83,    87,    88,    89,    90,   125,    22,    39,    83,    83,
      44,    61,    48,   126,    22,    60,   109,    83,    45,    83,
      45,    23,    23,   126,    23,   126,    23,   126,    23,   126,
      23,   126,    83,    89,    83,   127,   127,   127,   127,    24,
      23,   126,    83,    38,    40,   138,    83,   121,   122,   117,
      84,    39,    83,   111,   123,    45,    83,    45,    83,    23,
      23,    23,    23,    23,   126,    23,   125,    22,    22,    83,
      85,    88,   117,   128,   129,   130,   131,   139,   140,    61,
      24,   138,    37,    83,    28,    29,    30,    31,    32,    33,
     114,    24,   110,    83,    22,    83,    24,   132,   117,    22,
     117,   129,   131,    36,    52,    53,    54,    56,    61,    62,
      63,    64,    65,    66,   142,   117,   128,   129,    55,   141,
     142,    87,    88,    89,    90,    87,    88,    89,    90,   142,
     142,   141,   142,    42,    43,    85,   117,   122,     9,   138,
      22,    52,    57,   112,   111,    23,    22,    83,    22,    83,
      58,    59,   133,    24,   116,   116,    23,    53,    54,    56,
      22,    85,   131,    52,    57,    22,   117,   129,   131,    22,
     128,   129,    22,   128,   129,    22,   128,   129,    22,   128,
     129,    22,   128,   129,    22,   128,   129,    22,   128,   129,
      22,   128,   129,   117,   129,   131,   117,   130,   131,    22,
      85,   117,   129,   131,   139,   139,    83,     8,   135,    81,
     113,    57,   110,    50,   109,   118,    83,    24,   106,    83,
     125,   133,    83,   138,   117,    23,    23,   117,    57,   117,
     128,   128,   128,   128,   128,   128,   128,   128,   117,     4,
      23,    51,   123,   106,    83,    23,    23,   132,   125,     7,
     144,   116,   142,   116,   116,    23,    23,    23,    23,    23,
      23,    23,    23,   116,   143,   112,    61,    23,   106,    70,
      45,     4,    41,   145,    22,    85,   117,   131,    23,    23,
      23,    22,    83,    22,   139,   126,   139,     8,   134,   135,
     117,   117,   131,    72,   133,     4,   116,    24,    24,    61,
     131,    23,   131,   117,    83,    15,    16,   137,    23,    23,
      24,    24,   136,    75,    75,    71,   131,   113,   113,    61,
     137,   143,   136,    24,    73,    61,    81,    24,    74,    61,
      81,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   104,   105,   106,   106,   107,
     108,   108,   108,   109,   109,   110,   110,   111,   111,   112,
     112,   112,   113,   114,   114,   114,   114,   114,   114,   115,
     116,   116,   117,   117,   117,   117,   117,   118,   118,   119,
     120,   121,   121,   122,   122,   123,   123,   123,   124,   125,
     125,   125,   126,   126,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   128,   128,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   131,   131,   132,   132,
     133,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   137,   138,   138,   139,   139,   139,   139,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   141,   141,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   143,   143,   143,   144,
     144,   145,   145,   146,   147,   148,   149,   150,   150
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     9,    10,    27,     0,     3,     5,
       8,     9,     5,     0,     1,     0,     3,     6,     3,     0,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     8,
       0,     3,     1,     1,     1,     1,     1,     0,     4,     4,
       5,     1,     3,     3,     3,     2,    11,    11,     2,     0,
       1,     2,     2,     4,     3,     3,     3,     3,     3,     1,
       1,     1,     3,     2,     1,     4,     3,     1,     1,     3,
       5,     5,     5,     5,     5,     5,     5,     5,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     4,     4,     4,
       4,     3,     3,     3,     3,     3,     1,     3,     0,     4,
       0,     2,     6,     0,     5,    10,    10,     0,     4,     1,
       1,     0,     0,     2,     0,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       6,     6,     6,     6,     6,     6,     9,     3,     3,     3,
       2,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     1,     2,     1,     1,     1,     0,
       3,     0,     2,     7,     2,     7,     4,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 251 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 2047 "yacc_sql.cpp"
    break;

  case 25: /* exit_stmt: EXIT  */
#line 283 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 2056 "yacc_sql.cpp"
    break;

  case 26: /* help_stmt: HELP  */
#line 289 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 2064 "yacc_sql.cpp"
    break;

  case 27: /* sync_stmt: SYNC  */
#line 294 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 2072 "yacc_sql.cpp"
    break;

  case 28: /* begin_stmt: TRX_BEGIN  */
#line 300 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 2080 "yacc_sql.cpp"
    break;

  case 29: /* commit_stmt: TRX_COMMIT  */
#line 306 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 2088 "yacc_sql.cpp"
    break;

  case 30: /* rollback_stmt: TRX_ROLLBACK  */
#line 312 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 2096 "yacc_sql.cpp"
    break;

  case 31: /* drop_table_stmt: DROP TABLE ID  */
#line 318 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2106 "yacc_sql.cpp"
    break;

  case 32: /* show_tables_stmt: SHOW TABLES  */
#line 325 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 2114 "yacc_sql.cpp"
    break;

  case 33: /* desc_table_stmt: DESC ID  */
#line 331 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2124 "yacc_sql.cpp"
    break;

  case 34: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID index_rel_list RBRACE  */
#line 340 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-6].string);
      create_index.relation_name = (yyvsp[-4].string);
      if ((yyvsp[-1].index_list) != nullptr) {
        create_index.attribute_names.swap(*(yyvsp[-1].index_list));
      }
      create_index.attribute_names.emplace_back((yyvsp[-2].string));

      create_index.unique = false;
      free((yyvsp[-6].string));
      free((yyvsp[-4].string));
      free((yyvsp[-2].string));
      if ((yyvsp[-1].index_list) != nullptr){
        delete((yyvsp[-1].index_list));
      }
    }
#line 2147 "yacc_sql.cpp"
    break;

  case 35: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID index_rel_list RBRACE  */
#line 359 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-6].string);
      create_index.relation_name = (yyvsp[-4].string);
      // create_index.attribute_name = $8;
      if ((yyvsp[-1].index_list) != nullptr){
        create_index.attribute_names.swap(*(yyvsp[-1].index_list));
      }
      create_index.attribute_names.emplace_back((yyvsp[-2].string));
      create_index.unique = true;
      free((yyvsp[-6].string));
      free((yyvsp[-4].string));
      free((yyvsp[-2].string));
      if ((yyvsp[-1].index_list) != nullptr){
        delete((yyvsp[-1].index_list));
      }
    }
#line 2170 "yacc_sql.cpp"
    break;

  case 36: /* create_vec_index_stmt: CREATE VECTOR_T INDEX ID ON ID LBRACE ID RBRACE WITH LBRACE TYPE EQ ID COMMA DISTANCE EQ func_op COMMA LISTS EQ NUMBER COMMA PROBES EQ NUMBER RBRACE  */
#line 381 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_VEC_INDEX);
      CreateVecIndexSqlNode &create_vec_index = (yyval.sql_node)->create_vec_index;
      create_vec_index.index_name = (yyvsp[-23].string);
      create_vec_index.relation_name = (yyvsp[-21].string);
      create_vec_index.attribute_name = (yyvsp[-19].string);
      create_vec_index.distance_name = (yyvsp[-9].func);
      create_vec_index.type_name = (yyvsp[-13].string);
      create_vec_index.nlist = (yyvsp[-5].number);
      create_vec_index.probes = (yyvsp[-1].number);
      free((yyvsp[-23].string));
      free((yyvsp[-21].string));
      free((yyvsp[-19].string));
      free((yyvsp[-13].string));
    }
#line 2190 "yacc_sql.cpp"
    break;

  case 37: /* index_rel_list: %empty  */
#line 400 "yacc_sql.y"
    {
      (yyval.index_list) = nullptr;
    }
#line 2198 "yacc_sql.cpp"
    break;

  case 38: /* index_rel_list: COMMA ID index_rel_list  */
#line 403 "yacc_sql.y"
                              {
      if ((yyvsp[0].index_list) != nullptr) {
        (yyval.index_list) = (yyvsp[0].index_list);
      } else {
        (yyval.index_list) = new std::vector<std::string>;
      }
      (yyval.index_list)->emplace_back((yyvsp[-1].string));
      free((yyvsp[-1].string));
    }
#line 2212 "yacc_sql.cpp"
    break;

  case 39: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 416 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2224 "yacc_sql.cpp"
    break;

  case 40: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format  */
#line 426 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-5].string);
      free((yyvsp[-5].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-2].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
        delete src_attrs;
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-3].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-3].attr_info);

      AttrInfoSqlNode null_field;
      null_field.type = AttrType::INTS;
      null_field.name = NULL_FIELD_NAME;
      null_field.length = 4;
      null_field.isnull = false;
      create_table.attr_infos.emplace_back(null_field);

      if ((yyvsp[0].string) != nullptr) {
        create_table.storage_format = (yyvsp[0].string);
        free((yyvsp[0].string));
      }
    }
#line 2257 "yacc_sql.cpp"
    break;

  case 41: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE as_option select_stmt  */
#line 455 "yacc_sql.y"
    {
      (yyval.sql_node) = (yyvsp[0].sql_node);
      (yyval.sql_node)->flag = SCF_CREATE_TABLE;
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-6].string);
      free((yyvsp[-6].string));
      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-3].attr_infos);
      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-4].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-4].attr_info);
    }
#line 2276 "yacc_sql.cpp"
    break;

  case 42: /* create_table_stmt: CREATE TABLE ID as_option select_stmt  */
#line 470 "yacc_sql.y"
    {
      (yyval.sql_node) = (yyvsp[0].sql_node);
      (yyval.sql_node)->flag = SCF_CREATE_TABLE;
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-2].string);
      free((yyvsp[-2].string));
    }
#line 2288 "yacc_sql.cpp"
    break;

  case 43: /* as_option: %empty  */
#line 480 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2296 "yacc_sql.cpp"
    break;

  case 44: /* as_option: AS  */
#line 484 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2304 "yacc_sql.cpp"
    break;

  case 45: /* attr_def_list: %empty  */
#line 490 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2312 "yacc_sql.cpp"
    break;

  case 46: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 494 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2326 "yacc_sql.cpp"
    break;

  case 47: /* attr_def: ID type LBRACE number RBRACE isnull  */
#line 507 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->isnull = (yyvsp[0].boolean);
      free((yyvsp[-5].string));
    }
#line 2339 "yacc_sql.cpp"
    break;

  case 48: /* attr_def: ID type isnull  */
#line 516 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->isnull = (yyvsp[0].boolean);
      free((yyvsp[-2].string));
    }
#line 2352 "yacc_sql.cpp"
    break;

  case 49: /* isnull: %empty  */
#line 528 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2360 "yacc_sql.cpp"
    break;

  case 50: /* isnull: NULL_KY  */
#line 532 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2368 "yacc_sql.cpp"
    break;

  case 51: /* isnull: NOT NULL_KY  */
#line 536 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2376 "yacc_sql.cpp"
    break;

  case 52: /* number: NUMBER  */
#line 542 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2382 "yacc_sql.cpp"
    break;

  case 53: /* type: INT_T  */
#line 545 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::INTS); }
#line 2388 "yacc_sql.cpp"
    break;

  case 54: /* type: STRING_T  */
#line 546 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::CHARS); }
#line 2394 "yacc_sql.cpp"
    break;

  case 55: /* type: FLOAT_T  */
#line 547 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::FLOATS); }
#line 2400 "yacc_sql.cpp"
    break;

  case 56: /* type: VECTOR_T  */
#line 548 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::VECTORS); }
#line 2406 "yacc_sql.cpp"
    break;

  case 57: /* type: DATE_T  */
#line 549 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::DATES); }
#line 2412 "yacc_sql.cpp"
    break;

  case 58: /* type: TEXT_T  */
#line 550 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::TEXTS); }
#line 2418 "yacc_sql.cpp"
    break;

  case 59: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 554 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-5].string);
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.sql_node)->insertion.values.swap(*(yyvsp[-1].value_list));
        delete (yyvsp[-1].value_list);
      }
      (yyval.sql_node)->insertion.values.emplace_back(*(yyvsp[-2].value));
      std::reverse((yyval.sql_node)->insertion.values.begin(), (yyval.sql_node)->insertion.values.end());
      delete (yyvsp[-2].value);
      free((yyvsp[-5].string));
    }
#line 2435 "yacc_sql.cpp"
    break;

  case 60: /* value_list: %empty  */
#line 570 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2443 "yacc_sql.cpp"
    break;

  case 61: /* value_list: COMMA value value_list  */
#line 573 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2457 "yacc_sql.cpp"
    break;

  case 62: /* value: NUMBER  */
#line 584 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2466 "yacc_sql.cpp"
    break;

  case 63: /* value: FLOAT  */
#line 588 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2475 "yacc_sql.cpp"
    break;

  case 64: /* value: SSS  */
#line 592 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2486 "yacc_sql.cpp"
    break;

  case 65: /* value: VECTOR_LIST  */
#line 598 "yacc_sql.y"
                 {
      char *tmp = common::substr((yyvsp[0].string),0,strlen((yyvsp[0].string))-1);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2497 "yacc_sql.cpp"
    break;

  case 66: /* value: NULL_KY  */
#line 604 "yacc_sql.y"
              {
      (yyval.value) = new Value(NULL_VALUE, 1);
    }
#line 2505 "yacc_sql.cpp"
    break;

  case 67: /* storage_format: %empty  */
#line 610 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 2513 "yacc_sql.cpp"
    break;

  case 68: /* storage_format: STORAGE FORMAT EQ ID  */
#line 614 "yacc_sql.y"
    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2521 "yacc_sql.cpp"
    break;

  case 69: /* delete_stmt: DELETE FROM ID where  */
#line 621 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2535 "yacc_sql.cpp"
    break;

  case 70: /* update_stmt: UPDATE ID SET set_clause_list where  */
#line 633 "yacc_sql.y"
    {
        (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
        (yyval.sql_node)->update.relation_name = (yyvsp[-3].string);
        int temp = 0;
        if (nullptr != (yyvsp[-1].set_clause_list)) {
            for (UpdateKV kv : *(yyvsp[-1].set_clause_list)) {
              (yyval.sql_node)->update.attribute_names.emplace_back(kv.attr_name);
              if(kv.is_subquery){
                (yyval.sql_node)->update.subquery_values.emplace_back(kv.subquery);
                (yyval.sql_node)->update.record.emplace_back(temp);
              }
              else{
                (yyval.sql_node)->update.values.emplace_back(kv.value);
              }
              temp++;
            }
            delete (yyvsp[-1].set_clause_list);  // $4 只需要在这里释放一次
        }
        if ((yyvsp[0].condition_list) != nullptr) {
            (yyval.sql_node)->update.conditions.swap(*(yyvsp[0].condition_list));
            delete (yyvsp[0].condition_list);  // $5 在此处释放
        }
        free((yyvsp[-3].string));  // 正确释放 $2
        // delete $5;  // 这里不需要再释放 $5，避免 double-free
    }
#line 2565 "yacc_sql.cpp"
    break;

  case 71: /* set_clause_list: set_clause  */
#line 663 "yacc_sql.y"
    {
        (yyval.set_clause_list) = new std::vector<UpdateKV>();
        (yyval.set_clause_list)->emplace_back(*(yyvsp[0].set_clause));
        delete (yyvsp[0].set_clause);  // 确保 $1 是 new 出来的对象
    }
#line 2575 "yacc_sql.cpp"
    break;

  case 72: /* set_clause_list: set_clause_list COMMA set_clause  */
#line 669 "yacc_sql.y"
    {
        (yyvsp[-2].set_clause_list)->emplace_back(*(yyvsp[0].set_clause));
        (yyval.set_clause_list) = (yyvsp[-2].set_clause_list);
        delete (yyvsp[0].set_clause);  // 确保 $3 是 new 出来的对象
    }
#line 2585 "yacc_sql.cpp"
    break;

  case 73: /* set_clause: ID EQ value  */
#line 679 "yacc_sql.y"
    {
        (yyval.set_clause) = new UpdateKV();
        (yyval.set_clause)->attr_name = strdup((yyvsp[-2].string));  // 使用 strdup 复制字符串，避免释放后使用问题
        (yyval.set_clause)->value = *(yyvsp[0].value);
        free((yyvsp[-2].string));  // 确保在拷贝完成后再释放
    }
#line 2596 "yacc_sql.cpp"
    break;

  case 74: /* set_clause: ID EQ SUB_QUERY  */
#line 686 "yacc_sql.y"
    {
      (yyval.set_clause) = new UpdateKV();
      (yyval.set_clause)->is_subquery = true;
      (yyval.set_clause)->attr_name = strdup((yyvsp[-2].string));
      (yyval.set_clause)->subquery = strdup((yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2609 "yacc_sql.cpp"
    break;

  case 75: /* select_stmt: SELECT expression_list  */
#line 699 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[0].expression_list));
        delete (yyvsp[0].expression_list);
      }
    }
#line 2621 "yacc_sql.cpp"
    break;

  case 76: /* select_stmt: SELECT expression_list FROM ID alias rel_list join_list where group_by having order_by  */
#line 707 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-9].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[-9].expression_list));
        delete (yyvsp[-9].expression_list);
      }
      if ((yyvsp[-5].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-5].relation_list));
        delete (yyvsp[-5].relation_list);
      }
      std::string temp = "";
      if (nullptr != (yyvsp[-6].string)) {
        temp = (yyvsp[-6].string);
      }
      (yyval.sql_node)->selection.relations.emplace_back((yyvsp[-7].string),temp);
      free((yyvsp[-6].string));
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      if ((yyvsp[-3].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-3].condition_list));
        delete (yyvsp[-3].condition_list);
      }
      free((yyvsp[-7].string));
      
      if ((yyvsp[-4].join_sql_node) != nullptr) {
        (yyval.sql_node)->selection.relations.insert((yyval.sql_node)->selection.relations.end(), (yyvsp[-4].join_sql_node)->relations.begin(), (yyvsp[-4].join_sql_node)->relations.end());
        (yyval.sql_node)->selection.conditions.insert((yyval.sql_node)->selection.conditions.end(), (yyvsp[-4].join_sql_node)->conditions.begin(), (yyvsp[-4].join_sql_node)->conditions.end());
        delete (yyvsp[-4].join_sql_node);
      }
      if ((yyvsp[-2].expression_list) != nullptr) {
        (yyval.sql_node)->selection.group_by.swap(*(yyvsp[-2].expression_list));
        delete (yyvsp[-2].expression_list);
      }
      if ((yyvsp[-1].condition_list) != nullptr) {
        (yyval.sql_node)->selection.having_conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }
      if ((yyvsp[0].order_by_list) != nullptr) {
        (yyval.sql_node)->selection.order_rules.swap(*(yyvsp[0].order_by_list));
        delete (yyvsp[0].order_by_list);
      }
    }
#line 2668 "yacc_sql.cpp"
    break;

  case 77: /* select_stmt: SELECT expression_list FROM ID alias rel_list join_list where group_by having vec_order_by  */
#line 750 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-9].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[-9].expression_list));
        delete (yyvsp[-9].expression_list);
      }
      if ((yyvsp[-5].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-5].relation_list));
        delete (yyvsp[-5].relation_list);
      }
      (yyval.sql_node)->selection.relations.emplace_back((yyvsp[-7].string),"");
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      if ((yyvsp[-3].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-3].condition_list));
        delete (yyvsp[-3].condition_list);
      }
      free((yyvsp[-7].string));
      
      if ((yyvsp[-4].join_sql_node) != nullptr) {
        (yyval.sql_node)->selection.relations.insert((yyval.sql_node)->selection.relations.end(), (yyvsp[-4].join_sql_node)->relations.begin(), (yyvsp[-4].join_sql_node)->relations.end());
        (yyval.sql_node)->selection.conditions.insert((yyval.sql_node)->selection.conditions.end(), (yyvsp[-4].join_sql_node)->conditions.begin(), (yyvsp[-4].join_sql_node)->conditions.end());
        delete (yyvsp[-4].join_sql_node);
      }
      if ((yyvsp[-2].expression_list) != nullptr) {
        (yyval.sql_node)->selection.group_by.swap(*(yyvsp[-2].expression_list));
        delete (yyvsp[-2].expression_list);
      }
      if ((yyvsp[-1].condition_list) != nullptr) {
        (yyval.sql_node)->selection.having_conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }
      if ((yyvsp[0].vec_order_by) != nullptr) {
        (yyval.sql_node)->selection.vec_order_rules = *(yyvsp[0].vec_order_by);
        delete (yyvsp[0].vec_order_by);
      }
    }
#line 2710 "yacc_sql.cpp"
    break;

  case 78: /* calc_stmt: CALC expression_list  */
#line 790 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2720 "yacc_sql.cpp"
    break;

  case 79: /* alias: %empty  */
#line 797 "yacc_sql.y"
                {
      (yyval.string) = nullptr;
    }
#line 2728 "yacc_sql.cpp"
    break;

  case 80: /* alias: ID  */
#line 800 "yacc_sql.y"
         {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2736 "yacc_sql.cpp"
    break;

  case 81: /* alias: AS ID  */
#line 803 "yacc_sql.y"
            {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2744 "yacc_sql.cpp"
    break;

  case 82: /* expression_list: expression alias  */
#line 808 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      if (nullptr != (yyvsp[0].string)) {
        (yyvsp[-1].expression)->set_alias((yyvsp[0].string));
      }
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
      free((yyvsp[0].string));
    }
#line 2757 "yacc_sql.cpp"
    break;

  case 83: /* expression_list: expression alias COMMA expression_list  */
#line 817 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      if (nullptr != (yyvsp[-2].string)) {
        (yyvsp[-3].expression)->set_alias((yyvsp[-2].string));
      }
      (yyval.expression_list)->emplace((yyval.expression_list)->begin(), (yyvsp[-3].expression));
      free((yyvsp[-2].string));
    }
#line 2774 "yacc_sql.cpp"
    break;

  case 84: /* expression: LBRACE expression RBRACE  */
#line 831 "yacc_sql.y"
                             {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2783 "yacc_sql.cpp"
    break;

  case 85: /* expression: expression '+' expression  */
#line 835 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2791 "yacc_sql.cpp"
    break;

  case 86: /* expression: expression '-' expression  */
#line 838 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2799 "yacc_sql.cpp"
    break;

  case 87: /* expression: expression '*' expression  */
#line 841 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2807 "yacc_sql.cpp"
    break;

  case 88: /* expression: expression '/' expression  */
#line 844 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2815 "yacc_sql.cpp"
    break;

  case 89: /* expression: value  */
#line 847 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2825 "yacc_sql.cpp"
    break;

  case 90: /* expression: rel_attr  */
#line 852 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2836 "yacc_sql.cpp"
    break;

  case 91: /* expression: '*'  */
#line 858 "yacc_sql.y"
          {
      (yyval.expression) = new StarExpr();
    }
#line 2844 "yacc_sql.cpp"
    break;

  case 92: /* expression: ID DOT '*'  */
#line 861 "yacc_sql.y"
                {
      (yyval.expression) = new StarExpr((yyvsp[-2].string));
    }
#line 2852 "yacc_sql.cpp"
    break;

  case 93: /* expression: '-' expression  */
#line 864 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2860 "yacc_sql.cpp"
    break;

  case 94: /* expression: aggr_expr  */
#line 867 "yacc_sql.y"
                {
      (yyval.expression) = (yyvsp[0].expression);
    }
#line 2868 "yacc_sql.cpp"
    break;

  case 95: /* expression: func_op LBRACE expression_list RBRACE  */
#line 870 "yacc_sql.y"
                                            {
      (yyval.expression) = new FunctionExpr((FuncOp)(yyvsp[-3].func),std::move(*(yyvsp[-1].expression_list)));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[-1].expression_list);
    }
#line 2878 "yacc_sql.cpp"
    break;

  case 96: /* expression: func_op LBRACE RBRACE  */
#line 875 "yacc_sql.y"
                            {
      (yyval.expression) = new FunctionExpr((FuncOp)(yyvsp[-2].func),std::vector<std::unique_ptr<Expression>>());
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2887 "yacc_sql.cpp"
    break;

  case 97: /* simple_expression: value  */
#line 881 "yacc_sql.y"
          {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2897 "yacc_sql.cpp"
    break;

  case 98: /* simple_expression: rel_attr  */
#line 886 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2908 "yacc_sql.cpp"
    break;

  case 99: /* arith_expr: LBRACE arith_expr RBRACE  */
#line 894 "yacc_sql.y"
                             {
      (yyval.expression) = (yyvsp[-1].expression);
    }
#line 2916 "yacc_sql.cpp"
    break;

  case 100: /* arith_expr: arith_expr '+' LBRACE simple_expression RBRACE  */
#line 897 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2924 "yacc_sql.cpp"
    break;

  case 101: /* arith_expr: arith_expr '-' LBRACE simple_expression RBRACE  */
#line 900 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2932 "yacc_sql.cpp"
    break;

  case 102: /* arith_expr: arith_expr '*' LBRACE simple_expression RBRACE  */
#line 903 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2940 "yacc_sql.cpp"
    break;

  case 103: /* arith_expr: arith_expr '/' LBRACE simple_expression RBRACE  */
#line 906 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2948 "yacc_sql.cpp"
    break;

  case 104: /* arith_expr: simple_expression '+' LBRACE simple_expression RBRACE  */
#line 909 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2956 "yacc_sql.cpp"
    break;

  case 105: /* arith_expr: simple_expression '-' LBRACE simple_expression RBRACE  */
#line 912 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2964 "yacc_sql.cpp"
    break;

  case 106: /* arith_expr: simple_expression '*' LBRACE simple_expression RBRACE  */
#line 915 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2972 "yacc_sql.cpp"
    break;

  case 107: /* arith_expr: simple_expression '/' LBRACE simple_expression RBRACE  */
#line 918 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2980 "yacc_sql.cpp"
    break;

  case 108: /* arith_expr: '-' arith_expr  */
#line 921 "yacc_sql.y"
                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2988 "yacc_sql.cpp"
    break;

  case 109: /* arith_expr: '-' simple_expression  */
#line 924 "yacc_sql.y"
                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2996 "yacc_sql.cpp"
    break;

  case 110: /* arith_expr: arith_expr '+' simple_expression  */
#line 927 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3004 "yacc_sql.cpp"
    break;

  case 111: /* arith_expr: arith_expr '-' simple_expression  */
#line 930 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3012 "yacc_sql.cpp"
    break;

  case 112: /* arith_expr: arith_expr '*' simple_expression  */
#line 933 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3020 "yacc_sql.cpp"
    break;

  case 113: /* arith_expr: arith_expr '/' simple_expression  */
#line 936 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3028 "yacc_sql.cpp"
    break;

  case 114: /* arith_expr: simple_expression '+' arith_expr  */
#line 939 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3036 "yacc_sql.cpp"
    break;

  case 115: /* arith_expr: simple_expression '-' arith_expr  */
#line 942 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3044 "yacc_sql.cpp"
    break;

  case 116: /* arith_expr: simple_expression '*' arith_expr  */
#line 945 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3052 "yacc_sql.cpp"
    break;

  case 117: /* arith_expr: simple_expression '/' arith_expr  */
#line 948 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3060 "yacc_sql.cpp"
    break;

  case 118: /* arith_expr: arith_expr '+' arith_expr  */
#line 951 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3068 "yacc_sql.cpp"
    break;

  case 119: /* arith_expr: arith_expr '-' arith_expr  */
#line 954 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3076 "yacc_sql.cpp"
    break;

  case 120: /* arith_expr: arith_expr '*' arith_expr  */
#line 957 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3084 "yacc_sql.cpp"
    break;

  case 121: /* arith_expr: arith_expr '/' arith_expr  */
#line 960 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3092 "yacc_sql.cpp"
    break;

  case 122: /* arith_expr: simple_expression '+' simple_expression  */
#line 963 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3100 "yacc_sql.cpp"
    break;

  case 123: /* arith_expr: simple_expression '-' simple_expression  */
#line 966 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3108 "yacc_sql.cpp"
    break;

  case 124: /* arith_expr: simple_expression '*' simple_expression  */
#line 969 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3116 "yacc_sql.cpp"
    break;

  case 125: /* arith_expr: simple_expression '/' simple_expression  */
#line 972 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3124 "yacc_sql.cpp"
    break;

  case 126: /* aggr_expr: SUM LBRACE expression_list RBRACE  */
#line 977 "yacc_sql.y"
                                      {
      (yyval.expression) = create_aggregate_expression("SUM", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 3132 "yacc_sql.cpp"
    break;

  case 127: /* aggr_expr: AVG LBRACE expression_list RBRACE  */
#line 980 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("AVG", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 3140 "yacc_sql.cpp"
    break;

  case 128: /* aggr_expr: MAX LBRACE expression_list RBRACE  */
#line 983 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("MAX", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 3148 "yacc_sql.cpp"
    break;

  case 129: /* aggr_expr: MIN LBRACE expression_list RBRACE  */
#line 986 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("MIN", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 3156 "yacc_sql.cpp"
    break;

  case 130: /* aggr_expr: COUNT LBRACE expression_list RBRACE  */
#line 989 "yacc_sql.y"
                                          {
      (yyval.expression) = create_aggregate_expression("COUNT", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 3164 "yacc_sql.cpp"
    break;

  case 131: /* aggr_expr: SUM LBRACE RBRACE  */
#line 992 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->emplace_back(std::make_unique<ValueExpr>());
      empty->emplace_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("SUM", empty, sql_string, &(yyloc));
    }
#line 3175 "yacc_sql.cpp"
    break;

  case 132: /* aggr_expr: AVG LBRACE RBRACE  */
#line 998 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->emplace_back(std::make_unique<ValueExpr>());
      empty->emplace_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("AVG", empty, sql_string, &(yyloc));
    }
#line 3186 "yacc_sql.cpp"
    break;

  case 133: /* aggr_expr: MIN LBRACE RBRACE  */
#line 1004 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->emplace_back(std::make_unique<ValueExpr>());
      empty->emplace_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("MIN", empty, sql_string, &(yyloc));
    }
#line 3197 "yacc_sql.cpp"
    break;

  case 134: /* aggr_expr: MAX LBRACE RBRACE  */
#line 1010 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->emplace_back(std::make_unique<ValueExpr>());
      empty->emplace_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("MAX", empty, sql_string, &(yyloc));
    }
#line 3208 "yacc_sql.cpp"
    break;

  case 135: /* aggr_expr: COUNT LBRACE RBRACE  */
#line 1016 "yacc_sql.y"
                          {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->emplace_back(std::make_unique<ValueExpr>());
      empty->emplace_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("COUNT", empty, sql_string, &(yyloc));
    }
#line 3219 "yacc_sql.cpp"
    break;

  case 136: /* rel_attr: ID  */
#line 1025 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 3229 "yacc_sql.cpp"
    break;

  case 137: /* rel_attr: ID DOT ID  */
#line 1030 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 3241 "yacc_sql.cpp"
    break;

  case 138: /* rel_list: %empty  */
#line 1041 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 3249 "yacc_sql.cpp"
    break;

  case 139: /* rel_list: COMMA ID alias rel_list  */
#line 1044 "yacc_sql.y"
                              {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::pair<std::string,std::string>>;
      }
      std::string temp = "";
      if (nullptr != (yyvsp[-1].string)) {
        temp = (yyvsp[-1].string);
      }
      (yyval.relation_list)->emplace_back((yyvsp[-2].string),temp);
      free((yyvsp[-2].string));
    }
#line 3267 "yacc_sql.cpp"
    break;

  case 140: /* join_list: %empty  */
#line 1060 "yacc_sql.y"
    {
      (yyval.join_sql_node) = nullptr;
    }
#line 3275 "yacc_sql.cpp"
    break;

  case 141: /* join_list: INNER join_list  */
#line 1063 "yacc_sql.y"
                      {
      (yyval.join_sql_node) = (yyvsp[0].join_sql_node);
    }
#line 3283 "yacc_sql.cpp"
    break;

  case 142: /* join_list: JOIN ID alias ON condition_list join_list  */
#line 1066 "yacc_sql.y"
                                                {
      (yyval.join_sql_node) = new JoinSqlNode();

      if ((yyvsp[-1].condition_list) != nullptr) {
        (yyval.join_sql_node)->conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }
      std::string temp = "";
      if (nullptr != (yyvsp[-3].string)) {
        temp = (yyvsp[-3].string);
      }
      (yyval.join_sql_node)->relations.emplace_back((yyvsp[-4].string),temp);

      free((yyvsp[-4].string));

      if ((yyvsp[0].join_sql_node) != nullptr) {
        (yyval.join_sql_node)->relations.insert((yyval.join_sql_node)->relations.end(), (yyvsp[0].join_sql_node)->relations.begin(), (yyvsp[0].join_sql_node)->relations.end());
        (yyval.join_sql_node)->conditions.insert((yyval.join_sql_node)->conditions.end(), (yyvsp[0].join_sql_node)->conditions.begin(), (yyvsp[0].join_sql_node)->conditions.end());
        delete (yyvsp[0].join_sql_node);
      }
    }
#line 3309 "yacc_sql.cpp"
    break;

  case 143: /* order_by: %empty  */
#line 1089 "yacc_sql.y"
  {
    (yyval.order_by_list) = nullptr;
  }
#line 3317 "yacc_sql.cpp"
    break;

  case 144: /* order_by: ORDER BY rel_attr order_op order_by_list  */
#line 1093 "yacc_sql.y"
  {
    (yyval.order_by_list) = new std::vector<std::pair<RelAttrSqlNode, OrderOp>>;
    (yyval.order_by_list)->emplace_back(std::make_pair(*(yyvsp[-2].rel_attr), (yyvsp[-1].orderOp)));
    delete (yyvsp[-2].rel_attr);
    if ((yyvsp[0].order_by_list) != nullptr) {
      (yyval.order_by_list)->insert((yyval.order_by_list)->end(), (yyvsp[0].order_by_list)->begin(), (yyvsp[0].order_by_list)->end());
    }
  }
#line 3330 "yacc_sql.cpp"
    break;

  case 145: /* vec_order_by: ORDER BY func_op LBRACE rel_attr COMMA value RBRACE LIMIT number  */
#line 1105 "yacc_sql.y"
  {
    (yyval.vec_order_by) = new VecOrderByNode;
    (yyval.vec_order_by)->type = (yyvsp[-7].func);
    (yyval.vec_order_by)->first_attr = *(yyvsp[-5].rel_attr);
    (yyval.vec_order_by)->value = *(yyvsp[-3].value);
    (yyval.vec_order_by)->limit = (yyvsp[0].number); 
    (yyval.vec_order_by)->expr = new UnboundFieldExpr((yyval.vec_order_by)->first_attr.relation_name, (yyval.vec_order_by)->first_attr.attribute_name);
    (yyval.vec_order_by)->expr->set_name(token_name(sql_string, &(yyloc)));
  }
#line 3344 "yacc_sql.cpp"
    break;

  case 146: /* vec_order_by: ORDER BY func_op LBRACE value COMMA rel_attr RBRACE LIMIT number  */
#line 1115 "yacc_sql.y"
  {
    (yyval.vec_order_by) = new VecOrderByNode;
    (yyval.vec_order_by)->type = (yyvsp[-7].func);
    (yyval.vec_order_by)->first_attr = *(yyvsp[-3].rel_attr);
    (yyval.vec_order_by)->value = *(yyvsp[-5].value);
    (yyval.vec_order_by)->limit = (yyvsp[0].number);
    (yyval.vec_order_by)->expr = new UnboundFieldExpr((yyval.vec_order_by)->first_attr.relation_name, (yyval.vec_order_by)->first_attr.attribute_name);
    (yyval.vec_order_by)->expr->set_name(token_name(sql_string, &(yyloc)));
  }
#line 3358 "yacc_sql.cpp"
    break;

  case 147: /* order_by_list: %empty  */
#line 1127 "yacc_sql.y"
  {
    (yyval.order_by_list) = nullptr;
  }
#line 3366 "yacc_sql.cpp"
    break;

  case 148: /* order_by_list: COMMA rel_attr order_op order_by_list  */
#line 1131 "yacc_sql.y"
  {
    (yyval.order_by_list) = new std::vector<std::pair<RelAttrSqlNode, OrderOp>>;
    (yyval.order_by_list)->emplace_back(std::make_pair(*(yyvsp[-2].rel_attr), (yyvsp[-1].orderOp)));
    delete (yyvsp[-2].rel_attr);

    if ((yyvsp[0].order_by_list) != nullptr) {
      (yyval.order_by_list)->insert((yyval.order_by_list)->end(), (yyvsp[0].order_by_list)->begin(), (yyvsp[0].order_by_list)->end());
    }
  }
#line 3380 "yacc_sql.cpp"
    break;

  case 149: /* order_op: DESC  */
#line 1143 "yacc_sql.y"
       { (yyval.orderOp) = ORDER_DESC; }
#line 3386 "yacc_sql.cpp"
    break;

  case 150: /* order_op: ASC  */
#line 1144 "yacc_sql.y"
       { (yyval.orderOp) = ORDER_ASC;  }
#line 3392 "yacc_sql.cpp"
    break;

  case 151: /* order_op: %empty  */
#line 1145 "yacc_sql.y"
       { (yyval.orderOp) = ORDER_DEFAULT; }
#line 3398 "yacc_sql.cpp"
    break;

  case 152: /* where: %empty  */
#line 1151 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3406 "yacc_sql.cpp"
    break;

  case 153: /* where: WHERE condition_list  */
#line 1155 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 3414 "yacc_sql.cpp"
    break;

  case 154: /* condition_list: %empty  */
#line 1161 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3422 "yacc_sql.cpp"
    break;

  case 155: /* condition_list: condition  */
#line 1164 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 3432 "yacc_sql.cpp"
    break;

  case 156: /* condition_list: condition AND condition_list  */
#line 1169 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3442 "yacc_sql.cpp"
    break;

  case 157: /* condition_list: condition OR condition_list  */
#line 1174 "yacc_sql.y"
                                  {
      (yyvsp[-2].condition)->conjunction="OR";
      (yyvsp[0].condition_list)[0][0].conjunction="OR";
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3454 "yacc_sql.cpp"
    break;

  case 158: /* condition: arith_expr comp_op value  */
#line 1183 "yacc_sql.y"
                              {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].value);
    }
#line 3468 "yacc_sql.cpp"
    break;

  case 159: /* condition: arith_expr comp_op rel_attr  */
#line 1192 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].rel_attr);
    }
#line 3482 "yacc_sql.cpp"
    break;

  case 160: /* condition: value comp_op arith_expr  */
#line 1201 "yacc_sql.y"
                               {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 0;
        (yyval.condition)->left_value = *(yyvsp[-2].value);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].value);
    }
#line 3496 "yacc_sql.cpp"
    break;

  case 161: /* condition: rel_attr comp_op arith_expr  */
#line 1210 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 1;
        (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].rel_attr);
    }
#line 3510 "yacc_sql.cpp"
    break;

  case 162: /* condition: arith_expr comp_op arith_expr  */
#line 1219 "yacc_sql.y"
                                    {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
    }
#line 3523 "yacc_sql.cpp"
    break;

  case 163: /* condition: rel_attr comp_op value  */
#line 1227 "yacc_sql.y"
                                {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 1;
        (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].rel_attr);
        delete (yyvsp[0].value);
    }
#line 3538 "yacc_sql.cpp"
    break;

  case 164: /* condition: value comp_op value  */
#line 1237 "yacc_sql.y"
                              {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 0;
        (yyval.condition)->left_value = *(yyvsp[-2].value);
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].value);
        delete (yyvsp[0].value);
    }
#line 3553 "yacc_sql.cpp"
    break;

  case 165: /* condition: rel_attr comp_op rel_attr  */
#line 1247 "yacc_sql.y"
                                   {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 1;
        (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].rel_attr);
        delete (yyvsp[0].rel_attr);
    }
#line 3568 "yacc_sql.cpp"
    break;

  case 166: /* condition: value comp_op rel_attr  */
#line 1257 "yacc_sql.y"
                                {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 0;
        (yyval.condition)->left_value = *(yyvsp[-2].value);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].value);
        delete (yyvsp[0].rel_attr);
    }
#line 3583 "yacc_sql.cpp"
    break;

  case 167: /* condition: rel_attr comp_op SUB_QUERY  */
#line 1267 "yacc_sql.y"
                                    {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 1;
        (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
        (yyval.condition)->right_is_attr = 2;
        (yyval.condition)->right_subquery = (yyvsp[0].string);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].rel_attr);
        free((yyvsp[0].string));
    }
#line 3598 "yacc_sql.cpp"
    break;

  case 168: /* condition: SUB_QUERY comp_op rel_attr  */
#line 1277 "yacc_sql.y"
                                    {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 2;
        (yyval.condition)->left_subquery = (yyvsp[-2].string);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        free((yyvsp[-2].string));
        delete (yyvsp[0].rel_attr);
    }
#line 3613 "yacc_sql.cpp"
    break;

  case 169: /* condition: SUB_QUERY comp_op SUB_QUERY  */
#line 1287 "yacc_sql.y"
                                     {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 2;
        (yyval.condition)->left_subquery = (yyvsp[-2].string);
        (yyval.condition)->right_is_attr = 2;
        (yyval.condition)->right_subquery = (yyvsp[0].string);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        free((yyvsp[-2].string));
        free((yyvsp[0].string));
    }
#line 3628 "yacc_sql.cpp"
    break;

  case 170: /* condition: value comp_op LBRACE value value_list RBRACE  */
#line 1297 "yacc_sql.y"
                                                      {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 0;
        (yyval.condition)->left_value = *(yyvsp[-5].value);
        (yyval.condition)->right_is_attr = 3;
        if ((yyvsp[-1].value_list) != nullptr) {
            (yyval.condition)->right_list.swap(*(yyvsp[-1].value_list));
            delete (yyvsp[-1].value_list);
        }
        (yyval.condition)->right_list.emplace_back(*(yyvsp[-2].value));
        std::reverse((yyval.condition)->right_list.begin(), (yyval.condition)->right_list.end());
        (yyval.condition)->comp = (yyvsp[-4].comp);
        delete (yyvsp[-5].value);
        delete (yyvsp[-2].value);
    }
#line 3648 "yacc_sql.cpp"
    break;

  case 171: /* condition: rel_attr comp_op LBRACE value value_list RBRACE  */
#line 1312 "yacc_sql.y"
                                                         {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 1;
        (yyval.condition)->left_attr = *(yyvsp[-5].rel_attr);
        (yyval.condition)->right_is_attr = 3;
        if ((yyvsp[-1].value_list) != nullptr) {
            (yyval.condition)->right_list.swap(*(yyvsp[-1].value_list));
            delete (yyvsp[-1].value_list);
        }
        (yyval.condition)->right_list.emplace_back(*(yyvsp[-2].value));
        std::reverse((yyval.condition)->right_list.begin(), (yyval.condition)->right_list.end());
        (yyval.condition)->comp = (yyvsp[-4].comp);
        delete (yyvsp[-5].rel_attr);
        delete (yyvsp[-2].value);
    }
#line 3668 "yacc_sql.cpp"
    break;

  case 172: /* condition: SUB_QUERY comp_op LBRACE value value_list RBRACE  */
#line 1327 "yacc_sql.y"
                                                          {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 2;
        (yyval.condition)->left_subquery = (yyvsp[-5].string);
        (yyval.condition)->right_is_attr = 3;
        if ((yyvsp[-1].value_list) != nullptr) {
            (yyval.condition)->right_list.swap(*(yyvsp[-1].value_list));
            delete (yyvsp[-1].value_list);
        }
        (yyval.condition)->right_list.emplace_back(*(yyvsp[-2].value));
        std::reverse((yyval.condition)->right_list.begin(), (yyval.condition)->right_list.end());
        (yyval.condition)->comp = (yyvsp[-4].comp);
        free((yyvsp[-5].string));
        delete (yyvsp[-2].value);
    }
#line 3688 "yacc_sql.cpp"
    break;

  case 173: /* condition: LBRACE value value_list RBRACE comp_op value  */
#line 1342 "yacc_sql.y"
                                                   {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 3;
        if ((yyvsp[-3].value_list) != nullptr) {
            (yyval.condition)->left_list.swap(*(yyvsp[-3].value_list));
            delete (yyvsp[-3].value_list);
        }
        (yyval.condition)->left_list.emplace_back(*(yyvsp[-4].value));
        std::reverse((yyval.condition)->left_list.begin(), (yyval.condition)->left_list.end());
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-4].value);
        delete (yyvsp[0].value);
    }
#line 3708 "yacc_sql.cpp"
    break;

  case 174: /* condition: LBRACE value value_list RBRACE comp_op rel_attr  */
#line 1357 "yacc_sql.y"
                                                      {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 3;
        if ((yyvsp[-3].value_list) != nullptr) {
            (yyval.condition)->left_list.swap(*(yyvsp[-3].value_list));
            delete (yyvsp[-3].value_list);
        }
        (yyval.condition)->left_list.emplace_back(*(yyvsp[-4].value));
        std::reverse((yyval.condition)->left_list.begin(), (yyval.condition)->left_list.end());
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-4].value);
        delete (yyvsp[0].rel_attr);
    }
#line 3728 "yacc_sql.cpp"
    break;

  case 175: /* condition: LBRACE value value_list RBRACE comp_op SUB_QUERY  */
#line 1372 "yacc_sql.y"
                                                       {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 3;
        if ((yyvsp[-3].value_list) != nullptr) {
            (yyval.condition)->left_list.swap(*(yyvsp[-3].value_list));
            delete (yyvsp[-3].value_list);
        }
        (yyval.condition)->left_list.emplace_back(*(yyvsp[-4].value));
        std::reverse((yyval.condition)->left_list.begin(), (yyval.condition)->left_list.end());
        (yyval.condition)->right_is_attr = 2;
        (yyval.condition)->right_subquery = (yyvsp[0].string);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-4].value);
        free((yyvsp[0].string));
    }
#line 3748 "yacc_sql.cpp"
    break;

  case 176: /* condition: LBRACE value value_list RBRACE comp_op LBRACE value value_list RBRACE  */
#line 1387 "yacc_sql.y"
                                                                            {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 3;
        if ((yyvsp[-6].value_list) != nullptr) {
            (yyval.condition)->left_list.swap(*(yyvsp[-6].value_list));
            delete (yyvsp[-6].value_list);
        }
        (yyval.condition)->left_list.emplace_back(*(yyvsp[-7].value));
        std::reverse((yyval.condition)->left_list.begin(), (yyval.condition)->left_list.end());
        (yyval.condition)->right_is_attr = 3;
        if ((yyvsp[-1].value_list) != nullptr) {
            (yyval.condition)->right_list.swap(*(yyvsp[-1].value_list));
            delete (yyvsp[-1].value_list);
        }
        (yyval.condition)->right_list.emplace_back(*(yyvsp[-2].value));
        std::reverse((yyval.condition)->right_list.begin(), (yyval.condition)->right_list.end());
        (yyval.condition)->comp = (yyvsp[-4].comp);
        delete (yyvsp[-7].value);
        delete (yyvsp[-2].value);
    }
#line 3773 "yacc_sql.cpp"
    break;

  case 177: /* condition: aggr_expr comp_op value  */
#line 1407 "yacc_sql.y"
                              {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;     
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].value);
    }
#line 3787 "yacc_sql.cpp"
    break;

  case 178: /* condition: aggr_expr comp_op rel_attr  */
#line 1416 "yacc_sql.y"
                                 {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;     
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].rel_attr);
    }
#line 3801 "yacc_sql.cpp"
    break;

  case 179: /* condition: aggr_expr comp_op aggr_expr  */
#line 1425 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 4;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);  
    }
#line 3814 "yacc_sql.cpp"
    break;

  case 180: /* condition: value is_null_choice  */
#line 1433 "yacc_sql.y"
                           {
      (yyval.condition) = new ConditionSqlNode;
      Value val;
      val.set_null(0);
        
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-1].value);  
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = val;
      (yyval.condition)->comp = (yyvsp[0].comp);
      delete (yyvsp[-1].value);
    }
#line 3831 "yacc_sql.cpp"
    break;

  case 181: /* condition: rel_attr is_null_choice  */
#line 1445 "yacc_sql.y"
                              {
      (yyval.condition) = new ConditionSqlNode;
      Value val;
      val.set_null(0);

      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-1].rel_attr);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = val;
      (yyval.condition)->comp = (yyvsp[0].comp);
      delete (yyvsp[-1].rel_attr);
    }
#line 3848 "yacc_sql.cpp"
    break;

  case 182: /* is_null_choice: IS NULL_KY  */
#line 1460 "yacc_sql.y"
                 { (yyval.comp) =  OP_ISNULL; }
#line 3854 "yacc_sql.cpp"
    break;

  case 183: /* is_null_choice: IS NOT NULL_KY  */
#line 1461 "yacc_sql.y"
                     { (yyval.comp) = OP_ISNOTNULL; }
#line 3860 "yacc_sql.cpp"
    break;

  case 184: /* comp_op: EQ  */
#line 1465 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3866 "yacc_sql.cpp"
    break;

  case 185: /* comp_op: LT  */
#line 1466 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3872 "yacc_sql.cpp"
    break;

  case 186: /* comp_op: GT  */
#line 1467 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3878 "yacc_sql.cpp"
    break;

  case 187: /* comp_op: LE  */
#line 1468 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3884 "yacc_sql.cpp"
    break;

  case 188: /* comp_op: GE  */
#line 1469 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3890 "yacc_sql.cpp"
    break;

  case 189: /* comp_op: NE  */
#line 1470 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3896 "yacc_sql.cpp"
    break;

  case 190: /* comp_op: LIKE  */
#line 1471 "yacc_sql.y"
           { (yyval.comp) = CLIKE; }
#line 3902 "yacc_sql.cpp"
    break;

  case 191: /* comp_op: NOT LIKE  */
#line 1472 "yacc_sql.y"
               { (yyval.comp) = CNLIKE; }
#line 3908 "yacc_sql.cpp"
    break;

  case 192: /* comp_op: IN  */
#line 1473 "yacc_sql.y"
         { (yyval.comp) = IN_LIST; }
#line 3914 "yacc_sql.cpp"
    break;

  case 193: /* comp_op: NOT IN  */
#line 1474 "yacc_sql.y"
             { (yyval.comp) = NOTIN_LIST; }
#line 3920 "yacc_sql.cpp"
    break;

  case 194: /* comp_op: EXIST  */
#line 1475 "yacc_sql.y"
            { (yyval.comp) = EXIST_LIST; }
#line 3926 "yacc_sql.cpp"
    break;

  case 195: /* comp_op: NOT EXIST  */
#line 1476 "yacc_sql.y"
                { (yyval.comp) = NOTEXIST_LIST; }
#line 3932 "yacc_sql.cpp"
    break;

  case 196: /* func_op: I2_DISTANCE_T  */
#line 1480 "yacc_sql.y"
                    { (yyval.func) = I2_DISTANCE; }
#line 3938 "yacc_sql.cpp"
    break;

  case 197: /* func_op: COSINE_DISTANCE_T  */
#line 1481 "yacc_sql.y"
                        { (yyval.func) = COSINE_DISTANCE; }
#line 3944 "yacc_sql.cpp"
    break;

  case 198: /* func_op: INNER_PRODUCT_T  */
#line 1482 "yacc_sql.y"
                      { (yyval.func) = INNER_PRODUCT; }
#line 3950 "yacc_sql.cpp"
    break;

  case 199: /* group_by: %empty  */
#line 1486 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 3958 "yacc_sql.cpp"
    break;

  case 200: /* group_by: GROUP BY expression_list  */
#line 1490 "yacc_sql.y"
          {
        (yyval.expression_list) = (yyvsp[0].expression_list);
	  }
#line 3966 "yacc_sql.cpp"
    break;

  case 201: /* having: %empty  */
#line 1496 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3974 "yacc_sql.cpp"
    break;

  case 202: /* having: HAVING condition_list  */
#line 1500 "yacc_sql.y"
    {
      (yyval.condition_list) = (yyvsp[0].condition_list);
    }
#line 3982 "yacc_sql.cpp"
    break;

  case 203: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1507 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3996 "yacc_sql.cpp"
    break;

  case 204: /* explain_stmt: EXPLAIN ID  */
#line 1520 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
    }
#line 4004 "yacc_sql.cpp"
    break;

  case 205: /* explain_vec_stmt: EXPLAIN SELECT expression_list FROM ID where vec_order_by  */
#line 1527 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_VEC_EXPLAIN);
      (yyval.sql_node)->vec_explain.table_name = (yyvsp[-2].string);
      (yyval.sql_node)->vec_explain.inited = 1;
      (yyval.sql_node)->vec_explain.vec_order_by = *(yyvsp[0].vec_order_by);
      free((yyvsp[-2].string));
    }
#line 4016 "yacc_sql.cpp"
    break;

  case 206: /* set_variable_stmt: SET ID EQ value  */
#line 1539 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 4028 "yacc_sql.cpp"
    break;


#line 4032 "yacc_sql.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1551 "yacc_sql.y"

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
