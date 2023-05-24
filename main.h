#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>

int execute_builtin(data *data;);
void exit_builtin(data *data);
void env_builtin(data *data);
void setenv_builtin(data *data);
void unsetenv_builtin(data *data);

#endif
