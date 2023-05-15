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

	for (i = 0; i < 5; i++)
	{
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			return (1);
		}
		else if (pid == 0)
		{
			execl("/bin/ls", "ls", "-l", "/tmp", NULL);
			perror("execl");
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
