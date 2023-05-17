#include "main.h"

/**
  * _strncmp - compares n bytes of string 1 with string 2
  * @s1: string1
  * @s2: string2
  * @n: numbver of bytes of string1 to use
  * Return: <0 if n bytes of s1 < s2
  * 0 if n bytes of s1 == s2
  * >0 if n bytes of s1 > s2
  */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

/**
  * _getenv - gets an environment variable
  * @name: name of enivronment variable
  * Return: content of environment variable if found
  * otherwise NULL
  */

char *_getenv(const char *name)
{
	extern char **environ;
	char **env = environ;
	size_t name_len = _strlen(name);

	while(*env != NULL)
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

/**
  * main - entry point
  * @argc: number of arguments
  * argv: environment variable names
  * Return: 0
  */
  /*
int main(int argc, char *argv[])
{
	int i;
	char *value;

	if(argc < 2)
	{
		printf("Usage: %s environment_variable_name1 ....\n", argv[0]);
		return (1);
	}

	i = 1;
	while(argv[i])
	{
		printf("In while loop before _getenv call\n");
		value = _getenv(argv[i]);
		printf("In while loop after _getenv call\n");
		if (value != NULL)
		{
			printf("The value of %s is\n\n%s\n", argv[i], value);
		}
		else
		{
			printf("The variable %s was not found\n", argv[i]);
		}
		i++;
	}
	return (0);
}

*/