#include "main.h"

/**
  * _strchr - returns the first occurence of a character c in a string s
  * @s: string
  * @c: character
  * Return: pointer to first occurence
  */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

/**
  * _strncmp - compares n bytes of string 1 with string 2
  * @s1: string1
  * @s2: string2
  * @n: numbver of bytes of string1 to use
  * Return: <0 if n bytes of s1 < s2
  * 0 if n bytes of s1 == s2
  * >0 if n bytes of s1 > s2
  */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);

}

