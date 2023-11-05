/* 函数与一维数组 */

#include <stdio.h>
#include <stdlib.h>

/**
 *  int a[N[ = {1,2,3,4,5,6}];
 *  int *p;
 *
 *  实参->  a     *a    a[0] &a[3]  p[i]  p     *p   p+1
 *
 *  形参-> int *  int   int  int *  int  int *  int  int *
 *
 *
 * */

#if 0
// void print_arr(int *p, long n)
void print_arr(int p[], int n) // int p[] 依然还是个指针
{
  int i;

  printf("%s:%ld\n", __FUNCTION__, sizeof(p)); // 还是8

  for (i = 0; i < n; i++) {
    // printf("%d ", p[i]);
    printf("%d ", *(p + i));
  }
  printf("\n");
}

#endif

void func(int *p, int n) {
  int i, j, m, tmp;
  m = (n - 1) / 2;
  for (i = 0; i <= m; i++) {
    j = n - 1 - i;
    tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;
  }
}

int main() {
  int a[] = {1, 3, 5, 7, 9};
  int i;

  // printf("%s:%ld\n", __FUNCTION__, sizeof(a));
  // print_arr(a, sizeof(a) / sizeof(*a));

  for (i = 0; i < sizeof(a) / sizeof(*a); i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  func(a, sizeof(a) / sizeof(*a));

  for (i = 0; i < sizeof(a) / sizeof(*a); i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  exit(0);
}
