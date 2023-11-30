#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 * main - Tutorial about wait syscall
 * @argc: Arguments count
 * @argv: Arguments value
 * Return: (0) success, (1) failure
 */

int main(int argc, char **argv)
{
	int i;

	if (!argc || !argv)
		return (1);
	if (argc < 1 || !*argv)
		return (1);
	if ((i = fork()) == -1)
		return (1);

	/* Supposed to print the pid of the child first */
	wait(NULL);
	/* Prints once for parent, and once for child process */
	printf("PID: %d\n", i);
	return (0);
}
