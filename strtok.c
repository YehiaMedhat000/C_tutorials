#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Tutorial using strtok()
 * Return: (0) success, (1) failure
 */
int main(void)
{
	char str[] = "This is some text to split using strtok()";
	char *chunk;

	chunk = strtok(str, " ");
	while (chunk != NULL)
	{
		printf("%s\n", chunk);
		chunk = strtok(NULL, " ");
	}
	return (0);
}
