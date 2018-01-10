%{
  int yylineno;

//Keywords
  #define WHILE 1
  #define VOID 2
  #define RETURN 3
  #define MAINFUNC 4
  #define BREAK 5
  #define CONTINUE 7
  #define IF 8

// Datatypes
  #define SI 10
  	//short int
  #define USI 11
  	//unsigned short int
  #define UI 12
  	//unsigned int
  #define INT 13
  	//int
  #define LI 14
  	//long int
  #define ULI 15
  	//unsigned long int
  #define CHAR 16
  	//char
  #define SC 17
  	//signed char
  #define UC 18
  	//unsigned char

//Identifier and Constant
  #define ID 20
  #define CONST 21

//Operators
//Comparators
  #define LE 22
  	// Less than
  #define GE 23
  	// Greater than
  #define EQ 24
  	// Check for equality
  #define NE 25
  	// Not equal to check
  #define L 29
  #define G 30

//Logical
  #define OR 26
  #define AND 27
  #define NOT 28

//Assignment
  #define ASS 29
  	//   =	Simple assignment operator.
  #define ADDASS 30
  	// +=	Add AND assignment operator.
  #define SUBASS 31
  	// -=	Subtract AND assignment operator.
  #define MULASS 32
  	// *=	Multiply AND assignment operator.
  #define DIVASS 33
 	// /=	Divide AND assignment operator.
  #define MODASS 34
  	//	%=	Modulus AND assignment operator.

//Arithmetic
  #define PLUS 35
  #define SUB 36
  #define MULT 37
  #define DIV 38
  #define MOD 39
  #define PP 40
  	// ++
  #define MM 41
  	// --

//Binary Ops
  #define BA 42
  	// Binary and
  #define BO 43
  	// Binary or
  #define BC 44
  	// Binary complement
  #define OC 45
	//one's complement
  #define LS 46
    // left shift
  #define RS 47
    //right shift

//Format Specifiers
  #define FI 48
  	// %d
  #define FUI 49
  	// %u
  #define FLI 50
  	// %ld
  #define FC 51
  	// %c
  #define FLUI 52
  	// %lu

// Miscelaneous tokens
  #define SEMICOLON 53
  #define BA1 54
  	// '(' bracket
  #define BA2 55
  	// ')' bracket
  #define BB1 56
  	// '[' bracket
  #define BB2 57
  	// ']' bracket
  #define BC1 58
  	// '{' bracket
  #define BC2 59
  	//'}' bracket
  #define COMMA 60
  	// ','
  #define Q 61
  	// Quote "
  #define SQ 62
  	// Single Quote '
  #define HEAD 63
  	// Header file
  #define ARR 64
	// Array
  #define SLC 65
	// Single comment '/'
  #define MLCO 66
  	// Multiline Comment Open '/*'
  #define MLCC 67
  	// Multilien Comment Close '*/'
  #define DEF 68
    // Macro
  #define PRINTF 69
  #define SCANF 70
  #define FUNC 71
%}

  alpha [A-Z|a-z]
  digit [0-9]
  und [_]
  space [ ]

%%
  \n	{yylineno++;}
  "main[ ]*(void)" return MAINFUNC;
  "main[ ]*()" return MAINFUNC;
  "main[ ]*(int argc, char **argv)" return MAINFUNC;
  "main[ ]*(int argc, char *argv[])" return MAINFUNC;
  "return"	return RETURN;
  void return VOID;
  break	return BREAK;
  if return IF;
  while return WHILE;
  printf return PRINTF;
  continue return CONTINUE;
  scanf return SCANF;
// Header files
  "#include[ ]*<{alpha}{alpha}*\.h>" return HEAD;
// Macros
  "#define {alpha}({alpha}|{digit}|{und})* {digit}+" return DEF;
  "#define {alpha}({alpha}|{digit}|{und})* ({digit}+)\.({digit}+)" return DEF;
  "#define {alpha}({alpha}|{digit}|{und})* {alpha}({alpha}|{digit}|{und})*" return DEF;

  {alpha}({alpha}|{digit}|{und})*    return ID;
  {alpha}({alpha}|{digit}|{und})*\[{digit}*\] return ARR;
  {digit}+    return CONST;
  ({digit}+)\.({digit}+) return CONST;

// comparators
  "<=" return LE;
  ">=" return GE;
  "==" return EQ;
  "!=" return NE;
  ">" return G;
  "<" return L;

// logical operators
  "||" return OR;
  "&&" return AND;
  "!" return NOT;

// Datatypes
  "short int" return SI;
  "unsigned short int" return USI;
  "unsigned int" return UI;
  "int" return INT;
  "long int" return LI;
  "unsigned long int" return ULI;
  "char" return CHAR;
  "signed char" return SC;
  "unsigned char" return UC;

//Assignment
  "=" return ASS;
	//  =	Simple assignment operator.
  "+=" return ADDASS;
  	// +=	Add AND assignment operator.
  "-=" return SUBASS;
  	// -=	Subtract AND assignment operator.
  "*=" return MULASS;
  	// *=	Multiply AND assignment operator.
  "/=" return DIVASS;
 	// /=	Divide AND assignment operator.
  "%=" return MODASS;
  	//	%=	Modulus AND assignment operator.

// Arithmetic operators
  "+" return PLUS;
  "-" return SUB;
  "*" return MULT;
  "/" return DIV;
  "%" return MOD;
  "++" return PP;
  "--" return MM;

//Format Specifiers
  "%d" return FI;
  "%u" return FUI;
  "%ld" return FLI;
  "%c" return FC;
  "%lu" return FLUI;

//Binary Ops
  "&" return BA;
  	// Binary and
  "|" return BO;
  	// Binary or
  "!" return BC;
  	// Binary complement
  "~" return OC;
	//one's complement
  "<<" return LS;
    // left shift
  ">>" return RS;
    //right shift

// Comments
  "//" return SLC;
  "/*" return MLCO;
  "*/" return MLCC;

// Miscellaneous
  ";" return SEMICOLON;
  "(" return BA1
  ')' return BA2;
  "[" return BB1;
  ']' return BB2;
  "{" return BC1
  '}' return BC2;
  ',' return COMMA;
  "\"" return Q;
  "'" return SQ;
  printf return PRINTF;
  scanf return SCANF;
%%

struct symbol
{
	char token[100];
	char type[100];
	int typeno;
}symbolTable[100000];

int main(void)
{
  int newToken, // The current token being processed
      tokenType, //Whether token is Keyword, Operators etc
      tokenTypeCount[20]={0}, //Number of tokens of that particular type
      i=0, // Number of symbols in the symbol table
      j,k, // Iterators
      ba_c=0,ba_o=0,ba_l, // Number of open and close paranthesis, last line where the open parantesis was used
      bb_o=0,bb_c=0,bb_l, // Number of open and close square braces,  last line where the open sqaure brace was used
      bc_o=0,bc_c=0,bc_l, // Number of open and close curly braces,  last line where the open curly brace was used
      quoteLine=0, // Last place where quote was used
      quoteCount=0, // Number of double quotes
      rep=0; // Flag to denote whether the current token is already in symbol table

  //Taking the input program
  yyin= fopen("test.c","r");

  //Reading a single token from the program
  newToken = yylex();
  printf("\n");

  int mlc=0, // Flag to denote whether current token is part of a multiline comment
      slcline=0, // Line number of the single line comment
      mlcline; // Starting line number of multi line comment

  while(newToken)
  {
    rep = 0;

    if(yylineno==slcline) // If token belongs to a single line comment, ignore all the tokens
    {
      newToken=yylex();
      continue;
    }

    for(k=0;k<i;k++) // Checking whether token already exists is symbol table
    {
      if(!(strcmp(symbolTable[k].token,yytext)))
      {
        rep = 1;
        break;
      }
    }

    if(yylineno!=quoteLine && quoteLine != 0)
    {
      if(quoteCount%2 != 0)
        printf("\n-------------ERROR : INCOMPLETE STRING at Line %d------------------\n",quoteLine);
      quoteCount=0;
    }

    if(ba_c > ba_o)
      printf("\n-------------ERROR : UNMATCHED ')' at Line %d------------------\n", yylineno);

    if(bb_c>bb_o)
      printf("\n-------------ERROR : UNMATCHED '}' at Line %d------------------\n", yylineno);

    if(bc_c>bc_o)
      printf("\n-------------ERROR : UNMATCHED ']' at Line %d------------------\n", yylineno);

    if(rep==0 && newToken!=65 && newToken!=66 && newToken!=67 && mlc==0 && quoteCount%2==0)
    {
      strcpy(symbolTable[i].token,yytext);
    }

    if(((newToken>=1 && newToken<=8)) && mlc==0) // Keywords
    {
      if(rep==0 && quoteCount%2==0)
      {
        tokenType=0;
        strcpy(symbolTable[i].type,"KEYWORD");
      }
      printf("%s\t\tKeyword----------Line %d\n",yytext,yylineno);
    }

    else if(newToken==12 && mlc==0) // Identifiers
    {
      if(rep==0 && quoteCount%2==0)
      {
        tokenType=1;
        strcpy(symbolTable[i].type,"ID");
      }
      printf("%s\t\tIdentifier----------Line %d\n",yytext,yylineno);
    }

    else if(newToken==13 && mlc==0)
    {
      if(rep==0 && quoteCount%2==0)
      {
        tokenType=2;
        strcpy(symbolTable[i].type,"CONSTANT");
      }
      printf("%s\t\tConstant----------Line %d\n",yytext,yylineno);
    }

    else if(newToken>=14 && newToken<=32 && mlc==0)
    {
      if(rep==0 && quoteCount%2==0)
      {
        tokenType=3;
        strcpy(symbolTable[i].type,"OPERATOR");
      }
      printf("%s\t\tOperator----------Line %d\n",yytext,yylineno);
    }

    else if(newToken>=33 && newToken<=41 && mlc==0)
    {
      if(newToken==41)
      {
        quoteCount++;
        quoteLine=yylineno;
      }
      if(newToken==34)
        ba_o++;
      if(newToken==35)
        ba_c++;
      if(newToken==36)
        bb_o++;
      if(newToken==37)
        bb_c++;
      if(newToken==38)
        bc_o++;
      if(newToken==39)
        bc_c++;
      if(rep==0 && quoteCount%2==0)
      {
        tokenType=4;
        strcpy(symbolTable[i].type,"SPECIAL CHAR");
      }
      printf("%s\t\tSpecial Character----------Line %d\n",yytext,yylineno);
    }

    else if(newToken==42 && mlc==0)
    {
      if(rep==0 && quoteCount%2==0)
      {
        tokenType=5;
        strcpy(symbolTable[i].type,"HEADER");
      }
      printf("%s\t\tHeader----------Line %d\n",yytext,yylineno);
    }

    else if(newToken>=43 && newToken<=44 && mlc==0)
    {
      if(rep==0 && quoteCount%2==0)
      {
        tokenType=6;
        strcpy(symbolTable[i].type,"FORMAT SPECIFIER");
      }
      printf("%s\t\tFormat Specifier----------Line %d\n",yytext,yylineno);
    }

    else if(newToken==47 && mlc==0)
    {
      if(rep==0 && quoteCount%2==0)
      {
        tokenType=7;
        strcpy(symbolTable[i].type,"ARRAY");
      }
      printf("%s\t\tArray----------Line %d\n",yytext,yylineno);
    }

    else if(newToken==48 && mlc==0)
    {
      tokenType=15;
      printf("%s\t\tSingle Line Comment----------Line %d\n",yytext,yylineno);
      slcline=yylineno;
    }

    else if(newToken==49)
    {
      mlc=1;
      printf("%s\t\tMulti Line Comment Start----------Line %d\n",yytext,yylineno);
      mlcline = yylineno;

    }

    else if(newToken==50 && mlc==1)
    {
      mlc=0;
      printf("%s\t\tMulti Line Comment End----------Line %d\n",yytext,yylineno);
      mlcline=0;
    }

    else if(newToken==50 && mlc==0)
      printf("\n---------------ERROR : UNMATCHED NESTED END COMMENT-------------\n");

    else if(newToken==51 && mlc==0)
    {
      if(rep==0 && quoteCount%2==0)
      {
        tokenType=8;
        strcpy(symbolTable[i].type,"Preprocessor Directive");
      }
      printf("%s\t\tPreprocessor Directive----------Line %d\n",yytext,yylineno);
    }

    else if(newToken>=52 && newToken<=53 && mlc==0)
    {
      if(rep==0 && quoteCount%2==0)
      {
        tokenType=9;
        strcpy(symbolTable[i].type,"Pre Defined Function");
      }
      printf("%s\t\tPre Defined Function----------Line %d\n",yytext,yylineno);
    }

    else if(newToken==54 && mlc==0)
    {
      if(rep==0 && quoteCount%2==0)
      {
        tokenType=10;
        strcpy(symbolTable[i].type,"User Defined Function");
      }
      printf("%s\t\tUser Defined Function----------Line %d\n",yytext,yylineno);
    }

    else if(newToken==55 && mlc==0)
    {
      if(rep==0 && quoteCount%2==0)
      {
        tokenType=11;
        strcpy(symbolTable[i].type,"Main Function");
      }
      printf("%s\t\tMain Function----------Line %d\n",yytext,yylineno);
    }

    if(rep==0 && newToken!=48 && newToken!=49 && newToken!=50 && mlc==0 && quoteCount%2==0)
    {
      tokenTypeCount[tokenType]++;
      symbolTable[i].typeno = tokenTypeCount[tokenType];
      i++;
    }
    newToken=yylex();
  }

  if(mlc==1)
    printf("\n--------------------ERROR : UNMATCHED COMMENT starting at Line %d------------\n",mlcline);

  if(ba_c!=ba_o)
    printf("\n--------------------ERROR : UNMATCHED '(' at Line %d ------------------------\n",ba_l);

  if(bb_c!=bb_o)
    printf("\n--------------------ERROR : UNMATCHED '{' at Line %d ------------------------\n",bb_l);

  if(bc_c!=bc_o)
    printf("\n--------------------ERROR ! UNMATCHED '[' at Line %d ------------------------\n",bc_l);

  printf("\n------------Symbol Table---------------------\n\nSNo\tToken\t\tAttribute\t\tMemory Location\n\n");

  for(j=0;j<i;j++)
    printf("%d\t%s\t\t< %s , %d >\t\t%d\n",symbolTable[j].sno,symbolTable[j].token,symbolTable[j].type,symbolTable[j].typeno,symbolTable[j].addr);

  return 0;
}

int yywrap(void)
{
	return 1;
}


























  
