#ifndef __RE_DIREC
#define __RE_DIREC

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "redirec.h"
#include <fcntl.h>
#include <time.h>
#include <sys/wait.h>
#include "run_command.h"
void redirect(char *arr[],int pos);

#endif