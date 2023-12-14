#include "main.h"
#include <stdlib.h>

/**
 * int_bin - converts integer to binary
 *
 * @intb: the integer to be converted
 *
 * @buffer: accumulator
 *
 * @start_pt: tracker for the accumulator
 *
 * Return: the number of characters printed
 */

int int_bin(int intb, char *buffer, int *start_pt)
{
	int check, prnt;
	char *result;
	int intbb = intb;

	result = malloc(sizeof(int) * 32);

	for (check = 0; intbb > 0; check++)
	{
		result[check] = intbb % 2;
		intbb = intbb / 2;
	}
	for (prnt = check - 1; prnt >= 0; prnt--)
	{
		buffer[*start_pt] = ('0' + result[prnt]);
		(*start_pt)++;
	}
	free(result);
	return (0);
}
