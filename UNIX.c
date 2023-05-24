#include "shell.h"

/**
 * lookforslash - identifies if first char is a slash.
 * @cmd: first string
 *
 * Return: 1 if yes 0 if no.
 */
int lookforslash(char *cmd)
{
	int read = 0;

	while (cmd[read])
	{
		if (cmd[0] == '/')
		{
			printf("%c\n", cmd[0]);
			return (1);
		}
		read++;
	}
	return (0);
}

/**
 * compareExit - identifies if first char is a slash.
 * @z1: first string
 * @z2: exit string
 * Return: 1 if yes 0 if no.
 */
int compareExit(char *z1, char *z2)
{
	int j = 0;

	for (; (*z2 != '\0' && *z1 != '\0') && *z1 == *z2; z1++)
	{
		if (j == 3)
			break;
		j++;
		z2++;
	}
	return (*z1 - *z2);
}

/**
 * compareEnv - identifies if first char is a slash.
 * @z1: first string
 * @z2: exit string
 *
 * Return: 1 if yes 0 if no.
 */
int compareEnv(char *z1, char *z2)
{
	int j = 0;

	for (; (*z2 != '\0' && *z1 != '\0') && *z1 == *z2; z1++)
	{
		if (j == 2)
			break;
		j++;
		z2++;
	}
	return (*z1 - *z2);
}

/**
 * identify_string - identify keyboard iput.
 * @parameter: call prompt from another function (prompt)
 * Return: str
 */
char **identify_string(char *parameter)
{
	char **buf = malloc(1024 * sizeof(char *));
	char *split;
	int j = 0;
	char *delem = " \t\n";

	split = strtok(parameter, delem);

	while (split != NULL)
	{
		buf[j] = split;
		j++;
		split = strtok(NULL, delem);
	}
	execute_proc(buf);
	return (buf);
}

/**
 * controlC - avoid close the shell
 * @sig: keep going shell
 */
void controlC(int sig)
{
	(void) sig;
	write(1, "\n$ ", 3);
}
