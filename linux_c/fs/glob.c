//
// Created by Acyco on 2023-12-28.
//

#include <stdio.h>
#include <stdlib.h>
#include <glob.h>

//#define  PAT "/etc/a*.conf"
#define  PAT "/etc/.*"

#if  0
int errfunc_(const char *errpath, int errno)
{
    puts(errpath);
    fprintf(stderr,"ERROR MSG: %s\n", strerror(errno))
}

#endif

int main()
{
    glob_t  globres;
    int i, err;

    err = glob(PAT, 0, NULL, &globres);
    if(err)
    {
        printf("Error code = %d\n", err);
        exit(1);
    }

    for (int i = 0; i < globres.gl_pathc; i++)
        puts(globres.gl_pathv[i]);


    globfree(&globres);

    exit(0);
}