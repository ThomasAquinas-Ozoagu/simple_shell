#include "main.h"
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
	char *line = NULL;
	int k = 0, status;
	pid_t pid;

	while (argc && _printf(":) ") &&
		(nread = getline(&line, &len, stdin)) != -1)
	{
		if (line[0] == 'e' && line[1] == 'x' && line[2] == 'i'
		    && line[3] == 't' && line[4] == 10)
			exit(0);
		argv = _strtok(line, ' ');
		for (k = 0; argv[k]; k++)
		{
			if (argv[k][_strlen(argv[k]) - 1] == 10)
				argv[k][_strlen(argv[k]) - 1] = '\0';
		}
		if (!argv)
			_printf("_strtok failed");
		argv[0] = findpath(argv[0], envp);

		if (argv[0] == NULL)
			_printf("Error:: No such file or directory\n");
		else
		{
			pid = fork();
			if (pid == -1)
				_printf("fork error");
			if (pid == 0)
			{
				if (execve(argv[0], argv, envp) == -1)
					perror("");
			}
			else
				wait(&status);
		}
	}

	return (0);
}
