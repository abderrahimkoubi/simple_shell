#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TOKEN_BUF_SIZE 64
#define TOKEN_DELIM " \t\r\n\a"

void start_prompt(void);
char *read_command(void);
char **get_array_from_str(char *str, char **env);
char **_which(char *foundpath);
int executable_command(char **av, char **args, char **env,
		int status_main, int count);

#endif
