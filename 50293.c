#include <stdio.h>
#include <stdbool.h>
typedef struct group{
  int power;
  int num;
}Group;
 
void set_group(Group *gp, int power, int num)
{
  gp->power = power;
  gp->num = num;
  return;
}
bool compare(Group cur, Group max)
{
  if (cur.power * cur.num > max.power * max.num)
    return true;
  else if (cur.power * cur.num < max.power * max.num)
    return false;
  else
    if (cur.power < max.power)
      return true;
    else
      return false;
}
int read_int() 
{
  int x = 0;
  char ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch - '0'); // x * 10
    ch = getchar();
  }
  return x;
}
int main() 
{
  Group cur, max, first;
  int n;
  int new_power;
  n = read_int(); 
  new_power = read_int();
 
  first.power = new_power;
 
  // record the first group
  int index = 1;
  do {
    if (index >= n) {
      printf("%d %d\n", first.power, index);
      return 0;
    }
    index++;
  } while ((new_power = read_int()) >= 1 && new_power == first.power);
 
  set_group(&first, first.power, index - 1);
  set_group(&cur, new_power, 1);
  if (compare(cur, first))
    set_group(&max, new_power, cur.num);
  else
    set_group(&max, first.power, first.num);
 
  while (index < n) {
    new_power = read_int();
    if (new_power == cur.power)
      cur.num = cur.num + 1;
    else {
      if (compare(cur, max))
        set_group(&max, cur.power, cur.num);
      set_group(&cur, new_power, 1);
    }
    ++index;
  }
 
  if (cur.power == first.power)
    cur.num += first.num;
 
  if (compare(cur, max))
    set_group(&max, cur.power, cur.num);
 
  printf("%d %d\n", max.power, max.num);
  return 0;
}