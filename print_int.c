#include "main.h"
#include <stdlib.h>

/**
 * print_int - prints integers on std output
 *
 * @num: number to be printed
 *
 * @start_pt: where the buffer will start storing input
 *
 * @buffer: storage buffer
 *
 * Return: number of characters printed
 */

int print_int(int num, char *buffer, int *start_pt)
{

/* declare variables */
	unsigned int count, len, prt = num, rem = num;
	int piece = 0;


	if (num < 0)
	{
		buffer[*start_pt] = ('-');
		(*start_pt)++;
		prt = -1 * num;
		rem = -1 * num;
	}


	for (count = 0; rem > 0; count++)
	{
		rem /= 10;
	}


	for (len = count; len > 0; len--)
	{
		piece = _pow(10, len);
		buffer[*start_pt] = (prt / piece + '0');
		(*start_pt)++;
		prt = prt % piece;

	}

	return (0);
}
