#include <stdio.h>
#include <string.h>

void cat(int argc, char *args[])
{
    if (argc < 2)
    {
        printf("invalid use of command\n");
        return;
    }

    else if (argc >= 3 && strcmp(args[1], "-n") == 0)
    {
        for (int i = 2; i < argc; i++)
        {
            FILE *file = fopen(args[i], "r");
            if (!file)
            {
                printf("%s File not found!\n", args[i]);
                //return;
            }
	    else{
            char l[1024];
            int p = 1;
            while (fgets(l, 1024, file))
            {
                printf("%d)%s", p, l);
                p++;
            }
            fclose(file);
	    }
        }
        return;
    }

    else if (argc >= 3 && strcmp(args[1], "-e") == 0)
    {
        FILE *file;
        for (int i = 2; i < argc; i++)
        {
            file = fopen(args[i], "r");
            if (!file){
                printf("%s File not found!\n", args[i]);
                //return;
            }
	    else{
            do
            {
                char charr = fgetc(file);

                if (feof(file))
                {
                    break;
                }
                if (charr == '\n')
                {
                    printf("$");
                }
                printf("%c", charr);
            } while (1);
            fclose(file);
	    }
        }
        return;
    }

    else if (argc >= 2)
    {
        FILE *file;
        for (int i = 1; i < argc; i++)
        {
            file = fopen(args[i], "r");
            if (!file)
            {
                printf("%s File not found!\n", args[i]);
                //return;
            }

            else{
	    do
            {
                char charr = fgetc(file);

                if (feof(file))
                {
                    break;
                }
                printf("%c", charr);
            } while (1);

            fclose(file);
	   }
        }
        return;
    }
}
