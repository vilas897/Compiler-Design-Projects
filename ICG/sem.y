%{
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

%token WHILE IF RETURN STRING PRINT FUNCTION ARRAY ELSE
%left LE GE EQ NEQ AND OR '<' '>'
%right '='
%left '+' '-'
%left '*' '/'
%type<str> ID NUM REAL LE GE EQ NEQ AND OR assignment secondary_assignment constant '=' '+' '-' '*' '/' expression additive_exp multiplicative_exp
%type<ival> INT FLOAT VOID Type

int mem_address = 100,i=1,type=258,fname[100], nP, fTypes[100], fTypes2[100],temptype,it,stack[100],stackindex=0,end[100],returnArr[10],returnCount,c,b,fl,top=0,label[20],label_index=0,ltop=0,n=0,returnArr[10],iter=0;;
char tokenstack[100][10],i_[2]="0",temp[2]="t", null[2]=" ";
float t[100];

void yyerror(char *s);
int printline();

struct symbol
{
	int num;
	char token[100];
	int type[100];
	int typenum;
	int addr;
	float fvalue;
	int scope;
	int arrFlag;
	int fType[100];
	int numParams;
}st[100];

void blockBegin()
{
	stack[stackindex]=i;
	i++;
	stackindex++;
	return;
}

void blockEnd()
{
	stackindex--;
	end[stack[stackindex]]=1;
	stack[stackindex]=0;
	return;
}

int returntype_func(int returnCount)
{
	return returnArr[returnCount-1];
}

void insertFunc(char *name, int type, int addr, int arrFlag, int params[100], int numParams)
{
	int i;
	if(lookup(name))
	{
		strcpy(st[n].token,name);
		st[n].typenum=1;
		st[n].type[st[n].typenum-1]=type;
		st[n].addr=addr;
		st[n].num=n+1;
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
				st[i].typenum++;
				st[i].type[st[i].typenum-1]=type;
				break;
			}
		}
	}

	return;
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


void pushReturnType( int returnCount, int returntype )
{
	returnArr[returnCount] = returntype;
	return;
}

void addScope(char *a,int scope)
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

int getScope(char *a,int cs)
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
			for(k=0;k<st[i].typenum;k++)
			{
				if(st[i].type[k]==258)
					st[i].fvalue=(int)temp;
				else
					st[i].fvalue=temp;
			}
		}
	}
}

void insertTable(char *name, int type, int addr, int arrFlag)
	{
		int i;
		if(lookup(name))
		{
			strcpy(st[n].token,name);
			st[n].typenum=1;
			st[n].type[st[n].typenum-1]=type;
			st[n].addr=addr;
			st[n].num=n+1;
			st[n].arrFlag = arrFlag;
			n++;
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(!strcmp(name,st[i].token))
				{
					st[i].typenum++;
					st[i].type[st[i].typenum-1]=type;
					break;
				}
			}
		}

		return;
	}

void printTable()
{
	int i,j;
	printf("\nSymbol Table\n\n");
	printf("\nSNo.\tToken\tAddress\tValue\tScope\tIsArray\tType\tParams\n");
	for(i=0;i<n;i++)
	{
		if(st[i].type[0]==258 || st[i].type[0]==261|| st[i].type[0]==262|| st[i].type[0]==263)
			printf("%d\t%s\t%d\t%d\t%d\t%d",st[i].num,st[i].token,st[i].addr,(int)st[i].fvalue,st[i].scope, st[i].arrFlag);
		else
			printf("%d\t%s\t%d\t%.1f\t%d\t%d",st[i].num,st[i].token,st[i].addr,st[i].fvalue,st[i].scope, st[i].arrFlag);
		for(j=0;j<st[i].typenum;j++)
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

void dummy_if1()
{
	label_index++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = not %s\n",temp,tokenstack[top]);
 	printf("if %s goto L%d\n",temp,label_index);
	i_[0]++;
	label[++ltop]=label_index;
}

void dummy_if2()
{
	label_index++;
	printf("goto L%d\n",label_index);
	printf("L%d: \n",label[ltop--]);
	label[++ltop]=label_index;
}

void dummy_if3()
{
	printf("L%d:\n",label[ltop--]);
}

void insertDuplicate(char *name, int type, int addr,int currScope)
{
	strcpy(st[n].token,name);
	st[n].typenum=1;
	st[n].type[st[n].typenum-1]=type;
	st[n].addr=addr;
	st[n].num=n+1;
	st[n].scope=currScope;
	n++;
	return;
}

void dummy_w1()
{
	label_index++;
	label[++ltop]=label_index;
	printf("L%d:\n",label_index);
}

void dummy_w2()
{
	label_index++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = not %s\n",temp,tokenstack[top--]);
 	printf("if %s goto L%d\n",temp,label_index);
	i_[0]++;
	label[++ltop]=label_index;
}

void dummy_w3()
{
	int y=label[ltop--];
	printf("goto L%d\n",label[ltop--]);
	printf("L%d:\n",y);
}

void push(char *a)
{
	strcpy(tokenstack[++top],a);
}

void dummy_arr1()
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

void gencodeAssignment()
{
	printf("%s = %s\n",tokenstack[top-2],tokenstack[top]);
	top-=2;
}

%}
%%

block_statement
 	: '{' statement_list '}'
	;

statement_list
 	: statement_list statement
	|
	;

statement
 	: declaration_statement
	| if_statement
	| block_statement
	| function_call
	| ID '(' ')' ';'
	| while_statement
	| return_statement
	| ';'
	| PRINT '(' STRING ')' ';'
	;

return_statement
	: RETURN constant ';' {
					if(!(strspn($2,"0123456789")==strlen($2)))
						pushReturnType(returnCount,FLOAT);
					else
						pushReturnType(returnCount,INT); returnCount++;
					}
	| RETURN ';' {pushReturnType(returnCount,VOID); returnCount++;}
	;

function_call
	: ID '(' call_list ')' ';' {
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

call_list
	: ID { printf("Push Param %s\n", $1); temptype = returntype($1, stack[stackindex-1]); it = 0; fTypes2[it] = temptype; }
	| constant {  printf("Push Param %s\n", $1); temptype = temp; it = 0; fTypes2[it] = temptype; }
	| call_list ',' ID {  printf("Push Param %s\n", $3); it++; temptype = returntype($3, stack[stackindex-1]); fTypes2[it] = temptype;}
	| call_list ',' constant {  printf("Push Param %s\n", $3); temptype = temp; it++; fTypes2[it] = temptype;}
	;

if_statement
 	: 	 IF '(' expression ')' {dummy_if1();} block_statement {dummy_if2();} else
	;

else
 	: ELSE block_statement {dummy_if3();}
	|
	;

start
 	: function_dec start
	| declaration_statement start
	|
	;

function_dec
	: Type ID  '(' ')'  { printf("\nfunction begin %s:\n", $2); } block_statement {

	if ($1!=returntype_func(returnCount))
	{
		printf("\nError : Type mismatch : Line %d\n",printline());
	}

	if (!(strcmp($2,"printf") && strcmp($2,"scanf") && strcmp($2,"getc") && strcmp($2,"gets") && strcmp($2,"getchar") && strcmp	($2,"puts") && strcmp($2,"putchar") && strcmp($2,"clearerr") && strcmp($2,"getw") && strcmp($2,"putw") && strcmp($2,"putc") && strcmp($2,"rewind") && strcmp($2,"sprint") && strcmp($2,"sscanf") && strcmp($2,"remove") && strcmp($2,"fflush")))
		printf("Error : Type mismatch in redeclaration of %s : Line %d\n",$2,printline());
	else
	{
		insertTable($2,FUNCTION,mem_address, 0);
		insertTable($2,$1,mem_address, 0);
		mem_address+=4;
	}
	printf("function end\n\n");
	}
	| Type ID '(' param_list ')'   { printf("\nfunction begin %s:\n", $2); } block_statement {

	if ($1!=returntype_func(returnCount))
	{
		printf("\nError : Type mismatch : Line %d %d %d\n",printline(), $1, returntype_func(returnCount));
	}

	if (!(strcmp($2,"printf") && strcmp($2,"scanf") && strcmp($2,"getc") && strcmp($2,"gets") && strcmp($2,"getchar") && strcmp	($2,"puts") && strcmp($2,"putchar") && strcmp($2,"clearerr") && strcmp($2,"getw") && strcmp($2,"putw") && strcmp($2,"putc") && strcmp($2,"rewind") && strcmp($2,"sprint") && strcmp($2,"sscanf") && strcmp($2,"remove") && strcmp($2,"fflush")))
		printf("Error : Type mismatch in redeclaration of %s : Line %d\n",$2,printline());
	else
	{
		insertFunc($2,FUNCTION,mem_address, 0, fname, nP);
		insertTable($2,$1,mem_address, 0);
		mem_address+=4;
	}
	printf("function end\n\n");
	};

param_list
	: Type ID
	{
		int scope=stack[stackindex-1];
		insertTable($2,$1,mem_address, 0);
		addScope($2,scope+1);
		mem_address+=4; nP = 1; fname[nP-1] = $1;
	}
	| param_list ',' Type ID
	{   int scope=stack[stackindex-1];
		insertTable($4,$3,mem_address, 0);
		addScope($4,scope+1);
		mem_address+=4;
		nP++; fname[nP-1] = $3;
	};

Type
 	: INT
	| FLOAT
	| VOID
	;

expression
   : expression '+'{strcpy(tokenstack[++top],"+");} additive_exp{gencode();}
   | expression '-'{strcpy(tokenstack[++top],"-");} additive_exp{gencode();}
   | additive_exp
   | ID {push($1);} '<' {strcpy(tokenstack[++top],"<");} expression {gencode();}
   | ID {push($1);} '>' {strcpy(tokenstack[++top],">");} expression {gencode();}
   | ID {push($1);} '=' {strcpy(tokenstack[++top],"||");} expression {gencodeAssignment();}
   | array {dummy_arr1();}
   ;

additive_exp
   : additive_exp '*'{strcpy(tokenstack[++top],"*");} multiplicative_exp{gencode();}
   | additive_exp '/'{strcpy(tokenstack[++top],"/");} multiplicative_exp{gencode();}
   | multiplicative_exp
   ;

multiplicative_exp
 	 : '(' expression ')' {$$=$2;}
   | ID {push($1);fl=1;}
   | constant {push($1);}
   ;


while_statement
 	: WHILE {dummy_w1();}'(' expression')' {dummy_w2();} block_statement {dummy_w3();}
	;

assignment
 	: ID '=' constant
	| ID '+' assignment
	| ID ',' assignment
	| constant ',' assignment
	| ID
	| constant
	;

secondary_assignment
 	: ID {push($1);} '=' {strcpy(tokenstack[++top],"=");} expression{gencodeAssignment();}
		{
		int currScopeId=getScope($1,stack[stackindex-1]);
		int type=getReturnType($1,currScopeId);
		if((!(strspn($5,"0123456789")==strlen($5))) && type==258 && fl==0)
			printf("\nError : Type Mismatch : Line %d\n",printline());
		if(!lookup($1))
		{
		int currscope=stack[stackindex-1];
		int scope=getScope($1,currscope);
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
	| constant ',' secondary_assignment
	| ID  {
		if(lookup($1))
			printf("\nUndeclared Variable %s : Line %d\n",$1,printline());
		}
	| constant
	;

constant
 	: NUM
	| REAL
	;

declaration_statement
	: Type ID '[' assignment ']' ';' {
						insertTable($2,ARRAY,mem_address, 1);
						insertTable($2,$1,mem_address, 0);
						mem_address+=4;
					}
	| ID '[' secondary_assignment ']' ';'
	| Type ID {push($2);} '=' {strcpy(tokenstack[++top],"=");} expression{gencodeAssignment();} ';'
		{
			if( (!(strspn($6,"0123456789")==strlen($6))) && $1==258 && (fl==0))
			{
				printf("\nError : Type Mismatch : Line %d\n",printline());
				fl=1;
			}
			if(!lookup($2))
			{
				int currscope=stack[stackindex-1];
				int previous_scope=getScope($2,currscope);
				if(currscope==previous_scope)
					printf("\nError : Redeclaration of %s : Line %d\n",$2,printline());
				else
				{
					insertDuplicate($2,$1,mem_address,currscope);
					updateVal($2,$6,stack[stackindex-1]);
					int sg=getScope($2,stack[stackindex-1]);
					mem_address+=4;
				}
			}
			else
			{
				int scope=stack[stackindex-1];
				insertTable($2,$1,mem_address, 0);
				addScope($2,scope);
				updateVal($2,$6,stack[stackindex-1]);
				mem_address+=4;
			}
		}
	| secondary_assignment ';'  {
				if(!lookup($1))
				{
					int currscope=stack[stackindex-1];
					int scope=getScope($1,currscope);
					if(!(scope<=currscope && end[scope]==0) || scope==0)
						printf("\nError : Variable %s out of scope : Line %d\n",$1,printline());
				}
				else
					printf("\nError : Undeclared Variable %s : Line %d\n",$1,printline());
				}
	;

array
 	: ID {push($1);}'[' expression']'
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
		printTable();
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
