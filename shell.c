#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main - a UNIX command line interpreter.
 * Return: - 0 if ok
 */

int main(void)
{
	size_t len = 0;
	ssize_t nread = 0;
	char **argv, *line = NULL;
	int i, j, status, vars = 2;
	pid_t pid;

	argv = malloc(40);
	if (!argv)
		return (-1);
	for (i = 0; i < vars; i++)
	{
		argv[i] = malloc(50 * sizeof(char));
		if (!argv)
			return (-1);
		argv[i] = " ";
	}
	while (nread != -1)
	{
		pid = fork();
		if (pid == -1)
			perror("Error:");
		if (pid == 0)
		{
			printf("#cisfun$ ");
			nread = getline(&line, &len, stdin);
			if (line[strlen(line) - 1] == 10)
				line[strlen(line) - 1] = '\0';
			else
				line[strlen(line)] = '\0';
			argv[0] = line, argv[1] = NULL;
			if (execve(argv[0], argv, environ) == -1)
				perror("Error:");
		}
		else
			wait(&status);
	}
	for (j = 0; j < vars; j++)
		free(argv[j]);
	free(argv);
	return (0);
}
