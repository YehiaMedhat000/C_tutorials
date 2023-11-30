#include <stdio.h>
#include <unistd.h>

/**
 * main - Program to get pid and ppid
 * Return: (0) success, (1) failure
 */

int main(void)
{
	int pid = getpid();
	int ppid = getppid();
	printf("pid: %d, ppid: %d\n", pid, ppid);
	return (0);
}
