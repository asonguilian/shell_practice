#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
  * main - fork + wait + exec
  * Return: 0 for parent, 1 for child
  */

int main(void)
{	
	int i, status;
	pid_t pid;
	char *args[] = {"ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			return (1);
		}
		else if (pid == 0)
		{
			execve("/bin/ls", args, NULL);
			perror("execve");
			return (1);
		}
		else
		{
			if (wait(&status) == -1)
			{
				perror("wait");
				return (1);
			}
		}
	}
	return (0);
}
