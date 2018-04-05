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
#include<string.h>
int g_addr = 100;
int i=1,lnum1=0,label1[20],ltop1;
int stack[100],index1=0,end[100],returnArr[10],returnCount,c,b,fl,top=0,label[20],lnum=0,ltop=0;
char tokenstack[100][10];
char i_[2]="0";
char temp[2]="t";
char null[2]=" ";
int type=258;
	int fname[100];
	int nP;
	int fTypes[100];
	int fTypes2[100];
	int temptype;
	int it;

void yyerror(char *s);
int printline();

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
	int fType[100];
	int numParams;
}st[100];

int n=0,returnArr[10];
float t[100];
int iter=0;

int returntype_func(int returnCount)
{
	return returnArr[returnCount-1];
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

void getParams(char* a)
	{
		for(i=0;i<=n;i++)
		{
			if(!strcmp(a,st[i].token))
			{
				for(int j=0; j<st[i].numParams; j++)
					fTypes[j] = st[i].fType[j];
			}
		}
		return 0;
	}


void storereturn( int returnCount, int returntype )
{
	returnArr[returnCount] = returntype;
	return;
}

void insertscope(char *a,int scope)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(!strcmp(a,st[i].token))
		{
			st[i].scope=scope;
			break;
		}
	}
}

int returnscope(char *a,int cs)
{
	int i;
	int max = 0;
	for(i=0;i<=n;i++)
	{
		if(!(strcmp(a,st[i].token)) && cs>=st[i].scope)
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

void insertFunc(char *name, int type, int addr, int arrFlag, int params[100], int numParams)
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
			for(int j=0; j<numParams; j++)
				st[n].fType[j] = params[j];
			st[n].numParams = numParams;
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

int getReturnType(char *a,int currScopeId)
{
	int i;
	for(i=0;i<=n;i++)
	{
		if(!strcmp(a,st[i].token) && st[i].scope==currScopeId)
		{
			return st[i].type[0];
		}
	}
}

void updateVal(char *a,char *b,int sc)
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
				if(st[i].type[k]==258)
					st[i].fvalue=(int)temp;
				else
					st[i].fvalue=temp;
			}
		}
	}
}

void storevalue(char *a,char *b,int currScope)
{
	int i;
	for(i=0;i<=n;i++)
	{
		if(!strcmp(a,st[i].token) && currScope==st[i].scope)
		{
			st[i].fvalue=atof(b);
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

void insertDup(char *name, int type, int addr,int currScope)
{
	strcpy(st[n].token,name);
	st[n].tn=1;
	st[n].type[st[n].tn-1]=type;
	st[n].addr=addr;
	st[n].sno=n+1;
	st[n].scope=currScope;
	n++;
	return;
}

	void print()
	{
		int i,j;
		printf("\nSymbol Table\n\n");
		printf("\nSNo.\tToken\tAddress\tValue\tScope\tIsArray\tType\tParams\n");
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
			for(int j=0;j<st[i].numParams;j++)
			{
				if(st[i].fType[j]==258)
					printf("\tINT");
				else if(st[i].fType[j]==259)
					printf("\tFLOAT");
				else if(st[i].fType[j]==274)
					printf("\tFUNCTION");
				else if(st[i].fType[j]==269)
					printf("\tARRAY");
				else if(st[i].fType[j]==260)
					printf("\tVOID");
				else if(st[i].fType[j]==261)
			  		printf("\tUNSIGNED INT");
				else if(st[i].fType[j]==263)
			    		printf("\tLONG INT");
				else if(st[i].fType[j]==262)
			      		printf("\tSHORT INT");
			}
			printf("\n");
		}
		return;
	}

void blockBegin()
{
	stack[index1]=i;
	i++;
	index1++;
	return;
}

void blockEnd()
{
	index1--;
	end[stack[index1]]=1;
	stack[index1]=0;
	return;
}

void if1()
{
	lnum++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = not %s\n",temp,tokenstack[top]);
 	printf("if %s goto L%d\n",temp,lnum);
	i_[0]++;
	label[++ltop]=lnum;
}

void if2()
{
	lnum++;
	printf("goto L%d\n",lnum);
	printf("L%d: \n",label[ltop--]);
	label[++ltop]=lnum;
}

void if3()
{
	printf("L%d:\n",label[ltop--]);
}

void w1()
{
	lnum++;
	label[++ltop]=lnum;
	printf("L%d:\n",lnum);
}

void w2()
{
	lnum++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = not %s\n",temp,tokenstack[top--]);
 	printf("if %s goto L%d\n",temp,lnum);
	i_[0]++;
	label[++ltop]=lnum;
}

void w3()
{
	int y=label[ltop--];
	printf("goto L%d\n",label[ltop--]);
	printf("L%d:\n",y);
}

void push(char *a)
{
	strcpy(tokenstack[++top],a);
}

void array1()
{
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = %s * 4\n",temp,tokenstack[top]);
	strcpy(tokenstack[top],temp);
	i_[0]++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = %s [ %s ] \n",temp,tokenstack[top-1],tokenstack[top]);
	top--;
	strcpy(tokenstack[top],temp);
	i_[0]++;
}

void gencode()
{
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = %s %s %s\n",temp,tokenstack[top-2],tokenstack[top-1],tokenstack[top]);
	top-=2;
	strcpy(tokenstack[top],temp);
	i_[0]++;
}

void gencodeUnaryMinus()
{
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = -%s\n",temp,tokenstack[top]);
	top--;
	strcpy(tokenstack[top],temp);
	i_[0]++;
}

void gencodeAssignment()
{
	printf("%s = %s\n",tokenstack[top-2],tokenstack[top]);
	top-=2;
}

	int retNumParams(char* a)
	{
		for(i=0;i<=n;i++)
		{
			if(!strcmp(a,st[i].token))
			{
				return st[i].numParams;
			}
		}
		return 0;
	}


#line 484 "y.tab.c" /* yacc.c:339  */

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
    ID = 261,
    NUM = 262,
    REAL = 263,
    LE = 264,
    GE = 265,
    EQ = 266,
    NEQ = 267,
    AND = 268,
    OR = 269,
    WHILE = 270,
    IF = 271,
    RETURN = 272,
    PREPROC = 273,
    STRING = 274,
    PRINT = 275,
    FUNCTION = 276,
    DO = 277,
    ARRAY = 278,
    ELSE = 279,
    STRUCT = 280,
    STRUCT_VAR = 281,
    FOR = 282,
    UMINUS = 283
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define VOID 260
#define ID 261
#define NUM 262
#define REAL 263
#define LE 264
#define GE 265
#define EQ 266
#define NEQ 267
#define AND 268
#define OR 269
#define WHILE 270
#define IF 271
#define RETURN 272
#define PREPROC 273
#define STRING 274
#define PRINT 275
#define FUNCTION 276
#define DO 277
#define ARRAY 278
#define ELSE 279
#define STRUCT 280
#define STRUCT_VAR 281
#define FOR 282
#define UMINUS 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 429 "sem.y" /* yacc.c:355  */

		int ival;
		char *str;
	

#line 583 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 600 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,    34,    32,    38,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
      28,    30,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   436,   436,   437,   438,   439,   443,   443,   460,   460,
     478,   484,   491,   492,   493,   497,   501,   502,   506,   507,
     508,   509,   510,   516,   517,   518,   519,   520,   523,   540,
     551,   552,   553,   554,   558,   558,   558,   562,   563,   567,
     567,   567,   571,   572,   573,   574,   575,   576,   580,   580,
     580,   580,   596,   600,   601,   605,   609,   610,   614,   614,
     614,   614,   644,   655,   660,   661,   665,   665,   669,   669,
     670,   670,   671,   672,   672,   672,   673,   673,   673,   674,
     674,   674,   675,   675,   675,   676,   676,   676,   677,   677,
     677,   678,   678,   678,   679,   679,   679,   680,   680,   680,
     681,   685,   685,   686,   686,   687,   691,   692,   692,   693,
     694
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "ID", "NUM",
  "REAL", "LE", "GE", "EQ", "NEQ", "AND", "OR", "WHILE", "IF", "RETURN",
  "PREPROC", "STRING", "PRINT", "FUNCTION", "DO", "ARRAY", "ELSE",
  "STRUCT", "STRUCT_VAR", "FOR", "'<'", "'>'", "'='", "UMINUS", "'+'",
  "'-'", "'*'", "'/'", "'('", "')'", "','", "'{'", "'}'", "';'", "'['",
  "']'", "$accept", "start", "Function", "$@1", "$@2", "param_list",
  "Type", "CompoundStmt", "StmtList", "stmt", "function_call", "call_list",
  "if", "$@3", "$@4", "else", "while", "$@5", "$@6", "assignment",
  "secondary_assignment", "$@7", "$@8", "$@9", "consttype", "Declaration",
  "$@10", "$@11", "$@12", "array", "$@13", "E", "$@14", "$@15", "$@16",
  "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23", "$@24", "$@25",
  "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32", "$@33", "T",
  "$@34", "$@35", "F", "$@36", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    60,    62,
      61,   283,    43,    45,    42,    47,    40,    41,    44,   123,
     125,    59,    91,    93
};
# endif

#define YYPACT_NINF -80

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define YYTABLE_NINF -98

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     131,   -80,   -80,   -80,   -80,   102,   -80,   -80,   131,    22,
     131,    28,   -32,    20,   131,    74,    74,    17,   -80,   -80,
     -80,    -5,   -80,    74,   -80,    -2,   -80,    40,   -80,     1,
      84,    67,   -80,    63,    70,   -80,     6,   109,     3,    76,
      87,   -80,   -80,    99,   -80,    70,   -80,   -80,    69,   128,
     -80,    91,   -80,   118,   -80,   159,    84,    84,    92,    84,
      70,   100,   138,   145,   146,   152,   155,   157,   147,   148,
     144,    81,   113,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
      91,   170,   -80,   -80,   -80,   -80,   -80,    69,    70,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,    81,    81,    81,    81,    45,   -80,   -80,   137,   -14,
      70,    70,    70,    70,    70,    70,    70,    70,    70,   128,
     128,   -80,   -80,    57,   -80,   143,    13,   149,   -80,   -80,
     174,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,    69,
      69,    69,    69,    69,    69,    69,    69,    69,     5,   150,
      70,   -80,   140,   163,   141,   -80,   151,   132,   -80,    70,
     119,   -80,   154,   -80,   156,   153,   121,   -80,   158,   -80,
     -80,   -80,   -80,    91,   -80,    91,   -80,   -80,   160,    91,
     -80,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    65,    12,    13,    14,    48,    56,    57,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     3,     1,
       2,    58,    62,     0,     4,    54,    52,     0,    49,     0,
       0,     0,    53,     0,     0,     6,     0,     0,    46,     0,
      47,    59,    64,   109,   107,     0,   110,   100,    50,    72,
     105,     0,     8,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    70,    51,   101,   103,    17,     7,
       0,     0,    42,    43,    44,    63,    45,    60,     0,    74,
      77,    80,    83,    86,    89,    92,    95,    98,   109,   108,
     106,     0,     0,     0,     0,     0,     9,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      71,   102,   104,    48,    39,     0,     0,     0,    15,    24,
       0,    26,    16,    27,    19,    21,    18,    61,    67,    75,
      78,    81,    84,    87,    90,    93,    96,    99,     0,     0,
       0,    23,     0,     0,    58,    30,     0,     0,    31,     0,
       0,    22,     0,    20,     0,     0,     0,    34,     0,    28,
      32,    33,    40,     0,    25,     0,    35,    41,    38,     0,
      36,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   110,   -80,   -80,   -80,   -80,   -26,   -79,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,     7,
       9,   -80,   -80,   -80,     0,    82,   -80,   -80,   -80,   -80,
     -80,   -43,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,    71,   -80,   -80,   -64,   -80
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    51,    80,    36,    11,    79,   105,   132,
     133,   157,   134,   173,   178,   180,   135,   149,   175,    39,
      12,    17,    34,    75,    46,    14,    31,    60,   108,    47,
      61,    48,   101,   102,    62,   110,    63,   111,    64,   112,
      65,   113,    66,   114,    67,   115,    68,   116,    69,   117,
      70,   118,    49,   103,   104,    50,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,   106,    72,    37,     2,     3,     4,    99,    13,    22,
      13,   155,     6,     7,    13,    13,    13,    87,    73,    74,
       6,     7,    19,    13,    26,    27,   131,    81,   -48,   138,
      40,    29,    32,    55,    21,    56,    15,    30,    35,   121,
     122,    57,   156,    52,    53,   109,     1,    28,     2,     3,
       4,   123,     6,     7,   151,    82,    40,    40,    23,    40,
     124,   125,   126,    83,    84,   127,    86,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    43,     6,     7,   130,
      25,     6,     7,    33,    78,   128,   129,    98,     6,     7,
      38,     6,     7,   148,   176,    15,   177,    41,   -54,    16,
     181,    73,    74,    44,    42,    13,    45,   160,   -73,   -76,
     -79,   -82,   -85,   -88,    44,    54,   166,    45,    18,    58,
      20,     2,     3,     4,    24,    59,   152,   -91,   -94,   -97,
      78,    -5,     1,    85,     2,     3,     4,     5,     6,     7,
      15,   -66,    88,   -54,    16,    73,    74,    89,   158,     8,
     100,    73,    74,    73,    74,    90,   167,    91,   172,   170,
       6,     7,    76,    77,    92,   171,     6,     7,    93,   164,
     165,    94,   119,   120,    97,    95,   107,    96,   137,   150,
     154,   161,   162,    30,   179,   153,   159,   136,     0,     0,
       0,   168,   163,     0,     0,     0,     0,   169,     0,   174
};

static const yytype_int16 yycheck[] =
{
       0,    80,    45,    29,     3,     4,     5,    71,     8,    41,
      10,     6,     7,     8,    14,    15,    16,    60,    32,    33,
       7,     8,     0,    23,    15,    16,   105,    53,    30,    43,
      30,    36,    23,    30,     6,    32,    38,    42,    37,   103,
     104,    38,    37,    37,    38,    88,     1,    30,     3,     4,
       5,     6,     7,     8,    41,    55,    56,    57,    38,    59,
      15,    16,    17,    56,    57,    20,    59,   110,   111,   112,
     113,   114,   115,   116,   117,   118,     6,     7,     8,   105,
       6,     7,     8,    43,    39,    40,    41,     6,     7,     8,
       6,     7,     8,    36,   173,    38,   175,    30,    41,    42,
     179,    32,    33,    33,    41,   105,    36,   150,     9,    10,
      11,    12,    13,    14,    33,     6,   159,    36,     8,    43,
      10,     3,     4,     5,    14,    38,   126,    28,    29,    30,
      39,     0,     1,    41,     3,     4,     5,     6,     7,     8,
      38,    42,    42,    41,    42,    32,    33,     9,   148,    18,
      37,    32,    33,    32,    33,    10,    37,    11,    37,     6,
       7,     8,    34,    35,    12,   165,     7,     8,    13,    37,
      38,    14,   101,   102,    30,    28,     6,    29,    41,    36,
       6,    41,    19,    42,    24,    36,    36,   105,    -1,    -1,
      -1,    37,    41,    -1,    -1,    -1,    -1,    41,    -1,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    18,    45,
      46,    50,    64,    68,    69,    38,    42,    65,    45,     0,
      45,     6,    41,    38,    45,     6,    64,    64,    30,    36,
      42,    70,    64,    43,    66,    37,    49,    50,     6,    63,
      68,    30,    41,     6,    33,    36,    68,    73,    75,    96,
      99,    47,    37,    38,     6,    30,    32,    38,    43,    38,
      71,    74,    78,    80,    82,    84,    86,    88,    90,    92,
      94,   100,    75,    32,    33,    67,    34,    35,    39,    51,
      48,    50,    68,    63,    63,    41,    63,    75,    42,     9,
      10,    11,    12,    13,    14,    28,    29,    30,     6,    99,
      37,    76,    77,    97,    98,    52,    51,     6,    72,    75,
      79,    81,    83,    85,    87,    89,    91,    93,    95,    96,
      96,    99,    99,     6,    15,    16,    17,    20,    40,    41,
      50,    51,    53,    54,    56,    60,    69,    41,    43,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    36,    61,
      36,    41,    68,    36,     6,     6,    37,    55,    68,    36,
      75,    41,    19,    41,    37,    38,    75,    37,    37,    41,
       6,    68,    37,    57,    41,    62,    51,    51,    58,    24,
      59,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    45,    45,    47,    46,    48,    46,
      49,    49,    50,    50,    50,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      55,    55,    55,    55,    57,    58,    56,    59,    59,    61,
      62,    60,    63,    63,    63,    63,    63,    63,    65,    66,
      67,    64,    64,    64,    64,    64,    68,    68,    70,    71,
      72,    69,    69,    69,    69,    69,    74,    73,    76,    75,
      77,    75,    75,    78,    79,    75,    80,    81,    75,    82,
      83,    75,    84,    85,    75,    86,    87,    75,    88,    89,
      75,    90,    91,    75,    92,    93,    75,    94,    95,    75,
      75,    97,    96,    98,    96,    96,    99,   100,    99,    99,
      99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     0,     6,     0,     7,
       2,     4,     1,     1,     1,     3,     2,     0,     1,     1,
       4,     1,     3,     2,     1,     5,     1,     1,     5,     4,
       1,     1,     3,     3,     0,     0,     8,     2,     0,     0,
       0,     7,     3,     3,     3,     3,     1,     1,     0,     0,
       0,     6,     3,     3,     1,     1,     1,     1,     0,     0,
       0,     8,     2,     6,     5,     1,     0,     5,     0,     4,
       0,     4,     1,     0,     0,     5,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       1,     0,     4,     0,     4,     1,     3,     0,     3,     1,
       1
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
#line 443 "sem.y" /* yacc.c:1646  */
    { printf("\nfunction begin %s:\n", (yyvsp[-2].str)); }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 443 "sem.y" /* yacc.c:1646  */
    {

		if ((yyvsp[-5].ival)!=returntype_func(returnCount))
		{
			printf("\nError : Type mismatch : Line %d\n",printline());
		}

		if (!(strcmp((yyvsp[-4].str),"printf") && strcmp((yyvsp[-4].str),"scanf") && strcmp((yyvsp[-4].str),"getc") && strcmp((yyvsp[-4].str),"gets") && strcmp((yyvsp[-4].str),"getchar") && strcmp	((yyvsp[-4].str),"puts") && strcmp((yyvsp[-4].str),"putchar") && strcmp((yyvsp[-4].str),"clearerr") && strcmp((yyvsp[-4].str),"getw") && strcmp((yyvsp[-4].str),"putw") && strcmp((yyvsp[-4].str),"putc") && strcmp((yyvsp[-4].str),"rewind") && strcmp((yyvsp[-4].str),"sprint") && strcmp((yyvsp[-4].str),"sscanf") && strcmp((yyvsp[-4].str),"remove") && strcmp((yyvsp[-4].str),"fflush")))
			printf("Error : Type mismatch in redeclaration of %s : Line %d\n",(yyvsp[-4].str),printline());
		else
		{
			insert((yyvsp[-4].str),FUNCTION,g_addr, 0);
			insert((yyvsp[-4].str),(yyvsp[-5].ival),g_addr, 0);
			g_addr+=4;
		}
		printf("function end\n\n");
		}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 460 "sem.y" /* yacc.c:1646  */
    { printf("\nfunction begin %s:\n", (yyvsp[-3].str)); }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 460 "sem.y" /* yacc.c:1646  */
    {

		if ((yyvsp[-6].ival)!=returntype_func(returnCount))
		{
			printf("\nError : Type mismatch : Line %d %d %d\n",printline(), (yyvsp[-6].ival), returntype_func(returnCount));
		}

		if (!(strcmp((yyvsp[-5].str),"printf") && strcmp((yyvsp[-5].str),"scanf") && strcmp((yyvsp[-5].str),"getc") && strcmp((yyvsp[-5].str),"gets") && strcmp((yyvsp[-5].str),"getchar") && strcmp	((yyvsp[-5].str),"puts") && strcmp((yyvsp[-5].str),"putchar") && strcmp((yyvsp[-5].str),"clearerr") && strcmp((yyvsp[-5].str),"getw") && strcmp((yyvsp[-5].str),"putw") && strcmp((yyvsp[-5].str),"putc") && strcmp((yyvsp[-5].str),"rewind") && strcmp((yyvsp[-5].str),"sprint") && strcmp((yyvsp[-5].str),"sscanf") && strcmp((yyvsp[-5].str),"remove") && strcmp((yyvsp[-5].str),"fflush")))
			printf("Error : Type mismatch in redeclaration of %s : Line %d\n",(yyvsp[-5].str),printline());
		else
		{
			insertFunc((yyvsp[-5].str),FUNCTION,g_addr, 0, fname, nP);
			insert((yyvsp[-5].str),(yyvsp[-6].ival),g_addr, 0);
			g_addr+=4;
		}
		printf("function end\n\n");
		}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 479 "sem.y" /* yacc.c:1646  */
    {
	int scope=stack[index1-1];
	insert((yyvsp[0].str),(yyvsp[-1].ival),g_addr, 0);
	insertscope((yyvsp[0].str),scope+1);
	g_addr+=4; nP = 1; fname[nP-1] = (yyvsp[-1].ival); }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 484 "sem.y" /* yacc.c:1646  */
    { int scope=stack[index1-1];
	insert((yyvsp[0].str),(yyvsp[-1].ival),g_addr, 0);
	insertscope((yyvsp[0].str),scope+1);
	g_addr+=4;
	nP++; fname[nP-1] = (yyvsp[-1].ival); }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 510 "sem.y" /* yacc.c:1646  */
    {
					if(!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str))))
						storereturn(returnCount,FLOAT);
					else
						storereturn(returnCount,INT); returnCount++;
					}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 516 "sem.y" /* yacc.c:1646  */
    {storereturn(returnCount,VOID); returnCount++;}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 523 "sem.y" /* yacc.c:1646  */
    {
		if(lookup((yyvsp[-4].str)))
			printf("\nError: Undeclared function %s : Line %d\n", (yyvsp[-4].str), printline());
		else
		{
			if(retNumParams((yyvsp[-4].str)) == 0)
				printf("\nError : Parameter list does not match signature : Line %d\n", printline());
			getParams((yyvsp[-4].str));
		}

		for(int j=0; j<retNumParams((yyvsp[-4].str)); j++)
		{
			if(fTypes[j] != fTypes2[j])
				printf("\nError : Parameter list does not match signature : Line %d\n", printline());
		}
		printf("call %s, %d\n", (yyvsp[-4].str), it);
	}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 540 "sem.y" /* yacc.c:1646  */
    {
		if(lookup((yyvsp[-3].str)))
			printf("\nError: Undeclared function %s : Line %d\n", (yyvsp[-3].str), printline());
		else
		{
			if(retNumParams((yyvsp[-3].str)) != 0)
				printf("\nError : Parameter list does not match signature : Line %d\n", printline());
		}
		printf("call %s, %d\n", (yyvsp[-3].str), 0);
	}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 551 "sem.y" /* yacc.c:1646  */
    { printf("Push Param %s\n", (yyvsp[0].str)); temptype = returntype((yyvsp[0].str), stack[index1-1]); it = 0; fTypes2[it] = temptype; }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 552 "sem.y" /* yacc.c:1646  */
    {  printf("Push Param %s\n", (yyvsp[0].str)); temptype = temp; it = 0; fTypes2[it] = temptype; }
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 553 "sem.y" /* yacc.c:1646  */
    {  printf("Push Param %s\n", (yyvsp[0].str)); it++; temptype = returntype((yyvsp[0].str), stack[index1-1]); fTypes2[it] = temptype;}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 554 "sem.y" /* yacc.c:1646  */
    {  printf("Push Param %s\n", (yyvsp[0].str)); temptype = temp; it++; fTypes2[it] = temptype;}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 558 "sem.y" /* yacc.c:1646  */
    {if1();}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 558 "sem.y" /* yacc.c:1646  */
    {if2();}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 562 "sem.y" /* yacc.c:1646  */
    {if3();}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 567 "sem.y" /* yacc.c:1646  */
    {w1();}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 567 "sem.y" /* yacc.c:1646  */
    {w2();}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 567 "sem.y" /* yacc.c:1646  */
    {w3();}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 580 "sem.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 580 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],"=");}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 580 "sem.y" /* yacc.c:1646  */
    {gencodeAssignment();}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 581 "sem.y" /* yacc.c:1646  */
    {
		int currScopeId=returnscope((yyvsp[-5].str),stack[index1-1]);
		int type=getReturnType((yyvsp[-5].str),currScopeId);
		if((!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str)))) && type==258 && fl==0)
			printf("\nError : Type Mismatch : Line %d\n",printline());
		if(!lookup((yyvsp[-5].str)))
		{
			int currscope=stack[index1-1];
			int scope=returnscope((yyvsp[-5].str),currscope);
			if((scope<=currscope && end[scope]==0) && !(scope==0))
			{
				updateVal((yyvsp[-5].str),(yyvsp[-1].str),currscope);
			}
		}
		}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 596 "sem.y" /* yacc.c:1646  */
    {
					if(lookup((yyvsp[-2].str)))
						printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-2].str),printline());
				}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 601 "sem.y" /* yacc.c:1646  */
    {
		if(lookup((yyvsp[0].str)))
			printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[0].str),printline());
		}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 614 "sem.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 614 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],"=");}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 614 "sem.y" /* yacc.c:1646  */
    {gencodeAssignment();}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 615 "sem.y" /* yacc.c:1646  */
    {
			if( (!(strspn((yyvsp[-2].str),"0123456789")==strlen((yyvsp[-2].str)))) && (yyvsp[-7].ival)==258 && (fl==0))
			{
				printf("\nError : Type Mismatch : Line %d\n",printline());
				fl=1;
			}
			if(!lookup((yyvsp[-6].str)))
			{
				int currscope=stack[index1-1];
				int previous_scope=returnscope((yyvsp[-6].str),currscope);
				if(currscope==previous_scope)
					printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-6].str),printline());
				else
				{
					insertDup((yyvsp[-6].str),(yyvsp[-7].ival),g_addr,currscope);
					updateVal((yyvsp[-6].str),(yyvsp[-2].str),stack[index1-1]);
					int sg=returnscope((yyvsp[-6].str),stack[index1-1]);
					g_addr+=4;
				}
			}
			else
			{
				int scope=stack[index1-1];
				insert((yyvsp[-6].str),(yyvsp[-7].ival),g_addr, 0);
				insertscope((yyvsp[-6].str),scope);
				updateVal((yyvsp[-6].str),(yyvsp[-2].str),stack[index1-1]);
				g_addr+=4;
			}
		}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 644 "sem.y" /* yacc.c:1646  */
    {
				if(!lookup((yyvsp[-1].str)))
				{
					int currscope=stack[index1-1];
					int scope=returnscope((yyvsp[-1].str),currscope);
					if(!(scope<=currscope && end[scope]==0) || scope==0)
						printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[-1].str),printline());
				}
				else
					printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[-1].str),printline());
				}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 655 "sem.y" /* yacc.c:1646  */
    {
						insert((yyvsp[-4].str),ARRAY,g_addr, 1);
						insert((yyvsp[-4].str),(yyvsp[-5].ival),g_addr, 0);
						g_addr+=4;
					}
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 665 "sem.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 669 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],"+");}
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 669 "sem.y" /* yacc.c:1646  */
    {gencode();}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 670 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],"-");}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 670 "sem.y" /* yacc.c:1646  */
    {gencode();}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 672 "sem.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 672 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],"<=");}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 672 "sem.y" /* yacc.c:1646  */
    {gencode();}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 673 "sem.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 673 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],">=");}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 673 "sem.y" /* yacc.c:1646  */
    {gencode();}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 674 "sem.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 674 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],"==");}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 674 "sem.y" /* yacc.c:1646  */
    {gencode();}
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 675 "sem.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 675 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],"!=");}
#line 2232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 675 "sem.y" /* yacc.c:1646  */
    {gencode();}
#line 2238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 676 "sem.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 676 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],"&&");}
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 676 "sem.y" /* yacc.c:1646  */
    {gencode();}
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 677 "sem.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 677 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],"||");}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 677 "sem.y" /* yacc.c:1646  */
    {gencode();}
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 678 "sem.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 678 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],"<");}
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 678 "sem.y" /* yacc.c:1646  */
    {gencode();}
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 679 "sem.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 679 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],">");}
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 679 "sem.y" /* yacc.c:1646  */
    {gencode();}
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 680 "sem.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 680 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],"||");}
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 680 "sem.y" /* yacc.c:1646  */
    {gencodeAssignment();}
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 681 "sem.y" /* yacc.c:1646  */
    {array1();}
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 685 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],"*");}
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 685 "sem.y" /* yacc.c:1646  */
    {gencode();}
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 686 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],"/");}
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 686 "sem.y" /* yacc.c:1646  */
    {gencode();}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 691 "sem.y" /* yacc.c:1646  */
    {(yyval.str)=(yyvsp[-1].str);}
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 692 "sem.y" /* yacc.c:1646  */
    {strcpy(tokenstack[++top],"-");}
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 692 "sem.y" /* yacc.c:1646  */
    {gencodeUnaryMinus();}
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 693 "sem.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));fl=1;}
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 694 "sem.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2392 "y.tab.c" /* yacc.c:1646  */
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
#line 696 "sem.y" /* yacc.c:1906  */


#include "lex.yy.c"
#include<ctype.h>
int main(int argc, char *argv[])
{
	yyin =fopen(argv[1],"r");
	yyparse();
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
void yyerror(char *s)
{
	printf("\nLine %d : %s %s\n",yylineno,s,yytext);
}
int printline()
{
	return yylineno;
}
