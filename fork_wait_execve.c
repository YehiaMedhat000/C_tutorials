#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* Write a program that executes the command ls -l /tmp in 5 different child processes
 Each child should be created by the same process (the father)
 Wait for a child to exit before creating a new child*/

/**
 * main - Tutorial using fork()
 * Return: (0) success, (1) failure
 */

int main(void)
{
	int pid, counter;
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

	for (counter = 0; counter < 5; counter++)
	{
		pid = fork();
		wait(NULL);
		if (pid == 0)
			execve("/usr/bin/ls", args, env);
		else
			continue;
	}
	return (0);
}
