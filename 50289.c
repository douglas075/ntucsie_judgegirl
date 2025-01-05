#include <stdio.h>
 
int main()
{
  int W, L, w, l;
  scanf("%d%d%d%d", &W, &L, &w, &l);
  int num = (W / w) * (L / l);
  printf("%d\n", num);
  printf("%d\n", W * L - num * w * l);
  return 0;
}