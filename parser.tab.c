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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"


#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "utils.h"
#include "ht.h"
#include "calc.h"

int yylex();
int yywrap();
void yyerror(const char* str);
FILE *fptr;
ht* hashTable;
TempSymb tabelaTemp[100];
String stringsEstaticas[128];
int stringsCount = 0;
int lastTemp = 0;
int tempCounter = 0;
char str_num[32];
int lastLabel = 0;
struct Pile *labelStack;
int indentation = 1;
int have_printf = 0;
int have_scanf = 0;


#line 99 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DOUBLE = 3,                     /* DOUBLE  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_CHARACTER = 5,                  /* CHARACTER  */
  YYSYMBOL_PLUS = 6,                       /* PLUS  */
  YYSYMBOL_MINUS = 7,                      /* MINUS  */
  YYSYMBOL_DIVIDE = 8,                     /* DIVIDE  */
  YYSYMBOL_TIMES = 9,                      /* TIMES  */
  YYSYMBOL_LEFT = 10,                      /* LEFT  */
  YYSYMBOL_RIGHT = 11,                     /* RIGHT  */
  YYSYMBOL_DONE = 12,                      /* DONE  */
  YYSYMBOL_ID = 13,                        /* ID  */
  YYSYMBOL_STRING = 14,                    /* STRING  */
  YYSYMBOL_EQUALS = 15,                    /* EQUALS  */
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_GT = 18,                        /* GT  */
  YYSYMBOL_GE = 19,                        /* GE  */
  YYSYMBOL_LT = 20,                        /* LT  */
  YYSYMBOL_LE = 21,                        /* LE  */
  YYSYMBOL_l_EQUALS = 22,                  /* l_EQUALS  */
  YYSYMBOL_DIF = 23,                       /* DIF  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_B_LEFT = 25,                    /* B_LEFT  */
  YYSYMBOL_B_RIGHT = 26,                   /* B_RIGHT  */
  YYSYMBOL_COMMA = 27,                     /* COMMA  */
  YYSYMBOL_IF = 28,                        /* IF  */
  YYSYMBOL_ELSE = 29,                      /* ELSE  */
  YYSYMBOL_WHILE = 30,                     /* WHILE  */
  YYSYMBOL_INTtype = 31,                   /* INTtype  */
  YYSYMBOL_FLOATtype = 32,                 /* FLOATtype  */
  YYSYMBOL_BOOLEANtype = 33,               /* BOOLEANtype  */
  YYSYMBOL_CHARtype = 34,                  /* CHARtype  */
  YYSYMBOL_writeCommand = 35,              /* writeCommand  */
  YYSYMBOL_readCommand = 36,               /* readCommand  */
  YYSYMBOL_returnCommand = 37,             /* returnCommand  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_block = 42,                     /* block  */
  YYSYMBOL_statement_list = 43,            /* statement_list  */
  YYSYMBOL_statement = 44,                 /* statement  */
  YYSYMBOL_declaration = 45,               /* declaration  */
  YYSYMBOL_commands = 46,                  /* commands  */
  YYSYMBOL_command = 47,                   /* command  */
  YYSYMBOL_while_command = 48,             /* while_command  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_50_2 = 50,                      /* $@2  */
  YYSYMBOL_return_command = 51,            /* return_command  */
  YYSYMBOL_read_command = 52,              /* read_command  */
  YYSYMBOL_read_value = 53,                /* read_value  */
  YYSYMBOL_write_command = 54,             /* write_command  */
  YYSYMBOL_write_value = 55,               /* write_value  */
  YYSYMBOL_write_formats = 56,             /* write_formats  */
  YYSYMBOL_atrib = 57,                     /* atrib  */
  YYSYMBOL_if_command = 58,                /* if_command  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_else_command = 61,              /* else_command  */
  YYSYMBOL_62_5 = 62,                      /* $@5  */
  YYSYMBOL_logical_expr = 63,              /* logical_expr  */
  YYSYMBOL_expr = 64,                      /* expr  */
  YYSYMBOL_term = 65,                      /* term  */
  YYSYMBOL_factor = 66,                    /* factor  */
  YYSYMBOL_logical_operations = 67         /* logical_operations  */
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
typedef yytype_int8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   120

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
       2,     2,     2,     2,     2,     2,     2,     2,    39,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    78,    80,    80,    82,    82,    90,    97,
     104,   105,   115,   116,   120,   121,   122,   123,   124,   125,
     129,   142,   129,   152,   161,   165,   181,   185,   216,   232,
     236,   258,   267,   258,   274,   274,   285,   294,   298,   306,
     314,   318,   326,   334,   338,   346,   354,   362,   374,   378,
     386,   394,   402,   410,   418,   426,   434,   442,   450,   458
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DOUBLE", "INT",
  "CHARACTER", "PLUS", "MINUS", "DIVIDE", "TIMES", "LEFT", "RIGHT", "DONE",
  "ID", "STRING", "EQUALS", "AND", "OR", "GT", "GE", "LT", "LE",
  "l_EQUALS", "DIF", "NOT", "B_LEFT", "B_RIGHT", "COMMA", "IF", "ELSE",
  "WHILE", "INTtype", "FLOATtype", "BOOLEANtype", "CHARtype",
  "writeCommand", "readCommand", "returnCommand", "';'", "'&'", "$accept",
  "program", "block", "statement_list", "statement", "declaration",
  "commands", "command", "while_command", "$@1", "$@2", "return_command",
  "read_command", "read_value", "write_command", "write_value",
  "write_formats", "atrib", "if_command", "$@3", "$@4", "else_command",
  "$@5", "logical_expr", "expr", "term", "factor", "logical_operations", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-96)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -4,    -5,     2,    25,     1,     6,    26,    29,    41,    45,
      93,    56,   -96,   -96,    -4,    31,   -96,   -96,    36,    37,
      39,    40,   -96,    93,    -2,    -2,   -96,   -96,   -96,   -96,
      65,    66,   -96,   -96,   -96,    93,   -96,     0,    38,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,     0,    63,    70,
       0,    91,    71,    57,    74,    59,    88,     9,    93,    93,
      93,    93,    -2,    91,   -96,    -2,    -2,    93,    93,    93,
      93,    93,    93,   -96,    93,   -96,    61,   -96,   -96,    38,
      38,   -96,   -96,     9,    72,    76,    91,    91,     0,     0,
       0,     0,     0,     0,    77,   -96,     0,    92,   -96,   -96,
     -96,   -96,    35,    35,   -96,    78,    89,    87,   -96,   -96,
     -96,    94,   -96,     8,   -96
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     0,     7,    19,     0,     0,
       0,     0,    14,     0,     0,     0,     8,     9,    10,    11,
       0,     0,    44,    45,    46,     0,    47,    23,    40,    43,
       1,     5,     6,    18,    16,    17,    15,    30,     0,     0,
      59,    37,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,    31,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,    26,     0,    24,    48,    38,
      39,    42,    41,    59,     0,     0,    49,    50,    51,    52,
      53,    54,    56,    55,     0,    27,    29,     0,    58,    12,
      12,    25,    32,    21,    13,     0,     0,    36,    22,    34,
      33,     0,    12,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -96,   -96,   -96,   103,   -96,   -96,   -95,     4,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,    95,   -10,    -9,    -7,   -25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,   102,   104,    17,    94,
     106,    18,    19,    56,    20,    54,    95,    21,    22,    85,
     105,   110,   111,    49,    50,    38,    39,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    32,    33,    34,    16,   103,    58,    59,    35,     1,
      23,    36,    24,    47,    26,    58,    59,   113,    16,    27,
      78,     1,    48,    63,     2,    57,     3,     4,     5,     6,
       7,     8,     9,    10,   114,    25,     2,    84,     3,    28,
      86,    87,    29,     8,     9,    10,    60,    61,     1,    79,
      80,    30,    83,    81,    82,    31,    40,    88,    89,    90,
      91,    92,    93,     2,    96,     3,    32,    33,    34,    42,
       8,     9,    10,    62,    43,    44,    36,    45,    46,    53,
      55,    64,    73,    98,    74,    75,    76,    48,    65,    66,
      67,    68,    69,    70,    71,    72,    32,    33,    34,    77,
      97,    99,   100,    35,   107,   101,    36,    65,    66,    67,
      68,    69,    70,    71,    72,   108,   109,    41,     0,   112,
      52
};

static const yytype_int8 yycheck[] =
{
      10,     3,     4,     5,     0,   100,     6,     7,    10,    13,
      15,    13,    10,    23,    13,     6,     7,   112,    14,    13,
      11,    13,    24,    48,    28,    35,    30,    31,    32,    33,
      34,    35,    36,    37,    26,    10,    28,    62,    30,    13,
      65,    66,    13,    35,    36,    37,     8,     9,    13,    58,
      59,    10,    62,    60,    61,    10,     0,    67,    68,    69,
      70,    71,    72,    28,    74,    30,     3,     4,     5,    38,
      35,    36,    37,    10,    38,    38,    13,    38,    38,    14,
      14,    11,    11,    11,    27,    11,    27,    24,    16,    17,
      18,    19,    20,    21,    22,    23,     3,     4,     5,    11,
      39,    25,    25,    10,    26,    13,    13,    16,    17,    18,
      19,    20,    21,    22,    23,    26,    29,    14,    -1,    25,
      25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    28,    30,    31,    32,    33,    34,    35,    36,
      37,    41,    42,    43,    44,    45,    47,    48,    51,    52,
      54,    57,    58,    15,    10,    10,    13,    13,    13,    13,
      10,    10,     3,     4,     5,    10,    13,    64,    65,    66,
       0,    43,    38,    38,    38,    38,    38,    64,    24,    63,
      64,    67,    63,    14,    55,    14,    53,    64,     6,     7,
       8,     9,    10,    67,    11,    16,    17,    18,    19,    20,
      21,    22,    23,    11,    27,    11,    27,    11,    11,    65,
      65,    66,    66,    64,    67,    59,    67,    67,    64,    64,
      64,    64,    64,    64,    49,    56,    64,    39,    11,    25,
      25,    13,    46,    46,    47,    60,    50,    26,    26,    29,
      61,    62,    25,    46,    26
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    43,    43,    44,    44,    45,    45,
      45,    45,    46,    46,    47,    47,    47,    47,    47,    47,
      49,    50,    48,    51,    52,    53,    54,    55,    55,    56,
      57,    59,    60,    58,    62,    61,    61,    63,    64,    64,
      64,    65,    65,    65,    66,    66,    66,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     1,     2,     2,
       2,     2,     0,     2,     1,     2,     2,     2,     2,     1,
       0,     0,     9,     2,     4,     4,     4,     3,     1,     1,
       3,     0,     0,    10,     0,     5,     0,     1,     3,     3,
       1,     3,     3,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     4,     1
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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = yylex ();
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 8: /* declaration: INTtype ID  */
#line 90 "parser.y"
                 {
      fprintf(fptr, "\t");
      char* temp = strdup((yyvsp[0].name));
      declareVariableAtTable(hashTable, (yyvsp[0].name), Int);
      fprintf(fptr, "%%var%d = alloca i32, align 4\n", getSymbolTableValue(hashTable, temp).index, temp);
      free(temp);
      }
#line 1234 "parser.tab.c"
    break;

  case 9: /* declaration: FLOATtype ID  */
#line 97 "parser.y"
                   {
      fprintf(fptr, "\t");
      char* temp = strdup((yyvsp[0].name));
      declareVariableAtTable(hashTable, (yyvsp[0].name), Float);
      fprintf(fptr, "%%var%d = alloca float, align 4\n", getSymbolTableValue(hashTable, temp).index, temp);
      free(temp);
      }
#line 1246 "parser.tab.c"
    break;

  case 10: /* declaration: BOOLEANtype ID  */
#line 104 "parser.y"
                     {fprintf(fptr, "bool %s;\n", strdup((yyvsp[0].name))); declareVariableAtTable(hashTable, (yyvsp[0].name), Bool);}
#line 1252 "parser.tab.c"
    break;

  case 11: /* declaration: CHARtype ID  */
#line 105 "parser.y"
                  {
      fprintf(fptr, "\t");
      char* temp = strdup((yyvsp[0].name));
      declareVariableAtTable(hashTable, (yyvsp[0].name), Char);
      fprintf(fptr, "%%var%d = alloca i8, align 1\n", getSymbolTableValue(hashTable, temp).index, temp);
      free(temp);
      }
#line 1264 "parser.tab.c"
    break;

  case 20: /* $@1: %empty  */
#line 129 "parser.y"
                                  {
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");
      fprintf(fptr, "br label %%Label%d\n\n", lastLabel);
      fprintf(fptr, "Label%d:\n", lastLabel);
      pilePush(labelStack, lastLabel++);
      printTempSymbTableToFile(fptr, tabelaTemp, lastTemp, indentation, Int);
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");
      fprintf(fptr, "br i1 %%%d, label %%Label%d, label %%Label%d\n", lastTemp-1 + tempCounter, lastLabel+1, lastLabel);
      tempCounter += lastTemp;
      lastTemp = 0; 
      pilePush(labelStack, lastLabel);
      lastLabel++;
      fprintf(fptr, "Label%d:\n", lastLabel++);
      }
#line 1283 "parser.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 142 "parser.y"
                        {
      tempCounter += lastTemp;
      lastTemp = 0;
      }
#line 1292 "parser.tab.c"
    break;

  case 22: /* while_command: WHILE LEFT logical_expr RIGHT $@1 B_LEFT commands $@2 B_RIGHT  */
#line 145 "parser.y"
                {
      int temp = (int) popPile(labelStack);
      fprintf(fptr, "br label %%Label%d\n\n", (int) popPile(labelStack));
      fprintf(fptr, "Label%d:\n", temp);
      }
#line 1302 "parser.tab.c"
    break;

  case 23: /* return_command: returnCommand expr  */
#line 152 "parser.y"
                       {
      printTempSymbTableToFile(fptr, tabelaTemp, lastTemp, indentation, Int);
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");
      fprintf(fptr, "ret i32 %s\n", tabelaTemp[lastTemp-1].result);
      tempCounter += lastTemp;
      lastTemp = 0;
}
#line 1314 "parser.tab.c"
    break;

  case 24: /* read_command: readCommand LEFT read_value RIGHT  */
#line 161 "parser.y"
                                      {
        have_scanf = 1;
    }
#line 1322 "parser.tab.c"
    break;

  case 25: /* read_value: STRING COMMA '&' ID  */
#line 165 "parser.y"
                               {
    String temp;
    Types type = parseString((yyvsp[-3].name), &temp); /* Parseando para identificar o tipo da string */
    if (type != TypeError){
      for (int i = 0; i < indentation; i++) { fprintf(fptr, "\t"); }
      char* aux;
      aux = strdup((yyvsp[0].name));
      fprintf(fptr, "%%%d = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str.%d, ptr noundef %%var%d)\n", tempCounter + lastTemp, stringsCount,getSymbolTableValue(hashTable, aux).index);
      stringsEstaticas[stringsCount++] = temp;
      tempCounter++;
      free(aux);
    }
}
#line 1340 "parser.tab.c"
    break;

  case 26: /* write_command: writeCommand LEFT write_value RIGHT  */
#line 181 "parser.y"
                                        { have_printf = 1; }
#line 1346 "parser.tab.c"
    break;

  case 27: /* write_value: STRING COMMA write_formats  */
#line 185 "parser.y"
                                 {
      String temp;
      Types type = parseString((yyvsp[-2].name), &temp);
      printTempSymbTableToFile(fptr, tabelaTemp, lastTemp, indentation, type);
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");

      switch (type) {
        case Float:
        fprintf(fptr, "%%%d = fpext float %s to double\n", tempCounter + lastTemp, tabelaTemp[lastTemp-1].result);
        tempCounter++;
        fprintf(fptr, "%%%d = call i32 (ptr, ...) @printf(ptr noundef @.str.%d, double noundef %%%d)\n", tempCounter + lastTemp, stringsCount, tempCounter + lastTemp - 1);
        break;
        case Int:
        fprintf(fptr, "%%%d = call i32 (ptr, ...) @printf(ptr noundef @.str.%d, i32 noundef %s)\n", tempCounter + lastTemp, stringsCount, tabelaTemp[lastTemp-1].result);
        break;
        case Char:
        fprintf(fptr, "%%%d = sext i8 %s to i32\n", tempCounter + lastTemp, tabelaTemp[lastTemp-1].result);
        tempCounter++;
        fprintf(fptr, "%%%d = call i32 (ptr, ...) @printf(ptr noundef @.str.%d, i32 noundef %%%d)\n", tempCounter + lastTemp, stringsCount, tempCounter + lastTemp - 1);
        break;
        case TypeError:
        printf("Má formatação no printf.\nEncerrando Compilação sem exito.\n");
        exit(EXIT_FAILURE);
        break;
      }
      stringsEstaticas[stringsCount] = temp;
      stringsCount++;
      tempCounter++;
      tempCounter += lastTemp;
      lastTemp = 0;
    }
#line 1382 "parser.tab.c"
    break;

  case 28: /* write_value: STRING  */
#line 216 "parser.y"
             {
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");
      fprintf(fptr, "%%%d = call i32 (ptr, ...) @printf(ptr noundef @.str.%d)\n", tempCounter + lastTemp, stringsCount);
      String temp;
      Types type = parseString((yyvsp[0].name), &temp);
      if (type != TypeError) {
        printf("Má formatação no printf.\nEncerrando Compilação sem exito.\n");
        exit(EXIT_FAILURE);
      }
      stringsEstaticas[stringsCount] = temp;
      stringsCount++;
      tempCounter++;
    }
#line 1400 "parser.tab.c"
    break;

  case 29: /* write_formats: expr  */
#line 232 "parser.y"
             {
        }
#line 1407 "parser.tab.c"
    break;

  case 30: /* atrib: ID EQUALS expr  */
#line 236 "parser.y"
                     {
      printTempSymbTableToFile(fptr, tabelaTemp, lastTemp, indentation, getSymbolTableValue(hashTable, (yyvsp[-2].name)).Type);
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");
      
      switch (getSymbolTableValue(hashTable, (yyvsp[-2].name)).Type) {
      case Float:
        fprintf(fptr, "store float %s, ptr %%var%d, align 4;\n", tabelaTemp[lastTemp-1].result, getSymbolTableValue(hashTable, (yyvsp[-2].name)).index);
        break;
      case Int:
        fprintf(fptr, "store i32 %s, ptr %%var%d, align 4;\n", tabelaTemp[lastTemp-1].result, getSymbolTableValue(hashTable, (yyvsp[-2].name)).index);
        break;
      case Char:
        fprintf(fptr, "store i8 %s, ptr %%var%d, align 1;\n", tabelaTemp[lastTemp-1].result, getSymbolTableValue(hashTable, (yyvsp[-2].name)).index);
      default:
        break;
      }
      tempCounter += lastTemp;
      lastTemp = 0;
    }
#line 1431 "parser.tab.c"
    break;

  case 31: /* $@3: %empty  */
#line 258 "parser.y"
                               {
      printTempSymbTableToFile(fptr, tabelaTemp, lastTemp, indentation, Int);
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");
      fprintf(fptr, "br i1 %%%d, label %%Label%d, label %%Label%d\n", lastTemp-1 + tempCounter, lastLabel+1, lastLabel);
      tempCounter += lastTemp;
      lastTemp = 0; 
      pilePush(labelStack, lastLabel);
      lastLabel++;
      fprintf(fptr, "Label%d:\n", lastLabel++);
      }
#line 1446 "parser.tab.c"
    break;

  case 32: /* $@4: %empty  */
#line 267 "parser.y"
                        {// printTempSymbTableToFile(fptr, tabelaTemp, lastTemp, indentation);
      tempCounter += lastTemp;
      lastTemp = 0;
      }
#line 1455 "parser.tab.c"
    break;

  case 34: /* $@5: %empty  */
#line 274 "parser.y"
           {
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");
      fprintf(fptr, "br label %%Label%d\n\n", lastLabel);
      fprintf(fptr, "Label%d:\n", (int) popPile(labelStack));
      pilePush(labelStack, lastLabel);
      lastLabel++;
      }
#line 1467 "parser.tab.c"
    break;

  case 35: /* else_command: ELSE $@5 B_LEFT commands B_RIGHT  */
#line 280 "parser.y"
                                {
      int temp = (int) popPile(labelStack);
      fprintf(fptr, "br label %%Label%d\n\n", temp);
      fprintf(fptr, "Label%d:\n", temp);
      }
#line 1477 "parser.tab.c"
    break;

  case 36: /* else_command: %empty  */
#line 285 "parser.y"
             {
      int temp = (int) popPile(labelStack);
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");
      fprintf(fptr, "br label %%Label%d\n\n", temp);
      fprintf(fptr, "Label%d:\n", temp);
    }
#line 1488 "parser.tab.c"
    break;

  case 37: /* logical_expr: logical_operations  */
#line 294 "parser.y"
                       {(yyval.intValue) = (yyvsp[0].intValue);}
#line 1494 "parser.tab.c"
    break;

  case 38: /* expr: expr PLUS term  */
#line 298 "parser.y"
                     {(yyval.doubleValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_PLUS;
      tabelaTemp[lastTemp].arg1 = (yyvsp[-2].doubleValue);
      tabelaTemp[lastTemp].arg2 = (yyvsp[0].doubleValue);
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
#line 1507 "parser.tab.c"
    break;

  case 39: /* expr: expr MINUS term  */
#line 306 "parser.y"
                      {(yyval.doubleValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_MINUS;
      tabelaTemp[lastTemp].arg1 = (yyvsp[-2].doubleValue);
      tabelaTemp[lastTemp].arg2 = (yyvsp[0].doubleValue);
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
#line 1520 "parser.tab.c"
    break;

  case 40: /* expr: term  */
#line 314 "parser.y"
           {(yyval.doubleValue) = (yyvsp[0].doubleValue);}
#line 1526 "parser.tab.c"
    break;

  case 41: /* term: term TIMES factor  */
#line 318 "parser.y"
                        {(yyval.doubleValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_MULT;
      tabelaTemp[lastTemp].arg1 = (yyvsp[-2].doubleValue);
      tabelaTemp[lastTemp].arg2 = (yyvsp[0].doubleValue);
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
#line 1539 "parser.tab.c"
    break;

  case 42: /* term: term DIVIDE factor  */
#line 326 "parser.y"
                         {(yyval.doubleValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_DIV;
      tabelaTemp[lastTemp].arg1 = (yyvsp[-2].doubleValue);
      tabelaTemp[lastTemp].arg2 = (yyvsp[0].doubleValue);
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
#line 1552 "parser.tab.c"
    break;

  case 43: /* term: factor  */
#line 334 "parser.y"
             {(yyval.doubleValue) = (yyvsp[0].doubleValue);}
#line 1558 "parser.tab.c"
    break;

  case 44: /* factor: DOUBLE  */
#line 338 "parser.y"
             {(yyval.doubleValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_EQUAL;
      tabelaTemp[lastTemp].arg1 = (yyvsp[0].doubleValue);
      tabelaTemp[lastTemp].arg2 = 0;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
    }
#line 1571 "parser.tab.c"
    break;

  case 45: /* factor: INT  */
#line 346 "parser.y"
          {(yyval.doubleValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_EQUAL;
      tabelaTemp[lastTemp].arg1 = (yyvsp[0].intValue);
      tabelaTemp[lastTemp].arg2 = 0;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
    }
#line 1584 "parser.tab.c"
    break;

  case 46: /* factor: CHARACTER  */
#line 354 "parser.y"
                {(yyval.doubleValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_EQUAL;
      tabelaTemp[lastTemp].arg1 = (yyvsp[0].character);
      tabelaTemp[lastTemp].arg2 = 0;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
    }
#line 1597 "parser.tab.c"
    break;

  case 47: /* factor: ID  */
#line 362 "parser.y"
         {
      (yyval.doubleValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_VAR;
      tabelaTemp[lastTemp].arg1 = 0;
      tabelaTemp[lastTemp].arg2 = 0;
      sprintf(str_num, "%%var%d", getSymbolTableValue(hashTable, (yyvsp[0].name)).index);
      strcpy(tabelaTemp[lastTemp].name, str_num);
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      free((yyvsp[0].name));
      }
#line 1614 "parser.tab.c"
    break;

  case 48: /* factor: LEFT expr RIGHT  */
#line 374 "parser.y"
                      {(yyval.doubleValue) = (yyvsp[-1].doubleValue);}
#line 1620 "parser.tab.c"
    break;

  case 49: /* logical_operations: logical_operations AND logical_operations  */
#line 378 "parser.y"
                                                {(yyval.intValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_AND;
      tabelaTemp[lastTemp].arg1 = (yyvsp[-2].intValue);
      tabelaTemp[lastTemp].arg2 = (yyvsp[0].intValue);
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
#line 1633 "parser.tab.c"
    break;

  case 50: /* logical_operations: logical_operations OR logical_operations  */
#line 386 "parser.y"
                                               {(yyval.intValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_OR;
      tabelaTemp[lastTemp].arg1 = (yyvsp[-2].intValue);
      tabelaTemp[lastTemp].arg2 = (yyvsp[0].intValue);
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
#line 1646 "parser.tab.c"
    break;

  case 51: /* logical_operations: logical_operations GT expr  */
#line 394 "parser.y"
                                 {(yyval.intValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_GT;
      tabelaTemp[lastTemp].arg1 = (yyvsp[-2].intValue);
      tabelaTemp[lastTemp].arg2 = (yyvsp[0].doubleValue);
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
#line 1659 "parser.tab.c"
    break;

  case 52: /* logical_operations: logical_operations GE expr  */
#line 402 "parser.y"
                                  {(yyval.intValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_GE;
      tabelaTemp[lastTemp].arg1 = (yyvsp[-2].intValue);
      tabelaTemp[lastTemp].arg2 = (yyvsp[0].doubleValue);
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
#line 1672 "parser.tab.c"
    break;

  case 53: /* logical_operations: logical_operations LT expr  */
#line 410 "parser.y"
                                 {(yyval.intValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_LT;
      tabelaTemp[lastTemp].arg1 = (yyvsp[-2].intValue);
      tabelaTemp[lastTemp].arg2 = (yyvsp[0].doubleValue);
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
#line 1685 "parser.tab.c"
    break;

  case 54: /* logical_operations: logical_operations LE expr  */
#line 418 "parser.y"
                                  {(yyval.intValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_LE;
      tabelaTemp[lastTemp].arg1 = (yyvsp[-2].intValue);
      tabelaTemp[lastTemp].arg2 = (yyvsp[0].doubleValue);
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
#line 1698 "parser.tab.c"
    break;

  case 55: /* logical_operations: logical_operations DIF expr  */
#line 426 "parser.y"
                                  {(yyval.intValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_DIF;
      tabelaTemp[lastTemp].arg1 = (yyvsp[-2].intValue);
      tabelaTemp[lastTemp].arg2 = (yyvsp[0].doubleValue);
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
#line 1711 "parser.tab.c"
    break;

  case 56: /* logical_operations: logical_operations l_EQUALS expr  */
#line 434 "parser.y"
                                       {(yyval.intValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_L_EQUAL;
      tabelaTemp[lastTemp].arg1 = (yyvsp[-2].intValue);
      tabelaTemp[lastTemp].arg2 = (yyvsp[0].doubleValue);
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
#line 1724 "parser.tab.c"
    break;

  case 57: /* logical_operations: NOT logical_operations  */
#line 442 "parser.y"
                             {(yyval.intValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_NOT;
      tabelaTemp[lastTemp].arg1 = (yyvsp[0].intValue);
      tabelaTemp[lastTemp].arg2 = 0;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
    }
#line 1737 "parser.tab.c"
    break;

  case 58: /* logical_operations: NOT LEFT logical_operations RIGHT  */
#line 450 "parser.y"
                                        {(yyval.intValue) = lastTemp;
      tabelaTemp[lastTemp].op = OP_NOT;
      tabelaTemp[lastTemp].arg1 = (yyvsp[-1].intValue);
      tabelaTemp[lastTemp].arg2 = 0;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
    }
#line 1750 "parser.tab.c"
    break;

  case 59: /* logical_operations: expr  */
#line 458 "parser.y"
           {(yyval.intValue) = (yyvsp[0].doubleValue);}
#line 1756 "parser.tab.c"
    break;


#line 1760 "parser.tab.c"

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
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 460 "parser.y"


int yywrap( ) {
  return 1;
}

void yyerror(const char* str) {
  fprintf(stderr, "Compiler error: '%s'.\n", str);
}

extern int yylex_destroy(void);
extern FILE *yyin;

int main(int argc, char *argv[]) {
  if (argc < 2) {
      fprintf(stderr, "Usage: %s <input-file>\n", argv[0]);
      return 1;
  }
  yyin = fopen(argv[1], "r");
  if (yyin == NULL) {
      fprintf(stderr, "Error opening file `%s`\n", argv[1]);
      return 1;
  }


  if (argc > 2)
    fptr = fopen(argv[2], "w");
  else
    fptr = fopen("saida.ll", "w");
  // Open a file in writing mode

  // int c; copiar conteudo do codigo fonte para a saida.
  // while ((c = fgetc(yyin)) != EOF)
  // {
  //     fputc(c, fptr);
  // }
  // fputc('\n', fptr);

  // fclose(yyin);
  // yyin = fopen(argv[1], "r");
  // if (yyin == NULL) {
  //     fprintf(stderr, "Error opening file `%s`\n", argv[1]);
  //     return 1;
  // }

  // Write some text to the file
  fprintf(fptr,"define i32 @main() {\nentry:\n");

  labelStack = createPile();
  hashTable = ht_create();
  yyparse();


  hti it = ht_iterator(hashTable);
  while (ht_next(&it)) {
    if (it.value) {
      free(it.value);
      it.value = NULL;
    }
  }
  ht_destroy(hashTable);
  yylex_destroy();
  fclose(stdin);
  fprintf(fptr,"\n}\n");


  fprintf(fptr,"\n\n");
  if (have_printf) {
    fprintf(fptr,"\n\n");
    fprintf(fptr,"declare i32 @printf(ptr noundef, ...) #1\n");
  }
  if (have_scanf) {
    fprintf(fptr,"declare i32 @__isoc99_scanf(ptr noundef, ...) #1\n\n");
  }
  // fprintf(fptr,"attributes #0 = { noinline nounwind optnone sspstrong uwtable \"frame-pointer\"=\"all\" \"min-legal-vector-width\"=\"0\" \"no-trapping-math\"=\"true\" \"stack-protector-buffer-size\"=\"8\" \"target-cpu\"=\"x86-64\" \"target-features\"=\"+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87\" \"tune-cpu\"=\"generic\" }\n");
  // fprintf(fptr,"attributes #1 = { \"frame-pointer\"=\"all\" \"no-trapping-math\"=\"true\" \"stack-protector-buffer-size\"=\"8\" \"target-cpu\"=\"x86-64\" \"target-features\"=\"+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87\" \"tune-cpu\"=\"generic\" }\n");

  for(int i = 0; i < stringsCount; i++) {
    fprintf(fptr,"@.str.%d = private unnamed_addr constant [%d x i8] c\"%s\", align 1\n",
            i, stringsEstaticas[i].size, stringsEstaticas[i].data);
    free(stringsEstaticas[i].data);
  }
  fclose(fptr); 
  destroyPile(labelStack);
  
  printTempSymbTable(tabelaTemp, lastTemp);
  return 0;
}
