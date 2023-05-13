#include <stdio.h>

/**
 * main - Entry Point
 * @ac: argument count
 * @av: an array of strings of argument
 *
 * Description: This program prints the contents of av without using ac
 * Return: 0 (Success)
 */

int main(int ac, char *av[])
{
	(void)ac;
	char **ptrAv = av;

	while(*ptrAv)
	{
		printf("%s\n", *ptrAv++);
	}

	return (0);
}
