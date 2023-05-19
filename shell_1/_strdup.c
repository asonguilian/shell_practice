#include "shell.h"

/**
 * _strdup - returns a pointer to a space in memory
 * which contains a duplicated string
 * @str: the string to be duplicated
 *
 * Return: the duplicated string
 */

char *_strdup(char *str)
{
	int i = 0, len = 0;
	char *dup_str;

	while(str[i] != '\0')
	{
		len++;
		i++;
	}

	if (!str)
		return (NULL);

	dup_str = (char *)malloc(sizeof(char) * len + 1);
	if (dup_str == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup_str[i] = str[i];

	return (dup_str);
}
