/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "subc.y" /* yacc.c:339  */

/*
 * File Name   : subc.y
 * Description : a skeleton bison input
 */
#include "subc.h"
int    yylex ();
int    yyerror (char* s);
void    REDUCE(char* s);

#line 77 "subc.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "subc.tab.h".  */
#ifndef YY_YY_SUBC_TAB_H_INCLUDED
# define YY_YY_SUBC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    TYPE = 259,
    VOID = 260,
    ELSE = 261,
    LOGICAL_OR = 262,
    LOGICAL_AND = 263,
    EQUOP = 264,
    RELOP = 265,
    INCOP = 266,
    DECOP = 267,
    STRUCTOP = 268,
    STRUCT = 269,
    CHAR_CONST = 270,
    STRING = 271,
    INTEGER_CONST = 272,
    RETURN = 273,
    IF = 274,
    WHILE = 275,
    FOR = 276,
    BREAK = 277,
    CONTINUE = 278
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 13 "subc.y" /* yacc.c:355  */

	int	    intVal;
	double	    floatval;
	char	    *stringVal;
	struct id   *idptr;
	struct decl *declptr;
	struct ste  *steptr;

#line 150 "subc.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SUBC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 165 "subc.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,     2,     2,     2,    11,     2,
      22,    23,    16,    14,     7,    15,    24,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,     8,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    20,     2,    21,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
       5,     6,     9,    10,    12,    13,    18,    19,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    60,    61,    66,    76,    86,    88,    90,
      90,   103,   123,   127,   133,   133,   150,   174,   194,   214,
     214,   244,   250,   255,   261,   269,   279,   291,   293,   297,
     307,   317,   323,   331,   335,   339,   341,   345,   347,   349,
     353,   357,   359,   360,   361,   362,   363,   364,   367,   368,
     372,   386,   407,   410,   413,   423,   426,   429,   439,   442,
     445,   448,   451,   454,   462,   468,   474,   477,   480,   483,
     495,   503,   511,   515,   519,   525,   531,   544,   557,   567,
     579,   591,   609,   621,   625
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "TYPE", "VOID", "ELSE", "','",
  "'='", "LOGICAL_OR", "LOGICAL_AND", "'&'", "EQUOP", "RELOP", "'+'",
  "'-'", "'*'", "'!'", "INCOP", "DECOP", "'['", "']'", "'('", "')'", "'.'",
  "STRUCTOP", "STRUCT", "CHAR_CONST", "STRING", "INTEGER_CONST", "RETURN",
  "IF", "WHILE", "FOR", "BREAK", "CONTINUE", "';'", "'{'", "'}'",
  "$accept", "program", "ext_def_list", "ext_def", "$@1", "type_specifier",
  "struct_specifier", "@2", "func_decl", "@3", "pointers", "param_list",
  "param_decl", "def_list", "def", "compound_stmt", "local_defs",
  "stmt_list", "stmt", "expr_e", "const_expr", "expr", "or_expr",
  "or_list", "and_expr", "and_list", "binary", "unary", "args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,    44,    61,   262,
     263,    38,   264,   265,    43,    45,    42,    33,   266,   267,
      91,    93,    40,    41,    46,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,    59,   123,   125
};
# endif

#define YYPACT_NINF -126

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-126)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -126,    22,    10,  -126,  -126,  -126,    21,  -126,     1,  -126,
     -10,    -9,  -126,  -126,    30,  -126,     9,  -126,    -2,  -126,
    -126,  -126,   183,     7,  -126,    10,  -126,     6,  -126,   183,
     183,   183,   183,   183,   183,   183,  -126,  -126,  -126,    44,
    -126,  -126,    54,  -126,    76,    87,   208,    69,  -126,    10,
      11,    52,  -126,    42,  -126,    65,    65,    65,    65,    65,
      65,    70,   195,    58,   183,   183,   183,   183,   183,   183,
     183,  -126,  -126,   183,   162,   101,   102,  -126,    90,    43,
    -126,  -126,   106,  -126,   140,    88,    89,    92,    81,    82,
    -126,  -126,  -126,  -126,    93,  -126,  -126,  -126,  -126,    65,
      87,    41,    53,  -126,  -126,  -126,    91,  -126,   118,   103,
    -126,  -126,   127,    10,  -126,    -1,  -126,    95,   183,   183,
     183,  -126,  -126,  -126,  -126,   183,  -126,   129,  -126,   183,
    -126,  -126,   130,   131,   114,  -126,  -126,   183,   139,   105,
     105,   183,   142,   116,   155,  -126,   128,  -126,  -126,   105,
     183,  -126,   143,   105,  -126
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    11,    12,     0,     3,    22,    13,
       9,    16,    21,     8,     0,     7,     0,    14,     0,    28,
      10,    28,     0,    19,     5,    34,    36,     0,    69,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    66,     0,
      50,    52,    53,    55,    56,    58,    63,     0,    17,     0,
      22,     0,    27,     0,    15,    76,    70,    77,    71,    74,
      75,     0,    63,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    73,     0,     0,     0,     0,    18,    22,     0,
      23,    31,     0,    32,     0,     0,     0,     0,     0,     0,
      41,    33,    38,    35,     0,    64,    65,     6,    54,    63,
      57,    60,    59,    61,    62,    51,     0,    82,    83,     0,
      79,    80,     0,     0,    20,     0,    39,     0,     0,     0,
      49,    46,    47,    37,    78,     0,    81,    25,    24,     0,
      29,    40,     0,     0,     0,    48,    84,     0,     0,     0,
       0,    49,     0,     0,    42,    44,     0,    26,    30,     0,
      49,    43,     0,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,  -126,  -126,     0,  -126,  -126,   168,  -126,
     -49,  -126,    59,   150,  -126,   158,  -126,  -126,   -58,  -125,
    -106,   -22,  -126,  -126,   111,  -126,    79,   -26,    57
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    16,    50,     9,    21,    51,    49,
      14,    79,    80,    25,    52,    92,    26,    53,    93,   134,
      39,    94,    41,    42,    43,    44,    45,    46,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    82,     8,    55,    56,    57,    58,    59,    60,    62,
       4,     5,    47,    61,     4,     5,   146,    12,    22,   129,
      23,    23,     3,   138,    11,   152,    15,    12,    17,   112,
      48,   142,     6,    18,    24,   130,     6,    13,    99,    99,
      99,    99,    99,    99,    54,    28,    19,    81,   105,    78,
     113,   106,   108,    29,    67,    68,    69,    30,    31,    32,
      33,    34,   117,    64,    35,    63,   114,    68,    69,    36,
      37,    38,    84,    85,    86,    87,    88,    89,    90,    19,
      91,   144,   145,    71,    72,    73,    65,    74,    83,    75,
      76,   151,    77,    95,    97,   154,   132,   133,   135,    66,
      67,    68,    69,   108,   110,   111,    12,    40,    28,   115,
     118,   119,   124,    78,   120,    40,    29,   121,   122,   135,
      30,    31,    32,    33,    34,   125,   126,    35,   135,   123,
     127,   131,    36,    37,    38,    84,    85,    86,    87,    88,
      89,    90,    19,    28,   100,   101,   102,   103,   104,   137,
     141,    29,   148,   139,   140,    30,    31,    32,    33,    34,
     143,   149,    35,   147,   150,    28,   153,    36,    37,    38,
      10,    27,   128,    29,    20,    98,   116,    30,    31,    32,
      33,    34,   136,     0,    35,   107,    28,     0,     0,    36,
      37,    38,     0,     0,    29,     0,     0,     0,    30,    31,
      32,    33,    34,    70,     0,    35,     0,     0,     0,     0,
      36,    37,    38,    71,    72,    73,    70,    74,    96,    75,
      76,     0,     0,     0,     0,     0,    71,    72,    73,     0,
      74,     0,    75,    76
};

static const yytype_int16 yycheck[] =
{
      22,    50,     2,    29,    30,    31,    32,    33,    34,    35,
       4,     5,     5,    35,     4,     5,   141,    16,    20,    20,
      22,    22,     0,   129,     3,   150,    36,    16,    37,    78,
      23,   137,    26,     3,    36,    36,    26,    36,    64,    65,
      66,    67,    68,    69,    38,     3,    37,    36,    70,    49,
       7,    73,    74,    11,    13,    14,    15,    15,    16,    17,
      18,    19,    84,     9,    22,    21,    23,    14,    15,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,   139,   140,    18,    19,    20,    10,    22,    36,    24,
      25,   149,    23,    23,    36,   153,   118,   119,   120,    12,
      13,    14,    15,   125,     3,     3,    16,   129,     3,     3,
      22,    22,    21,   113,    22,   137,    11,    36,    36,   141,
      15,    16,    17,    18,    19,     7,    23,    22,   150,    36,
       3,    36,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,     3,    65,    66,    67,    68,    69,    20,
      36,    11,    36,    23,    23,    15,    16,    17,    18,    19,
      21,     6,    22,    21,    36,     3,    23,    27,    28,    29,
       2,    21,   113,    11,    16,    64,    36,    15,    16,    17,
      18,    19,   125,    -1,    22,    23,     3,    -1,    -1,    27,
      28,    29,    -1,    -1,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,     8,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    18,    19,    20,     8,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
      22,    -1,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,     0,     4,     5,    26,    42,    44,    45,
      47,     3,    16,    36,    49,    36,    43,    37,     3,    37,
      54,    46,    20,    22,    36,    52,    55,    52,     3,    11,
      15,    16,    17,    18,    19,    22,    27,    28,    29,    59,
      60,    61,    62,    63,    64,    65,    66,     5,    23,    48,
      44,    47,    53,    56,    38,    66,    66,    66,    66,    66,
      66,    60,    66,    21,     9,    10,    12,    13,    14,    15,
       8,    18,    19,    20,    22,    24,    25,    23,    44,    50,
      51,    36,    49,    36,    30,    31,    32,    33,    34,    35,
      36,    38,    54,    57,    60,    23,    23,    36,    63,    66,
      65,    65,    65,    65,    65,    60,    60,    23,    60,    67,
       3,     3,    49,     7,    23,     3,    36,    60,    22,    22,
      22,    36,    36,    36,    21,     7,    23,     3,    51,    20,
      36,    36,    60,    60,    58,    60,    67,    20,    59,    23,
      23,    36,    59,    21,    57,    57,    58,    21,    36,     6,
      36,    57,    58,    23,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    42,    43,
      42,    44,    44,    44,    46,    45,    45,    47,    47,    48,
      47,    49,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    53,    53,    54,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      59,    60,    60,    61,    62,    62,    63,    64,    64,    65,
      65,    65,    65,    65,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     7,     2,     2,     0,
       3,     1,     1,     1,     0,     6,     2,     5,     6,     0,
       7,     1,     0,     1,     3,     3,     6,     2,     0,     4,
       7,     2,     2,     4,     1,     2,     0,     2,     1,     2,
       3,     1,     5,     7,     5,     9,     2,     2,     1,     0,
       1,     3,     1,     1,     3,     1,     1,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     4,     3,
       3,     4,     3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 4:
#line 61 "subc.y" /* yacc.c:1646  */
    {
	}
#line 1363 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 66 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-3].declptr) && !check_is_declared_for_else((yyvsp[-1].idptr)))	//ID와 동일한 ste가 현재 scope에 있는지 확인
		    {
			declare((yyvsp[-1].idptr), makevardecl((yyvsp[-2].declptr)? (yyvsp[-2].declptr):(yyvsp[-3].declptr))); 
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 1378 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 76 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-6].declptr) && (yyvsp[-2].declptr) && !check_is_declared_for_else((yyvsp[-4].idptr)))
		    {
			declare((yyvsp[-4].idptr), makeconstdecl(makearraydecl((yyvsp[-2].declptr)->intvalue, makevardecl((yyvsp[-5].declptr)? (yyvsp[-5].declptr):(yyvsp[-6].declptr)))));
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 1393 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 86 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1400 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 88 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1407 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 90 "subc.y" /* yacc.c:1646  */
    { 
		    push_scope();
		    if((yyvsp[0].declptr))
			push_ste_list((yyvsp[0].declptr)->formals);
		}
#line 1417 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 95 "subc.y" /* yacc.c:1646  */
    {
		    free_scope();
		    if((yyvsp[-2].declptr))
			(yyvsp[-2].declptr)->isdeclared = 1;
		}
#line 1427 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 103 "subc.y" /* yacc.c:1646  */
    {
		    struct decl *typeptr = finddecl((yyvsp[0].idptr));
		    if(typeptr)
		    {
			if(check_is_type(typeptr))  
			{
			    (yyval.declptr) = typeptr; 
			}
			else
			{
			    //error
			    (yyval.declptr) = NULL;
			}
		    }
		    else
		    {
			//error
			(yyval.declptr) = NULL;
		    }
		}
#line 1452 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 123 "subc.y" /* yacc.c:1646  */
    {
		    struct decl *typeptr = finddecl((yyvsp[0].idptr));
		    (yyval.declptr) = typeptr;
		}
#line 1461 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 127 "subc.y" /* yacc.c:1646  */
    { 
		    (yyval.declptr) = (yyvsp[0].declptr);
		}
#line 1469 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 133 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = check_is_declared_for_struct((yyvsp[-1].idptr));
		    push_scope();
		}
#line 1478 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 137 "subc.y" /* yacc.c:1646  */
    {
		    struct ste *fields = pop_scope();
		    if(!(yyvsp[-2].declptr))
		    {
			pushStr((yyvsp[-4].idptr), (yyval.declptr) = makestructdecl(fields));
		    }
		    else
		    {
			//error
			free_ste_list(fields);
			(yyval.declptr) = NULL;
		    }
		}
#line 1496 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 150 "subc.y" /* yacc.c:1646  */
    {
		    struct decl *declptr = findstructdecl((yyvsp[0].idptr));
		    if(declptr)
		    {
			if(check_is_struct_type(declptr))
			{
			    (yyval.declptr) = declptr;
			}
			else
			{
			    //error
			    (yyval.declptr) = NULL;
			}
		    }
		    else
		    {
			//error;
			yyerror("struct is not declared");
			(yyval.declptr) = NULL;
		    }
		}
#line 1522 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 174 "subc.y" /* yacc.c:1646  */
    {
		    struct decl *procdecl = makeprocdecl();
		    push_scope();
		    declare(returnid, (yyvsp[-3].declptr)? (yyvsp[-3].declptr):(yyvsp[-4].declptr));
		    struct ste *formals;
		    formals = pop_scope();
		    procdecl->returntype = formals->decl;
		    procdecl->formals = formals;
		    if(!check_is_declared_for_else((yyvsp[-2].idptr)))
		    {
			(yyval.declptr) = procdecl;
			declare((yyvsp[-2].idptr), (yyval.declptr));
		    }
		    else
		    {
			free(procdecl);
			free_ste_list(formals);
			(yyval.declptr) = NULL;
		    }
		}
#line 1547 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 194 "subc.y" /* yacc.c:1646  */
    {
		    struct decl *procdecl = makeprocdecl();
		    push_scope();
		    declare(returnid, (yyvsp[-4].declptr)? (yyvsp[-4].declptr):(yyvsp[-5].declptr));
		    struct ste *formals;
		    formals = pop_scope();
		    procdecl->returntype = formals->decl;
		    procdecl->formals = formals;
		    if(!check_is_declared_for_else((yyvsp[-3].idptr)))
		    {
			(yyval.declptr) = procdecl;
			declare((yyvsp[-3].idptr), (yyval.declptr));
		    }
		    else
		    {
			free(procdecl);
			free_ste_list(formals);
			(yyval.declptr) = NULL;
		    }
		}
#line 1572 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 214 "subc.y" /* yacc.c:1646  */
    {
		    struct decl *procdecl = makeprocdecl();
		    (yyvsp[0].declptr) = check_is_declared_for_else((yyvsp[-1].idptr));
		    push_scope();
		    declare(returnid, (yyvsp[-2].declptr)? (yyvsp[-2].declptr):(yyvsp[-3].declptr));
		    (yyval.declptr) = procdecl;
		}
#line 1584 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 220 "subc.y" /* yacc.c:1646  */
    {
		    struct ste *formals;
		    struct decl *procdecl = (yyvsp[-2].declptr);
		    formals = pop_scope();
		    /* pop_scope reverses stes(first one is the returnid) */
		    procdecl->returntype = formals->decl; /* No for type checking */
		    procdecl->formals = formals;	// must check again
		    if(!(yyvsp[-3].declptr) && (yyvsp[-1].declptr))
		    {
			(yyval.declptr) = procdecl;
			declare((yyvsp[-4].idptr), (yyval.declptr));
		    }
		    //push_scope(); /* for installing formals & locals in this scope */
		    //pushstelist(formals); 
		    else
		    {
			free(procdecl);
			free_ste_list(formals);
			(yyval.declptr) = NULL;
		    }
		}
#line 1610 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 244 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-1].declptr))
			(yyval.declptr) = makeptrdecl((yyvsp[-1].declptr));
		    else
			(yyval.declptr) = NULL;
		}
#line 1621 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 250 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = NULL;
		}
#line 1629 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 255 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[0].declptr))
			(yyval.declptr) = (yyvsp[0].declptr);
		    else
			(yyval.declptr) = NULL;
		}
#line 1640 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 261 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-2].declptr) && (yyvsp[0].declptr))
			(yyval.declptr) = (yyvsp[-2].declptr);
		    else
			(yyval.declptr) = NULL;
		}
#line 1651 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 269 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-2].declptr) && !check_is_declared_for_else((yyvsp[0].idptr)))
		    {
			declare((yyvsp[0].idptr), makevardecl((yyvsp[-1].declptr)? (yyvsp[-1].declptr):(yyvsp[-2].declptr)));
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 1666 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 279 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-5].declptr) && (yyvsp[-1].declptr) && !check_is_declared_for_else((yyvsp[-3].idptr)))
		    {
			declare((yyvsp[-3].idptr), makeconstdecl(makearraydecl((yyvsp[-1].declptr)->intvalue, makevardecl((yyvsp[-4].declptr)? (yyvsp[-4].declptr):(yyvsp[-5].declptr)))));
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 1681 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 291 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1688 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 293 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1695 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 297 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-3].declptr) && !check_is_declared_for_else((yyvsp[-1].idptr)))
		    {
			declare((yyvsp[-1].idptr), makevardecl((yyvsp[-2].declptr)? (yyvsp[-2].declptr):(yyvsp[-3].declptr)));
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 1710 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 307 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-6].declptr) && (yyvsp[-2].declptr) && !check_is_declared_for_else((yyvsp[-4].idptr)))
		    {
			declare((yyvsp[-4].idptr), makeconstdecl(makearraydecl((yyvsp[-2].declptr)->intvalue, makevardecl((yyvsp[-5].declptr)? (yyvsp[-5].declptr):(yyvsp[-6].declptr)))));
		    }
		    else
		    {
			(yyval.declptr)= NULL;
		    }
		}
#line 1725 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 317 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-1].declptr))
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 1736 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 323 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-1].declptr))
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 1747 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 331 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1754 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 335 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1761 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 339 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1768 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 341 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1775 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 345 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1782 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 347 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1789 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 349 "subc.y" /* yacc.c:1646  */
    {
		   if(!check_compatible(finddecl(returnid), voidtype))
			yyerror("not compatible");
		}
#line 1798 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 353 "subc.y" /* yacc.c:1646  */
    {
		    if(!check_compatible(finddecl(returnid), (yyvsp[-1].declptr)))
			yyerror("not compatible");
		}
#line 1807 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 357 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1814 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 368 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1821 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 372 "subc.y" /* yacc.c:1646  */
    {
		    if(check_compatible_type((yyvsp[0].declptr), inttype))
		    {
			(yyval.declptr) = (yyvsp[0].declptr);
		    }
		    else
		    {
			yyerror("not inttype");
			(yyval.declptr) = NULL;
		    }

		}
#line 1838 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 386 "subc.y" /* yacc.c:1646  */
    {
		    if(check_is_var_type((yyvsp[-2].declptr)))
		    {
			if(check_compatible((yyvsp[-2].declptr)->type, (yyvsp[0].declptr)))
			{
			    (yyval.declptr) = (yyvsp[-2].declptr)->type;
			}
			else
			{
			    if((yyvsp[0].declptr))
				yyerror("not compatible");
			    (yyval.declptr) = NULL;
			}
		    }
		    else
		    {
			if((yyvsp[-2].declptr))
			    yyerror("not variable");
			(yyval.declptr) = NULL;
		    }
		}
#line 1864 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 413 "subc.y" /* yacc.c:1646  */
    {
		    if(check_compatible_type((yyvsp[-2].declptr), inttype) && check_compatible_type((yyvsp[0].declptr), inttype))
		    {
			(yyval.declptr) = (yyvsp[-2].declptr);
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 1879 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 429 "subc.y" /* yacc.c:1646  */
    {
		    if(check_compatible_type((yyvsp[-2].declptr), inttype) && check_compatible_type((yyvsp[0].declptr), inttype))
		    {
			(yyval.declptr) = (yyvsp[-2].declptr);
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 1894 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 442 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = reloptype((yyvsp[-2].declptr), (yyvsp[0].declptr));
		}
#line 1902 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 445 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = equoptype((yyvsp[-2].declptr), (yyvsp[0].declptr));
		}
#line 1910 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 448 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = plustype((yyvsp[-2].declptr), (yyvsp[0].declptr));
		}
#line 1918 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 451 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = minustype((yyvsp[-2].declptr), (yyvsp[0].declptr));
		}
#line 1926 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 454 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[0].declptr))
			(yyval.declptr) = (yyvsp[0].declptr)->type;
		    else 
			(yyval.declptr) = NULL;
		}
#line 1937 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 462 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-1].declptr))
			declare(dummy, (yyval.declptr) = makeconstdecl((yyvsp[-1].declptr)));
		    else
			(yyval.declptr) = NULL;
		}
#line 1948 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 468 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-1].declptr))
			(yyval.declptr) = (yyvsp[-1].declptr);
		    else
			(yyval.declptr) = NULL;
		}
#line 1959 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 474 "subc.y" /* yacc.c:1646  */
    {
		    declare(dummy, (yyval.declptr) = makenumconstdecl(inttype, (yyvsp[0].intVal)));
		}
#line 1967 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 477 "subc.y" /* yacc.c:1646  */
    {
		    declare(dummy, (yyval.declptr) = makecharconstdecl(chartype, (yyvsp[0].stringVal)));
		}
#line 1975 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 480 "subc.y" /* yacc.c:1646  */
    {
		    declare(dummy, (yyval.declptr) = makestringconstdecl(chartype, (yyvsp[0].stringVal)));
		}
#line 1983 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 483 "subc.y" /* yacc.c:1646  */
    {
		    if(finddecl((yyvsp[0].idptr)))
		    {
			(yyval.declptr) = finddecl((yyvsp[0].idptr));
		    }
		    else
		    {
			//error
			yyerror("not declared");
			(yyval.declptr) = NULL;
		    }
		}
#line 2000 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 495 "subc.y" /* yacc.c:1646  */
    {
		    if(check_compatible_type((yyvsp[0].declptr)->type, inttype))
		    {
			(yyval.declptr) = (yyvsp[0].declptr);
		    }
		    else
			(yyval.declptr) = NULL;
		}
#line 2013 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 503 "subc.y" /* yacc.c:1646  */
    {
		    if(check_compatible_type((yyvsp[0].declptr)->type, inttype))
		    {
			(yyval.declptr) = (yyvsp[0].declptr);
		    }
		    else
			(yyval.declptr) = NULL;
		}
#line 2026 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 511 "subc.y" /* yacc.c:1646  */
    {
		    if(!INDECOPtype((yyvsp[-1].declptr)->type))
			(yyval.declptr) = NULL;
		}
#line 2035 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 515 "subc.y" /* yacc.c:1646  */
    {
		    if(!INDECOPtype((yyvsp[-1].declptr)->type))
			(yyval.declptr) = NULL;
		}
#line 2044 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 519 "subc.y" /* yacc.c:1646  */
    {
		    if(!INDECOPtype((yyvsp[0].declptr)->type))
			(yyval.declptr) = NULL;
		    else
			(yyval.declptr) = (yyvsp[0].declptr);
		}
#line 2055 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 525 "subc.y" /* yacc.c:1646  */
    {
		    if(!INDECOPtype((yyvsp[0].declptr)->type))
			(yyval.declptr) = NULL;
		    else
			(yyval.declptr) = (yyvsp[0].declptr);
		}
#line 2066 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 531 "subc.y" /* yacc.c:1646  */
    {
		    if(check_is_var_type((yyvsp[0].declptr)))
		    {
			declare(dummy, (yyval.declptr) = makeconstdecl(makeptrdecl((yyvsp[0].declptr)->type)));
		    }
		    else
		    {
			//error
			if((yyvsp[0].declptr))
			    yyerror("not variable");
			(yyval.declptr) = NULL;
		    }
		}
#line 2084 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 544 "subc.y" /* yacc.c:1646  */
    {
		    if(check_is_var_type((yyvsp[0].declptr)) && check_is_ptr_type((yyvsp[0].declptr)->type))
		    {
			declare(dummy, (yyval.declptr) = makevardecl((yyvsp[0].declptr)->type->ptrto));
		    }
		    else
		    {
			//error
			if((yyvsp[0].declptr))
			    yyerror("not variable");
			(yyval.declptr) = NULL;
		    }
		}
#line 2102 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 557 "subc.y" /* yacc.c:1646  */
    {
		    if(check_is_const_type((yyvsp[-3].declptr)))
		    {
			(yyval.declptr) = arrayaccess((yyvsp[-3].declptr), (yyvsp[-1].declptr));
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 2117 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 567 "subc.y" /* yacc.c:1646  */
    {
		    if(check_is_var_type((yyvsp[-2].declptr)))
		    {
			(yyval.declptr) = structaccess((yyvsp[-2].declptr), (yyvsp[0].idptr));
		    }
		    else
		    {
			if((yyvsp[-2].declptr))
			    yyerror("not variable");
			(yyval.declptr) = NULL;
		    }
		}
#line 2134 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 579 "subc.y" /* yacc.c:1646  */
    {
		    if(check_is_var_type((yyvsp[-2].declptr)))
		    {
			(yyval.declptr) = structPtraccess((yyvsp[-2].declptr), (yyvsp[0].idptr));
		    }
		    else
		    {
			if((yyvsp[-1].stringVal))
			    yyerror("not variable");
			(yyval.declptr) = NULL;
		    }
		}
#line 2151 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 591 "subc.y" /* yacc.c:1646  */
    {
		    if(check_is_proc((yyvsp[-3].declptr)))
		    {
			(yyval.declptr) = check_function_call((yyvsp[-3].declptr), (yyvsp[-1].declptr));
			//must delete args
		    }
		    else
		    {	
			(yyval.declptr) = NULL;
		    }

		    struct decl *temp = (yyvsp[-1].declptr);
		    while(temp)
		    {
			free(temp);
			temp = temp->next;
		    }
		}
#line 2174 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 609 "subc.y" /* yacc.c:1646  */
    {
		    if(check_is_proc((yyvsp[-2].declptr)))
		    {
			(yyval.declptr)  = check_function_call((yyvsp[-2].declptr), NULL);
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 2189 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 621 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = makevardecl((yyvsp[0].declptr));
		    (yyval.declptr)->next = NULL;
		}
#line 2198 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 625 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = makevardecl((yyvsp[-2].declptr));
		    (yyval.declptr)->next = (yyvsp[0].declptr);
		}
#line 2207 "subc.tab.c" /* yacc.c:1646  */
    break;


#line 2211 "subc.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 630 "subc.y" /* yacc.c:1906  */


/*  Additional C Codes 
 	Implemnt REDUCE function here */

int    yyerror (char* s)
{
    if(filename)
    {
	fprintf (stderr, "%s:%d: error: %s\n", filename, read_line(), s);
    }
    else
    {
	fprintf (stderr, "%d: error: %s\n", read_line(), s);
    }
}

void 	REDUCE( char* s)
{
	printf("%s\n",s);
}

void init_type()
{
    SStack.TOP = (struct ScopeNode*)malloc(sizeof(struct ScopeNode));
    SStack.TOP->prev = NULL;
    SStack.TOP->top = NULL;
    StrStack = NULL;

    inttype = maketypedecl(Hash("int"));
    chartype = maketypedecl(Hash("char"));
    voidtype = maketypedecl(VOID);

    declare(enter(TYPE, "int", 3), inttype);
    declare(enter(TYPE, "char", 4), chartype);
    declare(enter(VOID, "void", 4), voidtype);
    returnid = enter(ID, "*return", 7);
    dummy = enter(ID, "*dummy", 6);
}

struct ste *push_scope()	/* SStack.TOP에다가 새로히 ScopeNode를 만들고 연결 시킨다. */
{
    struct ScopeNode *temp = SStack.TOP;
    SStack.TOP = (struct ScopeNode*)malloc(sizeof(struct ScopeNode));
    SStack.TOP->prev = temp;
    SStack.TOP->top = temp->top;
    return SStack.TOP->top;
}

struct ste *push_ste_list(struct ste *formals)	//완벽한 deep copy를 해준다.
{
    struct ste *ftemp = formals;
    while(ftemp)
    {
	if(ftemp->decl->declclass == TYPE)  //returnid의 경우 decl이 바로 TYPE을 가리키므로 ftemp->decl을 바로 사용한다.
	    declare(ftemp->name, ftemp->decl);
	else if(ftemp->decl->type->typeclass == Hash("array")) //array의 경우 pointer array일 경우와 그 외의 경우로 나눠서 deepcopy한다.
	{
	    if(ftemp->decl->type->elementvar->type->typeclass == Hash("ptr"))
	    {
		declare(ftemp->name, makeconstdecl(makearraydecl(ftemp->decl->type->intvalue, makevardecl(makeptrdecl(ftemp->decl->type->elementvar->type->ptrto)))));
	    }
	    else
	    {
		declare(ftemp->name, makeconstdecl(makearraydecl(ftemp->decl->type->intvalue, makevardecl(ftemp->decl->type->elementvar->type))));
	    }
	}
	else if(ftemp->decl->type->typeclass == Hash("ptr")) //pointer의 경우 ptrto를 사용해서 deepcopy한다.
	{
	    declare(ftemp->name, makevardecl(makeptrdecl(ftemp->decl->type->ptrto)));
	}
	else	//그 외의 경우 그냥 decl->type을 사용해서 deepcopy한다.
	{
	    declare(ftemp->name, makevardecl(ftemp->decl->type));
	}
	ftemp = ftemp->prev;
    }
    return SStack.TOP->top;
}


struct ste *pop_scope()		/* 현재 SStack.TOP->prev가 가르키는 ste까지 내려간다. */
{
    struct ste *temp = SStack.TOP->top;
    struct ste *temp3 = SStack.TOP->prev->top;
    struct ste *Head = NULL;

    if(temp == temp3)	/* push_scope()하고 아무것도 추가하지 않은 경우 */
    {
	SStack.TOP = SStack.TOP->prev;
	return temp;
    }

    while(temp != temp3)
    {
	struct ste *headtemp = Head;
	struct ste *stacktemp = temp->prev;
	Head = temp;
	Head->prev = headtemp;
	temp = stacktemp;
    }
    
    SStack.TOP = SStack.TOP->prev;	/* SStack.TOP의 scope를 한단계 낮춘다. */
    return Head;
}

struct ste *free_scope()    //function이 끝나고 ste를 전부 free시키는 함수
{
    struct ste *temp = SStack.TOP->top;
    struct ste *temp3 = SStack.TOP->prev->top;

    if(temp == temp3)
    {
	free(SStack.TOP);
	SStack.TOP = SStack.TOP->prev;
	return NULL;
    }

    while(temp != temp3)
    {
	free_ste(temp);
	temp = temp->prev;
    }

    free(SStack.TOP);
    SStack.TOP = SStack.TOP->prev;
    return NULL;
}

struct ste *free_ste_list(struct ste *steptr)
{
    struct ste *temp = steptr;
    while(temp)
    {
	free_ste(temp);
	temp = temp->prev;
    }
    return NULL;
}

struct ste *insert(id *entry, struct decl *declptr)	/* declare와 똑같은 함수 이다. */
{
    struct ste *STE = (struct ste*)malloc(sizeof(struct ste));
    STE->name = entry;			    /* ste를 새로 만들고 name에 entry를 넣는다. */
    STE->decl = declptr;		    /* decl에 declptr를 넣는다 */
    STE->prev = SStack.TOP->top;	    /* SStack.TOP->top을 prev에 넣는다. */
    SStack.TOP->top = STE;		    /* SStack.TOP->top를 새로운 ste로 바꿔준다. */
    return SStack.TOP->top;
}

struct ste *free_ste(struct ste *steptr)
{
    free_decl(steptr->decl);	//ste를 해제하고 그 decl도 해제한다.
    free(steptr);
    return NULL;
}

struct decl *free_decl(struct decl *declptr)
{
    if(declptr->declclass == TYPE)  //declclass == TYPE이면 해제 하지 않는다.
    {
	if(declptr->typeclass == Hash("array"))	//다만 array나 pointer면 해제한다.
	{
	    free(declptr);
	    free_decl(declptr->elementvar);
	}
	else if(declptr->typeclass == Hash("ptr"))
	{
	    free(declptr);
	}
	return NULL;
    }
    else
    {
	free(declptr);
	free_decl(declptr->type);
    }
    return NULL;
}

struct ste *sdestroy()
{
    while(SStack.TOP->top)
    {
	free(SStack.TOP->top);
	SStack.TOP->top = SStack.TOP->top->prev;
    }

    while(SStack.TOP)
    {
	free(SStack.TOP);
	SStack.TOP = SStack.TOP->prev;
    }

    while(StrStack)
    {
	free(StrStack->decl->fieldlist);
	free(StrStack);
	StrStack = StrStack->prev;
    }

    return NULL;
}



struct ste *declare(id* entry, struct decl *declptr)
{
    return insert(entry, declptr);
}






struct decl *maketypedecl(int type)	/* 맨 처음 int, char, void를 넣어줄 때 사용하는 함수 */
{
    struct decl *typedecl = (struct decl*)malloc(sizeof(struct decl));
    typedecl->declclass = TYPE;
    typedecl->typeclass = type;
    return typedecl;
}

struct decl *makevardecl(struct decl *typeptr)	/* vardecl을 만든다 */
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("VAR");
    temp->type = typeptr;
    return temp;
}

struct decl *makeptrdecl(struct decl *typeptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->ptrto = typeptr;
    temp->typeclass = Hash("ptr");
    temp->declclass = TYPE;
    return temp;
}

struct decl *makearraydecl(int numidx, struct decl *varptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->elementvar = varptr;
    temp->declclass = TYPE;
    temp->num_index = numidx;
    temp->typeclass = Hash("array");
    return temp;
}

struct decl *makestructdecl(struct ste *fieldptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->fieldlist = fieldptr;
    temp->declclass = TYPE;
    temp->typeclass = Hash("struct");
    return temp;
}

struct decl *makeconstdecl(struct decl *typeptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("CONST");
    temp->type = typeptr;
    return temp;
}

struct decl *makenumconstdecl(struct decl *typeptr, int intconst)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("CONST");
    temp->type = typeptr;
    temp->intvalue = intconst;
    return temp;
}

struct decl *makecharconstdecl(struct decl *typeptr, char *charconst)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("CONST");
    temp->type = typeptr;
    temp->charvalue = charconst;
    return temp;
}

struct decl *makestringconstdecl(struct decl *typeptr, const char* stringconst)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("CONST");
    temp->type = makeptrdecl(typeptr);
    temp->stringvalue = stringconst;
    return temp;
}

struct decl *makeprocdecl()
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("FUNC");
    temp->isdeclared = 0;
    return temp;
}





struct decl *finddecl(id *entry)	    /* entry에 해당하는 name을 가진 ste가 있는지 찾는다.*/
{
    struct ste *temp = SStack.TOP->top;
    while(temp)
    {
	if(temp->name == entry)
	{
	    return temp->decl;
	}
	temp = temp->prev;
    }
    return NULL;
}

struct decl *findstructdecl(struct id *entry)
{
    struct ste *temp = StrStack;
    while(temp)
    {
	if(temp->name == entry)
	{
	    return temp->decl;
	}
	temp = temp->prev;
    }
    return NULL;
}

struct decl *findcurrentdecl(struct id *fieldid, struct ste *fieldlist)
{
    struct ste *temp = fieldlist;
    while(temp)
        {
	    if(temp->name == fieldid)
	        {
		    //REDUCE(temp->name->name);
		    return temp->decl;
		}
	    temp = temp->prev;
        }
    yyerror("struct not have same name field");
    return NULL;
}






struct decl *structaccess(struct decl *structptr, struct id *fieldid)
{
    struct decl *typeptr = structptr->type;
    if(check_is_struct_type(typeptr))
	return(findcurrentdecl(fieldid, typeptr->fieldlist));
    else
	return NULL;
}

struct decl *structPtraccess(struct decl *structptr, struct id *fieldid)
{
    struct decl *typeptr = structptr->type;
    if(check_is_ptr_type(typeptr))
    {
	typeptr = typeptr->ptrto;
	if(check_is_struct_type(typeptr))
	    return(findcurrentdecl(fieldid, typeptr->fieldlist));
	else
	    return NULL;
    }
    else
	return NULL;
}

struct decl *arrayaccess(struct decl *arrayptr, struct decl *indexptr)
{
    struct decl *arraytype = arrayptr->type;
    if(check_is_array_type(arraytype))
    {
	if(check_compatible_type(indexptr, inttype))
	    return (arraytype->elementvar);
	else
	{
	    yyerror("index is not int type");
	    return NULL;
	}
    }
    else
	return NULL;
}







struct decl *plustype(struct decl *type1, struct decl *type2)
{
    if(type1 == NULL || type2 == NULL)
    {
	yyerror("type is not suitable for plus operaton");
	return NULL;
    }
    else if(type1 == inttype && type2 == inttype)
    {
	return inttype;
    }
    else if(type1 == inttype && type2->typeclass == Hash("ptr"))
    {
	return inttype;
    }
    else if(type1->typeclass == Hash("ptr") && type2 == inttype)
    {
	return type1;
    }
    yyerror("type is not suitable for plus operaton");
    return NULL;
}

struct decl *minustype(struct decl *type1, struct decl *type2)
{
    if(type1 == NULL || type2 == NULL)
    {
	yyerror("type is not suitable for minus operaton");
	return NULL;
    }
    else if(type1 == inttype && type2 == inttype)
    {
	return inttype;
    }
    else if(type1->typeclass == Hash("ptr") && type2 == inttype)
    {
	return type1;
    }
    yyerror("type is not suitable for minus operaton");
    return NULL;
}

struct decl *reloptype(struct decl *type1, struct decl *type2)
{
    if(check_compatible_type(type1, type2))
    {
	if(type1->typeclass == Hash("struct"))
	{
	    yyerror("type is not suitable for relop operaton");
	    return NULL;
	}
	else
	{
	    return inttype;
	}
    }
    yyerror("type is not suitable for relop operaton");
    return NULL;
}
    
struct decl *equoptype(struct decl *type1, struct decl *type2)
{
    if(check_compatible_type(type1, type2))
    {
	if(type1->typeclass == Hash("struct"))
	{
	    yyerror("type is not suitable for equop operaton");
	    return NULL;
	}
	else
	{
	    return inttype;
	}
    }
    yyerror("type is not suitable for equop operaton");
    return NULL;
}

struct decl *INDECOPtype(struct decl *type)
{
    if(type == inttype || type == chartype)
    {
	return type;
    }
    else if(type->typeclass == Hash("ptr"))
    {
	return type;
    }
    else
    {
        yyerror("type is not suitable for incop(or decop) operaton");
	return NULL;
    }
}




struct decl *check_is_var_type(struct decl *declptr)
{
    if(declptr && declptr->declclass == Hash("VAR"))
    {
	return declptr;
    }
    else
    {
	//error
	//yyerror("not variable");
        return NULL;
    }
}

struct decl *check_is_const_type(struct decl *declptr)
{
    if(declptr && declptr->declclass == Hash("CONST"))
    {
	return declptr;
    }
    else
    {
	yyerror("not constant");
	return NULL;
    }
}

struct decl *check_compatible(struct decl *declptr1, struct decl *declptr2)
{
    if(declptr2 && declptr1)
    {
	if(declptr1->typeclass == Hash("ptr"))	    //declptr1이 포인터 인 경우
	{
	    if(declptr1->ptrto == declptr2->ptrto)	//type 확인
	    {
		return declptr1;
	    }
	    else if(declptr2->typeclass == Hash("array"))	// declptr2가 array인지 확인
	    {
		if(declptr1->ptrto == declptr2->elementvar->type)
		{
		    return declptr1;
		}
	    }
	}
	else if(declptr1 == declptr2) //type이 같은가 확인
	{
	    return declptr1;
	}
    }
    //error
    //yyerror("not compatible");
    return NULL;
}

struct decl *check_compatible_type(struct decl *declptr1, struct decl *declptr2)
{
    
    if(declptr2 && declptr1)
    {
	if(declptr1->typeclass == Hash("ptr"))	    //declptr1이 포인터 인 경우
	{
	    if(declptr1->ptrto == declptr2->ptrto)	//type 확인
	    {
		return declptr1;
	    }
	}
	else if(declptr1 == declptr2) //type이 같은가 확인
	{
	    return declptr1;
	}
    }
    //error
    //yyerror("not compatible");
    return NULL;
}

struct decl *check_is_struct_type(struct decl *structptr)
{
    if(structptr && structptr->typeclass == Hash("struct"))
    {
	return structptr;
    }
    else
    {
    	yyerror("not struct");
	return NULL;
    }
}

struct decl *check_is_array_type(struct decl *arrayptr)
{
    if(arrayptr && arrayptr->typeclass == Hash("array"))
    {
	return arrayptr;
    }
    else
    {
    	yyerror("not array");
	return NULL;
    }
}

struct decl *check_is_ptr_type(struct decl *ptrptr)
{
    if(ptrptr && ptrptr->typeclass == Hash("ptr"))
    {
	return ptrptr;
    }
    else
    {
        yyerror("not pointer");
	return NULL;
    }
}

struct decl *check_is_type(struct decl* declptr)
{
    if(declptr && declptr->declclass == TYPE)
    {
	return declptr;
    }
    else
    {
        yyerror("not type");
	return NULL;
    //error checking
    }
}

struct decl *check_function_call(struct decl *procptr, struct decl *actuals)
{
    struct ste *formals = procptr->formals->prev;
    /* 1. compare number of formals and actuals */

    /* 2. check for type match			*/
    while(formals != NULL && actuals != NULL)
    {
	if(check_is_var_type(formals->decl))
	{
	    if(check_compatible(formals->decl->type, actuals->type))
	    {
		formals = formals->prev;
		actuals = actuals->next;
	    }
	    else
	    {
		break;
	    }
	}
	else
	{
	    break;
	}
    }
    if(formals || actuals)
    {
   	yyerror("actual args are not equal to formal args");
	return NULL;
    }

    return makeconstdecl(procptr->returntype);  /* for decl of the call */
}

struct decl *check_is_proc(struct decl *procptr)
{
    if(procptr && procptr->declclass == Hash("FUNC"))
    {
	return procptr;
    }
    else
    {
	yyerror("not a function");
	return NULL;
    }
}

struct decl *check_is_declared_for_else(struct id *entry)
{
    struct ste *temp = SStack.TOP->top;
    struct ste *temp2;

    if(SStack.TOP->prev == NULL)
	temp2 = NULL;
    else
	temp2 = SStack.TOP->prev->top;

    while(temp != temp2)
    {
	if(temp->name == entry)
	{
	    if(temp->decl->declclass == Hash("FUNC"))
	    {
		if(!temp->decl->isdeclared)
		{
		    return NULL;
		}
	    }
	    yyerror("redeclaration");
	    return temp->decl;
	}
	temp = temp->prev;
    }
    
    temp = StrStack;
    while(temp)
    {
	if(temp->name == entry)
	{
	    yyerror("redeclaration");
	    return temp->decl;
	}
	temp = temp->prev;
    } 
    return NULL;
}

struct decl *check_is_declared_for_struct(struct id *entry)
{
    struct ste *temp = SStack.TOP->top;
    while(temp)
    {
	if(temp->name == entry)
	{
	    yyerror("redeclaration");
	    return temp->decl;
	}
	temp = temp->prev;
    }

    temp = StrStack;
    while(temp)
    {
	if(temp->name == entry)
	{
	    yyerror("redeclaration");
	    return temp->decl;
	}
	temp = temp->prev;
    }
    return NULL;
}





unsigned int Hash(const char *key)
{
    unsigned int hashvalue = 0;
    while(*key) 
	hashvalue += *key++;
    return hashvalue;
}

void printStack(struct ste *top)
{
    while(top)
    {
	printf("\nThis variable's name is %s\n", top->name->name);
	tellmetype(top->decl);
	top = top->prev;
    }
}

void tellmetype(struct decl *declptr)
{
    struct decl *temp = declptr;
    
    if(!temp)
	return;
    
    printf("/**** Speak To Me ****/\n");

    if(temp->declclass == Hash("VAR"))
    {
	REDUCE("Declclass is VAR");
    }
    else if(temp->declclass == Hash("CONST"))
    {
	REDUCE("Declclass is CONST");
    }
    else if(temp->declclass == Hash("FUNC"))
    {
	REDUCE("Declclass is FUNC");
    }
    else if(temp->declclass == TYPE)
    {
	REDUCE("Declclass is TYPE");
    }

    if(temp->typeclass == Hash("int"))
    {
	REDUCE("Typeclass is INT");
    }
    else if(temp->typeclass == Hash("ptr"))
    {
	REDUCE("Typeclass is Pointer");
    }
    else if(temp->typeclass == Hash("array"))
    {
	REDUCE("Typeclass is Array");
    }
    else if(temp->typeclass == Hash("char"))
    {
	REDUCE("Typeclass is CHAR");
    }
    else if(temp->typeclass == Hash("struct"))
    {
	REDUCE("Typeclass is Struct");
    }
    else if(temp->typeclass == VOID)
    {
	REDUCE("Typeclass is VOID");
    }
    
    printf("\n");

    if(temp->type)
    {
	tellmetype(temp->type);
    }
    if(temp->returntype)
    {
	tellmetype(temp->returntype);
    }
    if(temp->elementvar)
    {
	tellmetype(temp->elementvar);
    }
    if(temp->ptrto)
    {
	tellmetype(temp->ptrto);
    }
    if(temp->fieldlist)
    {
	printStack(temp->fieldlist);
    }
    if(temp->formals)
    {
	printStack(temp->formals);
    }
    
}

struct ste *pushStr(struct id *entry, struct decl *declptr)
{
    struct ste *temp = StrStack;
    StrStack = (struct ste*)malloc(sizeof(struct ste));
    StrStack->name = entry;
    StrStack->decl = declptr;
    StrStack->prev = temp;
    return StrStack;
}
