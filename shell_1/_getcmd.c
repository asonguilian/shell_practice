#include "shell.h"

/**
 * _getcmd - gets a command from stdin
 * and replaces trailing \n with \0
 * @argv: the array to store the command passed
 *
 * Return: Nothing
 */

void _getcmd(char **argv)
{
	char *cmd;
	size_t n = 0;
	ssize_t leave;

	cmd = NULL;
	putstring("#cisfun$ ");
	leave = getline(&cmd, &n, stdin);

	if (leave < 0)
	{
		perror("getline");
		free(cmd);
	}
	else
	{
		if (cmd[leave - 1] == '\n')
			cmd[leave - 1] = '\0';
	}

	argv[0] = _strdup(cmd);
	free(cmd);
}
