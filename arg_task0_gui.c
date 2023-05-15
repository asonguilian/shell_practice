#include <stdio.h>

/**
  * main - prints arguments
  *
  * Return : always 0
  */

int main(int ac __attribute__((unused)), char **av)
{
	int i = 0;
	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return 0;
}
