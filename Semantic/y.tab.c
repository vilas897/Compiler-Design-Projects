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
#line 1 "sem.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	int g_addr = 100;
	int i=1;
	int j=8;
	int stack[100];
	int index1=0;
	int end[100];
	int arr[10];
	int gl1,gl2,curr_type=0,c=0,b;
	int type=258;

	struct sym
	{
		int sno;
		char token[100];
		int type[100];
		int tn;
		int addr;
		float fvalue;
		int scope;
		int arrFlag;
	}st[100];

	int n=0,arr[10];

	void storereturn( int curr_type, int returntype )
	{
		arr[curr_type] = returntype;
		return;
	}

	void insertscope(char *a,int s)
	{
		int i;
		for(i=0;i<n;i++)
		{
			if(!strcmp(a,st[i].token))
			{
				st[i].scope=s;
				break;
			}
		}
	}

	int returntype_func(int ct)
	{
		return arr[ct-1];
	}

	int isArray(char* a)
	{
		for(i=0;i<=n;i++)
		{
			if(!strcmp(a,st[i].token))
			{
				if(st[i].arrFlag==1)
					return st[i].fvalue;
						else
							return 0;
			 }
		}
		return 0;
	}

	int returnscope(char *a,int cs)
	{
		//printf("\nString is: %s", a);
		int i;
		int max = 0;
		for(i=0;i<=n;i++)
		{
			if(!strcmp(a,st[i].token))
			{
				if(st[i].scope>=max)
					max = st[i].scope;
			}
		}
		return max;
	}

	int lookup(char *a)
	{
		int i;
		for(i=0;i<n;i++)
		{
			if( !strcmp( a, st[i].token) )
				return 0;
		}
		return 1;
	}

	int returntype(char *a,int scope_curr)
	{
		int i;
		for(i=0;i<=n;i++)
		{
			if(!strcmp(a,st[i].token) && st[i].scope==scope_curr)
				return st[i].type[0];
		}
	}

	void update_value(char *a,char *b,int sc)
	{
		int i,j,k;
		int max=0;
		for(i=0;i<=n;i++)
		{
			if(!strcmp(a,st[i].token)   && sc>=st[i].scope)
			{
				if(st[i].scope>=max)
					max=st[i].scope;
			}
		}
		for(i=0;i<=n;i++)
		{
			if(!strcmp(a,st[i].token)   && max==st[i].scope)
			{
				float temp=atof(b);
				for(k=0;k<st[i].tn;k++)
				{
					if(st[i].type[k]==258||st[i].type[0]==269)
						st[i].fvalue=(int)temp;
					else
						st[i].fvalue=temp;
				}
			}
		}
	}

	void insert(char *name, int type, int addr, int arrFlag)
	{
		int i;
		if(lookup(name))
		{
			strcpy(st[n].token,name);
			st[n].tn=1;
			st[n].type[st[n].tn-1]=type;
			st[n].addr=addr;
			st[n].sno=n+1;
			st[n].arrFlag = arrFlag;
			n++;
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(!strcmp(name,st[i].token))
				{
					st[i].tn++;
					st[i].type[st[i].tn-1]=type;
					break;
				}
			}
		}

		return;
	}

	void insert_dup(char *name, int type, int addr,int s_c, int arrFlag)
	{
		strcpy(st[n].token,name);
		st[n].tn=1;
		st[n].type[st[n].tn-1]=type;
		st[n].addr=addr;
		st[n].sno=n+1;
		st[n].scope=s_c;
		st[n].arrFlag=arrFlag;
		n++;
		return;
	}

	void print()
	{
		int i,j;
		printf("\nSymbol Table\n\n");
		printf("\nSNo.\tToken\tAddress\tValue\tScope\tIsArray\tType\n");
		for(i=0;i<n;i++)
		{
			if(st[i].type[0]==258 || st[i].type[0]==261|| st[i].type[0]==262|| st[i].type[0]==263)
				printf("%d\t%s\t%d\t%d\t%d\t%d",st[i].sno,st[i].token,st[i].addr,(int)st[i].fvalue,st[i].scope, st[i].arrFlag);
			else
				printf("%d\t%s\t%d\t%.1f\t%d\t%d",st[i].sno,st[i].token,st[i].addr,st[i].fvalue,st[i].scope, st[i].arrFlag);
			for(j=0;j<st[i].tn;j++)
			{
				if(st[i].type[j]==258)
					printf("\tINT");
				else if(st[i].type[j]==259)
					printf("\tFLOAT");
				else if(st[i].type[j]==274)
					printf("\tFUNCTION");
				else if(st[i].type[j]==269)
					printf("\tARRAY");
				else if(st[i].type[j]==260)
					printf("\tVOID");
        else if(st[i].type[j]==261)
  				printf("\tUNSIGNED INT");
        else if(st[i].type[j]==263)
    			printf("\tLONG INT");
        else if(st[i].type[j]==262)
      		printf("\tSHORT INT");
			}
			printf("\n");
		}
		return;
	}

#line 275 "y.tab.c" /* yacc.c:339  */

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
    INT = 258,
    FLOAT = 259,
    VOID = 260,
    UNSIGNED_INT = 261,
    S_INT = 262,
    L_INT = 263,
    ID = 264,
    INT_CONST = 265,
    FLOAT_CONST = 266,
    WHILE = 267,
    IF = 268,
    RETURN = 269,
    PREPROC = 270,
    LE = 271,
    STRING = 272,
    PRINT = 273,
    FUNCTION = 274,
    ARRAY = 275,
    ELSE = 276
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define VOID 260
#define UNSIGNED_INT 261
#define S_INT 262
#define L_INT 263
#define ID 264
#define INT_CONST 265
#define FLOAT_CONST 266
#define WHILE 267
#define IF 268
#define RETURN 269
#define PREPROC 270
#define LE 271
#define STRING 272
#define PRINT 273
#define FUNCTION 274
#define ARRAY 275
#define ELSE 276

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 218 "sem.y" /* yacc.c:355  */

		int ival;
		char *str;
	

#line 360 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 377 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

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
      23,    24,    33,    31,    28,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
       2,    22,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    26,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   225,   225,   226,   227,   228,   232,   249,   250,   251,
     252,   253,   254,   258,   262,   263,   264,   268,   269,   270,
     271,   277,   278,   279,   280,   284,   285,   289,   293,   294,
     297,   317,   325,   326,   327,   335,   336,   339,   354,   382,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     428,   429,   433,   460,   481,   495,   505
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "UNSIGNED_INT",
  "S_INT", "L_INT", "ID", "INT_CONST", "FLOAT_CONST", "WHILE", "IF",
  "RETURN", "PREPROC", "LE", "STRING", "PRINT", "FUNCTION", "ARRAY",
  "ELSE", "'='", "'('", "')'", "'{'", "'}'", "';'", "','", "'['", "']'",
  "'+'", "'-'", "'*'", "'/'", "$accept", "start", "Function", "Type",
  "compound_stmt", "statement_list", "stmt", "if_stmt", "while_stmt",
  "expr1", "secondary_assignment", "assignment_exp", "exp", "consttype",
  "Declaration", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    61,    40,    41,   123,   125,    59,    44,    91,
      93,    43,    45,    42,    47
};
# endif

#define YYPACT_NINF -74

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-74)))

#define YYTABLE_NINF -37

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     124,   -74,   -74,   -74,   -74,   -74,   -74,   -74,    51,   -74,
     -74,   124,    33,     4,   124,     6,     3,   -74,   122,    36,
     124,    39,    39,    -4,   -74,    16,   -21,   -74,   -74,   -74,
      89,   -74,    33,    33,    33,    33,    39,   -74,   -74,   -74,
      25,    47,   -74,    33,    33,    33,    33,     7,    37,   -74,
      56,   122,   122,   122,   122,   -74,    48,    66,    52,    57,
     112,   117,    50,    70,    83,    33,   -74,   -74,   -74,   -74,
     -74,   -74,    70,   -74,    88,   122,   -74,    96,   -74,    94,
      97,    -3,   103,   -74,   -74,   129,   -74,   -74,   -74,   -74,
     -74,    39,    39,   -74,   110,   123,    65,    30,   -74,    35,
     -74,   114,    39,    70,    70,    33,   141,   -74,   137,   128,
      70,   136,   -74,   -74
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    56,     7,     8,     9,    10,    11,    12,    38,    50,
      51,     0,     0,     0,     0,     0,     0,    32,    35,    48,
       0,     0,     0,     0,     3,    38,     0,    48,     1,     2,
       0,    54,     0,     0,     0,     0,     0,     4,    30,    31,
       0,     0,    49,     0,     0,     0,     0,     0,     0,    53,
       0,    40,    41,    42,    43,    33,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    44,    45,    46,
      47,    52,    16,     6,     0,    37,    15,     0,    55,     0,
       0,     0,     0,    13,    22,     0,    24,    14,    18,    19,
      17,     0,     0,    21,     0,     0,     0,     0,    29,     0,
      20,     0,     0,     0,     0,     0,    28,    27,    25,     0,
       0,     0,    26,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -74,    54,   -74,    87,   -63,   -74,   -74,   -74,   -74,   -73,
     -20,   -74,    -7,   -12,    90
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    13,    14,    15,    73,    77,    87,    88,    89,    97,
      16,    17,    18,    19,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,    38,    39,    42,    28,    26,    40,     9,    10,    76,
      43,    44,    45,    46,    86,    30,    55,     9,    10,    99,
      27,    27,    27,    27,    93,    51,    52,    53,    54,   106,
      31,    27,    27,    27,    27,    62,    58,    59,    60,    61,
     107,   108,    25,     9,    10,    41,   102,   112,     8,     9,
      10,   102,   -36,    27,   103,    56,    12,    57,    75,   104,
     -36,    63,    12,   -36,    36,    24,    64,   -34,    29,    94,
      65,    98,    98,    21,    37,   -34,    67,    71,   -34,    22,
      23,    68,    98,    32,    33,    34,    35,    47,    32,    33,
      34,    35,    49,    27,    50,    72,    66,     1,   109,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    79,    80,
      81,    47,    48,    74,    82,    78,    49,    91,    50,    12,
      92,    72,    83,    84,    -5,     1,    95,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    69,   100,    96,    11,
     101,    70,   105,    32,    33,    34,    35,    12,    32,    33,
      34,    35,   111,    32,    33,    34,    35,   102,   110,    32,
      33,    34,    35,   113,    85,     0,     0,    90
};

static const yytype_int8 yycheck[] =
{
      12,    21,    22,    24,     0,    12,    10,    10,    11,    72,
      31,    32,    33,    34,    77,     9,    36,    10,    11,    92,
      32,    33,    34,    35,    27,    32,    33,    34,    35,   102,
      27,    43,    44,    45,    46,    47,    43,    44,    45,    46,
     103,   104,     9,    10,    11,    29,    16,   110,     9,    10,
      11,    16,    16,    65,    24,    30,    23,    10,    65,    24,
      24,    24,    23,    27,    28,    11,    10,    16,    14,    81,
      22,    91,    92,    22,    20,    24,    24,    27,    27,    28,
      29,    24,   102,    31,    32,    33,    34,    22,    31,    32,
      33,    34,    27,   105,    29,    25,    30,     1,   105,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    22,    23,    30,    18,    27,    27,    23,    29,    23,
      23,    25,    26,    27,     0,     1,    23,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    24,    27,     9,    15,
      17,    24,    28,    31,    32,    33,    34,    23,    31,    32,
      33,    34,    24,    31,    32,    33,    34,    16,    21,    31,
      32,    33,    34,    27,    77,    -1,    -1,    77
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    15,    23,    36,    37,    38,    45,    46,    47,    48,
      49,    22,    28,    29,    36,     9,    47,    48,     0,    36,
       9,    27,    31,    32,    33,    34,    28,    36,    45,    45,
      10,    29,    24,    31,    32,    33,    34,    22,    23,    27,
      29,    47,    47,    47,    47,    45,    30,    10,    47,    47,
      47,    47,    48,    24,    10,    22,    30,    24,    24,    24,
      24,    27,    25,    39,    30,    47,    39,    40,    27,    12,
      13,    14,    18,    26,    27,    38,    39,    41,    42,    43,
      49,    23,    23,    27,    48,    23,     9,    44,    45,    44,
      27,    17,    16,    24,    24,    28,    44,    39,    39,    47,
      21,    24,    39,    27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    36,    36,    36,    37,    38,    38,    38,
      38,    38,    38,    39,    40,    40,    40,    41,    41,    41,
      41,    41,    41,    41,    41,    42,    42,    43,    44,    44,
      45,    45,    45,    45,    45,    45,    45,    46,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      48,    48,    49,    49,    49,    49,    49
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     5,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     0,     1,     1,     1,
       3,     2,     1,     7,     1,     5,     7,     5,     3,     1,
       3,     3,     1,     3,     1,     1,     1,     6,     1,     4,
       3,     3,     3,     3,     5,     5,     5,     5,     1,     3,
       1,     1,     5,     3,     2,     6,     1
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
        case 6:
#line 232 "sem.y" /* yacc.c:1646  */
    {
	if ((yyvsp[-4].ival)!=returntype_func(curr_type))
	{
		printf("\nError : Type mismatch : Line %d\n",printline());
	}

	if (!(strcmp((yyvsp[-3].str),"printf") && strcmp((yyvsp[-3].str),"scanf") && strcmp((yyvsp[-3].str),"getc") && strcmp((yyvsp[-3].str),"gets") && strcmp((yyvsp[-3].str),"getchar") && strcmp	((yyvsp[-3].str),"puts") && strcmp((yyvsp[-3].str),"putchar") && strcmp((yyvsp[-3].str),"clearerr") && strcmp((yyvsp[-3].str),"getw") && strcmp((yyvsp[-3].str),"putw") && strcmp((yyvsp[-3].str),"putc") && strcmp((yyvsp[-3].str),"rewind") && strcmp((yyvsp[-3].str),"sprint") && strcmp((yyvsp[-3].str),"sscanf") && strcmp((yyvsp[-3].str),"remove") && strcmp((yyvsp[-3].str),"fflush")))
		printf("Error : Type mismatch in redeclaration of %s : Line %d\n",(yyvsp[-3].str),printline());
	else
	{
		insert((yyvsp[-3].str),FUNCTION,g_addr, 0);
		insert((yyvsp[-3].str),(yyvsp[-4].ival),g_addr, 0);
		g_addr+=4;
	}
	}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 271 "sem.y" /* yacc.c:1646  */
    {
					if(!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str))))
						storereturn(curr_type,FLOAT);
					else
						storereturn(curr_type,INT); curr_type++;
				}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 277 "sem.y" /* yacc.c:1646  */
    {storereturn(curr_type,VOID); curr_type++;}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 298 "sem.y" /* yacc.c:1646  */
    {
	  c=0;
		int scope_curr=returnscope((yyvsp[-2].str),stack[index1-1]);
		//printf("Scope: %d",scope_curr);
		int type=returntype((yyvsp[-2].str),scope_curr);
		if((!(strspn((yyvsp[0].str),"0123456789")==strlen((yyvsp[0].str)))) && type==258)
			printf("\nError : Type Mismatch : Line %d\n",printline());
		if(!lookup((yyvsp[-2].str)))
		{
			int currscope=stack[index1-1];
			int scope=returnscope((yyvsp[-2].str),currscope);
			if((scope<=currscope && end[scope]==0) && !(scope==0))
				update_value((yyvsp[-2].str),(yyvsp[0].str),currscope);
		}
		if(isArray((yyvsp[-2].str)))
				printf("\nError: Array Identfier has no subscript: Line %d\n", printline());

		}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 317 "sem.y" /* yacc.c:1646  */
    {
					if(lookup((yyvsp[-2].str)))
						printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-2].str),printline());

						if(isArray((yyvsp[-2].str)))
								printf("\nError: Array identfier has no subscript: Line %d\n", printline());

				}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 327 "sem.y" /* yacc.c:1646  */
    {
		if(lookup((yyvsp[0].str)))
			printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[0].str),printline());

			if(isArray((yyvsp[0].str)))
				printf("\nError: Non-array variable used as an array: Line %d\n", printline());

		}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 339 "sem.y" /* yacc.c:1646  */
    {
			if(lookup((yyvsp[-5].str)))
				printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-5].str),printline());

			if(isArray((yyvsp[-5].str))==0)
				printf("\nError: Non-array variable used as an array: Line %d\n", printline());

				float bound = isArray((yyvsp[-5].str));

				if(isArray((yyvsp[-5].str)) && (atoi((yyvsp[-3].str)) >= bound || atoi((yyvsp[-3].str)) < 0))
					printf("\nError: Array subscript out of bounds : Line %d\n", printline());

		}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 354 "sem.y" /* yacc.c:1646  */
    {
	if(isArray((yyvsp[0].str)))
	 printf("\nError: Array identifier has no subscript: Line %d\n", printline());

	if(c==0)
	{
		c=1;
		int scope_curr=returnscope((yyvsp[0].str),stack[index1-1]);
		b=returntype((yyvsp[0].str),scope_curr);
	}
	else
	{
		int scope_curr1=returnscope((yyvsp[0].str),stack[index1-1]);
		if(b!=returntype((yyvsp[0].str),scope_curr1))
			printf("\nError : Type Mismatch : Line %d\n",printline());
	}
	if(!lookup((yyvsp[0].str)))
	{
		int currscope=stack[index1-1];
		//printf("\ncurrscope%d Current Scope: %d\n", currscope, stack[index1-1]);
		int scope=returnscope((yyvsp[0].str),currscope);
		//printf("Curr scope: %d %d\n", currscope,scope);
		if(!(scope<=currscope && end[scope]==0))
			printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[0].str),printline());
	}
  else
    printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[0].str),printline());
	}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 382 "sem.y" /* yacc.c:1646  */
    {
		if(c==0)
		{
			c=1;
			int scope_curr=returnscope((yyvsp[-3].str),stack[index1-1]);
			b=returntype((yyvsp[-3].str),scope_curr);
		}
		else
		{
			int scope_curr1=returnscope((yyvsp[-3].str),stack[index1-1]);
			if(b!=returntype((yyvsp[-3].str),scope_curr1))
				printf("\nError : Type Mismatch : Line %d\n",printline());
		}
		if(!lookup((yyvsp[-3].str)))
		{
			int currscope=stack[index1-1];
			//printf("\ncurrscope%d Current Scope: %d\n", currscope, stack[index1-1]);
			int scope=returnscope((yyvsp[-3].str),currscope);
			//printf("Curr scope: %d %d\n", currscope,scope);
			if(!(scope<=currscope && end[scope]==0))
				printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[-3].str),printline());
		}
	  else
	    printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[-3].str),printline());

		if(isArray((yyvsp[-3].str))==0)
			printf("\nError: Non-array variable used as an array: Line %d\n", printline());

		float bound = isArray((yyvsp[-3].str));

		if(isArray((yyvsp[-3].str)) && (atoi((yyvsp[-1].str)) >= bound || atoi((yyvsp[-1].str)) < 0) )
			printf("\nError: Array subscript out of bounds : Line %d\n", printline());

		}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 434 "sem.y" /* yacc.c:1646  */
    {
			if( (!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str)))) && (yyvsp[-4].ival)==258)
				printf("\nError : Type Mismatch : Line %d\n",printline());

			if(!lookup((yyvsp[-3].str)))
			{
				int currscope=stack[index1-1];
				int previous_scope=returnscope((yyvsp[-3].str),currscope);
				if(currscope==previous_scope)
					printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-3].str),printline());
				else
				{
					insert_dup((yyvsp[-3].str),(yyvsp[-4].ival),g_addr,currscope, 0);
					update_value((yyvsp[-3].str),(yyvsp[-1].str),stack[index1-1]);
					g_addr+=4;
				}
			}
			else
			{
				int scope=stack[index1-1];
				insert((yyvsp[-3].str),(yyvsp[-4].ival),g_addr, 0);
				insertscope((yyvsp[-3].str),scope);
				update_value((yyvsp[-3].str),(yyvsp[-1].str),stack[index1-1]);
				g_addr+=4;
			}
		}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 460 "sem.y" /* yacc.c:1646  */
    {
		if(!lookup((yyvsp[-1].str)))
		{
			int currscope=stack[index1-1];
			int previous_scope=returnscope((yyvsp[-1].str),currscope);
			if(currscope==previous_scope)
				printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-1].str),printline());
			else
			{
				insert_dup((yyvsp[-1].str),(yyvsp[-2].ival),g_addr,currscope, 0);
				g_addr+=4;
			}
		}
		else
		{
			int scope=stack[index1-1];
			insert((yyvsp[-1].str),(yyvsp[-2].ival),g_addr, 0);
			insertscope((yyvsp[-1].str),scope);
			g_addr+=4;
		}
	}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 481 "sem.y" /* yacc.c:1646  */
    {
				if(!lookup((yyvsp[-1].str)))
				{
					int currscope=stack[index1-1];
					//printf("\ncurrscope%d Current Scope: %d\n", currscope, stack[index1-1]);
					int scope=returnscope((yyvsp[-1].str),currscope);
					//printf("Curr scope: %d %d\n", currscope,scope);
					if(!(scope<=currscope && end[scope]==0))
						printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[-1].str),printline());
				}
				else
					printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[-1].str),printline());
				}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 495 "sem.y" /* yacc.c:1646  */
    {
						insert((yyvsp[-4].str),ARRAY,g_addr,1);
						insert((yyvsp[-4].str),(yyvsp[-5].ival),g_addr,1);
						update_value((yyvsp[-4].str),(yyvsp[-2].str),stack[index1-1]);
						g_addr+=4;
						if(atoi((yyvsp[-2].str))<=0)
						{
							printf("\nError: Illegal array subscript %d : Line %d\n", atoi((yyvsp[-2].str)), printline());
						}
					}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1799 "y.tab.c" /* yacc.c:1646  */
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
#line 508 "sem.y" /* yacc.c:1906  */


#include "lex.yy.c"
#include<ctype.h>
int main(int argc, char *argv[])
{
	yyin =fopen(argv[1],"r");
	if(!yyparse())
	{
		printf("Parsing done\n");
		print();
	}
	else
	{
		printf("Error\n");
	}
	fclose(yyin);
	return 0;
}

yyerror(char *s)
{
	printf("\nLine %d : %s %s\n",yylineno,s,yytext);
}

int printline()
{
	return yylineno;
}

void block_start()
{
	stack[index1]=i;
	i++;
	index1++;
	//printf("\n\nTop of stack changed to: %d at line %d", stack[index1-1], yylineno);
	return;
}

void block_end()
{
	index1--;
	//printf("\n\nTop of stack changed to: %d at line %d", stack[index1-1], yylineno);
	end[stack[index1]]=1;
	stack[index1]=0;
	return;
}
