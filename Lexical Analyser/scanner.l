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

struct row
{
	char token[100];
	char attr[100];
	int attrno;
}r[100000];

int main(void)
{
}

int yywrap(void)
{
	return 1;
}
