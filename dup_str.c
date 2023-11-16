#include "shell.h"

/**
 * _str_dupl - function to duplicate a string
 * @s : string to be duplicated
 * Return: char
*/

char *_str_dupl(char *s)
{
	char *new_chars;
	char *count = s;
	int j = 0;

	while (*count)
	{
		count++;
		j++;
	}
	new_chars = malloc(sizeof(char) * (j + 1));
	j = 0;
	count = s;
	while (*count)
	{
		*(new_chars + j) = *count;
		count++;
		j++;
	}
	*(new_chars + j) = '\0';
	return (new_chars);
}
