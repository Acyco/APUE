/* 指针函数 */

#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 4

void print_arr(int *p, int n) {
  // 把整个二维数组当成一维数组
  for (int i = 0; i < n; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
}

void print_arr1(int p[][N], int m, int n) {
  int i, j;

  printf("sizeof(p) = %ld\n", sizeof(p)); // p 是一级指针，占用8

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%4d ", *(*p + i) + j);
    }
    printf("\n");
  }
}

float average_score(int *p, int n) {
  int i;
  float sum = 0;
  for (i = 0; i < n; i++) {
    sum += p[i];
  }
  return sum / n;
}

#if 0
void find_num(int (*p)[N], int num) {
  int i;

  for (i = 0; i < N; i++) {
    printf("%d ", *(*(p + num) + i));
  }
  printf("\n");
}
#else

int * find_num( int (*p)[N], int num) {
    if(num > M-1)
        return NULL;
    return *(p + num);
}
#endif

int main() {
  int a[M][N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  float ave;
  int num = 4;
  int * res;
  int i;

  ave = average_score(a, M * N);
  printf("ave = %f\n", ave);

  res = find_num(a, num);

  if(res != NULL) {
      for (i = 0; i < N; i++) 
          printf("%d ", res[i]);
      printf("\n");
  }
  else {
      printf("Con not find!\n");
  }


  exit(0);
}
