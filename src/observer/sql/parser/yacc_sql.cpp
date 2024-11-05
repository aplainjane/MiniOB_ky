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
  YYSYMBOL_SUM = 70,                       /* SUM  */
  YYSYMBOL_AVG = 71,                       /* AVG  */
  YYSYMBOL_COUNT = 72,                     /* COUNT  */
  YYSYMBOL_MAX = 73,                       /* MAX  */
  YYSYMBOL_MIN = 74,                       /* MIN  */
  YYSYMBOL_NUMBER = 75,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 76,                     /* FLOAT  */
  YYSYMBOL_ID = 77,                        /* ID  */
  YYSYMBOL_SSS = 78,                       /* SSS  */
  YYSYMBOL_SUB_QUERY = 79,                 /* SUB_QUERY  */
  YYSYMBOL_VECTOR_LIST = 80,               /* VECTOR_LIST  */
  YYSYMBOL_81_ = 81,                       /* '+'  */
  YYSYMBOL_82_ = 82,                       /* '-'  */
  YYSYMBOL_83_ = 83,                       /* '*'  */
  YYSYMBOL_84_ = 84,                       /* '/'  */
  YYSYMBOL_UMINUS = 85,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 86,                  /* $accept  */
  YYSYMBOL_commands = 87,                  /* commands  */
  YYSYMBOL_command_wrapper = 88,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 89,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 90,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 91,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 92,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 93,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 94,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 95,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 96,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 97,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 98,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 99,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 100,        /* create_table_stmt  */
  YYSYMBOL_as_option = 101,                /* as_option  */
  YYSYMBOL_attr_def_list = 102,            /* attr_def_list  */
  YYSYMBOL_attr_def = 103,                 /* attr_def  */
  YYSYMBOL_isnull = 104,                   /* isnull  */
  YYSYMBOL_number = 105,                   /* number  */
  YYSYMBOL_type = 106,                     /* type  */
  YYSYMBOL_insert_stmt = 107,              /* insert_stmt  */
  YYSYMBOL_value_list = 108,               /* value_list  */
  YYSYMBOL_value = 109,                    /* value  */
  YYSYMBOL_storage_format = 110,           /* storage_format  */
  YYSYMBOL_delete_stmt = 111,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 112,              /* update_stmt  */
  YYSYMBOL_set_clause_list = 113,          /* set_clause_list  */
  YYSYMBOL_set_clause = 114,               /* set_clause  */
  YYSYMBOL_select_stmt = 115,              /* select_stmt  */
  YYSYMBOL_calc_stmt = 116,                /* calc_stmt  */
  YYSYMBOL_expression_list = 117,          /* expression_list  */
  YYSYMBOL_expression = 118,               /* expression  */
  YYSYMBOL_simple_expression = 119,        /* simple_expression  */
  YYSYMBOL_arith_expr = 120,               /* arith_expr  */
  YYSYMBOL_aggr_expr = 121,                /* aggr_expr  */
  YYSYMBOL_rel_attr = 122,                 /* rel_attr  */
  YYSYMBOL_rel_list = 123,                 /* rel_list  */
  YYSYMBOL_join_list = 124,                /* join_list  */
  YYSYMBOL_order_by = 125,                 /* order_by  */
  YYSYMBOL_order_by_list = 126,            /* order_by_list  */
  YYSYMBOL_order_op = 127,                 /* order_op  */
  YYSYMBOL_where = 128,                    /* where  */
  YYSYMBOL_condition_list = 129,           /* condition_list  */
  YYSYMBOL_condition = 130,                /* condition  */
  YYSYMBOL_is_null_choice = 131,           /* is_null_choice  */
  YYSYMBOL_comp_op = 132,                  /* comp_op  */
  YYSYMBOL_func_op = 133,                  /* func_op  */
  YYSYMBOL_group_by = 134,                 /* group_by  */
  YYSYMBOL_having = 135,                   /* having  */
  YYSYMBOL_load_data_stmt = 136,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 137,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 138,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 139             /* opt_semicolon  */
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
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   749

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  195
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  368

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   336


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
       2,     2,    83,    81,     2,    82,     2,    84,     2,     2,
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
      75,    76,    77,    78,    79,    80,    85
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   237,   237,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   268,   274,   279,   285,   291,   297,   303,
     310,   316,   324,   343,   365,   375,   404,   419,   430,   433,
     440,   443,   456,   465,   478,   481,   485,   492,   495,   496,
     497,   498,   499,   500,   503,   520,   523,   534,   538,   542,
     548,   554,   560,   563,   570,   582,   612,   618,   628,   635,
     648,   656,   696,   704,   709,   720,   724,   727,   730,   733,
     736,   741,   747,   750,   753,   756,   761,   767,   772,   780,
     783,   786,   789,   792,   795,   798,   801,   804,   807,   810,
     813,   816,   819,   822,   825,   828,   831,   834,   837,   840,
     843,   846,   849,   852,   855,   858,   863,   866,   869,   872,
     875,   878,   884,   890,   896,   902,   911,   916,   927,   930,
     943,   946,   949,   969,   972,   984,   987,  1000,  1001,  1002,
    1008,  1012,  1018,  1021,  1026,  1031,  1040,  1049,  1058,  1067,
    1076,  1084,  1094,  1104,  1114,  1124,  1134,  1144,  1154,  1169,
    1184,  1199,  1214,  1229,  1244,  1264,  1273,  1282,  1290,  1302,
    1317,  1318,  1322,  1323,  1324,  1325,  1326,  1327,  1328,  1329,
    1330,  1331,  1332,  1333,  1337,  1338,  1339,  1343,  1346,  1353,
    1356,  1363,  1376,  1384,  1394,  1395
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
  "I2_DISTANCE_T", "COSINE_DISTANCE_T", "INNER_PRODUCT_T", "SUM", "AVG",
  "COUNT", "MAX", "MIN", "NUMBER", "FLOAT", "ID", "SSS", "SUB_QUERY",
  "VECTOR_LIST", "'+'", "'-'", "'*'", "'/'", "UMINUS", "$accept",
  "commands", "command_wrapper", "exit_stmt", "help_stmt", "sync_stmt",
  "begin_stmt", "commit_stmt", "rollback_stmt", "drop_table_stmt",
  "show_tables_stmt", "desc_table_stmt", "create_index_stmt",
  "drop_index_stmt", "create_table_stmt", "as_option", "attr_def_list",
  "attr_def", "isnull", "number", "type", "insert_stmt", "value_list",
  "value", "storage_format", "delete_stmt", "update_stmt",
  "set_clause_list", "set_clause", "select_stmt", "calc_stmt",
  "expression_list", "expression", "simple_expression", "arith_expr",
  "aggr_expr", "rel_attr", "rel_list", "join_list", "order_by",
  "order_by_list", "order_op", "where", "condition_list", "condition",
  "is_null_choice", "comp_op", "func_op", "group_by", "having",
  "load_data_stmt", "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-170)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-89)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     689,    66,    32,   442,   442,   -63,    25,  -170,    22,    29,
       6,  -170,  -170,  -170,  -170,  -170,    21,    43,   689,    99,
     105,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,    49,   135,    81,   113,   114,   442,  -170,  -170,  -170,
    -170,   153,   160,   179,   182,   183,  -170,  -170,   143,  -170,
    -170,   442,  -170,  -170,  -170,    83,  -170,  -170,   187,   171,
    -170,  -170,   136,   140,   175,   161,   173,  -170,  -170,  -170,
    -170,   -18,   146,   181,  -170,   190,   -12,   202,   296,   318,
     358,   380,   150,  -170,   442,   442,   442,   442,   442,   420,
     151,   198,   210,   180,   237,   186,   185,  -170,   246,   216,
     204,   211,  -170,  -170,   267,  -170,   268,  -170,   270,  -170,
     276,  -170,   277,  -170,  -170,   -61,   -61,  -170,  -170,  -170,
     279,   281,   284,   464,  -170,   242,     0,  -170,  -170,   274,
     297,   292,  -170,   245,   301,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,   258,   -13,   237,   501,   418,   501,   605,    79,
     665,   418,   605,  -170,    13,    98,   180,  -170,   327,  -170,
    -170,  -170,  -170,  -170,  -170,    -5,   185,   314,   321,   273,
     281,   -13,   278,   210,   320,   501,    50,    -2,  -170,    10,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,   -17,
    -170,    45,    52,   -32,  -170,   510,   523,   532,   540,   549,
     562,   571,   599,   608,   501,   -44,  -170,   451,   464,   464,
    -170,  -170,  -170,   280,   283,   294,  -170,  -170,   292,   -11,
     282,   281,  -170,  -170,   309,   354,   237,   359,   360,  -170,
    -170,  -170,  -170,   237,  -170,  -170,   340,  -170,   501,   116,
     250,   330,   501,    45,    52,   501,    45,    52,   501,  -170,
    -170,   501,  -170,  -170,   501,    45,    52,   501,    45,    52,
     501,  -170,  -170,   501,  -170,  -170,   116,   250,   330,  -170,
    -170,  -170,   501,  -170,   116,   250,   330,  -170,  -170,  -170,
    -170,   361,  -170,  -170,   348,   246,  -170,   281,   381,   464,
     373,   364,   320,  -170,   418,   320,  -170,    50,    34,   102,
     111,   164,   184,   226,   264,   326,    50,    -4,   345,  -170,
     393,  -170,   -13,   442,   464,   409,  -170,   621,   395,   396,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,   397,  -170,
     344,  -170,  -170,  -170,  -170,   419,  -170,   237,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,   347,   320,   156,   399,  -170,
    -170,   415,  -170,   347,  -170,   156,   415,  -170
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,    24,    23,     0,     0,     0,     0,
     194,    22,    21,    14,    15,    16,    17,     9,    10,    11,
      12,    13,     8,     5,     7,     6,     4,     3,    18,    19,
      20,     0,     0,     0,     0,     0,     0,    61,   184,   185,
     186,     0,     0,     0,     0,     0,    57,    58,   126,    59,
      60,     0,    82,    80,    72,    73,    84,    81,     0,    70,
      31,    30,     0,     0,     0,     0,     0,   192,     1,   195,
       2,    38,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,   140,     0,     0,     0,     0,    39,     0,     0,
       0,     0,    75,   121,     0,   122,     0,   125,     0,   124,
       0,   123,     0,   127,    74,    76,    77,    78,    79,    86,
       0,   128,     0,   142,    64,     0,   140,    66,   193,     0,
       0,    40,    37,     0,     0,    34,   116,   117,   120,   118,
     119,    85,     0,   130,     0,     0,     0,     0,    87,     0,
       0,     0,    88,   141,   143,     0,     0,    65,     0,    48,
      49,    52,    53,    50,    51,    44,     0,     0,     0,     0,
     128,   130,     0,   140,    55,     0,    87,     0,    88,     0,
     178,   180,   182,   172,   173,   174,   175,   176,   177,     0,
      87,    99,    98,     0,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,     0,   142,   142,
      69,    68,    67,     0,     0,     0,    45,    43,    40,    62,
       0,   128,   129,   131,     0,   187,     0,     0,     0,    89,
     179,   181,   183,     0,   157,   156,     0,   170,     0,   152,
     148,   154,     0,   112,   104,     0,   113,   105,     0,   114,
     106,     0,   115,   107,     0,   100,   108,     0,   101,   109,
       0,   102,   110,     0,   103,   111,   146,   150,   147,   165,
     167,   166,     0,   155,   151,   149,   153,   144,   145,   191,
      47,     0,    46,    41,     0,     0,    35,   128,     0,   142,
       0,   189,    55,    54,     0,    55,   171,    87,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    44,     0,    36,
       0,    32,   130,     0,   142,   133,    56,     0,     0,     0,
      94,    95,    96,    97,    90,    91,    92,    93,     0,    42,
       0,    33,   132,   188,   190,     0,    71,     0,   163,   161,
     162,   160,   158,   159,    63,     0,    55,   139,     0,   138,
     137,   135,   164,     0,   134,   139,   135,   136
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,  -170,   426,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,   217,   231,   269,   144,  -170,
    -170,  -170,  -148,    15,  -170,  -170,  -170,  -170,   299,  -106,
    -170,    33,   157,    31,   -68,  -118,    -3,  -164,  -169,  -170,
     100,   103,  -129,  -168,  -170,   305,  -152,  -170,  -170,  -170,
    -170,  -170,  -170,  -170
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   108,   177,   141,   227,   291,
     175,    33,   237,   200,   296,    34,    35,   136,   137,    36,
      37,    64,    65,   159,   187,    66,   188,   153,   183,   346,
     364,   361,   134,   163,   164,   204,   199,    68,   301,   325,
      38,    39,    40,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    67,   142,   -38,   106,   243,   205,   167,   214,   215,
     217,   112,   233,    47,    70,   161,   232,   224,    63,    63,
     246,   239,    97,    98,   166,   247,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    71,    60,    69,   238,   294,
     133,    44,   107,    67,    45,   181,   182,   225,   225,   107,
     287,   288,   226,   226,   235,   218,   219,   330,    67,    72,
      58,    63,   244,   240,   241,   160,   242,   298,    73,    95,
      96,    97,    98,   -55,   236,    41,    63,    42,    43,   210,
     211,   212,   213,    74,    67,    67,    67,    67,    67,   202,
      76,    67,    67,    67,    67,    67,    67,   280,    75,    78,
     161,   161,    63,    63,    63,    63,    63,    94,    79,    63,
      63,    63,    63,    63,    63,   206,   207,   208,   209,   138,
     114,   116,   118,   120,   122,   331,    81,   124,   208,   209,
     162,   322,   130,   320,   332,   212,   213,   250,   254,   257,
     260,   263,   266,   269,   272,   275,   277,    82,   158,   285,
     160,   160,   327,   342,   326,    47,   344,   328,    83,   329,
     206,   207,   208,   209,    95,    96,    97,    98,   338,   184,
     186,   359,   360,    56,    57,    87,    59,   220,    60,    92,
     221,   161,    88,   206,   207,   208,   209,   333,   201,   319,
      84,    85,   206,   207,   208,   209,   245,   -87,   -87,   -87,
     -87,    89,   251,    86,    90,    91,   161,   334,   358,    99,
     100,   278,   281,   101,   286,   162,   162,   102,    93,   103,
     249,   105,   104,   109,    46,   113,   110,   123,   131,   276,
     279,   160,   284,   158,   158,   111,   132,   253,   256,   259,
     262,   265,   268,   271,   274,   206,   207,   208,   209,   335,
     133,   302,   125,   126,   127,   128,   160,   135,   305,    47,
       4,   143,   140,   307,   139,   206,   207,   208,   209,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,   144,    60,   308,    61,    62,   309,   336,   145,   310,
     146,   147,   311,   148,    47,   312,   162,   316,   313,   149,
     150,   314,   151,   165,   315,   152,   154,   206,   207,   208,
     209,   168,    56,    57,   158,    59,   176,    60,    46,   115,
      67,   162,   178,   179,   350,   169,   170,   171,   172,   173,
     174,   210,   211,   212,   213,   180,   223,   229,    63,   158,
      46,   117,   349,   230,   236,   206,   207,   208,   209,   337,
     231,   292,   357,    47,   299,   234,   343,   289,   290,   297,
     365,   300,   356,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    47,    60,   323,    61,    62,
      46,   119,   303,   304,   317,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   306,    60,   318,
      61,    62,    46,   121,   321,   324,   340,   206,   207,   208,
     209,   -88,   -88,   -88,   -88,    47,   341,   345,   351,   352,
     353,   354,   362,   355,    58,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    47,    60,   363,
      61,    62,    46,   129,    77,   228,   295,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,   293,
      60,   339,    61,    62,    46,   222,   367,   216,   366,     0,
     189,   190,   191,   282,   192,     0,     0,    47,     0,   193,
     194,   195,   196,   197,   198,     0,   155,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    47,
      60,     0,    61,    62,     0,     0,     0,     0,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    47,    60,   185,    61,    62,    56,    57,    58,    59,
     283,    60,   248,   157,    51,    52,    53,    54,    55,    56,
      57,    58,    59,   156,    60,   252,   157,     0,     0,     0,
       0,     0,     0,     0,   255,     0,     0,     0,    47,     0,
       0,     0,   258,     0,     0,     0,     0,    47,     0,     0,
       0,   261,     0,     0,     0,     0,    56,    57,    58,    59,
      47,    60,     0,   157,   264,    56,    57,    58,    59,    47,
      60,     0,   157,   267,     0,     0,     0,    47,    56,    57,
      58,    59,     0,    60,     0,   157,    47,    56,    57,    58,
      59,     0,    60,     0,   157,    56,    57,    58,    59,    47,
      60,   270,   157,     0,    56,    57,    58,    59,    47,    60,
     273,   157,     0,     0,     0,     0,     0,    56,    57,    58,
      59,     0,    60,   347,   157,     0,    56,    57,    58,    59,
       0,    60,     0,   157,     0,     0,    47,   189,   190,   191,
     203,   192,     0,     0,     0,    47,   193,   194,   195,   196,
     197,   198,     0,     0,    56,    57,    58,    59,    47,    60,
       0,   157,     0,    56,    57,    58,    59,     0,    60,     0,
     157,     0,     0,     0,     1,     2,    56,    57,    58,    59,
     348,    60,     3,     4,     0,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    11,    12,    13,   189,   190,   191,
       0,   192,     0,    14,    15,     0,   193,   194,   195,   196,
     197,   198,     0,    16,     0,    17,     0,     0,    18,     0,
       0,     0,     0,     0,     0,     0,   210,   211,   212,   213
};

static const yytype_int16 yycheck[] =
{
       3,     4,   108,    14,    22,    22,   158,   136,   160,   161,
     162,    23,   181,    57,    77,   133,   180,    22,     3,     4,
      52,    23,    83,    84,    24,    57,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    10,    80,     4,   186,    50,
      40,     9,    60,    46,    12,    58,    59,    52,    52,    60,
     218,   219,    57,    57,   183,    42,    43,    23,    61,    37,
      77,    46,    79,    53,    54,   133,    56,   231,    39,    81,
      82,    83,    84,    23,    24,     9,    61,    11,    12,    81,
      82,    83,    84,    77,    87,    88,    89,    90,    91,   157,
      47,    94,    95,    96,    97,    98,    99,   215,    77,     0,
     218,   219,    87,    88,    89,    90,    91,    24,     3,    94,
      95,    96,    97,    98,    99,    81,    82,    83,    84,   104,
      87,    88,    89,    90,    91,    23,    77,    94,    83,    84,
     133,   299,    99,   297,    23,    83,    84,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,    12,   133,   217,
     218,   219,   304,   322,   302,    57,   324,   305,    77,   307,
      81,    82,    83,    84,    81,    82,    83,    84,   316,   154,
     155,    15,    16,    75,    76,    22,    78,    79,    80,    36,
     165,   299,    22,    81,    82,    83,    84,    23,   157,   295,
      77,    77,    81,    82,    83,    84,   199,    81,    82,    83,
      84,    22,   205,    46,    22,    22,   324,    23,   356,    22,
      39,   214,   215,    77,   217,   218,   219,    77,    61,    44,
     205,    48,    61,    77,    22,    23,    45,    77,    77,   214,
     215,   299,   217,   218,   219,    45,    38,   206,   207,   208,
     209,   210,   211,   212,   213,    81,    82,    83,    84,    23,
      40,   236,    95,    96,    97,    98,   324,    77,   243,    57,
      14,    45,    77,   248,    78,    81,    82,    83,    84,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    77,    80,   252,    82,    83,   255,    23,    77,   258,
      23,    23,   261,    23,    57,   264,   299,   282,   267,    23,
      23,   270,    23,    61,   273,    24,    22,    81,    82,    83,
      84,    37,    75,    76,   299,    78,    24,    80,    22,    23,
     323,   324,    77,    22,   327,    28,    29,    30,    31,    32,
      33,    81,    82,    83,    84,    77,     9,    23,   323,   324,
      22,    23,   327,    22,    24,    81,    82,    83,    84,    23,
      77,    57,   355,    57,    45,    77,   323,    77,    75,    77,
     363,     7,   347,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    57,    80,     4,    82,    83,
      22,    23,    23,    23,    23,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    57,    80,    51,
      82,    83,    22,    23,    23,    41,    61,    81,    82,    83,
      84,    81,    82,    83,    84,    57,    23,     8,    23,    23,
      23,    77,    23,     4,    77,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    57,    80,    24,
      82,    83,    22,    23,    18,   176,   229,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,   228,
      80,   317,    82,    83,    22,   166,   366,   162,   365,    -1,
      52,    53,    54,    22,    56,    -1,    -1,    57,    -1,    61,
      62,    63,    64,    65,    66,    -1,    22,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    57,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    57,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    57,    80,    22,    82,    83,    75,    76,    77,    78,
      79,    80,    22,    82,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    22,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      57,    80,    -1,    82,    22,    75,    76,    77,    78,    57,
      80,    -1,    82,    22,    -1,    -1,    -1,    57,    75,    76,
      77,    78,    -1,    80,    -1,    82,    57,    75,    76,    77,
      78,    -1,    80,    -1,    82,    75,    76,    77,    78,    57,
      80,    22,    82,    -1,    75,    76,    77,    78,    57,    80,
      22,    82,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    -1,    80,    22,    82,    -1,    75,    76,    77,    78,
      -1,    80,    -1,    82,    -1,    -1,    57,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    57,    61,    62,    63,    64,
      65,    66,    -1,    -1,    75,    76,    77,    78,    57,    80,
      -1,    82,    -1,    75,    76,    77,    78,    -1,    80,    -1,
      82,    -1,    -1,    -1,     5,     6,    75,    76,    77,    78,
      79,    80,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    25,    26,    27,    52,    53,    54,
      -1,    56,    -1,    34,    35,    -1,    61,    62,    63,    64,
      65,    66,    -1,    44,    -1,    46,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    13,    14,    16,    17,    18,    19,    20,
      21,    25,    26,    27,    34,    35,    44,    46,    49,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   107,   111,   112,   115,   116,   136,   137,
     138,     9,    11,    12,     9,    12,    22,    57,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      80,    82,    83,   109,   117,   118,   121,   122,   133,   117,
      77,    10,    37,    39,    77,    77,    47,    88,     0,     3,
     139,    77,    12,    77,    77,    77,   118,    22,    22,    22,
      22,    22,    36,   118,    24,    81,    82,    83,    84,    22,
      39,    77,    77,    44,    61,    48,    22,    60,   101,    77,
      45,    45,    23,    23,   117,    23,   117,    23,   117,    23,
     117,    23,   117,    77,   117,   118,   118,   118,   118,    23,
     117,    77,    38,    40,   128,    77,   113,   114,   109,    78,
      77,   103,   115,    45,    77,    77,    23,    23,    23,    23,
      23,    23,    24,   123,    22,    22,    79,    82,   109,   119,
     120,   121,   122,   129,   130,    61,    24,   128,    37,    28,
      29,    30,    31,    32,    33,   106,    24,   102,    77,    22,
      77,    58,    59,   124,   109,    22,   109,   120,   122,    52,
      53,    54,    56,    61,    62,    63,    64,    65,    66,   132,
     109,   119,   120,    55,   131,   132,    81,    82,    83,    84,
      81,    82,    83,    84,   132,   132,   131,   132,    42,    43,
      79,   109,   114,     9,    22,    52,    57,   104,   103,    23,
      22,    77,   123,   124,    77,   128,    24,   108,   108,    23,
      53,    54,    56,    22,    79,   122,    52,    57,    22,   109,
     120,   122,    22,   119,   120,    22,   119,   120,    22,   119,
     120,    22,   119,   120,    22,   119,   120,    22,   119,   120,
      22,   119,   120,    22,   119,   120,   109,   120,   122,   109,
     121,   122,    22,    79,   109,   120,   122,   129,   129,    77,
      75,   105,    57,   102,    50,   101,   110,    77,   123,    45,
       7,   134,   109,    23,    23,   109,    57,   109,   119,   119,
     119,   119,   119,   119,   119,   119,   109,    23,    51,   115,
     123,    23,   129,     4,    41,   135,   108,   132,   108,   108,
      23,    23,    23,    23,    23,    23,    23,    23,   108,   104,
      61,    23,   124,   117,   129,     8,   125,    22,    79,   109,
     122,    23,    23,    23,    77,     4,   109,   122,   108,    15,
      16,   127,    23,    24,   126,   122,   127,   126
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    98,    99,   100,   100,   100,   101,   101,
     102,   102,   103,   103,   104,   104,   104,   105,   106,   106,
     106,   106,   106,   106,   107,   108,   108,   109,   109,   109,
     109,   109,   110,   110,   111,   112,   113,   113,   114,   114,
     115,   115,   116,   117,   117,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   119,   119,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   122,   122,   123,   123,
     124,   124,   124,   125,   125,   126,   126,   127,   127,   127,
     128,   128,   129,   129,   129,   129,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     131,   131,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   133,   133,   133,   134,   134,   135,
     135,   136,   137,   138,   139,   139
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     9,    10,     5,     8,     9,     5,     0,     1,
       0,     3,     6,     3,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     8,     0,     3,     1,     1,     1,
       1,     1,     0,     4,     4,     5,     1,     3,     3,     3,
       2,    10,     2,     1,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     2,     1,     4,     3,     1,     1,     3,
       5,     5,     5,     5,     5,     5,     5,     5,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     4,     4,     4,
       4,     3,     3,     3,     3,     3,     1,     3,     0,     3,
       0,     2,     5,     0,     5,     0,     4,     1,     1,     0,
       0,     2,     0,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     6,     6,
       6,     6,     6,     6,     9,     3,     3,     3,     2,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     0,     3,     0,
       2,     7,     2,     4,     0,     1
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
#line 238 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1995 "yacc_sql.cpp"
    break;

  case 23: /* exit_stmt: EXIT  */
#line 268 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 2004 "yacc_sql.cpp"
    break;

  case 24: /* help_stmt: HELP  */
#line 274 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 2012 "yacc_sql.cpp"
    break;

  case 25: /* sync_stmt: SYNC  */
#line 279 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 2020 "yacc_sql.cpp"
    break;

  case 26: /* begin_stmt: TRX_BEGIN  */
#line 285 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 2028 "yacc_sql.cpp"
    break;

  case 27: /* commit_stmt: TRX_COMMIT  */
#line 291 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 2036 "yacc_sql.cpp"
    break;

  case 28: /* rollback_stmt: TRX_ROLLBACK  */
#line 297 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 2044 "yacc_sql.cpp"
    break;

  case 29: /* drop_table_stmt: DROP TABLE ID  */
#line 303 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2054 "yacc_sql.cpp"
    break;

  case 30: /* show_tables_stmt: SHOW TABLES  */
#line 310 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 2062 "yacc_sql.cpp"
    break;

  case 31: /* desc_table_stmt: DESC ID  */
#line 316 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2072 "yacc_sql.cpp"
    break;

  case 32: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID rel_list RBRACE  */
#line 325 "yacc_sql.y"
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
#line 2095 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID rel_list RBRACE  */
#line 344 "yacc_sql.y"
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
#line 2118 "yacc_sql.cpp"
    break;

  case 34: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 366 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2130 "yacc_sql.cpp"
    break;

  case 35: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format  */
#line 376 "yacc_sql.y"
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
#line 2163 "yacc_sql.cpp"
    break;

  case 36: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE as_option select_stmt  */
#line 405 "yacc_sql.y"
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
#line 2182 "yacc_sql.cpp"
    break;

  case 37: /* create_table_stmt: CREATE TABLE ID as_option select_stmt  */
#line 420 "yacc_sql.y"
    {
      (yyval.sql_node) = (yyvsp[0].sql_node);
      (yyval.sql_node)->flag = SCF_CREATE_TABLE;
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-2].string);
      free((yyvsp[-2].string));
    }
#line 2194 "yacc_sql.cpp"
    break;

  case 38: /* as_option: %empty  */
#line 430 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2202 "yacc_sql.cpp"
    break;

  case 39: /* as_option: AS  */
#line 434 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2210 "yacc_sql.cpp"
    break;

  case 40: /* attr_def_list: %empty  */
#line 440 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2218 "yacc_sql.cpp"
    break;

  case 41: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 444 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2232 "yacc_sql.cpp"
    break;

  case 42: /* attr_def: ID type LBRACE number RBRACE isnull  */
#line 457 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->isnull = (yyvsp[0].boolean);
      free((yyvsp[-5].string));
    }
#line 2245 "yacc_sql.cpp"
    break;

  case 43: /* attr_def: ID type isnull  */
#line 466 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->isnull = (yyvsp[0].boolean);
      free((yyvsp[-2].string));
    }
#line 2258 "yacc_sql.cpp"
    break;

  case 44: /* isnull: %empty  */
#line 478 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2266 "yacc_sql.cpp"
    break;

  case 45: /* isnull: NULL_KY  */
#line 482 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2274 "yacc_sql.cpp"
    break;

  case 46: /* isnull: NOT NULL_KY  */
#line 486 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2282 "yacc_sql.cpp"
    break;

  case 47: /* number: NUMBER  */
#line 492 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2288 "yacc_sql.cpp"
    break;

  case 48: /* type: INT_T  */
#line 495 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::INTS); }
#line 2294 "yacc_sql.cpp"
    break;

  case 49: /* type: STRING_T  */
#line 496 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::CHARS); }
#line 2300 "yacc_sql.cpp"
    break;

  case 50: /* type: FLOAT_T  */
#line 497 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::FLOATS); }
#line 2306 "yacc_sql.cpp"
    break;

  case 51: /* type: VECTOR_T  */
#line 498 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::VECTORS); }
#line 2312 "yacc_sql.cpp"
    break;

  case 52: /* type: DATE_T  */
#line 499 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::DATES); }
#line 2318 "yacc_sql.cpp"
    break;

  case 53: /* type: TEXT_T  */
#line 500 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::TEXTS); }
#line 2324 "yacc_sql.cpp"
    break;

  case 54: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 504 "yacc_sql.y"
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
#line 2341 "yacc_sql.cpp"
    break;

  case 55: /* value_list: %empty  */
#line 520 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2349 "yacc_sql.cpp"
    break;

  case 56: /* value_list: COMMA value value_list  */
#line 523 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2363 "yacc_sql.cpp"
    break;

  case 57: /* value: NUMBER  */
#line 534 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2372 "yacc_sql.cpp"
    break;

  case 58: /* value: FLOAT  */
#line 538 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2381 "yacc_sql.cpp"
    break;

  case 59: /* value: SSS  */
#line 542 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2392 "yacc_sql.cpp"
    break;

  case 60: /* value: VECTOR_LIST  */
#line 548 "yacc_sql.y"
                 {
      char *tmp = common::substr((yyvsp[0].string),0,strlen((yyvsp[0].string))-1);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2403 "yacc_sql.cpp"
    break;

  case 61: /* value: NULL_KY  */
#line 554 "yacc_sql.y"
              {
      (yyval.value) = new Value(NULL_VALUE, 1);
    }
#line 2411 "yacc_sql.cpp"
    break;

  case 62: /* storage_format: %empty  */
#line 560 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 2419 "yacc_sql.cpp"
    break;

  case 63: /* storage_format: STORAGE FORMAT EQ ID  */
#line 564 "yacc_sql.y"
    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2427 "yacc_sql.cpp"
    break;

  case 64: /* delete_stmt: DELETE FROM ID where  */
#line 571 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2441 "yacc_sql.cpp"
    break;

  case 65: /* update_stmt: UPDATE ID SET set_clause_list where  */
#line 583 "yacc_sql.y"
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
#line 2471 "yacc_sql.cpp"
    break;

  case 66: /* set_clause_list: set_clause  */
#line 613 "yacc_sql.y"
    {
        (yyval.set_clause_list) = new std::vector<UpdateKV>();
        (yyval.set_clause_list)->push_back(*(yyvsp[0].set_clause));
        delete (yyvsp[0].set_clause);  // 确保 $1 是 new 出来的对象
    }
#line 2481 "yacc_sql.cpp"
    break;

  case 67: /* set_clause_list: set_clause_list COMMA set_clause  */
#line 619 "yacc_sql.y"
    {
        (yyvsp[-2].set_clause_list)->push_back(*(yyvsp[0].set_clause));
        (yyval.set_clause_list) = (yyvsp[-2].set_clause_list);
        delete (yyvsp[0].set_clause);  // 确保 $3 是 new 出来的对象
    }
#line 2491 "yacc_sql.cpp"
    break;

  case 68: /* set_clause: ID EQ value  */
#line 629 "yacc_sql.y"
    {
        (yyval.set_clause) = new UpdateKV();
        (yyval.set_clause)->attr_name = strdup((yyvsp[-2].string));  // 使用 strdup 复制字符串，避免释放后使用问题
        (yyval.set_clause)->value = *(yyvsp[0].value);
        free((yyvsp[-2].string));  // 确保在拷贝完成后再释放
    }
#line 2502 "yacc_sql.cpp"
    break;

  case 69: /* set_clause: ID EQ SUB_QUERY  */
#line 636 "yacc_sql.y"
    {
      (yyval.set_clause) = new UpdateKV();
      (yyval.set_clause)->is_subquery = true;
      (yyval.set_clause)->attr_name = strdup((yyvsp[-2].string));
      (yyval.set_clause)->subquery = strdup((yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2515 "yacc_sql.cpp"
    break;

  case 70: /* select_stmt: SELECT expression_list  */
#line 649 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[0].expression_list));
        delete (yyvsp[0].expression_list);
      }
    }
#line 2527 "yacc_sql.cpp"
    break;

  case 71: /* select_stmt: SELECT expression_list FROM ID rel_list join_list where group_by having order_by  */
#line 657 "yacc_sql.y"
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
#line 2569 "yacc_sql.cpp"
    break;

  case 72: /* calc_stmt: CALC expression_list  */
#line 697 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2579 "yacc_sql.cpp"
    break;

  case 73: /* expression_list: expression  */
#line 705 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2588 "yacc_sql.cpp"
    break;

  case 74: /* expression_list: expression COMMA expression_list  */
#line 710 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace((yyval.expression_list)->begin(), (yyvsp[-2].expression));
    }
#line 2601 "yacc_sql.cpp"
    break;

  case 75: /* expression: LBRACE expression RBRACE  */
#line 720 "yacc_sql.y"
                             {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2610 "yacc_sql.cpp"
    break;

  case 76: /* expression: expression '+' expression  */
#line 724 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2618 "yacc_sql.cpp"
    break;

  case 77: /* expression: expression '-' expression  */
#line 727 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2626 "yacc_sql.cpp"
    break;

  case 78: /* expression: expression '*' expression  */
#line 730 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2634 "yacc_sql.cpp"
    break;

  case 79: /* expression: expression '/' expression  */
#line 733 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2642 "yacc_sql.cpp"
    break;

  case 80: /* expression: value  */
#line 736 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2652 "yacc_sql.cpp"
    break;

  case 81: /* expression: rel_attr  */
#line 741 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2663 "yacc_sql.cpp"
    break;

  case 82: /* expression: '*'  */
#line 747 "yacc_sql.y"
          {
      (yyval.expression) = new StarExpr();
    }
#line 2671 "yacc_sql.cpp"
    break;

  case 83: /* expression: '-' expression  */
#line 750 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2679 "yacc_sql.cpp"
    break;

  case 84: /* expression: aggr_expr  */
#line 753 "yacc_sql.y"
                {
      (yyval.expression) = (yyvsp[0].expression);
    }
#line 2687 "yacc_sql.cpp"
    break;

  case 85: /* expression: func_op LBRACE expression_list RBRACE  */
#line 756 "yacc_sql.y"
                                            {
      (yyval.expression) = new FunctionExpr((FuncOp)(yyvsp[-3].func),std::move(*(yyvsp[-1].expression_list)));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[-1].expression_list);
    }
#line 2697 "yacc_sql.cpp"
    break;

  case 86: /* expression: func_op LBRACE RBRACE  */
#line 761 "yacc_sql.y"
                            {
      (yyval.expression) = new FunctionExpr((FuncOp)(yyvsp[-2].func),std::vector<std::unique_ptr<Expression>>());
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2706 "yacc_sql.cpp"
    break;

  case 87: /* simple_expression: value  */
#line 767 "yacc_sql.y"
          {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2716 "yacc_sql.cpp"
    break;

  case 88: /* simple_expression: rel_attr  */
#line 772 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2727 "yacc_sql.cpp"
    break;

  case 89: /* arith_expr: LBRACE arith_expr RBRACE  */
#line 780 "yacc_sql.y"
                             {
      (yyval.expression) = (yyvsp[-1].expression);
    }
#line 2735 "yacc_sql.cpp"
    break;

  case 90: /* arith_expr: arith_expr '+' LBRACE simple_expression RBRACE  */
#line 783 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2743 "yacc_sql.cpp"
    break;

  case 91: /* arith_expr: arith_expr '-' LBRACE simple_expression RBRACE  */
#line 786 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2751 "yacc_sql.cpp"
    break;

  case 92: /* arith_expr: arith_expr '*' LBRACE simple_expression RBRACE  */
#line 789 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2759 "yacc_sql.cpp"
    break;

  case 93: /* arith_expr: arith_expr '/' LBRACE simple_expression RBRACE  */
#line 792 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2767 "yacc_sql.cpp"
    break;

  case 94: /* arith_expr: simple_expression '+' LBRACE simple_expression RBRACE  */
#line 795 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2775 "yacc_sql.cpp"
    break;

  case 95: /* arith_expr: simple_expression '-' LBRACE simple_expression RBRACE  */
#line 798 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2783 "yacc_sql.cpp"
    break;

  case 96: /* arith_expr: simple_expression '*' LBRACE simple_expression RBRACE  */
#line 801 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2791 "yacc_sql.cpp"
    break;

  case 97: /* arith_expr: simple_expression '/' LBRACE simple_expression RBRACE  */
#line 804 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2799 "yacc_sql.cpp"
    break;

  case 98: /* arith_expr: '-' arith_expr  */
#line 807 "yacc_sql.y"
                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2807 "yacc_sql.cpp"
    break;

  case 99: /* arith_expr: '-' simple_expression  */
#line 810 "yacc_sql.y"
                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2815 "yacc_sql.cpp"
    break;

  case 100: /* arith_expr: arith_expr '+' simple_expression  */
#line 813 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2823 "yacc_sql.cpp"
    break;

  case 101: /* arith_expr: arith_expr '-' simple_expression  */
#line 816 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2831 "yacc_sql.cpp"
    break;

  case 102: /* arith_expr: arith_expr '*' simple_expression  */
#line 819 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2839 "yacc_sql.cpp"
    break;

  case 103: /* arith_expr: arith_expr '/' simple_expression  */
#line 822 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2847 "yacc_sql.cpp"
    break;

  case 104: /* arith_expr: simple_expression '+' arith_expr  */
#line 825 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2855 "yacc_sql.cpp"
    break;

  case 105: /* arith_expr: simple_expression '-' arith_expr  */
#line 828 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2863 "yacc_sql.cpp"
    break;

  case 106: /* arith_expr: simple_expression '*' arith_expr  */
#line 831 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2871 "yacc_sql.cpp"
    break;

  case 107: /* arith_expr: simple_expression '/' arith_expr  */
#line 834 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2879 "yacc_sql.cpp"
    break;

  case 108: /* arith_expr: arith_expr '+' arith_expr  */
#line 837 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2887 "yacc_sql.cpp"
    break;

  case 109: /* arith_expr: arith_expr '-' arith_expr  */
#line 840 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2895 "yacc_sql.cpp"
    break;

  case 110: /* arith_expr: arith_expr '*' arith_expr  */
#line 843 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2903 "yacc_sql.cpp"
    break;

  case 111: /* arith_expr: arith_expr '/' arith_expr  */
#line 846 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2911 "yacc_sql.cpp"
    break;

  case 112: /* arith_expr: simple_expression '+' simple_expression  */
#line 849 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2919 "yacc_sql.cpp"
    break;

  case 113: /* arith_expr: simple_expression '-' simple_expression  */
#line 852 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2927 "yacc_sql.cpp"
    break;

  case 114: /* arith_expr: simple_expression '*' simple_expression  */
#line 855 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2935 "yacc_sql.cpp"
    break;

  case 115: /* arith_expr: simple_expression '/' simple_expression  */
#line 858 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2943 "yacc_sql.cpp"
    break;

  case 116: /* aggr_expr: SUM LBRACE expression_list RBRACE  */
#line 863 "yacc_sql.y"
                                      {
      (yyval.expression) = create_aggregate_expression("SUM", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2951 "yacc_sql.cpp"
    break;

  case 117: /* aggr_expr: AVG LBRACE expression_list RBRACE  */
#line 866 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("AVG", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2959 "yacc_sql.cpp"
    break;

  case 118: /* aggr_expr: MAX LBRACE expression_list RBRACE  */
#line 869 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("MAX", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2967 "yacc_sql.cpp"
    break;

  case 119: /* aggr_expr: MIN LBRACE expression_list RBRACE  */
#line 872 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("MIN", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2975 "yacc_sql.cpp"
    break;

  case 120: /* aggr_expr: COUNT LBRACE expression_list RBRACE  */
#line 875 "yacc_sql.y"
                                          {
      (yyval.expression) = create_aggregate_expression("COUNT", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2983 "yacc_sql.cpp"
    break;

  case 121: /* aggr_expr: SUM LBRACE RBRACE  */
#line 878 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("SUM", empty, sql_string, &(yyloc));
    }
#line 2994 "yacc_sql.cpp"
    break;

  case 122: /* aggr_expr: AVG LBRACE RBRACE  */
#line 884 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("AVG", empty, sql_string, &(yyloc));
    }
#line 3005 "yacc_sql.cpp"
    break;

  case 123: /* aggr_expr: MIN LBRACE RBRACE  */
#line 890 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("MIN", empty, sql_string, &(yyloc));
    }
#line 3016 "yacc_sql.cpp"
    break;

  case 124: /* aggr_expr: MAX LBRACE RBRACE  */
#line 896 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("MAX", empty, sql_string, &(yyloc));
    }
#line 3027 "yacc_sql.cpp"
    break;

  case 125: /* aggr_expr: COUNT LBRACE RBRACE  */
#line 902 "yacc_sql.y"
                          {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("COUNT", empty, sql_string, &(yyloc));
    }
#line 3038 "yacc_sql.cpp"
    break;

  case 126: /* rel_attr: ID  */
#line 911 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 3048 "yacc_sql.cpp"
    break;

  case 127: /* rel_attr: ID DOT ID  */
#line 916 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 3060 "yacc_sql.cpp"
    break;

  case 128: /* rel_list: %empty  */
#line 927 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 3068 "yacc_sql.cpp"
    break;

  case 129: /* rel_list: COMMA ID rel_list  */
#line 930 "yacc_sql.y"
                        {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::string>;
      }

      (yyval.relation_list)->push_back((yyvsp[-1].string));
      free((yyvsp[-1].string));
    }
#line 3083 "yacc_sql.cpp"
    break;

  case 130: /* join_list: %empty  */
#line 943 "yacc_sql.y"
    {
      (yyval.join_sql_node) = nullptr;
    }
#line 3091 "yacc_sql.cpp"
    break;

  case 131: /* join_list: INNER join_list  */
#line 946 "yacc_sql.y"
                      {
      (yyval.join_sql_node) = (yyvsp[0].join_sql_node);
    }
#line 3099 "yacc_sql.cpp"
    break;

  case 132: /* join_list: JOIN ID ON condition_list join_list  */
#line 949 "yacc_sql.y"
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
#line 3122 "yacc_sql.cpp"
    break;

  case 133: /* order_by: %empty  */
#line 969 "yacc_sql.y"
  {
    (yyval.order_by_list) = nullptr;
  }
#line 3130 "yacc_sql.cpp"
    break;

  case 134: /* order_by: ORDER BY rel_attr order_op order_by_list  */
#line 973 "yacc_sql.y"
  {
    (yyval.order_by_list) = new std::vector<std::pair<RelAttrSqlNode, OrderOp>>;
    (yyval.order_by_list)->emplace_back(std::make_pair(*(yyvsp[-2].rel_attr), (yyvsp[-1].orderOp)));
    delete (yyvsp[-2].rel_attr);
    if ((yyvsp[0].order_by_list) != nullptr) {
      (yyval.order_by_list)->insert((yyval.order_by_list)->end(), (yyvsp[0].order_by_list)->begin(), (yyvsp[0].order_by_list)->end());
    }
  }
#line 3143 "yacc_sql.cpp"
    break;

  case 135: /* order_by_list: %empty  */
#line 984 "yacc_sql.y"
  {
    (yyval.order_by_list) = nullptr;
  }
#line 3151 "yacc_sql.cpp"
    break;

  case 136: /* order_by_list: COMMA rel_attr order_op order_by_list  */
#line 988 "yacc_sql.y"
  {
    (yyval.order_by_list) = new std::vector<std::pair<RelAttrSqlNode, OrderOp>>;
    (yyval.order_by_list)->emplace_back(std::make_pair(*(yyvsp[-2].rel_attr), (yyvsp[-1].orderOp)));
    delete (yyvsp[-2].rel_attr);

    if ((yyvsp[0].order_by_list) != nullptr) {
      (yyval.order_by_list)->insert((yyval.order_by_list)->end(), (yyvsp[0].order_by_list)->begin(), (yyvsp[0].order_by_list)->end());
    }
  }
#line 3165 "yacc_sql.cpp"
    break;

  case 137: /* order_op: DESC  */
#line 1000 "yacc_sql.y"
       { (yyval.orderOp) = ORDER_DESC; }
#line 3171 "yacc_sql.cpp"
    break;

  case 138: /* order_op: ASC  */
#line 1001 "yacc_sql.y"
       { (yyval.orderOp) = ORDER_ASC;  }
#line 3177 "yacc_sql.cpp"
    break;

  case 139: /* order_op: %empty  */
#line 1002 "yacc_sql.y"
       { (yyval.orderOp) = ORDER_DEFAULT; }
#line 3183 "yacc_sql.cpp"
    break;

  case 140: /* where: %empty  */
#line 1008 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3191 "yacc_sql.cpp"
    break;

  case 141: /* where: WHERE condition_list  */
#line 1012 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 3199 "yacc_sql.cpp"
    break;

  case 142: /* condition_list: %empty  */
#line 1018 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3207 "yacc_sql.cpp"
    break;

  case 143: /* condition_list: condition  */
#line 1021 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 3217 "yacc_sql.cpp"
    break;

  case 144: /* condition_list: condition AND condition_list  */
#line 1026 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3227 "yacc_sql.cpp"
    break;

  case 145: /* condition_list: condition OR condition_list  */
#line 1031 "yacc_sql.y"
                                  {
      (yyvsp[-2].condition)->conjunction="OR";
      (yyvsp[0].condition_list)[0][0].conjunction="OR";
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3239 "yacc_sql.cpp"
    break;

  case 146: /* condition: arith_expr comp_op value  */
#line 1040 "yacc_sql.y"
                              {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].value);
    }
#line 3253 "yacc_sql.cpp"
    break;

  case 147: /* condition: arith_expr comp_op rel_attr  */
#line 1049 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].rel_attr);
    }
#line 3267 "yacc_sql.cpp"
    break;

  case 148: /* condition: value comp_op arith_expr  */
#line 1058 "yacc_sql.y"
                               {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 0;
        (yyval.condition)->left_value = *(yyvsp[-2].value);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].value);
    }
#line 3281 "yacc_sql.cpp"
    break;

  case 149: /* condition: rel_attr comp_op arith_expr  */
#line 1067 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 1;
        (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].rel_attr);
    }
#line 3295 "yacc_sql.cpp"
    break;

  case 150: /* condition: arith_expr comp_op arith_expr  */
#line 1076 "yacc_sql.y"
                                    {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
    }
#line 3308 "yacc_sql.cpp"
    break;

  case 151: /* condition: rel_attr comp_op value  */
#line 1084 "yacc_sql.y"
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
#line 3323 "yacc_sql.cpp"
    break;

  case 152: /* condition: value comp_op value  */
#line 1094 "yacc_sql.y"
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
#line 3338 "yacc_sql.cpp"
    break;

  case 153: /* condition: rel_attr comp_op rel_attr  */
#line 1104 "yacc_sql.y"
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
#line 3353 "yacc_sql.cpp"
    break;

  case 154: /* condition: value comp_op rel_attr  */
#line 1114 "yacc_sql.y"
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
#line 3368 "yacc_sql.cpp"
    break;

  case 155: /* condition: rel_attr comp_op SUB_QUERY  */
#line 1124 "yacc_sql.y"
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
#line 3383 "yacc_sql.cpp"
    break;

  case 156: /* condition: SUB_QUERY comp_op rel_attr  */
#line 1134 "yacc_sql.y"
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
#line 3398 "yacc_sql.cpp"
    break;

  case 157: /* condition: SUB_QUERY comp_op SUB_QUERY  */
#line 1144 "yacc_sql.y"
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
#line 3413 "yacc_sql.cpp"
    break;

  case 158: /* condition: value comp_op LBRACE value value_list RBRACE  */
#line 1154 "yacc_sql.y"
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
#line 3433 "yacc_sql.cpp"
    break;

  case 159: /* condition: rel_attr comp_op LBRACE value value_list RBRACE  */
#line 1169 "yacc_sql.y"
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
#line 3453 "yacc_sql.cpp"
    break;

  case 160: /* condition: SUB_QUERY comp_op LBRACE value value_list RBRACE  */
#line 1184 "yacc_sql.y"
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
#line 3473 "yacc_sql.cpp"
    break;

  case 161: /* condition: LBRACE value value_list RBRACE comp_op value  */
#line 1199 "yacc_sql.y"
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
#line 3493 "yacc_sql.cpp"
    break;

  case 162: /* condition: LBRACE value value_list RBRACE comp_op rel_attr  */
#line 1214 "yacc_sql.y"
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
#line 3513 "yacc_sql.cpp"
    break;

  case 163: /* condition: LBRACE value value_list RBRACE comp_op SUB_QUERY  */
#line 1229 "yacc_sql.y"
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
#line 3533 "yacc_sql.cpp"
    break;

  case 164: /* condition: LBRACE value value_list RBRACE comp_op LBRACE value value_list RBRACE  */
#line 1244 "yacc_sql.y"
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
#line 3558 "yacc_sql.cpp"
    break;

  case 165: /* condition: aggr_expr comp_op value  */
#line 1264 "yacc_sql.y"
                              {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;     
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].value);
    }
#line 3572 "yacc_sql.cpp"
    break;

  case 166: /* condition: aggr_expr comp_op rel_attr  */
#line 1273 "yacc_sql.y"
                                 {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;     
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].rel_attr);
    }
#line 3586 "yacc_sql.cpp"
    break;

  case 167: /* condition: aggr_expr comp_op aggr_expr  */
#line 1282 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 4;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);  
    }
#line 3599 "yacc_sql.cpp"
    break;

  case 168: /* condition: value is_null_choice  */
#line 1290 "yacc_sql.y"
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
#line 3616 "yacc_sql.cpp"
    break;

  case 169: /* condition: rel_attr is_null_choice  */
#line 1302 "yacc_sql.y"
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
#line 3633 "yacc_sql.cpp"
    break;

  case 170: /* is_null_choice: IS NULL_KY  */
#line 1317 "yacc_sql.y"
                 { (yyval.comp) =  OP_ISNULL; }
#line 3639 "yacc_sql.cpp"
    break;

  case 171: /* is_null_choice: IS NOT NULL_KY  */
#line 1318 "yacc_sql.y"
                     { (yyval.comp) = OP_ISNOTNULL; }
#line 3645 "yacc_sql.cpp"
    break;

  case 172: /* comp_op: EQ  */
#line 1322 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3651 "yacc_sql.cpp"
    break;

  case 173: /* comp_op: LT  */
#line 1323 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3657 "yacc_sql.cpp"
    break;

  case 174: /* comp_op: GT  */
#line 1324 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3663 "yacc_sql.cpp"
    break;

  case 175: /* comp_op: LE  */
#line 1325 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3669 "yacc_sql.cpp"
    break;

  case 176: /* comp_op: GE  */
#line 1326 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3675 "yacc_sql.cpp"
    break;

  case 177: /* comp_op: NE  */
#line 1327 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3681 "yacc_sql.cpp"
    break;

  case 178: /* comp_op: LIKE  */
#line 1328 "yacc_sql.y"
           { (yyval.comp) = CLIKE; }
#line 3687 "yacc_sql.cpp"
    break;

  case 179: /* comp_op: NOT LIKE  */
#line 1329 "yacc_sql.y"
               { (yyval.comp) = CNLIKE; }
#line 3693 "yacc_sql.cpp"
    break;

  case 180: /* comp_op: IN  */
#line 1330 "yacc_sql.y"
         { (yyval.comp) = IN_LIST; }
#line 3699 "yacc_sql.cpp"
    break;

  case 181: /* comp_op: NOT IN  */
#line 1331 "yacc_sql.y"
             { (yyval.comp) = NOTIN_LIST; }
#line 3705 "yacc_sql.cpp"
    break;

  case 182: /* comp_op: EXIST  */
#line 1332 "yacc_sql.y"
            { (yyval.comp) = EXIST_LIST; }
#line 3711 "yacc_sql.cpp"
    break;

  case 183: /* comp_op: NOT EXIST  */
#line 1333 "yacc_sql.y"
                { (yyval.comp) = NOTEXIST_LIST; }
#line 3717 "yacc_sql.cpp"
    break;

  case 184: /* func_op: I2_DISTANCE_T  */
#line 1337 "yacc_sql.y"
                    { (yyval.func) = I2_DISTANCE; }
#line 3723 "yacc_sql.cpp"
    break;

  case 185: /* func_op: COSINE_DISTANCE_T  */
#line 1338 "yacc_sql.y"
                        { (yyval.func) = COSINE_DISTANCE; }
#line 3729 "yacc_sql.cpp"
    break;

  case 186: /* func_op: INNER_PRODUCT_T  */
#line 1339 "yacc_sql.y"
                      { (yyval.func) = INNER_PRODUCT; }
#line 3735 "yacc_sql.cpp"
    break;

  case 187: /* group_by: %empty  */
#line 1343 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 3743 "yacc_sql.cpp"
    break;

  case 188: /* group_by: GROUP BY expression_list  */
#line 1347 "yacc_sql.y"
          {
        (yyval.expression_list) = (yyvsp[0].expression_list);
	  }
#line 3751 "yacc_sql.cpp"
    break;

  case 189: /* having: %empty  */
#line 1353 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3759 "yacc_sql.cpp"
    break;

  case 190: /* having: HAVING condition_list  */
#line 1357 "yacc_sql.y"
    {
      (yyval.condition_list) = (yyvsp[0].condition_list);
    }
#line 3767 "yacc_sql.cpp"
    break;

  case 191: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1364 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3781 "yacc_sql.cpp"
    break;

  case 192: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1377 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3790 "yacc_sql.cpp"
    break;

  case 193: /* set_variable_stmt: SET ID EQ value  */
#line 1385 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3802 "yacc_sql.cpp"
    break;


#line 3806 "yacc_sql.cpp"

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

#line 1397 "yacc_sql.y"

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
