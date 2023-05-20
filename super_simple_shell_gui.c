#include "main.h"

/**
 * main - super simple shell
 *
 * Return: Always 0.
 */

int main(void)
{
	while (1)
	{
		char *command = NULL;
		size_t command_size = 0, command_len;
		int status, ret, pid;

		printf("AGA_shell$: ");
		ssize_t bytes_read = getline(&command, &command_size, stdin);

		if (bytes_read == -1)
		{
			perror("getline");
			free(command);
			return (1);
		}

		/* Remove trailing newline character from the input*/
		command_len = _strlen(command);
		if (command_len > 0 && command[command_len - 1] == '\n')
			command[command_len - 1] = '\0';

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			free(command);
			return (1);
		}
		else if (pid == 0)
		{
			/* Child process*/
			ret = execve(command, command, NULL);
			if (ret == -1)
			{
				perror("execve");
				free(command);
				return (1);
			}
		}
		else
		{
			/* Parent process*/
			status;
			if (wait(&status) == -1)
			{
				perror("wait");
				free(command);
				return (1);
			}
		}

		free(command);
	}

	return (0);
}
