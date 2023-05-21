#include "shell.h"

/**
 * _getcmd - gets a command from stdin
 * and replaces trailing \n with \0
 * @cmd: the command
 *
 * Return: 0 or 1 (Success) 2 or 3 (Error)
 */

int _getcmd(char **cmd)
{
	size_t n = 0;
	ssize_t leave;
	int cmd_len;

	cmd_len = _strlen(*cmd);
	leave = getline(cmd, &n, stdin);

	if (leave == -1)
		return (2);
	if (leave == 0)
		return (3);
	if (*(*cmd + 0) == '\n')
		return (1);

	if (cmd_len > 0 && *(*cmd + cmd_len - 1) == '\n')
	{
		(*cmd)[cmd_len - 1] = '\0';
		return (0);
	}

	return (0);
}
