#include <stdio.h>
#include <stdlib.h>

/**
  * main - waits for user to enter a command
  *
  * Return: always 0
  */

int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;

	while (1)
	{
		printf("$ ");
		if (getline(&command, &bufsize, stdin) == -1)
			break;
		printf("%s\n", command);
	}
	free(command);
	return (0);
}
