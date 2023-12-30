//
// Created by Acyco on 2023-12-30.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pid_t pid;

    if(argc < 3)
    {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }

    pid = fork();
    if(pid < 0)
    {
        perror("fork()");
        exit(1);
    }

    if(pid == 0)
    {
        setuid(atoi(argv[1]));
        execvp(argv[2], argv+2);
        perror("execvp()");
        exit(1);
    }

    exit(0);
}