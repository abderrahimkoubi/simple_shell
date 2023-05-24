#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(const char *s);
char *str_concat(char *string1, char *string2);
int _strcmp(char *string1, char *string2);
#endif
