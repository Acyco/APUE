/* 嵌套 */

#include <stdio.h>
#include <stdlib.h>

void c() {
  printf("[%s] begin\n", __FUNCTION__);
  printf("[%s] end\n", __FUNCTION__);
}

void b() {
  printf("[%s] begin\n", __FUNCTION__);
  printf("[%s] call c()!\n", __FUNCTION__);
  c();
  printf("[%s] c() returned!\n", __FUNCTION__);
  printf("[%s] end\n", __FUNCTION__);
}

void a() {
  printf("[%s] begin\n", __FUNCTION__);
  printf("[%s] call b()!\n", __FUNCTION__);
  b();
  printf("[%s] b() returned!\n", __FUNCTION__);
  printf("[%s] end\n", __FUNCTION__);
}

int main() {
  printf("[%s] begin\n", __FUNCTION__);
  printf("[%s] call a()!\n", __FUNCTION__);
  a();
  printf("[%s] a() returned!\n", __FUNCTION__);
  printf("[%s] end\n", __FUNCTION__);
  exit(0);
}
