#include "main.h"

/**
  * _which - finds the path to a given command
  * @cmd: command namespace
  * @environ: environment variable
  * Return: the path to cmd
  */

char *_which(char *cmd, char **environ)
{
	char *path, *dir, *full_path, *path_copy;
	int path_length, cmd_length;
	struct stat st;

	path = _getenv("PATH", environ);
	/*check if path is empty*/
	if (path == NULL || *path == '\0')
		return (NULL);
	path_length = _strlen(path);
	cmd_length = _strlen(cmd);
	full_path = malloc(sizeof(char) * path_length * cmd_length + 2);
	if (full_path == NULL)
		return (NULL);
	path_copy = _strdup(path);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	/*check if command is an absolute path*/
	if (cmd[0] == '/')
	{
		if (stat(cmd, &st) == 0)
		{
			full_path = _strdup(cmd);
			return (full_path);
		}
	}
	free(full_path);
	free(path_copy);
	return (NULL);
}
