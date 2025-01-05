#include <stdio.h>
 
int main()
{
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  printf("%d\n%d\n%d\n", ((a + b + c) >> 1) - a, ((a + b + c) >> 1) - b, ((a + b + c) >> 1) - c);
}