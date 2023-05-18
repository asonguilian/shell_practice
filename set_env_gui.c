#include "main.h"


int is_valid_name(const char *name)
{
    if (name == NULL || _strchr(name, '=') != NULL)
    {
        return (-1);
    }
	return (0);
}

char *create_env_string(const char *name, const char *value)
{
    size_t len_name = _strlen(name), len_value = _strlen(value), len;
	char *env_string;
	
	len = len_name + len_value + 2; /* +2 char for = and null terminator*/
    env_string = (char *)malloc(len);
	
    if (env_string != NULL)
    {
		_strcpy(env_string, name);
		env_string[name_len] = '=';
		_strcpy(env_string + name_len + 1, value);
		
    }
    return (env_string);
}

int _setenv_replace(const char *name, const char *value)
{
    char **envp = __environ;
    size_t len_name = _strlen(name);
	
    while (*envp != NULL)
    {
        if (_strncmp(*envp, name, len_name) == 0 && (*envp)[len_name] == '=')
	{
            free(*envp);
            *envp = (char *)value;
            return (0);
        }
        envp++;
    }

    return (-1);
}

int _setenv_add(const char *name, const char *value)
{
    size_t len_env = 0; /*size of environ*/
    char **envp = __environ;
	char **new_environ;

	/*loop to determine the length of environ */
    while (*envp != NULL)
    {
        len_env++;
        envp++;
    }
	
	new_environ = (char **)malloc((len_env + 2) * sizeof(char *));
    if (new_environ == NULL)
    {
        return (-1);
    }
    if (environ != NULL)
    {
	    _memcpy(new_environ, environ, envc * sizeof(char *));
	    free(environ);
    }
    environ = new_environ;

    environ[len_env] = (char *)value;
    environ[len_env + 1] = NULL;

    return (0);
}

int _setenv(const char *name, const char *value, int overwrite)
{
	char *env_string, *old_value;
	
    if (!is_valid_name(name))
    {
        return (-1);
    }

    env_string = create_env_string(name, value);
	
    if (env_string == NULL)
    {
        return (-1);
    }

    old_value = _getenv(name);
	
    if (old_value != NULL && !overwrite)
    {
        free(env_string);
        return (0);
    }

    if (old_value != NULL)
    {
        if (_setenv_replace(name, env_string) == -1)
	{
            free(env_string);
            return (-1);
        }
    }
    else
    {
        if (_setenv_add(name, env_string) == -1)
	{
            free(env_string);
            return (-1);
        }
    }

    return (0);
}