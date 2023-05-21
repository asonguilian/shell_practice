#include "main.h"


/**
 * print_error - displays an error msg to stderr
 * @msg: error message to be printed
 */

void print_error(const char *msg)
{
	size_t len = _strlen(msg);

	write(STDERR_FILENO, msg, len);
}

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
		return (i);
	}
}

/**
 * execute_cmd - execute a command
 * @command: command to be executed
 * @file_name: name of executable file
 * Return: 0 on success, otherwise 1
 */
int execute_cmd(char *command, char *file_name)
{
	pid_t pid;
	int status;
	char *args[1024], *path;

	parse_cmd(command, args);
	/*use the which function to locate the path of the file*/
	path = _which(args[0]);
	if (path == NULL)
	{
		print_error(file_name);
		print_error(": command not found\n");
/*		printf("args[0] is %s$ and path is %s$\n", args[0], path);*/
/*		free(path);*/
		return (1);
	}
/*	printf("B4 fork: %s$=====%s$\n", args[0], path);*/
	pid = fork();
	if (pid == -1)
	{
		print_error("Fork failed\n");
		free(path);
		return (1);
	}
	if (pid == 0)
	{
		/*child process*/
		if (execve(path, args, __environ) == -1)
		{
			perror(file_name);
			exit(1);
		}
	}
	else
	{
		/*parent process*/
		wait(&status);
	}
	free(path);
	return (0);
}

/**
 * main - super simple shell
 * @ac: number of argument
 * @argv: pointer array containing arguments
 * Return: Always 0.
 */
int main(int ac, char *argv[])
{
	char *command = NULL, *prompt = "#cisfun$ ";
	int cmd_val;

	(void)ac;
	if (isatty(STDIN_FILENO))/*interactive mode*/
	{
		while (1)
		{
			write(STDOUT_FILENO, prompt, _strlen(prompt));
			fflush(stdout);
			cmd_val = read_cmd(&command);
			if (cmd_val == 1)
				continue;
			if (cmd_val == 2 || cmd_val == 3)
			{
				free(command);
				exit(0);
			}
			execute_cmd(command, argv[0]);
			free(command);
		}
	}
	else
	{
		cmd_val = read_cmd(&command);
		if (cmd_val == 2 || cmd_val == 3)
		{
			free(command);
			exit(0);
		}
		execute_cmd(command, argv[0]);
		free(command);
	}
	return (0);
}
