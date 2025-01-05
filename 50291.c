#include <stdio.h>
 
int main()
{
  int x1, x2, x3, y1, y2, y3;
 
  for (int i = 0; i < 2; ++i) {
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    int v = 3;
 
    if ((x1 ^ x2) < 0) ++v;
    if ((x1 ^ x3) < 0) ++v;
    if ((x3 ^ x2) < 0) ++v;
    if ((y1 ^ y2) < 0) ++v;
    if ((y1 ^ y3) < 0) ++v;
    if ((y3 ^ y2) < 0) ++v;
 
    if ((x1 ^ x2) < 0 && (y1 ^ y2) < 0 && x1 * y2 == x2 * y1) --v;
    if ((x1 ^ x3) < 0 && (y1 ^ y3) < 0 && x1 * y3 == x3 * y1) --v;
    if ((x3 ^ x2) < 0 && (y3 ^ y2) < 0 && x3 * y2 == x2 * y3) --v;
    printf("%d\n", v);
  }
  return 0;
}