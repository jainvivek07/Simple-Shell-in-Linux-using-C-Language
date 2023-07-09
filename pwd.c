#include <stdio.h>
#include <unistd.h>    

void pwd()
{
    char current[1024];
    getcwd(current, 1024);
    printf("%s\n", current);
    return;
}
