#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - split strings
 *
 * @argc: argument count
 * @argv: argument variable
 * Return: 0 if successful
 */

int main(int argc, char *argv[])
{
	char *result = NULL;
	int k;

	for (k = 1; k < argc; k++)
	{

		result = strtok(argv[k], " ");
		if (result != NULL)
			printf("%s\n", result);
	}
	return (0);
}
