#include <stdio.h>
#include <stdlib.h>

/*
#define INT int
typedef int INT;

INT i;   --->  int i;


#define IP  int *
typedef int *IP;

IP p,q; ----> int *p,q;     // #define
IP p,q; ----> int *p,*q;    // typedef


typedef int ARR[6];    ---> int[6] -> ARR

ARR a;  ---> int a[6];

struct note_st
{
    int i;
    float f;
};

typedef struct node_st NODE;
NODE a; ----> struct node_st a;
NODE *p; ----> struct node_st *p;

typedef struct node_st *NODEP;
NODEP p; ----> struct node_st *p;

typedef struct
{
    int i;
    float f;
}NODE, *NODEP;

typedef int FUNC(int);  ---> int(int) FUNC;
FUNC f; ----> int f(int);

typedef int *FUNCP(int);
FUNCP p; ----> int *p(int);

typedef int *(*FUNCP)(int);
FUNCP p; ----> int *(*p)(int);

 */


typedef int INT;

int main()
{
    INT i = 100;
    printf("%d\n", i);
    exit(0);
}
