/* 匿名数组指针 */

#include <stdio.h>
#include <stdlib.h>

// TYPE NAME = VALUE;

// a[i]:  a[i] = *(a+i) = *(p+i) = p[i]
// &a[i]: &a[i] = a+i = p+i = &p[i]

int main() {
  int *p = (int[3]){1, 2, 3}; // 匿名数组
  int i;
  for (i = 0; i < 3; i++) {
    printf("%p --> %d\n", &p[i], p[i]);
  }
  exit(0);
}
