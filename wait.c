#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid, my_ppid, child_pid;
	int status;

	my_pid = getpid();
	my_ppid = getppid();

	printf("Before fork: child = %u, parent: %u\n", my_pid, my_ppid);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}

	my_pid = getpid(); /* Get both PIDs */
	my_ppid = getppid();

	if (child_pid == 0)
	{
		;
	}
	else
	{
	wait(&status);
	printf("Oh, it's all better now\n");
	printf("The child is %u while the parent is %u\n", my_pid, my_ppid);
	}

	printf("\nStatus = %d\n", status);
	return (0);
}
