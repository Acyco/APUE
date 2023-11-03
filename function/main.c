/* 函数的定义 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>
/*
 * 函数定义 ：  数据类型 函数名 (【数据类型 形参名, 数据类型 形参名,....】)
 * */

// int main() // 入口函数
//  int main(void)
//  int main(int argc, char *argv[])
//  int main(int argc, char **argv)

int main(int argc, char *argv[]) {

  int i;
  printf("argc = %d\n", argc);

  for (i = 0; argv[i] != NULL; i++) {
    puts(argv[i]);
  }

  // printf("Hello!\n"); // 会返回父进程一个数，返回printf有效打印的
  //  ，但在我mac系统上的编译器编译 执行返回的是0;
  // exit(0); // return 0; 和exit(0); 是有区别
}
