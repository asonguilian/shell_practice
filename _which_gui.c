#include "main.h"

/**
  * _which - finds the path to a given file(command)
  * @cmd: the string containing the cmd
  * Return: the path to cmd
  */

char *_which(const char *cmd)
{
	char *path = getenv("PATH");
	char *dir, *full_path;
	int path_length, cmd_length;
	struct stat st;

	path_length = _strlen(path);
	cmd_length = _strlen(cmd);
	full_path = malloc(sizeof(char) * path_length * cmd_length + 2);
	if (full_path == NULL)
		return (NULL);
	dir = strtok(path, ":");
	while (dir != NULL)
	{
		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);
		if (stat(full_path, &st) == 0)
			return (full_path);
		dir = strtok(NULL, ":");
	}
	free(full_path);
	return (NULL);
}

/**
  * main - entry point
  * @argc: file name
  * @argv: array containing file(s) to be located
  * Return: 0
  */

int main(int argc, char *argv[])
{
	unsigned int i;
	char *cmd_path;

	if (argc < 2)
	{
		printf("Usage: %s file_name ....\n", argv[0]);
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		cmd_path = _which(argv[i]);
		if (cmd_path != NULL)
		{
			printf("%s is located in %s\n", argv[i], cmd_path);
		}
		else
		{
			printf("Command not found\n");
			printf("argv[i] is %s and cmd_path is %s\n", argv[i], cmd_path);
		}
		i++;
	}
	return (0);
}

