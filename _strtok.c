#include "main.h"
#include <stdlib.h>

/**
 * _strtok - splits a string into a array of strings using a delimiter
 * @raw: string to be split
 * @delim: delimiter
 * Return: an array
 */

char **_strtok(char *raw, char delim)
{
	int i, j = 0, k, l, m = 0, delimiters = 0, len = _strlen(raw);
	char **argv;

	for (i = 0; raw[i]; i++)      /* Count delimiters */
	{
		if (raw[i] == delim)
			delimiters++;
	}	/* Create array based on number of delimiters + 2 */
	argv = malloc((delimiters + 2) * sizeof(char *));
	if (!argv)
	{
		_printf("malloc error");
		/* return (-1); */
	}
	for (m = 0; m < (delimiters + 2); m++)
	{
		argv[m] = malloc(50 * sizeof(char));
		if (!argv[m])
			_printf("malloc 2 error");
	} /* assign strings to members of array */
	for (l = 0; l < (delimiters + 1); l++)
	{
		for (k = 0; k >= 0; k++)
		{
			if (raw[j] != delim)
				argv[l][k] = raw[j];
			else
			{
				argv[l][k] = '\0';
				k = -2;
			}
			if (j < len)
				j++;
			else
				k = -2;
		}
		k = 0;
	}
	argv[l] = '\0';
	return (argv);
}
