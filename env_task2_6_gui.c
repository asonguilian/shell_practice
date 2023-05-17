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
  * _setenv - sets an environment variable
  * @name: 
  * @value: 
  * @overwite: 
  * Return: 
  */
int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	size_t len_value = _strlen(value);
	size_t len_name = _strlen(name);
	int result = 0;
	char *name_value = malloc(len_name + len_value + 1);
	char *old_value;
/**
  * print_path_dir - prints path directories line by line
  * Return : nothing
  *
  */
void print_path_dir()
{
	char *path = _getenv("PATH");
	char *delim = ":";
	char *dir;

	if (path == NULL)
	{
		printf("PATH environment variable not found\n");
		return;
	}
	dir = strtok(path, delim);

	while (dir != NULL)
	{
		printf("%s\n", dir);
		dir = strtok(NULL, delim);
	}
}
/**
  * get_path_list - builds a linked list of path directories
  * Return : path_list
  */
path_list *get_path_list()
{
	char *path = _getenv("PATH");
	char *delim = ":", *dir;
	path_list *head = NULL, *tail = NULL, *node;

	if (path == NULL)
	{
		printf("PATH env variable not found\n");
		return (NULL);
	}
	dir = strtok(path, delim);

	while (dir !=NULL)
	{
		node = malloc(sizeof(path_list));
		node->dir = _strdup(dir);
		node-> next = NULL;
		if (head == NULL)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
		dir = strtok(NULL, delim);
	}
	return (head);
}
void print_path_list(path_list *head)
{
	path_list *node = head;
	printf("\nPrinting path list directories\n");
	while(node != NULL)
	{
		printf("%s\n", node->dir);
		node = node->next;
	}
	return;
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
int main(void)
{
/*	print_path_dir();*/
	path_list *head = get_path_list();
	print_path_list(head);
	return (0);
}
