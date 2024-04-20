#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parser(char *args[1024], char *line);

/**
 * main - Tutorial using strtok()
 * Return: (0) success, (1) failure
 */

int main(void)
{
	unsigned int i = 0;
	char str[] = "This is some text to split using strtok()";
	char str2[] = "Yehia Medhat Yusuf Yusuf Selim";
	char *chunk;
	char *args[1024];

	chunk = strtok(str, " ");
	while (chunk != NULL)
	{
		printf("%s\n", chunk);
		chunk = strtok(NULL, " ");
	}

	parser(args, str2);
	while (args[i])
		printf("%s\n", args[i++]);
	return (0);
}

void parser(char *args[1024], char *line)
{
	unsigned int i = 0;
	char *token;

	if (!line || !*line)
		return;

	args[i] = strtok(line, " ");
	while (args[i++])
		args[i] = strtok(NULL, " ");
}
