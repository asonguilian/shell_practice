#include "main.h"

/**
  * is_valid_name - verifies if the string is a valid env variable
  * @name: envrionment variable
  * Return: 0 if it is valis, -1 otherwise
  */
int is_valid_name(const char *name)
{
	if (name == NULL || _strchr(name, '=') != NULL)
	{
		return (-1);
	}
	return (0);
}
/**
  * create_env_string - creates a string for an env variable format name=value
  * @name: name of env variable
  * @value: given value
  * Return: new string containing name=new_value
  */

char *create_env_string(const char *name, const char *value)
{
	size_t len_name = _strlen(name), len_value = _strlen(value), total_len;
	char *env_string;

	if (name == NULL)
		return (NULL);

	total_len = len_name + len_value + 2; /* +2 char for = and null terminator*/
	env_string = (char *)malloc(total_len * sizeof(char));

	if (env_string == NULL)
		return (NULL);
	_memcpy(env_string, name, len_name);
	env_string[len_name] = '=';
	if (value != NULL)
		_memcpy(env_string + len_name + 1, value, len_value);
	env_string[total_len - 1] = '\0';

	return (env_string);
}
/**
  * _set_env_replace - updates the value of an existing env variable
  * @name: env variable
  * @value: new value to be given
  * Return: 0 on succes, -1 otherwise
  */
int _set_env_replace(const char *name, const char *value)
{
	char **envp = __environ;
	size_t len_name = _strlen(name);
	char *old_env_string, *new_env_string;

	if (name == NULL)
		return (-1);

	/*loop to find the env var with matching name*/
	while (*envp != NULL)
	{
		if (_strncmp(*envp, name, len_name) == 0 && (*envp)[len_name] == '=')
		{
			old_env_string = *envp;
			new_env_string = create_env_string(name, value);
			if (new_env_string == NULL)
				return (-1);
			*envp = new_env_string;
			free(old_env_string);
			return (0);
		}
		envp++;
	}

	return (-1);
}

/**
  * _set_env_add - adds a new env variable and it's value
  * @name: env variable name
  * @value: value of name
  * Return: on success 0, otherwise -1
 */

int _set_env_add(const char *name, const char *value)
{
	size_t i, len_env = 0; /*size of environ*/
	char **envp = __environ;
	char **new_environ;
	char *env_string;

	/*loop to determine the length of environ */
	while (*envp != NULL)
	{
		len_env++;
		envp++;
	}

	/*create new env var*/
	env_string = create_env_string(name, value);
	if (env_string == NULL)
		return (-1);
	/*create space for new environment variable array*/
	new_environ = (char **)malloc((len_env + 2) * sizeof(char *));
	if (new_environ == NULL)
	{
		free(env_string);
		return (-1);
	}
	/*copy exisitng env vars into new environ array*/
	envp = __environ;
	for (i = 0; i < len_env; i++)
		new_environ[i] = envp[i];
	/*add new env var to the new environ array*/
	new_environ[len_env] = env_string;
	new_environ[len_env + 1] = NULL;
	/* replace old environ var with new environ var*/

	__environ = new_environ;
	return (0);
}
/**
  * _setenv - updates or adds an env variable
  * @name: environment variable name
  * @value: value of env variable
  * @overwrite: determines if an existing env var will be updated or not
  * Return: 0 on success, -1 otherwise
  */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *env_string, *old_value;

	/*check if name is a valid env var*/
	if (!is_valid_name(name))
	{
		return (-1);
	}
	/* create new env var string*/
	env_string = create_env_string(name, value);

	if (env_string == NULL)
	{
		return (-1);
	}
	/*get old value of env var if it exist*/
	old_value = _getenv(name);

	/*update the env var if it already exist*/
	if (old_value != NULL)
	{
		if (overwrite)
		{
			if(_set_env_replace(name, value) == -1)
			{
				free(env_string);
				return (-1);
			}
		}
		else
		{
			free(env_string);
			return (0);
		}
	}
	else/*env var does not exist so we add it*/
	{
		if (_set_env_add(name, value) == -1)
		{
			free(env_string);
			return (-1);
		}
	}

	return (0);
}
