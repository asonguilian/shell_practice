#include "main.h"

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
