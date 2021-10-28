#include "errors.h"
#include <stdlib.h>
#include <stdio.h>

void err_exit(char* type)
{
    perror(type);
    exit(1);
}