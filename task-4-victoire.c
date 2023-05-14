#include <stdio.h>
#include <string.h>

/**
 * main - Entry Point
 *
 * Description: This program tokenizes a string
 * Return: 0 (Success)
 */

int main(void)
{
	char str[]  = "Hello I Am Building A Simple Shell";
	char *delim = " ";
	char *tokenize;

	tokenize = strtok(str, delim);
	printf("%s\n", tokenize);

	return (0);
}
