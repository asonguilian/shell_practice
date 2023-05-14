#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main -Entry Point
 *
 * Description: This program executes a command in 5 diffetnt
 * child processes
 * Return: 0 (Success)
 */

int main(void)
{
	pid_t process;
	int status, i;

	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		process = fork();
	/*	process = getpid();*/
	/*	printf("My PID is %u\n", process);*/
		if (process == -1)
		{
			perror("Error\n");
			exit(98);
		}

		else if (process == 0)
		{
			printf("My PID is %u\n", getpid());
			printf("My PPID is %u\n", getppid());
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error\n");
				exit(97);
			}
			else
			{
				printf("Done\n");
			}
		}
		else if (process > 0)
		{
			wait(&status);
		}
	}

	return (0);
}
