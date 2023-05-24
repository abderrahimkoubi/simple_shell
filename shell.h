#ifndef SHELL_H
#define SHELL_H
#include <sys/types.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void _exec(char **tmp_args, char **env);
void _find_path(char **env, char **tmp_args, char **buffer);
void _exec_path(char *tmp_path, char **tmp_args, char **env);
void _update_PWD(char **env);
void _handle_cd(char **env, char **tmp_args, char **buffer);
int _get_user_input(ssize_t n, char inputcmd[100], char *input);
void _loop(char **buffer, char **env);
void _handle_args(char **tmp_args, char inputcmd[100]);

#endif
