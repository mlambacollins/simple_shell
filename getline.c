#include "shell.h"
/**
 * main - function for reading a line from command input.
 * Return: The number of characters read, or -1 if an error occurs.
 * @ac: Number of command-line arguments.
 * @av: Array of command-line arguments.
 * Return: 0 success, -1 error
*/
int main(int ac, char **av)
{
	char *prompt = " $ ";
	char *ptr = NULL;
	size_t n = 0;
	ssize_t read;

	(void)ac;
	(void)av;

	printf("%s", prompt);
	read = getline(&ptr, &n, stdin);
	if (read != -1)
	{
		printf("%s\n", ptr);
	}
	else
	{
		printf("Input Error.\n");
	}
	free(ptr);
	return (0);
}
