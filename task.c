#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry Point
 *
 * Description: This program prints the process ID of a process
 * Return: 0 (Success)
 */

int main(void)
{
	pid_t process;

	process = getpid();

	printf("I am a process, and my process ID is %u\n", process);

	return (0);
}
