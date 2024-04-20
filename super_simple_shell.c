#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define USAGE "Usage: prompt <command>"
#define PS1 "#cisfun$ "

/**
 * execute - Executes the program passed in
 * the prompt
 * @args: The array of arguments containing
 * the program and its options and arguments
 * Return: Nothing (void)
 */

void execute(char *args[1024]);

/**
 * parser - Parses a line from the stdin
 * stream, using strtok with " " delimiters
 * @args: The array of parsed tokens
 * @prompt: The prompt to parse
 * Return: Nothing (void)
 */

void parser(char *args[1024], char *prompt);

/**
 * main - Simple shell
 * Return: (0) success, (1) failure
 */

int main()
{
	/* Init the needed vars */
	size_t n = 0;
	char *prompt = NULL, *args[1024];

	do {
		/* Print the prompt */
		printf(PS1);
		/* Get the line */
		n = getline(&prompt, &n, stdin);
		/* Call the parser */
		parser(args, prompt);
		/* Execute */
		execute(args);

	} while (n != EOF);
	/* Exited the shell */
	free(prompt);
	return (0);
}

void parser(char *args[1024], char *prompt)
{
	unsigned int i = 0;

	/* If there's no input to parse */
	if (!prompt || !*prompt)
		return;

	/* Remove the \n char */
	*(prompt + strlen(prompt) - 1) = 0;

	args[i] = strtok(prompt, " ");
	while (args[i++])
		args[i] = strtok(NULL, " ");
}

void execute(char *args[1024])
{
	int pid, i = 0;

	/* Fork parent process to get a child process
	 * to run the program without exiting
	 */
	if ((pid = fork()) == 0)
	{
		/* Run the program */
		if (execvp(args[0], args) == -1)
		{
			/* Handle execvp errors */
			perror("");
			/* Kill the zombie process */
			kill(getpid(), SIGINT);
		}
	}
	wait(NULL);
}
