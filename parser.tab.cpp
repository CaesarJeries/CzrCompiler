/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.ypp" /* yacc.c:339  */


#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <exception>
#include "hw5.hpp"
#include "Scope.hpp"
#include "FunctionTable.hpp"
#include "ScopeManager.hpp"
#include "output.hpp"
#include "CodeGen.hpp"
#include "RegPool.hpp"
#include "bp.hpp"

#define DEBUG 0



using std::stringstream;
using namespace CodeGen;
using namespace std;
int yylex();
void yyerror(const char*);
string setType(string t1, string t2);
bool checkAssignmentType(string, string);
bool checkBinOpType(string, string);
bool isNumber(string type);
extern int yylineno;
using namespace output;

void debug_print(string s){
	if(DEBUG) cout << s << endl;
}

/**	Globals	*/
ScopeManager scopeManager;
FunctionTable functions;

#define CHECK_VAR_DECL(s) do{ \
if(scopeManager.isDeclared(s) == false){ \
				errorUndef(yylineno, s); \
				YYERROR; \
			} \
}while(0)


#define CHECK_DECL_IDEN(s) do{ \
	if(scopeManager.isDeclared(s) || functions.isDeclared(s)){ \
				errorDef(yylineno, s); \
				YYERROR; \
	} \
}while(0)


#define CHECK_VAR_NOT_DECL(s) CHECK_DECL_IDEN(s)

#define CHECK_FUNC_DECL(s) do{ \
if(functions.isDeclared(s) == false){ \
				errorUndefFunc(yylineno, s); \
				YYERROR; \
			} \
}while(0)

#define CHECK_FUNC_NOT_DECL(s) CHECK_DECL_IDEN(s)



#line 136 "parser.tab.cpp" /* yacc.c:339  */

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
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
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
    VOID = 258,
    INT = 259,
    BYTE = 260,
    B = 261,
    BOOL = 262,
    TRUE = 263,
    FALSE = 264,
    RETURN = 265,
    IF = 266,
    ELSE = 267,
    WHILE = 268,
    SWITCH = 269,
    CASE = 270,
    BREAK = 271,
    DEFAULT = 272,
    COLON = 273,
    SC = 274,
    COMMA = 275,
    LPAREN = 276,
    RPAREN = 277,
    LBRACE = 278,
    RBRACE = 279,
    ID = 280,
    NUM = 281,
    STRING = 282,
    EOF_TOKEN = 283,
    ASSIGN = 284,
    OR = 285,
    AND = 286,
    RELOP = 287,
    PLUS = 288,
    MINUS = 289,
    MULT = 290,
    DIV = 291,
    NOT = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 225 "parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   232

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    96,   109,   110,   116,   123,   115,   147,
     147,   149,   150,   151,   157,   156,   163,   170,   172,   180,
     179,   195,   204,   247,   294,   295,   305,   347,   360,   364,
     346,   401,   400,   415,   421,   434,   420,   462,   474,   481,
     473,   527,   550,   567,   566,   586,   599,   607,   606,   620,
     634,   658,   679,   718,   717,   760,   761,   762,   764,   768,
     787,   806,   824,   844,   853,   861,   866,   877,   887,   897,
     907,   936,   935,   973,   972,  1009,  1026,  1030,  1034
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "BYTE", "B", "BOOL",
  "TRUE", "FALSE", "RETURN", "IF", "ELSE", "WHILE", "SWITCH", "CASE",
  "BREAK", "DEFAULT", "COLON", "SC", "COMMA", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "ID", "NUM", "STRING", "EOF_TOKEN", "ASSIGN", "OR", "AND",
  "RELOP", "PLUS", "MINUS", "MULT", "DIV", "NOT", "$accept", "Program",
  "Funcs", "FuncDecl", "$@1", "$@2", "RetType", "Formals", "FormalsList",
  "$@3", "FormalDecl", "Statements", "Statement", "$@4", "$@5", "$@6",
  "@7", "Statement_With_Else", "$@8", "$@9", "$@10", "$@11", "$@12",
  "CaseList", "CaseStatement", "@13", "CaseDec", "$@14", "Call", "ExpList",
  "$@15", "Type", "Exp", "$@16", "$@17", "M", "N", "NB", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF -108

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-108)))

#define YYTABLE_NINF -79

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,  -108,  -108,  -108,  -108,  -108,    23,  -108,    39,     3,
    -108,  -108,  -108,  -108,    12,    56,  -108,  -108,    18,    25,
      42,    47,  -108,    45,    56,   170,  -108,    -5,    48,    58,
      59,  -108,    16,   109,  -108,    74,    69,    79,  -108,  -108,
    -108,    65,    80,   103,  -108,    65,  -108,   166,    65,  -108,
      65,   170,    50,    65,  -108,  -108,  -108,    -4,    91,    95,
    -108,  -108,  -108,  -108,  -108,    65,    65,    65,    65,    65,
     181,    65,   181,   131,  -108,    96,   117,   173,  -108,    65,
    -108,  -108,  -108,  -108,   137,   -17,   -17,  -108,  -108,    99,
     181,  -108,  -108,  -108,   104,  -108,   191,    65,    65,  -108,
     118,   121,    65,  -108,   155,   196,  -108,  -108,   116,  -108,
     170,  -108,  -108,  -108,   170,    32,   134,  -108,   133,   143,
      82,  -108,    83,  -108,  -108,  -108,    11,  -108,   146,  -108,
     170,  -108,  -108,  -108,  -108,  -108,   153,  -108,   144,  -108,
     170,  -108,  -108,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    55,    56,    57,     3,     0,     2,     5,     0,
       9,     1,     4,     6,     0,    11,     7,    12,    13,     0,
       0,     0,    16,     0,     0,    78,    15,     0,     0,     0,
       0,    19,     0,    78,    17,     0,     0,     0,    68,    69,
      25,     0,    63,    65,    67,     0,    64,     0,     0,    76,
       0,    78,     0,     0,     8,    18,    24,     0,     0,     0,
      66,    70,    26,    73,    71,     0,     0,     0,     0,     0,
      27,     0,    77,    78,    51,     0,    52,     0,    21,     0,
      37,    58,    76,    76,    75,    59,    60,    61,    62,     0,
      34,    38,    20,    50,     0,    23,     0,     0,     0,    28,
       0,     0,     0,    22,    74,    72,    76,    35,     0,    54,
      78,    76,    39,    29,    78,     0,    33,    77,     0,     0,
       0,    42,    43,    31,    30,    36,     0,    76,     0,    41,
      78,    77,    47,    76,    49,    40,    44,    76,     0,    46,
      78,    76,    32,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,   160,  -108,  -108,  -108,  -108,  -108,   158,  -108,
    -108,   -49,   -32,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,    98,  -108,  -108,  -108,   -25,    77,
    -108,    88,   -14,  -108,  -108,   -71,  -107,  -108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    14,    20,     9,    16,    17,    21,
      18,    33,    34,    51,    89,   106,   116,   124,   131,   100,
     111,   101,   115,   120,   121,   130,   122,   138,    46,    75,
      94,    36,    76,    83,    82,    71,    91,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    55,    73,    38,    39,     1,     2,     3,    35,     4,
     125,    97,    98,    47,    40,    78,    41,   132,    68,    69,
      42,    43,    44,    11,   137,    79,    35,    59,    13,   133,
       5,    61,    45,    15,    70,   110,    72,    52,   -14,    77,
     114,    55,     1,     2,     3,    53,     4,   118,    35,   119,
      22,    84,    85,    86,    87,    88,   134,    90,    38,    39,
       2,     3,   139,     4,    23,    96,   140,    24,    25,    48,
     143,    41,    74,    38,    39,    42,    43,    44,   113,    49,
      50,   136,   117,   104,   105,    35,    41,    45,    10,    35,
      42,    43,    44,    56,    57,    58,    10,   118,   -45,   119,
     -45,    52,    45,    19,    55,    35,   128,   -45,   142,    60,
      80,    35,    19,     2,     3,    35,     4,    81,    93,    27,
      28,    99,    29,    30,   102,    63,    64,    65,    66,    67,
      68,    69,    31,    54,    32,     2,     3,   -53,     4,   112,
     107,    27,    28,   108,    29,    30,   123,    63,    64,    65,
      66,    67,    68,    69,    31,    92,    32,     2,     3,   126,
       4,   127,   141,    27,    28,   135,    29,    30,    12,   -78,
      66,    67,    68,    69,     2,     3,    31,     4,    32,   109,
      27,    28,    26,    29,    30,    62,    64,    65,    66,    67,
      68,    69,    95,    31,     0,    32,    63,    64,    65,    66,
      67,    68,    69,    63,    64,    65,    66,    67,    68,    69,
     103,    63,    64,    65,    66,    67,    68,    69,   129,     0,
       0,    63,    64,    65,    66,    67,    68,    69,    65,    66,
      67,    68,    69
};

static const yytype_int16 yycheck[] =
{
      25,    33,    51,     8,     9,     3,     4,     5,    33,     7,
     117,    82,    83,    27,    19,    19,    21,     6,    35,    36,
      25,    26,    27,     0,   131,    29,    51,    41,    25,    18,
      28,    45,    37,    21,    48,   106,    50,    21,    20,    53,
     111,    73,     3,     4,     5,    29,     7,    15,    73,    17,
      25,    65,    66,    67,    68,    69,   127,    71,     8,     9,
       4,     5,   133,     7,    22,    79,   137,    20,    23,    21,
     141,    21,    22,     8,     9,    25,    26,    27,   110,    21,
      21,   130,   114,    97,    98,   110,    21,    37,     0,   114,
      25,    26,    27,    19,    25,    16,     8,    15,    15,    17,
      17,    21,    37,    15,   136,   130,    24,    24,   140,     6,
      19,   136,    24,     4,     5,   140,     7,    22,    22,    10,
      11,    22,    13,    14,    20,    30,    31,    32,    33,    34,
      35,    36,    23,    24,    25,     4,     5,    20,     7,    23,
      22,    10,    11,    22,    13,    14,    12,    30,    31,    32,
      33,    34,    35,    36,    23,    24,    25,     4,     5,    26,
       7,    18,    18,    10,    11,    19,    13,    14,     8,    16,
      33,    34,    35,    36,     4,     5,    23,     7,    25,   102,
      10,    11,    24,    13,    14,    19,    31,    32,    33,    34,
      35,    36,    19,    23,    -1,    25,    30,    31,    32,    33,
      34,    35,    36,    30,    31,    32,    33,    34,    35,    36,
      19,    30,    31,    32,    33,    34,    35,    36,   120,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    32,    33,
      34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,    28,    39,    40,    41,    44,
      69,     0,    40,    25,    42,    21,    45,    46,    48,    69,
      43,    47,    25,    22,    20,    23,    46,    10,    11,    13,
      14,    23,    25,    49,    50,    66,    69,    75,     8,     9,
      19,    21,    25,    26,    27,    37,    66,    70,    21,    21,
      21,    51,    21,    29,    24,    50,    19,    25,    16,    70,
       6,    70,    19,    30,    31,    32,    33,    34,    35,    36,
      70,    73,    70,    49,    22,    67,    70,    70,    19,    29,
      19,    22,    72,    71,    70,    70,    70,    70,    70,    52,
      70,    74,    24,    22,    68,    19,    70,    73,    73,    22,
      57,    59,    20,    19,    70,    70,    53,    22,    22,    67,
      73,    58,    23,    50,    73,    60,    54,    50,    15,    17,
      61,    62,    64,    12,    55,    74,    26,    18,    24,    62,
      63,    56,     6,    18,    73,    19,    49,    74,    65,    73,
      73,    18,    50,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    42,    43,    41,    44,
      44,    45,    45,    46,    47,    46,    48,    49,    49,    51,
      50,    50,    50,    50,    50,    50,    50,    52,    53,    54,
      50,    56,    55,    55,    57,    58,    50,    50,    59,    60,
      50,    61,    61,    63,    62,    62,    64,    65,    64,    64,
      66,    66,    67,    68,    67,    69,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    70,    72,    70,    70,    73,    74,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     0,     0,    10,     1,
       1,     0,     1,     1,     0,     4,     2,     1,     2,     0,
       4,     3,     5,     4,     2,     2,     3,     0,     0,     0,
      10,     0,     5,     0,     0,     0,    10,     3,     0,     0,
      11,     2,     1,     0,     3,     1,     4,     0,     6,     3,
       4,     3,     1,     0,     4,     1,     1,     1,     3,     3,
       3,     3,     3,     1,     1,     1,     2,     1,     1,     1,
       2,     0,     5,     0,     5,     3,     0,     0,     0
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
#line 87 "parser.ypp" /* yacc.c:1646  */
    {
			if(functions.isMainDefined() == false){
				errorMainMissing();
				YYERROR;
			}
			emitCode();
			YYACCEPT;
			}
#line 1427 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 97 "parser.ypp" /* yacc.c:1646  */
    {
				if(functions.isMainDefined() == false){
					errorMainMissing();
					YYERROR;
				}
				emitCode();
				YYACCEPT;
			}
#line 1440 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 116 "parser.ypp" /* yacc.c:1646  */
    {
				CHECK_FUNC_NOT_DECL((yyvsp[0]).name);
				Function((yyvsp[0]).name, (yyvsp[-1]).type);
				scopeManager.addScope((yyvsp[-1]).type);
				emitFunctionLabel((yyvsp[0]).name);
				emit("subu $fp, $sp, 4 # set current frame pointer");
			}
#line 1452 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 123 "parser.ypp" /* yacc.c:1646  */
    { functions.addFunction(Function::getCurrentFunc()); }
#line 1458 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "parser.ypp" /* yacc.c:1646  */
    {
				string str = getNext();
				bpatch((yyvsp[-1]).returnList, str);
				popLocals();
				scopeManager.popScope(false); // passing true results in bad address exceptions
				if((yyvsp[-8]).name == "main" && (yyvsp[-9]).type == "VOID"){
					// terminate program
					emit("li $v0, 10");
					emit("syscall");
				}else{
					emitReturn();
				}
				
				endDeclaration((yyvsp[-8]).name);
				RegPool::freeAll(); // ?
			}
#line 1479 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 152 "parser.ypp" /* yacc.c:1646  */
    {
					Function::addParamType((yyvsp[0]).type);
					scopeManager.addParam(Variable((yyvsp[0]).name, (yyvsp[0]).type));	
				}
#line 1488 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 157 "parser.ypp" /* yacc.c:1646  */
    {
					Function::addParamType((yyvsp[0]).type);
					scopeManager.addParam(Variable((yyvsp[0]).name, (yyvsp[0]).type));
				}
#line 1497 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 164 "parser.ypp" /* yacc.c:1646  */
    {
				//CHECK_VAR_NOT_DECL($2.name);
				(yyval).name = (yyvsp[0]).name;
				(yyval).type = (yyvsp[-1]).type;
			}
#line 1507 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 173 "parser.ypp" /* yacc.c:1646  */
    {
				(yyval).nextList = merge((yyvsp[-1]).nextList, (yyvsp[0]).nextList);
				(yyval).breakList = merge((yyvsp[-1]).breakList, (yyvsp[0]).breakList);
				(yyval).returnList = merge((yyvsp[-1]).returnList, (yyvsp[0]).returnList);
			}
#line 1517 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 180 "parser.ypp" /* yacc.c:1646  */
    { scopeManager.addScope(Scope::brace_scope); }
#line 1523 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 182 "parser.ypp" /* yacc.c:1646  */
    {
				(yyval).line = (yyvsp[-1]).line;
				(yyval).type = (yyvsp[-1]).type;
				scopeManager.popScope(true);
				
				(yyval).nextList = merge((yyvsp[-1]).nextList, (yyval).nextList);
				(yyval).breakList = merge((yyvsp[-1]).breakList, (yyval).breakList);
				(yyval).trueList = merge((yyvsp[-1]).trueList, (yyval).trueList);
				(yyval).falseList = merge((yyvsp[-1]).falseList, (yyval).falseList);
				(yyval).returnList = merge((yyvsp[-1]).returnList, (yyval).returnList);
			}
#line 1539 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 196 "parser.ypp" /* yacc.c:1646  */
    {
				CHECK_VAR_NOT_DECL((yyvsp[-1]).name);
				scopeManager.addVar(Variable((yyvsp[-1]).name, (yyvsp[-2]).type));
				(yyval).nextList = newList();
				(yyval).breakList = newList();
				pushLocalVariable();
			}
#line 1551 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 205 "parser.ypp" /* yacc.c:1646  */
    {
				CHECK_VAR_NOT_DECL((yyvsp[-3]).name);
				if(checkAssignmentType((yyvsp[-4]).type, (yyvsp[-1]).type) == false){
					errorMismatch(yylineno);
					YYERROR;
				}
				scopeManager.addVar(Variable((yyvsp[-3]).name, (yyvsp[-4]).type));
				(yyval).nextList = newList();
				(yyval).breakList = newList();
				/*	if Exp == TRUE/FALSE, jump to next line.	*/
				if((yyvsp[-1]).expType == "BOOLCONST" || (yyvsp[-1]).expType == "CALL" || (yyvsp[-1]).expType == "BOOLEXP"){
					string str = getNext();
					bpatch((yyvsp[-1]).trueList, str);
					bpatch((yyvsp[-1]).falseList, str);
					(yyvsp[-1]).trueList = newList();
					(yyvsp[-1]).falseList = newList();
				}
				if((yyvsp[-1]).expType == "BOOLEXP"){
					(yyvsp[-1]).reg = RegPool::getRegister();
					emitBoolOp((yyvsp[-1]).reg, (yyvsp[-1]).boolRegs, (yyvsp[-1]).op);
					RegPool::freeRegister((yyvsp[-1]).boolRegs);
				}
				if((yyvsp[-1]).expType == "RELOP"){
					string reg = RegPool::getRegister();
					string str = getNext();
					emit("addu " + reg + ", $zero, 1");
					bpatch((yyvsp[-1]).trueList, str);
					(yyvsp[-1]).trueList = newList();
					int location = emit("j ");
					str = getNext();
					emit("addu " + reg + ", $zero, 0");
					bpatch((yyvsp[-1]).falseList, str);
					(yyvsp[-1]).falseList = newList();
					bpatch(makelist(location), getNext());
					(yyvsp[-1]).reg = reg;
					RegPool::freeRegister((yyvsp[-1]).regList);
				}
				emit("# push local variable " + (yyvsp[-3]).name);
				pushLocalVariable((yyvsp[-1]).reg);
				RegPool::freeRegister((yyvsp[-1]).reg);
			}
#line 1597 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 248 "parser.ypp" /* yacc.c:1646  */
    {
				CHECK_VAR_DECL((yyvsp[-3]).name);
				string left_type = scopeManager.getVarType((yyvsp[-3]).name);
				if(checkAssignmentType(left_type, (yyvsp[-1]).type) == false){
					errorMismatch(yylineno);
					YYERROR;
				}
				(yyval).nextList = newList();
				(yyval).breakList = newList();
				/*	if Exp == TRUE/FALSE, jump to next line.	*/
				if((yyvsp[-1]).expType == "BOOLCONST" || (yyvsp[-1]).expType == "CALL"){
					string str = getNext();
					bpatch((yyvsp[-1]).trueList, str);
					bpatch((yyvsp[-1]).falseList, str);
					(yyvsp[-1]).trueList = newList();
					(yyvsp[-1]).falseList = newList();
				}
				if((yyvsp[-1]).expType == "BOOLEXP"){
					(yyvsp[-1]).reg = RegPool::getRegister();
					string str = getNext();
					bpatch((yyvsp[-1]).trueList, str);
					bpatch((yyvsp[-1]).falseList, str);
					(yyvsp[-1]).trueList = newList();
					(yyvsp[-1]).falseList = newList();
					emitBoolOp((yyvsp[-1]).reg, (yyvsp[-1]).boolRegs, (yyvsp[-1]).op);
					RegPool::freeRegister((yyvsp[-1]).boolRegs);
				}
				if((yyvsp[-1]).expType == "RELOP"){
					string reg = RegPool::getRegister();
					string str = getNext();
					emit("addu " + reg + ", $zero, 1");
					bpatch((yyvsp[-1]).trueList, str);
					(yyvsp[-1]).trueList = newList();
					int location = emit("j ");
					str = getNext();
					emit("addu " + reg + ", $zero, 0");
					bpatch((yyvsp[-1]).falseList, str);
					(yyvsp[-1]).falseList = newList();
					bpatch(makelist(location), getNext());
					(yyvsp[-1]).reg = reg;
					RegPool::freeRegister((yyvsp[-1]).regList);
				}
				updateLocalVariable(scopeManager.getVarOffset((yyvsp[-3]).name), (yyvsp[-1]).reg);
				RegPool::freeRegister((yyvsp[-1]).reg);
			}
#line 1647 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 296 "parser.ypp" /* yacc.c:1646  */
    {
				if(scopeManager.checkReturnTypeMatch("VOID", false) == false){
					errorMismatch(yylineno);
					YYERROR;
				}
				(yyval).type = string("RETURN");
				(yyval).nextList = newList();
				(yyval).returnList = makelist(emit("j "));
			}
#line 1661 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 306 "parser.ypp" /* yacc.c:1646  */
    {
				if(scopeManager.checkReturnTypeMatch((yyvsp[-1]).type, true) == false){
					errorMismatch(yylineno);
					YYERROR;
				}
				if((yyvsp[-1]).expType == "BOOLCONST" || (yyvsp[-1]).expType == "CALL" || (yyvsp[-1]).expType == "BOOLEXP"){
					string str = getNext();
					bpatch((yyvsp[-1]).trueList, str);
					bpatch((yyvsp[-1]).falseList, str);
					(yyvsp[-1]).trueList = newList();
					(yyvsp[-1]).falseList = newList();
				}
				if((yyvsp[-1]).expType == "BOOLEXP"){
					(yyvsp[-1]).reg = RegPool::getRegister();
					emitBoolOp((yyvsp[-1]).reg, (yyvsp[-1]).boolRegs, (yyvsp[-1]).op);
					RegPool::freeRegister((yyvsp[-1]).boolRegs);
				}
				if((yyvsp[-1]).expType == "RELOP"){
					string reg = RegPool::getRegister();
					string str = getNext();
					emit("addu " + reg + ", $zero, 1");
					bpatch((yyvsp[-1]).trueList, str);
					(yyvsp[-1]).trueList = newList();
					int location = emit("j ");
					str = getNext();
					emit("addu " + reg + ", $zero, 0");
					bpatch((yyvsp[-1]).falseList, str);
					(yyvsp[-1]).falseList = newList();
					bpatch(makelist(location), getNext());
					(yyvsp[-1]).reg = reg;
					RegPool::freeRegister((yyvsp[-1]).regList);
				}
				(yyval).type = string("RETURN");
				emit("move $v0, " + (yyvsp[-1]).reg + " # store return value");
				RegPool::freeRegister((yyvsp[-1]).reg);
				RegPool::freeRegister((yyvsp[-1]).regList);
				(yyval).nextList = newList();
				(yyval).returnList = makelist(emit("j "));
			}
#line 1705 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 347 "parser.ypp" /* yacc.c:1646  */
    {
				if((yyvsp[0]).type != "BOOL"){
					errorMismatch(yylineno);
					YYERROR;
				}
				if((yyvsp[0]).expType == "ID" || (yyvsp[0]).expType == "CALL"){
					int true_location = emitTrueCheck((yyvsp[0]).reg);
					int false_location = emit("j ");
					(yyvsp[0]).trueList = makelist(true_location);
					(yyvsp[0]).falseList = makelist(false_location);
				}
			}
#line 1722 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 360 "parser.ypp" /* yacc.c:1646  */
    {
				scopeManager.addScope(Scope::if_scope);
			}
#line 1730 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 364 "parser.ypp" /* yacc.c:1646  */
    {
				//		Exp			M
				bpatch((yyvsp[-5]).trueList, (yyvsp[-1]).quad);
				(yyvsp[-5]).trueList = newList();
				
				//				Statement
				(yyval).breakList = (yyvsp[0]).breakList;
				(yyval).returnList = (yyvsp[0]).returnList;
				scopeManager.popScope(true);
				RegPool::freeRegister((yyvsp[-5]).reg);
				RegPool::freeRegister((yyvsp[-5]).regList);
			}
#line 1747 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 377 "parser.ypp" /* yacc.c:1646  */
    {
				if((yyvsp[0]).quad != "NOELSE"){
					bpatch((yyvsp[-7]).falseList, (yyvsp[0]).quad);
					bpatch((yyvsp[-2]).nextList, (yyvsp[0]).quad2);
					(yyvsp[-7]).falseList = newList();
					(yyvsp[-2]).nextList = newList();
					(yyval).nextList = (yyvsp[0]).nextList;
					(yyval).breakList = merge((yyvsp[0]).breakList, (yyval).breakList);
					(yyval).returnList = merge((yyvsp[0]).returnList, (yyvsp[-2]).returnList);
					
				}else{
					vector<int> temp = merge((yyval).nextList, (yyvsp[-7]).falseList);
					(yyvsp[-7]).falseList = newList();
					(yyval).nextList = newList();
					bpatch(temp, (yyvsp[0]).quad2);
					(yyval).breakList = (yyvsp[-2]).breakList;
					(yyval).returnList = (yyvsp[-2]).returnList;
				}
			}
#line 1771 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 401 "parser.ypp" /* yacc.c:1646  */
    { scopeManager.addScope(Scope::else_scope); }
#line 1777 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 403 "parser.ypp" /* yacc.c:1646  */
    {
							(yyval).quad = (yyvsp[-1]).quad;
							string str = getNext();
							(yyval).quad2 = str;
							bpatch((yyvsp[-2]).nextList, str);
							(yyvsp[-2]).nextList = newList();
							(yyval).nextList = (yyvsp[0]).nextList;
							(yyval).breakList = (yyvsp[0]).breakList;
							(yyval).returnList = (yyvsp[0]).returnList;
							scopeManager.popScope(true);
						}
#line 1793 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 415 "parser.ypp" /* yacc.c:1646  */
    {
							(yyval).quad = string("NOELSE");
							(yyval).quad2 = getNext();
						}
#line 1802 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 421 "parser.ypp" /* yacc.c:1646  */
    {
				if((yyvsp[0]).type != "BOOL"){
					errorMismatch(yylineno);
					YYERROR;
				}
				if((yyvsp[0]).expType == "ID" || (yyvsp[0]).expType == "CALL"){
					int true_location = emitTrueCheck((yyvsp[0]).reg);
					int false_location = emit("j ");
					(yyvsp[0]).trueList = makelist(true_location);
					(yyvsp[0]).falseList = makelist(false_location);
				}
			}
#line 1819 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 434 "parser.ypp" /* yacc.c:1646  */
    {
				scopeManager.addScope(Scope::while_scope);
			}
#line 1827 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 438 "parser.ypp" /* yacc.c:1646  */
    {
				(yyval).nextList = newList();
				(yyval).breakList = newList();
				(yyval).returnList = (yyvsp[-1]).returnList;

				//  	EXP          M2
				bpatch((yyvsp[-6]).trueList, (yyvsp[-2]).quad);
				string str = getNext();
				bpatch((yyvsp[-6]).falseList, str);
				//		Statement
				bpatch((yyvsp[-1]).breakList, str);

				// if Statement reached the end N (there was no break), go to the boolean exp again
				
				// 		N            M1
				bpatch((yyvsp[0]).nextList, (yyvsp[-7]).quad); 

				// 		Statement   M1
				bpatch((yyvsp[-1]).nextList, (yyvsp[-7]).quad);
				scopeManager.popScope(true);
				RegPool::freeRegister((yyvsp[-6]).reg);
				RegPool::freeRegister((yyvsp[-6]).regList);
			}
#line 1855 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 463 "parser.ypp" /* yacc.c:1646  */
    {
				if(!scopeManager.isInsideWhileBlock() && !scopeManager.isInsideSwitchCase()){
					errorUnexpectedBreak(yylineno);
					YYERROR;
				}
				(yyval).type = string("RETURN");
				(yyval).breakList = (yyvsp[-2]).nextList;
				(yyval).nextList = newList();
			}
#line 1869 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 474 "parser.ypp" /* yacc.c:1646  */
    {
				if(!isNumber((yyvsp[-1]).type)){
					errorMismatch(yylineno);
					YYERROR;
				}
			}
#line 1880 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 481 "parser.ypp" /* yacc.c:1646  */
    {
				scopeManager.addScope(Scope::switch_scope);
				scopeManager.enteredSwitchScope();
			}
#line 1889 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 487 "parser.ypp" /* yacc.c:1646  */
    {
				scopeManager.exitedSwitchScope();
				scopeManager.popScope(true);
				//		N
				emit("# Break out of switch statement");
				vector<int> v = makelist(emit("j "));
				string str = getNext();
				bpatch((yyvsp[-7]).nextList, str);
				//						CaseList
				list<string> quadList = (yyvsp[-2]).quadList;
				list<int> valueList = (yyvsp[-2]).valueList;
				string quad = string("");
				int value = 0;
				
				
				while(!quadList.empty()){
					quad = quadList.front();
					value = valueList.front();
					stringstream ss;
					ss << value;
					emit("beq " + (yyvsp[-8]).reg + ", " + ss.str() + ", " + quad);
					quadList.pop_front();
					valueList.pop_front();
				}
				// If a default case exists, jump to defaultQuad
				if((yyvsp[-2]).defaultQuad != ""){
					emit("j " + (yyvsp[-2]).defaultQuad + " # jump to default case");
				}
				emit("# End of switch statement");
				string next_label = getNext();
				bpatch((yyvsp[-2]).nextList, next_label);
				bpatch(v, next_label);
				//$$.nextList = makelist(emit("j "));
				//$$.breakList = $9.breakList;
				bpatch((yyvsp[-2]).breakList, next_label);
				(yyval).returnList = (yyvsp[-2]).returnList;
				RegPool::freeRegister((yyvsp[-8]).reg);
				RegPool::freeRegister((yyvsp[-8]).regList);
			}
#line 1933 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 528 "parser.ypp" /* yacc.c:1646  */
    {
				(yyval).quadList = (yyvsp[-1]).quadList;
				(yyval).valueList = (yyvsp[-1]).valueList;
				if((yyvsp[0]).type == "default"){
					if((yyvsp[-1]).defaultQuad == ""){
						(yyval).defaultQuad = (yyvsp[0]).defaultQuad;
						(yyval).type = "default";
					}else{
						(yyval).defaultQuad = (yyvsp[-1]).defaultQuad;
						(yyval).type = "default";
					}
				}else{
					(yyval).defaultQuad = (yyvsp[-1]).defaultQuad;
					(yyval).quadList.push_back((yyvsp[0]).quad);
					(yyval).valueList.push_back((yyvsp[0]).val);
				}
				
				(yyval).nextList = merge((yyvsp[-1]).nextList, (yyvsp[0]).nextList);
				(yyval).breakList = merge((yyvsp[-1]).breakList, (yyvsp[0]).breakList);
				(yyval).returnList = merge((yyvsp[-1]).returnList, (yyvsp[0]).returnList);
			}
#line 1959 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 551 "parser.ypp" /* yacc.c:1646  */
    {
				//cout << "CaseStat: quad = " << $1.quad << ", value = " << $1.val << endl;
				if((yyvsp[0]).type == "default"){
					(yyval).defaultQuad = (yyvsp[0]).defaultQuad;
					(yyval).type = "default";
				}else{
					(yyval).quadList.push_front((yyvsp[0]).quad);
					(yyval).valueList.push_front((yyvsp[0]).val);
				}
				(yyval).nextList = (yyvsp[0]).nextList;
				(yyval).breakList = (yyvsp[0]).breakList;
				(yyval).returnList = (yyvsp[0]).returnList;
			}
#line 1977 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 567 "parser.ypp" /* yacc.c:1646  */
    {
					if((yyvsp[0]).type == "default"){
						(yyval).defaultQuad = (yyvsp[0]).defaultQuad;
						(yyval).type = "default";
					}else{
						(yyval).quad = (yyvsp[0]).quad;
						(yyval).val = (yyvsp[0]).val;
					}
					scopeManager.enteredSwitchCase();
				}
#line 1992 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 578 "parser.ypp" /* yacc.c:1646  */
    {
					scopeManager.exitedSwitchCase();
					(yyval).nextList = (yyvsp[0]).nextList;
					(yyval).breakList = (yyvsp[0]).breakList;
					(yyval).returnList = (yyvsp[0]).returnList;
				}
#line 2003 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 587 "parser.ypp" /* yacc.c:1646  */
    {
					if((yyvsp[0]).type == "default"){
						(yyval).defaultQuad = (yyvsp[0]).defaultQuad;
						(yyval).type = "default";
					}else{
						(yyval).quad = (yyvsp[0]).quad;
						(yyval).val = (yyvsp[0]).val;
					}
					(yyval).nextList = makelist(emit("j "));
				}
#line 2018 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 600 "parser.ypp" /* yacc.c:1646  */
    {
				(yyval).val = (yyvsp[-2]).val;
				(yyval).quad = (yyvsp[0]).quad;
			}
#line 2027 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 607 "parser.ypp" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).val > 255 || (yyvsp[-1]).val < 0){
					errorByteTooLarge(yylineno, (yyvsp[-2]).lexeme);
					YYERROR;
				}
				
			}
#line 2039 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 615 "parser.ypp" /* yacc.c:1646  */
    {
				(yyval).val = (yyvsp[-4]).val;
				(yyval).quad = (yyvsp[0]).quad;
			}
#line 2048 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 621 "parser.ypp" /* yacc.c:1646  */
    {
				if(scopeManager.hasDefaultStatement()){
					errorTooManyDefaults(yylineno);
					YYERROR;
				}
				scopeManager.defaultEncountered();
				(yyval).type = "default";
				(yyval).defaultQuad = (yyvsp[0]).quad;
			}
#line 2062 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 635 "parser.ypp" /* yacc.c:1646  */
    {
			CHECK_FUNC_DECL((yyvsp[-3]).name);
			if(functions.checkTypeMatch((yyvsp[-3]).name, (yyvsp[-1]).typeList) == false){
				vector<string> v = functions.getArgumentTypes((yyvsp[-3]).name);
				errorPrototypeMismatch(yylineno, (yyvsp[-3]).name, v);
				YYERROR;
			}
			(yyval).type = functions.getReturnType((yyvsp[-3]).name);
			list<string> saved_regs = saveRegs();
			pushFramePointer();
			pushReturnAddress();
			int n = (yyvsp[-1]).regList.size();
			pushArguments((yyvsp[-1]).regList);
			RegPool::freeRegister((yyvsp[-1]).regList);
			RegPool::freeRegister((yyvsp[-1]).reg);
			emit("jal " + (yyvsp[-3]).name);
			popArguments(n);
			popReturnAddress();
			popFramePointer();
			restoreRegs(saved_regs);
			(yyval).reg = string("$v0");
		}
#line 2089 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 659 "parser.ypp" /* yacc.c:1646  */
    {
			CHECK_FUNC_DECL((yyvsp[-2]).name);
			list<string> t = list<string>();
			if(functions.checkTypeMatch((yyvsp[-2]).name, t) == false){
				vector<string> v = functions.getArgumentTypes((yyvsp[-2]).name);
				errorPrototypeMismatch(yylineno, (yyvsp[-2]).name, v);
				YYERROR;
			}
			(yyval).type = functions.getReturnType((yyvsp[-2]).name);
			list<string> saved_regs = saveRegs();
			pushFramePointer();
			pushReturnAddress();
			emit("jal " + (yyvsp[-2]).name);
			popReturnAddress();
			popFramePointer();
			restoreRegs(saved_regs);
			(yyval).reg = string("$v0");
			(yyval).name = (yyvsp[-2]).name;
		}
#line 2113 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 680 "parser.ypp" /* yacc.c:1646  */
    {
				//emit("# ExpList -> Exp : expType = " + $1.expType);
				if((yyvsp[0]).expType == "BOOLCONST"){
					string str = getNext();
					bpatch((yyvsp[0]).trueList, str);
					bpatch((yyvsp[0]).falseList, str);
					RegPool::freeRegister((yyvsp[0]).reg);
				}
				if((yyvsp[0]).expType == "BOOLEXP"){
					(yyvsp[0]).reg = RegPool::getRegister();
					
					string str = getNext();
					bpatch((yyvsp[0]).trueList, str);
					bpatch((yyvsp[0]).falseList, str);
					emitBoolOp((yyvsp[0]).reg, (yyvsp[0]).boolRegs, (yyvsp[0]).op);
					RegPool::freeRegister((yyvsp[0]).boolRegs);
				}
				if((yyvsp[0]).expType == "RELOP"){
					string reg = RegPool::getRegister();
					string str = getNext();
					emit("addu " + reg + ", $zero, 1");
					bpatch((yyvsp[0]).trueList, str);
					(yyvsp[0]).trueList = newList();
					int location = emit("j ");
					str = getNext();
					emit("addu " + reg + ", $zero, 0");
					bpatch((yyvsp[0]).falseList, str);
					(yyvsp[0]).falseList = newList();
					bpatch(makelist(location), getNext());
					(yyvsp[0]).reg = reg;
					RegPool::freeRegister((yyvsp[0]).regList);
				}
				(yyval).typeList.push_front((yyvsp[0]).type);
				(yyval).regList.push_front((yyvsp[0]).reg);
				//$$.regList = merge($$.regList, $1.regList);
			}
#line 2154 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 718 "parser.ypp" /* yacc.c:1646  */
    {
				if((yyvsp[0]).expType == "BOOLCONST"){
					string str = getNext();
					bpatch((yyvsp[0]).trueList, str);
					bpatch((yyvsp[0]).falseList, str);
					//RegPool::freeRegister($1.reg);
				}
				if((yyvsp[0]).expType == "BOOLEXP"){
					//emit("# ExpList -> Exp : at BOOLEXP");
					(yyvsp[0]).reg = RegPool::getRegister();
					string str = getNext();
					bpatch((yyvsp[0]).trueList, str);
					bpatch((yyvsp[0]).falseList, str);
					emitBoolOp((yyvsp[0]).reg, (yyvsp[0]).boolRegs, (yyvsp[0]).op);
					
					RegPool::freeRegister((yyvsp[0]).boolRegs);
				}
				if((yyvsp[0]).expType == "RELOP"){
					string reg = RegPool::getRegister();
					string str = getNext();
					emit("addu " + reg + ", $zero, 1");
					bpatch((yyvsp[0]).trueList, str);
					(yyvsp[0]).trueList = newList();
					int location = emit("j ");
					str = getNext();
					emit("addu " + reg + ", $zero, 0");
					bpatch((yyvsp[0]).falseList, str);
					(yyvsp[0]).falseList = newList();
					bpatch(makelist(location), getNext());
					(yyvsp[0]).reg = reg;
					RegPool::freeRegister((yyvsp[0]).regList);
				}
			}
#line 2192 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 752 "parser.ypp" /* yacc.c:1646  */
    {
				
				(yyval).regList = merge((yyvsp[0]).regList, (yyvsp[-3]).regList);
				(yyval).typeList = (yyvsp[0]).typeList;
				(yyval).typeList.push_front((yyvsp[-3]).type);
				(yyval).regList.push_front((yyvsp[-3]).reg);
			}
#line 2204 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 760 "parser.ypp" /* yacc.c:1646  */
    { (yyval).type = string("INT");}
#line 2210 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 761 "parser.ypp" /* yacc.c:1646  */
    { (yyval).type = string("BYTE");}
#line 2216 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 762 "parser.ypp" /* yacc.c:1646  */
    { (yyval).type = string("BOOL");}
#line 2222 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 765 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval) = (yyvsp[-1]);
		}
#line 2230 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 769 "parser.ypp" /* yacc.c:1646  */
    {
			if(checkBinOpType((yyvsp[-2]).type, (yyvsp[0]).type) == false){
				errorMismatch(yylineno);
				YYERROR;
			}
			(yyval).type = setType((yyvsp[-2]).type, (yyvsp[0]).type);
			string reg = (yyvsp[-2]).reg;	// recycle a register from one of the sons
			(yyval).reg = reg;
			emit("addu " + reg + ", " + (yyvsp[-2]).reg + ", " + (yyvsp[0]).reg);
			if((yyval).type == "BYTE"){
				emit("and " + reg + ", " + reg + ", 255");
			}
			//RegPool::freeRegister($1.reg);
			RegPool::freeRegister((yyvsp[0]).reg);
			RegPool::freeRegister((yyvsp[-2]).regList);
			RegPool::freeRegister((yyvsp[0]).regList);
		}
#line 2252 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 788 "parser.ypp" /* yacc.c:1646  */
    {
			if(checkBinOpType((yyvsp[-2]).type, (yyvsp[0]).type) == false){
				errorMismatch(yylineno);
				YYERROR;
			}
			(yyval).type = setType((yyvsp[-2]).type, (yyvsp[0]).type);
			string reg = (yyvsp[-2]).reg;
			(yyval).reg = reg;
			emit("subu " + reg + ", " + (yyvsp[-2]).reg + ", " + (yyvsp[0]).reg);
			if((yyval).type == "BYTE"){
				emit("and " + reg + ", " + reg + ", 255");
			}
			//RegPool::freeRegister($1.reg);
			RegPool::freeRegister((yyvsp[0]).reg);
			RegPool::freeRegister((yyvsp[-2]).regList);
			RegPool::freeRegister((yyvsp[0]).regList);
		}
#line 2274 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 807 "parser.ypp" /* yacc.c:1646  */
    {
			if(checkBinOpType((yyvsp[-2]).type, (yyvsp[0]).type) == false){
				errorMismatch(yylineno);
				YYERROR;
			}
			(yyval).type = setType((yyvsp[-2]).type, (yyvsp[0]).type);
			string reg = (yyvsp[-2]).reg;
			(yyval).reg = reg;
			emit("mul " + reg + ", " + (yyvsp[-2]).reg + ", " + (yyvsp[0]).reg);
			if((yyval).type == "BYTE"){
				emit("and " + reg + ", " + reg + ", 255");
			}
			RegPool::freeRegister((yyvsp[0]).reg);
			RegPool::freeRegister((yyvsp[-2]).regList);
			RegPool::freeRegister((yyvsp[0]).regList);
		}
#line 2295 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 825 "parser.ypp" /* yacc.c:1646  */
    {
			if(checkBinOpType((yyvsp[-2]).type, (yyvsp[0]).type) == false){
				errorMismatch(yylineno);
				YYERROR;
			}
			(yyval).type = setType((yyvsp[-2]).type, (yyvsp[0]).type);
			addDivByZeroCheck((yyvsp[0]).reg);
			string reg = (yyvsp[-2]).reg;
			(yyval).reg = reg;
			emit("divu " + reg + ", " + (yyvsp[-2]).reg + ", " + (yyvsp[0]).reg);
			if((yyval).type == "BYTE"){
				emit("and " + reg + ", " + reg + ", 255");
			}
			//RegPool::freeRegister($1.reg);
			RegPool::freeRegister((yyvsp[0]).reg);
			RegPool::freeRegister((yyvsp[-2]).regList);
			RegPool::freeRegister((yyvsp[0]).regList);
		}
#line 2318 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 844 "parser.ypp" /* yacc.c:1646  */
    {
			CHECK_VAR_DECL((yyvsp[0]).name);
			(yyval).type = scopeManager.getVarType((yyvsp[0]).name);
			(yyval).reg = RegPool::getRegister();
			int offset = scopeManager.getVarOffset((yyvsp[0]).name);
			loadVariableValue((yyvsp[0]).name, (yyval).reg, offset);
			(yyval).expType = string("ID");
		}
#line 2331 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 854 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval) = (yyvsp[0]);
			(yyval).expType = string("CALL");
			(yyval).reg = RegPool::getRegister();
			emit("move " + (yyval).reg + ", $v0 # store return value of: " + (yyvsp[0]).name);
		}
#line 2342 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 861 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval).type = string("INT");
			(yyval).reg = RegPool::getRegister();
			writeToReg((yyval).reg, (yyvsp[0]).val);
		}
#line 2352 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 867 "parser.ypp" /* yacc.c:1646  */
    { 
			if((yyvsp[-1]).val > 255 || (yyvsp[-1]).val < 0){
				errorByteTooLarge(yylineno, (yyvsp[-1]).lexeme);
				YYERROR;
			}
			(yyval).type = string("BYTE");
			(yyval).reg = RegPool::getRegister();
			writeToReg((yyval).reg, (yyvsp[-1]).val);
		}
#line 2366 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 878 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval).label = emitStringData((yyvsp[0]).lexeme);
			(yyval).reg = RegPool::getRegister();
			emit("la " + (yyval).reg + ", " + (yyval).label);
		}
#line 2376 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 888 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval).reg = RegPool::getRegister();
			writeToReg((yyval).reg, 1);
			(yyval).trueList = makelist(emit("j "));
			(yyval).falseList = newList();
			(yyval).type = string("BOOL");
			(yyval).expType = string("BOOLCONST");
		}
#line 2389 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 898 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval).reg = RegPool::getRegister();
			writeToReg((yyval).reg, 0);
			(yyval).trueList = newList();
			(yyval).falseList = makelist(emit("j "));
			(yyval).type = string("BOOL");
			(yyval).expType = string("BOOLCONST");
		}
#line 2402 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 908 "parser.ypp" /* yacc.c:1646  */
    {
			emit("xor " + (yyvsp[0]).reg + ", " + (yyvsp[0]).reg + ", 1");
			
			if((yyvsp[0]).type != "BOOL"){
				errorMismatch(yylineno);
				YYERROR;
			}
			if((yyvsp[0]).expType == "ID" || (yyvsp[0]).expType == "CALL"){
				
				int true_location = emitTrueCheck((yyvsp[0]).reg);
				int false_location = emit("j ");
				(yyvsp[0]).trueList = makelist(false_location);
				(yyvsp[0]).falseList = makelist(true_location);
			}
			
			(yyval).type = string("BOOL");
			//if($2.expType != "ID" && $2.expType != "CALL") $$.expType = $2.expType;
			(yyval).expType = "BOOLEXP";
			(yyval).trueList = (yyvsp[0]).falseList;
			(yyval).falseList = (yyvsp[0]).trueList;
			(yyval).reg = (yyvsp[0]).reg;
			(yyval).regList = (yyvsp[0]).regList;
			(yyval).boolRegs.push_back((yyvsp[0]).reg);
			(yyval).op = "not";
			
		}
#line 2433 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 936 "parser.ypp" /* yacc.c:1646  */
    {
			if((yyvsp[-1]).expType == "ID" || (yyvsp[-1]).expType == "CALL"){
				int true_location = emitTrueCheck((yyvsp[-1]).reg);
				int false_location = emit("j ");
				(yyvsp[-1]).trueList = makelist(true_location);
				(yyvsp[-1]).falseList = makelist(false_location);
			}
		}
#line 2446 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 945 "parser.ypp" /* yacc.c:1646  */
    {
			
			if((yyvsp[-4]).type != "BOOL" || (yyvsp[0]).type != "BOOL"){
				errorMismatch(yylineno);
				YYERROR;
			}
			
			if((yyvsp[0]).expType == "ID" || (yyvsp[0]).expType == "CALL"){
				int true_location = emitTrueCheck((yyvsp[0]).reg);
				int false_location = emit("j ");
				(yyvsp[0]).trueList = makelist(true_location);
				(yyvsp[0]).falseList = makelist(false_location);
			}
			(yyval).type = string("BOOL");
			(yyval).expType = "BOOLEXP";
			if((yyvsp[-4]).expType == "RELOP" || (yyvsp[0]).expType == "RELOP"){
				(yyval).expType = "RELOP";
			}
			bpatch((yyvsp[-4]).trueList, (yyvsp[-1]).quad);
			(yyval).trueList = (yyvsp[0]).trueList;
			(yyval).falseList = merge((yyvsp[-4]).falseList, (yyvsp[0]).falseList);
			(yyval).regList = merge((yyvsp[-4]).regList, (yyvsp[0]).regList);
			(yyval).boolRegs.push_back((yyvsp[-4]).reg);
			(yyval).boolRegs.push_back((yyvsp[0]).reg);
			(yyval).op = "and";
		}
#line 2477 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 973 "parser.ypp" /* yacc.c:1646  */
    {
			if((yyvsp[-1]).expType == "ID" || (yyvsp[-1]).expType == "CALL"){
				int true_location = emitTrueCheck((yyvsp[-1]).reg);
				int false_location = emit("j ");
				(yyvsp[-1]).trueList = makelist(true_location);
				(yyvsp[-1]).falseList = makelist(false_location);
			}
		}
#line 2490 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 982 "parser.ypp" /* yacc.c:1646  */
    {
			if((yyvsp[-4]).type != "BOOL" || (yyvsp[0]).type != "BOOL"){
				errorMismatch(yylineno);
				YYERROR;
			}
			
			if((yyvsp[0]).expType == "ID" || (yyvsp[0]).expType == "CALL"){
				int true_location = emitTrueCheck((yyvsp[0]).reg);
				int false_location = emit("j ");
				(yyvsp[0]).trueList = makelist(true_location);
				(yyvsp[0]).falseList = makelist(false_location);
			}
			(yyval).type = string("BOOL");
			(yyval).expType = "BOOLEXP";
			if((yyvsp[-4]).expType == "RELOP" || (yyvsp[0]).expType == "RELOP"){
				(yyval).expType = "RELOP";
			}
			bpatch((yyvsp[-4]).falseList, (yyvsp[-1]).quad);
			(yyval).trueList = merge((yyvsp[-4]).trueList, (yyvsp[0]).trueList);
			(yyval).falseList = (yyvsp[0]).falseList;
			(yyval).regList = merge((yyvsp[-4]).regList, (yyvsp[0]).regList);
			(yyval).boolRegs.push_back((yyvsp[-4]).reg);
			(yyval).boolRegs.push_back((yyvsp[0]).reg);
			(yyval).op = "or";
		}
#line 2520 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 1010 "parser.ypp" /* yacc.c:1646  */
    {
			if(!isNumber((yyvsp[-2]).type) || !isNumber((yyvsp[0]).type)){
				errorMismatch(yylineno);
				YYERROR;
			}
			(yyval).type = string("BOOL");
			(yyval).expType = string("RELOP");
			int true_location = emitCondBranch((yyvsp[-2]).reg, (yyvsp[0]).reg, (yyvsp[-1]).lexeme);
			int false_location = emit("j ");
			(yyval).trueList = makelist(true_location);
			(yyval).falseList = makelist(false_location);
			(yyval).regList.push_back((yyvsp[-2]).reg);
			(yyval).regList.push_back((yyvsp[0]).reg);
		}
#line 2539 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 1026 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval).quad = getNext();
	}
#line 2547 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1030 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval).nextList = makelist(emit("j "));
	}
#line 2555 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1034 "parser.ypp" /* yacc.c:1646  */
    {
		emit("# break statement");
		(yyval).nextList = makelist(emit("j "));
	}
#line 2564 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2568 "parser.tab.cpp" /* yacc.c:1646  */
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
#line 1039 "parser.ypp" /* yacc.c:1906  */



bool checkAssignmentType(string lval, string rval){
	if(lval != rval){
		if(lval == "INT" && rval == "BYTE") return true;
		return false;
	}
	return true;
}

bool checkBinOpType(string type1, string type2){
	if(isNumber(type1) && isNumber(type2)) return true;
	return false;
}

bool isNumber(string type){
	return type == "INT" || type == "BYTE";
}

string setType(string t1, string t2){
	if(t1 == "INT" || t2 == "INT") return "INT";
	return "BYTE";
}


void yyerror (char const *s) {
   errorSyn(yylineno);
   exit(1);
}

 
int main(){
	RegPool::init();
	addDivByZeroCode();
	addPrintCode();
	scopeManager = ScopeManager();
	functions = FunctionTable();
	int retval = 0;
	try{
		yyparse();
	} catch(exception& e){
		cout << "Caught exception: " << e.what() << endl;
		emitCode();
	}
	RegPool::release();
	return retval;
}
