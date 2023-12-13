#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
		printf("\n1 nread is now %ld\n", nread);
		nread = getline(&line, &len, stdin);
		printf("\n2 nread is now %ld\n", nread);
		fwrite(line, nread, 1, stdout);
		printf("\n3 nread is now %ld\n", nread);
		stop = nread;
	}

	free(line);


	return (0);
}
