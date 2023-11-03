/* 递归 */

#include <stdio.h>
#include <stdlib.h>

#if 0

3! = 3*2*1;
3! = 3*2!
        2! = 2* 1!
                1! = 1
                0! = 1
n! = n*(n-1)!
        (n-1)!= (n-1) * (n-2)！
8! = 8*7*6*5*4*3*2*1;
#endif

int func(int n) {
  if (n < 0) {
    return -1;
  }
  if (n == 1 || n == 0) {
    return 1;
  }
  return n * func(n - 1);
}

int main() {
  int n;
  int res;

  scanf("%d", &n);

  res = func(n);

  printf("%d!= %d\n", n, res);
  exit(0);
}
