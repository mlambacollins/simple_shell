#include "shell.h"

/**
 * _strcmp - function for comparing the length of two strings
 * @s1: first string
 * @s2: second string
 * Return: integer
*/
int _strcmp(char *s1, char *s2)
{
	int j = 0;
	int len1, len2;

	if (s1 == NULL || s2 == NULL)
	{
		return (-1);
	}
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	if (len1 == len2)
	{
		while (s1[j])
		{
			if (s1[j] != s2[j])
			{
				return (-1);
			}
			j++;
		}
		return (0);
	}
	return (-1);
}
