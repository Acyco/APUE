#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
struct
{
    int i;
    char ch;
    union
    {
        int a;
        char c;
    } un;
    float f;
};

union
{
    int a;
    double d;
    struct
    {
        int arr[10];
        float f;
    } c;
};
 */

union
{
    struct
    {
        uint16_t i;
        uint16_t j;
    } x;
    uint32_t y;
} a;


int main()
{
//   uint32_t i = 0x11223344;
//   printf("%x\n", (i >> 16) + i & 0xFFFF);

    a.y = 0x11223344;
    printf("%x\n", a.x.i + a.x.j);
    exit(0);
}