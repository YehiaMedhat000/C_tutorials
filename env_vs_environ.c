#include <stdio.h>

extern char **environ;

/**
 * main - Tutorial using environ and env
 * @argc: Arguments count
 * @argv: Arguments values
 * @envp: Environment variables
 * Return: (0) Always
 */

int main(int argc, char **argv, char **env)
{
	argc = argc;
	argv = argv;
	printf("Address of envp: %p\n", *env);
	printf("Address of environ: %p\n", *environ);
	return (0);
}
