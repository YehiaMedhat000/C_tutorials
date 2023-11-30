#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - Tutorial using getline
 * and EOF macro
 * @argc: Arguments count
 * @argv: Arguments values
 * Return: (0) success, (1) failure
 */

int main()
{
	char *lineptr = NULL;
	size_t n = 0;

	printf("$ ");
	while (getline(&lineptr, &n, stdin) != EOF)
	{
		printf("%s", lineptr);
		printf("$ ");
	}

	return (0);
}
