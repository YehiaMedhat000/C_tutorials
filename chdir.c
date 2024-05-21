#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(int ac, char **av)
{
	char cwd[1024];
	size_t size = 1024;

	if (ac != 2)
	{
		printf("Usage: ./a.out <dir>\n");
		exit(EXIT_FAILURE);
	}

	if (chdir(av[1]) == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}

	printf("CWD: %s\n", getcwd(cwd, size));
	printf("%u\n", size);
	return (0);
}
