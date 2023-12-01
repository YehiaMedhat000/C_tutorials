#include <stdio.h>
#include <string.h>

/**
 * _getenv - Custom implementation of
 * the getenv() function
 * @var: String containing the name
 * of the environment variable
 * Return: Pointer to the value of the
 * variable, NULL if there's no match
 */

char *_getenv(const char *var)
{
	extern char **environ;
	size_t n = strlen(var);

	while(*environ)
	{
		if (strncmp(*environ, var, n) == 0)
			return (*environ);
		environ++;
	}

	return (NULL);
}

/**
 * main - Testing the _getenv()
 * Return: (0) Always
 */

int main(void)
{
	extern char **environ;
	char *var = "LESSOPEN";

	printf("%s\n", _getenv(var));
	return (0);
}
