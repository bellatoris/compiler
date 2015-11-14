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


#line 80 "subc.tab.c" /* yacc.c:339  */

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
#line 16 "subc.y" /* yacc.c:355  */

	int	    intVal;
	double	    floatval;
	char	    *stringVal;
	struct id   *idptr;
	struct decl *declptr;
	struct ste  *steptr;

#line 153 "subc.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SUBC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 168 "subc.tab.c" /* yacc.c:358  */

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
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

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
       0,    62,    62,    64,    65,    69,    84,    99,   106,   113,
     113,   129,   150,   156,   164,   167,   164,   184,   208,   208,
     234,   234,   259,   259,   291,   295,   301,   304,   309,   313,
     319,   322,   327,   338,   349,   356,   365,   370,   376,   379,
     384,   387,   390,   394,   398,   401,   402,   403,   404,   405,
     406,   409,   410,   413,   416,   421,   424,   427,   428,   431,
     434,   435,   438,   441,   444,   447,   450,   455,   458,   461,
     464,   465,   466,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   481,   484,   487,   492,   499,   502
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
  "struct_specifier", "$@2", "@3", "func_decl", "@4", "@5", "@6",
  "pointers", "param_list", "param_decl", "def_list", "def",
  "compound_stmt", "local_defs", "stmt_list", "stmt", "expr_e",
  "const_expr", "expr", "or_expr", "or_list", "and_expr", "and_list",
  "binary", "unary", "args", YY_NULLPTR
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

#define YYPACT_NINF -123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define YYTABLE_NINF -21

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -123,    14,    24,  -123,  -123,  -123,     7,  -123,   -15,  -123,
     -20,    17,  -123,  -123,    53,  -123,    25,  -123,    -2,  -123,
    -123,  -123,   164,    10,  -123,    24,  -123,    24,  -123,   164,
     164,   164,   164,   164,   164,   164,  -123,  -123,  -123,    44,
    -123,  -123,    85,  -123,    92,   175,   176,    82,   107,    24,
      -4,    78,  -123,    42,    77,   131,   131,   131,   131,   131,
     131,    97,    73,    93,   164,   164,   164,   164,   164,   164,
     164,  -123,  -123,   164,   143,   118,   125,  -123,   109,   117,
      60,  -123,  -123,   144,  -123,     8,   112,   126,   130,   121,
     127,  -123,  -123,  -123,  -123,   128,  -123,  -123,  -123,  -123,
    -123,   131,   175,    94,    75,  -123,  -123,  -123,   147,  -123,
     162,   150,  -123,  -123,  -123,   171,    24,  -123,    46,  -123,
     140,   164,   164,   164,  -123,  -123,  -123,  -123,   164,  -123,
     157,  -123,   164,  -123,  -123,   155,   174,   149,  -123,  -123,
     164,   178,   108,   108,   164,   181,   167,   198,  -123,   169,
    -123,  -123,   108,   164,  -123,   183,   108,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    11,    12,     0,     3,    25,    13,
       9,    17,    24,     8,     0,     7,     0,    14,     0,    31,
      10,    31,     0,    22,     5,    37,    39,    15,    72,     0,
       0,     0,     0,     0,     0,     0,    70,    71,    69,     0,
      53,    55,    56,    58,    59,    61,    66,     0,     0,     0,
      25,     0,    30,     0,     0,    79,    73,    80,    74,    77,
      78,     0,    66,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,     0,     0,     0,     0,    19,     0,    25,
       0,    26,    34,     0,    35,     0,     0,     0,     0,     0,
       0,    44,    36,    41,    38,     0,    16,    67,    68,     6,
      57,    66,    60,    63,    62,    64,    65,    54,     0,    85,
      86,     0,    82,    83,    21,     0,     0,    23,     0,    42,
       0,     0,     0,    52,    49,    50,    40,    81,     0,    84,
      28,    27,     0,    32,    43,     0,     0,     0,    51,    87,
       0,     0,     0,     0,    52,     0,     0,    45,    47,     0,
      29,    33,     0,    52,    46,     0,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,  -123,  -123,     0,  -123,  -123,  -123,   205,
    -123,  -123,  -123,   -33,  -123,    95,   187,  -123,   193,  -123,
    -123,   -39,  -122,   -85,   -22,  -123,  -123,   146,  -123,    19,
     -26,    84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    16,    50,     9,    21,    54,    51,
      47,    48,    49,    14,    80,    81,    25,    52,    93,    26,
      53,    94,   137,    39,    95,    41,    42,    43,    44,    45,
      46,   111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    12,     8,    55,    56,    57,    58,    59,    60,    62,
      11,    28,    12,    61,     3,   -20,    15,    83,    22,    29,
      23,    13,   149,    30,    31,    32,    33,    34,     4,     5,
      35,   155,    82,   -18,    24,    36,    37,    38,   101,   101,
     101,   101,   101,   101,   119,    28,   115,   141,   107,    79,
       6,   108,   110,    29,    17,   145,    18,    30,    31,    32,
      33,    34,    19,   120,    35,    63,   132,   116,    23,    36,
      37,    38,    85,    86,    87,    88,    89,    90,    91,    19,
      92,    70,   133,   117,   102,   103,   104,   105,   106,    68,
      69,    71,    72,    73,    64,    74,    98,    75,    76,   135,
     136,   138,    65,   147,   148,    77,   110,    67,    68,    69,
      40,    28,    78,   154,    84,    96,    79,   157,    40,    29,
      97,   112,   138,    30,    31,    32,    33,    34,   113,    99,
      35,   138,   114,    12,   121,    36,    37,    38,    85,    86,
      87,    88,    89,    90,    91,    19,    28,   118,   122,    71,
      72,    73,   123,    74,    29,    75,    76,   124,    30,    31,
      32,    33,    34,   125,   126,    35,   109,    28,   127,   128,
      36,    37,    38,   129,   130,    29,   134,   140,   142,    30,
      31,    32,    33,    34,    70,   144,    35,    66,    67,    68,
      69,    36,    37,    38,    71,    72,    73,   143,    74,   146,
      75,    76,   150,   151,   152,   153,   156,    10,    27,    20,
     100,   131,   139
};

static const yytype_uint8 yycheck[] =
{
      22,    16,     2,    29,    30,    31,    32,    33,    34,    35,
       3,     3,    16,    35,     0,     5,    36,    50,    20,    11,
      22,    36,   144,    15,    16,    17,    18,    19,     4,     5,
      22,   153,    36,    23,    36,    27,    28,    29,    64,    65,
      66,    67,    68,    69,    36,     3,    79,   132,    70,    49,
      26,    73,    74,    11,    37,   140,     3,    15,    16,    17,
      18,    19,    37,    85,    22,    21,    20,     7,    22,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,     8,    36,    23,    65,    66,    67,    68,    69,    14,
      15,    18,    19,    20,     9,    22,    23,    24,    25,   121,
     122,   123,    10,   142,   143,    23,   128,    13,    14,    15,
     132,     3,     5,   152,    36,    38,   116,   156,   140,    11,
      23,     3,   144,    15,    16,    17,    18,    19,     3,    36,
      22,   153,    23,    16,    22,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     3,     3,    22,    18,
      19,    20,    22,    22,    11,    24,    25,    36,    15,    16,
      17,    18,    19,    36,    36,    22,    23,     3,    21,     7,
      27,    28,    29,    23,     3,    11,    36,    20,    23,    15,
      16,    17,    18,    19,     8,    36,    22,    12,    13,    14,
      15,    27,    28,    29,    18,    19,    20,    23,    22,    21,
      24,    25,    21,    36,     6,    36,    23,     2,    21,    16,
      64,   116,   128
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,     0,     4,     5,    26,    42,    44,    45,
      48,     3,    16,    36,    52,    36,    43,    37,     3,    37,
      57,    46,    20,    22,    36,    55,    58,    55,     3,    11,
      15,    16,    17,    18,    19,    22,    27,    28,    29,    62,
      63,    64,    65,    66,    67,    68,    69,    49,    50,    51,
      44,    48,    56,    59,    47,    69,    69,    69,    69,    69,
      69,    63,    69,    21,     9,    10,    12,    13,    14,    15,
       8,    18,    19,    20,    22,    24,    25,    23,     5,    44,
      53,    54,    36,    52,    36,    30,    31,    32,    33,    34,
      35,    36,    38,    57,    60,    63,    38,    23,    23,    36,
      66,    69,    68,    68,    68,    68,    68,    63,    63,    23,
      63,    70,     3,     3,    23,    52,     7,    23,     3,    36,
      63,    22,    22,    22,    36,    36,    36,    21,     7,    23,
       3,    54,    20,    36,    36,    63,    63,    61,    63,    70,
      20,    62,    23,    23,    36,    62,    21,    60,    60,    61,
      21,    36,     6,    36,    60,    61,    23,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    42,    43,
      42,    44,    44,    44,    46,    47,    45,    45,    49,    48,
      50,    48,    51,    48,    52,    52,    53,    53,    54,    54,
      55,    55,    56,    56,    56,    56,    57,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    61,    61,    62,    63,    63,    64,    65,    65,    66,
      67,    67,    68,    68,    68,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     7,     2,     2,     0,
       3,     1,     1,     1,     0,     0,     7,     2,     0,     6,
       0,     7,     0,     7,     1,     0,     1,     3,     3,     6,
       2,     0,     4,     7,     2,     2,     4,     1,     2,     0,
       2,     1,     2,     3,     1,     5,     7,     5,     9,     2,
       2,     1,     0,     1,     3,     1,     1,     3,     1,     1,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     3,     3,     4,     3,     1,     3
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
#line 65 "subc.y" /* yacc.c:1646  */
    { REDUCE("ext_def_list->epsilion"); }
#line 1364 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "subc.y" /* yacc.c:1646  */
    {
		    if(!check_is_declared_for_else((yyvsp[-1].idptr)) && (yyvsp[-3].declptr))	//ID와 동일한 ste가 현재 scope에 있는지 확인
		    {
			declare((yyvsp[-1].idptr), makevardecl((yyvsp[-2].declptr)? (yyvsp[-2].declptr):(yyvsp[-3].declptr))); 
		    }
		    else
		    {
			//error
			printf("%d: error: declaration error\n",read_line());
			(yyval.declptr) = NULL;
		    
			REDUCE("ext_def->type_specifier pointers ID ';'");
		    }
		    printStack(SStack.TOP->top);
		}
#line 1384 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 84 "subc.y" /* yacc.c:1646  */
    {
		    if(!check_is_declared_for_else((yyvsp[-4].idptr)) && (yyvsp[-6].declptr))
		    {
			declare((yyvsp[-4].idptr), makeconstdecl(makearraydecl((yyvsp[-2].intVal), makevardecl((yyvsp[-5].declptr)? (yyvsp[-5].declptr):(yyvsp[-6].declptr)))));
		    }
		    else
		    {
			//error
			printf("%d: error: declaration error\n",read_line());
			(yyval.declptr) = NULL;
		    
			REDUCE("ext_def->type_specifier pointers ID '[' const_expr ']' ';' ");
		    }
		    printStack(StrStack);
		}
#line 1404 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 99 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-1].declptr))
		    {
			printf("%d: error: declaration error\n",read_line());
			REDUCE("ext_def->func_decl ';'");
		    }
		}
#line 1416 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 106 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-1].declptr))
		    {
			printf("%d: error: declaration error\n",read_line());
			REDUCE("ext_def->type_specifier ';'");
		    }
		}
#line 1428 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 113 "subc.y" /* yacc.c:1646  */
    { 
		    push_scope();
		    if((yyvsp[0].declptr))
			push_ste_list((yyvsp[0].declptr)->formals);
		}
#line 1438 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 118 "subc.y" /* yacc.c:1646  */
    {
		    pop_scope();
		    if(!(yyvsp[-2].declptr))
		    {
			printf("%d: error: declaration error\n",read_line());
			REDUCE("ext_def->func_decl compound_stmt");
		    }
		}
#line 1451 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 129 "subc.y" /* yacc.c:1646  */
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
			REDUCE("type_specifier->TYPE");
		    }
		}
#line 1477 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 150 "subc.y" /* yacc.c:1646  */
    {
		    struct decl *typeptr = finddecl((yyvsp[0].idptr));
		    //check_is_type(typeptr);
		    (yyval.declptr) = typeptr;
		    REDUCE("type_specifier->VOID");
		}
#line 1488 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 156 "subc.y" /* yacc.c:1646  */
    { 
		    (yyval.declptr) = (yyvsp[0].declptr);
		    if(!(yyval.declptr))
			REDUCE("type_specifier->struct_specifier"); 
		}
#line 1498 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 164 "subc.y" /* yacc.c:1646  */
    {
		    push_scope();
		}
#line 1506 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 167 "subc.y" /* yacc.c:1646  */
    {
		    struct ste *fields = pop_scope();
		    (yyval.steptr) = fields;
		}
#line 1515 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 172 "subc.y" /* yacc.c:1646  */
    {
		    if(!check_is_declared_for_struct((yyvsp[-5].idptr)))
		    {
			pushStr((yyvsp[-5].idptr), (yyval.declptr) = makestructdecl((yyvsp[-1].steptr)));
		    }
		    else
		    {
			//error
			(yyval.declptr) = NULL;
			REDUCE("struct_specifier->STRUCT ID '{' def_list '}'");
		    }
		}
#line 1532 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 184 "subc.y" /* yacc.c:1646  */
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
			(yyval.declptr) = NULL;
			REDUCE("struct_specifier->STRUCT ID"); 
		    }
		}
#line 1558 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 208 "subc.y" /* yacc.c:1646  */
    {
		    struct decl *procdecl = makeprocdecl();
		    /*if(!check_is_declared_for_else($3))
		    {
			declare($3, procdecl);
		    }*/
		    push_scope();
		    declare(returnid, (yyvsp[-2].declptr)? (yyvsp[-2].declptr):(yyvsp[-3].declptr));
		    (yyval.declptr) = procdecl;
		}
#line 1573 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 217 "subc.y" /* yacc.c:1646  */
    {
		    struct ste *formals;
		    struct decl *procdecl = (yyvsp[-1].declptr);
		    formals = pop_scope();
		    procdecl->returntype = formals->decl;
		    procdecl->formals = formals;
		    if(!check_is_declared_for_else((yyvsp[-3].idptr)))
		    {
			(yyval.declptr) = procdecl;
			declare((yyvsp[-3].idptr), procdecl);
		    }
		    else
		    {
			(yyval.declptr) = NULL;
			REDUCE("func_decl->type_specifier pointers ID '(' ')'");
		    }
		}
#line 1595 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 234 "subc.y" /* yacc.c:1646  */
    {
		    struct decl *procdecl = makeprocdecl();
		    /*if(!check_is_declared_for_else($3))
			declare($3, procdecl);*/
		    push_scope();
		    declare(returnid, (yyvsp[-2].declptr)? (yyvsp[-2].declptr):(yyvsp[-3].declptr));
		    (yyval.declptr) = procdecl;
		}
#line 1608 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 242 "subc.y" /* yacc.c:1646  */
    {
		    struct ste *formals;
		    struct decl *procdecl = (yyvsp[-2].declptr);
		    formals = pop_scope();
		    procdecl->returntype = formals->decl;
		    procdecl->formals = formals;
		    if(!check_is_declared_for_else((yyvsp[-4].idptr)))
		    {
			(yyval.declptr) = procdecl;
			declare((yyvsp[-4].idptr), (yyval.declptr));
		    }
		    else
		    {
			(yyval.declptr) = NULL;
			REDUCE("func_decl->type_specifier pointer ID '(' VOID ')' ");
		    }
		}
#line 1630 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 259 "subc.y" /* yacc.c:1646  */
    {
		    struct decl *procdecl = makeprocdecl();
		    /*if(!check_is_declared_for_else($3))
			declare($3, procdecl);*/
		    push_scope(); /*for collecting formals */
		    declare(returnid, (yyvsp[-2].declptr)? (yyvsp[-2].declptr):(yyvsp[-3].declptr));
		    (yyval.declptr) = procdecl;
		}
#line 1643 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 266 "subc.y" /* yacc.c:1646  */
    {
		    struct ste *formals;
		    struct decl *procdecl = (yyvsp[-2].declptr);
		    //printStack(SStack.TOP->top);
		    formals = pop_scope();
		    /* pop_scope reverses stes(first one is the returnid) */
		    procdecl->returntype = formals->decl; /* No for type checking */
		    procdecl->formals = formals;	// must check again
		    if(!check_is_declared_for_else((yyvsp[-4].idptr)))
		    {
			(yyval.declptr) = procdecl;
			declare((yyvsp[-4].idptr), (yyval.declptr));
		    }
		    //push_scope(); /* for installing formals & locals in this scope */
		    //pushstelist(formals); 
		    else
		    {
			(yyval.declptr) = NULL;
			REDUCE("func_decl->type_specifier pointers ID '(' param_list ')' ");
		    }
		}
#line 1669 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 291 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = makeptrdecl((yyvsp[-1].declptr));
		    REDUCE("pointers->'*'");
		}
#line 1678 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 295 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = NULL;
		    REDUCE("pointers->epsilon");
		}
#line 1687 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 301 "subc.y" /* yacc.c:1646  */
    {
		    REDUCE("param_list->param_decl");
		}
#line 1695 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 304 "subc.y" /* yacc.c:1646  */
    {
		    REDUCE("param_list->param_list ',' param_decl");
		}
#line 1703 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 309 "subc.y" /* yacc.c:1646  */
    {
		    declare((yyvsp[0].idptr), makevardecl((yyvsp[-1].declptr)? (yyvsp[-1].declptr):(yyvsp[-2].declptr)));
		    REDUCE("param_decl->type_specifier pointers ID");
		}
#line 1712 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 313 "subc.y" /* yacc.c:1646  */
    {
		    declare((yyvsp[-3].idptr), makeconstdecl(makearraydecl((yyvsp[-1].intVal), makevardecl((yyvsp[-4].declptr)? (yyvsp[-4].declptr):(yyvsp[-5].declptr)))));
		    REDUCE("param_decl->type_specifier pointers ID '[' const_expr ']'");
		}
#line 1721 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 319 "subc.y" /* yacc.c:1646  */
    {
		    REDUCE("def_list->def_list def");
		}
#line 1729 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 322 "subc.y" /* yacc.c:1646  */
    {
		    REDUCE("def_list->epsilon");
		}
#line 1737 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 327 "subc.y" /* yacc.c:1646  */
    {
		    if(!check_is_declared_for_else((yyvsp[-1].idptr)) && (yyvsp[-3].declptr))
		    {
			declare((yyvsp[-1].idptr), makevardecl((yyvsp[-2].declptr)? (yyvsp[-2].declptr):(yyvsp[-3].declptr)));
		    }
		    else
		    {
			(yyval.declptr) = NULL;
			REDUCE("def->type_specifier pointerts ID ';'");
		    }
		}
#line 1753 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 338 "subc.y" /* yacc.c:1646  */
    {
		    if(!check_is_declared_for_else((yyvsp[-4].idptr)) && (yyvsp[-6].declptr))
		    {
		    declare((yyvsp[-4].idptr), makeconstdecl(makearraydecl((yyvsp[-2].intVal), makevardecl((yyvsp[-5].declptr)? (yyvsp[-5].declptr):(yyvsp[-6].declptr)))));
		    }
		    else
		    {
			(yyval.declptr)= NULL;
			REDUCE("def->type_specifier pointers ID '[' const_expr ']' ';' ");
		    }
		}
#line 1769 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 349 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-1].declptr))
		    {
			(yyval.declptr) = NULL;
			REDUCE("def->type_specifier ';'");
		    }
		}
#line 1781 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 356 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-1].declptr))
		    {
			(yyval.declptr) = NULL;
			REDUCE("def->func_decl ';'");
		    }
		}
#line 1793 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 365 "subc.y" /* yacc.c:1646  */
    {
		    REDUCE("compound_stmt->'{' local_defs stmt_list '}'");
		}
#line 1801 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 370 "subc.y" /* yacc.c:1646  */
    {
		    //printStack(SStack.TOP->top);
		    REDUCE("local_defs->def_list");
		}
#line 1810 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 376 "subc.y" /* yacc.c:1646  */
    {
		    REDUCE("stmt_list->stmt_list stmt");
		}
#line 1818 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 379 "subc.y" /* yacc.c:1646  */
    {
		    REDUCE("stmt_list->epsilon");
		}
#line 1826 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 384 "subc.y" /* yacc.c:1646  */
    {
		    REDUCE("stmt->expr ';'");
		}
#line 1834 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 387 "subc.y" /* yacc.c:1646  */
    {
		    REDUCE("stmt->compound_stmt");
		}
#line 1842 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 390 "subc.y" /* yacc.c:1646  */
    {
		    if(!check_same_type(finddecl(returnid), voidtype))
			REDUCE("stmt->RETURN ';'");
		}
#line 1851 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 394 "subc.y" /* yacc.c:1646  */
    {
		    if(!check_same_type(finddecl(returnid), (yyvsp[-1].declptr)))
		    REDUCE("stmt->RETURN expr ';'");
		}
#line 1860 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 398 "subc.y" /* yacc.c:1646  */
    {
		    REDUCE("stmt->';'");
		}
#line 1868 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 416 "subc.y" /* yacc.c:1646  */
    {
		    check_is_var_type((yyvsp[-2].declptr));
		    check_compatible((yyvsp[-2].declptr), (yyvsp[0].declptr));
		    (yyval.declptr) = (yyvsp[-2].declptr)->type;
		}
#line 1878 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 438 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = reloptype((yyvsp[-2].declptr), (yyvsp[0].declptr));
		}
#line 1886 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 441 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = equoptype((yyvsp[-2].declptr), (yyvsp[0].declptr));
		}
#line 1894 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 444 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = plustype((yyvsp[-2].declptr), (yyvsp[0].declptr));
		}
#line 1902 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 447 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = minustype((yyvsp[-2].declptr), (yyvsp[0].declptr));
		}
#line 1910 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 450 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = (yyvsp[0].declptr)->type;
		}
#line 1918 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 455 "subc.y" /* yacc.c:1646  */
    {
		    REDUCE("unary->'(' expr ')'");
		}
#line 1926 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 458 "subc.y" /* yacc.c:1646  */
    {
		    REDUCE("unary->'(' unary ')'");
		}
#line 1934 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 461 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = makenumconstdecl(inttype, (yyvsp[0].intVal));
		}
#line 1942 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 466 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = finddecl((yyvsp[0].idptr));
		    REDUCE("unary->ID"); 
		}
#line 1951 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 478 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = arrayaccess((yyvsp[-3].declptr), (yyvsp[-1].declptr));
		}
#line 1959 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 481 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = structaccess((yyvsp[-2].declptr), (yyvsp[0].idptr));
		}
#line 1967 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 484 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = structPtraccess((yyvsp[-2].declptr), (yyvsp[0].idptr));
		}
#line 1975 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 487 "subc.y" /* yacc.c:1646  */
    {
		    check_is_proc((yyvsp[-3].declptr));
		    (yyval.declptr) = check_function_call((yyvsp[-3].declptr), (yyvsp[-1].declptr));
		    REDUCE("unary->unary '(' args ')'");
		}
#line 1985 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 492 "subc.y" /* yacc.c:1646  */
    {
		    check_is_proc((yyvsp[-2].declptr));
		    (yyval.declptr)  = check_function_call((yyvsp[-2].declptr), NULL);
		    REDUCE("unary->unary '(' ')'");
		}
#line 1995 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 499 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = (yyvsp[0].declptr);
		}
#line 2003 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 502 "subc.y" /* yacc.c:1646  */
    {
		    (yyvsp[-2].declptr)->next = (yyvsp[0].declptr);
		    (yyval.declptr) = (yyvsp[-2].declptr);
		}
#line 2012 "subc.tab.c" /* yacc.c:1646  */
    break;


#line 2016 "subc.tab.c" /* yacc.c:1646  */
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
#line 507 "subc.y" /* yacc.c:1906  */


/*  Additional C Codes 
 	Implemnt REDUCE function here */

int    yyerror (char* s)
{
	fprintf (stderr, "%s\n", s);
}

void 	REDUCE( char* s)
{
	printf("%s\n",s);
}

struct ste *push_scope()	/* SStack.TOP에다가 새로히 ScopeNode를 만들고 연결 시킨다. */
{
    struct ScopeNode *temp = SStack.TOP;
    SStack.TOP = (struct ScopeNode*)malloc(sizeof(struct ScopeNode));
    SStack.TOP->prev = temp;
    SStack.TOP->top = temp->top;
    return SStack.TOP->top;
}

struct ste *push_ste_list(struct ste *formals)
{
    struct ste *ftemp = formals;
    while(ftemp)
    {
	declare(ftemp->name, ftemp->decl);
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

struct ste *insert(id *entry, struct decl *declptr)	/* declare와 똑같은 함수 이다. */
{
    struct ste *STE = (struct ste*)malloc(sizeof(struct ste));
    STE->name = entry;			    /* ste를 새로 만들고 name에 entry를 넣는다. */
    STE->decl = declptr;		    /* decl에 declptr를 넣는다 */
    STE->prev = SStack.TOP->top;	    /* SStack.TOP->top을 prev에 넣는다. */
    SStack.TOP->top = STE;		    /* SStack.TOP->top를 새로운 ste로 바꿔준다. */
    return SStack.TOP->top;
}

void lookup()
{
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
    temp->value = intconst;
}

struct decl *makeprocdecl()
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("FUNC");
    return temp;
}





struct decl *finddecl(id *entry)	    /* entry에 해당하는 name을 가진 ste가 있는지 찾는다.*/
{
    struct ste *temp = SStack.TOP->top;
    while(temp)
    {
	if(temp->name == entry)
	{
	    //REDUCE(temp->name->name);
	    return temp->decl;
	}
	temp = temp->prev;
    }
    //printf("%d: error: declaration error\n",read_line());
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
    //printf("%d: error: declaration error\n", read_line());
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
    printf("%d: error: declaration error",read_line());
    return NULL;
}






struct decl *structaccess(struct decl *structptr, struct id *fieldid)
{
    struct decl *typeptr = structptr->type;
    check_is_struct_type(typeptr);
    return(findcurrentdecl(fieldid, typeptr->fieldlist));
}

struct decl *structPtraccess(struct decl *structptr, struct id *fieldid)
{
    struct decl *typeptr = structptr->type;
    check_is_struct_type(typeptr->type);
    return(findcurrentdecl(fieldid, typeptr->type->fieldlist));
}

struct decl *arrayaccess(struct decl *arrayptr, struct decl *indexptr)
{
    struct decl *arraytype = arrayptr->type;
    check_is_array_type(arraytype);
    check_same_type(inttype, indexptr);
    return (arraytype->elementvar);
}







struct decl *plustype(struct decl *type1, struct decl *type2)
{
    struct decl *type_after;
    type_after = check_compatible_type(type1, type2);
    return type_after;
}

struct decl *minustype(struct decl *type1, struct decl *type2)
{
    struct decl *type_after;
    type_after = check_compatible_type(type1, type2);
    return type_after;
}

struct decl *reloptype(struct decl *type1, struct decl *type2)
{
    struct decl *type_after;
    type_after = check_compatible_type(type1, type2);
    return type_after;
}
    
struct decl *equoptype(struct decl *type1, struct decl *type2)
{
    struct decl *type_after;
    type_after = check_compatible_type(type1, type2);
    return type_after;
}





struct decl *check_is_var_type(struct decl *declptr)
{
    if(declptr->typeclass == Hash("VAR"))
    {
	return declptr;
    }
    else
    {
        return NULL;
    }
}

struct decl *check_compatible(struct decl *declptr1, struct decl *declptr2)
{
    if(declptr1->type == declptr2->type && declptr1->declclass == declptr2->declclass)
    {
	return declptr1;
    }
    else
    {
	//error
	return NULL;
    }
}

struct decl *check_compatible_type(struct decl *type1, struct decl *type2)
{
    if(type1 == type2)
    {
	return type1;
    }
    else
    {
	return NULL;
    }
}

struct decl *check_is_struct_type(struct decl *structptr)
{
    if(structptr->typeclass == Hash("struct"))
    {
	return structptr;
    }
    else
    {
	return NULL;
    }
}

struct decl *check_is_array_type(struct decl *arrayptr)
{
    if(arrayptr->typeclass == Hash("array"))
    {
	return arrayptr;
    }
    else
    {
	return NULL;
    }
}

struct decl *check_same_type(struct decl *declptr1, struct decl *declptr2)
{
    if(declptr1 == declptr2)
    {
	return declptr1;
    }
    else
    {
	return NULL;
    }
}

struct decl *check_is_type(struct decl* declptr)
{
    if(declptr->declclass == TYPE)
    {
	return declptr;
    }
    else
    {
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
	check_is_var_type(formals->decl);
	check_compatible(formals->decl, actuals);
	formals = formals->prev;
	actuals = actuals->next;
    }

    if(formals || actuals)
    {
	return NULL;
    }

    return procptr->returntype;  /* for decl of the call */
}

struct decl *check_is_proc(struct decl *procptr)
{
    if(procptr->declclass == Hash("FUNC"))
    {
	return procptr;
    }
    else
    {
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
	    //printf("%d: error: declaration error\n",read_line());
	    return temp->decl;
	}
	temp = temp->prev;
    }
    
   /* temp = StrStack;
    while(temp)
    {
	if(temp->name == entry)
	{
	    //printf("%d: error: declaration error\n", read_line());
	    return NULL;
	}
	temp = temp->prev;
    } */

    return NULL;
}

struct decl *check_is_declared_for_struct(struct id *entry)
{
    struct ste *temp = SStack.TOP->top;
   /* while(temp)
    {
	if(temp->name == entry)
	{
	    return temp->decl;
	}
	temp = temp->prev;
    }*/

    temp = StrStack;
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




void add_type_to_var(struct decl *declptr1, struct decl *declptr2)
{

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
	REDUCE("VAR");
    }
    else if(temp->declclass == Hash("CONST"))
    {
	REDUCE("CONST");
    }
    else if(temp->declclass == Hash("FUNC"))
    {
	REDUCE("FUNC");
    }
    else if(temp->declclass == TYPE)
    {
	REDUCE("TYPE");
    }

    if(temp->typeclass == Hash("int"))
    {
	REDUCE("INT");
    }
    else if(temp->typeclass == Hash("ptr"))
    {
	REDUCE("Pointer");
    }
    else if(temp->typeclass == Hash("array"))
    {
	REDUCE("Array");
    }
    else if(temp->typeclass == Hash("char"))
    {
	REDUCE("CHAR");
    }
    else if(temp->typeclass == Hash("struct"))
    {
	REDUCE("Struct");
    }
    else if(temp->typeclass == VOID)
    {
	REDUCE("VOID");
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