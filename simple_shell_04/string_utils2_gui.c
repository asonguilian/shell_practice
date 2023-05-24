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
/**
  * _strcmp - compares two strings
  * @s1: pointer to string 1
  * @s2: pointer to string 2
  * Return: < 0 if s1 is less than s2
  * 0 if s1 equal s2
  * > 0 if s1 > s2
  */
int _strcmp(const char *s1, const char *s2)
{
	int l1, l2, i, n, dif;

	dif = 0;
	l1 = _strlen(s1);
	l2 = _strlen(s2);
	if (l1 <= l2)
		n = l1;
	else
		n = l2;
	for (i = 0; i < n; i++)
	{
		dif = s1[i] - s2[i];
		if (dif != 0)
			return (dif);
	}
	dif = s1[i] - s2[i];
	return (dif);
}
/**
  * _isinteger - checks if a string is an integer
  * @str: string to check
  * Return: 1 is string is an integer, 0 otherwise
  */
int _isinteger(char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
	{
		str++;
		if (*str == '\0')
			return (0);
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		str++;
	}
	return (1);
}
