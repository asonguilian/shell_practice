#include "main.h"

/**
  *_strlen - returns the length of a string s
  *@s: string whose length will be returned
  *
  * Return: the length of the string s
  */

int _strlen(const char *s)
{
	int count = 0;
	while (*(s + count) != '\0')
		count++;
	return (count);
}

/**
  * _strcpy - copies the string src to the string dest
  *@dest: pointer to which the string is copied
  *@src: pointer to the string to be copied
  * Return: the pointer dest
  */

char *_strcpy(char *dest, const char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);
}

/**
  * _strcat - concatenates  two strings
  *
  *@src: pointer to input string
  *@dest: pointer to output string
  *
  * Return: returns a pointer to a string dest
  */

char *_strcat(char *dest, const char *src)
{
	int  i, ldest, lsrc;

	ldest = _strlen(dest);
	lsrc = _strlen(src);

	for (i = 0; i < lsrc; i++)
		dest[ldest + i] = src[i];
	dest[ldest + i] = '\0';
	return (dest);
}

/**
  * _memcpy - copies n bytes of memory area from src to dest
  * @dest:  deestination memory area
  * @src:  source memory area
  * @n: number of bytes to be copied
  * Return: the pointer to dest
  */

char *_memcpy(char *dest, const char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
/**
  *_strdup - duplicates a string
  * @str: original string
  * Return: pointer to string duplicate
  */

char *_strdup(const char *str)
{
	size_t len = _strlen(str);
	char *new_str = malloc(len + 1);

	if (new_str == NULL)
	{
		perror("Error during malloc");
		return (NULL);
	}
	_strcpy(new_str, str);
	return (new_str);
}
