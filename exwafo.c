#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main -executes the command ls -l /tmp in 5 different child processes
 *       Each child should be created by the same process (the father).
 *       Wait for a child to exit before creating a new child.
 * Return: - 0 if ok
 */

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t pid, my_pid, my_ppid;
	int count, status;

	printf("Before Exwefo\n");
	printf("Before fork\n");

	my_pid = getpid();
	my_ppid = getppid();
	printf("Initial pids: %u --> %u\n\n", my_ppid, my_pid);

	count = 0;
	while (count < 5)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}
		printf("After fork %d\n", count);
		my_pid = getpid();
		my_ppid = getppid();

		if (pid == 0)
		{
/* printf("\nWaiting: %u --> %u --> %u at %d count\n\n", */
			/* my_ppid, my_pid, pid, count); */
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
		}
		else
		{
			wait(&status);
/* printf("\nAfter wait: %u --> %u --> %u at */
/* %d count\n\n", my_ppid, my_pid, pid, count); */
			count++;
		}
	}
	return (0);
}
