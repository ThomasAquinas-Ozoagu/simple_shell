#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - a UNIX command line interpreter.
 * @argc: argument count
 * @argv: argument variables
 * @envp: Environment variables
 * Return: - 0 if ok
 */

int main(int argc, char **argv, char **envp)
{
	size_t len = 0;
	ssize_t nread = 0;
	char *line = NULL;
	int j, status, vars = 2;
	pid_t pid;

	(void)argc;
	while (nread != -1)
	{
		pid = fork();
		if (pid == -1)
			perror("Error:");
		if (pid == 0)
		{
			printf("#cisfun$ ");
			nread = getline(&line, &len, stdin);
			if (line[nread - 1] == 10)
				line[nread - 1] = '\0';
/* Allocate space */
			argv = malloc(2 * sizeof(char *));
			argv[0] = malloc(nread * sizeof(char));
			argv[1] = malloc(sizeof(char));
			if ((!argv) || (!argv[0]) || (!argv[1]))
				return (-1);
			argv = _strtok(line, ' ');
/* Execute program */
			if (execve(argv[0], argv, envp) == -1)
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
