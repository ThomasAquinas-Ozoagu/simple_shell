#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/**
 * main - a UNIX command line interpreter
 * Return: - 0 if ok
 */

int main(void)
{
	size_t len = 0;
	ssize_t nread, stop;
	char **argv, *line = NULL;
	int i, k, status;
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

	while (stop != -1)
	{
		pid = fork();
		if (pid == -1)
			_printf("fork error");
		if (pid == 0)
		{
			_printf("#cisfun$ ");
			nread = getline(&line, &len, stdin);
			stop = nread;

			argv = _strtok(line, ' ');

			for (k = 0; argv[k]; k++)
			{
				if (argv[k][_strlen(argv[k]) - 1] == 10)
					argv[k][_strlen(argv[k]) - 1] = '\0';
			}
			if (!argv)
				_printf("_strtok failed");

			if (execve(argv[0], argv, environ) == -1)
				perror("");
		}
		else
			wait(&status);
	}
/*	free(argv[j]); */
	free(argv);


	return (0);
}
