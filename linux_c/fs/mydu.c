//
// Created by Acyco on 2023-12-29.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <glob.h>
#include <unistd.h>
#include <string.h>

#define PATHSIZE 1024

static int path_noloop(const char *path)
{
    char *pos;
    pos = strrchr(path, '/');
    if (pos == NULL)
        exit(1);

    // 防止死循环 把. 和 .. 目录给排除
    if (strcmp(pos + 1, ".") == 0 || strcmp(pos + 1, "..") == 0)
        return 0;
    return 1;
}

static int64_t mydu(const char *path)
{
    int i;
    static struct stat statres;
    static char nextpath[PATHSIZE];
    glob_t globres;
    int64_t sum;

    if (lstat(path, &statres) < 0)
    {
        perror("lstat()");
        exit(1);
    }

    if (!S_ISDIR(statres.st_mode))
    {
        return statres.st_blocks;
    }

    strncpy(nextpath, path, PATHSIZE - 1);
    strncat(nextpath, "/*", PATHSIZE - 1);
    glob(nextpath, 0, NULL, &globres);

    strncpy(nextpath, path, PATHSIZE - 1);
    strncat(nextpath, "/.*", PATHSIZE - 1); //把.隐藏文件也加入进去
    glob(nextpath, GLOB_APPEND, NULL, &globres);

    sum = statres.st_blocks;

    for (i = 0; i < globres.gl_pathc; i++)
    {
        if (path_noloop(globres.gl_pathv[i]))
            sum += mydu(globres.gl_pathv[i]);
    }

    globfree(&globres); // 释放
    return sum;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }

    printf("%lld\n", mydu(argv[1]) / 2);

    exit(0);
}