#include<stdio.h>
#define x 3

int main() 
{
    int a=4; 
    if(a<10) 
    {
	a=a+1;
	printf("\n%d\n",a); 
    }
    else 
    {
	a=a-2; 
    }
    return 0; 
}
