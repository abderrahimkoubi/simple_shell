#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* add_end_path - adds path to cmd
* @path: path of a written cmd
* @cmd:  an entered cmd
*
* Return: buffer containing command with path on success, or NULL on failure
*/
char *add_end_path(const char *path, const char *cmd);

{
	char path[100];
	char cmd[100];

	printf("Enter path: ");
	scanf("%99s", path);

	printf("Enter command: ");
	scanf("%99s", cmd);

	char *result = add_end_path(path, cmd);

	if
		(result != NULL)
		{
			printf("Command with path: %s\n", result);
			free(result);
		}
	else
	{
		printf("Failed to allocate memory for command with path\n");
	}

	return (0);
}

char *add_end_path(const char *path, const char *cmd)
{
	size_t path_len = strlen(path);
	size_t cmd_len = strlen(cmd);

	char *buffer = malloc(path_len + cmd_len + 2);

	if
		(buffer == NULL)
			return (NULL);

	snprintf(buffer, path_len + cmd_len + 2, "%s/%s", path, cmd);

	return (buffer);
}
