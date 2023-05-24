#ifndef shell_h
#define shell_h

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
#endif
