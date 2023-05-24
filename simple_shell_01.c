#include "main.h"

#define BUFFER_SIZE 1024

void display_prompt(void);
char *read_command(void);
void execute_command(char *command);

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char *command;

	while (1)
	{
		display_prompt();
		command = read_command();

		if (feof(stdin))
		{
			printf("\n");
			break;
		}

		execute_command(command);
		free(command);
	}

	exit(EXIT_SUCCESS);
}

/**
 * display_prompt - Displays the shell prompt
 */
void display_prompt(void)
{
	printf("$ ");
}

/**
 * read_command - Reads a command line from the user
 *
 * Return: The command line entered by the user
 */
char *read_command(void)
{
	char *buffer;
	size_t bufsize = BUFFER_SIZE;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	getline(&buffer, &bufsize, stdin);

	buffer[strcspn(buffer, "\n")] = '\0';

	return (buffer);
}

/**
 * execute_command - Executes a command
 * @command: The command to execute
 */
void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{

		if (execve(command, NULL, environ) == -1)
		{
			perror("execve error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
