#include "main.h"



/**
 * read_cmd - read command and removes trailing end of line
 * @command:  string that will contain the command read
 * Return: 0 if cmd is read succesfully and different from \n
 * 1 if command read is \n
 * 2 if getline fails
 * 3 if getline encounters C-d
 */

int read_cmd(char **command)
{
	size_t command_len, command_size = 0;
	ssize_t bytes_read;

	/* read command*/
	bytes_read = getline(command, &command_size, stdin);

	if (bytes_read == -1)
	{
		/*perror("getline");*/
		return (2);
	}
	if (bytes_read == 0)
	{
		return (3);
	}
	if (*(*command + 0) == '\n')
		return (1);
	/* Remove trailing newline character from the input*/
	command_len = _strlen(*command);
	if (command_len > 0 && *(*command + command_len - 1) == '\n')
	{
		(*command)[command_len - 1] = '\0';
		return (0);
	}
	return (0);

}

/**
 * parse_cmd - parse command string into an array of arguments
 * @command: command string to be parsed
 * @args: array to store parsed arguments
 * Return: number of tokens in string command
 */
int parse_cmd(char *command, char **args)
{
	int i = 0;
	char *token;

	if (command == NULL)
		return (0);
	/*parse command and arguments*/
	token = strtok(command, " ");
	if (token == NULL)
	{
		/*command is empty*/
		return (0);
	}
	args[i] = token;
	i++;
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		args[i] = token;
		i++;
	}
	if (i == 1)
	{
		/*command is without arguments*/
		args[1] = NULL;
		return (1);
	}
	else
	{
		args[i] = NULL;
		return (i - 1);
	}
}

/**
 * execute_cmd - execute a command
 * @args: pointer to arry containing cmd and it's arguments
 * @file_name: name of executable file
 * @env: pointer to aray containing the environment
 * Return: 0 on success, otherwise 1
 */
int execute_cmd(char ***args, char *file_name, char **env)
{
	pid_t pid, wpid;
	int status;
	char *path;

	/*use the which function to locate the path of the file*/
	path = _which(*args[0], env);
	if (path == NULL)
	{
		perror(file_name);
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed\n");
		free(path);
		return (1);
	}
	if (pid == 0)/*child process*/
	{
		if (execve(path, *args, env) == -1)
		{
			perror(file_name);
			exit(1);
		}
	}
	else
	{/*parent process*/
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
			if (wpid == -1)
			{
				perror("waitpid");
				free(path);
				return (1);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(path);
	return (0);
}
