%{
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
%}

%token<ival> INT FLOAT VOID UNSIGNED_INT S_INT L_INT
%token<str> ID INT_CONST FLOAT_CONST
%token WHILE IF RETURN PREPROC LE STRING PRINT FUNCTION ARRAY ELSE
%right '='

%type<str> secondary_assignment consttype assignment_exp
%type<ival> Type

%union {
		int ival;
		char *str;
	}

%%

start : Function start
	| PREPROC start
	| Declaration start
	|
	;

Function
	: Type ID '('')' compound_stmt {
	if ($1!=returntype_func(curr_type))
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
	};

Type
	: INT
	| FLOAT
	| VOID
  | UNSIGNED_INT
  | S_INT
  | L_INT
	;

compound_stmt
	: '{' statement_list '}'
	;

statement_list
	: statement_list stmt
	| compound_stmt
	|
	;

stmt
	: Declaration
	| if_stmt
	| while_stmt
	| RETURN consttype ';' {
					if(!(strspn($2,"0123456789")==strlen($2)))
						storereturn(curr_type,FLOAT);
					else
						storereturn(curr_type,INT); curr_type++;
				}
	| RETURN ';' {storereturn(curr_type,VOID); curr_type++;}
	| ';'
	| PRINT '(' STRING ',' exp ')' ';'
	| compound_stmt
	;

if_stmt
	: IF '(' expr1 ')' compound_stmt
	| IF '(' expr1 ')' compound_stmt ELSE compound_stmt
	;

while_stmt
	: WHILE '(' expr1 ')' compound_stmt
	;

expr1
	: expr1 LE expr1
	| secondary_assignment
	;

secondary_assignment : ID '=' secondary_assignment
	{
	  c=0;
		int scope_curr=returnscope($1,stack[index1-1]);
		//printf("Scope: %d",scope_curr);
		int type=returntype($1,scope_curr);
		if((!(strspn($3,"0123456789")==strlen($3))) && type==258)
			printf("\nError : Type Mismatch : Line %d\n",printline());
		if(!lookup($1))
		{
			int currscope=stack[index1-1];
			int scope=returnscope($1,currscope);
			if((scope<=currscope && end[scope]==0) && !(scope==0))
				update_value($1,$3,currscope);
		}
		if(isArray($1))
				printf("\nError: Array Identfier has no subscript: Line %d\n", printline());

		}

	| ID ',' secondary_assignment    {
					if(lookup($1))
						printf("\nUndeclared Variable %s : Line %d\n",$1,printline());

						if(isArray($1))
								printf("\nError: Array identfier has no subscript: Line %d\n", printline());

				}
	| assignment_exp
	| consttype ',' secondary_assignment
	| ID  {
		if(lookup($1))
			printf("\nUndeclared Variable %s : Line %d\n",$1,printline());

			if(isArray($1))
				printf("\nError: Non-array variable used as an array: Line %d\n", printline());

		}
	| exp
	| consttype
	;

assignment_exp :  ID '[' INT_CONST ']' '=' exp {
			if(lookup($1))
				printf("\nUndeclared Variable %s : Line %d\n",$1,printline());

			if(isArray($1)==0)
				printf("\nError: Non-array variable used as an array: Line %d\n", printline());

				float bound = isArray($1);

				if(isArray($1) && (atoi($3) >= bound || atoi($3) < 0))
					printf("\nError: Array subscript out of bounds : Line %d\n", printline());

		}
		;

exp : ID {
	if(isArray($1))
	 printf("\nError: Array identifier has no subscript: Line %d\n", printline());

	if(c==0)
	{
		c=1;
		int scope_curr=returnscope($1,stack[index1-1]);
		b=returntype($1,scope_curr);
	}
	else
	{
		int scope_curr1=returnscope($1,stack[index1-1]);
		if(b!=returntype($1,scope_curr1))
			printf("\nError : Type Mismatch : Line %d\n",printline());
	}
	if(!lookup($1))
	{
		int currscope=stack[index1-1];
		//printf("\ncurrscope%d Current Scope: %d\n", currscope, stack[index1-1]);
		int scope=returnscope($1,currscope);
		//printf("Curr scope: %d %d\n", currscope,scope);
		if(!(scope<=currscope && end[scope]==0))
			printf("\nError : Variable %s out of scope : Line %d\n",$1,printline());
	}
  else
    printf("\nError : Undeclared Variable %s : Line %d\n",$1,printline());
	}
	| ID '[' INT_CONST ']'{
		if(c==0)
		{
			c=1;
			int scope_curr=returnscope($1,stack[index1-1]);
			b=returntype($1,scope_curr);
		}
		else
		{
			int scope_curr1=returnscope($1,stack[index1-1]);
			if(b!=returntype($1,scope_curr1))
				printf("\nError : Type Mismatch : Line %d\n",printline());
		}
		if(!lookup($1))
		{
			int currscope=stack[index1-1];
			//printf("\ncurrscope%d Current Scope: %d\n", currscope, stack[index1-1]);
			int scope=returnscope($1,currscope);
			//printf("Curr scope: %d %d\n", currscope,scope);
			if(!(scope<=currscope && end[scope]==0))
				printf("\nError : Variable %s out of scope : Line %d\n",$1,printline());
		}
	  else
	    printf("\nError : Undeclared Variable %s : Line %d\n",$1,printline());

		if(isArray($1)==0)
			printf("\nError: Non-array variable used as an array: Line %d\n", printline());

		float bound = isArray($1);

		if(isArray($1) && (atoi($3) >= bound || atoi($3) < 0) )
			printf("\nError: Array subscript out of bounds : Line %d\n", printline());

		}
	| exp '+' exp
	| exp '-' exp
	| exp '*' exp
	| exp '/' exp
	| '(' exp '+' exp ')'
	| '(' exp '-' exp ')'
	| '(' exp '*' exp ')'
	| '(' exp '/' exp ')'
	| consttype
	| '(' exp ')'
	;

consttype : INT_CONST
	| FLOAT_CONST
	;

Declaration
	: Type ID '=' consttype ';'
		{
			if( (!(strspn($4,"0123456789")==strlen($4))) && $1==258)
				printf("\nError : Type Mismatch : Line %d\n",printline());

			if(!lookup($2))
			{
				int currscope=stack[index1-1];
				int previous_scope=returnscope($2,currscope);
				if(currscope==previous_scope)
					printf("\nError : Redeclaration of %s : Line %d\n",$2,printline());
				else
				{
					insert_dup($2,$1,g_addr,currscope, 0);
					update_value($2,$4,stack[index1-1]);
					g_addr+=4;
				}
			}
			else
			{
				int scope=stack[index1-1];
				insert($2,$1,g_addr, 0);
				insertscope($2,scope);
				update_value($2,$4,stack[index1-1]);
				g_addr+=4;
			}
		}
	| Type ID ';' {
		if(!lookup($2))
		{
			int currscope=stack[index1-1];
			int previous_scope=returnscope($2,currscope);
			if(currscope==previous_scope)
				printf("\nError : Redeclaration of %s : Line %d\n",$2,printline());
			else
			{
				insert_dup($2,$1,g_addr,currscope, 0);
				g_addr+=4;
			}
		}
		else
		{
			int scope=stack[index1-1];
			insert($2,$1,g_addr, 0);
			insertscope($2,scope);
			g_addr+=4;
		}
	}
	| secondary_assignment ';'  {
				if(!lookup($1))
				{
					int currscope=stack[index1-1];
					//printf("\ncurrscope%d Current Scope: %d\n", currscope, stack[index1-1]);
					int scope=returnscope($1,currscope);
					//printf("Curr scope: %d %d\n", currscope,scope);
					if(!(scope<=currscope && end[scope]==0))
						printf("\nError : Variable %s out of scope : Line %d\n",$1,printline());
				}
				else
					printf("\nError : Undeclared Variable %s : Line %d\n",$1,printline());
				}

	| Type ID '[' INT_CONST ']' ';' {
						insert($2,ARRAY,g_addr,1);
						insert($2,$1,g_addr,1);
						update_value($2,$4,stack[index1-1]);
						g_addr+=4;
						if(atoi($4)<=0)
						{
							printf("\nError: Illegal array subscript %d : Line %d\n", atoi($4), printline());
						}
					}
	| error
	;

%%

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
