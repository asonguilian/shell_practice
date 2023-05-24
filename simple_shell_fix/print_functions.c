#include "main.h"

/**
 * print_msg - prints a string on stdout
 * @msg: string to be printed
 */

void print_msg(char *msg)
{
	size_t len = _strlen(msg);

	write(STDOUT_FILENO, msg, len);
}

/**
 * print_env - prints the environment
 * @env: pointer to array containing the environment
 */
void print_env(char **env)
{
	unsigned int i = 0;

	print_msg("\n");
	while (env[i] != NULL)
	{
		print_msg(env[i]);
		print_msg("\n");
		i++;
	}
}
