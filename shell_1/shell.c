#include "shell.h"

/**
 * main - Entry Point
 *
 * Description: This program mimics a Bash Shell
 * Return: 0 (Success) or -1 (Failure)
 */

int main(int ac, char **argv)
{
	char **env = __environ;
	pid_t wait_pid, pid;
	int status;

	(void) ac;
	argv = malloc(sizeof(char *) * 2);
	if (argv == NULL)
	{
		perror("Failed to allocate memory");
		return (-1);
	}
	while (1)
	{
		_getcmd(argv);
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(argv);
			return (-1);
		}
		else if (pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				perror(argv[0]);
				free(argv);
				return (-1);
			}
		}
		if (pid > 0)
		{
			wait_pid = wait(&status);
			if (wait_pid == -1)
			{
				perror("wait");
				free(argv);
				return (-1);
			}
		}
	}

	free(argv);
	return (0);
}
