#ifndef SHELL_H
#define SHELL_H

void start_prompt(void);
char *read_command(void);
char **get_array_from_str(char *str, char **env);
char **_which(char *foundpath);
int executable_command(char **av, char **args, char **env,
		int status_main, int count);

#endif
