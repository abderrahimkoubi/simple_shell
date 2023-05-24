#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(void);
/**
 * main - Entry point
 *
 * Description: Unique UNIX command line interpreter
 * Return: Always 0
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;
	char *prompt = "#shell$ ";

	while (1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));

		characters = getline(&buffer, &bufsize, stdin);
		if (characters == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (buffer[characters - 1] == '\n')
			buffer[characters - 1] = '\0';

		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			break;
		}

		if (access(buffer, X_OK) == 0)
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("fork");
			}
			else if (pid == 0)
			{
				char *argv[] = {buffer, NULL};

				execve(buffer, argv, NULL);
				perror("execve");
				_exit(EXIT_FAILURE);
			}
			else
			{
				wait(NULL);
			}
		}
		else
		{
			char *error_message = "error command not found\n";

			write(STDOUT_FILENO, error_message, strlen(error_message));
		}
	}

	return (0);
}
