#include "shell.h"

/**
 * putstring - writes a string to stdout
 * @string: the string to be written
 *
 * Return: Nothing
 */

void putstring(char *string)
{
	while (*string != '\0')
	{
		write(1, string, 1);
		string++;
	}
}
