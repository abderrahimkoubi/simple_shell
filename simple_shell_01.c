#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100
/**
 * execute_command - Execute the user-entered command
 * @command: User command to execute
 *
 * Return: void
 */
void execute_command(const char *command);
/**
 * main - entry point
 *
 * Return : 0
 */
int main ( )
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		putchar('s');
		putchar('i');
		putchar('m');
		putchar('p');
		putchar('l');
		putchar('e');
		putchar('_');
		putchar('s');
		putchar('h');
		putchar('e');
		putchar('l');
		putchar('l');
		putchar('$');
		putchar(' ');

		if
			(fgets(command, sizeof(command), stdin) == NULL)
			{
				putchar('\n');
				break;
			}

		command[strcspn(command, "\n")] = '\0';

		execute_command(command);
	}

	return (0);
}

void execute_command(const char *command)
{
	pid_t pid = fork();

	if
		(pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
	else
		if
			(pid == 0)
			{

				if
					(execlp(command, command, NULL) == -1)
					{
						perror("Command not found");
						exit(EXIT_FAILURE);
					}
			}
		else
		{

			wait(NULL);
		}
}	
