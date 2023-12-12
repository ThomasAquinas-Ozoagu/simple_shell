#include <unistd.h>
#include <stdio.h>

/**
 * main - gets the parent id from a child processd
 *
 * Return: always 0
 */

int main(void)
{
	pid_t parent_pid;

	parent_pid = getppid();
	printf("%u\n", parent_pid);

	return (0);
}
