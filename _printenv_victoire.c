#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry Point
 *
 * Description: This program prints all the environment
 * variables
 * Return: 0 (Success)
 */

int main(int ac, char *argv[], char *env[])
{
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}

	return (0);
}
