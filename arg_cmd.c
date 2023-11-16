#include "shell.h"
/**
 * _argc - function for number of command arguments
 * @s: string pointer to check
 * Return: integer
*/

int _argc(char *s)
{
	char *new_chars;
	char *token;
	int j = 0;

	new_chars = _str_dupl(s);
	token = strtok(new_chars, " ");
	while (token)
	{
		j++;
		token = strtok(NULL, " ");
	}
	free(new_chars);
	return (j);
}
