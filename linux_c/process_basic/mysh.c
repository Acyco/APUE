//
// Created by Acyco on 2023-12-30.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <glob.h>
#include <sys/wait.h>

struct cmd_st
{
    glob_t globres;
};

#define DELIMS " \t\n"

static void prompt(void)
{
    printf("mysh-0.1$ ");
}

static void parse(char *line, struct cmd_st *res)
{
    // ls -a    -l  /etc /aa/bb/cc/dddd/fff/ asdfaddf
    char *tok;
    int i = 0;

    while (1)
    {
        tok = strsep(&line, DELIMS);
        if(tok  == NULL)
            break;
        if(tok[0] == '\0')
            continue;

        glob(tok, GLOB_NOCHECK|GLOB_APPEND*i,NULL, &res->globres);
        i = 1;
    }
}

int main()
{
    char *linebuf = NULL;
    size_t  linebuf_size = 0;
    struct cmd_st cmd;
    pid_t pid;

    while (1)
    {
        prompt();
        if(getline(&linebuf,&linebuf_size, stdin) < 0)
            break;

        parse(linebuf, &cmd);

        if(0) //  内部命令
        {/*do something*/}
        else{ // 外部命令
            pid = fork();
            if(pid < 0)
            {
                perror("fork()");
                exit(1);
            }

            if(pid == 0)   // child
            {
                execvp(cmd.globres.gl_pathv[0], cmd.globres.gl_pathv);
                perror("execvp();");
                exit(1);
            }
            else
            {
                wait(NULL);

            }
        }
    }

    exit(0);
}