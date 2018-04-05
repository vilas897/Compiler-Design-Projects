%{
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

%}

%token<ival> INT FLOAT VOID
%token<str> ID NUM REAL LE GE EQ NEQ AND OR
%token WHILE IF RETURN PREPROC STRING PRINT FUNCTION DO ARRAY ELSE STRUCT STRUCT_VAR FOR
%left LE GE EQ NEQ AND OR '<' '>'
%right '='
%right UMINUS
%left '+' '-'
%left '*' '/'
%type<str> assignment secondary_assignment consttype '=' '+' '-' '*' '/' E T F
%type<ival> Type
%union {
		int ival;
		char *str;
	}
%%

start
 	: Function start
	| PREPROC start
	| Declaration start
	|
	;

	Function
		: Type ID  '(' ')'  { printf("\nfunction begin %s:\n", $2); } CompoundStmt {

		if ($1!=returntype_func(returnCount))
		{
			printf("\nError : Type mismatch : Line %d\n",printline());
		}

		if (!(strcmp($2,"printf") && strcmp($2,"scanf") && strcmp($2,"getc") && strcmp($2,"gets") && strcmp($2,"getchar") && strcmp	($2,"puts") && strcmp($2,"putchar") && strcmp($2,"clearerr") && strcmp($2,"getw") && strcmp($2,"putw") && strcmp($2,"putc") && strcmp($2,"rewind") && strcmp($2,"sprint") && strcmp($2,"sscanf") && strcmp($2,"remove") && strcmp($2,"fflush")))
			printf("Error : Type mismatch in redeclaration of %s : Line %d\n",$2,printline());
		else
		{
			insert($2,FUNCTION,g_addr, 0);
			insert($2,$1,g_addr, 0);
			g_addr+=4;
		}
		printf("function end\n\n");
		}
		| Type ID '(' param_list ')'   { printf("\nfunction begin %s:\n", $2); } CompoundStmt {

		if ($1!=returntype_func(returnCount))
		{
			printf("\nError : Type mismatch : Line %d %d %d\n",printline(), $1, returntype_func(returnCount));
		}

		if (!(strcmp($2,"printf") && strcmp($2,"scanf") && strcmp($2,"getc") && strcmp($2,"gets") && strcmp($2,"getchar") && strcmp	($2,"puts") && strcmp($2,"putchar") && strcmp($2,"clearerr") && strcmp($2,"getw") && strcmp($2,"putw") && strcmp($2,"putc") && strcmp($2,"rewind") && strcmp($2,"sprint") && strcmp($2,"sscanf") && strcmp($2,"remove") && strcmp($2,"fflush")))
			printf("Error : Type mismatch in redeclaration of %s : Line %d\n",$2,printline());
		else
		{
			insertFunc($2,FUNCTION,g_addr, 0, fname, nP);
			insert($2,$1,g_addr, 0);
			g_addr+=4;
		}
		printf("function end\n\n");
		};

	param_list: Type ID
	{
	int scope=stack[index1-1];
	insert($2,$1,g_addr, 0);
	insertscope($2,scope+1);
	g_addr+=4; nP = 1; fname[nP-1] = $1; }
	| param_list ',' Type ID { int scope=stack[index1-1];
	insert($4,$3,g_addr, 0);
	insertscope($4,scope+1);
	g_addr+=4;
	nP++; fname[nP-1] = $3; };

Type
 	: INT
	| FLOAT
	| VOID
	;

CompoundStmt
 	: '{' StmtList '}'
	;

StmtList
 	: StmtList stmt
	|
	;

stmt
 	: Declaration
	| if
	| ID '(' ')' ';'
	| while
	| RETURN consttype ';' {
					if(!(strspn($2,"0123456789")==strlen($2)))
						storereturn(returnCount,FLOAT);
					else
						storereturn(returnCount,INT); returnCount++;
					}
	| RETURN ';' {storereturn(returnCount,VOID); returnCount++;}
	| ';'
	| PRINT '(' STRING ')' ';'
	| CompoundStmt
	| function_call
	;

	function_call: ID '(' call_list ')' ';' {
		if(lookup($1))
			printf("\nError: Undeclared function %s : Line %d\n", $1, printline());
		else
		{
			if(retNumParams($1) == 0)
				printf("\nError : Parameter list does not match signature : Line %d\n", printline());
			getParams($1);
		}

		for(int j=0; j<retNumParams($1); j++)
		{
			if(fTypes[j] != fTypes2[j])
				printf("\nError : Parameter list does not match signature : Line %d\n", printline());
		}
		printf("call %s, %d\n", $1, it);
	}
	| ID '(' ')' ';' {
		if(lookup($1))
			printf("\nError: Undeclared function %s : Line %d\n", $1, printline());
		else
		{
			if(retNumParams($1) != 0)
				printf("\nError : Parameter list does not match signature : Line %d\n", printline());
		}
		printf("call %s, %d\n", $1, 0);
	};

	call_list : ID { printf("Push Param %s\n", $1); temptype = returntype($1, stack[index1-1]); it = 0; fTypes2[it] = temptype; }
		| consttype {  printf("Push Param %s\n", $1); temptype = temp; it = 0; fTypes2[it] = temptype; }
		| call_list ',' ID {  printf("Push Param %s\n", $3); it++; temptype = returntype($3, stack[index1-1]); fTypes2[it] = temptype;}
		| call_list ',' consttype {  printf("Push Param %s\n", $3); temptype = temp; it++; fTypes2[it] = temptype;}
		;

if
 	: 	 IF '(' E ')' {if1();} CompoundStmt {if2();} else
	;

else
 	: ELSE CompoundStmt {if3();}
	|
	;

while
 	: WHILE {w1();}'(' E ')' {w2();} CompoundStmt {w3();}
	;

assignment
 	: ID '=' consttype
	| ID '+' assignment
	| ID ',' assignment
	| consttype ',' assignment
	| ID
	| consttype
	;

secondary_assignment
 	: ID {push($1);} '=' {strcpy(tokenstack[++top],"=");} E {gencodeAssignment();}
		{
		int currScopeId=returnscope($1,stack[index1-1]);
		int type=getReturnType($1,currScopeId);
		if((!(strspn($5,"0123456789")==strlen($5))) && type==258 && fl==0)
			printf("\nError : Type Mismatch : Line %d\n",printline());
		if(!lookup($1))
		{
			int currscope=stack[index1-1];
			int scope=returnscope($1,currscope);
			if((scope<=currscope && end[scope]==0) && !(scope==0))
			{
				updateVal($1,$5,currscope);
			}
		}
		}
	| ID ',' secondary_assignment    {
					if(lookup($1))
						printf("\nUndeclared Variable %s : Line %d\n",$1,printline());
				}
	| consttype ',' secondary_assignment
	| ID  {
		if(lookup($1))
			printf("\nUndeclared Variable %s : Line %d\n",$1,printline());
		}
	| consttype
	;

consttype
 	: NUM
	| REAL
	;

Declaration
	: Type ID {push($2);} '=' {strcpy(tokenstack[++top],"=");} E {gencodeAssignment();} ';'
		{
			if( (!(strspn($6,"0123456789")==strlen($6))) && $1==258 && (fl==0))
			{
				printf("\nError : Type Mismatch : Line %d\n",printline());
				fl=1;
			}
			if(!lookup($2))
			{
				int currscope=stack[index1-1];
				int previous_scope=returnscope($2,currscope);
				if(currscope==previous_scope)
					printf("\nError : Redeclaration of %s : Line %d\n",$2,printline());
				else
				{
					insertDup($2,$1,g_addr,currscope);
					updateVal($2,$6,stack[index1-1]);
					int sg=returnscope($2,stack[index1-1]);
					g_addr+=4;
				}
			}
			else
			{
				int scope=stack[index1-1];
				insert($2,$1,g_addr, 0);
				insertscope($2,scope);
				updateVal($2,$6,stack[index1-1]);
				g_addr+=4;
			}
		}
	| secondary_assignment ';'  {
				if(!lookup($1))
				{
					int currscope=stack[index1-1];
					int scope=returnscope($1,currscope);
					if(!(scope<=currscope && end[scope]==0) || scope==0)
						printf("\nError : Variable %s out of scope : Line %d\n",$1,printline());
				}
				else
					printf("\nError : Undeclared Variable %s : Line %d\n",$1,printline());
				}
	| Type ID '[' assignment ']' ';' {
						insert($2,ARRAY,g_addr, 1);
						insert($2,$1,g_addr, 0);
						g_addr+=4;
					}
	| ID '[' secondary_assignment ']' ';'
	| error
	;

array
 	: ID {push($1);}'[' E ']'
	;

E
 	 : E '+'{strcpy(tokenstack[++top],"+");} T{gencode();}
   | E '-'{strcpy(tokenstack[++top],"-");} T{gencode();}
   | T
   | ID {push($1);} LE {strcpy(tokenstack[++top],"<=");} E {gencode();}
   | ID {push($1);} GE {strcpy(tokenstack[++top],">=");} E {gencode();}
   | ID {push($1);} EQ {strcpy(tokenstack[++top],"==");} E {gencode();}
   | ID {push($1);} NEQ {strcpy(tokenstack[++top],"!=");} E {gencode();}
   | ID {push($1);} AND {strcpy(tokenstack[++top],"&&");} E {gencode();}
   | ID {push($1);} OR {strcpy(tokenstack[++top],"||");} E {gencode();}
   | ID {push($1);} '<' {strcpy(tokenstack[++top],"<");} E {gencode();}
   | ID {push($1);} '>' {strcpy(tokenstack[++top],">");} E {gencode();}
   | ID {push($1);} '=' {strcpy(tokenstack[++top],"||");} E {gencodeAssignment();}
   | array {array1();}
   ;

T
 	 : T '*'{strcpy(tokenstack[++top],"*");} F{gencode();}
   | T '/'{strcpy(tokenstack[++top],"/");} F{gencode();}
   | F
   ;

F
 	 : '(' E ')' {$$=$2;}
   | '-'{strcpy(tokenstack[++top],"-");} F{gencodeUnaryMinus();} %prec UMINUS
   | ID {push($1);fl=1;}
   | consttype {push($1);}
   ;
%%

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
