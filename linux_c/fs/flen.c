//
// Created by Acyco on 2023-12-28.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

static off_t flen(const char *fname)
{
    struct stat statres;
    if(stat(fname,&statres) < 0)
    {
        perror("stat()");
        exit(1);
    }

    return statres.st_size;
}

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }


    printf("%lld\n",flen(argv[1]));

    exit(0);
}