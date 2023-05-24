#include "main.h"

/**
  * _getenv - gets an environment variable
  * @name: name of enivronment variable
  * @environ: pointer to array of string of environment variables
  * Return: content of environment variable if found
  * otherwise NULL
  */

char *_getenv(char *name, char **environ)
{
	char **env = environ;
	size_t name_len = _strlen(name);

	while (*env != NULL)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (*env + name_len + 1);
			/*return the value after the '=' */
		}
		env++;
	}
	return (NULL);
}

