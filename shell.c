#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - a UNIX command line interpreter
 * @argc: Argument count
 * @argv: Argument variables
 * @envp: Environmental variables
 * Return: - 0 if ok
 */

int main(int argc, char *argv[], char *envp[])
{
	size_t len = 0;
	ssize_t nread;
	char *line = NULL, **comm;
	int /*k = 0,*/ status;
	pid_t pid;
	int i;

	if (argc != 1)
		_printf("usage: %s", argv[0]);
	comm = malloc(2 * sizeof(char *));
	if (!comm)
		return (-1);
	for (i = 0; i < 2; i++)
	{
		comm[i] = malloc(50 * sizeof(char));
		if (!comm[i])
			return (-1);
		comm[i] = " ";
	}
	while (_printf("#cisfun$ ") &&
		(nread = getline(&line, &len, stdin)) != -1)
	{
		if (line[_strlen(line) - 1] == 10)
			line[_strlen(line) - 1] = '\0';
		pid = fork();
		if (pid == -1)
			_printf("fork error");
		if (pid == 0)
		{
			comm[0] = line;
			comm[1] = NULL;
			if (execve(comm[0], comm, envp) == -1)
				perror("./shell");
		}
		else
			wait(&status);
	}
	return (0);
}
