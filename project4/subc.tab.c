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
    CONTINUE = 278,
    READ_INT = 279,
    READ_CHAR = 280,
    WRITE_INT = 281,
    WRITE_CHAR = 282,
    WRITE_STRING = 283
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

#line 155 "subc.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SUBC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 170 "subc.tab.c" /* yacc.c:358  */

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
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,     8,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    20,     2,    21,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    71,    72,    77,    90,   101,   103,   105,
     105,   123,   143,   147,   153,   153,   175,   199,   244,   287,
     287,   340,   347,   352,   358,   366,   377,   390,   393,   398,
     409,   420,   430,   442,   451,   442,   473,   478,   480,   484,
     487,   489,   500,   500,   522,   523,   524,   524,   529,   530,
     531,   532,   533,   536,   539,   544,   546,   553,   559,   568,
     570,   574,   598,   598,   654,   657,   660,   678,   681,   684,
     684,   705,   708,   708,   744,   744,   772,   772,   793,   793,
     814,   822,   828,   834,   844,   851,   858,   889,   903,   917,
     948,   979,  1008,  1037,  1057,  1079,  1103,  1120,  1137,  1137,
    1180,  1209,  1240
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
  "IF", "WHILE", "FOR", "BREAK", "CONTINUE", "READ_INT", "READ_CHAR",
  "WRITE_INT", "WRITE_CHAR", "WRITE_STRING", "';'", "'{'", "'}'",
  "$accept", "program", "ext_def_list", "ext_def", "$@1", "type_specifier",
  "struct_specifier", "@2", "func_decl", "@3", "pointers", "param_list",
  "param_decl", "def_list", "def", "compound_stmt", "@4", "$@5",
  "local_defs", "stmt_list", "stmt", "$@6", "$@7", "LABEL", "BRANCH",
  "expr_e", "const_expr", "expr", "$@8", "or_expr", "or_list", "and_expr",
  "and_list", "$@9", "binary", "$@10", "$@11", "$@12", "$@13", "unary",
  "$@14", "args", YY_NULLPTR
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
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,    59,   123,   125
};
# endif

#define YYPACT_NINF -120

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-120)))

#define YYTABLE_NINF -63

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -120,    20,    17,  -120,  -120,  -120,    25,  -120,     0,  -120,
      16,    -2,  -120,  -120,    71,  -120,    37,  -120,    12,  -120,
    -120,  -120,     8,    10,  -120,  -120,     5,  -120,     8,     8,
       8,     8,     8,     8,     8,  -120,  -120,  -120,    59,  -120,
    -120,    80,  -120,    82,   116,    63,    67,  -120,    17,    17,
    -120,  -120,     1,    52,  -120,    78,    78,    78,    78,    78,
      78,    72,    36,    58,     8,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,     8,    86,   107,   109,   106,  -120,   100,    22,
    -120,  -120,  -120,   115,  -120,  -120,  -120,  -120,  -120,    78,
       8,     8,     8,     8,     8,   101,  -120,     8,  -120,  -120,
       8,   118,    17,  -120,   133,    29,   116,   124,    62,  -120,
    -120,  -120,  -120,    39,  -120,   112,  -120,    93,  -120,   113,
     119,    99,   102,   120,   123,   131,   132,   134,  -120,  -120,
    -120,  -120,   105,     8,  -120,     8,  -120,     8,  -120,     8,
     135,     8,     8,  -120,  -120,     8,     8,     8,     8,     8,
    -120,   138,  -120,   157,   139,     8,   156,   140,  -120,   159,
     160,   161,   163,   164,   147,  -120,  -120,   171,   174,     8,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,   154,   174,
       8,   191,   175,  -120,  -120,   174,  -120,  -120,   174,  -120,
    -120
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    11,    12,     0,     3,    22,    13,
       9,    16,    21,     8,     0,     7,     0,    14,     0,    33,
      10,    28,     0,    19,     5,    28,     0,    86,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    83,     0,    61,
      64,    65,    67,    68,    71,    80,     0,    17,     0,    36,
      34,    15,    22,     0,    27,    93,    87,    94,    88,    91,
      92,     0,    80,     0,     0,    69,    74,    72,    76,    78,
      89,    90,     0,    98,     0,     0,     0,    18,    22,     0,
      23,    38,    31,     0,    32,    81,    82,     6,    66,    80,
       0,     0,     0,     0,     0,     0,   100,     0,    96,    97,
       0,     0,     0,    20,     0,     0,    70,    75,    73,    77,
      79,    95,   102,     0,    63,    25,    24,    42,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,    35,
      40,    37,     0,     0,    29,     0,    99,     0,    41,     0,
       0,     0,    60,    50,    51,     0,     0,     0,     0,     0,
      39,     0,   101,     0,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,    26,    43,     0,     0,    60,
      52,    53,    54,    55,    56,    30,    58,    48,     0,     0,
      60,    57,     0,    46,    45,     0,    57,    49,     0,    57,
      47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,  -120,  -120,  -120,    -1,  -120,  -120,   197,  -120,
     -39,  -120,    98,   192,  -120,   202,  -120,  -120,  -120,  -120,
    -116,  -120,  -120,   -95,  -120,   -96,  -119,   -22,  -120,  -120,
    -120,   155,  -120,  -120,    14,  -120,  -120,  -120,  -120,   -26,
    -120,  -120
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    16,    52,     9,    21,    53,    48,
      14,    79,    80,    26,    54,   130,    25,    81,    50,   104,
     131,   139,   186,   140,   179,   157,    38,   132,    76,    40,
      41,    42,    43,    90,    44,    92,    91,    93,    94,    45,
      97,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,     8,    55,    56,    57,    58,    59,    60,    62,     4,
       5,    27,    61,    83,   151,    46,    12,    12,   153,    28,
       3,     4,     5,    29,    30,    31,    32,    33,    11,   102,
      34,     6,    22,    47,    23,    35,    36,    37,    89,   101,
      17,    13,    82,     6,   -62,   103,   135,    78,    51,   133,
      95,    23,   177,    24,    70,    71,    72,    15,    73,    86,
      74,    75,   136,   181,    89,    89,    89,    89,    89,   187,
     134,   -62,   189,   178,    18,   112,    68,    69,   114,    19,
      63,    70,    71,    72,   182,    73,   184,    74,    75,    64,
      77,   188,    65,    84,   190,    85,    70,    71,    72,    87,
      73,    78,    74,    75,   106,   107,   108,   109,   110,    96,
      98,    39,    99,   152,   100,    39,    12,   154,   105,   156,
     158,   115,   111,   159,   160,   161,   162,   163,    66,    67,
      68,    69,   137,   167,   138,   141,    27,    67,    68,    69,
     143,   142,   145,   144,    28,   146,   150,   158,    29,    30,
      31,    32,    33,   147,   148,    34,   149,   155,   158,   164,
      35,    36,    37,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    19,   129,    27,   165,   168,
     166,   169,   170,   171,   172,    28,   173,   174,   175,    29,
      30,    31,    32,    33,   176,   180,    34,   183,   185,    10,
     116,    35,    36,    37,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    19,    49,    20,    88
};

static const yytype_uint8 yycheck[] =
{
      22,     2,    28,    29,    30,    31,    32,    33,    34,     4,
       5,     3,    34,    52,   133,     5,    16,    16,   137,    11,
       0,     4,     5,    15,    16,    17,    18,    19,     3,     7,
      22,    26,    20,    23,    22,    27,    28,    29,    64,    78,
      42,    41,    41,    26,     8,    23,     7,    48,    43,    20,
      72,    22,   168,    41,    18,    19,    20,    41,    22,    23,
      24,    25,    23,   179,    90,    91,    92,    93,    94,   185,
      41,     8,   188,   169,     3,    97,    14,    15,   100,    42,
      21,    18,    19,    20,   180,    22,   181,    24,    25,     9,
      23,   186,    10,    41,   189,    23,    18,    19,    20,    41,
      22,   102,    24,    25,    90,    91,    92,    93,    94,    23,
       3,   133,     3,   135,     8,   137,    16,   139,     3,   141,
     142,     3,    21,   145,   146,   147,   148,   149,    12,    13,
      14,    15,    20,   155,    41,    22,     3,    13,    14,    15,
      41,    22,    22,    41,    11,    22,    41,   169,    15,    16,
      17,    18,    19,    22,    22,    22,    22,    22,   180,    21,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     3,    21,    23,
      41,    41,    23,    23,    23,    11,    23,    23,    41,    15,
      16,    17,    18,    19,    23,    41,    22,     6,    23,     2,
     102,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    25,    16,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,     0,     4,     5,    26,    47,    49,    50,
      52,     3,    16,    41,    54,    41,    48,    42,     3,    42,
      59,    51,    20,    22,    41,    60,    57,     3,    11,    15,
      16,    17,    18,    19,    22,    27,    28,    29,    70,    71,
      73,    74,    75,    76,    78,    83,     5,    23,    53,    57,
      62,    43,    49,    52,    58,    83,    83,    83,    83,    83,
      83,    71,    83,    21,     9,    10,    12,    13,    14,    15,
      18,    19,    20,    22,    24,    25,    72,    23,    49,    55,
      56,    61,    41,    54,    41,    23,    23,    41,    75,    83,
      77,    80,    79,    81,    82,    71,    23,    84,     3,     3,
       8,    54,     7,    23,    63,     3,    78,    78,    78,    78,
      78,    21,    71,    85,    71,     3,    56,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    43,
      59,    64,    71,    20,    41,     7,    23,    20,    41,    65,
      67,    22,    22,    41,    41,    22,    22,    22,    22,    22,
      41,    70,    71,    70,    71,    22,    71,    69,    71,    71,
      71,    71,    71,    71,    21,    21,    41,    71,    23,    41,
      23,    23,    23,    23,    23,    41,    23,    64,    69,    68,
      41,    64,    69,     6,    67,    23,    66,    64,    67,    64,
      67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    48,
      47,    49,    49,    49,    51,    50,    50,    52,    52,    53,
      52,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    58,    58,    60,    61,    59,    62,    63,    63,    64,
      64,    64,    65,    64,    64,    64,    66,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    67,    68,    69,
      69,    70,    72,    71,    71,    73,    74,    74,    75,    77,
      76,    76,    79,    78,    80,    78,    81,    78,    82,    78,
      78,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    84,    83,
      83,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     7,     2,     2,     0,
       3,     1,     1,     1,     0,     6,     2,     5,     6,     0,
       7,     1,     0,     1,     3,     3,     6,     2,     0,     4,
       7,     2,     2,     0,     0,     6,     1,     2,     0,     2,
       1,     2,     0,     4,     1,     8,     0,    12,     5,     9,
       2,     2,     4,     4,     4,     4,     4,     0,     0,     1,
       0,     1,     0,     4,     1,     1,     3,     1,     1,     0,
       4,     1,     0,     4,     0,     4,     0,     4,     0,     4,
       1,     3,     3,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     4,     3,     3,     0,     5,
       3,     3,     1
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
        case 2:
#line 65 "subc.y" /* yacc.c:1646  */
    {
		char command[100];
		sprintf(command,"Lglob.data %d",Global_Scope->offset); 
		Write_Else(command);
    }
#line 1394 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 72 "subc.y" /* yacc.c:1646  */
    {
	}
#line 1401 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 77 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-3].declptr) && !check_is_declared_for_else((yyvsp[-1].idptr))) 
		    {
			struct decl *temp = declare((yyvsp[-1].idptr), makevardecl((yyvsp[-2].declptr)? (yyvsp[-2].declptr):(yyvsp[-3].declptr)))->decl;
			temp->argument = 0;
			//printStack(SStack.TOP->top);
			//printStack(StrStack);
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 1419 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 90 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-6].declptr) && (yyvsp[-2].declptr) && !check_is_declared_for_else((yyvsp[-4].idptr)))
		    {
			struct decl *temp = declare((yyvsp[-4].idptr), makeconstdecl(makearraydecl((yyvsp[-2].declptr)->intvalue, makevardecl((yyvsp[-5].declptr)? (yyvsp[-5].declptr):(yyvsp[-6].declptr)))))->decl;
			temp->argument = 0;			
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 1435 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1442 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 103 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1449 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 105 "subc.y" /* yacc.c:1646  */
    {
		    struct id* func_name = find_func((yyvsp[0].declptr))->name;
		    Write_Label(func_name->name);
		}
#line 1458 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 108 "subc.y" /* yacc.c:1646  */
    {
		    struct id* func_name = find_func((yyvsp[-2].declptr))->name;
		    char command[100];
		    sprintf(command,"%s_final",func_name->name); 
		    Write_Label(command);
		    Write_Command("push_reg fp");
		    Write_Command("pop_reg sp");
		    Write_Command("pop_reg fp");
		    Write_Command("pop_reg pc");
		    sprintf(command,"%s_end",func_name->name); 
		    Write_Label(command);
		}
#line 1475 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 123 "subc.y" /* yacc.c:1646  */
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
#line 1500 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 143 "subc.y" /* yacc.c:1646  */
    {
		    struct decl *typeptr = finddecl((yyvsp[0].idptr));
		    (yyval.declptr) = typeptr;
		}
#line 1509 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 147 "subc.y" /* yacc.c:1646  */
    { 
		    (yyval.declptr) = (yyvsp[0].declptr);
		}
#line 1517 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 153 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = check_is_declared_for_struct((yyvsp[-1].idptr));
		    push_scope();
		}
#line 1526 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 157 "subc.y" /* yacc.c:1646  */
    {
		    struct ste *fields = pop_scope();
		    if(!fields)
		    {
			yyerror("struct has no fields");
			(yyval.declptr) = NULL;
		    }
		    else if(!(yyvsp[-2].declptr))
		    {
			pushStr((yyvsp[-4].idptr), (yyval.declptr) = makestructdecl(fields));
		    }
		    else
		    {
			//error
			//free_ste_list(fields);
			(yyval.declptr) = NULL;
		    }
		}
#line 1549 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 175 "subc.y" /* yacc.c:1646  */
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
#line 1575 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 199 "subc.y" /* yacc.c:1646  */
    {
		    struct decl *procdecl = makeprocdecl();
		    push_scope();
		    declare(returnid, (yyvsp[-3].declptr)? (yyvsp[-3].declptr):(yyvsp[-4].declptr));
		    struct ste *formals;
		    formals = pop_scope();
		    procdecl->returntype = formals->decl;
		    procdecl->formals = formals;

		    struct decl *isdecl = check_is_declared_for_else((yyvsp[-2].idptr));

		    if(!isdecl)
		    {
			(yyval.declptr) = procdecl;
			declare((yyvsp[-2].idptr), (yyval.declptr));
			(yyval.declptr)->size = 0;
		    }
		    //int type은 한번 선언된적이 있는 function이 인지 확인 해준다.
		    else if(isdecl == inttype)
		    {
			struct decl *temp = finddecl((yyvsp[-2].idptr));
			//처음 선언했던 formal과 지금 선언하려는 formal이 같은지 확인한다.
			if(!check_function_declare(temp, procdecl))
			{
			    (yyval.declptr) = NULL;
			    yyerror("wrong declaration");
			}
			else
			{
			    (yyval.declptr) = temp;
			}
			procdecl->returntype = NULL;
			procdecl->formals = NULL;
			//free(procdecl);
			//free_ste_list(formals);
		    }
		    else
		    {
			procdecl->returntype = NULL;
			procdecl->formals = NULL;
			//free(procdecl);
			//free_ste_list(formals);
			(yyval.declptr) = NULL;
		    }
		}
#line 1625 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 244 "subc.y" /* yacc.c:1646  */
    {
		    struct decl *procdecl = makeprocdecl();
		    push_scope();
		    declare(returnid, (yyvsp[-4].declptr)? (yyvsp[-4].declptr):(yyvsp[-5].declptr));
		    struct ste *formals;
		    formals = pop_scope();
		    procdecl->returntype = formals->decl;
		    procdecl->formals = formals;

		    struct decl *isdecl = check_is_declared_for_else((yyvsp[-3].idptr));

		    if(!isdecl)
		    {
			(yyval.declptr) = procdecl;
			declare((yyvsp[-3].idptr), (yyval.declptr));
			(yyval.declptr)->size = 0;
		    }
		    else if(isdecl == inttype)
		    {
			struct decl *temp = finddecl((yyvsp[-3].idptr));
			if(!check_function_declare(temp, procdecl))
			{
			    yyerror("wrong declarartion");
			    (yyval.declptr) = NULL;
			}
			else
			{
			    (yyval.declptr) = temp;
			}
			procdecl->returntype = NULL;
			procdecl->formals = NULL;
			//free(procdecl);
			//free_ste_list(formals);
		    }
		    else
		    {
			procdecl->returntype = NULL;
			procdecl->formals = NULL;
			//free(procdecl);
			//free_ste_list(formals);
			(yyval.declptr) = NULL;
		    }
		}
#line 1673 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 287 "subc.y" /* yacc.c:1646  */
    {
		    struct decl *procdecl = makeprocdecl();
		    //tellmetype(procdecl);
		    //필요없는 elementvar을 사용해서 선언된적 있는 ID인지 확인한다.
		    procdecl->elementvar = check_is_declared_for_else((yyvsp[-1].idptr));
		    push_scope();
		    declare(returnid, (yyvsp[-2].declptr)? (yyvsp[-2].declptr):(yyvsp[-3].declptr));
		    (yyval.declptr) = procdecl;
		}
#line 1687 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 295 "subc.y" /* yacc.c:1646  */
    {
		    struct ste *formals;
		    struct decl *procdecl = (yyvsp[-2].declptr);
		    formals = pop_scope();
		    /* pop_scope reverses stes(first one is the returnid) */
		    procdecl->returntype = formals->decl; /* No for type checking */
		    procdecl->formals = formals;	// must check again
		    if(!(procdecl->elementvar) && (yyvsp[-1].intVal))
		    {
			(yyval.declptr) = procdecl;
			procdecl->elementvar = NULL;
			declare((yyvsp[-4].idptr), (yyval.declptr));
			(yyval.declptr)->size = (yyvsp[-1].intVal);
		    }
		    else if(procdecl->elementvar == inttype && (yyvsp[-1].intVal))
		    {
			struct decl *temp = finddecl((yyvsp[-4].idptr));
			if(check_function_declare(temp, procdecl))
			{
			    (yyval.declptr) = temp;
			}
			else
			{
			    yyerror("wrong declaration");
			    (yyval.declptr) = NULL;
			}
			procdecl->formals = NULL;
			procdecl->elementvar = NULL;
			procdecl->returntype = NULL;
			//free(procdecl);
			//free_ste_list(formals);
		    } 
		    else
		    {
			procdecl->formals = NULL;
			procdecl->elementvar = NULL;
			procdecl->returntype = NULL;
			//free(procdecl);
			//free_ste_list(formals);
			(yyval.declptr) = NULL;
		    }
		}
#line 1734 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 340 "subc.y" /* yacc.c:1646  */
    {
		    //TYPE이면 ptrdecl을 미리 만들어 둔다.
		    if((yyvsp[-1].declptr) && (yyvsp[-1].declptr)->declclass == TYPE)	
			(yyval.declptr) = makeptrdecl((yyvsp[-1].declptr));
		    else
			(yyval.declptr) = NULL;
		}
#line 1746 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 347 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = NULL;
		}
#line 1754 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 352 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[0].intVal))
			(yyval.intVal) = (yyvsp[0].intVal);
		    else
			(yyval.intVal) = 0;
		}
#line 1765 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 358 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-2].intVal) && (yyvsp[0].intVal))
			(yyval.intVal) = (yyvsp[-2].intVal) + (yyvsp[0].intVal);
		    else
			(yyval.intVal) = 0;
		}
#line 1776 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 366 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-2].declptr) && !check_is_declared_for_else((yyvsp[0].idptr)))
		    {
			struct decl *temp = declare((yyvsp[0].idptr), makevardecl((yyvsp[-1].declptr)? (yyvsp[-1].declptr):(yyvsp[-2].declptr)))->decl;
			(yyval.intVal) = temp->size;
		    }
		    else
		    {
			(yyval.intVal) = 0;
		    }
		}
#line 1792 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 377 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-5].declptr) && (yyvsp[-1].declptr) && !check_is_declared_for_else((yyvsp[-3].idptr)))
		    {
			struct decl *temp = declare((yyvsp[-3].idptr), makeconstdecl(makearraydecl((yyvsp[-1].declptr)->intvalue, makevardecl((yyvsp[-4].declptr)? (yyvsp[-4].declptr):(yyvsp[-5].declptr)))))->decl;
			(yyval.intVal) = temp->size;
		    }
		    else
		    {
			(yyval.intVal) = 0;
		    }
		}
#line 1808 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 390 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.intVal) = (yyvsp[-1].intVal) + (yyvsp[0].intVal);
		}
#line 1816 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 393 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.intVal) = 0;
		}
#line 1824 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 398 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-3].declptr) && !check_is_declared_for_else((yyvsp[-1].idptr)))
		    {
			struct decl *temp = declare((yyvsp[-1].idptr), makevardecl((yyvsp[-2].declptr)? (yyvsp[-2].declptr):(yyvsp[-3].declptr)))->decl;
			(yyval.intVal) = temp->size;
		    }
		    else
		    {
			(yyval.intVal) = 0;
		    }
		}
#line 1840 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 409 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-6].declptr) && (yyvsp[-2].declptr) && !check_is_declared_for_else((yyvsp[-4].idptr)))
		    {
			struct decl *temp = declare((yyvsp[-4].idptr), makeconstdecl(makearraydecl((yyvsp[-2].declptr)->intvalue, makevardecl((yyvsp[-5].declptr)? (yyvsp[-5].declptr):(yyvsp[-6].declptr)))))->decl;
			(yyval.intVal) = temp->size;
		    }
		    else
		    {
			(yyval.intVal)= 0;
		    }
		}
#line 1856 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 420 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-1].declptr))
		    {
			(yyval.intVal) = 0;
		    }
		    else
		    {
			(yyval.intVal) = 0;
		    }
		}
#line 1871 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 430 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-1].declptr))
		    {
			(yyval.intVal) = 0;
		    }
		    else
		    {
			(yyval.intVal) = 0;
		    }
		}
#line 1886 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 442 "subc.y" /* yacc.c:1646  */
    {
		    push_scope();
		    if((yyvsp[(-1) - (1)].declptr) && !finddecl(returnid))
		    {
			push_ste_list((yyvsp[(-1) - (1)].declptr)->formals);
			(yyval.intVal) = 1;
		    }
		    else
			(yyval.intVal) = 0;
		}
#line 1901 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 451 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-1].intVal))
		    {
			struct id *func_name = find_func((yyvsp[(-1) - (3)].declptr))->name;
			char command[100];
			sprintf(command, "shift_sp %d", (yyvsp[0].intVal));
			Write_Command(command);
			sprintf(command, "%s_start", func_name->name);
			Write_Label(command);
			in_func = 1;
		    }
		}
#line 1918 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 462 "subc.y" /* yacc.c:1646  */
    {
		    //free_scope();
		    pop_scope();
		    if((yyvsp[(-1) - (6)].declptr) && !finddecl(returnid))
		    {
			(yyvsp[(-1) - (6)].declptr)->isdeclared = 1;
			in_func = 0;
		    }
		}
#line 1932 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 473 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.intVal) = (yyvsp[0].intVal);
		}
#line 1940 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 478 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1947 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 480 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1954 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 484 "subc.y" /* yacc.c:1646  */
    {
		    Write_Command("shift_sp -1");
		}
#line 1962 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 487 "subc.y" /* yacc.c:1646  */
    {
		}
#line 1969 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 489 "subc.y" /* yacc.c:1646  */
    {
		   if(!check_compatible(finddecl(returnid), voidtype))
			yyerror("return value is not return type");
		   else
		   {
			struct id *func_name = find_func_closest()->name;
			char command[100];
			sprintf(command, "jump %s_final", func_name->name);
			Write_Command(command);
		   }
		}
#line 1985 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 500 "subc.y" /* yacc.c:1646  */
    {
		    char command[100];
		    Write_Command("push_reg fp");
		    Write_Command("push_const -1");
		    Write_Command("add");
		    sprintf(command, "push_const -%d", finddecl(returnid)->size);
		    Write_Command(command);
		    Write_Command("add");		    
		}
#line 1999 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 508 "subc.y" /* yacc.c:1646  */
    {
		    if(!check_compatible(finddecl(returnid), (yyvsp[-1].declptr)->type))
			yyerror("return value is not return type");
		    else
		    {
			struct id *func_name = find_func_closest()->name;
			char command[100];
			if((yyvsp[-1].declptr)->fetch)
			    Write_Command("fetch");
			Write_Command("assgin");
			sprintf(command, "jump %s_final", func_name->name);
			Write_Command(command);
		    }
		}
#line 2018 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 524 "subc.y" /* yacc.c:1646  */
    {
		    char command[100];
		    sprintf(command, "jump label_%d", label_no + 1);
		    Write_Command(command);
		}
#line 2028 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 533 "subc.y" /* yacc.c:1646  */
    {

		}
#line 2036 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 536 "subc.y" /* yacc.c:1646  */
    {

		}
#line 2044 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 539 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-1].declptr)->fetch)
			Write_Command("fetch");
		    Write_Command("write_int");
		}
#line 2054 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 544 "subc.y" /* yacc.c:1646  */
    {
		}
#line 2061 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 546 "subc.y" /* yacc.c:1646  */
    {
		    char command[100];
		    sprintf(command,"push_const str_%d",string_no++);
		    Write_Command(command);
		    Write_Command("write_string");
		}
#line 2072 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 553 "subc.y" /* yacc.c:1646  */
    {
		    char command[100];
		    sprintf(command, "label_%d", label_no++);      
		    Write_Label(command);
		}
#line 2082 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 559 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[(-1) - (0)].declptr)->fetch)
			Write_Command("fetch");
		    char command[100];
		    sprintf(command, "branch_false label_%d", label_no);
		    Write_Command(command);
		}
#line 2094 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 568 "subc.y" /* yacc.c:1646  */
    {
		}
#line 2101 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 570 "subc.y" /* yacc.c:1646  */
    {
		}
#line 2108 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 574 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[0].declptr))
		    {
			(yyval.declptr) = NULL;
		    }
		    //check index type
		    else if(check_compatible_type((yyvsp[0].declptr)->type, inttype))
		    {
			if((yyvsp[0].declptr)->declclass == Hash("CONST"))
			    (yyval.declptr) = (yyvsp[0].declptr);
			else
			{
			    yyerror("index is must const");
			    (yyval.declptr) = NULL;
			}
		    }
		    else
		    {
			yyerror("index is not inttype");
			(yyval.declptr) = NULL;
		    }
		}
#line 2135 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 598 "subc.y" /* yacc.c:1646  */
    {
		    Write_Command("push_reg sp");
		    Write_Command("fetch");
		    //struct assign은 길게 늘어뜨리면 될것이다. while문을 쓰면 될듯
		}
#line 2145 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 602 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-3].declptr) || !(yyvsp[0].declptr))
		    {
			(yyval.declptr) = NULL;
		    }
		    else if(check_is_var_type((yyvsp[-3].declptr)))
		    {
			if(check_compatible((yyvsp[-3].declptr)->type, (yyvsp[0].declptr)->type))
			{
			    (yyval.declptr) = (yyvsp[-3].declptr);
			    (yyvsp[-3].declptr)->intvalue = (yyvsp[0].declptr)->intvalue;
			    (yyvsp[-3].declptr)->charvalue = (yyvsp[0].declptr)->charvalue;
			    (yyvsp[-3].declptr)->stringvalue = (yyvsp[0].declptr)->stringvalue;
			    if((yyvsp[0].declptr)->fetch)
			    {
				Write_Command("fetch");
			    }
			    Write_Command("assign");
			    Write_Command("fetch");
			    (yyval.declptr)->fetch = 0;

			    if((yyvsp[-3].declptr)->type->typeclass == Hash("struct"))
			    {
				int size = (yyvsp[-3].declptr)->size;
				char command[100];
				while(size > 1)
				{
				    //global 일 때도 해결해야함
				    Write_Command("push_reg fp");
				    sprintf(command, "push_const %d", (yyvsp[-3].declptr)->offset + (yyvsp[-3].declptr)->size - (--size));
				    Write_Command(command);
				    Write_Command("add");
				    Write_Command("push_reg fp");
				    sprintf(command, "push_const %d", (yyvsp[0].declptr)->offset + (yyvsp[-3].declptr)->size - (size));
				    Write_Command(command);
				    Write_Command("fetch");
				    Write_Command("assign");
				}
			    }
			}
			else
			{
			    yyerror("LHS and RHS are not same type");
			    (yyval.declptr) = NULL;
			}
		    }
		    else
		    {
			yyerror("LHS is not variable");
			(yyval.declptr) = NULL;
		    }
		}
#line 2202 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 660 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-2].declptr) || !(yyvsp[0].declptr))
		    {
			(yyval.declptr) = NULL;
		    }
		    else if(check_compatible_type((yyvsp[-2].declptr)->type, inttype) && check_compatible_type((yyvsp[0].declptr)->type, inttype))
		    {
			(yyval.declptr) = (yyvsp[-2].declptr);
			if((yyvsp[0].declptr)->fetch)
			    Write_Command("fetch");
			(yyval.declptr)->fetch = 0;
		    }
		    else
		    {
			yyerror("not int type");
			(yyval.declptr) = NULL;
		    }
		}
#line 2225 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 684 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-1].declptr)->fetch)
			Write_Command("fetch");
		}
#line 2234 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 687 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-3].declptr) || !(yyvsp[0].declptr))
		    {
			(yyval.declptr) = NULL;
		    }
		    else if(check_compatible_type((yyvsp[-3].declptr)->type, inttype) && check_compatible_type((yyvsp[0].declptr)->type, inttype))
		    {
			(yyval.declptr) = (yyvsp[-3].declptr);
			if((yyvsp[0].declptr)->fetch)
			    Write_Command("fetch");
			(yyval.declptr)->fetch = 0;
		    }
		    else
		    {
			yyerror("not int type");
			(yyval.declptr) = NULL;
		    }
		}
#line 2257 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 708 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-1].declptr)->fetch)
			Write_Command("fetch");
		}
#line 2266 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 711 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-3].declptr) || !(yyvsp[0].declptr))
		    {
			(yyval.declptr) = NULL;
		    }
		    else if(reloptype((yyvsp[-3].declptr)->type, (yyvsp[0].declptr)->type))
		    {
			(yyval.declptr) = makeconstdecl(inttype);
			if((yyvsp[0].declptr)->fetch)
			    Write_Command("fetch");
			(yyval.declptr)->fetch = 0;
			if(!strcmp((yyvsp[-2].stringVal), ">="))
			{
			    Write_Command("greater_equal");
			}
			else if(!strcmp((yyvsp[-2].stringVal), ">"))
			{
			    Write_Command("greater");
			}
			else if(!strcmp((yyvsp[-2].stringVal), "<"))
			{
			    Write_Command("less");
			}
			else
			{
			    Write_Command("less_equal");
			}
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 2304 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 744 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-1].declptr)->fetch)
			Write_Command("fetch");
		}
#line 2313 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 747 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-3].declptr) || !(yyvsp[0].declptr))
		    {
			(yyval.declptr) = NULL;
		    }
		    else if(equoptype((yyvsp[-3].declptr)->type, (yyvsp[0].declptr)->type))
		    {
			(yyval.declptr) = makeconstdecl(inttype);
			if((yyvsp[0].declptr)->fetch)
			    Write_Command("fetch");
			(yyval.declptr)->fetch = 0;
			if(!strcmp((yyvsp[-2].stringVal), "=="))
			{
			    Write_Command("equal");
			}
			else
			{
			    Write_Command("not equal");
			}
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 2343 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 772 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-1].declptr)->fetch)
			Write_Command("fetch");
		}
#line 2352 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 775 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-3].declptr) || !(yyvsp[0].declptr))
		    {
			(yyval.declptr) = NULL;
		    }
		    else if(plustype((yyvsp[-3].declptr)->type, (yyvsp[0].declptr)->type))
		    {
			(yyval.declptr) = (yyvsp[-3].declptr);
			if((yyvsp[0].declptr)->fetch)
			    Write_Command("fetch");
			(yyval.declptr)->fetch = 0;
			Write_Command("add");
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 2375 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 793 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-1].declptr)->fetch)
			Write_Command("fetch");
		}
#line 2384 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 796 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-3].declptr) || !(yyvsp[0].declptr))
		    {
			(yyval.declptr) = NULL;
		    }
		    else if(minustype((yyvsp[-3].declptr)->type, (yyvsp[0].declptr)->type))
		    {
			(yyval.declptr) = (yyvsp[-3].declptr);
			if((yyvsp[0].declptr)->fetch)
			    Write_Command("fetch");
			(yyval.declptr)->fetch = 0;
			Write_Command("sub");
		    }
		    else
		    { 
			(yyval.declptr) = NULL;
		    }
		}
#line 2407 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 814 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[0].declptr))
			(yyval.declptr) = (yyvsp[0].declptr);	//do not return decl->type
		    else 
			(yyval.declptr) = NULL;
		}
#line 2418 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 822 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-1].declptr))  // it made by const decl!!
			(yyval.declptr) = makeconstdecl((yyvsp[-1].declptr)->type);
		    else
			(yyval.declptr) = NULL;
		}
#line 2429 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 828 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-1].declptr))
			(yyval.declptr) = (yyvsp[-1].declptr);
		    else
			(yyval.declptr) = NULL;
		}
#line 2440 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 834 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = makenumconstdecl(inttype, (yyvsp[0].intVal));
		    if(in_func)
		    {
			char command[100];
			sprintf(command, "push_const %d", (yyvsp[0].intVal));
			Write_Command(command);
			(yyval.declptr)->fetch = 0;
		    }
		}
#line 2455 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 844 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = makecharconstdecl(chartype, (yyvsp[0].stringVal));
		    (yyval.declptr)->fetch = 0;
		    char command[100];
		    sprintf(command,"push_const %d", (yyval.declptr)->charvalue[0]);
		    Write_Command(command);
		}
#line 2467 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 851 "subc.y" /* yacc.c:1646  */
    {
		    (yyval.declptr) = makestringconstdecl(chartype, (yyvsp[0].stringVal)); 
		    (yyval.declptr)->fetch = 0;
		    char command[100];
		    sprintf(command, "str_%d. string %s", string_no, (yyval.declptr)->stringvalue);
		    Write_Else(command);
		}
#line 2479 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 858 "subc.y" /* yacc.c:1646  */
    {
		    if(finddecl((yyvsp[0].idptr)))
		    {
			(yyval.declptr) = finddecl((yyvsp[0].idptr));
			if((yyval.declptr)->declclass == Hash("FUNC"))
			{
			}
			else if((yyval.declptr)->scope == Global_Scope)
			{
			    char command[100];
			    sprintf(command, "push_const Lglob+%d", (yyval.declptr)->offset);
			    Write_Command(command);
			    (yyval.declptr)->fetch = 1;
			}
			else
			{
			    Write_Command("push_reg fp");
			    char command[100];
			    sprintf(command, "push_const %d", (yyval.declptr)->offset);
			    Write_Command(command);
			    Write_Command("add");
			    (yyval.declptr)->fetch = 1;
			}
		    }
		    else
		    {
			//error
			yyerror("not declared");
			(yyval.declptr) = NULL;
		    }
		}
#line 2515 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 889 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[0].declptr) && check_compatible_type((yyvsp[0].declptr)->type, inttype))
		    {
			(yyval.declptr) = (yyvsp[0].declptr);
			if((yyvsp[0].declptr)->fetch)
			    Write_Command("fetch");
			Write_Command("negate");
		    }
		    else
		    {
			yyerror("not int type");
			(yyval.declptr) = NULL;
		    }
		}
#line 2534 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 903 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[0].declptr) && check_compatible_type((yyvsp[0].declptr)->type, inttype))
		    {
			(yyval.declptr) = (yyvsp[0].declptr);
			if((yyvsp[0].declptr)->fetch)
			    Write_Command("fetch");
			Write_Command("not");
		    }
		    else
		    {
			yyerror("not int type");
			(yyval.declptr) = NULL;
		    }
		}
#line 2553 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 917 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-1].declptr) && !INDECOPtype((yyvsp[-1].declptr)->type))
			(yyval.declptr) = NULL;
		    else
		    {
			(yyval.declptr) =(yyvsp[-1].declptr);
			Write_Command("push_reg sp");	
			Write_Command("fetch");					
			Write_Command("push_reg sp");				
			Write_Command("fetch");					
			Write_Command("fetch");
			char command[100];
			int size;
			if((yyvsp[-1].declptr)->type->typeclass == Hash("ptr"))
			{
			    size = (yyvsp[-1].declptr)->type->ptrto->size;
			} 
			else
			{
			    size = 1;
			}
			sprintf(command, "push_const %d", size);
			Write_Command(command);				
			Write_Command("add");					
			Write_Command("assign");				
			Write_Command("fetch");
			Write_Command(command);				
			Write_Command("sub");					
			(yyvsp[-1].declptr)->fetch = 0;
		    }
		}
#line 2589 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 948 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-1].declptr) && !INDECOPtype((yyvsp[-1].declptr)->type))
			(yyval.declptr) = NULL;
		    else
		    {
			(yyval.declptr) = (yyvsp[-1].declptr);
			Write_Command("push_reg sp");	
			Write_Command("fetch");					
			Write_Command("push_reg sp");				
			Write_Command("fetch");					
			Write_Command("fetch");
			char command[100];
			int size;
			if((yyvsp[-1].declptr)->type->typeclass == Hash("ptr"))
			{
			    size = (yyvsp[-1].declptr)->type->ptrto->size;
			} 
			else
			{
			    size = 1;
			}
			sprintf(command, "push_const %d", size);
			Write_Command(command);				
			Write_Command("sub");					
			Write_Command("assign");				
			Write_Command("fetch");
			Write_Command(command);				
			Write_Command("add");					
			(yyvsp[-1].declptr)->fetch = 0;
		    }
		}
#line 2625 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 979 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[0].declptr) && !INDECOPtype((yyvsp[0].declptr)->type))
			(yyval.declptr) = NULL;
		    else
			{
			(yyval.declptr) = (yyvsp[0].declptr);
			Write_Command("push_reg sp");
			Write_Command("fetch");
			Write_Command("push_reg sp");
			Write_Command("fetch");
			Write_Command("fetch");
			char command[100];
			int size;
			if((yyvsp[0].declptr)->type->typeclass == Hash("ptr"))
			{
			    size = (yyvsp[0].declptr)->type->ptrto->size;
			} 
			else
			{
			    size = 1;
			}
			sprintf(command, "push_const %d", size);
			Write_Command(command);				
			Write_Command("add");					
			Write_Command("assign");
			Write_Command("fetch");
			(yyvsp[0].declptr)->fetch = 0;
			}
		}
#line 2659 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1008 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[0].declptr) && !INDECOPtype((yyvsp[0].declptr)->type))
			(yyval.declptr) = NULL;
		    else
		    {
			(yyval.declptr) = (yyvsp[0].declptr);
			Write_Command("push_reg sp");	
			Write_Command("fetch");					
			Write_Command("push_reg sp");				
			Write_Command("fetch");					
			Write_Command("fetch");
			char command[100];
			int size;
			if((yyvsp[0].declptr)->type->typeclass == Hash("ptr"))
			{
			    size = (yyvsp[0].declptr)->type->ptrto->size;
			} 
			else
			{
			    size = 1;
			}
			sprintf(command, "push_const %d", size);
			Write_Command(command);				
			Write_Command("sub");					
			Write_Command("assign");				
			Write_Command("fetch");					
			(yyvsp[0].declptr)->fetch = 0;
		    }      
		}
#line 2693 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1037 "subc.y" /* yacc.c:1646  */
    {
		    if(check_is_var_type((yyvsp[0].declptr)))	//i must check this again! must deep copy
		    {	
			struct decl *temp;
			if(temp = deep_copy_pointer((yyvsp[0].declptr)->type))
			{
			    (yyval.declptr) = makeconstdecl(temp);
			    (yyval.declptr)->fetch = 0;
			}
			else
			    (yyval.declptr) = NULL;
		    }
		    else
		    {
			//error
			if((yyvsp[0].declptr))
			    yyerror("not variable");
			(yyval.declptr) = NULL;
		    }
		}
#line 2718 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1057 "subc.y" /* yacc.c:1646  */
    {
		    if(check_is_var_type((yyvsp[0].declptr)) && check_is_ptr_type((yyvsp[0].declptr)->type))
		    {
			struct decl *temp;
			if(temp = deep_copy_variable((yyvsp[0].declptr)->type->ptrto))
			{
			    (yyval.declptr) = temp;
			    if((yyvsp[0].declptr)->fetch)
				Write_Command("fetch");
			    (yyval.declptr)->fetch = 1;
			}
			else
			    (yyval.declptr) = NULL;
		    }
		    else
		    {
			//error
			if((yyvsp[0].declptr) && !check_is_var_type((yyvsp[0].declptr)))
			    yyerror("not variable");
			(yyval.declptr) = NULL;
		    }
		}
#line 2745 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1079 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-3].declptr) || !(yyvsp[-1].declptr))
		    {
			(yyval.declptr) = NULL;
		    }
		    else if(check_is_const_type((yyvsp[-3].declptr)))
		    {
			(yyval.declptr) = arrayaccess((yyvsp[-3].declptr), (yyvsp[-1].declptr)->type);
			(yyval.declptr)->fetch = 1;
			char command[100];
			sprintf(command, "push_const %d", (yyvsp[-3].declptr)->type->elementvar->size);
			if((yyvsp[-1].declptr)->fetch)
			{
			    Write_Command("fetch");
			}
			Write_Command(command);
			Write_Command("mul");
			Write_Command("add");
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 2774 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1103 "subc.y" /* yacc.c:1646  */
    {
		    if(check_is_var_type((yyvsp[-2].declptr)))
		    {
			(yyval.declptr) = structaccess((yyvsp[-2].declptr), (yyvsp[0].idptr));
			(yyval.declptr)->fetch = 1;
			char command[100];
			sprintf(command, "push_const %d", (yyval.declptr)->offset);
			Write_Command(command);
			Write_Command("add");
		    }
		    else
		    {
			if((yyvsp[-2].declptr))
			    yyerror("not variable");
			(yyval.declptr) = NULL;
		    }
		}
#line 2796 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1120 "subc.y" /* yacc.c:1646  */
    {
		    if(check_is_var_type((yyvsp[-2].declptr)))
		    {
			(yyval.declptr) = structPtraccess((yyvsp[-2].declptr), (yyvsp[0].idptr));
			(yyval.declptr)->fetch = 1;
			char command[100];
			sprintf(command, "push_const %d", (yyval.declptr)->offset);
			Write_Command(command);
			Write_Command("add");
		    }
		    else
		    {
			if((yyvsp[-2].declptr))
			    yyerror("not variable");
			(yyval.declptr) = NULL;
		    }
		}
#line 2818 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1137 "subc.y" /* yacc.c:1646  */
    {
		   char command[100];
		   sprintf(command, "shift_sp %d", find_func((yyvsp[-1].declptr))->decl->formals->decl->size);
		   Write_Command(command);
		   sprintf(command, "push_const label_%d", label_no);
		   Write_Command(command);
		   Write_Command("push_reg fp");
		}
#line 2831 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1144 "subc.y" /* yacc.c:1646  */
    {
		    if(!(yyvsp[-4].declptr) || !(yyvsp[-1].declptr))
		    {
			(yyval.declptr) = NULL;
		    }
		    else if(check_is_proc((yyvsp[-4].declptr)))
		    {
			(yyval.declptr) = check_function_call((yyvsp[-4].declptr), (yyvsp[-1].declptr));
			struct id *func_name = find_func((yyvsp[-4].declptr))->name;
			(yyval.declptr)->fetch = 0;
			char command[100];
			Write_Command("push_reg sp");
			sprintf(command, "push_const -%d", (yyvsp[-4].declptr)->size);
			Write_Command(command);
			Write_Command("add");
			Write_Command("pop_reg fp");
			sprintf(command, "jump %s", func_name->name);
			Write_Command(command);
			sprintf(command, "label_%d", label_no++);
			Write_Label(command);
		    }
		    else
		    {	
			(yyval.declptr) = NULL;
		    }
		    
		    /*if($3)
		    {
			struct decl *temp = $3;
			while(temp)
			{
			    free(temp);
			    temp = temp->next;
			}
			}*/
		}
#line 2872 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1180 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-2].declptr) && check_is_proc((yyvsp[-2].declptr)))
		    {
			(yyval.declptr) = check_function_call((yyvsp[-2].declptr), NULL);
			struct id *func_name = find_func((yyvsp[-2].declptr))->name;
			(yyval.declptr)->fetch = 0;
			char command[100];
			sprintf(command, "shift_sp %d", find_func((yyvsp[-2].declptr))->decl->formals->decl->size);
			Write_Command(command);
			sprintf(command, "push_const label_%d", label_no);
			Write_Command(command);
			Write_Command("push_reg fp");
			Write_Command("push_reg sp");
			sprintf(command, "push_const -%d", (yyvsp[-2].declptr)->size);
			Write_Command(command);
			Write_Command("add");
			Write_Command("pop_reg fp");
			sprintf(command, "jump %s", func_name->name);
			Write_Command(command);
			sprintf(command, "label_%d", label_no);
			Write_Label(command);
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 2904 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1209 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[-2].declptr) && (yyvsp[0].declptr))
		    {
			(yyval.declptr) = (yyvsp[-2].declptr);
			struct decl *temp = (yyval.declptr);
			while(temp->next)
			{
			    temp = temp->next;
			}
			temp->next = makevardecl((yyvsp[0].declptr)->type);
			temp->next->next = NULL;
			(yyval.declptr)->fetch = 1;
			if((yyvsp[0].declptr)->fetch)
			    Write_Command("fetch");

			int size = (yyvsp[0].declptr)->size;
			while(size > 1)
			{
			    Write_Command("push_reg fp");
			    char command[100];
			    sprintf(command, "push_const %d", (yyvsp[0].declptr)->offset +(yyvsp[0].declptr)->size -(--size));
			    Write_Command(command);
			    Write_Command("add");
			    Write_Command("fetch");
			}
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 2940 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1240 "subc.y" /* yacc.c:1646  */
    {
		    if((yyvsp[0].declptr))
		    {
			(yyval.declptr) = makevardecl((yyvsp[0].declptr)->type);
			(yyval.declptr)->next = NULL;
			(yyval.declptr)->fetch = 1;
			if((yyvsp[0].declptr)->fetch)
			    Write_Command("fetch");
			int size = (yyvsp[0].declptr)->size;
			while(size > 1)
			{
			    Write_Command("push_reg fp");
			    char command[100];
			    sprintf(command, "push_const %d", (yyvsp[0].declptr)->offset + (yyvsp[0].declptr)->size-(--size));
			    Write_Command(command);
			    Write_Command("add");
			    Write_Command("fetch");
			}
		    }
		    else
		    {
			(yyval.declptr) = NULL;
		    }
		}
#line 2969 "subc.tab.c" /* yacc.c:1646  */
    break;


#line 2973 "subc.tab.c" /* yacc.c:1646  */
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
#line 1265 "subc.y" /* yacc.c:1906  */


/*  Additional C Codes 
 	Implemnt REDUCE function here */


//project4
void Write_Command(char* command)
{
    if(file_out)
    {
	fprintf(file_out,"\t%s\n", command);
    }
    else
    {
	printf("\t%s\n", command);
    }
}
void Write_Label(char* command)
{
    if(file_out)
    {
	fprintf(file_out,"%s:\n", command);
    }
    else
    {
	printf("%s:\n", command);
    }
}
void Write_Else(char* command)
{
    if(file_out)
    {
	fprintf(file_out,"%s\n", command);
    }
    else
    {
	printf("%s\n",command);
    }
}


int get_field_size(struct ste *steptr)
{
    int size = 0;
    struct ste *temp = steptr;
    while(temp)
    {
	size += temp->decl->size;
	temp = temp->prev;
    }
    return size;
}

struct ste *find_func(struct decl *declptr)
{
    struct ste *temp = SStack.TOP->top;
    while(temp)
    {
	if(temp->decl == declptr)
	{
	    return temp;
	}
	temp = temp->prev;
    }
    return NULL;
}

struct ste *find_func_closest()
{
    struct ste *temp = SStack.TOP->top;
    while(temp)
    {
	if(temp->decl->declclass == Hash("FUNC"))
	{
	    return temp;
	}
	temp = temp->prev;
    }
    return NULL;
}


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
    SStack.TOP->garbage_top = NULL;
    SStack.TOP->offset = 0;
    StrStack = NULL;

    Global_Scope = SStack.TOP;	//global scope


    inttype = maketypedecl(Hash("int"));
    chartype = maketypedecl(Hash("char"));
    voidtype = maketypedecl(VOID);

    declare(enter(TYPE, "int", 3), inttype)->decl->size = 1;
    declare(enter(TYPE, "char", 4), chartype)->decl->size = 1;
    declare(enter(VOID, "void", 4), voidtype)->decl->size = 1;
    returnid = enter(ID, "*return", 7);
    in_func = 0;
    label_no = 0;
    string_no = 0;

    Write_Command("shift_sp 1");
    Write_Command("push_const EXIT");
    Write_Command("push_reg fp");
    Write_Command("push_reg sp");
    Write_Command("pop_reg fp");
    Write_Command("jump main");
    Write_Label("EXIT");
    Write_Command("exit");
}

struct ste *push_scope()	/* SStack.TOP에다가 새로히 ScopeNode를 만들고 연결 시킨다. */
{
    struct ScopeNode *temp = SStack.TOP;
    SStack.TOP = (struct ScopeNode*)malloc(sizeof(struct ScopeNode));
    SStack.TOP->prev = temp;
    SStack.TOP->top = temp->top;
    SStack.TOP->garbage_top = temp->garbage_top;
    SStack.TOP->offset = 0;
    return SStack.TOP->top;
}

struct decl *deep_copy(struct decl *declptr)
{
    struct decl *ftemp = declptr;
    if(ftemp)
    {
	 if(ftemp->typeclass == Hash("array"))
	{
	    if(ftemp->elementvar->type->typeclass == Hash("ptr"))
	    {
		return garbage_insert(makeconstdecl(makearraydecl(ftemp->intvalue, makevardecl(makeptrdecl(ftemp->elementvar->type->ptrto)))))->decl;
	    }
	    else
	    {
		return garbage_insert(makeconstdecl(makearraydecl(ftemp->intvalue, makevardecl(ftemp->elementvar->type))))->decl;
	    }
	}
	else if(ftemp->typeclass == Hash("ptr"))
	{
	    return garbage_insert(makeconstdecl(makeptrdecl(ftemp->ptrto)))->decl;
	}
	else
	{
	    return garbage_insert(makeconstdecl(ftemp))->decl;
	}	
    }
    return NULL;
}

struct decl *deep_copy_pointer(struct decl *declptr)
{
    struct decl *ftemp = declptr;
    if(ftemp)
    {
	 if(ftemp->typeclass == Hash("array"))
	{
	   /* if(ftemp->elementvar->type->typeclass == Hash("ptr"))
	    {
		return makeptrdecl(makearraydecl(ftemp->intvalue, makevardecl(makeptrdecl(ftemp->elementvar->type->ptrto))));
	    }
	    else
	    {
		return makeptrdecl(makearraydecl(ftemp->intvalue, makevardecl(ftemp->elementvar->type)));
	    }*/
	    yyerror("not & operator type");
	    return NULL;
	}
	else if(ftemp->typeclass == Hash("ptr"))
	{
	   // return makeptrdecl(makeptrdecl(ftemp->ptrto));
	    yyerror("not & operator type");
	    return NULL;
	}
	else
	{
	    return makeptrdecl(ftemp);
	}	
    }
    return NULL;
}

struct decl *deep_copy_variable(struct decl *declptr)
{
    struct decl *ftemp = declptr;
    if(ftemp)
    {
	 if(ftemp->typeclass == Hash("array"))
	{
	   /* if(ftemp->elementvar->type->typeclass == Hash("ptr"))
	    {
		return makevardecl(makearraydecl(ftemp->intvalue, makevardecl(makeptrdecl(ftemp->elementvar->type->ptrto))));
	    }
	    else
	    {
		return makevardecl(makearraydecl(ftemp->intvalue, makevardecl(ftemp->elementvar->type)));
	    }*/
	yyerror("not * operator type");
	return NULL;
	}
	else if(ftemp->typeclass == Hash("ptr"))
	{
	   // return makevardecl(makeptrdecl(ftemp->ptrto));
	    yyerror("not * operator type");
	    return NULL;
	}
	else
	{
	    return makevardecl(ftemp);
	}	
    }
    return NULL;
}


struct ste *push_ste_list(struct ste *formals)	//완벽한 deep copy를 해준다. 안한다.
{
    struct ste *ftemp = formals;
    while(ftemp)
    {
	declare(ftemp->name, ftemp->decl);
	/*if(ftemp->decl->declclass == TYPE)  //returnid의 경우 decl이 바로 TYPE을 가리키므로 ftemp->decl을 바로 사용한다.
	{
	    if(ftemp->decl->typeclass == Hash("ptr"))
	    {
		declare(ftemp->name, makeptrdecl(ftemp->decl->ptrto));
	    }
	    else
	    {
		declare(ftemp->name, ftemp->decl);
	    }
	}
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
	}*/
	ftemp = ftemp->prev;
    }
    return SStack.TOP->top;
}


struct ste *pop_scope()		/* 현재 SStack.TOP->prev가 가르키는 ste까지 내려간다. */
{
    struct ste *temp = SStack.TOP->top;
    struct ste *temp2 = NULL;
    struct ste *Head = NULL;

    if(temp == SStack.TOP->prev->top)/* push_scope()하고 아무것도 추가하지 않은 경우 */
    {
	//free(SStack.TOP);
	SStack.TOP = SStack.TOP->prev;
	return NULL;
    }

    while(temp != SStack.TOP->prev->top)
    {
	Head = temp->prev;
	temp->prev = temp2;
	temp2 = temp;
	temp = Head;
    }
    temp = NULL;
    Head = NULL;
    /*
    struct ste *garbage_temp = SStack.TOP->garbage_top;
    struct ste *garbage_temp3 = SStack.TOP->prev->garbage_top;
    while(garbage_temp != garbage_temp3)
    {
	free_ste(garbage_temp);
	garbage_temp = garbage_temp->prev;
    }
    
    free(SStack.TOP);*/
    SStack.TOP = SStack.TOP->prev;      /* SStack.TOP의 scope를 한단계 낮춘다. */

    return temp2;
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

    struct ste *garbage_temp = SStack.TOP->garbage_top;
    struct ste *garbage_temp3 = SStack.TOP->prev->garbage_top;
    while(garbage_temp != garbage_temp3)
    {
	free_ste(garbage_temp);
	garbage_temp = garbage_temp->prev;
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
    declptr->scope = SStack.TOP;
    declptr->offset = SStack.TOP->offset;
    SStack.TOP->offset += declptr->size;
    return SStack.TOP->top;
}

struct ste *garbage_insert( struct decl *declptr)
{
    struct ste *STE = (struct ste*)malloc(sizeof(struct ste));
    STE->decl = declptr;
    STE->prev = SStack.TOP->garbage_top;
    STE->name = NULL;
    SStack.TOP->garbage_top = STE;

    return SStack.TOP->garbage_top;
}

struct ste *free_ste(struct ste *steptr)
{
    free_decl(steptr->decl);	//ste를 해제하고 그 decl도 해제한다.
    free(steptr);
    steptr->decl = NULL;
    steptr->name = NULL;
    return NULL;
}

//when decl free make all pointer and value 0
struct decl *free_decl(struct decl *declptr)
{
    if(declptr->type)
    {
	if(declptr->type->typeclass == Hash("array"))
	{
	    if(declptr->type->elementvar->type->typeclass == Hash("ptr"))
	    {
		declptr->type->elementvar->type->ptrto = NULL;
		declptr->type->elementvar->type->typeclass = 0;
		declptr->type->elementvar->type->declclass = 0;
		free(declptr->type->elementvar->type);
		declptr->type->elementvar->typeclass = 0;
		declptr->type->elementvar->declclass = 0;
		declptr->type->elementvar->type = NULL;
		free(declptr->type->elementvar);
		declptr->type->typeclass = 0;
		declptr->type->declclass = 0;
		declptr->type->elementvar = NULL;
		free(declptr->type);
		declptr->typeclass = 0;
		declptr->declclass = 0;
		declptr->type = NULL;
		free(declptr);
	    }
	    else
	    {
		declptr->type->elementvar->typeclass = 0;
		declptr->type->elementvar->declclass = 0;
		declptr->type->elementvar->type = NULL;
		free(declptr->type->elementvar);
		declptr->type->typeclass = 0;
		declptr->type->declclass = 0;
		declptr->type->elementvar = NULL;
		free(declptr->type);
		declptr->typeclass = 0;
		declptr->declclass = 0;
		declptr->type = NULL;
		free(declptr);
	    }
	}
	else if(declptr->type->typeclass == Hash("ptr"))
	{
	    declptr->type->typeclass = 0;
	    declptr->type->declclass = 0;
	    declptr->type->ptrto = NULL;
	    free(declptr->type);
	    declptr->typeclass = 0;
	    declptr->declclass = 0;
	    declptr->type = NULL;
	    free(declptr);
	}
	else
	{
	    declptr->typeclass = 0;
	    declptr->declclass = 0;
	    declptr->type = NULL;
	    free(declptr);
	}
    }
    else if(declptr->ptrto)
    {
	declptr->typeclass = 0;
	declptr->declclass = 0;
	declptr->ptrto = NULL;
	free(declptr);
    }
    return NULL;
}

struct ste *sdestroy()
{
    while(SStack.TOP->top)
    {
	if(SStack.TOP->top->decl->declclass == Hash("FUNC"))
	{
	    free_ste(SStack.TOP->top->decl->formals);
	    free(SStack.TOP->top->decl);
	}
	if(SStack.TOP->top->decl->declclass == TYPE)
	    free(SStack.TOP->top->decl);
	free_ste(SStack.TOP->top);
	SStack.TOP->top = SStack.TOP->top->prev;
    }

    while(SStack.TOP->garbage_top)
    {
	free_ste(SStack.TOP->garbage_top);
	SStack.TOP->garbage_top = SStack.TOP->garbage_top->prev;
    }

    while(SStack.TOP)
    {
	free(SStack.TOP);
	SStack.TOP = SStack.TOP->prev;
    }

    while(StrStack)
    {
	if(StrStack->decl->fieldlist)
	    free_ste(StrStack->decl->fieldlist);
	free(StrStack->decl);
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
    temp->size = typeptr->size;
    temp->fetch = 1;
    return temp;
}

struct decl *makeptrdecl(struct decl *typeptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->ptrto = typeptr;
    temp->typeclass = Hash("ptr");
    temp->declclass = TYPE;
    temp->size = 1;
    temp->fetch = 1;
    return temp;
}

struct decl *makearraydecl(int numidx, struct decl *varptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->elementvar = varptr;
    temp->declclass = TYPE;
    temp->num_index = numidx;
    temp->typeclass = Hash("array");
    temp->size = numidx * (temp->elementvar->size);
    return temp;
}

struct decl *makestructdecl(struct ste *fieldptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->fieldlist = fieldptr;
    temp->declclass = TYPE;
    temp->typeclass = Hash("struct");
    temp->size = get_field_size(fieldptr);
    return temp;
}

struct decl *makeconstdecl(struct decl *typeptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("CONST");
    temp->type = typeptr;
    temp->size = typeptr->size;
    return temp;
}

struct decl *makenumconstdecl(struct decl *typeptr, int intconst)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("CONST");
    temp->type = typeptr;
    temp->intvalue = intconst;
    temp->size = typeptr->size;
    return temp;
}

struct decl *makecharconstdecl(struct decl *typeptr, char *charconst)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("CONST");
    temp->type = typeptr;
    temp->charvalue = charconst;
    temp->size = typeptr->size;
    return temp;
}

struct decl *makestringconstdecl(struct decl *typeptr, const char* stringconst)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("CONST");
    temp->type = makeptrdecl(typeptr);
    temp->stringvalue = stringconst;
    temp->size = strlen(stringconst);
    return temp;
}

struct decl *makeprocdecl()
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("FUNC");
    temp->isdeclared = 0;
    return temp;
}






struct decl *finddecl(id *entry)    /* entry에 해당하는 name을 가진 ste가 있는지 찾는다.*/
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
//	yyerror("type is not suitable for plus operaton");
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
    else
    {
	yyerror("type is not suitable for plus operaton");
	return NULL;
    }
}

struct decl *minustype(struct decl *type1, struct decl *type2)
{
    if(type1 == NULL || type2 == NULL)
    {
//	yyerror("type is not suitable for minus operaton");
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
    else
    {
	yyerror("type is not suitable for minus operaton");
	return NULL;
    }
}

struct decl *reloptype(struct decl *type1, struct decl *type2)
{
    if(check_compatible_type(type1, type2))
    {
	if(type1->typeclass == Hash("struct") || type1->typeclass == Hash("array") || type1->typeclass == VOID)
	{
	    yyerror("type is not suitable for relop operaton");
	    return NULL;
	}
	else
	{
	    return inttype;
	}
    }
    else
    {
	yyerror("type is not suitable for relop operaton");
	return NULL;
    }
}
    
struct decl *equoptype(struct decl *type1, struct decl *type2)
{
    if(check_compatible_type(type1, type2))
    {
	if(type1->typeclass == Hash("struct") || type1->typeclass == Hash("array") || type1->typeclass == VOID)
	{
	    yyerror("type is not suitable for equop operaton");
	    return NULL;
	}
	else
	{
	    return inttype;
	}
    }
    else
    {
	yyerror("type is not suitable for equop operaton");
	return NULL;
    }
}

struct decl *INDECOPtype(struct decl *type)
{
    if(type == inttype || type == chartype)
    {
	return type;
    }
    else if(type == NULL)
    {
	return NULL;
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
		yyerror("1");
		break;
	    }
	}
	else if(formals->decl->type->typeclass == Hash("array") && actuals->type->typeclass == Hash("array"))
	{
	    if(check_compatible(formals->decl->type->elementvar->type, actuals->type->elementvar->type))
	    {
		formals = formals->prev;
		actuals = actuals->next;
	    }
	    else
	    {
		yyerror("2");
		break;
	    }
	}
	else
	{
	    yyerror("3");
	    break;
	}
    }
    if(formals || actuals)
    {
   	yyerror("actual args are not equal to formal args");
	return NULL;
    }

//    return deep_copy(procptr->returntype);  /* for decl of the call */
    return makeconstdecl(procptr->returntype);
}

struct decl *check_function_declare(struct decl *procptr, struct decl *procptr2)
{
    struct ste *formals = procptr->formals;
    struct ste *actuals = procptr2->formals;
    /* 1. compare number of formals and actuals */

    /* 2. check for type match			*/
    while(formals != NULL && actuals != NULL)
    {
	if(check_is_var_type(formals->decl))
	{
	    if(check_compatible(formals->decl->type, actuals->decl->type))
	    {
		if(formals->decl->type->typeclass == Hash("ptr") && actuals->decl->type->typeclass == Hash("array"))
		    break; 
		else
		{
		    formals = formals->prev;
		    actuals = actuals->prev;
		}
	    }
	    else
		break;
	}
	else if(formals->name == returnid)
	{
	    if(formals->decl == actuals->decl)
	    {
		formals = formals->prev;
		actuals = actuals->prev;
	    }
	    else if(formals->decl->typeclass == Hash("ptr") && formals->decl->ptrto == actuals->decl->ptrto)
	    {
		formals = formals->prev;
		actuals = actuals->prev;
	    }
	    else
		break;
	}
	else if(formals->decl->type->typeclass == Hash("array") && actuals->decl->type->typeclass == Hash("array"))
	{
	    if(check_compatible(formals->decl->type->elementvar->type, actuals->decl->type->elementvar->type))
	    {
		formals = formals->prev;
		actuals = actuals->prev;
	    }
	    else
		break;
	}
	else
	    break;
    }
    if(formals || actuals)
    {
	return NULL;
    }

    return (procptr->returntype);  /* for decl of the call */
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

struct decl *check_is_declared_for_else(struct id *entry) //variable을 선언하기 위해 동일한 entry를 name으로 가지는 ste가 있는지 찾는 함수 이다. struct scope와 현재 scope만 뒤진다. 
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
		    return inttype; //한번 정의 된적 있다는 신호이다.
		}
	    }
	    yyerror("redeclaration");
	    return temp->decl;
	}
	temp = temp->prev;
    }
    /*
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
    */
    return NULL; 
}

struct decl *check_is_declared_for_struct(struct id *entry) //struct를 선언하기 위해 동일한 entry를 name으로 가지는 ste가 있는지 찾는 함수 이다. 전체 scope를 다 뒤진다. 
{
    /*
    struct ste *temp = SStack.TOP->top;
    while(temp)
    {
	if(temp->name == entry)
	{
	    yyerror("redeclaration");
	    return temp->decl;
	}
	temp = temp->prev;
    }*/
    
    struct ste *temp = StrStack;
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
	if(top->name)
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
	REDUCE("look the type decl");
	tellmetype(temp->type);
    }
    if(temp->returntype)
    {
	REDUCE("look the returntype decl");
	tellmetype(temp->returntype);
    }
    if(temp->elementvar)
    {
	REDUCE("look the elmentvar decl");
	tellmetype(temp->elementvar);
    }
    if(temp->ptrto)
    {
	REDUCE("look the ptrto decl");
	tellmetype(temp->ptrto);
    }
    if(temp->fieldlist)
    {
	REDUCE("look the fieldlist");
	printStack(temp->fieldlist);
    }
    if(temp->formals)
    {
	REDUCE("look the formals");
	printStack(temp->formals);
    }
    
}

struct ste *pushStr(struct id *entry, struct decl *declptr) //struct stack의 push 함수
{
    struct ste *temp = StrStack;
    StrStack = (struct ste*)malloc(sizeof(struct ste));
    StrStack->name = entry;
    StrStack->decl = declptr;
    StrStack->prev = temp;
    return StrStack;
}
