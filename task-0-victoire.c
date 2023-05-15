#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry Point
 *
 * Description: This program prints the PID of a parent process
 * Return: 0 (Success)
 */

int main(void)
{
	pid_t parent;

	parent = getppid();

	printf("My parent process ID is %u\n", parent);

	return (0);
}
