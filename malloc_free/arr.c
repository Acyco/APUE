#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    int i;
    int num = 5;
    p = malloc(sizeof(int) * 5);

    for (i = 0; i < num; ++i)
        scanf("%d", &p[i]);
    for (i = 0; i < num; i++)
        printf("%d ", p[i]);
    printf("\n");
    free(p);
    exit(0);
}