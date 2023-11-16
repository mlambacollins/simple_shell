#include "shell.h"

/**
 * _handle_buitin - function for checking builtin functions
 * @line: first parameter
 * @av: second space param
 * @s_dup: third param
 * Return: void
*/
void _handle_buitin(char **line, char ***av, char **s_dup)
{
	int l;
	int j = 0;
	char buffer[] = "\n";

	if ((_strcmp((*av)[0], "exit")) == 0)
	{
		free(*line);
		free(*av);
		free(*s_dup);
		exit(2);
	}
	if ((_strcmp((*av)[0], "env")) == 0)
	{
		while (environ[j])
		{
			l = _strlen(environ[j]);
			write(STDOUT_FILENO, environ[j], l);
			write(STDOUT_FILENO, buffer, sizeof(buffer));
			j++;
		}
		free(*line);
		free(*av);
		free(*s_dup);
		exit(0);
	}
	return;
}
