#include <stdio.h>
int read()
{
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') 
  {  
    if (ch == '-') w = -1;        
    ch = getchar();               
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0'); 
    ch = getchar();  
  }
  return x * w; 
}
int write(int x)
{
  if (x < 0) 
  {
    x = -x;
    putchar('-');
  }
  if (x > 9) 
    write(x / 10);  
  putchar(x % 10 + '0');
}
int max(int a, int b) { return (a > b)? a : b ;}
int min(int a, int b) { return (a > b)? b : a ;}
int d1(int minx, int miny, int maxx, int maxy)
{
  // prerequisite x > 0 and y > 0
  if (maxx <= 0 || maxy <= 0)
    return 0;    
  int x = max(minx, 0);
  int y = max(miny, 0);
  return (maxx - x) * (maxy - y);
}
int d2(int minx, int miny, int maxx, int maxy)
{
  // x < 0 and y > 0
  if (minx >= 0 || maxy <= 0)
    return 0;    
  int x = min(maxx, 0);
  int y = max(miny, 0);
  return (x - minx) * (maxy - y);
}
int d3(int minx, int miny, int maxx, int maxy)
{
  // x < 0 and y < 0
  if (minx >= 0 || miny >= 0)
    return 0;    
  int x = min(maxx, 0);
  int y = min(maxy, 0);
  return (x - minx) * (y - miny);
}
int d4(int minx, int miny, int maxx, int maxy)
{
  // x > 0 and y < 0
  if (maxx <= 0 || miny >= 0)
    return 0;    
  int x = max(minx, 0);
  int y = min(maxy, 0);
  return (maxx - x) * (y - miny);
}
int main()
{
  int minx = read();
  int miny = read();
  int maxx = read();
  int maxy = read();
  // scanf("%d%d%d%d", &minx, &miny, &maxx, &maxy);
 
 
  write(d1(minx, miny, maxx, maxy));
  putchar('\n');
  write(d2(minx, miny, maxx, maxy));
  putchar('\n');
  write(d3(minx, miny, maxx, maxy));
  putchar('\n');
  write(d4(minx, miny, maxx, maxy));
  putchar('\n');
 
  return 0;
}