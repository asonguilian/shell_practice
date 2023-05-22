#include "main.h"

/**
  * _getenv - gets an environment variable
  * @name: name of enivronment variable
  * Return: content of environment variable if found
  * otherwise NULL
  */

char *_getenv(const char *name)
{
	char **env = __environ;
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

/**
  * print_path_dir - prints path directories line by line
  *
  */
void print_path_dir(void)
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
  * Return: linked_list of directories
  */
path_list *get_path_list(void)
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

	while (dir != NULL)
	{
		node = malloc(sizeof(path_list));
		node->dir = _strdup(dir);
		node->next = NULL;
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
/**
  * print_path_list - prints a linked list of directories
  * @head: pointer to the linked list
  */
void print_path_list(path_list *head)
{
	path_list *node = head;

	printf("\nPrinting path list directories\n");
	while (node != NULL)
	{
		printf("%s\n", node->dir);
		node = node->next;
	}
}

