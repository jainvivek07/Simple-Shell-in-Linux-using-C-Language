
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
#include "pwd.c"
#include "date.c"
#include "rm.c"
#include "mkdir.c"
#include "ls.c"
#include "cat.c"
#include "cd.c"

int count = 0;
int exitcode = 0;

void traverse(char *k, char *args[], int len)
{
    int i;
    char *ll1 = (char *)malloc(sizeof(char) * 256);
    for (i = 0; i < len; i++)
    {
        ll1[i] = k[i];
    }
    ll1[len] = '\0';
    while (*ll1 != '\0')
    {
        while (*ll1 == ' ' || *ll1 == '\t' || *ll1 == '\n')
        {
            *ll1++ = '\0';
        }
        *args++ = ll1;
        count++;
        while (*ll1 != '\0' && *ll1 != ' ' && *ll1 != '\t' && *ll1 != '\n')
        {
            ll1++;
        }
    }
    *args = '\0';
}


int abcde(char ipp[], char *args[])
{
    int i;
    int len = read(STDIN_FILENO, ipp, 1024);
    char *uu = (char *)malloc(sizeof(char) * 1024);
    for (i = 0; i < len - 1; i++)
    {
        uu[i] = ipp[i];
    }
    uu[len - 1] = '\0';
    if (len == 0 || ipp[0] == '\n')
    {
        return -1;
    }
    else if (len < 0)
    {
        printf("Command not read\n");
        exit(-1);
    }
    traverse(ipp, args, len - 1);
    return runcom(args, uu, count);
}

int main()
{
    char ipp[1024];
    char *args[512];
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        printf("Fork failed.\n");
        exit(1);
    }
    else if (pid == 0)
    {
        while (exitcode != 1)
        {
            printf(">>>");
            count = 0;
            fflush(stdout);
            abcde(ipp, args);
        }
    }
    else
    {
        wait(NULL);
    }
}

int runcom(char *args[], char *uu, int x)
{
    if (strcmp(args[0], "date") == 0)
    {
        date(x, args);
    }

    else if (strcmp(args[0], "exit") == 0)
    {
        exitcode = 1;
    }

    else if (strcmp(args[0], "mkdir") == 0)
    {
        makedir(x, args);
    }

    else if (strcmp(args[0], "echo") == 0)
    {
        if (x <= 1)
        {
            printf("Enter any arguments");
        }
        else if (strcmp(args[1], "-e") != 0 && strcmp(args[1], "*") != 0)
        {
            for (int i = 1; i < x; i++)
            {
                printf("%s ", args[i]);
            }
	    printf("\n");
        }

        else if (strcmp(args[1], "-e") == 0)
        {
            for (int i = 2; i < x; i++)
            {
                printf("%s", args[i]);
            }
	    printf("\n");
        }

        else if (strcmp(args[1], "*") == 0)
        {
            ls1(1,args);
        }
    }

    else if (strcmp(args[0], "cd") == 0)
    {
        cd(x, args[1]);
    }
    else if (strcmp(args[0], "pwd") == 0)
    {
        pwd();
    }
    else if (strcmp(args[0], "ls") == 0)
    {
        ls1(x, args);
    }

    else if (strcmp(args[0], "rm") == 0)
    {
        rm(x, args);
    }

    else if (strcmp(args[0], "cat") == 0)
    {
        cat(x, args);
    }

    else
    {
        printf("Enter a valid command.\n");
    }
    return -1;
}
