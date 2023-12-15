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
	ssize_t nread;
	char **argv, *line = NULL;
	int i, status;
	pid_t pid;

	argv = malloc(40);
	if (!argv)
		return (-1);
	for (i = 0; i < 5; i++)
	{
		argv[i] = malloc(50 * sizeof(char));
		if (!argv)
			return (-1);
		argv[i] = " ";
	}
	while (nread != -1)
	{
		printf("#cisfun$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			return(-1);
		if (line[strlen(line) - 1] == 10)
			line[strlen(line) - 1] = '\0';
		else
		{
			line[strlen(line)] = '\0';
		}
		argv[0] = line;
		argv[1] = NULL;
		pid = fork();
		if (pid == -1)
			perror("Error:");
		if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
				perror("Error:");
		}
		else
			wait(&status);
	}
	free(argv);
	return (0);
}
