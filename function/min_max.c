/* 函数嵌套调用 */

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c)
{
    int tmp;
    tmp = a > b ? a : b;
    return tmp > c ? tmp : c;

}

int min(int a, int b, int c)
{

    int tmp;
    tmp = a<b ? a: b;
    return tmp < c ?tmp : c;
}

int dist( int a, int b , int c )
{
    return max(a,b,c) - min(a,b,c);
}
int main()
{
    int a = 3, b= 5, c = 10;
    int res;

    res = dist(a, b, c);

    printf("res = %d\n", res);

    exit(0);
}
