#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

int _strlen(const char *s);
char *str_concat(const char *s1, const char *s2);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
#endif
