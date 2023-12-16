#include "main.h"
#include <sys/stat.h>

/**
 * findpath - locate the command in PATH
 *
 * @env: environmental Varialbes
 * @command: command to locate the path
 * Return: the full path
 */

char *findpath(char *command, char **env)
{
	int i, j, m;
	char **allpath, **onlyvals, *addslash, *filename;
	struct stat st;

	if (!command || !env)
		printf("Usage: findpath(char *command, char **env)");

	if (findchar(command, '/') >= 0)
		return (command);
	for (i = 0; env[i]; i++)
	{
		if (env[i][0] == 'P')
			if (env[i][1] == 'A')
				if (env[i][2] == 'T')
					if (env[i][3] == 'H')
					{
						j = i;
						i = -2;
					}
	}
	allpath = _strtok(env[j], '=');
	onlyvals = _strtok(allpath[1], ':');
	free(allpath);

	for (m = 0; onlyvals[m]; m++)
	{
		addslash = _strcat(onlyvals[m], "/");
/*		free(onlyvals); */
		filename = _strcat(addslash, command);
		free(addslash);
		if (stat(filename, &st) == 0)
		{
			return (filename);
		}
	}

	return (NULL);
}
