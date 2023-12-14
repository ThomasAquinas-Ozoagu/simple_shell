#include "main.h"
#include <stdlib.h>

/**
 * print_x - converts integer to base 8
 *
 * @intb: the integer to be converted
 *
 * @buffer: storage buffer
 *
 * @start_pt: buffer tracker
 *
 * Return: the number of characters printed
 */

int print_x(unsigned int intb, char *buffer, int *start_pt)
{
	int check, prnt;
	unsigned int *result;
	unsigned int intbb = intb;


	result = malloc(sizeof(int) * 32);
	if (result == NULL)
		return (-1);
	for (check = 0; intbb > 0; check++)
	{

		result[check] = intbb % 16;
		intbb = intbb / 16;

	}
	for (prnt = check - 1; prnt >= 0; prnt--)
	{
		if (result[prnt] < 10)
		{
			buffer[*start_pt] = ('0' + result[prnt]);
			(*start_pt)++;
		}
		if (result[prnt] >= 10)
		{
			buffer[*start_pt] = ('a' + (result[prnt] - 10));
			(*start_pt)++;
		}

	}
	free(result);
	return (0);
}
