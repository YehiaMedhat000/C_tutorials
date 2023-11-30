#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Write a program that executes the command ls -l /tmp in 5 different child processes
 Each child should be created by the same process (the father)
 Wait for a child to exit before creating a new child*/

/**
 * main - Tutorial using fork()
 * Return: (0) success, (1) failure
 */

int main(void)
{
	char *args[] = {
		"/usr/bin/ls",
		"-l",
		"/tmp",
		NULL
	};
	char *env[] = {
		"TEST=environment variable",
		NULL
	};

	execve("/usr/bin/ls", args, env);

	return (0);
}
