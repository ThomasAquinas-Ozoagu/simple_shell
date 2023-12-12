#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - gets a line from standard input
 * Return: 0 if ok
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread, stop;



	stop = 1;
	while (stop != -1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		fwrite(line, nread, 1, stdout);
		stop = nread;
	}

	free(line);


	return (0);
}
