#ifndef SHELL_H 
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

int main(int ac, char **argv);
void free_argv(char **argv);
char **parse_command(char *command, ssize_t num_chars);
char **tokenizePath();
char *getenv(const char *name);
char *actual_path(char *command);
char *findCommandPath(char **pathTokens,  char *command);
void freeTokenizedPath(char **pathTokens);
char *getCommandPath(char *command);
void execute_external_command(char *command, char **argv);
extern char **environ;
char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);


#endif
