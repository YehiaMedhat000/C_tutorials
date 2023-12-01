#include <stdio.h>

extern char **environ;

/**
 * main - Tutorial using environ()
 * Return: (0) Always
 */

int main(void)
{
	while (*environ)
		printf("%s\n", *environ++);
	return (0);
}
