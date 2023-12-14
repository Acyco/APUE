#include <stdio.h>
#include <stdlib.h>

/* 位域 */


union
{
  struct {
      char a:1;
      char b:2;
      char c:1;
  } x;
  char y;
} w;

int main()
{
    w.y = 1;
    printf("%d\n", w.x.a);
    w.y = 6;
    printf("%d\n", w.x.b);
    exit(0);
}