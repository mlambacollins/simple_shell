#include "shell.h"

/**
 * _strlen - function for determining the length of string
 * @s: string to check length
 * Return: an integer
*/

int _strlen(char *s)
{
	int l = 0;

	if (s == NULL)
	{
		return (0);
	}
	while (s[l])
	{
		l++;
	}
	return (l);
}
