#include<stdio.h>

int main()
{
	int a = 5;

	while(a>0)
	{
		printf("%d",a);
		a--;
		int b = 4;
		while(b>0)
		{
			printf("%d", a*b);
			b--;
		}
	}
}
