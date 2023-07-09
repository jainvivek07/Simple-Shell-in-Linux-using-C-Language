#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>

void makedir(int x, char *args[])
{

        if (x < 2)
        {
                printf("Too few arguments!");
                return;
        }

        else if (x > 2 && strcmp(args[1], "-v") == 0)
        {
                int check;
                for (int i = 2; i < x; i++)
                {
                        check = mkdir(args[i], 0777);

                        if (!check)
                                printf("mkdir: created Directory %s\n", args[i]);
                        else
                        {
                                printf("Unable to create directory %s\n", args[i]);
                        }
                }

                return;
        }

        else if (x > 2 && strcmp(args[1], "-p") == 0)
        {
                int cnt = 0;
                char *haha = args[2];
                char *next = strtok(haha, "/");

                while (next != NULL)
                {
                        int p = mkdir(next, 0777);
                        chdir(next);
                        cnt++;
                        next = strtok(NULL, "/");
                }

                for (int i = 0; i < cnt; i++)
                {
                        chdir("..");
                }
                return;
        }

        else
        {
                int check;
                for (int i = 1; i < x; i++)
                {
                        check = mkdir(args[i], 0777);

                        if (!check)
                        {
                                printf("");
                                // printf("mkdir: created Directory %s\n",args[i]);
                        }
                        
                        else
                        {
                                printf("Unable to create directory %s\n", args[i]);
                        }
                }

                return;
        }
}
