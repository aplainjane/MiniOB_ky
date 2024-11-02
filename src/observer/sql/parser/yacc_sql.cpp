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
  YYSYMBOL_TABLE = 8,                      /* TABLE  */
  YYSYMBOL_TABLES = 9,                     /* TABLES  */
  YYSYMBOL_UNIQUE = 10,                    /* UNIQUE  */
  YYSYMBOL_INDEX = 11,                     /* INDEX  */
  YYSYMBOL_CALC = 12,                      /* CALC  */
  YYSYMBOL_SELECT = 13,                    /* SELECT  */
  YYSYMBOL_DESC = 14,                      /* DESC  */
  YYSYMBOL_SHOW = 15,                      /* SHOW  */
  YYSYMBOL_SYNC = 16,                      /* SYNC  */
  YYSYMBOL_INSERT = 17,                    /* INSERT  */
  YYSYMBOL_DELETE = 18,                    /* DELETE  */
  YYSYMBOL_UPDATE = 19,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 20,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 21,                    /* RBRACE  */
  YYSYMBOL_COMMA = 22,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 23,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 24,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 25,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 26,                     /* INT_T  */
  YYSYMBOL_STRING_T = 27,                  /* STRING_T  */
  YYSYMBOL_DATE_T = 28,                    /* DATE_T  */
  YYSYMBOL_TEXT_T = 29,                    /* TEXT_T  */
  YYSYMBOL_FLOAT_T = 30,                   /* FLOAT_T  */
  YYSYMBOL_VECTOR_T = 31,                  /* VECTOR_T  */
  YYSYMBOL_HELP = 32,                      /* HELP  */
  YYSYMBOL_EXIT = 33,                      /* EXIT  */
  YYSYMBOL_DOT = 34,                       /* DOT  */
  YYSYMBOL_INTO = 35,                      /* INTO  */
  YYSYMBOL_VALUES = 36,                    /* VALUES  */
  YYSYMBOL_FROM = 37,                      /* FROM  */
  YYSYMBOL_WHERE = 38,                     /* WHERE  */
  YYSYMBOL_HAVING = 39,                    /* HAVING  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_SET = 41,                       /* SET  */
  YYSYMBOL_ON = 42,                        /* ON  */
  YYSYMBOL_LOAD = 43,                      /* LOAD  */
  YYSYMBOL_DATA = 44,                      /* DATA  */
  YYSYMBOL_INFILE = 45,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 46,                   /* EXPLAIN  */
  YYSYMBOL_STORAGE = 47,                   /* STORAGE  */
  YYSYMBOL_FORMAT = 48,                    /* FORMAT  */
  YYSYMBOL_NOT = 49,                       /* NOT  */
  YYSYMBOL_LIKE = 50,                      /* LIKE  */
  YYSYMBOL_IN = 51,                        /* IN  */
  YYSYMBOL_IS = 52,                        /* IS  */
  YYSYMBOL_EXIST = 53,                     /* EXIST  */
  YYSYMBOL_NULL_KY = 54,                   /* NULL_KY  */
  YYSYMBOL_INNER = 55,                     /* INNER  */
  YYSYMBOL_JOIN = 56,                      /* JOIN  */
  YYSYMBOL_EQ = 57,                        /* EQ  */
  YYSYMBOL_LT = 58,                        /* LT  */
  YYSYMBOL_GT = 59,                        /* GT  */
  YYSYMBOL_LE = 60,                        /* LE  */
  YYSYMBOL_GE = 61,                        /* GE  */
  YYSYMBOL_NE = 62,                        /* NE  */
  YYSYMBOL_I2_DISTANCE_T = 63,             /* I2_DISTANCE_T  */
  YYSYMBOL_COSINE_DISTANCE_T = 64,         /* COSINE_DISTANCE_T  */
  YYSYMBOL_INNER_PRODUCT_T = 65,           /* INNER_PRODUCT_T  */
  YYSYMBOL_SUM = 66,                       /* SUM  */
  YYSYMBOL_AVG = 67,                       /* AVG  */
  YYSYMBOL_COUNT = 68,                     /* COUNT  */
  YYSYMBOL_MAX = 69,                       /* MAX  */
  YYSYMBOL_MIN = 70,                       /* MIN  */
  YYSYMBOL_NUMBER = 71,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 72,                     /* FLOAT  */
  YYSYMBOL_ID = 73,                        /* ID  */
  YYSYMBOL_SSS = 74,                       /* SSS  */
  YYSYMBOL_SUB_QUERY = 75,                 /* SUB_QUERY  */
  YYSYMBOL_VECTOR_LIST = 76,               /* VECTOR_LIST  */
  YYSYMBOL_77_ = 77,                       /* '+'  */
  YYSYMBOL_78_ = 78,                       /* '-'  */
  YYSYMBOL_79_ = 79,                       /* '*'  */
  YYSYMBOL_80_ = 80,                       /* '/'  */
  YYSYMBOL_UMINUS = 81,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 82,                  /* $accept  */
  YYSYMBOL_commands = 83,                  /* commands  */
  YYSYMBOL_command_wrapper = 84,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 85,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 86,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 87,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 88,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 89,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 90,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 91,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 92,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 93,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 94,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 95,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 96,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 97,             /* attr_def_list  */
  YYSYMBOL_attr_def = 98,                  /* attr_def  */
  YYSYMBOL_isnull = 99,                    /* isnull  */
  YYSYMBOL_number = 100,                   /* number  */
  YYSYMBOL_type = 101,                     /* type  */
  YYSYMBOL_insert_stmt = 102,              /* insert_stmt  */
  YYSYMBOL_value_list = 103,               /* value_list  */
  YYSYMBOL_value = 104,                    /* value  */
  YYSYMBOL_storage_format = 105,           /* storage_format  */
  YYSYMBOL_delete_stmt = 106,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 107,              /* update_stmt  */
  YYSYMBOL_set_clause_list = 108,          /* set_clause_list  */
  YYSYMBOL_set_clause = 109,               /* set_clause  */
  YYSYMBOL_select_stmt = 110,              /* select_stmt  */
  YYSYMBOL_calc_stmt = 111,                /* calc_stmt  */
  YYSYMBOL_expression_list = 112,          /* expression_list  */
  YYSYMBOL_expression = 113,               /* expression  */
  YYSYMBOL_simple_expression = 114,        /* simple_expression  */
  YYSYMBOL_arith_expr = 115,               /* arith_expr  */
  YYSYMBOL_aggr_expr = 116,                /* aggr_expr  */
  YYSYMBOL_rel_attr = 117,                 /* rel_attr  */
  YYSYMBOL_rel_list = 118,                 /* rel_list  */
  YYSYMBOL_join_list = 119,                /* join_list  */
  YYSYMBOL_where = 120,                    /* where  */
  YYSYMBOL_condition_list = 121,           /* condition_list  */
  YYSYMBOL_condition = 122,                /* condition  */
  YYSYMBOL_is_null_choice = 123,           /* is_null_choice  */
  YYSYMBOL_comp_op = 124,                  /* comp_op  */
  YYSYMBOL_func_op = 125,                  /* func_op  */
  YYSYMBOL_group_by = 126,                 /* group_by  */
  YYSYMBOL_having = 127,                   /* having  */
  YYSYMBOL_load_data_stmt = 128,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 129,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 130,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 131             /* opt_semicolon  */
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
#define YYLAST   743

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  349

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   332


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
       2,     2,    79,    77,     2,    78,     2,    80,     2,     2,
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
      75,    76,    81
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   227,   227,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   258,   264,   269,   275,   281,   287,   293,
     300,   306,   314,   333,   355,   365,   397,   400,   413,   422,
     435,   438,   442,   449,   452,   453,   454,   455,   456,   457,
     460,   477,   480,   491,   495,   499,   505,   511,   517,   520,
     527,   539,   569,   575,   585,   592,   605,   641,   649,   654,
     665,   669,   672,   675,   678,   681,   686,   692,   695,   698,
     701,   706,   712,   717,   725,   728,   731,   734,   737,   740,
     743,   746,   749,   752,   755,   758,   761,   764,   767,   770,
     773,   776,   779,   782,   785,   788,   791,   794,   797,   800,
     803,   808,   811,   814,   817,   820,   823,   829,   835,   841,
     847,   856,   861,   872,   875,   888,   891,   894,   916,   920,
     926,   929,   934,   942,   951,   960,   969,   978,   986,   996,
    1006,  1016,  1026,  1036,  1046,  1056,  1071,  1086,  1101,  1116,
    1131,  1146,  1166,  1175,  1184,  1192,  1204,  1219,  1220,  1224,
    1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,
    1235,  1239,  1240,  1241,  1245,  1248,  1255,  1258,  1265,  1278,
    1286,  1296,  1297
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
  "CREATE", "DROP", "GROUP", "TABLE", "TABLES", "UNIQUE", "INDEX", "CALC",
  "SELECT", "DESC", "SHOW", "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE",
  "RBRACE", "COMMA", "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T",
  "STRING_T", "DATE_T", "TEXT_T", "FLOAT_T", "VECTOR_T", "HELP", "EXIT",
  "DOT", "INTO", "VALUES", "FROM", "WHERE", "HAVING", "AND", "SET", "ON",
  "LOAD", "DATA", "INFILE", "EXPLAIN", "STORAGE", "FORMAT", "NOT", "LIKE",
  "IN", "IS", "EXIST", "NULL_KY", "INNER", "JOIN", "EQ", "LT", "GT", "LE",
  "GE", "NE", "I2_DISTANCE_T", "COSINE_DISTANCE_T", "INNER_PRODUCT_T",
  "SUM", "AVG", "COUNT", "MAX", "MIN", "NUMBER", "FLOAT", "ID", "SSS",
  "SUB_QUERY", "VECTOR_LIST", "'+'", "'-'", "'*'", "'/'", "UMINUS",
  "$accept", "commands", "command_wrapper", "exit_stmt", "help_stmt",
  "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "show_tables_stmt", "desc_table_stmt",
  "create_index_stmt", "drop_index_stmt", "create_table_stmt",
  "attr_def_list", "attr_def", "isnull", "number", "type", "insert_stmt",
  "value_list", "value", "storage_format", "delete_stmt", "update_stmt",
  "set_clause_list", "set_clause", "select_stmt", "calc_stmt",
  "expression_list", "expression", "simple_expression", "arith_expr",
  "aggr_expr", "rel_attr", "rel_list", "join_list", "where",
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

#define YYPACT_NINF (-205)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     672,   223,    33,   436,   436,   -59,    17,  -205,   -11,    19,
     -19,  -205,  -205,  -205,  -205,  -205,    10,    46,   672,   107,
      34,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,    27,    52,    49,    72,    81,   436,  -205,  -205,  -205,
    -205,   142,   144,   146,   168,   170,  -205,  -205,   163,  -205,
    -205,   436,  -205,  -205,  -205,   245,  -205,  -205,   190,   179,
    -205,  -205,   157,   164,   198,   183,   201,  -205,  -205,  -205,
    -205,   229,   185,   217,  -205,   219,   -13,   232,   295,   316,
     355,   376,   191,  -205,   436,   436,   436,   436,   436,   415,
     193,   227,   231,   197,   399,   199,   203,   230,   205,   206,
    -205,  -205,   260,  -205,   261,  -205,   264,  -205,   268,  -205,
     286,  -205,  -205,    63,    63,  -205,  -205,  -205,   288,   266,
     292,   457,  -205,   262,   125,  -205,  -205,   283,    22,   298,
     253,   307,  -205,  -205,  -205,  -205,  -205,  -205,  -205,   255,
     -10,   399,   493,   134,   493,   681,    73,   649,   134,   681,
    -205,   290,   339,   197,  -205,   324,  -205,  -205,  -205,  -205,
    -205,  -205,    -7,   203,   312,   314,   271,   266,   -10,   273,
     231,   325,   493,   139,    -9,  -205,    66,  -205,  -205,  -205,
    -205,  -205,  -205,  -205,  -205,  -205,    37,  -205,   100,   135,
     -34,  -205,   501,   514,   522,   530,   543,   558,   569,   579,
     590,   493,   -38,  -205,   267,   457,  -205,  -205,  -205,   275,
     279,   297,  -205,  -205,   298,   308,   281,   266,  -205,  -205,
     315,   365,   399,   356,   357,  -205,  -205,  -205,  -205,   399,
    -205,  -205,   337,  -205,   493,   127,   148,   321,   493,   100,
     135,   493,   100,   135,   493,  -205,  -205,   493,  -205,  -205,
     493,   100,   135,   493,   100,   135,   493,  -205,  -205,   493,
    -205,  -205,   127,   148,   321,  -205,  -205,  -205,   493,  -205,
     127,   148,   321,  -205,  -205,  -205,   381,  -205,  -205,   358,
    -205,   266,   382,   457,   400,   366,   325,  -205,   134,   325,
    -205,   139,    -4,     0,    60,    78,   123,   165,   177,   214,
     139,   -31,   350,   387,  -205,   -10,   436,   457,  -205,  -205,
     600,   391,   395,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,   396,  -205,   359,  -205,  -205,  -205,  -205,   399,  -205,
    -205,  -205,  -205,  -205,  -205,  -205,   325,   416,  -205
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,    24,    23,     0,     0,     0,     0,
     181,    22,    21,    14,    15,    16,    17,     9,    10,    11,
      12,    13,     8,     5,     7,     6,     4,     3,    18,    19,
      20,     0,     0,     0,     0,     0,     0,    57,   171,   172,
     173,     0,     0,     0,     0,     0,    53,    54,   121,    55,
      56,     0,    77,    75,    67,    68,    79,    76,     0,     0,
      31,    30,     0,     0,     0,     0,     0,   179,     1,   182,
       2,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,     0,
      70,   116,     0,   117,     0,   120,     0,   119,     0,   118,
       0,   122,    69,    71,    72,    73,    74,    81,     0,   123,
       0,   130,    60,     0,   128,    62,   180,     0,     0,    36,
       0,     0,    34,   111,   112,   115,   113,   114,    80,     0,
     125,     0,     0,     0,     0,    82,     0,     0,     0,    83,
     129,   131,     0,     0,    61,     0,    44,    45,    48,    49,
      46,    47,    40,     0,     0,     0,     0,   123,   125,     0,
     128,    51,     0,    82,     0,    83,     0,   165,   167,   169,
     159,   160,   161,   162,   163,   164,     0,    82,    94,    93,
       0,   155,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   156,     0,   130,    65,    64,    63,     0,
       0,     0,    41,    39,    36,    58,     0,   123,   124,   126,
       0,   174,     0,     0,     0,    84,   166,   168,   170,     0,
     144,   143,     0,   157,     0,   139,   135,   141,     0,   107,
      99,     0,   108,   100,     0,   109,   101,     0,   110,   102,
       0,    95,   103,     0,    96,   104,     0,    97,   105,     0,
      98,   106,   133,   137,   134,   152,   154,   153,     0,   142,
     138,   136,   140,   132,   178,    43,     0,    42,    37,     0,
      35,   123,     0,   130,     0,   176,    51,    50,     0,    51,
     158,    82,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    40,     0,     0,    32,   125,     0,   130,    66,    52,
       0,     0,     0,    89,    90,    91,    92,    85,    86,    87,
      88,     0,    38,     0,    33,   127,   175,   177,     0,   150,
     148,   149,   147,   145,   146,    59,    51,     0,   151
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -205,  -205,   420,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,  -205,  -205,  -205,  -205,   233,   278,   147,  -205,  -205,
    -205,  -181,    -3,  -205,  -205,  -205,  -205,   296,  -205,  -205,
      15,   -36,    14,   -33,  -104,    36,  -155,  -174,  -125,  -204,
    -205,   301,  -152,  -205,  -205,  -205,  -205,  -205,  -205,  -205
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   174,   139,   223,   286,   172,
      33,   233,   197,   290,    34,    35,   134,   135,    36,    37,
      64,    65,   156,   184,    66,   185,   150,   180,   132,   160,
     161,   201,   196,    68,   295,   318,    38,    39,    40,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    63,   234,   202,   229,   211,   212,   214,   110,   164,
      86,   283,   235,   220,    70,   242,    47,   323,   221,    69,
     243,   324,   228,   222,    72,    93,    71,   158,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    79,    60,    67,
      67,    44,   221,    63,    45,   178,   179,   222,   166,   167,
     168,   169,   170,   171,    74,   231,    73,   239,    63,   123,
     124,   125,   126,    82,    95,    96,    97,    98,   207,   208,
     209,   210,   292,   203,   204,   205,   206,   203,   204,   205,
     206,   325,    67,    75,    63,    63,    63,    63,    63,   315,
      76,    63,    63,    63,    63,    63,    63,    67,   157,   326,
      81,   136,   112,   114,   116,   118,   120,    78,   276,   122,
      58,   158,   240,   337,   128,   319,   236,   237,   321,   238,
     322,   199,    83,    67,    67,    67,    67,    67,   155,   331,
      67,    67,    67,    67,    67,    67,   313,   203,   204,   205,
     206,   335,    97,    98,   327,    84,   320,   163,   181,   183,
     203,   204,   205,   206,    85,   203,   204,   205,   206,   217,
     -51,   232,    87,   131,    88,   347,    89,   159,   198,   246,
     250,   253,   256,   259,   262,   265,   268,   271,   273,   205,
     206,   281,   157,   186,   187,   188,   328,   189,    90,   158,
      91,   190,   191,   192,   193,   194,   195,    92,   329,   245,
     203,   204,   205,   206,   -82,   -82,   -82,   -82,   272,   275,
      99,   280,   155,   158,   209,   210,   100,   249,   252,   255,
     258,   261,   264,   267,   270,   207,   208,   209,   210,   296,
     101,    41,   241,    42,    43,   330,   299,   102,   247,   103,
     104,   301,   203,   204,   205,   206,   105,   274,   277,   106,
     282,   159,    46,   111,   203,   204,   205,   206,   107,   108,
     157,   109,   302,   130,   121,   303,   129,    94,   304,   131,
     133,   305,   140,   137,   306,   310,   138,   307,   141,   142,
     308,   143,   144,   309,   157,   145,    47,   278,   149,   146,
     155,   203,   204,   205,   206,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   147,    60,   148,
      61,    62,   151,    63,   155,    46,   113,   340,   165,   162,
     173,    47,    95,    96,    97,    98,   175,   176,   177,   159,
     215,   336,   219,   225,   226,   346,    46,   115,    56,    57,
      58,    59,   279,    60,   227,   154,   230,   232,   284,    47,
     285,   287,    67,   159,   291,   289,   341,   293,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      47,    60,   294,    61,    62,    46,   117,   297,   298,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,   300,    60,    47,    61,    62,    46,   119,   -83,   -83,
     -83,   -83,   311,   314,   316,   317,   312,   333,   334,    47,
      56,    57,   342,    59,   216,    60,   343,   344,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      47,    60,   345,    61,    62,    46,   127,   348,    77,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,   224,    60,    47,    61,    62,    46,   288,   332,   218,
     213,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      56,    57,     0,    59,     0,    60,     0,   152,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      47,    60,     0,    61,    62,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    47,    60,   182,    61,    62,     0,     0,     0,     0,
       0,   244,     0,    51,    52,    53,    54,    55,    56,    57,
      58,    59,   153,    60,   248,   154,     0,     0,     0,     0,
       0,     0,   251,     0,     0,     0,     0,    47,     0,     0,
     254,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,   257,    56,    57,    58,    59,    47,    60,
       0,   154,    56,    57,    58,    59,    47,    60,   260,   154,
       0,     0,     0,     0,    47,    56,    57,    58,    59,   263,
      60,     0,   154,    56,    57,    58,    59,    47,    60,   266,
     154,    56,    57,    58,    59,     0,    60,     0,   154,     0,
     269,     0,    47,     0,    56,    57,    58,    59,     0,    60,
     338,   154,     0,    47,     0,     0,     0,     0,     0,    56,
      57,    58,    59,    47,    60,     0,   154,     0,     0,     0,
      56,    57,    58,    59,    47,    60,     0,   154,     0,     0,
      56,    57,    58,    59,    47,    60,     0,   154,     0,     0,
       0,    56,    57,    58,    59,     0,    60,     0,   154,     0,
       0,    56,    57,    58,    59,   339,    60,     1,     2,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,   186,   187,
     188,     0,   189,     0,    14,    15,   190,   191,   192,   193,
     194,   195,     0,    16,     0,    17,     0,     0,    18,     0,
       0,     0,     0,     0,     0,     0,   207,   208,   209,   210,
     186,   187,   188,   200,   189,     0,     0,     0,   190,   191,
     192,   193,   194,   195
};

static const yytype_int16 yycheck[] =
{
       3,     4,   183,   155,   178,   157,   158,   159,    21,   134,
      46,   215,    21,    20,    73,    49,    54,    21,    49,     4,
      54,    21,   177,    54,    35,    61,     9,   131,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     3,    76,     3,
       4,     8,    49,    46,    11,    55,    56,    54,    26,    27,
      28,    29,    30,    31,    73,   180,    37,    20,    61,    95,
      96,    97,    98,    11,    77,    78,    79,    80,    77,    78,
      79,    80,   227,    77,    78,    79,    80,    77,    78,    79,
      80,    21,    46,    73,    87,    88,    89,    90,    91,   293,
      44,    94,    95,    96,    97,    98,    99,    61,   131,    21,
      73,   104,    87,    88,    89,    90,    91,     0,   212,    94,
      73,   215,    75,   317,    99,   296,    50,    51,   299,    53,
     301,   154,    73,    87,    88,    89,    90,    91,   131,   310,
      94,    95,    96,    97,    98,    99,   291,    77,    78,    79,
      80,   315,    79,    80,    21,    73,   298,    22,   151,   152,
      77,    78,    79,    80,    73,    77,    78,    79,    80,   162,
      21,    22,    20,    38,    20,   346,    20,   131,   154,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    79,
      80,   214,   215,    49,    50,    51,    21,    53,    20,   293,
      20,    57,    58,    59,    60,    61,    62,    34,    21,   202,
      77,    78,    79,    80,    77,    78,    79,    80,   211,   212,
      20,   214,   215,   317,    79,    80,    37,   203,   204,   205,
     206,   207,   208,   209,   210,    77,    78,    79,    80,   232,
      73,     8,   196,    10,    11,    21,   239,    73,   202,    41,
      57,   244,    77,    78,    79,    80,    45,   211,   212,    20,
     214,   215,    20,    21,    77,    78,    79,    80,    73,    42,
     293,    42,   248,    36,    73,   251,    73,    22,   254,    38,
      73,   257,    42,    74,   260,   278,    73,   263,    73,    73,
     266,    21,    21,   269,   317,    21,    54,    20,    22,    21,
     293,    77,    78,    79,    80,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    21,    76,    21,
      78,    79,    20,   316,   317,    20,    21,   320,    35,    57,
      22,    54,    77,    78,    79,    80,    73,    20,    73,   293,
      40,   316,     8,    21,    20,   338,    20,    21,    71,    72,
      73,    74,    75,    76,    73,    78,    73,    22,    73,    54,
      71,    54,   316,   317,    73,    47,   320,    42,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      54,    76,     7,    78,    79,    20,    21,    21,    21,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    54,    76,    54,    78,    79,    20,    21,    77,    78,
      79,    80,    21,    21,     4,    39,    48,    57,    21,    54,
      71,    72,    21,    74,    75,    76,    21,    21,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      54,    76,    73,    78,    79,    20,    21,    21,    18,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   173,    76,    54,    78,    79,    20,   224,   311,   163,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      71,    72,    -1,    74,    -1,    76,    -1,    20,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      54,    76,    -1,    78,    79,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    54,    76,    20,    78,    79,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    20,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    71,    72,    73,    74,    54,    76,
      -1,    78,    71,    72,    73,    74,    54,    76,    20,    78,
      -1,    -1,    -1,    -1,    54,    71,    72,    73,    74,    20,
      76,    -1,    78,    71,    72,    73,    74,    54,    76,    20,
      78,    71,    72,    73,    74,    -1,    76,    -1,    78,    -1,
      20,    -1,    54,    -1,    71,    72,    73,    74,    -1,    76,
      20,    78,    -1,    54,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    54,    76,    -1,    78,    -1,    -1,    -1,
      71,    72,    73,    74,    54,    76,    -1,    78,    -1,    -1,
      71,    72,    73,    74,    54,    76,    -1,    78,    -1,    -1,
      -1,    71,    72,    73,    74,    -1,    76,    -1,    78,    -1,
      -1,    71,    72,    73,    74,    75,    76,     5,     6,    -1,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    23,    24,    25,    49,    50,
      51,    -1,    53,    -1,    32,    33,    57,    58,    59,    60,
      61,    62,    -1,    41,    -1,    43,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    12,    13,    14,    15,    16,    17,    18,
      19,    23,    24,    25,    32,    33,    41,    43,    46,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,   102,   106,   107,   110,   111,   128,   129,
     130,     8,    10,    11,     8,    11,    20,    54,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      76,    78,    79,   104,   112,   113,   116,   117,   125,   112,
      73,     9,    35,    37,    73,    73,    44,    84,     0,     3,
     131,    73,    11,    73,    73,    73,   113,    20,    20,    20,
      20,    20,    34,   113,    22,    77,    78,    79,    80,    20,
      37,    73,    73,    41,    57,    45,    20,    73,    42,    42,
      21,    21,   112,    21,   112,    21,   112,    21,   112,    21,
     112,    73,   112,   113,   113,   113,   113,    21,   112,    73,
      36,    38,   120,    73,   108,   109,   104,    74,    73,    98,
      42,    73,    73,    21,    21,    21,    21,    21,    21,    22,
     118,    20,    20,    75,    78,   104,   114,   115,   116,   117,
     121,   122,    57,    22,   120,    35,    26,    27,    28,    29,
      30,    31,   101,    22,    97,    73,    20,    73,    55,    56,
     119,   104,    20,   104,   115,   117,    49,    50,    51,    53,
      57,    58,    59,    60,    61,    62,   124,   104,   114,   115,
      52,   123,   124,    77,    78,    79,    80,    77,    78,    79,
      80,   124,   124,   123,   124,    40,    75,   104,   109,     8,
      20,    49,    54,    99,    98,    21,    20,    73,   118,   119,
      73,   120,    22,   103,   103,    21,    50,    51,    53,    20,
      75,   117,    49,    54,    20,   104,   115,   117,    20,   114,
     115,    20,   114,   115,    20,   114,   115,    20,   114,   115,
      20,   114,   115,    20,   114,   115,    20,   114,   115,    20,
     114,   115,   104,   115,   117,   104,   116,   117,    20,    75,
     104,   115,   117,   121,    73,    71,   100,    54,    97,    47,
     105,    73,   118,    42,     7,   126,   104,    21,    21,   104,
      54,   104,   114,   114,   114,   114,   114,   114,   114,   114,
     104,    21,    48,   118,    21,   121,     4,    39,   127,   103,
     124,   103,   103,    21,    21,    21,    21,    21,    21,    21,
      21,   103,    99,    57,    21,   119,   112,   121,    20,    75,
     104,   117,    21,    21,    21,    73,   104,   103,    21
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    94,    95,    96,    97,    97,    98,    98,
      99,    99,    99,   100,   101,   101,   101,   101,   101,   101,
     102,   103,   103,   104,   104,   104,   104,   104,   105,   105,
     106,   107,   108,   108,   109,   109,   110,   111,   112,   112,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   119,   120,   120,
     121,   121,   121,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   123,   123,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   125,   125,   125,   126,   126,   127,   127,   128,   129,
     130,   131,   131
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
       4,     5,     1,     3,     3,     3,     9,     2,     1,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     2,     1,
       4,     3,     1,     1,     3,     5,     5,     5,     5,     5,
       5,     5,     5,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     4,     4,     4,     4,     3,     3,     3,     3,
       3,     1,     3,     0,     3,     0,     2,     5,     0,     2,
       0,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     6,     6,     6,     6,     6,
       6,     9,     3,     3,     3,     2,     2,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       2,     1,     1,     1,     0,     3,     0,     2,     7,     2,
       4,     0,     1
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
#line 228 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1975 "yacc_sql.cpp"
    break;

  case 23: /* exit_stmt: EXIT  */
#line 258 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1984 "yacc_sql.cpp"
    break;

  case 24: /* help_stmt: HELP  */
#line 264 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1992 "yacc_sql.cpp"
    break;

  case 25: /* sync_stmt: SYNC  */
#line 269 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 2000 "yacc_sql.cpp"
    break;

  case 26: /* begin_stmt: TRX_BEGIN  */
#line 275 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 2008 "yacc_sql.cpp"
    break;

  case 27: /* commit_stmt: TRX_COMMIT  */
#line 281 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 2016 "yacc_sql.cpp"
    break;

  case 28: /* rollback_stmt: TRX_ROLLBACK  */
#line 287 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 2024 "yacc_sql.cpp"
    break;

  case 29: /* drop_table_stmt: DROP TABLE ID  */
#line 293 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2034 "yacc_sql.cpp"
    break;

  case 30: /* show_tables_stmt: SHOW TABLES  */
#line 300 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 2042 "yacc_sql.cpp"
    break;

  case 31: /* desc_table_stmt: DESC ID  */
#line 306 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2052 "yacc_sql.cpp"
    break;

  case 32: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID rel_list RBRACE  */
#line 315 "yacc_sql.y"
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
#line 2075 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID rel_list RBRACE  */
#line 334 "yacc_sql.y"
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
#line 2098 "yacc_sql.cpp"
    break;

  case 34: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 356 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2110 "yacc_sql.cpp"
    break;

  case 35: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format  */
#line 366 "yacc_sql.y"
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
#line 2143 "yacc_sql.cpp"
    break;

  case 36: /* attr_def_list: %empty  */
#line 397 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2151 "yacc_sql.cpp"
    break;

  case 37: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 401 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2165 "yacc_sql.cpp"
    break;

  case 38: /* attr_def: ID type LBRACE number RBRACE isnull  */
#line 414 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->isnull = (yyvsp[0].boolean);
      free((yyvsp[-5].string));
    }
#line 2178 "yacc_sql.cpp"
    break;

  case 39: /* attr_def: ID type isnull  */
#line 423 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->isnull = (yyvsp[0].boolean);
      free((yyvsp[-2].string));
    }
#line 2191 "yacc_sql.cpp"
    break;

  case 40: /* isnull: %empty  */
#line 435 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2199 "yacc_sql.cpp"
    break;

  case 41: /* isnull: NULL_KY  */
#line 439 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2207 "yacc_sql.cpp"
    break;

  case 42: /* isnull: NOT NULL_KY  */
#line 443 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2215 "yacc_sql.cpp"
    break;

  case 43: /* number: NUMBER  */
#line 449 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2221 "yacc_sql.cpp"
    break;

  case 44: /* type: INT_T  */
#line 452 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::INTS); }
#line 2227 "yacc_sql.cpp"
    break;

  case 45: /* type: STRING_T  */
#line 453 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::CHARS); }
#line 2233 "yacc_sql.cpp"
    break;

  case 46: /* type: FLOAT_T  */
#line 454 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::FLOATS); }
#line 2239 "yacc_sql.cpp"
    break;

  case 47: /* type: VECTOR_T  */
#line 455 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::VECTORS); }
#line 2245 "yacc_sql.cpp"
    break;

  case 48: /* type: DATE_T  */
#line 456 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::DATES); }
#line 2251 "yacc_sql.cpp"
    break;

  case 49: /* type: TEXT_T  */
#line 457 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::TEXTS); }
#line 2257 "yacc_sql.cpp"
    break;

  case 50: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 461 "yacc_sql.y"
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
#line 2274 "yacc_sql.cpp"
    break;

  case 51: /* value_list: %empty  */
#line 477 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2282 "yacc_sql.cpp"
    break;

  case 52: /* value_list: COMMA value value_list  */
#line 480 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2296 "yacc_sql.cpp"
    break;

  case 53: /* value: NUMBER  */
#line 491 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2305 "yacc_sql.cpp"
    break;

  case 54: /* value: FLOAT  */
#line 495 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2314 "yacc_sql.cpp"
    break;

  case 55: /* value: SSS  */
#line 499 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2325 "yacc_sql.cpp"
    break;

  case 56: /* value: VECTOR_LIST  */
#line 505 "yacc_sql.y"
                 {
      char *tmp = common::substr((yyvsp[0].string),0,strlen((yyvsp[0].string))-1);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2336 "yacc_sql.cpp"
    break;

  case 57: /* value: NULL_KY  */
#line 511 "yacc_sql.y"
              {
      (yyval.value) = new Value(NULL_VALUE, 1);
    }
#line 2344 "yacc_sql.cpp"
    break;

  case 58: /* storage_format: %empty  */
#line 517 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 2352 "yacc_sql.cpp"
    break;

  case 59: /* storage_format: STORAGE FORMAT EQ ID  */
#line 521 "yacc_sql.y"
    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2360 "yacc_sql.cpp"
    break;

  case 60: /* delete_stmt: DELETE FROM ID where  */
#line 528 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2374 "yacc_sql.cpp"
    break;

  case 61: /* update_stmt: UPDATE ID SET set_clause_list where  */
#line 540 "yacc_sql.y"
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
#line 2404 "yacc_sql.cpp"
    break;

  case 62: /* set_clause_list: set_clause  */
#line 570 "yacc_sql.y"
    {
        (yyval.set_clause_list) = new std::vector<UpdateKV>();
        (yyval.set_clause_list)->push_back(*(yyvsp[0].set_clause));
        delete (yyvsp[0].set_clause);  // 确保 $1 是 new 出来的对象
    }
#line 2414 "yacc_sql.cpp"
    break;

  case 63: /* set_clause_list: set_clause_list COMMA set_clause  */
#line 576 "yacc_sql.y"
    {
        (yyvsp[-2].set_clause_list)->push_back(*(yyvsp[0].set_clause));
        (yyval.set_clause_list) = (yyvsp[-2].set_clause_list);
        delete (yyvsp[0].set_clause);  // 确保 $3 是 new 出来的对象
    }
#line 2424 "yacc_sql.cpp"
    break;

  case 64: /* set_clause: ID EQ value  */
#line 586 "yacc_sql.y"
    {
        (yyval.set_clause) = new UpdateKV();
        (yyval.set_clause)->attr_name = strdup((yyvsp[-2].string));  // 使用 strdup 复制字符串，避免释放后使用问题
        (yyval.set_clause)->value = *(yyvsp[0].value);
        free((yyvsp[-2].string));  // 确保在拷贝完成后再释放
    }
#line 2435 "yacc_sql.cpp"
    break;

  case 65: /* set_clause: ID EQ SUB_QUERY  */
#line 593 "yacc_sql.y"
    {
      (yyval.set_clause) = new UpdateKV();
      (yyval.set_clause)->is_subquery = true;
      (yyval.set_clause)->attr_name = strdup((yyvsp[-2].string));
      (yyval.set_clause)->subquery = strdup((yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2448 "yacc_sql.cpp"
    break;

  case 66: /* select_stmt: SELECT expression_list FROM ID rel_list join_list where group_by having  */
#line 606 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-7].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[-7].expression_list));
        delete (yyvsp[-7].expression_list);
      }
      if ((yyvsp[-4].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-4].relation_list));
        delete (yyvsp[-4].relation_list);
      }
      (yyval.sql_node)->selection.relations.push_back((yyvsp[-5].string));
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      if ((yyvsp[-2].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-2].condition_list));
        delete (yyvsp[-2].condition_list);
      }
      free((yyvsp[-5].string));
      
      if ((yyvsp[-3].join_sql_node) != nullptr) {
        (yyval.sql_node)->selection.relations.insert((yyval.sql_node)->selection.relations.end(), (yyvsp[-3].join_sql_node)->relations.begin(), (yyvsp[-3].join_sql_node)->relations.end());
        (yyval.sql_node)->selection.conditions.insert((yyval.sql_node)->selection.conditions.end(), (yyvsp[-3].join_sql_node)->conditions.begin(), (yyvsp[-3].join_sql_node)->conditions.end());
        delete (yyvsp[-3].join_sql_node);
      }
      if ((yyvsp[-1].expression_list) != nullptr) {
        (yyval.sql_node)->selection.group_by.swap(*(yyvsp[-1].expression_list));
        delete (yyvsp[-1].expression_list);
      }
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->selection.having_conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
    }
#line 2486 "yacc_sql.cpp"
    break;

  case 67: /* calc_stmt: CALC expression_list  */
#line 642 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2496 "yacc_sql.cpp"
    break;

  case 68: /* expression_list: expression  */
#line 650 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2505 "yacc_sql.cpp"
    break;

  case 69: /* expression_list: expression COMMA expression_list  */
#line 655 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace((yyval.expression_list)->begin(), (yyvsp[-2].expression));
    }
#line 2518 "yacc_sql.cpp"
    break;

  case 70: /* expression: LBRACE expression RBRACE  */
#line 665 "yacc_sql.y"
                             {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2527 "yacc_sql.cpp"
    break;

  case 71: /* expression: expression '+' expression  */
#line 669 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2535 "yacc_sql.cpp"
    break;

  case 72: /* expression: expression '-' expression  */
#line 672 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2543 "yacc_sql.cpp"
    break;

  case 73: /* expression: expression '*' expression  */
#line 675 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2551 "yacc_sql.cpp"
    break;

  case 74: /* expression: expression '/' expression  */
#line 678 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2559 "yacc_sql.cpp"
    break;

  case 75: /* expression: value  */
#line 681 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2569 "yacc_sql.cpp"
    break;

  case 76: /* expression: rel_attr  */
#line 686 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2580 "yacc_sql.cpp"
    break;

  case 77: /* expression: '*'  */
#line 692 "yacc_sql.y"
          {
      (yyval.expression) = new StarExpr();
    }
#line 2588 "yacc_sql.cpp"
    break;

  case 78: /* expression: '-' expression  */
#line 695 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2596 "yacc_sql.cpp"
    break;

  case 79: /* expression: aggr_expr  */
#line 698 "yacc_sql.y"
                {
      (yyval.expression) = (yyvsp[0].expression);
    }
#line 2604 "yacc_sql.cpp"
    break;

  case 80: /* expression: func_op LBRACE expression_list RBRACE  */
#line 701 "yacc_sql.y"
                                            {
      (yyval.expression) = new FunctionExpr((FuncOp)(yyvsp[-3].func),std::move(*(yyvsp[-1].expression_list)));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[-1].expression_list);
    }
#line 2614 "yacc_sql.cpp"
    break;

  case 81: /* expression: func_op LBRACE RBRACE  */
#line 706 "yacc_sql.y"
                            {
      (yyval.expression) = new FunctionExpr((FuncOp)(yyvsp[-2].func),std::vector<std::unique_ptr<Expression>>());
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2623 "yacc_sql.cpp"
    break;

  case 82: /* simple_expression: value  */
#line 712 "yacc_sql.y"
          {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2633 "yacc_sql.cpp"
    break;

  case 83: /* simple_expression: rel_attr  */
#line 717 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2644 "yacc_sql.cpp"
    break;

  case 84: /* arith_expr: LBRACE arith_expr RBRACE  */
#line 725 "yacc_sql.y"
                             {
      (yyval.expression) = (yyvsp[-1].expression);
    }
#line 2652 "yacc_sql.cpp"
    break;

  case 85: /* arith_expr: arith_expr '+' LBRACE simple_expression RBRACE  */
#line 728 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2660 "yacc_sql.cpp"
    break;

  case 86: /* arith_expr: arith_expr '-' LBRACE simple_expression RBRACE  */
#line 731 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2668 "yacc_sql.cpp"
    break;

  case 87: /* arith_expr: arith_expr '*' LBRACE simple_expression RBRACE  */
#line 734 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2676 "yacc_sql.cpp"
    break;

  case 88: /* arith_expr: arith_expr '/' LBRACE simple_expression RBRACE  */
#line 737 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2684 "yacc_sql.cpp"
    break;

  case 89: /* arith_expr: simple_expression '+' LBRACE simple_expression RBRACE  */
#line 740 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2692 "yacc_sql.cpp"
    break;

  case 90: /* arith_expr: simple_expression '-' LBRACE simple_expression RBRACE  */
#line 743 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2700 "yacc_sql.cpp"
    break;

  case 91: /* arith_expr: simple_expression '*' LBRACE simple_expression RBRACE  */
#line 746 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2708 "yacc_sql.cpp"
    break;

  case 92: /* arith_expr: simple_expression '/' LBRACE simple_expression RBRACE  */
#line 749 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2716 "yacc_sql.cpp"
    break;

  case 93: /* arith_expr: '-' arith_expr  */
#line 752 "yacc_sql.y"
                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2724 "yacc_sql.cpp"
    break;

  case 94: /* arith_expr: '-' simple_expression  */
#line 755 "yacc_sql.y"
                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2732 "yacc_sql.cpp"
    break;

  case 95: /* arith_expr: arith_expr '+' simple_expression  */
#line 758 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2740 "yacc_sql.cpp"
    break;

  case 96: /* arith_expr: arith_expr '-' simple_expression  */
#line 761 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2748 "yacc_sql.cpp"
    break;

  case 97: /* arith_expr: arith_expr '*' simple_expression  */
#line 764 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2756 "yacc_sql.cpp"
    break;

  case 98: /* arith_expr: arith_expr '/' simple_expression  */
#line 767 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2764 "yacc_sql.cpp"
    break;

  case 99: /* arith_expr: simple_expression '+' arith_expr  */
#line 770 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2772 "yacc_sql.cpp"
    break;

  case 100: /* arith_expr: simple_expression '-' arith_expr  */
#line 773 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2780 "yacc_sql.cpp"
    break;

  case 101: /* arith_expr: simple_expression '*' arith_expr  */
#line 776 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2788 "yacc_sql.cpp"
    break;

  case 102: /* arith_expr: simple_expression '/' arith_expr  */
#line 779 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2796 "yacc_sql.cpp"
    break;

  case 103: /* arith_expr: arith_expr '+' arith_expr  */
#line 782 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2804 "yacc_sql.cpp"
    break;

  case 104: /* arith_expr: arith_expr '-' arith_expr  */
#line 785 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2812 "yacc_sql.cpp"
    break;

  case 105: /* arith_expr: arith_expr '*' arith_expr  */
#line 788 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2820 "yacc_sql.cpp"
    break;

  case 106: /* arith_expr: arith_expr '/' arith_expr  */
#line 791 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2828 "yacc_sql.cpp"
    break;

  case 107: /* arith_expr: simple_expression '+' simple_expression  */
#line 794 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2836 "yacc_sql.cpp"
    break;

  case 108: /* arith_expr: simple_expression '-' simple_expression  */
#line 797 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2844 "yacc_sql.cpp"
    break;

  case 109: /* arith_expr: simple_expression '*' simple_expression  */
#line 800 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2852 "yacc_sql.cpp"
    break;

  case 110: /* arith_expr: simple_expression '/' simple_expression  */
#line 803 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2860 "yacc_sql.cpp"
    break;

  case 111: /* aggr_expr: SUM LBRACE expression_list RBRACE  */
#line 808 "yacc_sql.y"
                                      {
      (yyval.expression) = create_aggregate_expression("SUM", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2868 "yacc_sql.cpp"
    break;

  case 112: /* aggr_expr: AVG LBRACE expression_list RBRACE  */
#line 811 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("AVG", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2876 "yacc_sql.cpp"
    break;

  case 113: /* aggr_expr: MAX LBRACE expression_list RBRACE  */
#line 814 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("MAX", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2884 "yacc_sql.cpp"
    break;

  case 114: /* aggr_expr: MIN LBRACE expression_list RBRACE  */
#line 817 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("MIN", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2892 "yacc_sql.cpp"
    break;

  case 115: /* aggr_expr: COUNT LBRACE expression_list RBRACE  */
#line 820 "yacc_sql.y"
                                          {
      (yyval.expression) = create_aggregate_expression("COUNT", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2900 "yacc_sql.cpp"
    break;

  case 116: /* aggr_expr: SUM LBRACE RBRACE  */
#line 823 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("SUM", empty, sql_string, &(yyloc));
    }
#line 2911 "yacc_sql.cpp"
    break;

  case 117: /* aggr_expr: AVG LBRACE RBRACE  */
#line 829 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("AVG", empty, sql_string, &(yyloc));
    }
#line 2922 "yacc_sql.cpp"
    break;

  case 118: /* aggr_expr: MIN LBRACE RBRACE  */
#line 835 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("MIN", empty, sql_string, &(yyloc));
    }
#line 2933 "yacc_sql.cpp"
    break;

  case 119: /* aggr_expr: MAX LBRACE RBRACE  */
#line 841 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("MAX", empty, sql_string, &(yyloc));
    }
#line 2944 "yacc_sql.cpp"
    break;

  case 120: /* aggr_expr: COUNT LBRACE RBRACE  */
#line 847 "yacc_sql.y"
                          {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("COUNT", empty, sql_string, &(yyloc));
    }
#line 2955 "yacc_sql.cpp"
    break;

  case 121: /* rel_attr: ID  */
#line 856 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2965 "yacc_sql.cpp"
    break;

  case 122: /* rel_attr: ID DOT ID  */
#line 861 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2977 "yacc_sql.cpp"
    break;

  case 123: /* rel_list: %empty  */
#line 872 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 2985 "yacc_sql.cpp"
    break;

  case 124: /* rel_list: COMMA ID rel_list  */
#line 875 "yacc_sql.y"
                        {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::string>;
      }

      (yyval.relation_list)->push_back((yyvsp[-1].string));
      free((yyvsp[-1].string));
    }
#line 3000 "yacc_sql.cpp"
    break;

  case 125: /* join_list: %empty  */
#line 888 "yacc_sql.y"
    {
      (yyval.join_sql_node) = nullptr;
    }
#line 3008 "yacc_sql.cpp"
    break;

  case 126: /* join_list: INNER join_list  */
#line 891 "yacc_sql.y"
                      {
      (yyval.join_sql_node) = (yyvsp[0].join_sql_node);
    }
#line 3016 "yacc_sql.cpp"
    break;

  case 127: /* join_list: JOIN ID ON condition_list join_list  */
#line 894 "yacc_sql.y"
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
#line 3039 "yacc_sql.cpp"
    break;

  case 128: /* where: %empty  */
#line 916 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3047 "yacc_sql.cpp"
    break;

  case 129: /* where: WHERE condition_list  */
#line 920 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 3055 "yacc_sql.cpp"
    break;

  case 130: /* condition_list: %empty  */
#line 926 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3063 "yacc_sql.cpp"
    break;

  case 131: /* condition_list: condition  */
#line 929 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 3073 "yacc_sql.cpp"
    break;

  case 132: /* condition_list: condition AND condition_list  */
#line 934 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3083 "yacc_sql.cpp"
    break;

  case 133: /* condition: arith_expr comp_op value  */
#line 942 "yacc_sql.y"
                              {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].value);
    }
#line 3097 "yacc_sql.cpp"
    break;

  case 134: /* condition: arith_expr comp_op rel_attr  */
#line 951 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].rel_attr);
    }
#line 3111 "yacc_sql.cpp"
    break;

  case 135: /* condition: value comp_op arith_expr  */
#line 960 "yacc_sql.y"
                               {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 0;
        (yyval.condition)->left_value = *(yyvsp[-2].value);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].value);
    }
#line 3125 "yacc_sql.cpp"
    break;

  case 136: /* condition: rel_attr comp_op arith_expr  */
#line 969 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 1;
        (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].rel_attr);
    }
#line 3139 "yacc_sql.cpp"
    break;

  case 137: /* condition: arith_expr comp_op arith_expr  */
#line 978 "yacc_sql.y"
                                    {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
    }
#line 3152 "yacc_sql.cpp"
    break;

  case 138: /* condition: rel_attr comp_op value  */
#line 986 "yacc_sql.y"
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
#line 3167 "yacc_sql.cpp"
    break;

  case 139: /* condition: value comp_op value  */
#line 996 "yacc_sql.y"
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
#line 3182 "yacc_sql.cpp"
    break;

  case 140: /* condition: rel_attr comp_op rel_attr  */
#line 1006 "yacc_sql.y"
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
#line 3197 "yacc_sql.cpp"
    break;

  case 141: /* condition: value comp_op rel_attr  */
#line 1016 "yacc_sql.y"
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
#line 3212 "yacc_sql.cpp"
    break;

  case 142: /* condition: rel_attr comp_op SUB_QUERY  */
#line 1026 "yacc_sql.y"
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
#line 3227 "yacc_sql.cpp"
    break;

  case 143: /* condition: SUB_QUERY comp_op rel_attr  */
#line 1036 "yacc_sql.y"
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
#line 3242 "yacc_sql.cpp"
    break;

  case 144: /* condition: SUB_QUERY comp_op SUB_QUERY  */
#line 1046 "yacc_sql.y"
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
#line 3257 "yacc_sql.cpp"
    break;

  case 145: /* condition: value comp_op LBRACE value value_list RBRACE  */
#line 1056 "yacc_sql.y"
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
#line 3277 "yacc_sql.cpp"
    break;

  case 146: /* condition: rel_attr comp_op LBRACE value value_list RBRACE  */
#line 1071 "yacc_sql.y"
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
#line 3297 "yacc_sql.cpp"
    break;

  case 147: /* condition: SUB_QUERY comp_op LBRACE value value_list RBRACE  */
#line 1086 "yacc_sql.y"
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
#line 3317 "yacc_sql.cpp"
    break;

  case 148: /* condition: LBRACE value value_list RBRACE comp_op value  */
#line 1101 "yacc_sql.y"
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
#line 3337 "yacc_sql.cpp"
    break;

  case 149: /* condition: LBRACE value value_list RBRACE comp_op rel_attr  */
#line 1116 "yacc_sql.y"
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
#line 3357 "yacc_sql.cpp"
    break;

  case 150: /* condition: LBRACE value value_list RBRACE comp_op SUB_QUERY  */
#line 1131 "yacc_sql.y"
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
#line 3377 "yacc_sql.cpp"
    break;

  case 151: /* condition: LBRACE value value_list RBRACE comp_op LBRACE value value_list RBRACE  */
#line 1146 "yacc_sql.y"
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
#line 3402 "yacc_sql.cpp"
    break;

  case 152: /* condition: aggr_expr comp_op value  */
#line 1166 "yacc_sql.y"
                              {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;     
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].value);
    }
#line 3416 "yacc_sql.cpp"
    break;

  case 153: /* condition: aggr_expr comp_op rel_attr  */
#line 1175 "yacc_sql.y"
                                 {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;     
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].rel_attr);
    }
#line 3430 "yacc_sql.cpp"
    break;

  case 154: /* condition: aggr_expr comp_op aggr_expr  */
#line 1184 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 4;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);  
    }
#line 3443 "yacc_sql.cpp"
    break;

  case 155: /* condition: value is_null_choice  */
#line 1192 "yacc_sql.y"
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
#line 3460 "yacc_sql.cpp"
    break;

  case 156: /* condition: rel_attr is_null_choice  */
#line 1204 "yacc_sql.y"
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
#line 3477 "yacc_sql.cpp"
    break;

  case 157: /* is_null_choice: IS NULL_KY  */
#line 1219 "yacc_sql.y"
                 { (yyval.comp) =  OP_ISNULL; }
#line 3483 "yacc_sql.cpp"
    break;

  case 158: /* is_null_choice: IS NOT NULL_KY  */
#line 1220 "yacc_sql.y"
                     { (yyval.comp) = OP_ISNOTNULL; }
#line 3489 "yacc_sql.cpp"
    break;

  case 159: /* comp_op: EQ  */
#line 1224 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3495 "yacc_sql.cpp"
    break;

  case 160: /* comp_op: LT  */
#line 1225 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3501 "yacc_sql.cpp"
    break;

  case 161: /* comp_op: GT  */
#line 1226 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3507 "yacc_sql.cpp"
    break;

  case 162: /* comp_op: LE  */
#line 1227 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3513 "yacc_sql.cpp"
    break;

  case 163: /* comp_op: GE  */
#line 1228 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3519 "yacc_sql.cpp"
    break;

  case 164: /* comp_op: NE  */
#line 1229 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3525 "yacc_sql.cpp"
    break;

  case 165: /* comp_op: LIKE  */
#line 1230 "yacc_sql.y"
           { (yyval.comp) = CLIKE; }
#line 3531 "yacc_sql.cpp"
    break;

  case 166: /* comp_op: NOT LIKE  */
#line 1231 "yacc_sql.y"
               { (yyval.comp) = CNLIKE; }
#line 3537 "yacc_sql.cpp"
    break;

  case 167: /* comp_op: IN  */
#line 1232 "yacc_sql.y"
         { (yyval.comp) = IN_LIST; }
#line 3543 "yacc_sql.cpp"
    break;

  case 168: /* comp_op: NOT IN  */
#line 1233 "yacc_sql.y"
             { (yyval.comp) = NOTIN_LIST; }
#line 3549 "yacc_sql.cpp"
    break;

  case 169: /* comp_op: EXIST  */
#line 1234 "yacc_sql.y"
            { (yyval.comp) = EXIST_LIST; }
#line 3555 "yacc_sql.cpp"
    break;

  case 170: /* comp_op: NOT EXIST  */
#line 1235 "yacc_sql.y"
                { (yyval.comp) = NOTEXIST_LIST; }
#line 3561 "yacc_sql.cpp"
    break;

  case 171: /* func_op: I2_DISTANCE_T  */
#line 1239 "yacc_sql.y"
                    { (yyval.func) = I2_DISTANCE; }
#line 3567 "yacc_sql.cpp"
    break;

  case 172: /* func_op: COSINE_DISTANCE_T  */
#line 1240 "yacc_sql.y"
                        { (yyval.func) = COSINE_DISTANCE; }
#line 3573 "yacc_sql.cpp"
    break;

  case 173: /* func_op: INNER_PRODUCT_T  */
#line 1241 "yacc_sql.y"
                      { (yyval.func) = INNER_PRODUCT; }
#line 3579 "yacc_sql.cpp"
    break;

  case 174: /* group_by: %empty  */
#line 1245 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 3587 "yacc_sql.cpp"
    break;

  case 175: /* group_by: GROUP BY expression_list  */
#line 1249 "yacc_sql.y"
          {
        (yyval.expression_list) = (yyvsp[0].expression_list);
	  }
#line 3595 "yacc_sql.cpp"
    break;

  case 176: /* having: %empty  */
#line 1255 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3603 "yacc_sql.cpp"
    break;

  case 177: /* having: HAVING condition_list  */
#line 1259 "yacc_sql.y"
    {
      (yyval.condition_list) = (yyvsp[0].condition_list);
    }
#line 3611 "yacc_sql.cpp"
    break;

  case 178: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1266 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3625 "yacc_sql.cpp"
    break;

  case 179: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1279 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3634 "yacc_sql.cpp"
    break;

  case 180: /* set_variable_stmt: SET ID EQ value  */
#line 1287 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3646 "yacc_sql.cpp"
    break;


#line 3650 "yacc_sql.cpp"

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

#line 1299 "yacc_sql.y"

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
