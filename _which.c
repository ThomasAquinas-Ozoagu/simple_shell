#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * main - stat example
 *
 * @ac: argument count
 * @av: arguments
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;
	char cwd[PATH_MAX + 1];


	if ((ac < 2) || (strstr(av[1], "/") != NULL))
	{
		printf("Usage: %s filename ...\n", av[0]);
		return (1);
	}

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
		return (1);
	}


	strcat(cwd, "/");
	i = 1;
	while (av[i])
	{
		strcat(cwd, av[1]);
		printf("%s:", av[i]);
		if (stat(cwd, &st) == 0)
		{
			printf(" FOUND\n");
		}
		else
		{
			printf(" NOT FOUND\n");
		}
		i++;
	}
	return (0);
}
