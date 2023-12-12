#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	char **argv;
	int i, j;

	argv = malloc(40);
	if (!argv)
	{
		printf("malloc **argv failed\n");
		return (-1);
	}

	for (i = 0; i < 5; i++)
	{
		argv[i] = malloc(50 * sizeof(char));
		if (!argv)
		{
			printf("malloc argv[%d] failed\n", i);
			return (-1);
		}
		argv[i] = " ";
	}

	argv[0] = "/bin/ls";
	argv[1] = "-l";
	argv[2] = "/usr/";
	argv[3] = NULL;

	printf("\n\nBefore execve ********************************\n");

	j = 0;
	while (j < 5)
	{
		j++;
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
		printf("After execve\n");
	}
	return (0);
}
