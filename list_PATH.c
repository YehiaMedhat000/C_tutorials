#include "main.h"

/**
 * list_path - Lists the dirs in the
 * PATH variable
 * Return: Always (0)
 */

void list_path(void)
{
	extern char **environ;
	char *PATH = _getenv("PATH"), *dir;
	pid_t pid;
	char *args[] = {"/bin/ls", NULL, NULL};

	printf("%s\n", PATH);
	dir = strtok(PATH, ":");
	while (dir)
	{
		args[1] = dir;
		if ((pid = fork()) == 0)
			pid = execve("/bin/ls", args, environ);
		sleep(2);
		if (pid == -1)
			printf("\nfailure\n");
		dir = strtok(NULL, ":");
	}
}
