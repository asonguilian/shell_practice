#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry Point
 *
 * Description: This program prints with getline
 * Return: 0 (Success)
 */

int main(void)
{
	char *buffer;
	size_t bufsize = 10;

	buffer = malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
		return (-1);
	printf("$ ");

	getline(&buffer, &bufsize, stdin);
       printf("%s\n", buffer);
	free(buffer);
 	return (0);	
}
