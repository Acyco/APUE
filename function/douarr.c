/* 函数与二维数组*/

#include <stdio.h>
#include <stdlib.h>

/*
 *
 * int a[M][N] = (....);
 * int *p = *a;
 * int (*q)[N] = a;
 * -> a[i][j]   *(a+i)+j    a[i]+j     p[i]    *p
 *    q[i][j]     *q        q         p+3     q+2
 *
 *
 * -> int       int *       int *     int     int
 *  int        int *   int (*)[N]  int *    int (*)[N]
 *
 * */

#define M 3
#define N 4

#if 0
void print_arr(){
  int i, j;
  for(i = 0; i<M; i++)
  {
      for (j = 0; j < N; j++) {
        printf("%4d ", a[i][j]);
      }
      printf("\n");
  }
}
#endif

void print_arr(int *p, int n) {
  // 把整个二维数组当成一维数组
  for (int i = 0; i < n; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
}

// void print_arr1(int (*p)[N], int m, int n)
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

void find_num(int (*p)[N], int num) {
  int i;

  for (i = 0; i < N; i++) {
    printf("%d ", *(*(p + num) + i));
  }
  printf("\n");
}

int main() {
  int a[M][N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  float ave;
  int num = 1;

  ave = average_score(a, M * N);
  printf("ave = %f\n", ave);

  find_num(a, num);

  // print_arr(*a,M*N);

  //*a a[0]  *(a+0)   这样
  //  这些传参都是 把行转为列
  // print_arr(&a[0][0],M*N);

  printf("sizeof(a) = %ld\n", sizeof(a)); // 这里是a的占用字节 48
  print_arr1(a, M, N);

  exit(0);
}
