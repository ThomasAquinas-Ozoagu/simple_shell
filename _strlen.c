#include "main.h"


/**
 * _strlen - calculates the lenght of a string
 *
 * @s: the string whose lenght is about to be measured
 *
 * Return: the integer result of the analysis.
 */

int _strlen(char *s)
{
	int n;
	int count = 0;

	for (n = 0; s[n] != '\0'; n++)
		count++;

	return (count);
}
