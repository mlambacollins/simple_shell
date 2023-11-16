#include "shell.h"
int main(void)
{
	char *arg_v[] = {"/bin/ls", "-l", NULL};
	char *envrn[] = {NULL};
	pid_t c_pid = fork();

	if (c_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (c_pid == 0)
	{
		if (execve(arg_v[0], arg_v, envrn) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
