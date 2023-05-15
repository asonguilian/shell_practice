#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


/**
  * _strlen -returns length of the string
  * @s: input string
  * Return: length of the string
  */

int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;
	return (count);
}

/**
 * main - simple shell
 *
 * Return: Always 0.
 */

int main(void)
{
	while (1)
	{
		char *command = NULL;
		size_t command_size = 0, command_len;
		ssize_t bytes_read;
		int ret, pid, status;

		printf("AGA_SHELL:$ ");
		bytes_read = getline(&command, &command_size, stdin);
		if (bytes_read == -1)
		{
			perror("getline error");
			free(command);
			return (1);
		}
		/*now we remove trailing \n from the input(cmd)*/
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
		else if (pid == 0)/*child process*/
		{
			ret = execl(command, command, NULL);
			if (ret == -1)
			{
				perror("execl");
				free(command);
				return (1);
			}
		}
		else/*parent process*/
		{
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



