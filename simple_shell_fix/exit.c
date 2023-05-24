#include "main.h"

/**
 * exit_shell - exit the shell
 * @status: exit status code
 */
void exit_shell(int status)
{
	pid_t wpid;
	int child_status;

	do {
		wpid = waitpid(-1, &child_status, WNOHANG);
		if (wpid > 0)
		{
			print_msg("child process(es) terminating");
		}
	} while (wpid > 0);
	exit(status);
}
