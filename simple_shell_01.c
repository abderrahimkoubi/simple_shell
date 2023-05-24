#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
* add_end_path - adds path to cmd
* @path: path of a written cmd
* @cmd:  an entered cmd
*
* Return: buffer containing command with path on success, or NULL on failure
*/

char *add_end_path(char *path, char *cmd)
{
	char *buffer;
	size_t a = 0, b = 0;

	if (cmd == 0)
		cmd = "";

	if (path == 0)
		path = "";

	buffer = malloc(sizeof(char) * (_strlen(path) + _strlen(cmd) + 2));
	if (!buffer)
		return (NULL);

	while (path[a])
	{
		buffer[a] = path[a];
		a++;
	}

	if (path[a - 1] != '/')
	{
		buffer[a] = '/';
		a++;
	}
	while (cmd[b])
	{
		buffer[a + b] = cmd[b];
		b++;
	}
	buffer[a + b] = '\0';
	return (buffer);
}
