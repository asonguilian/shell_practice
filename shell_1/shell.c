#include "shell.h"

/**
 * main - Entry Point
 * @ac: argument count
 * @argv: array of arguments
 *
 * Description: This program mimics a Bash Shell
 * Return: 0 (Success) or -1 (Failure)
 */

int main(int ac, char **argv)
{

	(void) ac;

	exec("#cisfun ", argv[0]);
	return (0);
}
