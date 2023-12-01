#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define USAGE "Usage: prompt <command>"

/**
 * main - Simple shell
 * Return: (0) success, (1) failure
 */

int main()
{
	/* Init the needed vars */
	size_t n = 0;
	int pid;
	char *prompt = NULL, *arg = NULL;
	char *args[2], *envp[] = {"TEST=environment variable", NULL};

	printf("#cisfun$ ");
	/* Get the line */
	while (getline(&prompt, &n, stdin) != EOF)
	{
		/* Remove the \n char */
		*(prompt + strlen(prompt) - 1) = 0;

		/* Split the prompt using strtok() */
		arg = strtok(prompt, " ");

		args[0] = arg;
		args[1] = NULL;

		/* fork to keep the process running after execv
		 Execute the program */

		if ((pid = fork()) == 0)
		{
			execve(arg, args, envp);
		}
		wait(NULL);
		printf("#cisfun$ ");
	}
	return (0);
}
