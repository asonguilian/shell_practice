#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
  * _strlen - returns length of string
  * @s: input string
  * Return: length of string
  */
int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;
	return (count);
}

/**
  * split_string - splits a string
  * @str: string to be spllit
  * @delim: string delimiter
  * @num_tokens: number of tokens in str
  * Return: an array of each word (tokens) in the string str
  */

char **split_string(char *str, const char *delim, size_t *num_tokens)
{
	char **tokens = NULL;
	size_t count = 0, len, i;
	char *token = strtok((char *)str, delim);
	char *new_token;

	if (str == NULL || delim == NULL || num_tokens == NULL)
		return (NULL);
	while (token != NULL)
	{
		tokens = realloc(tokens, (count + 1) * sizeof(char *));
		if (tokens == NULL)
			return (NULL);
		len = _strlen(token);
		new_token = malloc(len + 1);
		if (new_token == NULL)
			return (NULL);
		for (i = 0; i < len; i++)
			new_token[i] = token[i];
		new_token[len] = '\0';
		tokens[count] = new_token;
		count++;
		token = strtok(NULL, delim);
	}

	*num_tokens = count;
	return (tokens);
}

/**
  * main - test the function split_string
  * Return: 0
  */
int main(void)
{
	char str[] = "This is a test string";
	const char delim[] = " ";
	size_t num_tokens = 0;
	size_t i;

	char **tokens = split_string(str, delim, &num_tokens);

	if (tokens != NULL)
	{
		for (i = 0; i < num_tokens; i++)
		{
			printf("Token %lu: %s\n", i, tokens[i]);
		}
		free(tokens);
	}
	return (0);
}
