#include "shell.h"
/**
 * prompt - function serves as the main loop for the command line interpreter
 *@ax: an array of strings representing the command-line arguments
 *@envi: represents the environment variables
 *
 * Return: 0
 */

void prompt(char **ax, char **envi)
{
	char input[1024];
	pid_t pid;
	int status;

	while (1)
	{
		printf("simple_shell$ ");

		if
			(fgets(input, sizeof(input), stdin) == NULL)
			{
				printf("\n");
				break;
			}
		input[strcspn(input, "\n")] = '\0';
		pid = fork();
		if
			(pid < 0)
	}
	perror("fork");
	exit(EXIT_FAILURE);
}
else
if
(pid == 0)
{
	if
		(execlp(input, input, NULL) == -1)
		{
			perror("execlp");
			exit(EXIT_FAILURE);
		}
	exit(EXIT_SUCCESS);
}
else
{
	waitpid(pid, &status, 0);
}
int main(int argc, char *argv[])
{
	char *envi[] = {NULL};
	prompt(argv, envi);
	return (0);
}
