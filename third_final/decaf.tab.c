/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTCONST = 258,
     BOOLCONST = 259,
     STRINGCONST = 260,
     IDENTIFIER = 261,
     KINT = 262,
     KBOOL = 263,
     KSTRING = 264,
     KVOID = 265,
     KCLASS = 266,
     KSTATIC = 267,
     KEXTENDS = 268,
     KFOR = 269,
     KWHILE = 270,
     KIF = 271,
     KELSE = 272,
     KRETURN = 273,
     KBREAK = 274,
     KPRINT = 275,
     KTHIS = 276,
     KREADINTEGER = 277,
     KREADLINE = 278,
     KNEW = 279,
     KINSTANCEOF = 280,
     KNULL = 281,
     OLB = 282,
     ORB = 283,
     OADD = 284,
     OSUB = 285,
     OMUL = 286,
     ODIV = 287,
     OIDIV = 288,
     OLT = 289,
     OLE = 290,
     OGT = 291,
     OGE = 292,
     OEQU = 293,
     ONE = 294,
     OAND = 295,
     OOR = 296,
     ONOT = 297,
     OASSIGN = 298,
     PLBB = 299,
     PRBB = 300,
     PCOMMA = 301,
     PLBBB = 302,
     PRBBB = 303,
     PSEP = 304,
     PPOINT = 305,
     LOWER_THAN_KELSE = 306
   };
#endif
/* Tokens.  */
#define INTCONST 258
#define BOOLCONST 259
#define STRINGCONST 260
#define IDENTIFIER 261
#define KINT 262
#define KBOOL 263
#define KSTRING 264
#define KVOID 265
#define KCLASS 266
#define KSTATIC 267
#define KEXTENDS 268
#define KFOR 269
#define KWHILE 270
#define KIF 271
#define KELSE 272
#define KRETURN 273
#define KBREAK 274
#define KPRINT 275
#define KTHIS 276
#define KREADINTEGER 277
#define KREADLINE 278
#define KNEW 279
#define KINSTANCEOF 280
#define KNULL 281
#define OLB 282
#define ORB 283
#define OADD 284
#define OSUB 285
#define OMUL 286
#define ODIV 287
#define OIDIV 288
#define OLT 289
#define OLE 290
#define OGT 291
#define OGE 292
#define OEQU 293
#define ONE 294
#define OAND 295
#define OOR 296
#define ONOT 297
#define OASSIGN 298
#define PLBB 299
#define PRBB 300
#define PCOMMA 301
#define PLBBB 302
#define PRBBB 303
#define PSEP 304
#define PPOINT 305
#define LOWER_THAN_KELSE 306




/* Copy the first part of user declarations.  */
#line 1 "decaf.y"

    #include <stdio.h>
    #include "lex.yy.c"
    #include "tree.h"
    void yyerror (char const *);
    extern FILE* yyin;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 9 "decaf.y"
{
	struct Ast* a;
}
/* Line 193 of yacc.c.  */
#line 210 "decaf.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 223 "decaf.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   486

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  186

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    13,    16,    18,    20,
      22,    24,    27,    31,    34,    35,    39,    40,    48,    55,
      63,    69,    72,    73,    75,    77,    81,    84,    85,    87,
      90,    92,    94,    96,    99,   102,   105,   107,   111,   113,
     114,   118,   120,   125,   132,   137,   140,   141,   145,   146,
     156,   162,   170,   176,   178,   181,   183,   189,   191,   193,
     195,   197,   199,   203,   207,   211,   215,   219,   223,   226,
     230,   234,   238,   242,   246,   250,   254,   258,   261,   265,
     269,   274,   280,   287,   293,   295,   297,   299
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    61,    54,    -1,    61,    54,    -1,    -1,
      56,    49,    -1,    57,     6,    -1,     7,    -1,     8,    -1,
       9,    -1,    10,    -1,    11,     6,    -1,    57,    44,    45,
      -1,    56,    59,    -1,    -1,    46,    56,    59,    -1,    -1,
      12,    57,     6,    27,    58,    28,    64,    -1,    57,     6,
      27,    58,    28,    64,    -1,    11,     6,    13,     6,    47,
      62,    48,    -1,    11,     6,    47,    62,    48,    -1,    63,
      62,    -1,    -1,    55,    -1,    60,    -1,    47,    65,    48,
      -1,    66,    65,    -1,    -1,    55,    -1,    67,    49,    -1,
      74,    -1,    73,    -1,    72,    -1,    76,    49,    -1,    75,
      49,    -1,    77,    49,    -1,    64,    -1,    68,    43,    79,
      -1,    69,    -1,    -1,    79,    50,     6,    -1,     6,    -1,
      79,    44,    79,    45,    -1,    79,    50,     6,    27,    70,
      28,    -1,     6,    27,    70,    28,    -1,    79,    71,    -1,
      -1,    46,    79,    71,    -1,    -1,    14,    27,    67,    49,
      78,    49,    67,    28,    66,    -1,    15,    27,    78,    28,
      66,    -1,    16,    27,    78,    28,    66,    17,    66,    -1,
      16,    27,    78,    28,    66,    -1,    18,    -1,    18,    79,
      -1,    19,    -1,    20,    27,    79,    71,    28,    -1,    79,
      -1,    80,    -1,    68,    -1,    21,    -1,    69,    -1,    27,
      79,    28,    -1,    79,    29,    79,    -1,    79,    30,    79,
      -1,    79,    31,    79,    -1,    79,    32,    79,    -1,    79,
      33,    79,    -1,    30,    79,    -1,    79,    34,    79,    -1,
      79,    35,    79,    -1,    79,    36,    79,    -1,    79,    37,
      79,    -1,    79,    38,    79,    -1,    79,    39,    79,    -1,
      79,    40,    79,    -1,    79,    41,    79,    -1,    42,    79,
      -1,    22,    27,    28,    -1,    23,    27,    28,    -1,    24,
       6,    27,    28,    -1,    24,    57,    44,    79,    45,    -1,
      25,    27,    79,    46,     6,    28,    -1,    27,    11,     6,
      28,    79,    -1,     3,    -1,     4,    -1,     5,    -1,    26,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    36,    36,    39,    40,    43,    46,    49,    50,    51,
      52,    53,    54,    57,    58,    61,    62,    65,    66,    69,
      70,    73,    74,    77,    78,    81,    84,    85,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    99,   100,   101,
     104,   105,   106,   110,   111,   113,   114,   117,   118,   121,
     124,   127,   128,   131,   132,   135,   138,   141,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   172,   173,   174,   175
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTCONST", "BOOLCONST", "STRINGCONST",
  "IDENTIFIER", "KINT", "KBOOL", "KSTRING", "KVOID", "KCLASS", "KSTATIC",
  "KEXTENDS", "KFOR", "KWHILE", "KIF", "KELSE", "KRETURN", "KBREAK",
  "KPRINT", "KTHIS", "KREADINTEGER", "KREADLINE", "KNEW", "KINSTANCEOF",
  "KNULL", "OLB", "ORB", "OADD", "OSUB", "OMUL", "ODIV", "OIDIV", "OLT",
  "OLE", "OGT", "OGE", "OEQU", "ONE", "OAND", "OOR", "ONOT", "OASSIGN",
  "PLBB", "PRBB", "PCOMMA", "PLBBB", "PRBBB", "PSEP", "PPOINT",
  "LOWER_THAN_KELSE", "$accept", "Program", "ClassDefList", "VariableDef",
  "Variable", "Type", "Formals", "VariableList", "FunctionDef", "ClassDef",
  "FieldList", "Field", "StmtBlock", "StmtList", "Stmt", "SimpleStmt",
  "LValue", "Call", "Actuals", "ExprList", "ForStmt", "WhileStmt",
  "IfStmt", "ReturnStmt", "BreakStmt", "PrintStmt", "BoolExpr", "Expr",
  "Constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    56,    57,    57,    57,
      57,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    67,
      68,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      73,    74,    74,    75,    75,    76,    77,    78,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     2,     1,     1,     1,
       1,     2,     3,     2,     0,     3,     0,     7,     6,     7,
       5,     2,     0,     1,     1,     3,     2,     0,     1,     2,
       1,     1,     1,     2,     2,     2,     1,     3,     1,     0,
       3,     1,     4,     6,     4,     2,     0,     3,     0,     9,
       5,     7,     5,     1,     2,     1,     5,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       4,     5,     6,     5,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     2,     4,     0,    22,
       3,     0,     7,     8,     9,    10,     0,     0,    23,     0,
       0,    24,     0,    22,    22,    11,     0,     5,     6,     0,
      20,    21,     0,     0,    14,    12,    19,    14,    16,     0,
       0,     0,     0,    13,     6,     0,     0,    16,    27,    18,
      17,    15,    84,    85,    86,    41,     0,     0,     0,    53,
      55,     0,    60,     0,     0,     0,     0,    87,     0,     0,
       0,    28,    36,     0,    27,     0,    59,    61,    32,    31,
      30,     0,     0,     0,     0,    58,    46,    39,     0,     0,
      59,    61,    54,     0,     0,     0,     0,     0,     0,     0,
       0,    68,    77,    25,    26,    29,     0,    34,    33,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     0,    57,
       0,    48,    78,    79,     0,     0,     0,     0,    62,    37,
      63,    64,    65,    66,    67,    69,    70,    71,    72,    73,
      74,    75,    76,     0,    40,    44,     0,    45,     0,    39,
      39,     0,    80,     0,     0,     0,    42,    46,    48,     0,
      50,    52,    56,    81,     0,    83,     0,    47,    39,    39,
      82,    43,     0,    51,    39,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    71,    19,    39,    40,    43,    21,     7,
      22,    23,    72,    73,    74,    75,    90,    91,   125,   157,
      78,    79,    80,    81,    82,    83,   128,    84,    85
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -147
static const yytype_int16 yypact[] =
{
      -3,    21,    10,    -3,     4,  -147,  -147,    -3,    31,    79,
    -147,     5,  -147,  -147,  -147,  -147,    40,   166,  -147,     6,
      -1,  -147,    16,    79,    79,  -147,     0,  -147,    38,    23,
    -147,  -147,    18,    42,   166,  -147,  -147,   166,    24,     1,
      65,    66,   166,  -147,  -147,    48,    48,    24,   136,  -147,
    -147,  -147,  -147,  -147,  -147,    70,    72,    89,    91,   267,
    -147,    93,  -147,    95,    96,   161,    97,  -147,   239,   267,
     267,  -147,  -147,    50,   136,    76,    84,   -17,  -147,  -147,
    -147,    80,    85,    86,   392,  -147,   267,   267,   267,   267,
    -147,  -147,   392,   267,   109,   120,   122,   121,   267,   147,
     282,   -35,   -35,  -147,  -147,  -147,   267,  -147,  -147,  -147,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   158,   151,   304,   131,   153,   392,
     154,   304,  -147,  -147,   156,   211,   326,   167,  -147,   392,
     196,   196,   -35,   -35,   -35,    -8,    -8,    -8,    -8,   436,
     436,    71,   414,   348,   169,  -147,   267,  -147,   267,   183,
     183,   172,  -147,   370,   205,   267,  -147,   267,   304,   163,
    -147,   201,  -147,  -147,   191,  -147,   192,  -147,   267,   183,
    -147,  -147,   193,  -147,   183,  -147
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,   215,    39,    19,    -5,   186,   177,  -147,   226,
      11,  -147,    12,   157,  -146,   -86,   -48,   -46,    81,  -128,
    -147,  -147,  -147,  -147,  -147,  -147,   -73,   -39,  -147
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -40
static const yytype_int16 yytable[] =
{
      76,   127,    77,   161,    20,    28,    33,    44,     1,   123,
       5,   -38,    26,   170,   171,   124,   130,     8,    20,    20,
      92,   110,   111,   112,   113,   114,    76,     4,    77,   100,
     101,   102,   -38,   183,    31,    32,   123,    11,   185,    76,
     177,    77,   124,    29,    29,    29,    25,   126,    18,   129,
     129,     9,    24,    38,   131,    27,    38,    49,    50,   136,
      97,    47,    18,    18,    30,    34,    36,   139,    35,    37,
      42,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   169,    12,    13,    14,    15,
      16,    17,   182,    45,    46,    48,   163,    86,   103,    87,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    76,    76,    77,    77,   123,    88,   168,    89,   129,
      93,   124,    94,    95,    98,   105,   175,   106,   126,   107,
      76,    76,    77,    77,   108,   109,    76,   132,    77,    52,
      53,    54,    55,    12,    13,    14,    15,    16,   133,   134,
      56,    57,    58,   137,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   154,   135,    69,    96,    12,    13,
      14,    15,    16,    12,    13,    14,    15,    16,    70,   155,
     158,   159,   160,    48,   162,   -39,    52,    53,    54,    55,
      12,    13,    14,    15,    16,   165,   167,    56,    57,    58,
     172,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   174,   178,    69,    52,    53,    54,    55,   179,   180,
     181,   184,    10,    41,    51,    70,     3,   112,   113,   114,
      48,   104,    62,    63,    64,    65,    66,    67,    68,     0,
     123,    69,    52,    53,    54,    55,   124,     0,   176,     0,
      99,     0,     0,    70,     0,     0,    35,     0,     0,     0,
      62,    63,    64,    65,    66,    67,    68,     0,     0,    69,
      52,    53,    54,    55,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,     0,     0,     0,    62,    63,
      64,    65,    66,    67,    68,     0,     0,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
     138,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,     0,   123,     0,     0,     0,
       0,     0,   124,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,     0,   123,     0,
     156,     0,     0,     0,   124,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     0,     0,
     123,     0,   164,     0,     0,     0,   124,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,     0,   123,   166,     0,     0,     0,     0,   124,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     0,     0,   123,   173,     0,     0,     0,     0,
     124,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,     0,   123,     0,     0,     0,
       0,     0,   124,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,     0,     0,     0,   123,     0,
       0,     0,     0,     0,   124,   110,   111,   112,   113,   114,
     115,   116,   117,   118,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,     0,     0,   124
};

static const yytype_int16 yycheck[] =
{
      48,    87,    48,   131,     9,     6,     6,     6,    11,    44,
       0,    28,    17,   159,   160,    50,    89,    13,    23,    24,
      59,    29,    30,    31,    32,    33,    74,     6,    74,    68,
      69,    70,    49,   179,    23,    24,    44,     6,   184,    87,
     168,    87,    50,    44,    44,    44,     6,    86,     9,    88,
      89,    47,    47,    34,    93,    49,    37,    45,    46,    98,
      65,    42,    23,    24,    48,    27,    48,   106,    45,    27,
      46,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   158,     7,     8,     9,    10,
      11,    12,   178,    28,    28,    47,   135,    27,    48,    27,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,   159,   160,   159,   160,    44,    27,   156,    27,   158,
      27,    50,    27,    27,    27,    49,   165,    43,   167,    49,
     178,   179,   178,   179,    49,    49,   184,    28,   184,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    28,    27,
      14,    15,    16,     6,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     6,    44,    30,     6,     7,     8,
       9,    10,    11,     7,     8,     9,    10,    11,    42,    28,
      49,    28,    28,    47,    28,    49,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    28,    27,    14,    15,    16,
      28,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     6,    49,    30,     3,     4,     5,     6,    17,    28,
      28,    28,     7,    37,    47,    42,     0,    31,    32,    33,
      47,    74,    21,    22,    23,    24,    25,    26,    27,    -1,
      44,    30,     3,     4,     5,     6,    50,    -1,   167,    -1,
      11,    -1,    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    50,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    44,    -1,
      46,    -1,    -1,    -1,    50,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      44,    -1,    46,    -1,    -1,    -1,    50,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      50,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    50,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    50,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    53,    61,     6,     0,    54,    61,    13,    47,
      54,     6,     7,     8,     9,    10,    11,    12,    55,    56,
      57,    60,    62,    63,    47,     6,    57,    49,     6,    44,
      48,    62,    62,     6,    27,    45,    48,    27,    56,    57,
      58,    58,    46,    59,     6,    28,    28,    56,    47,    64,
      64,    59,     3,     4,     5,     6,    14,    15,    16,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    30,
      42,    55,    64,    65,    66,    67,    68,    69,    72,    73,
      74,    75,    76,    77,    79,    80,    27,    27,    27,    27,
      68,    69,    79,    27,    27,    27,     6,    57,    27,    11,
      79,    79,    79,    48,    65,    49,    43,    49,    49,    49,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    44,    50,    70,    79,    67,    78,    79,
      78,    79,    28,    28,    27,    44,    79,     6,    28,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,     6,    28,    46,    71,    49,    28,
      28,    71,    28,    79,    46,    28,    45,    27,    79,    78,
      66,    66,    28,    45,     6,    79,    70,    71,    49,    17,
      28,    28,    67,    66,    28,    66
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 36 "decaf.y"
    {(yyval.a)=new_ast("Program", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a)); Symstack.push(&symglobal); Creat_Symtable((yyval.a), 0); print_symtable(&symglobal, 0);;}
    break;

  case 3:
#line 39 "decaf.y"
    {(yyval.a)=new_ast("ClassDefList", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 4:
#line 40 "decaf.y"
    {(yyval.a)=new_ast("ExtClassDefList", 0, -1);;}
    break;

  case 5:
#line 43 "decaf.y"
    {(yyval.a)=new_ast("VariableDef", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 6:
#line 46 "decaf.y"
    {(yyval.a)=new_ast("Variable", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 7:
#line 49 "decaf.y"
    {(yyval.a)=new_ast("Type", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 8:
#line 50 "decaf.y"
    {(yyval.a)=new_ast("Type", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 9:
#line 51 "decaf.y"
    {(yyval.a)=new_ast("Type", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 10:
#line 52 "decaf.y"
    {(yyval.a)=new_ast("Type", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 11:
#line 53 "decaf.y"
    {(yyval.a)=new_ast("Type", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 12:
#line 54 "decaf.y"
    {(yyval.a)=new_ast("Type", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 13:
#line 57 "decaf.y"
    {(yyval.a)=new_ast("Formals", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 14:
#line 58 "decaf.y"
    {(yyval.a)=new_ast("ExtFormals", 0, -1);;}
    break;

  case 15:
#line 61 "decaf.y"
    {(yyval.a)=new_ast("VariableList", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 16:
#line 62 "decaf.y"
    {(yyval.a)=new_ast("ExtVariableList", 0, -1);;}
    break;

  case 17:
#line 65 "decaf.y"
    {(yyval.a)=new_ast("FunctionDef", 7, (yyvsp[(1) - (7)].a), (yyvsp[(2) - (7)].a), (yyvsp[(3) - (7)].a), (yyvsp[(4) - (7)].a), (yyvsp[(5) - (7)].a), (yyvsp[(6) - (7)].a), (yyvsp[(7) - (7)].a));;}
    break;

  case 18:
#line 66 "decaf.y"
    {(yyval.a)=new_ast("FunctionDef", 6, (yyvsp[(1) - (6)].a), (yyvsp[(2) - (6)].a), (yyvsp[(3) - (6)].a), (yyvsp[(4) - (6)].a), (yyvsp[(5) - (6)].a), (yyvsp[(6) - (6)].a));;}
    break;

  case 19:
#line 69 "decaf.y"
    {(yyval.a)=new_ast("ClassDef", 7, (yyvsp[(1) - (7)].a), (yyvsp[(2) - (7)].a), (yyvsp[(3) - (7)].a), (yyvsp[(4) - (7)].a), (yyvsp[(5) - (7)].a), (yyvsp[(6) - (7)].a), (yyvsp[(7) - (7)].a));;}
    break;

  case 20:
#line 70 "decaf.y"
    {(yyval.a)=new_ast("ClassDef", 5, (yyvsp[(1) - (5)].a), (yyvsp[(2) - (5)].a), (yyvsp[(3) - (5)].a), (yyvsp[(4) - (5)].a), (yyvsp[(5) - (5)].a));;}
    break;

  case 21:
#line 73 "decaf.y"
    {(yyval.a)=new_ast("FieldList", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 22:
#line 74 "decaf.y"
    {(yyval.a)=new_ast("ExtFieldList", 0, -1);;}
    break;

  case 23:
#line 77 "decaf.y"
    {(yyval.a)=new_ast("Field", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 24:
#line 78 "decaf.y"
    {(yyval.a)=new_ast("Field", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 25:
#line 81 "decaf.y"
    {(yyval.a)=new_ast("StmtBlock", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 26:
#line 84 "decaf.y"
    {(yyval.a)=new_ast("StmtList", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 27:
#line 85 "decaf.y"
    {(yyval.a)=new_ast("ExtStmtList", 0, -1);;}
    break;

  case 28:
#line 88 "decaf.y"
    {(yyval.a)=new_ast("Stmt", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 29:
#line 89 "decaf.y"
    {(yyval.a)=new_ast("Stmt", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 30:
#line 90 "decaf.y"
    {(yyval.a)=new_ast("Stmt", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 31:
#line 91 "decaf.y"
    {(yyval.a)=new_ast("Stmt", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 32:
#line 92 "decaf.y"
    {(yyval.a)=new_ast("Stmt", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 33:
#line 93 "decaf.y"
    {(yyval.a)=new_ast("Stmt", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 34:
#line 94 "decaf.y"
    {(yyval.a)=new_ast("Stmt", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 35:
#line 95 "decaf.y"
    {(yyval.a)=new_ast("Stmt", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 36:
#line 96 "decaf.y"
    {(yyval.a)=new_ast("Stmt", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 37:
#line 99 "decaf.y"
    {(yyval.a)=new_ast("SimpleStmt", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 38:
#line 100 "decaf.y"
    {(yyval.a)=new_ast("SimpleStmt", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 39:
#line 101 "decaf.y"
    {(yyval.a)=new_ast("ExtSimpleStmt", 0, -1);;}
    break;

  case 40:
#line 104 "decaf.y"
    {(yyval.a)=new_ast("LValue", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 41:
#line 105 "decaf.y"
    {(yyval.a)=new_ast("LValue", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 42:
#line 106 "decaf.y"
    {(yyval.a)=new_ast("LValue", 4, (yyvsp[(1) - (4)].a), (yyvsp[(2) - (4)].a), (yyvsp[(3) - (4)].a), (yyvsp[(4) - (4)].a));;}
    break;

  case 43:
#line 110 "decaf.y"
    {(yyval.a)=new_ast("Call", 6, (yyvsp[(1) - (6)].a), (yyvsp[(2) - (6)].a), (yyvsp[(3) - (6)].a), (yyvsp[(4) - (6)].a), (yyvsp[(5) - (6)].a), (yyvsp[(6) - (6)].a));;}
    break;

  case 44:
#line 111 "decaf.y"
    {(yyval.a)=new_ast("Call", 4, (yyvsp[(1) - (4)].a), (yyvsp[(2) - (4)].a), (yyvsp[(3) - (4)].a), (yyvsp[(4) - (4)].a));;}
    break;

  case 45:
#line 113 "decaf.y"
    {(yyval.a)=new_ast("Actuals", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 46:
#line 114 "decaf.y"
    {(yyval.a)=new_ast("ExtActuals", 0, -1);;}
    break;

  case 47:
#line 117 "decaf.y"
    {(yyval.a)=new_ast("ExprList", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 48:
#line 118 "decaf.y"
    {(yyval.a)=new_ast("ExtExprList", 0, -1);;}
    break;

  case 49:
#line 121 "decaf.y"
    {(yyval.a)=new_ast("ForStmt", 9, (yyvsp[(1) - (9)].a), (yyvsp[(2) - (9)].a), (yyvsp[(3) - (9)].a), (yyvsp[(4) - (9)].a), (yyvsp[(5) - (9)].a), (yyvsp[(6) - (9)].a), (yyvsp[(7) - (9)].a), (yyvsp[(8) - (9)].a), (yyvsp[(9) - (9)].a));;}
    break;

  case 50:
#line 124 "decaf.y"
    {(yyval.a)=new_ast("WhileStmt", 5, (yyvsp[(1) - (5)].a), (yyvsp[(2) - (5)].a), (yyvsp[(3) - (5)].a), (yyvsp[(4) - (5)].a), (yyvsp[(5) - (5)].a));;}
    break;

  case 51:
#line 127 "decaf.y"
    {(yyval.a)=new_ast("IfStmt", 7, (yyvsp[(1) - (7)].a), (yyvsp[(2) - (7)].a), (yyvsp[(3) - (7)].a), (yyvsp[(4) - (7)].a), (yyvsp[(5) - (7)].a), (yyvsp[(6) - (7)].a), (yyvsp[(7) - (7)].a));;}
    break;

  case 52:
#line 128 "decaf.y"
    {(yyval.a)=new_ast("IfStmt", 5, (yyvsp[(1) - (5)].a), (yyvsp[(2) - (5)].a), (yyvsp[(3) - (5)].a), (yyvsp[(4) - (5)].a), (yyvsp[(5) - (5)].a));;}
    break;

  case 53:
#line 131 "decaf.y"
    {(yyval.a)=new_ast("ReturnStmt", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 54:
#line 132 "decaf.y"
    {(yyval.a)=new_ast("ReturnStmt", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 55:
#line 135 "decaf.y"
    {(yyval.a)=new_ast("BreakStmt", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 56:
#line 138 "decaf.y"
    {(yyval.a)=new_ast("PrintStmt", 5, (yyvsp[(1) - (5)].a), (yyvsp[(2) - (5)].a), (yyvsp[(3) - (5)].a), (yyvsp[(4) - (5)].a), (yyvsp[(5) - (5)].a));;}
    break;

  case 57:
#line 141 "decaf.y"
    {(yyval.a)=new_ast("BoolExpr", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 58:
#line 144 "decaf.y"
    {(yyval.a)=new_ast("Expr", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 59:
#line 145 "decaf.y"
    {(yyval.a)=new_ast("Expr", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 60:
#line 146 "decaf.y"
    {(yyval.a)=new_ast("Expr", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 61:
#line 147 "decaf.y"
    {(yyval.a)=new_ast("Expr", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 62:
#line 148 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 63:
#line 149 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 64:
#line 150 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 65:
#line 151 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 66:
#line 152 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 67:
#line 153 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 68:
#line 154 "decaf.y"
    {(yyval.a)=new_ast("Expr", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 69:
#line 155 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 70:
#line 156 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 71:
#line 157 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 72:
#line 158 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 73:
#line 159 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 74:
#line 160 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 75:
#line 161 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 76:
#line 162 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 77:
#line 163 "decaf.y"
    {(yyval.a)=new_ast("Expr", 2, (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));;}
    break;

  case 78:
#line 164 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 79:
#line 165 "decaf.y"
    {(yyval.a)=new_ast("Expr", 3, (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), (yyvsp[(3) - (3)].a));;}
    break;

  case 80:
#line 166 "decaf.y"
    {(yyval.a)=new_ast("Expr", 4, (yyvsp[(1) - (4)].a), (yyvsp[(2) - (4)].a), (yyvsp[(3) - (4)].a), (yyvsp[(4) - (4)].a));;}
    break;

  case 81:
#line 167 "decaf.y"
    {(yyval.a)=new_ast("Expr", 5, (yyvsp[(1) - (5)].a), (yyvsp[(2) - (5)].a), (yyvsp[(3) - (5)].a), (yyvsp[(4) - (5)].a), (yyvsp[(5) - (5)].a));;}
    break;

  case 82:
#line 168 "decaf.y"
    {(yyval.a)=new_ast("Expr", 6, (yyvsp[(1) - (6)].a), (yyvsp[(2) - (6)].a), (yyvsp[(3) - (6)].a), (yyvsp[(4) - (6)].a), (yyvsp[(5) - (6)].a), (yyvsp[(6) - (6)].a));;}
    break;

  case 83:
#line 169 "decaf.y"
    {(yyval.a)=new_ast("Expr", 5, (yyvsp[(1) - (5)].a), (yyvsp[(2) - (5)].a), (yyvsp[(3) - (5)].a), (yyvsp[(4) - (5)].a), (yyvsp[(5) - (5)].a));;}
    break;

  case 84:
#line 172 "decaf.y"
    {(yyval.a)=new_ast("Constant", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 85:
#line 173 "decaf.y"
    {(yyval.a)=new_ast("Constant", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 86:
#line 174 "decaf.y"
    {(yyval.a)=new_ast("Constant", 1, (yyvsp[(1) - (1)].a));;}
    break;

  case 87:
#line 175 "decaf.y"
    {(yyval.a)=new_ast("Constant", 1, (yyvsp[(1) - (1)].a));;}
    break;


/* Line 1267 of yacc.c.  */
#line 2069 "decaf.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 178 "decaf.y"


int main(int argc, char **argv)
{
	if(argc <= 1)
	{
		return 1;
	}
	FILE* f = fopen(argv[1], "r");
	if(!f)
	{
		perror(argv[1]);
		return 1;
	}
	//yydebug = 1;
	yyrestart(f);
	yyparse();
    return 0;
}

void yyerror(const char *s)
{
    printf("Line %d:%s\n",yylineno,s);
}

