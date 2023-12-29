//
// Created by Acyco on 2023-12-30.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

/**
 * -y: year
 * -m: month
 * -d: day
 * -H: hour
 * -M: minute
 * -S: second
 */

#define TIMESTRSIZE 1024
#define FMTSTRSIZE  1024

int main(int argc, char **argv)
{
    FILE *fp = stdout;
    time_t stamp;
    struct tm *tm;
    char timestr[TIMESTRSIZE];
    int c;
    char fmtstr[FMTSTRSIZE];

    fmtstr[0] = '\0'; // 初始化，不然会有乱码

    stamp = time(NULL);
    tm = localtime(&stamp);

    while(1)
    {
        c =  getopt(argc, argv,"-H:MSy:md");
        if(c < 0)
            break;
        switch (c)
        {
            case 1:
                if(fp == stdout)
                {
                    fp = fopen(argv[optind - 1], "w"); // 前一个参数 -1
                    if(fp == NULL)
                    {
                        perror("fopen()");
                        fp = stdout;
                    }
                }

                break;
            case 'H':
                if(strcmp(optarg, "12") == 0)
                    strncat(fmtstr, "%I(%P) ", FMTSTRSIZE - 1);
                else if(strcmp(optarg, "24") == 0)
                    strncat(fmtstr, "%H ", FMTSTRSIZE - 1);
                else
                    fprintf(stderr, "Invalid argument of -H!");
                break;
            case 'M':
                strncat(fmtstr, "%M ", FMTSTRSIZE - 1);
                break;
            case 'S':
                strncat(fmtstr, "%S ", FMTSTRSIZE - 1);
                break;
            case 'y':
                if(strcmp(optarg, "2") == 0)
                    strncat(fmtstr, "%y ", FMTSTRSIZE - 1);
                else if(strcmp(optarg, "4") == 0)
                    strncat(fmtstr, "%Y ", FMTSTRSIZE - 1);
                else
                    fprintf(stderr, "Invalid argument of -y!");
                break;
                break;
            case 'm':
                strncat(fmtstr, "%m ", FMTSTRSIZE - 1);
                break;
            case 'd':
                strncat(fmtstr, "%d ", FMTSTRSIZE - 1);
                break;
            default:
                break;

        }
    }

    strncat(fmtstr, "\n", FMTSTRSIZE - 1);
    strftime(timestr, TIMESTRSIZE, fmtstr, tm);
    fputs(timestr,fp);

    if(fp != stdout)
        fclose(fp);
    exit(0);
}