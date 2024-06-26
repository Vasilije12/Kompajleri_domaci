
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "pmf2.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <stdbool.h>

// AST struktura
typedef struct ASTNode {
    int nodetype;
    struct ASTNode *left;
    struct ASTNode *right;
    union {
        int int_value;
        double double_value;
        char* string_value;
        char* ident;
        char* decl;
        int bool_value;
    } value;
} ASTNode;

ASTNode *newNode(int nodetype, ASTNode *left, ASTNode *right);
ASTNode *newIntNode(int int_value);
ASTNode *newDoubleNode(double double_value);
ASTNode *newStringNode(char *string_value);
ASTNode *newIdentNode(char *ident);
ASTNode *newDeclNode(char *decl);
void printAST(ASTNode *node, int level);

void yyerror(const char* s);

// Funkcije za kreiranje čvorova
ASTNode *newNode(int nodetype, ASTNode *left, ASTNode *right) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->nodetype = nodetype;
    node->left = left;
    node->right = right;
    return node;
}

ASTNode *newIntNode(int int_value) {
    ASTNode *node = newNode('I', NULL, NULL);
    node->value.int_value = int_value;
    return node;
}

ASTNode *newDoubleNode(double double_value) {
    ASTNode *node = newNode('D', NULL, NULL);
    node->value.double_value = double_value;
    return node;
}

ASTNode *newStringNode(char *string_value) {
    ASTNode *node = newNode('S', NULL, NULL);
    node->value.string_value = strdup(string_value);
    return node;
}

ASTNode *newIdentNode(char *ident) {
    ASTNode *node = newNode('V', NULL, NULL);
    node->value.ident = strdup(ident);
    return node;
}

ASTNode *newDeclNode(char *decl){
    ASTNode *node = newNode('M',NULL,NULL);
    node->value.decl = strdup(decl);
}

// Funkcija za ispisivanje AST stabla
void printAST(ASTNode *node, int level) {
    if (node == NULL) return;
    int i;
    for ( i = 0; i < level; i++) printf("  ");
    switch (node->nodetype) {
        case 'I': printf("Int: %d\n", node->value.int_value); break;
        case 'D': printf("Double: %f\n", node->value.double_value); break;
        case 'S': printf("String: %s\n", node->value.string_value); break;
        case 'V': printf("Ident: %s\n", node->value.ident); break;
        //case 'i':printf("If\n");break;
        //case 'e':printf("Else:\n");break;
        //case "==": printf("Op:%s\n",node->nodetype); break;
        case ';':break;
        
        case '+': case '-': case '*': case '/': case '%':
        case '<': case '>': case '=': case '!': case '&': case '|':
        
            printf("Op: %c\n", node->nodetype); break;
        default: printf("Kljucna rijec: %c\n", node->nodetype);
    }
    //nekako da se dodaje u neki niz sve sto je na istom nivou i onda da se printa
   
    printAST(node->left, level +1);
    printAST(node->right, level +1);
}


/* Line 189 of yacc.c  */
#line 171 "pmf2.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     THEN = 259,
     ELSE = 260,
     CONTINUE = 261,
     WHILE = 262,
     FOR = 263,
     BREAK = 264,
     INT = 265,
     DOUBLE = 266,
     STRING = 267,
     T_TRUE = 268,
     T_FALSE = 269,
     T_ID = 270,
     T_INT = 271,
     T_DOUBLE = 272,
     T_STRING = 273,
     T_PLUS = 274,
     T_MINUS = 275,
     T_MNOZENJE = 276,
     T_DIJELJENJE = 277,
     T_MOD = 278,
     T_BACKSLASH = 279,
     T_MANJE = 280,
     T_MANJE_JEDNAKO = 281,
     T_VECE = 282,
     T_VECE_JEDNAKO = 283,
     T_DODJELE = 284,
     T_JEDNAKOSTI = 285,
     T_NEJEDNAKOSTI = 286,
     T_AND = 287,
     T_OR = 288,
     T_NOT = 289,
     T_SC = 290,
     T_ZAREZ = 291,
     T_TACKA = 292,
     T_DESNAZ = 293,
     T_LIJEVAZ = 294,
     LET = 295,
     IN = 296,
     END = 297,
     FI = 298,
     DO = 299,
     READ = 300,
     WRITE = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 97 "pmf2.y"

    int int_value;
    double double_value;
    char* string_value;
    char* ident;
    int bool_value;
    ASTNode *node;



/* Line 214 of yacc.c  */
#line 264 "pmf2.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 276 "pmf2.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   385

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    14,    19,    24,    25,    28,    29,
      34,    37,    42,    45,    48,    53,    55,    57,    61,    65,
      69,    73,    80,    87,    90,    91,    97,   103,   107,   111,
     115,   119,   123,   127,   131,   135,   139,   143,   147,   150,
     152,   154,   158,   162,   166,   170,   174,   178,   182,   186,
     190,   194,   198,   201,   203
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    40,    49,    41,    50,    42,    -1,    49,
      10,    15,    35,    -1,    49,    11,    15,    35,    -1,    49,
      12,    15,    35,    -1,    -1,    50,    51,    -1,    -1,    15,
      29,    55,    35,    -1,    55,    35,    -1,    15,    29,    56,
      35,    -1,    56,    35,    -1,    57,    35,    -1,    15,    29,
      57,    35,    -1,    52,    -1,    54,    -1,    45,    15,    35,
      -1,    46,    55,    35,    -1,    46,    56,    35,    -1,    46,
      57,    35,    -1,     3,    55,     4,    50,    53,    43,    -1,
       3,    56,     4,    50,    53,    43,    -1,     5,    50,    -1,
      -1,     7,    55,    44,    50,    42,    -1,     7,    56,    44,
      50,    42,    -1,    55,    19,    55,    -1,    55,    20,    55,
      -1,    55,    21,    55,    -1,    55,    22,    55,    -1,    55,
      23,    55,    -1,    55,    27,    55,    -1,    55,    28,    55,
      -1,    55,    25,    55,    -1,    55,    26,    55,    -1,    55,
      30,    55,    -1,    55,    31,    55,    -1,    34,    55,    -1,
      16,    -1,    15,    -1,    56,    19,    56,    -1,    56,    20,
      56,    -1,    56,    21,    56,    -1,    56,    22,    56,    -1,
      56,    23,    56,    -1,    56,    27,    56,    -1,    56,    28,
      56,    -1,    56,    25,    56,    -1,    56,    26,    56,    -1,
      56,    30,    56,    -1,    56,    31,    56,    -1,    34,    56,
      -1,    17,    -1,    18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   162,   162,   166,   167,   168,   169,   172,   173,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   190,   191,   194,   195,   198,   199,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   233
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "THEN", "ELSE", "CONTINUE",
  "WHILE", "FOR", "BREAK", "INT", "DOUBLE", "STRING", "T_TRUE", "T_FALSE",
  "T_ID", "T_INT", "T_DOUBLE", "T_STRING", "T_PLUS", "T_MINUS",
  "T_MNOZENJE", "T_DIJELJENJE", "T_MOD", "T_BACKSLASH", "T_MANJE",
  "T_MANJE_JEDNAKO", "T_VECE", "T_VECE_JEDNAKO", "T_DODJELE",
  "T_JEDNAKOSTI", "T_NEJEDNAKOSTI", "T_AND", "T_OR", "T_NOT", "T_SC",
  "T_ZAREZ", "T_TACKA", "T_DESNAZ", "T_LIJEVAZ", "LET", "IN", "END", "FI",
  "DO", "READ", "WRITE", "$accept", "program", "dekl", "sekv_komandi",
  "komanda", "if_statement", "else_blok", "while_statement", "int_exp",
  "double_exp", "string_exp", 0
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     4,     0,     2,     0,     4,
       2,     4,     2,     2,     4,     1,     1,     3,     3,     3,
       3,     6,     6,     2,     0,     5,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     0,     0,     1,     0,     0,     0,     8,     0,
       0,     0,     0,     3,     4,     5,     0,     0,    40,    39,
      53,    54,     0,     2,     0,     0,     7,    15,    16,     0,
       0,     0,    40,     0,     0,     0,     0,     0,    38,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    13,     8,
       8,     8,     8,     0,     0,     0,    17,    18,    19,    20,
       0,    27,    28,    29,    30,    31,    34,    35,    32,    33,
      36,    37,     0,    41,    42,    43,    44,    45,    48,    49,
      46,    47,    50,    51,    24,    24,     0,     0,     9,    11,
      14,     8,     0,     0,    25,    26,    23,    21,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    12,    26,    27,   112,    28,    29,    30,
      31
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int16 yypact[] =
{
     -33,   -60,     8,    -8,   -60,    17,    20,    22,   -60,    21,
      35,    36,    66,   -60,   -60,   -60,    38,    38,    28,   -60,
     -60,   -60,    38,   -60,    59,     0,   -60,   -60,   -60,   229,
     246,    43,   -60,   166,   186,   199,   214,     0,   -60,   -60,
      45,   263,   280,    50,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,   -60,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -60,   -60,   -60,
     -60,   -60,   -60,   297,   314,    51,   -60,   -60,   -60,   -60,
       4,     2,     2,   -60,   -60,   -60,   154,   154,   154,   154,
     331,   331,   -12,     6,     6,   -60,   -60,   -60,   357,   357,
     357,   357,   344,   344,    72,    72,    98,   118,   -60,   -60,
     -60,   -60,    48,    49,   -60,   -60,   138,   -60,   -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -60,   -59,   -60,   -60,   -10,   -60,    14,   -16,
     -11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int8 yytable[] =
{
      34,    36,     5,     6,     7,    20,    39,     1,     4,    42,
     104,   105,   106,   107,    43,    32,    19,    20,    21,    32,
      19,    74,    92,    46,    47,    48,    75,    58,    59,    60,
      33,    35,     9,     8,    22,    10,    38,    11,    80,    41,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    73,   116,    32,    19,    20,    13,    37,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    16,
      14,    15,    22,    17,    40,    16,    39,   111,    68,    17,
      76,    18,    19,    20,    21,    79,   110,    18,    19,    20,
      21,   117,   118,     0,    38,   113,     0,     0,     0,     0,
      22,    16,     0,     0,     0,    17,    22,     0,    23,     0,
       0,    24,    25,    18,    19,    20,    21,    24,    25,     0,
       0,    16,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,    22,    18,    19,    20,    21,     0,     0,     0,
     114,    16,     0,    24,    25,    17,     0,     0,     0,     0,
       0,     0,    22,    18,    19,    20,    21,     0,     0,     0,
     115,     0,     0,    24,    25,     0,     0,     0,     0,     0,
      69,     0,    22,    44,    45,    46,    47,    48,     0,    -1,
      -1,    -1,    -1,    24,    25,    44,    45,    46,    47,    48,
      70,    49,    50,    51,    52,     0,    53,    54,     0,     0,
       0,     0,     0,     0,     0,    56,    57,    58,    59,    60,
       0,    61,    62,    63,    64,     0,    65,    66,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,     0,    53,
      54,     0,     0,    56,    57,    58,    59,    60,     0,    61,
      62,    63,    64,    71,    65,    66,     0,     0,    44,    45,
      46,    47,    48,     0,    49,    50,    51,    52,    72,    53,
      54,     0,     0,     0,    55,    56,    57,    58,    59,    60,
       0,    61,    62,    63,    64,     0,    65,    66,     0,     0,
       0,    67,    44,    45,    46,    47,    48,     0,    49,    50,
      51,    52,     0,    53,    54,     0,     0,     0,    77,    56,
      57,    58,    59,    60,     0,    61,    62,    63,    64,     0,
      65,    66,     0,     0,     0,    78,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,     0,    53,    54,     0,
       0,     0,   108,    56,    57,    58,    59,    60,     0,    61,
      62,    63,    64,     0,    65,    66,     0,     0,     0,   109,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
       0,    -1,    -1,    56,    57,    58,    59,    60,     0,    61,
      62,    63,    64,     0,    -1,    -1,    56,    57,    58,    59,
      60,     0,    -1,    -1,    -1,    -1
};

static const yytype_int8 yycheck[] =
{
      16,    17,    10,    11,    12,    17,    22,    40,     0,    25,
      69,    70,    71,    72,    25,    15,    16,    17,    18,    15,
      16,    37,    34,    21,    22,    23,    37,    21,    22,    23,
      16,    17,    15,    41,    34,    15,    22,    15,    34,    25,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    37,   111,    15,    16,    17,    35,    29,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,     3,
      35,    35,    34,     7,    15,     3,    92,     5,    35,     7,
      35,    15,    16,    17,    18,    35,    35,    15,    16,    17,
      18,    43,    43,    -1,    80,   105,    -1,    -1,    -1,    -1,
      34,     3,    -1,    -1,    -1,     7,    34,    -1,    42,    -1,
      -1,    45,    46,    15,    16,    17,    18,    45,    46,    -1,
      -1,     3,    -1,    -1,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    15,    16,    17,    18,    -1,    -1,    -1,
      42,     3,    -1,    45,    46,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    15,    16,    17,    18,    -1,    -1,    -1,
      42,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
       4,    -1,    34,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    45,    46,    19,    20,    21,    22,    23,
       4,    25,    26,    27,    28,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    -1,    30,    31,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    -1,    30,
      31,    -1,    -1,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    44,    30,    31,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    44,    30,
      31,    -1,    -1,    -1,    35,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    -1,    30,    31,    -1,    -1,
      -1,    35,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    31,    -1,    -1,    -1,    35,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    -1,
      30,    31,    -1,    -1,    -1,    35,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    -1,    30,    31,    -1,
      -1,    -1,    35,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    -1,    30,    31,    -1,    -1,    -1,    35,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      -1,    30,    31,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    -1,    30,    31,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    48,    49,     0,    10,    11,    12,    41,    15,
      15,    15,    50,    35,    35,    35,     3,     7,    15,    16,
      17,    18,    34,    42,    45,    46,    51,    52,    54,    55,
      56,    57,    15,    55,    56,    55,    56,    29,    55,    56,
      15,    55,    56,    57,    19,    20,    21,    22,    23,    25,
      26,    27,    28,    30,    31,    35,    19,    20,    21,    22,
      23,    25,    26,    27,    28,    30,    31,    35,    35,     4,
       4,    44,    44,    55,    56,    57,    35,    35,    35,    35,
      34,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    34,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    50,    50,    50,    50,    35,    35,
      35,     5,    53,    53,    42,    42,    50,    43,    43
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 162 "pmf2.y"
    {
                                        printAST((yyvsp[(4) - (5)].node), 0);  ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 166 "pmf2.y"
    { (yyval.node) = newNode(';', (yyvsp[(1) - (4)].node), newDeclNode("INT")); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 167 "pmf2.y"
    {  ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 168 "pmf2.y"
    {  ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 169 "pmf2.y"
    { (yyval.node) = NULL; ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 172 "pmf2.y"
    { (yyval.node) = newNode(';', (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 173 "pmf2.y"
    { (yyval.node) = NULL; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 176 "pmf2.y"
    { (yyval.node) = newNode('=', newIdentNode((yyvsp[(1) - (4)].ident)), (yyvsp[(3) - (4)].node));  ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 177 "pmf2.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 178 "pmf2.y"
    { (yyval.node) = newNode('=', newIdentNode((yyvsp[(1) - (4)].ident)), (yyvsp[(3) - (4)].node)); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 179 "pmf2.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 180 "pmf2.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 181 "pmf2.y"
    { (yyval.node) = newNode('=', newIdentNode((yyvsp[(1) - (4)].ident)), (yyvsp[(3) - (4)].node)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 182 "pmf2.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 183 "pmf2.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 184 "pmf2.y"
    { (yyval.node) = newNode('R', newIdentNode((yyvsp[(2) - (3)].ident)), NULL); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 185 "pmf2.y"
    { (yyval.node) = newNode('W', (yyvsp[(2) - (3)].node), NULL); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 186 "pmf2.y"
    { (yyval.node) = newNode('W', (yyvsp[(2) - (3)].node), NULL); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 187 "pmf2.y"
    { (yyval.node) = newNode('W', (yyvsp[(2) - (3)].node), NULL); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 190 "pmf2.y"
    { (yyval.node) = newNode('i', (yyvsp[(2) - (6)].node),newNode('t',(yyvsp[(4) - (6)].node),(yyvsp[(5) - (6)].node))); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 191 "pmf2.y"
    { (yyval.node) = newNode('i', (yyvsp[(2) - (6)].node), newNode('k', NULL, (yyvsp[(4) - (6)].node))); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 194 "pmf2.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 195 "pmf2.y"
    { (yyval.node) = NULL; ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 198 "pmf2.y"
    { (yyval.node) = newNode('w', (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 199 "pmf2.y"
    { (yyval.node) = newNode('w', (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node)); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 202 "pmf2.y"
    { (yyval.node) = newNode('+', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));  ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 203 "pmf2.y"
    { (yyval.node) = newNode('-', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 204 "pmf2.y"
    { (yyval.node) = newNode('*', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 205 "pmf2.y"
    { (yyval.node) = newNode('/', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 206 "pmf2.y"
    { (yyval.node) = newNode('%', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 207 "pmf2.y"
    { (yyval.node) = newNode('>', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 208 "pmf2.y"
    { (yyval.node) = newNode('G', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 209 "pmf2.y"
    { (yyval.node) = newNode('<', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 210 "pmf2.y"
    { (yyval.node) = newNode('L', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 211 "pmf2.y"
    { (yyval.node) = newNode('Q', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 212 "pmf2.y"
    { (yyval.node) = newNode('!', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 213 "pmf2.y"
    { (yyval.node) = newNode('!', (yyvsp[(2) - (2)].node), NULL); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 214 "pmf2.y"
    { (yyval.node) = newIntNode((yyvsp[(1) - (1)].int_value));  ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 215 "pmf2.y"
    { (yyval.node) = newIdentNode((yyvsp[(1) - (1)].ident));  ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 218 "pmf2.y"
    { (yyval.node) = newNode('+', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));  ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 219 "pmf2.y"
    { (yyval.node) = newNode('-', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 220 "pmf2.y"
    { (yyval.node) = newNode('*', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 221 "pmf2.y"
    { (yyval.node) = newNode('/', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 222 "pmf2.y"
    { (yyval.node) = newNode('%', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 223 "pmf2.y"
    { (yyval.node) = newNode('>', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 224 "pmf2.y"
    { (yyval.node) = newNode('G', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 225 "pmf2.y"
    { (yyval.node) = newNode('<', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 226 "pmf2.y"
    { (yyval.node) = newNode('L', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 227 "pmf2.y"
    { (yyval.node) = newNode('=', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 228 "pmf2.y"
    { (yyval.node) = newNode('!', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 229 "pmf2.y"
    { (yyval.node) = newNode('!', (yyvsp[(2) - (2)].node), NULL); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 230 "pmf2.y"
    { (yyval.node) = newDoubleNode((yyvsp[(1) - (1)].double_value));  ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 233 "pmf2.y"
    { (yyval.node) = newStringNode((yyvsp[(1) - (1)].string_value)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1993 "pmf2.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 236 "pmf2.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    int res = yyparse();
    return res == 0 ? 0 : 1;
}

