#include "shell.h"

/**
 * _av - function for creating array arguments
 * @line: line for reading
 * Return: characters created
*/

char **_av(char *line)
{
	char *token;
	char **av;
	size_t arg_c;
	int nums = 0;

	arg_c = _argc(line);
	arg_c++;
	av = malloc(sizeof(char *) * arg_c);
	token = strtok(line, " ");
	while (token)
	{
		av[nums] = token;
		token = strtok(NULL, " ");
		nums++;
	}
	av[nums] = NULL;
	return (av);
}
