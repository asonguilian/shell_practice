#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Entry Point
 *
 * Description: This program mimics a Bash Shell
 * Return: 0 (Success) or -1 (Failure)
 */

int main(void)
{
	char *cmd = NULL;
	size_t n = 0;
	ssize_t leave;
	int status;
	pid_t pid, wait_pid;

	/* Starting of infinte loop */
	while (1)
	{
		printf("my_shell:$ ");
		leave = getline(&cmd, &n, stdin); /* getting input from keyboard */
		/* Condition to exit the shell */
		if (leave == -1)
		{
			printf("Leaving the shell...\n");
			free(cmd);
			return (-1);
		}
		/* Removing the trailing \n and replacing it with \0 */
		if (leave != -1)
		{
			if (cmd[leave - 1] == '\n')
				cmd[leave - 1] = '\0';
		}
		/* Setting argv to the cmd */
		char *argv[] = {"/bin/sh", "-c", cmd, NULL};
		char *envp[] = {NULL};
		/* Creating the child process */
		pid = fork();
		if (pid == -1)
		{
			perror("Fork");
			free(cmd);
			return (-1);
		}
		else if (pid == 0)
		{
			if (execve(argv[0], argv, envp) == -1)
			{
				perror("Execve");
				free(cmd);
				return (-1);
			}
		}
		if (pid > 0)
		{
			wait_pid = wait(&status);
			if (wait_pid == -1)
			{
				perror("Wait");
				free(cmd);
				return (-1);
			}
		}
	}

	free(cmd);
	return (0);
}
