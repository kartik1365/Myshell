#ifndef __RUN_COMMAND
#define __RUN_COMMAND

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <string.h>
#include "cd.h"
#include "redirec.h"
#include "pipe.h"
void run_command(char *arr[]);

#endif