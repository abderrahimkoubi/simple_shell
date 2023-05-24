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

void _env(char **env);
void execute_process(pid_t *pid, char *argv[], char *name);
int env_cmd(char *cmd);
int exit_cmd(char *cmd);

#endif /* SHELL_H */
