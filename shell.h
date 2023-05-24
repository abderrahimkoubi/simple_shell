#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

void exe_cmd(char **argv);
int str_tokens(char *buff, const char *separator, char **exec_argv);

#endif /* SHELL_H */
