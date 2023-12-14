#include "main.h"
#include <stdlib.h>

/**
 * print_o - converts integer to base 8
 *
 * @intb: the integer to be converted
 *
 * @buffer: Storage buffer
 *
 * @start_pt: tracker for the buffer
 *
 * Return: the number of characters printed
 */

int print_o(unsigned int intb, char *buffer, int *start_pt)
{
	int check, prnt;
	unsigned int *result;
	unsigned int intbb = intb;


	result = malloc(sizeof(int) * 32);
	if (result == NULL)
		return (-1);
	for (check = 0; intbb > 0; check++)
	{

		result[check] = intbb % 8;
		intbb = intbb / 8;

	}
	for (prnt = check - 1; prnt >= 0; prnt--)
	{

		buffer[*start_pt] = ('0' + result[prnt]);
		(*start_pt)++;
	}
	free(result);
	return (0);
}
