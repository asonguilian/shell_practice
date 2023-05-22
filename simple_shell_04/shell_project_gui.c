#include "main.h"


/**
 * print_msg - prints a string on stdout
 * @msg: string to be printed
 */

void print_msg(char *msg)
{
	size_t len = _strlen(msg);

	write(STDOUT_FILENO, msg, len);
}

/**
 * exit_shell - exit the shell
 * @status: exit status code
 */
void exit_shell(int status)
{
	pid_t wpid;
	int child_status;
	
	do {
		wpid = waitpid(-1, &child_status, WNOHANG);
		if (wpid > 0)
		{
			print_msg("child process(es) terminating");
		}
	} while (wpid > 0);
	exit(status);
}

/**
 * print_env - prints the environment
 * @env: pointer to array containing the environment
 */
void print_env(char **env)
{
	unsigned int i = 0;

	print_msg("\n");
	while (env[i] != NULL)
	{
		print_msg(env[i]);
		print_msg("\n");
		i++;
	}
}
/**
 * handle_builtin - handle built-in commands
 * @args: pointer to array of command arguments
 * @env: pointer to array containing environment
 * @num_args: number of tokens in command
 * Return: 1 if command is built-in command, otherwise 0
 */
int handle_builtin(char **args, char **env, int num_args)
{
	char *exit_msg = "Usage: exit [STATUS]\n\t\tSTATUS must be an integer\n";
	if (num_args > 0)
	{
		if (_strcmp(args[0], "exit") == 0)
		{
			if (num_args == 2)
			{
				if (_isinteger(args[1]) == 1)
				{
					exit_shell(_atoi(args[1]));
				}
				else
				{
					print_msg(exit_msg);
					return (1);
				}
			}
			else if (num_args == 1)
			{
				exit_shell(0);
				return (1);
			}
			else
			{
				return (0);
			}
		}
		else if (num_args == 1 && _strcmp(args[0], "env") == 0)
		{
			print_env(env);
			return (1);
		}
		else
		{
			return (0);
		}
	}
	return (0);
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
	path = _which(*args[0]);
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
	if (pid == 0)
	{
		/*child process*/
		if (execve(path, *args, env) == -1)
		{
			perror(file_name);
			exit(1);
		}
	}
	else
	{
		/*parent process*/
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
			if (wpid == -1)
			{
				perror("waitpid");
				free(path);
				/*free(args) if allocated dynamical*/
				return (1);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(path);
	/*free(args); if dynamic allocation*/
	return (0);
}

/**
 * main - super simple shell
 * @ac: number of argument
 * @argv: pointer to array containing arguments
 * @env: pointer to array containing the environment
 * Return: Always 0.
 */
int main(int ac, char *argv[], char **env)
{
	char *command = NULL, *prompt = "#cisfun$ ";
	int cmd_val, num_args, flag_builtin;
	char **args;

	(void)ac;
	if (isatty(STDIN_FILENO))/*interactive mode*/
	{
		while (1)
		{
			print_msg(prompt);
			fflush(stdout);
			cmd_val = read_cmd(&command);
			if (cmd_val == 1)
				continue;
			if (cmd_val == 2 || cmd_val == 3)
			{
				free(command);
				exit(0);
			}
			args = malloc(sizeof(char *) * 1024);
			if (args == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			num_args = parse_cmd(command, args);
			if (num_args == 0)
			{
				free(command);
				free(args);
				return (0);
			}
			flag_builtin = handle_builtin(args, env, num_args);
			if (flag_builtin == 1)
			{
				free(command);
				free(args);
				continue;
			}
			execute_cmd(&args, argv[0], env);
			free(command);
			free(args);
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
		args = malloc(sizeof(char *) * 1024);
		if (args == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		num_args = parse_cmd(command, args);
		if (num_args == 0)
		{
			free(command);
			free(args);
			return (0);
		}
		flag_builtin = handle_builtin(args, env, num_args);
		if (flag_builtin == 1)
		{
			free(command);
			free(args);
			return (0);
		}
		execute_cmd(&args,argv[0], env);
		free(command);
		free(args);
	}
	return (0);
}
