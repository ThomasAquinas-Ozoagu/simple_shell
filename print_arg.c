#include <stdio.h>

/**
 * main - prints args without using argument count
 *
 * @ac: argument count
 * @av: argument variables
 * Return: always 0
 */

int main(int ac, char *av[])
{
	int x;

	x = 0;
	while (av[x])
	{
		printf("%s\n", av[x]);
		x++;
	}
	return (0);
}
