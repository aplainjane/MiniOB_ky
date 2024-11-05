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
  YYSYMBOL_EQ = 60,                        /* EQ  */
  YYSYMBOL_LT = 61,                        /* LT  */
  YYSYMBOL_GT = 62,                        /* GT  */
  YYSYMBOL_LE = 63,                        /* LE  */
  YYSYMBOL_GE = 64,                        /* GE  */
  YYSYMBOL_NE = 65,                        /* NE  */
  YYSYMBOL_I2_DISTANCE_T = 66,             /* I2_DISTANCE_T  */
  YYSYMBOL_COSINE_DISTANCE_T = 67,         /* COSINE_DISTANCE_T  */
  YYSYMBOL_INNER_PRODUCT_T = 68,           /* INNER_PRODUCT_T  */
  YYSYMBOL_SUM = 69,                       /* SUM  */
  YYSYMBOL_AVG = 70,                       /* AVG  */
  YYSYMBOL_COUNT = 71,                     /* COUNT  */
  YYSYMBOL_MAX = 72,                       /* MAX  */
  YYSYMBOL_MIN = 73,                       /* MIN  */
  YYSYMBOL_NUMBER = 74,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 75,                     /* FLOAT  */
  YYSYMBOL_ID = 76,                        /* ID  */
  YYSYMBOL_SSS = 77,                       /* SSS  */
  YYSYMBOL_SUB_QUERY = 78,                 /* SUB_QUERY  */
  YYSYMBOL_VECTOR_LIST = 79,               /* VECTOR_LIST  */
  YYSYMBOL_80_ = 80,                       /* '+'  */
  YYSYMBOL_81_ = 81,                       /* '-'  */
  YYSYMBOL_82_ = 82,                       /* '*'  */
  YYSYMBOL_83_ = 83,                       /* '/'  */
  YYSYMBOL_UMINUS = 84,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 85,                  /* $accept  */
  YYSYMBOL_commands = 86,                  /* commands  */
  YYSYMBOL_command_wrapper = 87,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 88,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 89,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 90,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 91,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 92,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 93,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 94,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 95,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 96,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 97,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 98,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 99,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 100,            /* attr_def_list  */
  YYSYMBOL_attr_def = 101,                 /* attr_def  */
  YYSYMBOL_isnull = 102,                   /* isnull  */
  YYSYMBOL_number = 103,                   /* number  */
  YYSYMBOL_type = 104,                     /* type  */
  YYSYMBOL_insert_stmt = 105,              /* insert_stmt  */
  YYSYMBOL_value_list = 106,               /* value_list  */
  YYSYMBOL_value = 107,                    /* value  */
  YYSYMBOL_storage_format = 108,           /* storage_format  */
  YYSYMBOL_delete_stmt = 109,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 110,              /* update_stmt  */
  YYSYMBOL_set_clause_list = 111,          /* set_clause_list  */
  YYSYMBOL_set_clause = 112,               /* set_clause  */
  YYSYMBOL_select_stmt = 113,              /* select_stmt  */
  YYSYMBOL_calc_stmt = 114,                /* calc_stmt  */
  YYSYMBOL_expression_list = 115,          /* expression_list  */
  YYSYMBOL_expression = 116,               /* expression  */
  YYSYMBOL_simple_expression = 117,        /* simple_expression  */
  YYSYMBOL_arith_expr = 118,               /* arith_expr  */
  YYSYMBOL_aggr_expr = 119,                /* aggr_expr  */
  YYSYMBOL_rel_attr = 120,                 /* rel_attr  */
  YYSYMBOL_rel_list = 121,                 /* rel_list  */
  YYSYMBOL_join_list = 122,                /* join_list  */
  YYSYMBOL_order_by = 123,                 /* order_by  */
  YYSYMBOL_order_by_list = 124,            /* order_by_list  */
  YYSYMBOL_order_op = 125,                 /* order_op  */
  YYSYMBOL_where = 126,                    /* where  */
  YYSYMBOL_condition_list = 127,           /* condition_list  */
  YYSYMBOL_condition = 128,                /* condition  */
  YYSYMBOL_is_null_choice = 129,           /* is_null_choice  */
  YYSYMBOL_comp_op = 130,                  /* comp_op  */
  YYSYMBOL_func_op = 131,                  /* func_op  */
  YYSYMBOL_group_by = 132,                 /* group_by  */
  YYSYMBOL_having = 133,                   /* having  */
  YYSYMBOL_load_data_stmt = 134,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 135,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 136,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 137             /* opt_semicolon  */
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
#define YYLAST   739

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  191
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  363

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   335


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
       2,     2,    82,    80,     2,    81,     2,    83,     2,     2,
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
      75,    76,    77,    78,    79,    84
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   235,   235,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   266,   272,   277,   283,   289,   295,   301,
     308,   314,   322,   341,   363,   373,   405,   408,   421,   430,
     443,   446,   450,   457,   460,   461,   462,   463,   464,   465,
     468,   485,   488,   499,   503,   507,   513,   519,   525,   528,
     535,   547,   577,   583,   593,   600,   613,   621,   661,   669,
     674,   685,   689,   692,   695,   698,   701,   706,   712,   715,
     718,   721,   726,   732,   737,   745,   748,   751,   754,   757,
     760,   763,   766,   769,   772,   775,   778,   781,   784,   787,
     790,   793,   796,   799,   802,   805,   808,   811,   814,   817,
     820,   823,   828,   831,   834,   837,   840,   843,   849,   855,
     861,   867,   876,   881,   892,   895,   908,   911,   914,   934,
     937,   949,   952,   965,   966,   967,   973,   977,   983,   986,
     991,   996,  1005,  1014,  1023,  1032,  1041,  1049,  1059,  1069,
    1079,  1089,  1099,  1109,  1119,  1134,  1149,  1164,  1179,  1194,
    1209,  1229,  1238,  1247,  1255,  1267,  1282,  1283,  1287,  1288,
    1289,  1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,
    1302,  1303,  1304,  1308,  1311,  1318,  1321,  1328,  1341,  1349,
    1359,  1360
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
  "INNER", "JOIN", "EQ", "LT", "GT", "LE", "GE", "NE", "I2_DISTANCE_T",
  "COSINE_DISTANCE_T", "INNER_PRODUCT_T", "SUM", "AVG", "COUNT", "MAX",
  "MIN", "NUMBER", "FLOAT", "ID", "SSS", "SUB_QUERY", "VECTOR_LIST", "'+'",
  "'-'", "'*'", "'/'", "UMINUS", "$accept", "commands", "command_wrapper",
  "exit_stmt", "help_stmt", "sync_stmt", "begin_stmt", "commit_stmt",
  "rollback_stmt", "drop_table_stmt", "show_tables_stmt",
  "desc_table_stmt", "create_index_stmt", "drop_index_stmt",
  "create_table_stmt", "attr_def_list", "attr_def", "isnull", "number",
  "type", "insert_stmt", "value_list", "value", "storage_format",
  "delete_stmt", "update_stmt", "set_clause_list", "set_clause",
  "select_stmt", "calc_stmt", "expression_list", "expression",
  "simple_expression", "arith_expr", "aggr_expr", "rel_attr", "rel_list",
  "join_list", "order_by", "order_by_list", "order_op", "where",
  "condition_list", "condition", "is_null_choice", "comp_op", "func_op",
  "group_by", "having", "load_data_stmt", "explain_stmt",
  "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-213)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-85)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     680,    44,    62,   436,   436,   -56,    24,  -213,    29,    -7,
      21,  -213,  -213,  -213,  -213,  -213,    30,    26,   680,    61,
     137,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,    66,   132,    70,    82,    95,   436,  -213,  -213,  -213,
    -213,   159,   164,   169,   172,   184,  -213,  -213,   174,  -213,
    -213,   436,  -213,  -213,  -213,   115,  -213,  -213,   201,   185,
    -213,  -213,   170,   177,   204,   190,   197,  -213,  -213,  -213,
    -213,   243,   196,   230,  -213,   239,   -18,   229,   291,   319,
     352,   380,   198,  -213,   436,   436,   436,   436,   436,   413,
     209,   249,   248,   213,   549,   214,   218,   245,   231,   236,
    -213,  -213,   294,  -213,   295,  -213,   297,  -213,   298,  -213,
     300,  -213,  -213,     7,     7,  -213,  -213,  -213,   301,   302,
     305,   469,  -213,   269,    -5,  -213,  -213,   293,    17,   311,
     262,   317,  -213,  -213,  -213,  -213,  -213,  -213,  -213,   268,
      19,   549,   477,   539,   477,   411,   -42,   656,   539,   411,
    -213,    91,   613,   213,  -213,   336,  -213,  -213,  -213,  -213,
    -213,  -213,   -15,   218,   323,   327,   275,   302,    19,   276,
     248,   329,   477,   140,   -13,  -213,   119,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,    22,  -213,    97,   122,
     -44,  -213,   492,   500,   508,   533,   541,   556,   564,   572,
     597,   477,   -46,  -213,   192,   469,   469,  -213,  -213,  -213,
     278,   303,   312,  -213,  -213,   311,   321,   304,   302,  -213,
    -213,   333,   372,   549,   358,   359,  -213,  -213,  -213,  -213,
     549,  -213,  -213,   326,  -213,   477,    87,   175,   180,   477,
      97,   122,   477,    97,   122,   477,  -213,  -213,   477,  -213,
    -213,   477,    97,   122,   477,    97,   122,   477,  -213,  -213,
     477,  -213,  -213,    87,   175,   180,  -213,  -213,  -213,   477,
    -213,    87,   175,   180,  -213,  -213,  -213,  -213,   361,  -213,
    -213,   346,  -213,   302,   376,   469,   400,   364,   329,  -213,
     539,   329,  -213,   140,    -1,    34,   102,   107,   120,   139,
     151,   155,   140,     2,   347,   383,  -213,    19,   436,   469,
     402,  -213,   605,   385,   388,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,   389,  -213,   337,  -213,  -213,  -213,  -213,
     410,  -213,   549,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
     339,   329,   202,   393,  -213,  -213,   406,  -213,   339,  -213,
     202,   406,  -213
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,    24,    23,     0,     0,     0,     0,
     190,    22,    21,    14,    15,    16,    17,     9,    10,    11,
      12,    13,     8,     5,     7,     6,     4,     3,    18,    19,
      20,     0,     0,     0,     0,     0,     0,    57,   180,   181,
     182,     0,     0,     0,     0,     0,    53,    54,   122,    55,
      56,     0,    78,    76,    68,    69,    80,    77,     0,    66,
      31,    30,     0,     0,     0,     0,     0,   188,     1,   191,
       2,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,     0,     0,     0,     0,     0,
      71,   117,     0,   118,     0,   121,     0,   120,     0,   119,
       0,   123,    70,    72,    73,    74,    75,    82,     0,   124,
       0,   138,    60,     0,   136,    62,   189,     0,     0,    36,
       0,     0,    34,   112,   113,   116,   114,   115,    81,     0,
     126,     0,     0,     0,     0,    83,     0,     0,     0,    84,
     137,   139,     0,     0,    61,     0,    44,    45,    48,    49,
      46,    47,    40,     0,     0,     0,     0,   124,   126,     0,
     136,    51,     0,    83,     0,    84,     0,   174,   176,   178,
     168,   169,   170,   171,   172,   173,     0,    83,    95,    94,
       0,   164,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,   138,   138,    65,    64,    63,
       0,     0,     0,    41,    39,    36,    58,     0,   124,   125,
     127,     0,   183,     0,     0,     0,    85,   175,   177,   179,
       0,   153,   152,     0,   166,     0,   148,   144,   150,     0,
     108,   100,     0,   109,   101,     0,   110,   102,     0,   111,
     103,     0,    96,   104,     0,    97,   105,     0,    98,   106,
       0,    99,   107,   142,   146,   143,   161,   163,   162,     0,
     151,   147,   145,   149,   140,   141,   187,    43,     0,    42,
      37,     0,    35,   124,     0,   138,     0,   185,    51,    50,
       0,    51,   167,    83,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    40,     0,     0,    32,   126,     0,   138,
     129,    52,     0,     0,     0,    90,    91,    92,    93,    86,
      87,    88,    89,     0,    38,     0,    33,   128,   184,   186,
       0,    67,     0,   159,   157,   158,   156,   154,   155,    59,
       0,    51,   135,     0,   134,   133,   131,   160,     0,   130,
     135,   131,   132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -213,  -213,   399,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,   207,   265,   126,  -213,  -213,
    -213,  -174,    14,  -213,  -213,  -213,  -213,   277,  -213,  -213,
      32,   146,    73,   -55,   -80,    -3,  -156,  -176,  -213,    80,
      83,  -128,  -212,  -213,   283,  -143,  -213,  -213,  -213,  -213,
    -213,  -213,  -213
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   174,   139,   224,   288,   172,
      33,   234,   197,   292,    34,    35,   134,   135,    36,    37,
      64,    65,   156,   184,    66,   185,   150,   180,   341,   359,
     356,   132,   160,   161,   201,   196,    68,   297,   320,    38,
      39,    40,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    67,   230,   284,   285,   110,   164,   221,   243,   235,
     236,    47,   202,   244,   211,   212,   214,    63,    63,   163,
      70,   229,   325,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    73,    60,    71,   131,    69,   222,   203,   204,
     205,   206,   223,    67,   240,   166,   167,   168,   169,   170,
     171,   158,   232,    41,   222,    42,    43,   326,    67,   223,
      63,    78,    95,    96,    97,    98,    72,   207,   208,   209,
     210,    44,   294,    76,    45,    63,   157,   178,   179,   203,
     204,   205,   206,   317,    67,    67,    67,    67,    67,    97,
      98,    67,    67,    67,    67,    67,    67,    74,    58,   199,
     241,    63,    63,    63,    63,    63,    75,   339,    63,    63,
      63,    63,    63,    63,   203,   204,   205,   206,   136,   112,
     114,   116,   118,   120,   321,   327,   122,   323,   159,   324,
     328,   128,   277,   215,   216,   158,   158,   315,   333,    94,
      79,   337,    81,   329,    82,   155,    83,   247,   251,   254,
     257,   260,   263,   266,   269,   272,   274,   322,    84,   282,
     157,   157,   330,   -51,   233,   181,   183,   -83,   -83,   -83,
     -83,    85,   237,   238,   331,   239,   218,   353,   332,   205,
     206,    87,   203,   204,   205,   206,    88,   203,   204,   205,
     206,    89,    86,   242,    90,    95,    96,    97,    98,   248,
     203,   204,   205,   206,   209,   210,    91,    93,   275,   278,
      92,   283,   159,   159,   279,   158,   246,   354,   355,   203,
     204,   205,   206,    99,   100,   273,   276,   198,   281,   155,
     155,   203,   204,   205,   206,   203,   204,   205,   206,   158,
     157,   123,   124,   125,   126,   105,   101,   298,   103,    47,
     104,    46,   111,   102,   301,   207,   208,   209,   210,   303,
     -84,   -84,   -84,   -84,   157,   106,    56,    57,    58,    59,
     280,    60,   107,   154,   121,   108,   250,   253,   256,   259,
     262,   265,   268,   271,   109,   129,    47,   130,   131,   133,
     140,   137,   159,   312,   138,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   141,    60,   155,
      61,    62,   142,    46,   113,    67,   159,   143,   144,   345,
     145,   146,   304,   147,   148,   305,   149,   151,   306,   162,
     165,   307,    63,   155,   308,   173,   344,   309,   175,   176,
     310,    46,   115,   311,   177,   220,   226,   352,    47,   227,
     338,   228,   231,   233,   286,   360,   351,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,   289,
      60,   291,    61,    62,    46,   117,    47,   287,   295,   296,
     293,   299,   300,   302,   313,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   314,    60,   316,
      61,    62,    46,   119,   318,   319,   336,   335,   346,    47,
     340,   347,   348,   349,   350,    58,   357,    77,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
     358,    60,   290,    61,    62,    46,   127,    47,   225,   334,
     219,   362,   213,   361,     0,     0,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    46,    60,
       0,    61,    62,   186,   187,   188,   200,   189,     0,     0,
      47,   190,   191,   192,   193,   194,   195,     0,     0,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,   152,    60,    47,    61,    62,     0,     0,     0,   182,
       0,     0,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,   245,    60,     0,    61,    62,     0,
       0,     0,   249,     0,     0,     0,    47,     0,     0,     0,
     252,     0,     0,     0,    47,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   153,    60,    47,
     154,    56,    57,    58,    59,   255,    60,    47,   154,     0,
       0,     0,     0,   258,     0,    47,    56,    57,    58,    59,
       0,    60,     0,   154,    56,    57,    58,    59,   261,    60,
       0,   154,    56,    57,    58,    59,   264,    60,     0,   154,
      47,   186,   187,   188,   267,   189,     0,     0,    47,   190,
     191,   192,   193,   194,   195,     0,    47,    56,    57,    58,
      59,     0,    60,    47,   154,    56,    57,    58,    59,   270,
      60,    47,   154,    56,    57,     0,    59,   342,    60,    47,
      56,    57,    58,    59,     0,    60,     0,   154,    56,    57,
      58,    59,     0,    60,     0,   154,    56,    57,    58,    59,
       0,    60,     0,   154,    47,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
      47,    56,    57,    58,    59,     0,    60,     0,   154,    56,
      57,    58,    59,   343,    60,     1,     2,    56,    57,     0,
      59,   217,    60,     3,     4,     0,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,   186,   187,
     188,     0,   189,     0,    14,    15,   190,   191,   192,   193,
     194,   195,     0,     0,    16,     0,    17,     0,     0,    18,
       0,     0,     0,     0,     0,     0,   207,   208,   209,   210
};

static const yytype_int16 yycheck[] =
{
       3,     4,   178,   215,   216,    23,   134,    22,    52,   183,
      23,    57,   155,    57,   157,   158,   159,     3,     4,    24,
      76,   177,    23,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    39,    79,    10,    40,     4,    52,    80,    81,
      82,    83,    57,    46,    22,    28,    29,    30,    31,    32,
      33,   131,   180,     9,    52,    11,    12,    23,    61,    57,
      46,     0,    80,    81,    82,    83,    37,    80,    81,    82,
      83,     9,   228,    47,    12,    61,   131,    58,    59,    80,
      81,    82,    83,   295,    87,    88,    89,    90,    91,    82,
      83,    94,    95,    96,    97,    98,    99,    76,    76,   154,
      78,    87,    88,    89,    90,    91,    76,   319,    94,    95,
      96,    97,    98,    99,    80,    81,    82,    83,   104,    87,
      88,    89,    90,    91,   298,    23,    94,   301,   131,   303,
      23,    99,   212,    42,    43,   215,   216,   293,   312,    24,
       3,   317,    76,    23,    12,   131,    76,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   300,    76,   214,
     215,   216,    23,    23,    24,   151,   152,    80,    81,    82,
      83,    76,    53,    54,    23,    56,   162,   351,    23,    82,
      83,    22,    80,    81,    82,    83,    22,    80,    81,    82,
      83,    22,    46,   196,    22,    80,    81,    82,    83,   202,
      80,    81,    82,    83,    82,    83,    22,    61,   211,   212,
      36,   214,   215,   216,    22,   295,   202,    15,    16,    80,
      81,    82,    83,    22,    39,   211,   212,   154,   214,   215,
     216,    80,    81,    82,    83,    80,    81,    82,    83,   319,
     295,    95,    96,    97,    98,    48,    76,   233,    44,    57,
      60,    22,    23,    76,   240,    80,    81,    82,    83,   245,
      80,    81,    82,    83,   319,    22,    74,    75,    76,    77,
      78,    79,    76,    81,    76,    45,   203,   204,   205,   206,
     207,   208,   209,   210,    45,    76,    57,    38,    40,    76,
      45,    77,   295,   279,    76,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    76,    79,   295,
      81,    82,    76,    22,    23,   318,   319,    23,    23,   322,
      23,    23,   249,    23,    23,   252,    24,    22,   255,    60,
      37,   258,   318,   319,   261,    24,   322,   264,    76,    22,
     267,    22,    23,   270,    76,     9,    23,   350,    57,    22,
     318,    76,    76,    24,    76,   358,   342,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    57,
      79,    50,    81,    82,    22,    23,    57,    74,    45,     7,
      76,    23,    23,    57,    23,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    51,    79,    23,
      81,    82,    22,    23,     4,    41,    23,    60,    23,    57,
       8,    23,    23,    76,     4,    76,    23,    18,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      24,    79,   225,    81,    82,    22,    23,    57,   173,   313,
     163,   361,   159,   360,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    22,    79,
      -1,    81,    82,    52,    53,    54,    55,    56,    -1,    -1,
      57,    60,    61,    62,    63,    64,    65,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    22,    79,    57,    81,    82,    -1,    -1,    -1,    22,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    22,    79,    -1,    81,    82,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    57,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    57,
      81,    74,    75,    76,    77,    22,    79,    57,    81,    -1,
      -1,    -1,    -1,    22,    -1,    57,    74,    75,    76,    77,
      -1,    79,    -1,    81,    74,    75,    76,    77,    22,    79,
      -1,    81,    74,    75,    76,    77,    22,    79,    -1,    81,
      57,    52,    53,    54,    22,    56,    -1,    -1,    57,    60,
      61,    62,    63,    64,    65,    -1,    57,    74,    75,    76,
      77,    -1,    79,    57,    81,    74,    75,    76,    77,    22,
      79,    57,    81,    74,    75,    -1,    77,    22,    79,    57,
      74,    75,    76,    77,    -1,    79,    -1,    81,    74,    75,
      76,    77,    -1,    79,    -1,    81,    74,    75,    76,    77,
      -1,    79,    -1,    81,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    74,    75,    76,    77,    -1,    79,    -1,    81,    74,
      75,    76,    77,    78,    79,     5,     6,    74,    75,    -1,
      77,    78,    79,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    26,    27,    52,    53,
      54,    -1,    56,    -1,    34,    35,    60,    61,    62,    63,
      64,    65,    -1,    -1,    44,    -1,    46,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    13,    14,    16,    17,    18,    19,    20,
      21,    25,    26,    27,    34,    35,    44,    46,    49,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   105,   109,   110,   113,   114,   134,   135,
     136,     9,    11,    12,     9,    12,    22,    57,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      79,    81,    82,   107,   115,   116,   119,   120,   131,   115,
      76,    10,    37,    39,    76,    76,    47,    87,     0,     3,
     137,    76,    12,    76,    76,    76,   116,    22,    22,    22,
      22,    22,    36,   116,    24,    80,    81,    82,    83,    22,
      39,    76,    76,    44,    60,    48,    22,    76,    45,    45,
      23,    23,   115,    23,   115,    23,   115,    23,   115,    23,
     115,    76,   115,   116,   116,   116,   116,    23,   115,    76,
      38,    40,   126,    76,   111,   112,   107,    77,    76,   101,
      45,    76,    76,    23,    23,    23,    23,    23,    23,    24,
     121,    22,    22,    78,    81,   107,   117,   118,   119,   120,
     127,   128,    60,    24,   126,    37,    28,    29,    30,    31,
      32,    33,   104,    24,   100,    76,    22,    76,    58,    59,
     122,   107,    22,   107,   118,   120,    52,    53,    54,    56,
      60,    61,    62,    63,    64,    65,   130,   107,   117,   118,
      55,   129,   130,    80,    81,    82,    83,    80,    81,    82,
      83,   130,   130,   129,   130,    42,    43,    78,   107,   112,
       9,    22,    52,    57,   102,   101,    23,    22,    76,   121,
     122,    76,   126,    24,   106,   106,    23,    53,    54,    56,
      22,    78,   120,    52,    57,    22,   107,   118,   120,    22,
     117,   118,    22,   117,   118,    22,   117,   118,    22,   117,
     118,    22,   117,   118,    22,   117,   118,    22,   117,   118,
      22,   117,   118,   107,   118,   120,   107,   119,   120,    22,
      78,   107,   118,   120,   127,   127,    76,    74,   103,    57,
     100,    50,   108,    76,   121,    45,     7,   132,   107,    23,
      23,   107,    57,   107,   117,   117,   117,   117,   117,   117,
     117,   117,   107,    23,    51,   121,    23,   127,     4,    41,
     133,   106,   130,   106,   106,    23,    23,    23,    23,    23,
      23,    23,    23,   106,   102,    60,    23,   122,   115,   127,
       8,   123,    22,    78,   107,   120,    23,    23,    23,    76,
       4,   107,   120,   106,    15,    16,   125,    23,    24,   124,
     120,   125,   124
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    97,    98,    99,   100,   100,   101,   101,
     102,   102,   102,   103,   104,   104,   104,   104,   104,   104,
     105,   106,   106,   107,   107,   107,   107,   107,   108,   108,
     109,   110,   111,   111,   112,   112,   113,   113,   114,   115,
     115,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   117,   117,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   123,
     123,   124,   124,   125,   125,   125,   126,   126,   127,   127,
     127,   127,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   129,   129,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     131,   131,   131,   132,   132,   133,   133,   134,   135,   136,
     137,   137
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     9,    10,     5,     8,     0,     3,     6,     3,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       8,     0,     3,     1,     1,     1,     1,     1,     0,     4,
       4,     5,     1,     3,     3,     3,     2,    10,     2,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     2,
       1,     4,     3,     1,     1,     3,     5,     5,     5,     5,
       5,     5,     5,     5,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     4,     4,     4,     3,     3,     3,
       3,     3,     1,     3,     0,     3,     0,     2,     5,     0,
       5,     0,     4,     1,     1,     0,     0,     2,     0,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     6,     6,     6,     6,     6,     6,
       9,     3,     3,     3,     2,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     0,     3,     0,     2,     7,     2,     4,
       0,     1
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
#line 236 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1991 "yacc_sql.cpp"
    break;

  case 23: /* exit_stmt: EXIT  */
#line 266 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 2000 "yacc_sql.cpp"
    break;

  case 24: /* help_stmt: HELP  */
#line 272 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 2008 "yacc_sql.cpp"
    break;

  case 25: /* sync_stmt: SYNC  */
#line 277 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 2016 "yacc_sql.cpp"
    break;

  case 26: /* begin_stmt: TRX_BEGIN  */
#line 283 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 2024 "yacc_sql.cpp"
    break;

  case 27: /* commit_stmt: TRX_COMMIT  */
#line 289 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 2032 "yacc_sql.cpp"
    break;

  case 28: /* rollback_stmt: TRX_ROLLBACK  */
#line 295 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 2040 "yacc_sql.cpp"
    break;

  case 29: /* drop_table_stmt: DROP TABLE ID  */
#line 301 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2050 "yacc_sql.cpp"
    break;

  case 30: /* show_tables_stmt: SHOW TABLES  */
#line 308 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 2058 "yacc_sql.cpp"
    break;

  case 31: /* desc_table_stmt: DESC ID  */
#line 314 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2068 "yacc_sql.cpp"
    break;

  case 32: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID rel_list RBRACE  */
#line 323 "yacc_sql.y"
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
#line 2091 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID rel_list RBRACE  */
#line 342 "yacc_sql.y"
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
#line 2114 "yacc_sql.cpp"
    break;

  case 34: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 364 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2126 "yacc_sql.cpp"
    break;

  case 35: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format  */
#line 374 "yacc_sql.y"
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
#line 2159 "yacc_sql.cpp"
    break;

  case 36: /* attr_def_list: %empty  */
#line 405 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2167 "yacc_sql.cpp"
    break;

  case 37: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 409 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2181 "yacc_sql.cpp"
    break;

  case 38: /* attr_def: ID type LBRACE number RBRACE isnull  */
#line 422 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->isnull = (yyvsp[0].boolean);
      free((yyvsp[-5].string));
    }
#line 2194 "yacc_sql.cpp"
    break;

  case 39: /* attr_def: ID type isnull  */
#line 431 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->isnull = (yyvsp[0].boolean);
      free((yyvsp[-2].string));
    }
#line 2207 "yacc_sql.cpp"
    break;

  case 40: /* isnull: %empty  */
#line 443 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2215 "yacc_sql.cpp"
    break;

  case 41: /* isnull: NULL_KY  */
#line 447 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2223 "yacc_sql.cpp"
    break;

  case 42: /* isnull: NOT NULL_KY  */
#line 451 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2231 "yacc_sql.cpp"
    break;

  case 43: /* number: NUMBER  */
#line 457 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2237 "yacc_sql.cpp"
    break;

  case 44: /* type: INT_T  */
#line 460 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::INTS); }
#line 2243 "yacc_sql.cpp"
    break;

  case 45: /* type: STRING_T  */
#line 461 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::CHARS); }
#line 2249 "yacc_sql.cpp"
    break;

  case 46: /* type: FLOAT_T  */
#line 462 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::FLOATS); }
#line 2255 "yacc_sql.cpp"
    break;

  case 47: /* type: VECTOR_T  */
#line 463 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::VECTORS); }
#line 2261 "yacc_sql.cpp"
    break;

  case 48: /* type: DATE_T  */
#line 464 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::DATES); }
#line 2267 "yacc_sql.cpp"
    break;

  case 49: /* type: TEXT_T  */
#line 465 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::TEXTS); }
#line 2273 "yacc_sql.cpp"
    break;

  case 50: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 469 "yacc_sql.y"
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
#line 2290 "yacc_sql.cpp"
    break;

  case 51: /* value_list: %empty  */
#line 485 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2298 "yacc_sql.cpp"
    break;

  case 52: /* value_list: COMMA value value_list  */
#line 488 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2312 "yacc_sql.cpp"
    break;

  case 53: /* value: NUMBER  */
#line 499 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2321 "yacc_sql.cpp"
    break;

  case 54: /* value: FLOAT  */
#line 503 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2330 "yacc_sql.cpp"
    break;

  case 55: /* value: SSS  */
#line 507 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2341 "yacc_sql.cpp"
    break;

  case 56: /* value: VECTOR_LIST  */
#line 513 "yacc_sql.y"
                 {
      char *tmp = common::substr((yyvsp[0].string),0,strlen((yyvsp[0].string))-1);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2352 "yacc_sql.cpp"
    break;

  case 57: /* value: NULL_KY  */
#line 519 "yacc_sql.y"
              {
      (yyval.value) = new Value(NULL_VALUE, 1);
    }
#line 2360 "yacc_sql.cpp"
    break;

  case 58: /* storage_format: %empty  */
#line 525 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 2368 "yacc_sql.cpp"
    break;

  case 59: /* storage_format: STORAGE FORMAT EQ ID  */
#line 529 "yacc_sql.y"
    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2376 "yacc_sql.cpp"
    break;

  case 60: /* delete_stmt: DELETE FROM ID where  */
#line 536 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2390 "yacc_sql.cpp"
    break;

  case 61: /* update_stmt: UPDATE ID SET set_clause_list where  */
#line 548 "yacc_sql.y"
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
#line 2420 "yacc_sql.cpp"
    break;

  case 62: /* set_clause_list: set_clause  */
#line 578 "yacc_sql.y"
    {
        (yyval.set_clause_list) = new std::vector<UpdateKV>();
        (yyval.set_clause_list)->push_back(*(yyvsp[0].set_clause));
        delete (yyvsp[0].set_clause);  // 确保 $1 是 new 出来的对象
    }
#line 2430 "yacc_sql.cpp"
    break;

  case 63: /* set_clause_list: set_clause_list COMMA set_clause  */
#line 584 "yacc_sql.y"
    {
        (yyvsp[-2].set_clause_list)->push_back(*(yyvsp[0].set_clause));
        (yyval.set_clause_list) = (yyvsp[-2].set_clause_list);
        delete (yyvsp[0].set_clause);  // 确保 $3 是 new 出来的对象
    }
#line 2440 "yacc_sql.cpp"
    break;

  case 64: /* set_clause: ID EQ value  */
#line 594 "yacc_sql.y"
    {
        (yyval.set_clause) = new UpdateKV();
        (yyval.set_clause)->attr_name = strdup((yyvsp[-2].string));  // 使用 strdup 复制字符串，避免释放后使用问题
        (yyval.set_clause)->value = *(yyvsp[0].value);
        free((yyvsp[-2].string));  // 确保在拷贝完成后再释放
    }
#line 2451 "yacc_sql.cpp"
    break;

  case 65: /* set_clause: ID EQ SUB_QUERY  */
#line 601 "yacc_sql.y"
    {
      (yyval.set_clause) = new UpdateKV();
      (yyval.set_clause)->is_subquery = true;
      (yyval.set_clause)->attr_name = strdup((yyvsp[-2].string));
      (yyval.set_clause)->subquery = strdup((yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2464 "yacc_sql.cpp"
    break;

  case 66: /* select_stmt: SELECT expression_list  */
#line 614 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[0].expression_list));
        delete (yyvsp[0].expression_list);
      }
    }
#line 2476 "yacc_sql.cpp"
    break;

  case 67: /* select_stmt: SELECT expression_list FROM ID rel_list join_list where group_by having order_by  */
#line 622 "yacc_sql.y"
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
#line 2518 "yacc_sql.cpp"
    break;

  case 68: /* calc_stmt: CALC expression_list  */
#line 662 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2528 "yacc_sql.cpp"
    break;

  case 69: /* expression_list: expression  */
#line 670 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2537 "yacc_sql.cpp"
    break;

  case 70: /* expression_list: expression COMMA expression_list  */
#line 675 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace((yyval.expression_list)->begin(), (yyvsp[-2].expression));
    }
#line 2550 "yacc_sql.cpp"
    break;

  case 71: /* expression: LBRACE expression RBRACE  */
#line 685 "yacc_sql.y"
                             {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2559 "yacc_sql.cpp"
    break;

  case 72: /* expression: expression '+' expression  */
#line 689 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2567 "yacc_sql.cpp"
    break;

  case 73: /* expression: expression '-' expression  */
#line 692 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2575 "yacc_sql.cpp"
    break;

  case 74: /* expression: expression '*' expression  */
#line 695 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2583 "yacc_sql.cpp"
    break;

  case 75: /* expression: expression '/' expression  */
#line 698 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2591 "yacc_sql.cpp"
    break;

  case 76: /* expression: value  */
#line 701 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2601 "yacc_sql.cpp"
    break;

  case 77: /* expression: rel_attr  */
#line 706 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2612 "yacc_sql.cpp"
    break;

  case 78: /* expression: '*'  */
#line 712 "yacc_sql.y"
          {
      (yyval.expression) = new StarExpr();
    }
#line 2620 "yacc_sql.cpp"
    break;

  case 79: /* expression: '-' expression  */
#line 715 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2628 "yacc_sql.cpp"
    break;

  case 80: /* expression: aggr_expr  */
#line 718 "yacc_sql.y"
                {
      (yyval.expression) = (yyvsp[0].expression);
    }
#line 2636 "yacc_sql.cpp"
    break;

  case 81: /* expression: func_op LBRACE expression_list RBRACE  */
#line 721 "yacc_sql.y"
                                            {
      (yyval.expression) = new FunctionExpr((FuncOp)(yyvsp[-3].func),std::move(*(yyvsp[-1].expression_list)));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[-1].expression_list);
    }
#line 2646 "yacc_sql.cpp"
    break;

  case 82: /* expression: func_op LBRACE RBRACE  */
#line 726 "yacc_sql.y"
                            {
      (yyval.expression) = new FunctionExpr((FuncOp)(yyvsp[-2].func),std::vector<std::unique_ptr<Expression>>());
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2655 "yacc_sql.cpp"
    break;

  case 83: /* simple_expression: value  */
#line 732 "yacc_sql.y"
          {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2665 "yacc_sql.cpp"
    break;

  case 84: /* simple_expression: rel_attr  */
#line 737 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2676 "yacc_sql.cpp"
    break;

  case 85: /* arith_expr: LBRACE arith_expr RBRACE  */
#line 745 "yacc_sql.y"
                             {
      (yyval.expression) = (yyvsp[-1].expression);
    }
#line 2684 "yacc_sql.cpp"
    break;

  case 86: /* arith_expr: arith_expr '+' LBRACE simple_expression RBRACE  */
#line 748 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2692 "yacc_sql.cpp"
    break;

  case 87: /* arith_expr: arith_expr '-' LBRACE simple_expression RBRACE  */
#line 751 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2700 "yacc_sql.cpp"
    break;

  case 88: /* arith_expr: arith_expr '*' LBRACE simple_expression RBRACE  */
#line 754 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2708 "yacc_sql.cpp"
    break;

  case 89: /* arith_expr: arith_expr '/' LBRACE simple_expression RBRACE  */
#line 757 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2716 "yacc_sql.cpp"
    break;

  case 90: /* arith_expr: simple_expression '+' LBRACE simple_expression RBRACE  */
#line 760 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2724 "yacc_sql.cpp"
    break;

  case 91: /* arith_expr: simple_expression '-' LBRACE simple_expression RBRACE  */
#line 763 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2732 "yacc_sql.cpp"
    break;

  case 92: /* arith_expr: simple_expression '*' LBRACE simple_expression RBRACE  */
#line 766 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2740 "yacc_sql.cpp"
    break;

  case 93: /* arith_expr: simple_expression '/' LBRACE simple_expression RBRACE  */
#line 769 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2748 "yacc_sql.cpp"
    break;

  case 94: /* arith_expr: '-' arith_expr  */
#line 772 "yacc_sql.y"
                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2756 "yacc_sql.cpp"
    break;

  case 95: /* arith_expr: '-' simple_expression  */
#line 775 "yacc_sql.y"
                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2764 "yacc_sql.cpp"
    break;

  case 96: /* arith_expr: arith_expr '+' simple_expression  */
#line 778 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2772 "yacc_sql.cpp"
    break;

  case 97: /* arith_expr: arith_expr '-' simple_expression  */
#line 781 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2780 "yacc_sql.cpp"
    break;

  case 98: /* arith_expr: arith_expr '*' simple_expression  */
#line 784 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2788 "yacc_sql.cpp"
    break;

  case 99: /* arith_expr: arith_expr '/' simple_expression  */
#line 787 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2796 "yacc_sql.cpp"
    break;

  case 100: /* arith_expr: simple_expression '+' arith_expr  */
#line 790 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2804 "yacc_sql.cpp"
    break;

  case 101: /* arith_expr: simple_expression '-' arith_expr  */
#line 793 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2812 "yacc_sql.cpp"
    break;

  case 102: /* arith_expr: simple_expression '*' arith_expr  */
#line 796 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2820 "yacc_sql.cpp"
    break;

  case 103: /* arith_expr: simple_expression '/' arith_expr  */
#line 799 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2828 "yacc_sql.cpp"
    break;

  case 104: /* arith_expr: arith_expr '+' arith_expr  */
#line 802 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2836 "yacc_sql.cpp"
    break;

  case 105: /* arith_expr: arith_expr '-' arith_expr  */
#line 805 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2844 "yacc_sql.cpp"
    break;

  case 106: /* arith_expr: arith_expr '*' arith_expr  */
#line 808 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2852 "yacc_sql.cpp"
    break;

  case 107: /* arith_expr: arith_expr '/' arith_expr  */
#line 811 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2860 "yacc_sql.cpp"
    break;

  case 108: /* arith_expr: simple_expression '+' simple_expression  */
#line 814 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2868 "yacc_sql.cpp"
    break;

  case 109: /* arith_expr: simple_expression '-' simple_expression  */
#line 817 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2876 "yacc_sql.cpp"
    break;

  case 110: /* arith_expr: simple_expression '*' simple_expression  */
#line 820 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2884 "yacc_sql.cpp"
    break;

  case 111: /* arith_expr: simple_expression '/' simple_expression  */
#line 823 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2892 "yacc_sql.cpp"
    break;

  case 112: /* aggr_expr: SUM LBRACE expression_list RBRACE  */
#line 828 "yacc_sql.y"
                                      {
      (yyval.expression) = create_aggregate_expression("SUM", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2900 "yacc_sql.cpp"
    break;

  case 113: /* aggr_expr: AVG LBRACE expression_list RBRACE  */
#line 831 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("AVG", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2908 "yacc_sql.cpp"
    break;

  case 114: /* aggr_expr: MAX LBRACE expression_list RBRACE  */
#line 834 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("MAX", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2916 "yacc_sql.cpp"
    break;

  case 115: /* aggr_expr: MIN LBRACE expression_list RBRACE  */
#line 837 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("MIN", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2924 "yacc_sql.cpp"
    break;

  case 116: /* aggr_expr: COUNT LBRACE expression_list RBRACE  */
#line 840 "yacc_sql.y"
                                          {
      (yyval.expression) = create_aggregate_expression("COUNT", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2932 "yacc_sql.cpp"
    break;

  case 117: /* aggr_expr: SUM LBRACE RBRACE  */
#line 843 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("SUM", empty, sql_string, &(yyloc));
    }
#line 2943 "yacc_sql.cpp"
    break;

  case 118: /* aggr_expr: AVG LBRACE RBRACE  */
#line 849 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("AVG", empty, sql_string, &(yyloc));
    }
#line 2954 "yacc_sql.cpp"
    break;

  case 119: /* aggr_expr: MIN LBRACE RBRACE  */
#line 855 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("MIN", empty, sql_string, &(yyloc));
    }
#line 2965 "yacc_sql.cpp"
    break;

  case 120: /* aggr_expr: MAX LBRACE RBRACE  */
#line 861 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("MAX", empty, sql_string, &(yyloc));
    }
#line 2976 "yacc_sql.cpp"
    break;

  case 121: /* aggr_expr: COUNT LBRACE RBRACE  */
#line 867 "yacc_sql.y"
                          {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("COUNT", empty, sql_string, &(yyloc));
    }
#line 2987 "yacc_sql.cpp"
    break;

  case 122: /* rel_attr: ID  */
#line 876 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2997 "yacc_sql.cpp"
    break;

  case 123: /* rel_attr: ID DOT ID  */
#line 881 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 3009 "yacc_sql.cpp"
    break;

  case 124: /* rel_list: %empty  */
#line 892 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 3017 "yacc_sql.cpp"
    break;

  case 125: /* rel_list: COMMA ID rel_list  */
#line 895 "yacc_sql.y"
                        {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::string>;
      }

      (yyval.relation_list)->push_back((yyvsp[-1].string));
      free((yyvsp[-1].string));
    }
#line 3032 "yacc_sql.cpp"
    break;

  case 126: /* join_list: %empty  */
#line 908 "yacc_sql.y"
    {
      (yyval.join_sql_node) = nullptr;
    }
#line 3040 "yacc_sql.cpp"
    break;

  case 127: /* join_list: INNER join_list  */
#line 911 "yacc_sql.y"
                      {
      (yyval.join_sql_node) = (yyvsp[0].join_sql_node);
    }
#line 3048 "yacc_sql.cpp"
    break;

  case 128: /* join_list: JOIN ID ON condition_list join_list  */
#line 914 "yacc_sql.y"
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
#line 3071 "yacc_sql.cpp"
    break;

  case 129: /* order_by: %empty  */
#line 934 "yacc_sql.y"
  {
    (yyval.order_by_list) = nullptr;
  }
#line 3079 "yacc_sql.cpp"
    break;

  case 130: /* order_by: ORDER BY rel_attr order_op order_by_list  */
#line 938 "yacc_sql.y"
  {
    (yyval.order_by_list) = new std::vector<std::pair<RelAttrSqlNode, OrderOp>>;
    (yyval.order_by_list)->emplace_back(std::make_pair(*(yyvsp[-2].rel_attr), (yyvsp[-1].orderOp)));
    delete (yyvsp[-2].rel_attr);
    if ((yyvsp[0].order_by_list) != nullptr) {
      (yyval.order_by_list)->insert((yyval.order_by_list)->end(), (yyvsp[0].order_by_list)->begin(), (yyvsp[0].order_by_list)->end());
    }
  }
#line 3092 "yacc_sql.cpp"
    break;

  case 131: /* order_by_list: %empty  */
#line 949 "yacc_sql.y"
  {
    (yyval.order_by_list) = nullptr;
  }
#line 3100 "yacc_sql.cpp"
    break;

  case 132: /* order_by_list: COMMA rel_attr order_op order_by_list  */
#line 953 "yacc_sql.y"
  {
    (yyval.order_by_list) = new std::vector<std::pair<RelAttrSqlNode, OrderOp>>;
    (yyval.order_by_list)->emplace_back(std::make_pair(*(yyvsp[-2].rel_attr), (yyvsp[-1].orderOp)));
    delete (yyvsp[-2].rel_attr);

    if ((yyvsp[0].order_by_list) != nullptr) {
      (yyval.order_by_list)->insert((yyval.order_by_list)->end(), (yyvsp[0].order_by_list)->begin(), (yyvsp[0].order_by_list)->end());
    }
  }
#line 3114 "yacc_sql.cpp"
    break;

  case 133: /* order_op: DESC  */
#line 965 "yacc_sql.y"
       { (yyval.orderOp) = ORDER_DESC; }
#line 3120 "yacc_sql.cpp"
    break;

  case 134: /* order_op: ASC  */
#line 966 "yacc_sql.y"
       { (yyval.orderOp) = ORDER_ASC;  }
#line 3126 "yacc_sql.cpp"
    break;

  case 135: /* order_op: %empty  */
#line 967 "yacc_sql.y"
       { (yyval.orderOp) = ORDER_DEFAULT; }
#line 3132 "yacc_sql.cpp"
    break;

  case 136: /* where: %empty  */
#line 973 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3140 "yacc_sql.cpp"
    break;

  case 137: /* where: WHERE condition_list  */
#line 977 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 3148 "yacc_sql.cpp"
    break;

  case 138: /* condition_list: %empty  */
#line 983 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3156 "yacc_sql.cpp"
    break;

  case 139: /* condition_list: condition  */
#line 986 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 3166 "yacc_sql.cpp"
    break;

  case 140: /* condition_list: condition AND condition_list  */
#line 991 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3176 "yacc_sql.cpp"
    break;

  case 141: /* condition_list: condition OR condition_list  */
#line 996 "yacc_sql.y"
                                  {
      (yyvsp[-2].condition)->conjunction="OR";
      (yyvsp[0].condition_list)[0][0].conjunction="OR";
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3188 "yacc_sql.cpp"
    break;

  case 142: /* condition: arith_expr comp_op value  */
#line 1005 "yacc_sql.y"
                              {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].value);
    }
#line 3202 "yacc_sql.cpp"
    break;

  case 143: /* condition: arith_expr comp_op rel_attr  */
#line 1014 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].rel_attr);
    }
#line 3216 "yacc_sql.cpp"
    break;

  case 144: /* condition: value comp_op arith_expr  */
#line 1023 "yacc_sql.y"
                               {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 0;
        (yyval.condition)->left_value = *(yyvsp[-2].value);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].value);
    }
#line 3230 "yacc_sql.cpp"
    break;

  case 145: /* condition: rel_attr comp_op arith_expr  */
#line 1032 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 1;
        (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].rel_attr);
    }
#line 3244 "yacc_sql.cpp"
    break;

  case 146: /* condition: arith_expr comp_op arith_expr  */
#line 1041 "yacc_sql.y"
                                    {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
    }
#line 3257 "yacc_sql.cpp"
    break;

  case 147: /* condition: rel_attr comp_op value  */
#line 1049 "yacc_sql.y"
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
#line 3272 "yacc_sql.cpp"
    break;

  case 148: /* condition: value comp_op value  */
#line 1059 "yacc_sql.y"
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
#line 3287 "yacc_sql.cpp"
    break;

  case 149: /* condition: rel_attr comp_op rel_attr  */
#line 1069 "yacc_sql.y"
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
#line 3302 "yacc_sql.cpp"
    break;

  case 150: /* condition: value comp_op rel_attr  */
#line 1079 "yacc_sql.y"
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
#line 3317 "yacc_sql.cpp"
    break;

  case 151: /* condition: rel_attr comp_op SUB_QUERY  */
#line 1089 "yacc_sql.y"
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
#line 3332 "yacc_sql.cpp"
    break;

  case 152: /* condition: SUB_QUERY comp_op rel_attr  */
#line 1099 "yacc_sql.y"
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
#line 3347 "yacc_sql.cpp"
    break;

  case 153: /* condition: SUB_QUERY comp_op SUB_QUERY  */
#line 1109 "yacc_sql.y"
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
#line 3362 "yacc_sql.cpp"
    break;

  case 154: /* condition: value comp_op LBRACE value value_list RBRACE  */
#line 1119 "yacc_sql.y"
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
#line 3382 "yacc_sql.cpp"
    break;

  case 155: /* condition: rel_attr comp_op LBRACE value value_list RBRACE  */
#line 1134 "yacc_sql.y"
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
#line 3402 "yacc_sql.cpp"
    break;

  case 156: /* condition: SUB_QUERY comp_op LBRACE value value_list RBRACE  */
#line 1149 "yacc_sql.y"
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
#line 3422 "yacc_sql.cpp"
    break;

  case 157: /* condition: LBRACE value value_list RBRACE comp_op value  */
#line 1164 "yacc_sql.y"
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
#line 3442 "yacc_sql.cpp"
    break;

  case 158: /* condition: LBRACE value value_list RBRACE comp_op rel_attr  */
#line 1179 "yacc_sql.y"
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
#line 3462 "yacc_sql.cpp"
    break;

  case 159: /* condition: LBRACE value value_list RBRACE comp_op SUB_QUERY  */
#line 1194 "yacc_sql.y"
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
#line 3482 "yacc_sql.cpp"
    break;

  case 160: /* condition: LBRACE value value_list RBRACE comp_op LBRACE value value_list RBRACE  */
#line 1209 "yacc_sql.y"
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
#line 3507 "yacc_sql.cpp"
    break;

  case 161: /* condition: aggr_expr comp_op value  */
#line 1229 "yacc_sql.y"
                              {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;     
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].value);
    }
#line 3521 "yacc_sql.cpp"
    break;

  case 162: /* condition: aggr_expr comp_op rel_attr  */
#line 1238 "yacc_sql.y"
                                 {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;     
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].rel_attr);
    }
#line 3535 "yacc_sql.cpp"
    break;

  case 163: /* condition: aggr_expr comp_op aggr_expr  */
#line 1247 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 4;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);  
    }
#line 3548 "yacc_sql.cpp"
    break;

  case 164: /* condition: value is_null_choice  */
#line 1255 "yacc_sql.y"
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
#line 3565 "yacc_sql.cpp"
    break;

  case 165: /* condition: rel_attr is_null_choice  */
#line 1267 "yacc_sql.y"
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
#line 3582 "yacc_sql.cpp"
    break;

  case 166: /* is_null_choice: IS NULL_KY  */
#line 1282 "yacc_sql.y"
                 { (yyval.comp) =  OP_ISNULL; }
#line 3588 "yacc_sql.cpp"
    break;

  case 167: /* is_null_choice: IS NOT NULL_KY  */
#line 1283 "yacc_sql.y"
                     { (yyval.comp) = OP_ISNOTNULL; }
#line 3594 "yacc_sql.cpp"
    break;

  case 168: /* comp_op: EQ  */
#line 1287 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3600 "yacc_sql.cpp"
    break;

  case 169: /* comp_op: LT  */
#line 1288 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3606 "yacc_sql.cpp"
    break;

  case 170: /* comp_op: GT  */
#line 1289 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3612 "yacc_sql.cpp"
    break;

  case 171: /* comp_op: LE  */
#line 1290 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3618 "yacc_sql.cpp"
    break;

  case 172: /* comp_op: GE  */
#line 1291 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3624 "yacc_sql.cpp"
    break;

  case 173: /* comp_op: NE  */
#line 1292 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3630 "yacc_sql.cpp"
    break;

  case 174: /* comp_op: LIKE  */
#line 1293 "yacc_sql.y"
           { (yyval.comp) = CLIKE; }
#line 3636 "yacc_sql.cpp"
    break;

  case 175: /* comp_op: NOT LIKE  */
#line 1294 "yacc_sql.y"
               { (yyval.comp) = CNLIKE; }
#line 3642 "yacc_sql.cpp"
    break;

  case 176: /* comp_op: IN  */
#line 1295 "yacc_sql.y"
         { (yyval.comp) = IN_LIST; }
#line 3648 "yacc_sql.cpp"
    break;

  case 177: /* comp_op: NOT IN  */
#line 1296 "yacc_sql.y"
             { (yyval.comp) = NOTIN_LIST; }
#line 3654 "yacc_sql.cpp"
    break;

  case 178: /* comp_op: EXIST  */
#line 1297 "yacc_sql.y"
            { (yyval.comp) = EXIST_LIST; }
#line 3660 "yacc_sql.cpp"
    break;

  case 179: /* comp_op: NOT EXIST  */
#line 1298 "yacc_sql.y"
                { (yyval.comp) = NOTEXIST_LIST; }
#line 3666 "yacc_sql.cpp"
    break;

  case 180: /* func_op: I2_DISTANCE_T  */
#line 1302 "yacc_sql.y"
                    { (yyval.func) = I2_DISTANCE; }
#line 3672 "yacc_sql.cpp"
    break;

  case 181: /* func_op: COSINE_DISTANCE_T  */
#line 1303 "yacc_sql.y"
                        { (yyval.func) = COSINE_DISTANCE; }
#line 3678 "yacc_sql.cpp"
    break;

  case 182: /* func_op: INNER_PRODUCT_T  */
#line 1304 "yacc_sql.y"
                      { (yyval.func) = INNER_PRODUCT; }
#line 3684 "yacc_sql.cpp"
    break;

  case 183: /* group_by: %empty  */
#line 1308 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 3692 "yacc_sql.cpp"
    break;

  case 184: /* group_by: GROUP BY expression_list  */
#line 1312 "yacc_sql.y"
          {
        (yyval.expression_list) = (yyvsp[0].expression_list);
	  }
#line 3700 "yacc_sql.cpp"
    break;

  case 185: /* having: %empty  */
#line 1318 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3708 "yacc_sql.cpp"
    break;

  case 186: /* having: HAVING condition_list  */
#line 1322 "yacc_sql.y"
    {
      (yyval.condition_list) = (yyvsp[0].condition_list);
    }
#line 3716 "yacc_sql.cpp"
    break;

  case 187: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1329 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3730 "yacc_sql.cpp"
    break;

  case 188: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1342 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3739 "yacc_sql.cpp"
    break;

  case 189: /* set_variable_stmt: SET ID EQ value  */
#line 1350 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3751 "yacc_sql.cpp"
    break;


#line 3755 "yacc_sql.cpp"

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

#line 1362 "yacc_sql.y"

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
