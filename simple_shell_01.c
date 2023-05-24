#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define TOKEN_BUF_SIZE 64
#define TOKEN_DELIM " \t\r\n\a"

void start_prompt(void);
char *read_command(void);
char **get_array_from_str(char *str, char **env);
char **_which(char *foundpath);
int executable_command(char **av, char **args, char **env,
		int status_main, int count);
/**
 * main - Entry point for the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char *command;
	char **args;
	char **env = environ;

	while (1)
	{
		start_prompt();
		command = read_command();
		args = get_array_from_str(command, env);
		if (args != NULL)
		{
			executable_command(args, args, env, 0, 0);
		}
		free(command);
		free(args);
	}

	return (0);
}

/**
 * start_prompt - Displays the shell prompt
 */
void start_prompt(void)
{
	char *prompt = "#myShell$ ";

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
	}
}

/**
 * read_command - Reads the user input command
 * Return: The command string
 */
char *read_command(void)
{
	char *entry = NULL;
	size_t bufsize = 0;
	ssize_t signal;

	signal = getline(&entry, &bufsize, stdin);
	if (signal == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		free(entry);
		exit(0);
	}

	return (entry);
}

/**
 * get_array_from_str - Converts the command string to an array of arguments
 * @str: The command string
 * @env: The environment variables array
 * Return: The array of arguments
 */
char **get_array_from_str(char *str, char **env)
{
	int bufsize = TOKEN_BUF_SIZE;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, TOKEN_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[position] = NULL;

	return (tokens);
}

/**
 * _which - Searches for the executable in the directories
 * @foundpath: The value of the PATH environment variable
 * Return: The array of directories
 */
char **_which(char *foundpath)
{
	int bufsize = TOKEN_BUF_SIZE;
	int position = 0;
	char **directories = malloc(bufsize * sizeof(char *));
	char *copy_path = strdup(foundpath);
	char *token;

	if (!directories)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	token = strtok(copy_path, ":");
	while (token != NULL)
	{
		directories[position] = token;
		position++;

		token = strtok(NULL, ":");
	}
	directories[position] = NULL;

	free(copy_path);
	return (directories);
}

/**
 * executable_command - Executes the command
 * @av: The array of arguments
 * @args: The array of arguments
 * @env: The environment variables array
 * @status_main: The status flag
 * @count: The command count
 * Return: 1 on success
 */
int executable_command(char **av, char **args, char **env,
		int status_main, int count)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("./hsh: ");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("Error");
			free(args);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (status_main == 1)
		{
			free(args[0]);
		}

		free(args);
		waitpid(pid, &status, WUNTRACED);
	}

	return (1);
}
