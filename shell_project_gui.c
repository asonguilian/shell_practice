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
 * run_shell - runs the shell in interactive mode
 * @prompt: the prompt to display before each command
 * @file_name: name of the executable file to be displayed in error message
 */
void run_shell(const char *prompt, char *file_name)
{
	char *command = NULL, *args[2];
	pid_t pid;
	int status, cmd_val;

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
		args[0] = command;
		args[1] = NULL;
		pid = fork();
		if (pid < 0)
		{
			print_error("Fork failed\n");
			exit(1);
		}
		else if (pid == 0)
		{
			if (execve(command, args, __environ) < 0)
			{
				perror(file_name);
				free(command);
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
		free(command);
	}
}

/**
 * run_command - runs the shell in non-interactive mode with a single command
 ** @command: the command to run
 */
void run_command(const char *command)
{
	char *args[2];
	int cmd_val;

	cmd_val = read_cmd((char **)&command);
	if (cmd_val == 2 || cmd_val == 3)
	{
		free((char *)command);
		exit(0);
	}
	args[0] = (char *)command;
	args[1] = NULL;
	if (execve(command, args, __environ) < 0)
	{
		perror("execve");
		free((char *)command);
		exit(1);
	}
	free((char *)command);
}

/**
 * main - super simple shell
 * @ac: number of params
 * @argv: list of parameters
 * Return: Always 0.
 */
int main(int ac, char *argv[])
{
	(void)ac;

	if (isatty(STDIN_FILENO))
	{
		/* Running in interactive mode */
		run_shell("#cisfun$ ", argv[0]);
	}
	else
	{
		/* Running in non-interactive mode */
		run_command(argv[1]);
	}

	return (0);
}

