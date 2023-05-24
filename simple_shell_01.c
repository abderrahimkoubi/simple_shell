#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char *buffer;
	size_t bufsize = BUFFER_SIZE;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		printf("$ ");
		getline(&buffer, &bufsize, stdin);
		buffer[strcspn(buffer, "\n")] = '\0';
		if (feof(stdin))
		{
			printf("\n");
			break;
		}
		pid_t pid = fork();

		if (pid < 0)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if
				(execve(buffer, NULL, environ) == -1)
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

	free(buffer);
	exit(EXIT_SUCCESS);
}
