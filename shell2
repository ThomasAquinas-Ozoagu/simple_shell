#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/* #include <string.h> */

/**
 * main - a UNIX command line interpreter.
 * Return: - 0 if ok
 */

int main(void)
{
	size_t len = 0;
	ssize_t nread/*, stop*/;
	char **argv, *line = NULL, *prm = "";
	int i, j, status;
	pid_t pid;

	argv = malloc(40);
	if (!argv)
		return (-1);
	for (i = 0; i < 2; i++)
	{
		argv[i] = malloc(50 * sizeof(char));
		if (!argv)
			return (-1);
		argv[i] = " ";
	}


	if (isatty(STDIN_FILENO)) /* Check shell mode */
		prm = "#cisfun$ ";

	while ((_printf("%s", prm) != -1) && ((nread = getline(&line, &len, stdin)) != -1))
	{
		if (line[_strlen(line) - 1] == 10)
			line[_strlen(line) - 1] = '\0';
		argv[0] = line;
		argv[1] = NULL;

		pid = fork();
		if (pid == -1)
			perror("Error:");
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("./shell");
		}
		else
		{
			for (j = 0; j < 2; j++)
				free(argv[j]);
			free(argv);
			wait(&status);
		}
	}
	return (0);
}
