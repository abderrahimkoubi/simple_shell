#include "shell.h"
/**
 * main - Entry point
 * Description: prompts user for input and displays output
 * @argc: arguments count
 * @argv: arguments string vector
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *buff = NULL;
	char *prompt = "simpsh$ ";
	ssize_t inputsize;
	size_t cmdsize = 0;
	const char *separator = " \n";
	int i;
	pid_t pid;
	int is_redir = !isatty(STDIN_FILENO);
	char **exec_argv;
	(void) argc, (void) argv;
	exec_argv = malloc(sizeof(char *) * 256);
	if
		(exec_argv == NULL)
		{
			perror("Memory allocation failed");
			return (-1);
		}
	while (1)
	{
		if
			(!is_redir && isatty(STDOUT_FILENO))
			{
				write(STDIN_FILENO, prompt, strlen(prompt));
			}
		inputsize = getline(&buff, &cmdsize, stdin);
		{
			if
				(!is_redir && isatty(STDOUT_FILENO))
				{
					if
						(inputsize == -1)
						{
							printf("\n");
							return (-1);
						}
				}
		}
		if
			(inputsize <= 1)
			{
				continue;
			}
		inputsize = strlen(buff);
		if
			(buff[inputsize - 1] == '\n')
			{
				buff[inputsize - 1] = '\0';
			}
		str_tokens(buff, separator, exec_argv);
		pid = fork();
		if
			(pid == -1)
		{
			perror("Fork failed");
			return (-1);
		}
		else
			if
				(pid == 0)
				{
					exe_cmd(exec_argv);
					return (-1);
				}
			else
			{
				wait(NULL);
			}
		for (i = 0; exec_argv[i] != NULL; i++)
		{
			free(exec_argv[i]);
		}
	}
	free(buff);
	free(exec_argv);
	return (0);
}
