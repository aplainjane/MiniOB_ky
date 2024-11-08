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
  YYSYMBOL_drop_index_stmt = 106,          /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 107,        /* create_table_stmt  */
  YYSYMBOL_as_option = 108,                /* as_option  */
  YYSYMBOL_attr_def_list = 109,            /* attr_def_list  */
  YYSYMBOL_attr_def = 110,                 /* attr_def  */
  YYSYMBOL_isnull = 111,                   /* isnull  */
  YYSYMBOL_number = 112,                   /* number  */
  YYSYMBOL_type = 113,                     /* type  */
  YYSYMBOL_insert_stmt = 114,              /* insert_stmt  */
  YYSYMBOL_value_list = 115,               /* value_list  */
  YYSYMBOL_value = 116,                    /* value  */
  YYSYMBOL_storage_format = 117,           /* storage_format  */
  YYSYMBOL_delete_stmt = 118,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 119,              /* update_stmt  */
  YYSYMBOL_set_clause_list = 120,          /* set_clause_list  */
  YYSYMBOL_set_clause = 121,               /* set_clause  */
  YYSYMBOL_select_stmt = 122,              /* select_stmt  */
  YYSYMBOL_calc_stmt = 123,                /* calc_stmt  */
  YYSYMBOL_expression_list = 124,          /* expression_list  */
  YYSYMBOL_expression = 125,               /* expression  */
  YYSYMBOL_simple_expression = 126,        /* simple_expression  */
  YYSYMBOL_arith_expr = 127,               /* arith_expr  */
  YYSYMBOL_aggr_expr = 128,                /* aggr_expr  */
  YYSYMBOL_rel_attr = 129,                 /* rel_attr  */
  YYSYMBOL_rel_list = 130,                 /* rel_list  */
  YYSYMBOL_join_list = 131,                /* join_list  */
  YYSYMBOL_order_by = 132,                 /* order_by  */
  YYSYMBOL_vec_order_by = 133,             /* vec_order_by  */
  YYSYMBOL_order_by_list = 134,            /* order_by_list  */
  YYSYMBOL_order_op = 135,                 /* order_op  */
  YYSYMBOL_where = 136,                    /* where  */
  YYSYMBOL_condition_list = 137,           /* condition_list  */
  YYSYMBOL_condition = 138,                /* condition  */
  YYSYMBOL_is_null_choice = 139,           /* is_null_choice  */
  YYSYMBOL_comp_op = 140,                  /* comp_op  */
  YYSYMBOL_func_op = 141,                  /* func_op  */
  YYSYMBOL_group_by = 142,                 /* group_by  */
  YYSYMBOL_having = 143,                   /* having  */
  YYSYMBOL_load_data_stmt = 144,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 145,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 146,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 147             /* opt_semicolon  */
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
#define YYFINAL  80
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   786

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  199
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  404

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
       0,   246,   246,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   278,   284,   289,   295,   301,   307,
     313,   320,   326,   334,   353,   375,   394,   404,   433,   448,
     459,   462,   469,   472,   485,   494,   507,   510,   514,   521,
     524,   525,   526,   527,   528,   529,   532,   549,   552,   563,
     567,   571,   577,   583,   589,   592,   599,   611,   641,   647,
     657,   664,   677,   685,   723,   763,   771,   776,   787,   791,
     794,   797,   800,   803,   808,   814,   817,   820,   823,   828,
     834,   839,   847,   850,   853,   856,   859,   862,   865,   868,
     871,   874,   877,   880,   883,   886,   889,   892,   895,   898,
     901,   904,   907,   910,   913,   916,   919,   922,   925,   930,
     933,   936,   939,   942,   945,   951,   957,   963,   969,   978,
     983,   994,   997,  1010,  1013,  1016,  1036,  1039,  1051,  1062,
    1065,  1078,  1079,  1080,  1086,  1090,  1096,  1099,  1104,  1109,
    1118,  1127,  1136,  1145,  1154,  1162,  1172,  1182,  1192,  1202,
    1212,  1222,  1232,  1247,  1262,  1277,  1292,  1307,  1322,  1342,
    1351,  1360,  1368,  1380,  1395,  1396,  1400,  1401,  1402,  1403,
    1404,  1405,  1406,  1407,  1408,  1409,  1410,  1411,  1415,  1416,
    1417,  1421,  1424,  1431,  1434,  1441,  1454,  1462,  1472,  1473
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
  "drop_index_stmt", "create_table_stmt", "as_option", "attr_def_list",
  "attr_def", "isnull", "number", "type", "insert_stmt", "value_list",
  "value", "storage_format", "delete_stmt", "update_stmt",
  "set_clause_list", "set_clause", "select_stmt", "calc_stmt",
  "expression_list", "expression", "simple_expression", "arith_expr",
  "aggr_expr", "rel_attr", "rel_list", "join_list", "order_by",
  "vec_order_by", "order_by_list", "order_op", "where", "condition_list",
  "condition", "is_null_choice", "comp_op", "func_op", "group_by",
  "having", "load_data_stmt", "explain_stmt", "set_variable_stmt",
  "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-353)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-92)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     690,    30,    91,   463,   463,   -67,    14,  -353,    -1,    41,
     -51,  -353,  -353,  -353,  -353,  -353,   -49,    60,   690,    38,
     111,  -353,  -353,  -353,  -353,  -353,  -353,  -353,  -353,  -353,
    -353,  -353,  -353,  -353,  -353,  -353,  -353,  -353,  -353,  -353,
    -353,  -353,    62,   142,    76,   153,    98,   109,   463,  -353,
    -353,  -353,  -353,   151,   176,   177,   178,   184,  -353,  -353,
     171,  -353,  -353,   463,  -353,  -353,  -353,    -5,  -353,  -353,
     193,   180,  -353,  -353,   145,   147,   188,   174,   189,  -353,
    -353,  -353,  -353,    -9,   162,   191,   163,  -353,   199,   -15,
     211,   291,   324,   361,   394,   202,  -353,   463,   463,   463,
     463,   463,   430,   213,   220,   227,   215,   -34,   217,   219,
    -353,   289,   260,   224,   263,   228,  -353,  -353,   287,  -353,
     293,  -353,   294,  -353,   296,  -353,   297,  -353,  -353,   -25,
     -25,  -353,  -353,  -353,   299,   302,   301,   478,  -353,   267,
      -7,  -353,  -353,   295,   426,   307,  -353,   251,   313,   253,
    -353,  -353,  -353,  -353,  -353,  -353,  -353,   262,    34,   -34,
     493,   720,   493,   705,    81,   666,   720,   705,  -353,    84,
     -27,   215,  -353,   340,  -353,  -353,  -353,  -353,  -353,  -353,
      -8,   219,   329,   331,   273,   335,   302,    34,   279,   227,
     341,   493,   108,   -11,  -353,   129,  -353,  -353,  -353,  -353,
    -353,  -353,  -353,  -353,  -353,    79,  -353,    85,    97,   -32,
    -353,   511,   526,   543,   556,   564,   576,   584,   594,   606,
     493,   664,  -353,   339,   478,   478,  -353,  -353,  -353,   281,
     285,   319,  -353,  -353,   307,    -4,   303,   302,   304,  -353,
    -353,   333,   381,   -34,   366,   367,  -353,  -353,  -353,  -353,
     -34,  -353,  -353,   337,  -353,   493,   187,   194,   254,   493,
      85,    97,   493,    85,    97,   493,  -353,  -353,   493,  -353,
    -353,   493,    85,    97,   493,    85,    97,   493,  -353,  -353,
     493,  -353,  -353,   187,   194,   254,  -353,  -353,  -353,   493,
    -353,   187,   194,   254,  -353,  -353,  -353,  -353,   374,  -353,
    -353,   348,   289,  -353,   302,   386,   388,   478,   410,   378,
     341,  -353,   720,   341,  -353,   108,    90,   107,   123,   137,
     161,   166,   182,   250,   108,   -26,   354,  -353,   403,  -353,
     362,    34,   463,   478,   425,  -353,   409,   411,   412,  -353,
    -353,  -353,  -353,  -353,  -353,  -353,  -353,   413,  -353,   363,
    -353,   438,  -353,  -353,  -353,   444,  -353,  -353,   -34,  -353,
    -353,  -353,  -353,  -353,  -353,  -353,   392,   -40,   341,   404,
     175,   445,   446,   385,  -353,  -353,   455,   398,  -353,   460,
     398,  -353,   462,   417,   175,   -34,   428,   455,   473,     2,
    -353,   427,   477,   285,   431,  -353,   442,   424,   497,   443,
     461,   447,   500,  -353
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,    27,    28,    29,    25,    24,     0,     0,     0,     0,
     198,    23,    22,    15,    16,    17,    18,     9,    10,    11,
      12,    13,    14,     8,     5,     7,     6,     4,     3,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,    63,
     188,   189,   190,     0,     0,     0,     0,     0,    59,    60,
     129,    61,    62,     0,    85,    83,    75,    76,    87,    84,
       0,    72,    32,    31,     0,     0,     0,     0,     0,   196,
       1,   199,     2,    40,     0,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,    86,     0,     0,     0,
       0,     0,     0,     0,     0,   144,     0,     0,     0,     0,
      41,     0,     0,     0,     0,     0,    78,   124,     0,   125,
       0,   128,     0,   127,     0,   126,     0,   130,    77,    79,
      80,    81,    82,    89,     0,   131,     0,   146,    66,     0,
     144,    68,   197,     0,     0,    42,    39,     0,     0,     0,
      36,   119,   120,   123,   121,   122,    88,     0,   133,     0,
       0,     0,     0,    90,     0,     0,     0,    91,   145,   147,
       0,     0,    67,     0,    50,    51,    54,    55,    52,    53,
      46,     0,     0,     0,     0,     0,   131,   133,     0,   144,
      57,     0,    90,     0,    91,     0,   182,   184,   186,   176,
     177,   178,   179,   180,   181,     0,    90,   102,   101,     0,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,     0,   146,   146,    71,    70,    69,     0,
       0,     0,    47,    45,    42,    64,     0,   131,     0,   132,
     134,     0,   191,     0,     0,     0,    92,   183,   185,   187,
       0,   161,   160,     0,   174,     0,   156,   152,   158,     0,
     115,   107,     0,   116,   108,     0,   117,   109,     0,   118,
     110,     0,   103,   111,     0,   104,   112,     0,   105,   113,
       0,   106,   114,   150,   154,   151,   169,   171,   170,     0,
     159,   155,   153,   157,   148,   149,   195,    49,     0,    48,
      43,     0,     0,    37,   131,     0,     0,   146,     0,   193,
      57,    56,     0,    57,   175,    90,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    46,     0,    38,     0,    33,
       0,   133,     0,   146,   136,    58,     0,     0,     0,    97,
      98,    99,   100,    93,    94,    95,    96,     0,    44,     0,
      34,     0,   135,   192,   194,     0,    73,    74,     0,   167,
     165,   166,   164,   162,   163,    65,     0,     0,    57,     0,
     143,     0,     0,     0,   142,   141,   139,     0,   168,     0,
       0,   137,     0,     0,   143,     0,     0,   139,     0,     0,
     140,     0,     0,     0,     0,   138,     0,     0,     0,     0,
       0,     0,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -353,  -353,   506,  -353,  -353,  -353,  -353,  -353,  -353,  -353,
    -353,  -353,  -353,  -353,  -353,  -353,   290,   292,   346,   204,
     141,  -353,  -353,  -152,    -3,  -353,  -353,  -353,  -353,   365,
    -109,  -353,    31,   103,    47,   -76,  -119,    18,  -175,  -178,
    -353,  -353,   150,   154,  -136,  -157,  -353,   400,  -160,  -352,
    -353,  -353,  -353,  -353,  -353,  -353
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,   111,   182,   145,   233,
     298,   180,    34,   244,   206,   303,    35,    36,   140,   141,
      37,    38,    66,    67,   164,   193,    68,   194,   158,   189,
     356,   357,   381,   376,   138,   168,   169,   210,   205,    70,
     309,   334,    39,    40,    41,    82
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    65,   146,   211,   172,   220,   221,   223,   116,   240,
     -40,   239,   246,   109,   230,   371,    72,   171,   166,    97,
     253,    69,    69,    49,    73,   254,   231,    50,    51,    52,
      49,   232,    76,   137,    77,    71,    74,   392,    80,    42,
     245,    43,    44,    60,   231,    65,   301,    58,    59,   232,
      61,   110,    62,   242,    58,    59,   110,    61,   226,    62,
      65,   165,   305,    45,   100,   101,    69,   294,   295,    50,
      51,    52,    98,    99,   100,   101,   216,   217,   218,   219,
      75,    69,    98,    99,   100,   101,   208,    65,    65,    65,
      65,    65,   187,   188,    65,    65,    65,    65,    65,    65,
      46,   250,   287,    47,   142,   166,   166,    78,    69,    69,
      69,    69,    69,   339,    81,    69,    69,    69,    69,    69,
      69,   118,   120,   122,   124,   126,   224,   225,   128,   328,
     340,   -57,   243,   134,   163,   257,   261,   264,   267,   270,
     273,   276,   279,   282,   284,    83,   341,   292,   165,   165,
     331,    89,   336,   352,    84,   167,   190,   192,   335,    85,
     342,   337,    60,   338,   251,    86,    96,   227,   212,   213,
     214,   215,   347,    90,   214,   215,   354,   212,   213,   214,
     215,    87,   247,   248,   343,   249,   218,   219,   166,   344,
     374,   375,    88,   327,   212,   213,   214,   215,    91,    92,
      93,   129,   130,   131,   132,   345,    94,    95,   256,   207,
     212,   213,   214,   215,   166,   102,   372,   283,   286,   103,
     291,   163,   163,   252,   212,   213,   214,   215,   104,   258,
     105,   165,   106,    48,   117,   107,   113,   108,   285,   288,
     310,   293,   167,   167,   115,   112,   114,   313,   212,   213,
     214,   215,   315,   212,   213,   214,   215,   165,   136,   260,
     263,   266,   269,   272,   275,   278,   281,   137,    49,   212,
     213,   214,   215,   346,   -90,   -90,   -90,   -90,    50,    51,
      52,   216,   217,   218,   219,   127,   324,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   135,    62,   139,    63,
      64,   143,   144,     4,   163,   147,   316,   148,   149,   317,
     151,   150,   318,    48,   119,   319,   152,   153,   320,   154,
     155,   321,   156,   159,   322,   167,   157,   323,   170,    65,
     163,   181,   173,   360,   183,   184,   185,   212,   213,   214,
     215,   -91,   -91,   -91,   -91,   186,    48,   121,    49,   229,
      69,   167,   235,   236,   361,   368,   237,   238,    50,    51,
      52,   289,   241,   353,   296,   243,   297,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   299,    62,   307,    63,
      64,    49,   388,    48,   123,   370,   304,   306,   308,   311,
     312,    50,    51,    52,   314,   382,    49,   325,   384,   326,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   329,
      62,   330,    63,    64,   332,   349,    48,   125,    49,   333,
      58,    59,    60,    61,   290,    62,   350,   162,    50,    51,
      52,   358,   351,   355,   362,   363,   364,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   365,    62,   367,    63,
      64,    49,    48,   133,   174,   175,   176,   177,   178,   179,
     366,    50,    51,    52,   369,   373,    49,   377,   379,   378,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   380,
      62,    60,    63,    64,   383,    48,   385,    49,   386,   389,
      58,    59,    60,    61,   359,    62,   391,    50,    51,    52,
     160,   394,   393,   397,   396,   398,    53,    54,    55,    56,
      57,    58,    59,    60,    61,   191,    62,   400,    63,    64,
      49,   399,   401,   403,    79,   302,   300,   234,   402,   348,
      50,    51,    52,   255,   395,    49,   228,   390,   387,    53,
      54,    55,    56,    57,    58,    59,    60,    61,   259,    62,
      49,    63,    64,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   161,    62,   262,   162,   222,    49,     0,
       0,     0,     0,     0,    58,    59,    60,    61,   265,    62,
       0,   162,     0,    49,     0,     0,   268,     0,     0,     0,
       0,     0,    58,    59,    60,    61,     0,    62,   271,   162,
      49,     0,     0,     0,     0,     0,   274,    58,    59,    60,
      61,     0,    62,    49,   162,     0,   277,     0,     0,     0,
       0,    49,     0,     0,    58,    59,    60,    61,   280,    62,
       0,   162,     0,    49,     0,     0,     0,    58,    59,    60,
      61,    49,    62,     0,   162,    58,    59,    60,    61,     0,
      62,    49,   162,     0,     0,     0,     0,    58,    59,    60,
      61,     0,    62,    49,   162,    58,    59,    60,    61,     0,
      62,     0,   162,     0,     0,    58,    59,    60,    61,     0,
      62,     0,   162,     0,     0,     0,     0,    58,    59,    60,
      61,     0,    62,     0,   162,     1,     2,     0,     0,     0,
       0,     0,     0,     3,     4,     0,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,   195,   196,
     197,    49,   198,     0,    14,    15,     0,   199,   200,   201,
     202,   203,   204,     0,    16,     0,    17,     0,     0,    18,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
      62,     0,     0,   216,   217,   218,   219,   195,   196,   197,
     209,   198,     0,     0,     0,     0,   199,   200,   201,   202,
     203,   204,   195,   196,   197,     0,   198,     0,     0,     0,
       0,   199,   200,   201,   202,   203,   204
};

static const yytype_int16 yycheck[] =
{
       3,     4,   111,   163,   140,   165,   166,   167,    23,   187,
      14,   186,    23,    22,    22,   367,    83,    24,   137,    24,
      52,     3,     4,    57,    10,    57,    52,    67,    68,    69,
      57,    57,    83,    40,    83,     4,    37,   389,     0,     9,
     192,    11,    12,    83,    52,    48,    50,    81,    82,    57,
      84,    60,    86,   189,    81,    82,    60,    84,    85,    86,
      63,   137,   237,    33,    89,    90,    48,   224,   225,    67,
      68,    69,    87,    88,    89,    90,    87,    88,    89,    90,
      39,    63,    87,    88,    89,    90,   162,    90,    91,    92,
      93,    94,    58,    59,    97,    98,    99,   100,   101,   102,
       9,    22,   221,    12,   107,   224,   225,    47,    90,    91,
      92,    93,    94,    23,     3,    97,    98,    99,   100,   101,
     102,    90,    91,    92,    93,    94,    42,    43,    97,   304,
      23,    23,    24,   102,   137,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    83,    23,   223,   224,   225,
     307,    48,   312,   331,    12,   137,   159,   160,   310,    83,
      23,   313,    83,   315,    85,    12,    63,   170,    87,    88,
      89,    90,   324,    22,    89,    90,   333,    87,    88,    89,
      90,    83,    53,    54,    23,    56,    89,    90,   307,    23,
      15,    16,    83,   302,    87,    88,    89,    90,    22,    22,
      22,    98,    99,   100,   101,    23,    22,    36,   211,   162,
      87,    88,    89,    90,   333,    22,   368,   220,   221,    39,
     223,   224,   225,   205,    87,    88,    89,    90,    83,   211,
      83,   307,    44,    22,    23,    61,    45,    48,   220,   221,
     243,   223,   224,   225,    45,    83,    83,   250,    87,    88,
      89,    90,   255,    87,    88,    89,    90,   333,    38,   212,
     213,   214,   215,   216,   217,   218,   219,    40,    57,    87,
      88,    89,    90,    23,    87,    88,    89,    90,    67,    68,
      69,    87,    88,    89,    90,    83,   289,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    83,    86,    83,    88,
      89,    84,    83,    14,   307,    45,   259,    83,    45,   262,
      23,    83,   265,    22,    23,   268,    23,    23,   271,    23,
      23,   274,    23,    22,   277,   307,    24,   280,    61,   332,
     333,    24,    37,   336,    83,    22,    83,    87,    88,    89,
      90,    87,    88,    89,    90,    83,    22,    23,    57,     9,
     332,   333,    23,    22,   336,   358,    83,    22,    67,    68,
      69,    22,    83,   332,    83,    24,    81,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    57,    86,    45,    88,
      89,    57,   385,    22,    23,   367,    83,    83,     7,    23,
      23,    67,    68,    69,    57,   377,    57,    23,   380,    51,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    23,
      86,    23,    88,    89,     4,    61,    22,    23,    57,    41,
      81,    82,    83,    84,    85,    86,    23,    88,    67,    68,
      69,    22,    70,     8,    23,    23,    23,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    83,    86,     4,    88,
      89,    57,    22,    23,    28,    29,    30,    31,    32,    33,
      22,    67,    68,    69,    72,    61,    57,    22,    83,    23,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    24,
      86,    83,    88,    89,    24,    22,    24,    57,    71,    61,
      81,    82,    83,    84,    85,    86,    23,    67,    68,    69,
      22,    24,    75,    61,    73,    81,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    22,    86,    74,    88,    89,
      57,    24,    61,    23,    18,   235,   234,   181,    81,   325,
      67,    68,    69,    22,   393,    57,   171,   387,   384,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    22,    86,
      57,    88,    89,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    22,    88,   167,    57,    -1,
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
      86,    -1,    88,    -1,    -1,    81,    82,    83,    84,    -1,
      86,    -1,    88,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    -1,    86,    -1,    88,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    26,    27,    52,    53,
      54,    57,    56,    -1,    34,    35,    -1,    61,    62,    63,
      64,    65,    66,    -1,    44,    -1,    46,    -1,    -1,    49,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    -1,    -1,    87,    88,    89,    90,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,    52,    53,    54,    -1,    56,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    66
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    13,    14,    16,    17,    18,    19,    20,
      21,    25,    26,    27,    34,    35,    44,    46,    49,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   114,   118,   119,   122,   123,   144,
     145,   146,     9,    11,    12,    33,     9,    12,    22,    57,
      67,    68,    69,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    86,    88,    89,   116,   124,   125,   128,   129,
     141,   124,    83,    10,    37,    39,    83,    83,    47,    94,
       0,     3,   147,    83,    12,    83,    12,    83,    83,   125,
      22,    22,    22,    22,    22,    36,   125,    24,    87,    88,
      89,    90,    22,    39,    83,    83,    44,    61,    48,    22,
      60,   108,    83,    45,    83,    45,    23,    23,   124,    23,
     124,    23,   124,    23,   124,    23,   124,    83,   124,   125,
     125,   125,   125,    23,   124,    83,    38,    40,   136,    83,
     120,   121,   116,    84,    83,   110,   122,    45,    83,    45,
      83,    23,    23,    23,    23,    23,    23,    24,   130,    22,
      22,    85,    88,   116,   126,   127,   128,   129,   137,   138,
      61,    24,   136,    37,    28,    29,    30,    31,    32,    33,
     113,    24,   109,    83,    22,    83,    83,    58,    59,   131,
     116,    22,   116,   127,   129,    52,    53,    54,    56,    61,
      62,    63,    64,    65,    66,   140,   116,   126,   127,    55,
     139,   140,    87,    88,    89,    90,    87,    88,    89,    90,
     140,   140,   139,   140,    42,    43,    85,   116,   121,     9,
      22,    52,    57,   111,   110,    23,    22,    83,    22,   130,
     131,    83,   136,    24,   115,   115,    23,    53,    54,    56,
      22,    85,   129,    52,    57,    22,   116,   127,   129,    22,
     126,   127,    22,   126,   127,    22,   126,   127,    22,   126,
     127,    22,   126,   127,    22,   126,   127,    22,   126,   127,
      22,   126,   127,   116,   127,   129,   116,   128,   129,    22,
      85,   116,   127,   129,   137,   137,    83,    81,   112,    57,
     109,    50,   108,   117,    83,   130,    83,    45,     7,   142,
     116,    23,    23,   116,    57,   116,   126,   126,   126,   126,
     126,   126,   126,   126,   116,    23,    51,   122,   130,    23,
      23,   137,     4,    41,   143,   115,   140,   115,   115,    23,
      23,    23,    23,    23,    23,    23,    23,   115,   111,    61,
      23,    70,   131,   124,   137,     8,   132,   133,    22,    85,
     116,   129,    23,    23,    23,    83,    22,     4,   116,    72,
     129,   141,   115,    61,    15,    16,   135,    22,    23,    83,
      24,   134,   129,    24,   129,    24,    71,   135,   116,    61,
     134,    23,   141,    75,    24,   112,    73,    61,    81,    24,
      74,    61,    81,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   104,   105,   106,   107,   107,   107,
     108,   108,   109,   109,   110,   110,   111,   111,   111,   112,
     113,   113,   113,   113,   113,   113,   114,   115,   115,   116,
     116,   116,   116,   116,   117,   117,   118,   119,   120,   120,
     121,   121,   122,   122,   122,   123,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   129,
     129,   130,   130,   131,   131,   131,   132,   132,   133,   134,
     134,   135,   135,   135,   136,   136,   137,   137,   137,   137,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   139,   139,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   141,   141,
     141,   142,   142,   143,   143,   144,   145,   146,   147,   147
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     2,     9,    10,    27,     5,     8,     9,     5,
       0,     1,     0,     3,     6,     3,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     8,     0,     3,     1,
       1,     1,     1,     1,     0,     4,     4,     5,     1,     3,
       3,     3,     2,    10,    10,     2,     1,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     2,     1,     4,     3,
       1,     1,     3,     5,     5,     5,     5,     5,     5,     5,
       5,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       4,     4,     4,     4,     3,     3,     3,     3,     3,     1,
       3,     0,     3,     0,     2,     5,     0,     5,    10,     0,
       4,     1,     1,     0,     0,     2,     0,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     6,     6,     6,     6,     6,     6,     9,     3,
       3,     3,     2,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     2,     1,     1,
       1,     0,     3,     0,     2,     7,     2,     4,     0,     1
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
#line 247 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 2026 "yacc_sql.cpp"
    break;

  case 24: /* exit_stmt: EXIT  */
#line 278 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 2035 "yacc_sql.cpp"
    break;

  case 25: /* help_stmt: HELP  */
#line 284 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 2043 "yacc_sql.cpp"
    break;

  case 26: /* sync_stmt: SYNC  */
#line 289 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 2051 "yacc_sql.cpp"
    break;

  case 27: /* begin_stmt: TRX_BEGIN  */
#line 295 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 2059 "yacc_sql.cpp"
    break;

  case 28: /* commit_stmt: TRX_COMMIT  */
#line 301 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 2067 "yacc_sql.cpp"
    break;

  case 29: /* rollback_stmt: TRX_ROLLBACK  */
#line 307 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 2075 "yacc_sql.cpp"
    break;

  case 30: /* drop_table_stmt: DROP TABLE ID  */
#line 313 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2085 "yacc_sql.cpp"
    break;

  case 31: /* show_tables_stmt: SHOW TABLES  */
#line 320 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 2093 "yacc_sql.cpp"
    break;

  case 32: /* desc_table_stmt: DESC ID  */
#line 326 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2103 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID rel_list RBRACE  */
#line 335 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-6].string);
      create_index.relation_name = (yyvsp[-4].string);
      if ((yyvsp[-1].relation_list) != nullptr) {
        create_index.attribute_names.swap(*(yyvsp[-1].relation_list));
      }
      create_index.attribute_names.emplace_back((yyvsp[-2].string));

      create_index.unique = false;
      free((yyvsp[-6].string));
      free((yyvsp[-4].string));
      free((yyvsp[-2].string));
      if ((yyvsp[-1].relation_list) != nullptr){
        delete((yyvsp[-1].relation_list));
      }
    }
#line 2126 "yacc_sql.cpp"
    break;

  case 34: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID rel_list RBRACE  */
#line 354 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-6].string);
      create_index.relation_name = (yyvsp[-4].string);
      // create_index.attribute_name = $8;
      if ((yyvsp[-1].relation_list) != nullptr){
        create_index.attribute_names.swap(*(yyvsp[-1].relation_list));
      }
      create_index.attribute_names.emplace_back((yyvsp[-2].string));
      create_index.unique = true;
      free((yyvsp[-6].string));
      free((yyvsp[-4].string));
      free((yyvsp[-2].string));
      if ((yyvsp[-1].relation_list) != nullptr){
        delete((yyvsp[-1].relation_list));
      }
    }
#line 2149 "yacc_sql.cpp"
    break;

  case 35: /* create_vec_index_stmt: CREATE VECTOR_T INDEX ID ON ID LBRACE ID RBRACE WITH LBRACE TYPE EQ ID COMMA DISTANCE EQ func_op COMMA LISTS EQ NUMBER COMMA PROBES EQ NUMBER RBRACE  */
#line 376 "yacc_sql.y"
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
#line 2169 "yacc_sql.cpp"
    break;

  case 36: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 395 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2181 "yacc_sql.cpp"
    break;

  case 37: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format  */
#line 405 "yacc_sql.y"
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
      create_table.attr_infos.push_back(null_field);

      if ((yyvsp[0].string) != nullptr) {
        create_table.storage_format = (yyvsp[0].string);
        free((yyvsp[0].string));
      }
    }
#line 2214 "yacc_sql.cpp"
    break;

  case 38: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE as_option select_stmt  */
#line 434 "yacc_sql.y"
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
#line 2233 "yacc_sql.cpp"
    break;

  case 39: /* create_table_stmt: CREATE TABLE ID as_option select_stmt  */
#line 449 "yacc_sql.y"
    {
      (yyval.sql_node) = (yyvsp[0].sql_node);
      (yyval.sql_node)->flag = SCF_CREATE_TABLE;
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-2].string);
      free((yyvsp[-2].string));
    }
#line 2245 "yacc_sql.cpp"
    break;

  case 40: /* as_option: %empty  */
#line 459 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2253 "yacc_sql.cpp"
    break;

  case 41: /* as_option: AS  */
#line 463 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2261 "yacc_sql.cpp"
    break;

  case 42: /* attr_def_list: %empty  */
#line 469 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2269 "yacc_sql.cpp"
    break;

  case 43: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 473 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2283 "yacc_sql.cpp"
    break;

  case 44: /* attr_def: ID type LBRACE number RBRACE isnull  */
#line 486 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->isnull = (yyvsp[0].boolean);
      free((yyvsp[-5].string));
    }
#line 2296 "yacc_sql.cpp"
    break;

  case 45: /* attr_def: ID type isnull  */
#line 495 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->isnull = (yyvsp[0].boolean);
      free((yyvsp[-2].string));
    }
#line 2309 "yacc_sql.cpp"
    break;

  case 46: /* isnull: %empty  */
#line 507 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2317 "yacc_sql.cpp"
    break;

  case 47: /* isnull: NULL_KY  */
#line 511 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2325 "yacc_sql.cpp"
    break;

  case 48: /* isnull: NOT NULL_KY  */
#line 515 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2333 "yacc_sql.cpp"
    break;

  case 49: /* number: NUMBER  */
#line 521 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2339 "yacc_sql.cpp"
    break;

  case 50: /* type: INT_T  */
#line 524 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::INTS); }
#line 2345 "yacc_sql.cpp"
    break;

  case 51: /* type: STRING_T  */
#line 525 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::CHARS); }
#line 2351 "yacc_sql.cpp"
    break;

  case 52: /* type: FLOAT_T  */
#line 526 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::FLOATS); }
#line 2357 "yacc_sql.cpp"
    break;

  case 53: /* type: VECTOR_T  */
#line 527 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::VECTORS); }
#line 2363 "yacc_sql.cpp"
    break;

  case 54: /* type: DATE_T  */
#line 528 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::DATES); }
#line 2369 "yacc_sql.cpp"
    break;

  case 55: /* type: TEXT_T  */
#line 529 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::TEXTS); }
#line 2375 "yacc_sql.cpp"
    break;

  case 56: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 533 "yacc_sql.y"
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
#line 2392 "yacc_sql.cpp"
    break;

  case 57: /* value_list: %empty  */
#line 549 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2400 "yacc_sql.cpp"
    break;

  case 58: /* value_list: COMMA value value_list  */
#line 552 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2414 "yacc_sql.cpp"
    break;

  case 59: /* value: NUMBER  */
#line 563 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2423 "yacc_sql.cpp"
    break;

  case 60: /* value: FLOAT  */
#line 567 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2432 "yacc_sql.cpp"
    break;

  case 61: /* value: SSS  */
#line 571 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2443 "yacc_sql.cpp"
    break;

  case 62: /* value: VECTOR_LIST  */
#line 577 "yacc_sql.y"
                 {
      char *tmp = common::substr((yyvsp[0].string),0,strlen((yyvsp[0].string))-1);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2454 "yacc_sql.cpp"
    break;

  case 63: /* value: NULL_KY  */
#line 583 "yacc_sql.y"
              {
      (yyval.value) = new Value(NULL_VALUE, 1);
    }
#line 2462 "yacc_sql.cpp"
    break;

  case 64: /* storage_format: %empty  */
#line 589 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 2470 "yacc_sql.cpp"
    break;

  case 65: /* storage_format: STORAGE FORMAT EQ ID  */
#line 593 "yacc_sql.y"
    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2478 "yacc_sql.cpp"
    break;

  case 66: /* delete_stmt: DELETE FROM ID where  */
#line 600 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2492 "yacc_sql.cpp"
    break;

  case 67: /* update_stmt: UPDATE ID SET set_clause_list where  */
#line 612 "yacc_sql.y"
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
#line 2522 "yacc_sql.cpp"
    break;

  case 68: /* set_clause_list: set_clause  */
#line 642 "yacc_sql.y"
    {
        (yyval.set_clause_list) = new std::vector<UpdateKV>();
        (yyval.set_clause_list)->push_back(*(yyvsp[0].set_clause));
        delete (yyvsp[0].set_clause);  // 确保 $1 是 new 出来的对象
    }
#line 2532 "yacc_sql.cpp"
    break;

  case 69: /* set_clause_list: set_clause_list COMMA set_clause  */
#line 648 "yacc_sql.y"
    {
        (yyvsp[-2].set_clause_list)->push_back(*(yyvsp[0].set_clause));
        (yyval.set_clause_list) = (yyvsp[-2].set_clause_list);
        delete (yyvsp[0].set_clause);  // 确保 $3 是 new 出来的对象
    }
#line 2542 "yacc_sql.cpp"
    break;

  case 70: /* set_clause: ID EQ value  */
#line 658 "yacc_sql.y"
    {
        (yyval.set_clause) = new UpdateKV();
        (yyval.set_clause)->attr_name = strdup((yyvsp[-2].string));  // 使用 strdup 复制字符串，避免释放后使用问题
        (yyval.set_clause)->value = *(yyvsp[0].value);
        free((yyvsp[-2].string));  // 确保在拷贝完成后再释放
    }
#line 2553 "yacc_sql.cpp"
    break;

  case 71: /* set_clause: ID EQ SUB_QUERY  */
#line 665 "yacc_sql.y"
    {
      (yyval.set_clause) = new UpdateKV();
      (yyval.set_clause)->is_subquery = true;
      (yyval.set_clause)->attr_name = strdup((yyvsp[-2].string));
      (yyval.set_clause)->subquery = strdup((yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2566 "yacc_sql.cpp"
    break;

  case 72: /* select_stmt: SELECT expression_list  */
#line 678 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[0].expression_list));
        delete (yyvsp[0].expression_list);
      }
    }
#line 2578 "yacc_sql.cpp"
    break;

  case 73: /* select_stmt: SELECT expression_list FROM ID rel_list join_list where group_by having order_by  */
#line 686 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-8].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[-8].expression_list));
        delete (yyvsp[-8].expression_list);
      }
      if ((yyvsp[-5].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-5].relation_list));
        delete (yyvsp[-5].relation_list);
      }
      (yyval.sql_node)->selection.relations.push_back((yyvsp[-6].string));
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      if ((yyvsp[-3].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-3].condition_list));
        delete (yyvsp[-3].condition_list);
      }
      free((yyvsp[-6].string));
      
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
#line 2620 "yacc_sql.cpp"
    break;

  case 74: /* select_stmt: SELECT expression_list FROM ID rel_list join_list where group_by having vec_order_by  */
#line 724 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-8].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[-8].expression_list));
        delete (yyvsp[-8].expression_list);
      }
      if ((yyvsp[-5].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-5].relation_list));
        delete (yyvsp[-5].relation_list);
      }
      (yyval.sql_node)->selection.relations.push_back((yyvsp[-6].string));
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      if ((yyvsp[-3].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-3].condition_list));
        delete (yyvsp[-3].condition_list);
      }
      free((yyvsp[-6].string));
      
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
#line 2662 "yacc_sql.cpp"
    break;

  case 75: /* calc_stmt: CALC expression_list  */
#line 764 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2672 "yacc_sql.cpp"
    break;

  case 76: /* expression_list: expression  */
#line 772 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2681 "yacc_sql.cpp"
    break;

  case 77: /* expression_list: expression COMMA expression_list  */
#line 777 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace((yyval.expression_list)->begin(), (yyvsp[-2].expression));
    }
#line 2694 "yacc_sql.cpp"
    break;

  case 78: /* expression: LBRACE expression RBRACE  */
#line 787 "yacc_sql.y"
                             {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2703 "yacc_sql.cpp"
    break;

  case 79: /* expression: expression '+' expression  */
#line 791 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2711 "yacc_sql.cpp"
    break;

  case 80: /* expression: expression '-' expression  */
#line 794 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2719 "yacc_sql.cpp"
    break;

  case 81: /* expression: expression '*' expression  */
#line 797 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2727 "yacc_sql.cpp"
    break;

  case 82: /* expression: expression '/' expression  */
#line 800 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2735 "yacc_sql.cpp"
    break;

  case 83: /* expression: value  */
#line 803 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2745 "yacc_sql.cpp"
    break;

  case 84: /* expression: rel_attr  */
#line 808 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2756 "yacc_sql.cpp"
    break;

  case 85: /* expression: '*'  */
#line 814 "yacc_sql.y"
          {
      (yyval.expression) = new StarExpr();
    }
#line 2764 "yacc_sql.cpp"
    break;

  case 86: /* expression: '-' expression  */
#line 817 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2772 "yacc_sql.cpp"
    break;

  case 87: /* expression: aggr_expr  */
#line 820 "yacc_sql.y"
                {
      (yyval.expression) = (yyvsp[0].expression);
    }
#line 2780 "yacc_sql.cpp"
    break;

  case 88: /* expression: func_op LBRACE expression_list RBRACE  */
#line 823 "yacc_sql.y"
                                            {
      (yyval.expression) = new FunctionExpr((FuncOp)(yyvsp[-3].func),std::move(*(yyvsp[-1].expression_list)));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[-1].expression_list);
    }
#line 2790 "yacc_sql.cpp"
    break;

  case 89: /* expression: func_op LBRACE RBRACE  */
#line 828 "yacc_sql.y"
                            {
      (yyval.expression) = new FunctionExpr((FuncOp)(yyvsp[-2].func),std::vector<std::unique_ptr<Expression>>());
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2799 "yacc_sql.cpp"
    break;

  case 90: /* simple_expression: value  */
#line 834 "yacc_sql.y"
          {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2809 "yacc_sql.cpp"
    break;

  case 91: /* simple_expression: rel_attr  */
#line 839 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2820 "yacc_sql.cpp"
    break;

  case 92: /* arith_expr: LBRACE arith_expr RBRACE  */
#line 847 "yacc_sql.y"
                             {
      (yyval.expression) = (yyvsp[-1].expression);
    }
#line 2828 "yacc_sql.cpp"
    break;

  case 93: /* arith_expr: arith_expr '+' LBRACE simple_expression RBRACE  */
#line 850 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2836 "yacc_sql.cpp"
    break;

  case 94: /* arith_expr: arith_expr '-' LBRACE simple_expression RBRACE  */
#line 853 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2844 "yacc_sql.cpp"
    break;

  case 95: /* arith_expr: arith_expr '*' LBRACE simple_expression RBRACE  */
#line 856 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2852 "yacc_sql.cpp"
    break;

  case 96: /* arith_expr: arith_expr '/' LBRACE simple_expression RBRACE  */
#line 859 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2860 "yacc_sql.cpp"
    break;

  case 97: /* arith_expr: simple_expression '+' LBRACE simple_expression RBRACE  */
#line 862 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2868 "yacc_sql.cpp"
    break;

  case 98: /* arith_expr: simple_expression '-' LBRACE simple_expression RBRACE  */
#line 865 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2876 "yacc_sql.cpp"
    break;

  case 99: /* arith_expr: simple_expression '*' LBRACE simple_expression RBRACE  */
#line 868 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2884 "yacc_sql.cpp"
    break;

  case 100: /* arith_expr: simple_expression '/' LBRACE simple_expression RBRACE  */
#line 871 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2892 "yacc_sql.cpp"
    break;

  case 101: /* arith_expr: '-' arith_expr  */
#line 874 "yacc_sql.y"
                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2900 "yacc_sql.cpp"
    break;

  case 102: /* arith_expr: '-' simple_expression  */
#line 877 "yacc_sql.y"
                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2908 "yacc_sql.cpp"
    break;

  case 103: /* arith_expr: arith_expr '+' simple_expression  */
#line 880 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2916 "yacc_sql.cpp"
    break;

  case 104: /* arith_expr: arith_expr '-' simple_expression  */
#line 883 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2924 "yacc_sql.cpp"
    break;

  case 105: /* arith_expr: arith_expr '*' simple_expression  */
#line 886 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2932 "yacc_sql.cpp"
    break;

  case 106: /* arith_expr: arith_expr '/' simple_expression  */
#line 889 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2940 "yacc_sql.cpp"
    break;

  case 107: /* arith_expr: simple_expression '+' arith_expr  */
#line 892 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2948 "yacc_sql.cpp"
    break;

  case 108: /* arith_expr: simple_expression '-' arith_expr  */
#line 895 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2956 "yacc_sql.cpp"
    break;

  case 109: /* arith_expr: simple_expression '*' arith_expr  */
#line 898 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2964 "yacc_sql.cpp"
    break;

  case 110: /* arith_expr: simple_expression '/' arith_expr  */
#line 901 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2972 "yacc_sql.cpp"
    break;

  case 111: /* arith_expr: arith_expr '+' arith_expr  */
#line 904 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2980 "yacc_sql.cpp"
    break;

  case 112: /* arith_expr: arith_expr '-' arith_expr  */
#line 907 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2988 "yacc_sql.cpp"
    break;

  case 113: /* arith_expr: arith_expr '*' arith_expr  */
#line 910 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2996 "yacc_sql.cpp"
    break;

  case 114: /* arith_expr: arith_expr '/' arith_expr  */
#line 913 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3004 "yacc_sql.cpp"
    break;

  case 115: /* arith_expr: simple_expression '+' simple_expression  */
#line 916 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3012 "yacc_sql.cpp"
    break;

  case 116: /* arith_expr: simple_expression '-' simple_expression  */
#line 919 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3020 "yacc_sql.cpp"
    break;

  case 117: /* arith_expr: simple_expression '*' simple_expression  */
#line 922 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3028 "yacc_sql.cpp"
    break;

  case 118: /* arith_expr: simple_expression '/' simple_expression  */
#line 925 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 3036 "yacc_sql.cpp"
    break;

  case 119: /* aggr_expr: SUM LBRACE expression_list RBRACE  */
#line 930 "yacc_sql.y"
                                      {
      (yyval.expression) = create_aggregate_expression("SUM", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 3044 "yacc_sql.cpp"
    break;

  case 120: /* aggr_expr: AVG LBRACE expression_list RBRACE  */
#line 933 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("AVG", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 3052 "yacc_sql.cpp"
    break;

  case 121: /* aggr_expr: MAX LBRACE expression_list RBRACE  */
#line 936 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("MAX", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 3060 "yacc_sql.cpp"
    break;

  case 122: /* aggr_expr: MIN LBRACE expression_list RBRACE  */
#line 939 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("MIN", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 3068 "yacc_sql.cpp"
    break;

  case 123: /* aggr_expr: COUNT LBRACE expression_list RBRACE  */
#line 942 "yacc_sql.y"
                                          {
      (yyval.expression) = create_aggregate_expression("COUNT", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 3076 "yacc_sql.cpp"
    break;

  case 124: /* aggr_expr: SUM LBRACE RBRACE  */
#line 945 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("SUM", empty, sql_string, &(yyloc));
    }
#line 3087 "yacc_sql.cpp"
    break;

  case 125: /* aggr_expr: AVG LBRACE RBRACE  */
#line 951 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("AVG", empty, sql_string, &(yyloc));
    }
#line 3098 "yacc_sql.cpp"
    break;

  case 126: /* aggr_expr: MIN LBRACE RBRACE  */
#line 957 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("MIN", empty, sql_string, &(yyloc));
    }
#line 3109 "yacc_sql.cpp"
    break;

  case 127: /* aggr_expr: MAX LBRACE RBRACE  */
#line 963 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("MAX", empty, sql_string, &(yyloc));
    }
#line 3120 "yacc_sql.cpp"
    break;

  case 128: /* aggr_expr: COUNT LBRACE RBRACE  */
#line 969 "yacc_sql.y"
                          {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("COUNT", empty, sql_string, &(yyloc));
    }
#line 3131 "yacc_sql.cpp"
    break;

  case 129: /* rel_attr: ID  */
#line 978 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 3141 "yacc_sql.cpp"
    break;

  case 130: /* rel_attr: ID DOT ID  */
#line 983 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 3153 "yacc_sql.cpp"
    break;

  case 131: /* rel_list: %empty  */
#line 994 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 3161 "yacc_sql.cpp"
    break;

  case 132: /* rel_list: COMMA ID rel_list  */
#line 997 "yacc_sql.y"
                        {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::string>;
      }

      (yyval.relation_list)->push_back((yyvsp[-1].string));
      free((yyvsp[-1].string));
    }
#line 3176 "yacc_sql.cpp"
    break;

  case 133: /* join_list: %empty  */
#line 1010 "yacc_sql.y"
    {
      (yyval.join_sql_node) = nullptr;
    }
#line 3184 "yacc_sql.cpp"
    break;

  case 134: /* join_list: INNER join_list  */
#line 1013 "yacc_sql.y"
                      {
      (yyval.join_sql_node) = (yyvsp[0].join_sql_node);
    }
#line 3192 "yacc_sql.cpp"
    break;

  case 135: /* join_list: JOIN ID ON condition_list join_list  */
#line 1016 "yacc_sql.y"
                                          {
      (yyval.join_sql_node) = new JoinSqlNode();

      if ((yyvsp[-1].condition_list) != nullptr) {
        (yyval.join_sql_node)->conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }

      (yyval.join_sql_node)->relations.push_back((yyvsp[-3].string));

      free((yyvsp[-3].string));

      if ((yyvsp[0].join_sql_node) != nullptr) {
        (yyval.join_sql_node)->relations.insert((yyval.join_sql_node)->relations.end(), (yyvsp[0].join_sql_node)->relations.begin(), (yyvsp[0].join_sql_node)->relations.end());
        (yyval.join_sql_node)->conditions.insert((yyval.join_sql_node)->conditions.end(), (yyvsp[0].join_sql_node)->conditions.begin(), (yyvsp[0].join_sql_node)->conditions.end());
        delete (yyvsp[0].join_sql_node);
      }
    }
#line 3215 "yacc_sql.cpp"
    break;

  case 136: /* order_by: %empty  */
#line 1036 "yacc_sql.y"
  {
    (yyval.order_by_list) = nullptr;
  }
#line 3223 "yacc_sql.cpp"
    break;

  case 137: /* order_by: ORDER BY rel_attr order_op order_by_list  */
#line 1040 "yacc_sql.y"
  {
    (yyval.order_by_list) = new std::vector<std::pair<RelAttrSqlNode, OrderOp>>;
    (yyval.order_by_list)->emplace_back(std::make_pair(*(yyvsp[-2].rel_attr), (yyvsp[-1].orderOp)));
    delete (yyvsp[-2].rel_attr);
    if ((yyvsp[0].order_by_list) != nullptr) {
      (yyval.order_by_list)->insert((yyval.order_by_list)->end(), (yyvsp[0].order_by_list)->begin(), (yyvsp[0].order_by_list)->end());
    }
  }
#line 3236 "yacc_sql.cpp"
    break;

  case 138: /* vec_order_by: ORDER BY func_op LBRACE rel_attr COMMA value RBRACE LIMIT number  */
#line 1052 "yacc_sql.y"
  {
    (yyval.vec_order_by) = new VecOrderByNode;
    (yyval.vec_order_by)->type = (yyvsp[-7].func);
    (yyval.vec_order_by)->first_attr = *(yyvsp[-5].rel_attr);
    (yyval.vec_order_by)->value = *(yyvsp[-3].value);
    (yyval.vec_order_by)->limit = (yyvsp[0].number); 
  }
#line 3248 "yacc_sql.cpp"
    break;

  case 139: /* order_by_list: %empty  */
#line 1062 "yacc_sql.y"
  {
    (yyval.order_by_list) = nullptr;
  }
#line 3256 "yacc_sql.cpp"
    break;

  case 140: /* order_by_list: COMMA rel_attr order_op order_by_list  */
#line 1066 "yacc_sql.y"
  {
    (yyval.order_by_list) = new std::vector<std::pair<RelAttrSqlNode, OrderOp>>;
    (yyval.order_by_list)->emplace_back(std::make_pair(*(yyvsp[-2].rel_attr), (yyvsp[-1].orderOp)));
    delete (yyvsp[-2].rel_attr);

    if ((yyvsp[0].order_by_list) != nullptr) {
      (yyval.order_by_list)->insert((yyval.order_by_list)->end(), (yyvsp[0].order_by_list)->begin(), (yyvsp[0].order_by_list)->end());
    }
  }
#line 3270 "yacc_sql.cpp"
    break;

  case 141: /* order_op: DESC  */
#line 1078 "yacc_sql.y"
       { (yyval.orderOp) = ORDER_DESC; }
#line 3276 "yacc_sql.cpp"
    break;

  case 142: /* order_op: ASC  */
#line 1079 "yacc_sql.y"
       { (yyval.orderOp) = ORDER_ASC;  }
#line 3282 "yacc_sql.cpp"
    break;

  case 143: /* order_op: %empty  */
#line 1080 "yacc_sql.y"
       { (yyval.orderOp) = ORDER_DEFAULT; }
#line 3288 "yacc_sql.cpp"
    break;

  case 144: /* where: %empty  */
#line 1086 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3296 "yacc_sql.cpp"
    break;

  case 145: /* where: WHERE condition_list  */
#line 1090 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 3304 "yacc_sql.cpp"
    break;

  case 146: /* condition_list: %empty  */
#line 1096 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3312 "yacc_sql.cpp"
    break;

  case 147: /* condition_list: condition  */
#line 1099 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 3322 "yacc_sql.cpp"
    break;

  case 148: /* condition_list: condition AND condition_list  */
#line 1104 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3332 "yacc_sql.cpp"
    break;

  case 149: /* condition_list: condition OR condition_list  */
#line 1109 "yacc_sql.y"
                                  {
      (yyvsp[-2].condition)->conjunction="OR";
      (yyvsp[0].condition_list)[0][0].conjunction="OR";
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3344 "yacc_sql.cpp"
    break;

  case 150: /* condition: arith_expr comp_op value  */
#line 1118 "yacc_sql.y"
                              {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].value);
    }
#line 3358 "yacc_sql.cpp"
    break;

  case 151: /* condition: arith_expr comp_op rel_attr  */
#line 1127 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].rel_attr);
    }
#line 3372 "yacc_sql.cpp"
    break;

  case 152: /* condition: value comp_op arith_expr  */
#line 1136 "yacc_sql.y"
                               {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 0;
        (yyval.condition)->left_value = *(yyvsp[-2].value);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].value);
    }
#line 3386 "yacc_sql.cpp"
    break;

  case 153: /* condition: rel_attr comp_op arith_expr  */
#line 1145 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 1;
        (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].rel_attr);
    }
#line 3400 "yacc_sql.cpp"
    break;

  case 154: /* condition: arith_expr comp_op arith_expr  */
#line 1154 "yacc_sql.y"
                                    {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
    }
#line 3413 "yacc_sql.cpp"
    break;

  case 155: /* condition: rel_attr comp_op value  */
#line 1162 "yacc_sql.y"
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
#line 3428 "yacc_sql.cpp"
    break;

  case 156: /* condition: value comp_op value  */
#line 1172 "yacc_sql.y"
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
#line 3443 "yacc_sql.cpp"
    break;

  case 157: /* condition: rel_attr comp_op rel_attr  */
#line 1182 "yacc_sql.y"
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
#line 3458 "yacc_sql.cpp"
    break;

  case 158: /* condition: value comp_op rel_attr  */
#line 1192 "yacc_sql.y"
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
#line 3473 "yacc_sql.cpp"
    break;

  case 159: /* condition: rel_attr comp_op SUB_QUERY  */
#line 1202 "yacc_sql.y"
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
#line 3488 "yacc_sql.cpp"
    break;

  case 160: /* condition: SUB_QUERY comp_op rel_attr  */
#line 1212 "yacc_sql.y"
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
#line 3503 "yacc_sql.cpp"
    break;

  case 161: /* condition: SUB_QUERY comp_op SUB_QUERY  */
#line 1222 "yacc_sql.y"
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
#line 3518 "yacc_sql.cpp"
    break;

  case 162: /* condition: value comp_op LBRACE value value_list RBRACE  */
#line 1232 "yacc_sql.y"
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
#line 3538 "yacc_sql.cpp"
    break;

  case 163: /* condition: rel_attr comp_op LBRACE value value_list RBRACE  */
#line 1247 "yacc_sql.y"
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
#line 3558 "yacc_sql.cpp"
    break;

  case 164: /* condition: SUB_QUERY comp_op LBRACE value value_list RBRACE  */
#line 1262 "yacc_sql.y"
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
#line 3578 "yacc_sql.cpp"
    break;

  case 165: /* condition: LBRACE value value_list RBRACE comp_op value  */
#line 1277 "yacc_sql.y"
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
#line 3598 "yacc_sql.cpp"
    break;

  case 166: /* condition: LBRACE value value_list RBRACE comp_op rel_attr  */
#line 1292 "yacc_sql.y"
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
#line 3618 "yacc_sql.cpp"
    break;

  case 167: /* condition: LBRACE value value_list RBRACE comp_op SUB_QUERY  */
#line 1307 "yacc_sql.y"
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
#line 3638 "yacc_sql.cpp"
    break;

  case 168: /* condition: LBRACE value value_list RBRACE comp_op LBRACE value value_list RBRACE  */
#line 1322 "yacc_sql.y"
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
#line 3663 "yacc_sql.cpp"
    break;

  case 169: /* condition: aggr_expr comp_op value  */
#line 1342 "yacc_sql.y"
                              {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;     
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].value);
    }
#line 3677 "yacc_sql.cpp"
    break;

  case 170: /* condition: aggr_expr comp_op rel_attr  */
#line 1351 "yacc_sql.y"
                                 {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;     
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].rel_attr);
    }
#line 3691 "yacc_sql.cpp"
    break;

  case 171: /* condition: aggr_expr comp_op aggr_expr  */
#line 1360 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 4;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);  
    }
#line 3704 "yacc_sql.cpp"
    break;

  case 172: /* condition: value is_null_choice  */
#line 1368 "yacc_sql.y"
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
#line 3721 "yacc_sql.cpp"
    break;

  case 173: /* condition: rel_attr is_null_choice  */
#line 1380 "yacc_sql.y"
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
#line 3738 "yacc_sql.cpp"
    break;

  case 174: /* is_null_choice: IS NULL_KY  */
#line 1395 "yacc_sql.y"
                 { (yyval.comp) =  OP_ISNULL; }
#line 3744 "yacc_sql.cpp"
    break;

  case 175: /* is_null_choice: IS NOT NULL_KY  */
#line 1396 "yacc_sql.y"
                     { (yyval.comp) = OP_ISNOTNULL; }
#line 3750 "yacc_sql.cpp"
    break;

  case 176: /* comp_op: EQ  */
#line 1400 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3756 "yacc_sql.cpp"
    break;

  case 177: /* comp_op: LT  */
#line 1401 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3762 "yacc_sql.cpp"
    break;

  case 178: /* comp_op: GT  */
#line 1402 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3768 "yacc_sql.cpp"
    break;

  case 179: /* comp_op: LE  */
#line 1403 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3774 "yacc_sql.cpp"
    break;

  case 180: /* comp_op: GE  */
#line 1404 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3780 "yacc_sql.cpp"
    break;

  case 181: /* comp_op: NE  */
#line 1405 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3786 "yacc_sql.cpp"
    break;

  case 182: /* comp_op: LIKE  */
#line 1406 "yacc_sql.y"
           { (yyval.comp) = CLIKE; }
#line 3792 "yacc_sql.cpp"
    break;

  case 183: /* comp_op: NOT LIKE  */
#line 1407 "yacc_sql.y"
               { (yyval.comp) = CNLIKE; }
#line 3798 "yacc_sql.cpp"
    break;

  case 184: /* comp_op: IN  */
#line 1408 "yacc_sql.y"
         { (yyval.comp) = IN_LIST; }
#line 3804 "yacc_sql.cpp"
    break;

  case 185: /* comp_op: NOT IN  */
#line 1409 "yacc_sql.y"
             { (yyval.comp) = NOTIN_LIST; }
#line 3810 "yacc_sql.cpp"
    break;

  case 186: /* comp_op: EXIST  */
#line 1410 "yacc_sql.y"
            { (yyval.comp) = EXIST_LIST; }
#line 3816 "yacc_sql.cpp"
    break;

  case 187: /* comp_op: NOT EXIST  */
#line 1411 "yacc_sql.y"
                { (yyval.comp) = NOTEXIST_LIST; }
#line 3822 "yacc_sql.cpp"
    break;

  case 188: /* func_op: I2_DISTANCE_T  */
#line 1415 "yacc_sql.y"
                    { (yyval.func) = I2_DISTANCE; }
#line 3828 "yacc_sql.cpp"
    break;

  case 189: /* func_op: COSINE_DISTANCE_T  */
#line 1416 "yacc_sql.y"
                        { (yyval.func) = COSINE_DISTANCE; }
#line 3834 "yacc_sql.cpp"
    break;

  case 190: /* func_op: INNER_PRODUCT_T  */
#line 1417 "yacc_sql.y"
                      { (yyval.func) = INNER_PRODUCT; }
#line 3840 "yacc_sql.cpp"
    break;

  case 191: /* group_by: %empty  */
#line 1421 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 3848 "yacc_sql.cpp"
    break;

  case 192: /* group_by: GROUP BY expression_list  */
#line 1425 "yacc_sql.y"
          {
        (yyval.expression_list) = (yyvsp[0].expression_list);
	  }
#line 3856 "yacc_sql.cpp"
    break;

  case 193: /* having: %empty  */
#line 1431 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3864 "yacc_sql.cpp"
    break;

  case 194: /* having: HAVING condition_list  */
#line 1435 "yacc_sql.y"
    {
      (yyval.condition_list) = (yyvsp[0].condition_list);
    }
#line 3872 "yacc_sql.cpp"
    break;

  case 195: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1442 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3886 "yacc_sql.cpp"
    break;

  case 196: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1455 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3895 "yacc_sql.cpp"
    break;

  case 197: /* set_variable_stmt: SET ID EQ value  */
#line 1463 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3907 "yacc_sql.cpp"
    break;


#line 3911 "yacc_sql.cpp"

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

#line 1475 "yacc_sql.y"

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
