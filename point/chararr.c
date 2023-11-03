/* */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char *str = "hello";
  printf(
      "%ld %ld\n", sizeof(str),
      strlen(str)); // 8 5   为什么是8 因为str指针在我当前系统64位是占用8个字节

  // strcpy(str, "world"); //报错
  str = "world"; // 只要这样就可以了  常量与变量的区别

  puts(str);

  /*
      char str[] = "hello";

      printf("%ld %ld\n", sizeof(str), strlen(str));// 6 5

      //str = "world"; // 错的
      strcpy(str, "world"); //可以使用strcpy
      puts(str); // world
  */
  /*
char str[] = "I love china!";
char *p = str + 7;

puts(str); // I love china!
puts(p); //china!

*/
  exit(0);
}
