#include "shell.h"

void handle_sign(int signh);
/**
 * prompt - function to print prompt in interactive mode
 * Return: Nothing
*/
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
 * main - main function
 * Return: an integer
*/

int main(void)
{
	size_t n = 0;
	ssize_t read;
	pid_t c_pid;
	char *buff = NULL;
	char **av = NULL;
	char *s_dup = NULL;

	while (1)
	{
		prompt();
		read = getline(&buff, &n, stdin);
		if (read == -1)
		{
			free(buff);
			free(av);
			free(s_dup);
			exit(0);
		}
		if (buff[read - 1] == '\n')
			buff[read - 1] = '\0';
		c_pid = fork();
		if (c_pid == -1)
		{
			perror("An error occured");
			free(buff);
			buff = NULL;
			free(av);
			av = NULL;
			free(s_dup);
			s_dup = NULL;
		}
		if (c_pid == 0)
		{
			s_dup = _str_dupl(buff);
			av = _av(s_dup);
			_handle_buitin(&buff, &av, &s_dup);
			if (!av[0])
				break;
			if ((execve(av[0], av, environ)) == -1)
				perror(av[0]);
		}
		else
		{
			wait(NULL);
			free(buff);
			buff = NULL;
			free(av);
			av = NULL;
			free(s_dup);
			s_dup = NULL;
		}
	}
	free(buff);
	free(s_dup);
	free(av);
	return (0);
}

/**
 * handle_sign - function to handle signals
 * @signh: integer
 * Return: void
*/

void handle_sign(int signh)
{
	(void)signh;
	exit(0);
}
