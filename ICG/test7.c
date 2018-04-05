#include <stdio.h>

void sum(int a, int b)
{
    int c=0;
    c = 1;
    while(a>7)
    {
      b=6;
      while(b>=5)
      {
        a=9;
      }
    }
    return;
}

int main ( )
{
  int a=5;
	int b=6;
  while(a>7)
  {
    b=6;
    while(b>=5)
    {
      a=9;
    }
  }
	sum(a,b);
  return 0;
}
