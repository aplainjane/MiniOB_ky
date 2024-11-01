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
  YYSYMBOL_FLOAT_T = 29,                   /* FLOAT_T  */
  YYSYMBOL_VECTOR_T = 30,                  /* VECTOR_T  */
  YYSYMBOL_HELP = 31,                      /* HELP  */
  YYSYMBOL_EXIT = 32,                      /* EXIT  */
  YYSYMBOL_DOT = 33,                       /* DOT  */
  YYSYMBOL_INTO = 34,                      /* INTO  */
  YYSYMBOL_VALUES = 35,                    /* VALUES  */
  YYSYMBOL_FROM = 36,                      /* FROM  */
  YYSYMBOL_WHERE = 37,                     /* WHERE  */
  YYSYMBOL_HAVING = 38,                    /* HAVING  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_SET = 40,                       /* SET  */
  YYSYMBOL_ON = 41,                        /* ON  */
  YYSYMBOL_LOAD = 42,                      /* LOAD  */
  YYSYMBOL_DATA = 43,                      /* DATA  */
  YYSYMBOL_INFILE = 44,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 45,                   /* EXPLAIN  */
  YYSYMBOL_STORAGE = 46,                   /* STORAGE  */
  YYSYMBOL_FORMAT = 47,                    /* FORMAT  */
  YYSYMBOL_NOT = 48,                       /* NOT  */
  YYSYMBOL_LIKE = 49,                      /* LIKE  */
  YYSYMBOL_IN = 50,                        /* IN  */
  YYSYMBOL_IS = 51,                        /* IS  */
  YYSYMBOL_EXIST = 52,                     /* EXIST  */
  YYSYMBOL_NULL_KY = 53,                   /* NULL_KY  */
  YYSYMBOL_INNER = 54,                     /* INNER  */
  YYSYMBOL_JOIN = 55,                      /* JOIN  */
  YYSYMBOL_EQ = 56,                        /* EQ  */
  YYSYMBOL_LT = 57,                        /* LT  */
  YYSYMBOL_GT = 58,                        /* GT  */
  YYSYMBOL_LE = 59,                        /* LE  */
  YYSYMBOL_GE = 60,                        /* GE  */
  YYSYMBOL_NE = 61,                        /* NE  */
  YYSYMBOL_I2_DISTANCE_T = 62,             /* I2_DISTANCE_T  */
  YYSYMBOL_COSINE_DISTANCE_T = 63,         /* COSINE_DISTANCE_T  */
  YYSYMBOL_INNER_PRODUCT_T = 64,           /* INNER_PRODUCT_T  */
  YYSYMBOL_SUM = 65,                       /* SUM  */
  YYSYMBOL_AVG = 66,                       /* AVG  */
  YYSYMBOL_COUNT = 67,                     /* COUNT  */
  YYSYMBOL_MAX = 68,                       /* MAX  */
  YYSYMBOL_MIN = 69,                       /* MIN  */
  YYSYMBOL_NUMBER = 70,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 71,                     /* FLOAT  */
  YYSYMBOL_ID = 72,                        /* ID  */
  YYSYMBOL_SSS = 73,                       /* SSS  */
  YYSYMBOL_SUB_QUERY = 74,                 /* SUB_QUERY  */
  YYSYMBOL_VECTOR_LIST = 75,               /* VECTOR_LIST  */
  YYSYMBOL_76_ = 76,                       /* '+'  */
  YYSYMBOL_77_ = 77,                       /* '-'  */
  YYSYMBOL_78_ = 78,                       /* '*'  */
  YYSYMBOL_79_ = 79,                       /* '/'  */
  YYSYMBOL_UMINUS = 80,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 81,                  /* $accept  */
  YYSYMBOL_commands = 82,                  /* commands  */
  YYSYMBOL_command_wrapper = 83,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 84,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 85,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 86,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 87,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 88,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 89,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 90,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 91,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 92,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 93,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 94,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 95,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 96,             /* attr_def_list  */
  YYSYMBOL_attr_def = 97,                  /* attr_def  */
  YYSYMBOL_null_choice = 98,               /* null_choice  */
  YYSYMBOL_number = 99,                    /* number  */
  YYSYMBOL_type = 100,                     /* type  */
  YYSYMBOL_insert_stmt = 101,              /* insert_stmt  */
  YYSYMBOL_value_list = 102,               /* value_list  */
  YYSYMBOL_value = 103,                    /* value  */
  YYSYMBOL_storage_format = 104,           /* storage_format  */
  YYSYMBOL_delete_stmt = 105,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 106,              /* update_stmt  */
  YYSYMBOL_set_clause_list = 107,          /* set_clause_list  */
  YYSYMBOL_set_clause = 108,               /* set_clause  */
  YYSYMBOL_select_stmt = 109,              /* select_stmt  */
  YYSYMBOL_calc_stmt = 110,                /* calc_stmt  */
  YYSYMBOL_expression_list = 111,          /* expression_list  */
  YYSYMBOL_expression = 112,               /* expression  */
  YYSYMBOL_simple_expression = 113,        /* simple_expression  */
  YYSYMBOL_arith_expr = 114,               /* arith_expr  */
  YYSYMBOL_aggr_expr = 115,                /* aggr_expr  */
  YYSYMBOL_rel_attr = 116,                 /* rel_attr  */
  YYSYMBOL_rel_list = 117,                 /* rel_list  */
  YYSYMBOL_join_list = 118,                /* join_list  */
  YYSYMBOL_where = 119,                    /* where  */
  YYSYMBOL_condition_list = 120,           /* condition_list  */
  YYSYMBOL_condition = 121,                /* condition  */
  YYSYMBOL_is_null_choice = 122,           /* is_null_choice  */
  YYSYMBOL_comp_op = 123,                  /* comp_op  */
  YYSYMBOL_func_op = 124,                  /* func_op  */
  YYSYMBOL_group_by = 125,                 /* group_by  */
  YYSYMBOL_having = 126,                   /* having  */
  YYSYMBOL_load_data_stmt = 127,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 128,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 129,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 130             /* opt_semicolon  */
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
#define YYLAST   774

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  348

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   331


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
       2,     2,    78,    76,     2,    77,     2,    79,     2,     2,
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
      75,    80
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   226,   226,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   257,   263,   268,   274,   280,   286,   292,
     299,   305,   313,   332,   354,   364,   388,   391,   404,   413,
     426,   429,   433,   440,   443,   444,   445,   446,   447,   450,
     467,   470,   481,   485,   489,   495,   501,   508,   511,   518,
     530,   560,   566,   576,   583,   596,   632,   640,   645,   656,
     660,   663,   666,   669,   672,   677,   683,   686,   689,   692,
     697,   703,   708,   716,   719,   722,   725,   728,   731,   734,
     737,   740,   743,   746,   749,   752,   755,   758,   761,   764,
     767,   770,   773,   776,   779,   782,   785,   788,   791,   794,
     799,   802,   805,   808,   811,   814,   820,   826,   832,   838,
     847,   852,   863,   866,   879,   882,   885,   907,   911,   917,
     920,   925,   933,   942,   951,   960,   969,   977,   987,   997,
    1007,  1017,  1027,  1037,  1047,  1062,  1077,  1092,  1107,  1122,
    1137,  1157,  1166,  1175,  1183,  1195,  1210,  1211,  1215,  1216,
    1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,
    1230,  1231,  1232,  1236,  1239,  1246,  1249,  1256,  1269,  1277,
    1287,  1288
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
  "STRING_T", "DATE_T", "FLOAT_T", "VECTOR_T", "HELP", "EXIT", "DOT",
  "INTO", "VALUES", "FROM", "WHERE", "HAVING", "AND", "SET", "ON", "LOAD",
  "DATA", "INFILE", "EXPLAIN", "STORAGE", "FORMAT", "NOT", "LIKE", "IN",
  "IS", "EXIST", "NULL_KY", "INNER", "JOIN", "EQ", "LT", "GT", "LE", "GE",
  "NE", "I2_DISTANCE_T", "COSINE_DISTANCE_T", "INNER_PRODUCT_T", "SUM",
  "AVG", "COUNT", "MAX", "MIN", "NUMBER", "FLOAT", "ID", "SSS",
  "SUB_QUERY", "VECTOR_LIST", "'+'", "'-'", "'*'", "'/'", "UMINUS",
  "$accept", "commands", "command_wrapper", "exit_stmt", "help_stmt",
  "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "show_tables_stmt", "desc_table_stmt",
  "create_index_stmt", "drop_index_stmt", "create_table_stmt",
  "attr_def_list", "attr_def", "null_choice", "number", "type",
  "insert_stmt", "value_list", "value", "storage_format", "delete_stmt",
  "update_stmt", "set_clause_list", "set_clause", "select_stmt",
  "calc_stmt", "expression_list", "expression", "simple_expression",
  "arith_expr", "aggr_expr", "rel_attr", "rel_list", "join_list", "where",
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

#define YYPACT_NINF (-204)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-83)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     717,   153,    66,    -2,    -2,   -57,    11,  -204,   -10,     5,
     -13,  -204,  -204,  -204,  -204,  -204,    28,    40,   717,    90,
     105,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,    47,   111,    68,    74,    75,    -2,  -204,  -204,  -204,
    -204,   130,   131,   133,   140,   158,  -204,  -204,   146,  -204,
    -204,    -2,  -204,  -204,  -204,   203,  -204,  -204,   167,   154,
    -204,  -204,   117,   119,   156,   170,   183,  -204,  -204,  -204,
    -204,   177,   157,   189,  -204,   191,     2,   300,   321,   359,
     380,   418,   161,  -204,    -2,    -2,    -2,    -2,    -2,   439,
     162,   201,   202,   166,   403,   172,   176,   231,   212,   214,
    -204,  -204,   266,  -204,   269,  -204,   270,  -204,   271,  -204,
     274,  -204,  -204,   -65,   -65,  -204,  -204,  -204,   276,   272,
     278,   474,  -204,   244,   -12,  -204,  -204,   267,    18,   281,
     232,   286,  -204,  -204,  -204,  -204,  -204,  -204,  -204,   235,
      57,   403,   499,   507,   499,   473,   -22,   695,   507,   473,
    -204,   280,   344,   166,  -204,   301,  -204,  -204,  -204,  -204,
    -204,   -11,   176,   289,   295,   255,   272,    57,   257,   202,
     309,   499,    95,    78,  -204,     0,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,   132,  -204,    60,    64,   -36,
    -204,   508,   533,   542,   567,   576,   601,   610,   635,   644,
     499,   -37,  -204,   273,   474,  -204,  -204,  -204,   260,   263,
     296,  -204,  -204,   281,   308,   284,   272,  -204,  -204,   316,
     351,   403,   338,   339,  -204,  -204,  -204,  -204,   403,  -204,
    -204,   323,  -204,   499,   106,   192,   199,   499,    60,    64,
     499,    60,    64,   499,  -204,  -204,   499,  -204,  -204,   499,
      60,    64,   499,    60,    64,   499,  -204,  -204,   499,  -204,
    -204,   106,   192,   199,  -204,  -204,  -204,   499,  -204,   106,
     192,   199,  -204,  -204,  -204,   340,  -204,  -204,   334,  -204,
     272,   361,   474,   391,   364,   309,  -204,   507,   309,  -204,
      95,   116,   123,   137,   141,   145,   165,   184,   188,    95,
     -27,   347,   383,  -204,    57,    -2,   474,  -204,  -204,   265,
     384,   385,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
     386,  -204,   336,  -204,  -204,  -204,  -204,   403,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,   309,   388,  -204
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,    24,    23,     0,     0,     0,     0,
     180,    22,    21,    14,    15,    16,    17,     9,    10,    11,
      12,    13,     8,     5,     7,     6,     4,     3,    18,    19,
      20,     0,     0,     0,     0,     0,     0,    56,   170,   171,
     172,     0,     0,     0,     0,     0,    52,    53,   120,    54,
      55,     0,    76,    74,    66,    67,    78,    75,     0,     0,
      31,    30,     0,     0,     0,     0,     0,   178,     1,   181,
       2,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,     0,     0,     0,     0,     0,
      69,   115,     0,   116,     0,   119,     0,   118,     0,   117,
       0,   121,    68,    70,    71,    72,    73,    80,     0,   122,
       0,   129,    59,     0,   127,    61,   179,     0,     0,    36,
       0,     0,    34,   110,   111,   114,   112,   113,    79,     0,
     124,     0,     0,     0,     0,    81,     0,     0,     0,    82,
     128,   130,     0,     0,    60,     0,    44,    45,    48,    46,
      47,    40,     0,     0,     0,     0,   122,   124,     0,   127,
      50,     0,    81,     0,    82,     0,   164,   166,   168,   158,
     159,   160,   161,   162,   163,     0,    81,    93,    92,     0,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,     0,   129,    64,    63,    62,     0,     0,
       0,    41,    39,    36,    57,     0,   122,   123,   125,     0,
     173,     0,     0,     0,    83,   165,   167,   169,     0,   143,
     142,     0,   156,     0,   138,   134,   140,     0,   106,    98,
       0,   107,    99,     0,   108,   100,     0,   109,   101,     0,
      94,   102,     0,    95,   103,     0,    96,   104,     0,    97,
     105,   132,   136,   133,   151,   153,   152,     0,   141,   137,
     135,   139,   131,   177,    43,     0,    42,    37,     0,    35,
     122,     0,   129,     0,   175,    50,    49,     0,    50,   157,
      81,     0,     0,     0,     0,     0,     0,     0,     0,    81,
      40,     0,     0,    32,   124,     0,   129,    65,    51,     0,
       0,     0,    88,    89,    90,    91,    84,    85,    86,    87,
       0,    38,     0,    33,   126,   174,   176,     0,   149,   147,
     148,   146,   144,   145,    58,    50,     0,   150
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -204,  -204,   392,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,   190,   239,   110,  -204,  -204,
    -204,  -180,    -3,  -204,  -204,  -204,  -204,   253,  -204,  -204,
      15,   227,    49,   -33,  -104,    36,  -154,  -173,  -126,  -203,
    -204,   282,  -152,  -204,  -204,  -204,  -204,  -204,  -204,  -204
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   173,   139,   222,   285,   171,
      33,   232,   196,   289,    34,    35,   134,   135,    36,    37,
      64,    65,   156,   183,    66,   184,   150,   179,   132,   160,
     161,   200,   195,    68,   294,   317,    38,    39,    40,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    63,   233,   201,   228,   210,   211,   213,   164,   219,
     163,   282,   241,    97,    98,    70,    47,   242,    46,    69,
      71,   220,   227,   110,    72,   131,   221,   158,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   220,    60,    67,
      67,    73,   221,    63,   166,   167,   168,   169,   170,   235,
     236,    47,   237,   230,   202,   203,   204,   205,    63,    74,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,   291,    60,    44,    61,    62,    45,    95,    96,
      97,    98,    67,    76,    63,    63,    63,    63,    63,   314,
      78,    63,    63,    63,    63,    63,    63,    67,   157,   234,
      75,   136,   112,   114,   116,   118,   120,   275,    79,   122,
     158,   177,   178,   336,   128,   318,   -50,   231,   320,    81,
     321,   198,    82,    67,    67,    67,    67,    67,   155,   330,
      67,    67,    67,    67,    67,    67,   312,   322,   204,   205,
      83,   334,   208,   209,   323,   319,    84,    85,   180,   182,
      87,    88,   238,    89,   206,   207,   208,   209,   324,   216,
      90,    41,   325,    42,    43,   346,   326,   159,   245,   249,
     252,   255,   258,   261,   264,   267,   270,   272,    91,    92,
     280,   157,   -81,   -81,   -81,   -81,   327,    99,   158,   101,
     100,   102,   202,   203,   204,   205,   103,   106,   244,   202,
     203,   204,   205,   197,    58,   328,   239,   271,   274,   329,
     279,   155,   158,   202,   203,   204,   205,   202,   203,   204,
     205,   202,   203,   204,   205,    94,   104,   105,   295,   107,
     108,   240,   109,   121,   129,   298,   130,   246,   133,   131,
     300,   202,   203,   204,   205,   137,   273,   276,   138,   281,
     159,   248,   251,   254,   257,   260,   263,   266,   269,   157,
     202,   203,   204,   205,   202,   203,   204,   205,   206,   207,
     208,   209,   140,    86,   309,   -82,   -82,   -82,   -82,    95,
      96,    97,    98,   157,   141,   337,   142,   143,    93,   155,
     144,   145,   146,   277,   149,   147,   301,   148,   151,   302,
     162,   165,   303,   172,   174,   304,   175,   176,   305,   218,
     224,   306,    63,   155,   307,   225,   339,   308,    47,   214,
      46,   111,   123,   124,   125,   126,    47,   226,   159,   229,
     335,   231,   283,   284,   345,    56,    57,    58,    59,   338,
      60,    46,   113,    56,    57,    58,    59,   278,    60,   286,
     154,    67,   159,    47,   288,   340,   290,   292,   293,   296,
     297,   310,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    47,    60,   299,    61,    62,    46,
     115,   311,   313,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,   315,    60,    47,    61,    62,
      46,   117,   316,   332,   333,   341,   342,   343,   344,   347,
      77,   223,    47,   287,    56,    57,   217,    59,   215,    60,
     331,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    47,    60,     0,    61,    62,    46,   119,
       0,   212,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,    60,    47,    61,    62,    46,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,    56,    57,     0,    59,     0,    60,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    47,    60,   152,    61,    62,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,    60,     0,    61,    62,     0,   181,
       0,   185,   186,   187,   199,   188,     0,    47,   243,   189,
     190,   191,   192,   193,   194,     0,     0,     0,     0,    51,
      52,    53,    54,    55,    56,    57,    58,    59,   153,    60,
       0,   154,    47,   247,     0,   185,   186,   187,     0,   188,
       0,    47,   250,   189,   190,   191,   192,   193,   194,    56,
      57,    58,    59,     0,    60,     0,   154,     0,    56,    57,
      58,    59,     0,    60,     0,   154,    47,   253,     0,     0,
       0,     0,     0,     0,     0,    47,   256,     0,     0,     0,
       0,     0,     0,    56,    57,    58,    59,     0,    60,     0,
     154,     0,    56,    57,    58,    59,     0,    60,     0,   154,
      47,   259,     0,     0,     0,     0,     0,     0,     0,    47,
     262,     0,     0,     0,     0,     0,     0,    56,    57,    58,
      59,     0,    60,     0,   154,     0,    56,    57,    58,    59,
       0,    60,     0,   154,    47,   265,     0,     0,     0,     0,
       0,     0,     0,    47,   268,     0,     0,     0,     0,     0,
       0,    56,    57,    58,    59,     0,    60,     0,   154,     0,
      56,    57,    58,    59,     0,    60,     0,   154,    47,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,    56,    57,    58,    59,     0,
      60,     0,   154,     0,    56,    57,    58,    59,     0,    60,
       0,   154,     1,     2,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      11,    12,    13,   185,   186,   187,     0,   188,    14,    15,
       0,   189,   190,   191,   192,   193,   194,    16,     0,    17,
       0,     0,    18,     0,     0,     0,     0,     0,     0,     0,
       0,   206,   207,   208,   209
};

static const yytype_int16 yycheck[] =
{
       3,     4,   182,   155,   177,   157,   158,   159,   134,    20,
      22,   214,    48,    78,    79,    72,    53,    53,    20,     4,
       9,    48,   176,    21,    34,    37,    53,   131,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    48,    75,     3,
       4,    36,    53,    46,    26,    27,    28,    29,    30,    49,
      50,    53,    52,   179,    76,    77,    78,    79,    61,    72,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,   226,    75,     8,    77,    78,    11,    76,    77,
      78,    79,    46,    43,    87,    88,    89,    90,    91,   292,
       0,    94,    95,    96,    97,    98,    99,    61,   131,    21,
      72,   104,    87,    88,    89,    90,    91,   211,     3,    94,
     214,    54,    55,   316,    99,   295,    21,    22,   298,    72,
     300,   154,    11,    87,    88,    89,    90,    91,   131,   309,
      94,    95,    96,    97,    98,    99,   290,    21,    78,    79,
      72,   314,    78,    79,    21,   297,    72,    72,   151,   152,
      20,    20,    20,    20,    76,    77,    78,    79,    21,   162,
      20,     8,    21,    10,    11,   345,    21,   131,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    20,    33,
     213,   214,    76,    77,    78,    79,    21,    20,   292,    72,
      36,    72,    76,    77,    78,    79,    40,    20,   201,    76,
      77,    78,    79,   154,    72,    21,    74,   210,   211,    21,
     213,   214,   316,    76,    77,    78,    79,    76,    77,    78,
      79,    76,    77,    78,    79,    22,    56,    44,   231,    72,
      41,   195,    41,    72,    72,   238,    35,   201,    72,    37,
     243,    76,    77,    78,    79,    73,   210,   211,    72,   213,
     214,   202,   203,   204,   205,   206,   207,   208,   209,   292,
      76,    77,    78,    79,    76,    77,    78,    79,    76,    77,
      78,    79,    41,    46,   277,    76,    77,    78,    79,    76,
      77,    78,    79,   316,    72,    20,    72,    21,    61,   292,
      21,    21,    21,    20,    22,    21,   247,    21,    20,   250,
      56,    34,   253,    22,    72,   256,    20,    72,   259,     8,
      21,   262,   315,   316,   265,    20,   319,   268,    53,    39,
      20,    21,    95,    96,    97,    98,    53,    72,   292,    72,
     315,    22,    72,    70,   337,    70,    71,    72,    73,    74,
      75,    20,    21,    70,    71,    72,    73,    74,    75,    53,
      77,   315,   316,    53,    46,   319,    72,    41,     7,    21,
      21,    21,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    53,    75,    53,    77,    78,    20,
      21,    47,    21,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     4,    75,    53,    77,    78,
      20,    21,    38,    56,    21,    21,    21,    21,    72,    21,
      18,   172,    53,   223,    70,    71,   163,    73,    74,    75,
     310,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    53,    75,    -1,    77,    78,    20,    21,
      -1,   159,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    75,    53,    77,    78,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    70,    71,    -1,    73,    -1,    75,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    53,    75,    20,    77,    78,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    75,    -1,    77,    78,    -1,    20,
      -1,    48,    49,    50,    51,    52,    -1,    53,    20,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    77,    53,    20,    -1,    48,    49,    50,    -1,    52,
      -1,    53,    20,    56,    57,    58,    59,    60,    61,    70,
      71,    72,    73,    -1,    75,    -1,    77,    -1,    70,    71,
      72,    73,    -1,    75,    -1,    77,    53,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    -1,    75,    -1,
      77,    -1,    70,    71,    72,    73,    -1,    75,    -1,    77,
      53,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,    75,    -1,    77,    -1,    70,    71,    72,    73,
      -1,    75,    -1,    77,    53,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    75,    -1,    77,    -1,
      70,    71,    72,    73,    -1,    75,    -1,    77,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      75,    -1,    77,    -1,    70,    71,    72,    73,    -1,    75,
      -1,    77,     5,     6,    -1,    -1,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      23,    24,    25,    48,    49,    50,    -1,    52,    31,    32,
      -1,    56,    57,    58,    59,    60,    61,    40,    -1,    42,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    12,    13,    14,    15,    16,    17,    18,
      19,    23,    24,    25,    31,    32,    40,    42,    45,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   101,   105,   106,   109,   110,   127,   128,
     129,     8,    10,    11,     8,    11,    20,    53,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      75,    77,    78,   103,   111,   112,   115,   116,   124,   111,
      72,     9,    34,    36,    72,    72,    43,    83,     0,     3,
     130,    72,    11,    72,    72,    72,   112,    20,    20,    20,
      20,    20,    33,   112,    22,    76,    77,    78,    79,    20,
      36,    72,    72,    40,    56,    44,    20,    72,    41,    41,
      21,    21,   111,    21,   111,    21,   111,    21,   111,    21,
     111,    72,   111,   112,   112,   112,   112,    21,   111,    72,
      35,    37,   119,    72,   107,   108,   103,    73,    72,    97,
      41,    72,    72,    21,    21,    21,    21,    21,    21,    22,
     117,    20,    20,    74,    77,   103,   113,   114,   115,   116,
     120,   121,    56,    22,   119,    34,    26,    27,    28,    29,
      30,   100,    22,    96,    72,    20,    72,    54,    55,   118,
     103,    20,   103,   114,   116,    48,    49,    50,    52,    56,
      57,    58,    59,    60,    61,   123,   103,   113,   114,    51,
     122,   123,    76,    77,    78,    79,    76,    77,    78,    79,
     123,   123,   122,   123,    39,    74,   103,   108,     8,    20,
      48,    53,    98,    97,    21,    20,    72,   117,   118,    72,
     119,    22,   102,   102,    21,    49,    50,    52,    20,    74,
     116,    48,    53,    20,   103,   114,   116,    20,   113,   114,
      20,   113,   114,    20,   113,   114,    20,   113,   114,    20,
     113,   114,    20,   113,   114,    20,   113,   114,    20,   113,
     114,   103,   114,   116,   103,   115,   116,    20,    74,   103,
     114,   116,   120,    72,    70,    99,    53,    96,    46,   104,
      72,   117,    41,     7,   125,   103,    21,    21,   103,    53,
     103,   113,   113,   113,   113,   113,   113,   113,   113,   103,
      21,    47,   117,    21,   120,     4,    38,   126,   102,   123,
     102,   102,    21,    21,    21,    21,    21,    21,    21,    21,
     102,    98,    56,    21,   118,   111,   120,    20,    74,   103,
     116,    21,    21,    21,    72,   103,   102,    21
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    93,    94,    95,    96,    96,    97,    97,
      98,    98,    98,    99,   100,   100,   100,   100,   100,   101,
     102,   102,   103,   103,   103,   103,   103,   104,   104,   105,
     106,   107,   107,   108,   108,   109,   110,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   113,   113,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     116,   116,   117,   117,   118,   118,   118,   119,   119,   120,
     120,   120,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   122,   122,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     124,   124,   124,   125,   125,   126,   126,   127,   128,   129,
     130,   130
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     9,    10,     5,     8,     0,     3,     6,     3,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     8,
       0,     3,     1,     1,     1,     1,     1,     0,     4,     4,
       5,     1,     3,     3,     3,     9,     2,     1,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     2,     1,     4,
       3,     1,     1,     3,     5,     5,     5,     5,     5,     5,
       5,     5,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     4,     4,     4,     3,     3,     3,     3,     3,
       1,     3,     0,     3,     0,     2,     5,     0,     2,     0,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
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
#line 227 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1980 "yacc_sql.cpp"
    break;

  case 23: /* exit_stmt: EXIT  */
#line 257 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1989 "yacc_sql.cpp"
    break;

  case 24: /* help_stmt: HELP  */
#line 263 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1997 "yacc_sql.cpp"
    break;

  case 25: /* sync_stmt: SYNC  */
#line 268 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 2005 "yacc_sql.cpp"
    break;

  case 26: /* begin_stmt: TRX_BEGIN  */
#line 274 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 2013 "yacc_sql.cpp"
    break;

  case 27: /* commit_stmt: TRX_COMMIT  */
#line 280 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 2021 "yacc_sql.cpp"
    break;

  case 28: /* rollback_stmt: TRX_ROLLBACK  */
#line 286 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 2029 "yacc_sql.cpp"
    break;

  case 29: /* drop_table_stmt: DROP TABLE ID  */
#line 292 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2039 "yacc_sql.cpp"
    break;

  case 30: /* show_tables_stmt: SHOW TABLES  */
#line 299 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 2047 "yacc_sql.cpp"
    break;

  case 31: /* desc_table_stmt: DESC ID  */
#line 305 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2057 "yacc_sql.cpp"
    break;

  case 32: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID rel_list RBRACE  */
#line 314 "yacc_sql.y"
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
#line 2080 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID rel_list RBRACE  */
#line 333 "yacc_sql.y"
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
#line 2103 "yacc_sql.cpp"
    break;

  case 34: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 355 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2115 "yacc_sql.cpp"
    break;

  case 35: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format  */
#line 365 "yacc_sql.y"
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
      if ((yyvsp[0].string) != nullptr) {
        create_table.storage_format = (yyvsp[0].string);
        free((yyvsp[0].string));
      }
    }
#line 2140 "yacc_sql.cpp"
    break;

  case 36: /* attr_def_list: %empty  */
#line 388 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2148 "yacc_sql.cpp"
    break;

  case 37: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 392 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2162 "yacc_sql.cpp"
    break;

  case 38: /* attr_def: ID type LBRACE number RBRACE null_choice  */
#line 405 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->nullable = (yyvsp[0].boolean);
      free((yyvsp[-5].string));
    }
#line 2175 "yacc_sql.cpp"
    break;

  case 39: /* attr_def: ID type null_choice  */
#line 414 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->nullable = (yyvsp[0].boolean);
      free((yyvsp[-2].string));
    }
#line 2188 "yacc_sql.cpp"
    break;

  case 40: /* null_choice: %empty  */
#line 426 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2196 "yacc_sql.cpp"
    break;

  case 41: /* null_choice: NULL_KY  */
#line 430 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2204 "yacc_sql.cpp"
    break;

  case 42: /* null_choice: NOT NULL_KY  */
#line 434 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2212 "yacc_sql.cpp"
    break;

  case 43: /* number: NUMBER  */
#line 440 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2218 "yacc_sql.cpp"
    break;

  case 44: /* type: INT_T  */
#line 443 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::INTS); }
#line 2224 "yacc_sql.cpp"
    break;

  case 45: /* type: STRING_T  */
#line 444 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::CHARS); }
#line 2230 "yacc_sql.cpp"
    break;

  case 46: /* type: FLOAT_T  */
#line 445 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::FLOATS); }
#line 2236 "yacc_sql.cpp"
    break;

  case 47: /* type: VECTOR_T  */
#line 446 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::VECTORS); }
#line 2242 "yacc_sql.cpp"
    break;

  case 48: /* type: DATE_T  */
#line 447 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::DATES); }
#line 2248 "yacc_sql.cpp"
    break;

  case 49: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 451 "yacc_sql.y"
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
#line 2265 "yacc_sql.cpp"
    break;

  case 50: /* value_list: %empty  */
#line 467 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2273 "yacc_sql.cpp"
    break;

  case 51: /* value_list: COMMA value value_list  */
#line 470 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2287 "yacc_sql.cpp"
    break;

  case 52: /* value: NUMBER  */
#line 481 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2296 "yacc_sql.cpp"
    break;

  case 53: /* value: FLOAT  */
#line 485 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2305 "yacc_sql.cpp"
    break;

  case 54: /* value: SSS  */
#line 489 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2316 "yacc_sql.cpp"
    break;

  case 55: /* value: VECTOR_LIST  */
#line 495 "yacc_sql.y"
                 {
      char *tmp = common::substr((yyvsp[0].string),0,strlen((yyvsp[0].string))-1);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2327 "yacc_sql.cpp"
    break;

  case 56: /* value: NULL_KY  */
#line 501 "yacc_sql.y"
              {
      (yyval.value) = new Value();
      (yyval.value)->make_null();
    }
#line 2336 "yacc_sql.cpp"
    break;

  case 57: /* storage_format: %empty  */
#line 508 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 2344 "yacc_sql.cpp"
    break;

  case 58: /* storage_format: STORAGE FORMAT EQ ID  */
#line 512 "yacc_sql.y"
    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2352 "yacc_sql.cpp"
    break;

  case 59: /* delete_stmt: DELETE FROM ID where  */
#line 519 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2366 "yacc_sql.cpp"
    break;

  case 60: /* update_stmt: UPDATE ID SET set_clause_list where  */
#line 531 "yacc_sql.y"
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
#line 2396 "yacc_sql.cpp"
    break;

  case 61: /* set_clause_list: set_clause  */
#line 561 "yacc_sql.y"
    {
        (yyval.set_clause_list) = new std::vector<UpdateKV>();
        (yyval.set_clause_list)->push_back(*(yyvsp[0].set_clause));
        delete (yyvsp[0].set_clause);  // 确保 $1 是 new 出来的对象
    }
#line 2406 "yacc_sql.cpp"
    break;

  case 62: /* set_clause_list: set_clause_list COMMA set_clause  */
#line 567 "yacc_sql.y"
    {
        (yyvsp[-2].set_clause_list)->push_back(*(yyvsp[0].set_clause));
        (yyval.set_clause_list) = (yyvsp[-2].set_clause_list);
        delete (yyvsp[0].set_clause);  // 确保 $3 是 new 出来的对象
    }
#line 2416 "yacc_sql.cpp"
    break;

  case 63: /* set_clause: ID EQ value  */
#line 577 "yacc_sql.y"
    {
        (yyval.set_clause) = new UpdateKV();
        (yyval.set_clause)->attr_name = strdup((yyvsp[-2].string));  // 使用 strdup 复制字符串，避免释放后使用问题
        (yyval.set_clause)->value = *(yyvsp[0].value);
        free((yyvsp[-2].string));  // 确保在拷贝完成后再释放
    }
#line 2427 "yacc_sql.cpp"
    break;

  case 64: /* set_clause: ID EQ SUB_QUERY  */
#line 584 "yacc_sql.y"
    {
      (yyval.set_clause) = new UpdateKV();
      (yyval.set_clause)->is_subquery = true;
      (yyval.set_clause)->attr_name = strdup((yyvsp[-2].string));
      (yyval.set_clause)->subquery = strdup((yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2440 "yacc_sql.cpp"
    break;

  case 65: /* select_stmt: SELECT expression_list FROM ID rel_list join_list where group_by having  */
#line 597 "yacc_sql.y"
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
#line 2478 "yacc_sql.cpp"
    break;

  case 66: /* calc_stmt: CALC expression_list  */
#line 633 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2488 "yacc_sql.cpp"
    break;

  case 67: /* expression_list: expression  */
#line 641 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2497 "yacc_sql.cpp"
    break;

  case 68: /* expression_list: expression COMMA expression_list  */
#line 646 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace((yyval.expression_list)->begin(), (yyvsp[-2].expression));
    }
#line 2510 "yacc_sql.cpp"
    break;

  case 69: /* expression: LBRACE expression RBRACE  */
#line 656 "yacc_sql.y"
                             {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2519 "yacc_sql.cpp"
    break;

  case 70: /* expression: expression '+' expression  */
#line 660 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2527 "yacc_sql.cpp"
    break;

  case 71: /* expression: expression '-' expression  */
#line 663 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2535 "yacc_sql.cpp"
    break;

  case 72: /* expression: expression '*' expression  */
#line 666 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2543 "yacc_sql.cpp"
    break;

  case 73: /* expression: expression '/' expression  */
#line 669 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2551 "yacc_sql.cpp"
    break;

  case 74: /* expression: value  */
#line 672 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2561 "yacc_sql.cpp"
    break;

  case 75: /* expression: rel_attr  */
#line 677 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2572 "yacc_sql.cpp"
    break;

  case 76: /* expression: '*'  */
#line 683 "yacc_sql.y"
          {
      (yyval.expression) = new StarExpr();
    }
#line 2580 "yacc_sql.cpp"
    break;

  case 77: /* expression: '-' expression  */
#line 686 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2588 "yacc_sql.cpp"
    break;

  case 78: /* expression: aggr_expr  */
#line 689 "yacc_sql.y"
                {
      (yyval.expression) = (yyvsp[0].expression);
    }
#line 2596 "yacc_sql.cpp"
    break;

  case 79: /* expression: func_op LBRACE expression_list RBRACE  */
#line 692 "yacc_sql.y"
                                            {
      (yyval.expression) = new FunctionExpr((FuncOp)(yyvsp[-3].func),std::move(*(yyvsp[-1].expression_list)));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[-1].expression_list);
    }
#line 2606 "yacc_sql.cpp"
    break;

  case 80: /* expression: func_op LBRACE RBRACE  */
#line 697 "yacc_sql.y"
                            {
      (yyval.expression) = new FunctionExpr((FuncOp)(yyvsp[-2].func),std::vector<std::unique_ptr<Expression>>());
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2615 "yacc_sql.cpp"
    break;

  case 81: /* simple_expression: value  */
#line 703 "yacc_sql.y"
          {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2625 "yacc_sql.cpp"
    break;

  case 82: /* simple_expression: rel_attr  */
#line 708 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2636 "yacc_sql.cpp"
    break;

  case 83: /* arith_expr: LBRACE arith_expr RBRACE  */
#line 716 "yacc_sql.y"
                             {
      (yyval.expression) = (yyvsp[-1].expression);
    }
#line 2644 "yacc_sql.cpp"
    break;

  case 84: /* arith_expr: arith_expr '+' LBRACE simple_expression RBRACE  */
#line 719 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2652 "yacc_sql.cpp"
    break;

  case 85: /* arith_expr: arith_expr '-' LBRACE simple_expression RBRACE  */
#line 722 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2660 "yacc_sql.cpp"
    break;

  case 86: /* arith_expr: arith_expr '*' LBRACE simple_expression RBRACE  */
#line 725 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2668 "yacc_sql.cpp"
    break;

  case 87: /* arith_expr: arith_expr '/' LBRACE simple_expression RBRACE  */
#line 728 "yacc_sql.y"
                                                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2676 "yacc_sql.cpp"
    break;

  case 88: /* arith_expr: simple_expression '+' LBRACE simple_expression RBRACE  */
#line 731 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2684 "yacc_sql.cpp"
    break;

  case 89: /* arith_expr: simple_expression '-' LBRACE simple_expression RBRACE  */
#line 734 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2692 "yacc_sql.cpp"
    break;

  case 90: /* arith_expr: simple_expression '*' LBRACE simple_expression RBRACE  */
#line 737 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2700 "yacc_sql.cpp"
    break;

  case 91: /* arith_expr: simple_expression '/' LBRACE simple_expression RBRACE  */
#line 740 "yacc_sql.y"
                                                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-4].expression), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2708 "yacc_sql.cpp"
    break;

  case 92: /* arith_expr: '-' arith_expr  */
#line 743 "yacc_sql.y"
                     {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2716 "yacc_sql.cpp"
    break;

  case 93: /* arith_expr: '-' simple_expression  */
#line 746 "yacc_sql.y"
                            {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, new ValueExpr(*(new Value(0))), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2724 "yacc_sql.cpp"
    break;

  case 94: /* arith_expr: arith_expr '+' simple_expression  */
#line 749 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2732 "yacc_sql.cpp"
    break;

  case 95: /* arith_expr: arith_expr '-' simple_expression  */
#line 752 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2740 "yacc_sql.cpp"
    break;

  case 96: /* arith_expr: arith_expr '*' simple_expression  */
#line 755 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2748 "yacc_sql.cpp"
    break;

  case 97: /* arith_expr: arith_expr '/' simple_expression  */
#line 758 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2756 "yacc_sql.cpp"
    break;

  case 98: /* arith_expr: simple_expression '+' arith_expr  */
#line 761 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2764 "yacc_sql.cpp"
    break;

  case 99: /* arith_expr: simple_expression '-' arith_expr  */
#line 764 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2772 "yacc_sql.cpp"
    break;

  case 100: /* arith_expr: simple_expression '*' arith_expr  */
#line 767 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2780 "yacc_sql.cpp"
    break;

  case 101: /* arith_expr: simple_expression '/' arith_expr  */
#line 770 "yacc_sql.y"
                                       {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2788 "yacc_sql.cpp"
    break;

  case 102: /* arith_expr: arith_expr '+' arith_expr  */
#line 773 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2796 "yacc_sql.cpp"
    break;

  case 103: /* arith_expr: arith_expr '-' arith_expr  */
#line 776 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2804 "yacc_sql.cpp"
    break;

  case 104: /* arith_expr: arith_expr '*' arith_expr  */
#line 779 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2812 "yacc_sql.cpp"
    break;

  case 105: /* arith_expr: arith_expr '/' arith_expr  */
#line 782 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2820 "yacc_sql.cpp"
    break;

  case 106: /* arith_expr: simple_expression '+' simple_expression  */
#line 785 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2828 "yacc_sql.cpp"
    break;

  case 107: /* arith_expr: simple_expression '-' simple_expression  */
#line 788 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2836 "yacc_sql.cpp"
    break;

  case 108: /* arith_expr: simple_expression '*' simple_expression  */
#line 791 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2844 "yacc_sql.cpp"
    break;

  case 109: /* arith_expr: simple_expression '/' simple_expression  */
#line 794 "yacc_sql.y"
                                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2852 "yacc_sql.cpp"
    break;

  case 110: /* aggr_expr: SUM LBRACE expression_list RBRACE  */
#line 799 "yacc_sql.y"
                                      {
      (yyval.expression) = create_aggregate_expression("SUM", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2860 "yacc_sql.cpp"
    break;

  case 111: /* aggr_expr: AVG LBRACE expression_list RBRACE  */
#line 802 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("AVG", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2868 "yacc_sql.cpp"
    break;

  case 112: /* aggr_expr: MAX LBRACE expression_list RBRACE  */
#line 805 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("MAX", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2876 "yacc_sql.cpp"
    break;

  case 113: /* aggr_expr: MIN LBRACE expression_list RBRACE  */
#line 808 "yacc_sql.y"
                                        {
      (yyval.expression) = create_aggregate_expression("MIN", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2884 "yacc_sql.cpp"
    break;

  case 114: /* aggr_expr: COUNT LBRACE expression_list RBRACE  */
#line 811 "yacc_sql.y"
                                          {
      (yyval.expression) = create_aggregate_expression("COUNT", (yyvsp[-1].expression_list), sql_string, &(yyloc));
    }
#line 2892 "yacc_sql.cpp"
    break;

  case 115: /* aggr_expr: SUM LBRACE RBRACE  */
#line 814 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("SUM", empty, sql_string, &(yyloc));
    }
#line 2903 "yacc_sql.cpp"
    break;

  case 116: /* aggr_expr: AVG LBRACE RBRACE  */
#line 820 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("AVG", empty, sql_string, &(yyloc));
    }
#line 2914 "yacc_sql.cpp"
    break;

  case 117: /* aggr_expr: MIN LBRACE RBRACE  */
#line 826 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("MIN", empty, sql_string, &(yyloc));
    }
#line 2925 "yacc_sql.cpp"
    break;

  case 118: /* aggr_expr: MAX LBRACE RBRACE  */
#line 832 "yacc_sql.y"
                        {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("MAX", empty, sql_string, &(yyloc));
    }
#line 2936 "yacc_sql.cpp"
    break;

  case 119: /* aggr_expr: COUNT LBRACE RBRACE  */
#line 838 "yacc_sql.y"
                          {
      std::vector<std::unique_ptr<Expression> >* empty = new std::vector<std::unique_ptr<Expression> >;
      empty->push_back(std::make_unique<ValueExpr>());
      empty->push_back(std::make_unique<ValueExpr>());
      (yyval.expression) = create_aggregate_expression("COUNT", empty, sql_string, &(yyloc));
    }
#line 2947 "yacc_sql.cpp"
    break;

  case 120: /* rel_attr: ID  */
#line 847 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2957 "yacc_sql.cpp"
    break;

  case 121: /* rel_attr: ID DOT ID  */
#line 852 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2969 "yacc_sql.cpp"
    break;

  case 122: /* rel_list: %empty  */
#line 863 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 2977 "yacc_sql.cpp"
    break;

  case 123: /* rel_list: COMMA ID rel_list  */
#line 866 "yacc_sql.y"
                        {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::string>;
      }

      (yyval.relation_list)->push_back((yyvsp[-1].string));
      free((yyvsp[-1].string));
    }
#line 2992 "yacc_sql.cpp"
    break;

  case 124: /* join_list: %empty  */
#line 879 "yacc_sql.y"
    {
      (yyval.join_sql_node) = nullptr;
    }
#line 3000 "yacc_sql.cpp"
    break;

  case 125: /* join_list: INNER join_list  */
#line 882 "yacc_sql.y"
                      {
      (yyval.join_sql_node) = (yyvsp[0].join_sql_node);
    }
#line 3008 "yacc_sql.cpp"
    break;

  case 126: /* join_list: JOIN ID ON condition_list join_list  */
#line 885 "yacc_sql.y"
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
#line 3031 "yacc_sql.cpp"
    break;

  case 127: /* where: %empty  */
#line 907 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3039 "yacc_sql.cpp"
    break;

  case 128: /* where: WHERE condition_list  */
#line 911 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 3047 "yacc_sql.cpp"
    break;

  case 129: /* condition_list: %empty  */
#line 917 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3055 "yacc_sql.cpp"
    break;

  case 130: /* condition_list: condition  */
#line 920 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 3065 "yacc_sql.cpp"
    break;

  case 131: /* condition_list: condition AND condition_list  */
#line 925 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3075 "yacc_sql.cpp"
    break;

  case 132: /* condition: arith_expr comp_op value  */
#line 933 "yacc_sql.y"
                              {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].value);
    }
#line 3089 "yacc_sql.cpp"
    break;

  case 133: /* condition: arith_expr comp_op rel_attr  */
#line 942 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].rel_attr);
    }
#line 3103 "yacc_sql.cpp"
    break;

  case 134: /* condition: value comp_op arith_expr  */
#line 951 "yacc_sql.y"
                               {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 0;
        (yyval.condition)->left_value = *(yyvsp[-2].value);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].value);
    }
#line 3117 "yacc_sql.cpp"
    break;

  case 135: /* condition: rel_attr comp_op arith_expr  */
#line 960 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 1;
        (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[-2].rel_attr);
    }
#line 3131 "yacc_sql.cpp"
    break;

  case 136: /* condition: arith_expr comp_op arith_expr  */
#line 969 "yacc_sql.y"
                                    {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 5;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 5;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);
    }
#line 3144 "yacc_sql.cpp"
    break;

  case 137: /* condition: rel_attr comp_op value  */
#line 977 "yacc_sql.y"
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
#line 3159 "yacc_sql.cpp"
    break;

  case 138: /* condition: value comp_op value  */
#line 987 "yacc_sql.y"
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
#line 3174 "yacc_sql.cpp"
    break;

  case 139: /* condition: rel_attr comp_op rel_attr  */
#line 997 "yacc_sql.y"
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
#line 3189 "yacc_sql.cpp"
    break;

  case 140: /* condition: value comp_op rel_attr  */
#line 1007 "yacc_sql.y"
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
#line 3204 "yacc_sql.cpp"
    break;

  case 141: /* condition: rel_attr comp_op SUB_QUERY  */
#line 1017 "yacc_sql.y"
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
#line 3219 "yacc_sql.cpp"
    break;

  case 142: /* condition: SUB_QUERY comp_op rel_attr  */
#line 1027 "yacc_sql.y"
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
#line 3234 "yacc_sql.cpp"
    break;

  case 143: /* condition: SUB_QUERY comp_op SUB_QUERY  */
#line 1037 "yacc_sql.y"
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
#line 3249 "yacc_sql.cpp"
    break;

  case 144: /* condition: value comp_op LBRACE value value_list RBRACE  */
#line 1047 "yacc_sql.y"
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
#line 3269 "yacc_sql.cpp"
    break;

  case 145: /* condition: rel_attr comp_op LBRACE value value_list RBRACE  */
#line 1062 "yacc_sql.y"
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
#line 3289 "yacc_sql.cpp"
    break;

  case 146: /* condition: SUB_QUERY comp_op LBRACE value value_list RBRACE  */
#line 1077 "yacc_sql.y"
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
#line 3309 "yacc_sql.cpp"
    break;

  case 147: /* condition: LBRACE value value_list RBRACE comp_op value  */
#line 1092 "yacc_sql.y"
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
#line 3329 "yacc_sql.cpp"
    break;

  case 148: /* condition: LBRACE value value_list RBRACE comp_op rel_attr  */
#line 1107 "yacc_sql.y"
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
#line 3349 "yacc_sql.cpp"
    break;

  case 149: /* condition: LBRACE value value_list RBRACE comp_op SUB_QUERY  */
#line 1122 "yacc_sql.y"
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
#line 3369 "yacc_sql.cpp"
    break;

  case 150: /* condition: LBRACE value value_list RBRACE comp_op LBRACE value value_list RBRACE  */
#line 1137 "yacc_sql.y"
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
#line 3394 "yacc_sql.cpp"
    break;

  case 151: /* condition: aggr_expr comp_op value  */
#line 1157 "yacc_sql.y"
                              {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;     
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 0;
        (yyval.condition)->right_value = *(yyvsp[0].value);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].value);
    }
#line 3408 "yacc_sql.cpp"
    break;

  case 152: /* condition: aggr_expr comp_op rel_attr  */
#line 1166 "yacc_sql.y"
                                 {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;     
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 1;
        (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
        (yyval.condition)->comp = (yyvsp[-1].comp);
        delete (yyvsp[0].rel_attr);
    }
#line 3422 "yacc_sql.cpp"
    break;

  case 153: /* condition: aggr_expr comp_op aggr_expr  */
#line 1175 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_is_attr = 4;
        (yyval.condition)->left_expr = (yyvsp[-2].expression);
        (yyval.condition)->right_is_attr = 4;
        (yyval.condition)->right_expr = (yyvsp[0].expression);
        (yyval.condition)->comp = (yyvsp[-1].comp);  
    }
#line 3435 "yacc_sql.cpp"
    break;

  case 154: /* condition: value is_null_choice  */
#line 1183 "yacc_sql.y"
                           {
      (yyval.condition) = new ConditionSqlNode;
      Value val;
      val.make_null();
        
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-1].value);  
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = val;
      (yyval.condition)->comp = (yyvsp[0].comp);
      delete (yyvsp[-1].value);
    }
#line 3452 "yacc_sql.cpp"
    break;

  case 155: /* condition: rel_attr is_null_choice  */
#line 1195 "yacc_sql.y"
                              {
      (yyval.condition) = new ConditionSqlNode;
      Value val;
      val.make_null();
      
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-1].rel_attr);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = val;
      (yyval.condition)->comp = (yyvsp[0].comp);
      delete (yyvsp[-1].rel_attr);
    }
#line 3469 "yacc_sql.cpp"
    break;

  case 156: /* is_null_choice: IS NULL_KY  */
#line 1210 "yacc_sql.y"
                 { (yyval.comp) = IS_NULL; }
#line 3475 "yacc_sql.cpp"
    break;

  case 157: /* is_null_choice: IS NOT NULL_KY  */
#line 1211 "yacc_sql.y"
                     { (yyval.comp) = IS_NOT_NULL; }
#line 3481 "yacc_sql.cpp"
    break;

  case 158: /* comp_op: EQ  */
#line 1215 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3487 "yacc_sql.cpp"
    break;

  case 159: /* comp_op: LT  */
#line 1216 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3493 "yacc_sql.cpp"
    break;

  case 160: /* comp_op: GT  */
#line 1217 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3499 "yacc_sql.cpp"
    break;

  case 161: /* comp_op: LE  */
#line 1218 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3505 "yacc_sql.cpp"
    break;

  case 162: /* comp_op: GE  */
#line 1219 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3511 "yacc_sql.cpp"
    break;

  case 163: /* comp_op: NE  */
#line 1220 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3517 "yacc_sql.cpp"
    break;

  case 164: /* comp_op: LIKE  */
#line 1221 "yacc_sql.y"
           { (yyval.comp) = CLIKE; }
#line 3523 "yacc_sql.cpp"
    break;

  case 165: /* comp_op: NOT LIKE  */
#line 1222 "yacc_sql.y"
               { (yyval.comp) = CNLIKE; }
#line 3529 "yacc_sql.cpp"
    break;

  case 166: /* comp_op: IN  */
#line 1223 "yacc_sql.y"
         { (yyval.comp) = IN_LIST; }
#line 3535 "yacc_sql.cpp"
    break;

  case 167: /* comp_op: NOT IN  */
#line 1224 "yacc_sql.y"
             { (yyval.comp) = NOTIN_LIST; }
#line 3541 "yacc_sql.cpp"
    break;

  case 168: /* comp_op: EXIST  */
#line 1225 "yacc_sql.y"
            { (yyval.comp) = EXIST_LIST; }
#line 3547 "yacc_sql.cpp"
    break;

  case 169: /* comp_op: NOT EXIST  */
#line 1226 "yacc_sql.y"
                { (yyval.comp) = NOTEXIST_LIST; }
#line 3553 "yacc_sql.cpp"
    break;

  case 170: /* func_op: I2_DISTANCE_T  */
#line 1230 "yacc_sql.y"
                    { (yyval.func) = I2_DISTANCE; }
#line 3559 "yacc_sql.cpp"
    break;

  case 171: /* func_op: COSINE_DISTANCE_T  */
#line 1231 "yacc_sql.y"
                        { (yyval.func) = COSINE_DISTANCE; }
#line 3565 "yacc_sql.cpp"
    break;

  case 172: /* func_op: INNER_PRODUCT_T  */
#line 1232 "yacc_sql.y"
                      { (yyval.func) = INNER_PRODUCT; }
#line 3571 "yacc_sql.cpp"
    break;

  case 173: /* group_by: %empty  */
#line 1236 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 3579 "yacc_sql.cpp"
    break;

  case 174: /* group_by: GROUP BY expression_list  */
#line 1240 "yacc_sql.y"
          {
        (yyval.expression_list) = (yyvsp[0].expression_list);
	  }
#line 3587 "yacc_sql.cpp"
    break;

  case 175: /* having: %empty  */
#line 1246 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3595 "yacc_sql.cpp"
    break;

  case 176: /* having: HAVING condition_list  */
#line 1250 "yacc_sql.y"
    {
      (yyval.condition_list) = (yyvsp[0].condition_list);
    }
#line 3603 "yacc_sql.cpp"
    break;

  case 177: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1257 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3617 "yacc_sql.cpp"
    break;

  case 178: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1270 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3626 "yacc_sql.cpp"
    break;

  case 179: /* set_variable_stmt: SET ID EQ value  */
#line 1278 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3638 "yacc_sql.cpp"
    break;


#line 3642 "yacc_sql.cpp"

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

#line 1290 "yacc_sql.y"

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
