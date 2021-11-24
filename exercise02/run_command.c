#include "run_command.h"
#include "pipe.h"
void run_command(char *arr[])
{
    if (strcmp(arr[0], "exit") == 0)
        exit(0);
    if (strcmp(arr[0], "cd") == 0)
    {
        cd(arr);
        return;
    }
    int rflag = -1, pflag = -1;
    if (fork() == 0)
    {
        for (int i = 0; arr[i] != NULL; i++)
        {
            if (strcmp(arr[i], ">") == 0)
            {
                arr[i] = NULL;
                rflag = i;
            }
            else if (strcmp(arr[i], "|") == 0)
            {
                pflag = i;
            }
        }
        if (rflag != -1)
        {
            redirect(arr, rflag);
        }
        else if (pflag != -1)
        {
            _pipe(arr, pflag);
        }
        else
        {
            if (execvp(arr[0], arr) == -1)
                printf("command not found\n");
            // printf("done\n");
            // else if (strcmp(arr[0], "echo") == 0)
            // {
            //     echo(arr);
            // }
        }
        exit(0);
    }
    else
        wait(NULL);
}