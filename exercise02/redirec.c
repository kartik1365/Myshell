#include "redirec.h"
#include "tokenize.h"
#include "run_command.h"
void redirect(char *arr[], int pos)
{
    arr[pos] = NULL;
    if (fork() == 0)
    {
        int file = open(arr[pos + 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
        if (file == -1)
        {
            printf("ERROR\n");
            return;
        }
        int file2 = dup2(file, STDOUT_FILENO);
        close(file);
        run_command(arr);
        close(file2);
        exit(0);
    }
    else
    {
        wait(NULL);
    }
}