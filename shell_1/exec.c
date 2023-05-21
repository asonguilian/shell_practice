#include "shell.h"

/**
 * exec - executes the shell in interactive mode
 * @prompt: the prompt to be displayed
 * @file: the exe filename to be displayed on error
 *
 * Return: Nothing
 */

void exec(char *prompt, char *file)
{
	int status, val;
	pid_t pid;
	char *cmd, *argv[2];

	while (1)
	{
		putstring(prompt);
		val = _getcmd(&cmd);
		if (val == 1)
			continue;
		if (val == 2 || val == 3)
		{
			free(cmd);
			return;
		}
		argv[0] = cmd;
		argv[1] = NULL;
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(cmd);
		}
		if (pid == 0)
		{
			if (execve(argv[0], argv, __environ) == -1)
			{
				perror(file);
				free(cmd);
				exit(1);
			}
		}
		if (pid > 0)
		{
			wait(&status);
		}
	}
	free(cmd);
}
