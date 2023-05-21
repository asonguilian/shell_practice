#include "shell.h"

/**
 * _strlen - calculates the length of a string
 * @str: the string
 *
 * Return: the string length
 */

int _strlen(char *str)
{
	int len = 0;

	while (*str)
	{
		len++;
		str++;
	}

	return (len);
}
