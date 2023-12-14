#include "main.h"


/**
 * _pow - finds n to the power of m
 * @n: the number
 * @m: the power
 * Return: Sum
 */
int _pow(int n, int m)
{
	int x, suma = 1;

	for (x = m - 1; x > 0; x--)
	{
		suma = suma * n;
	}
	return (suma);
}



/**
 * print_u - prints unsigned integers on std output
 *
 * @num: number to be printed
 *
 * @buffer: storage buffer
 *
 * @start_pt: buffer tracker
 *
 * Return: number of characters printed
 */

int print_u(unsigned int num, char *buffer, int *start_pt)
{
	/* declare variables */
	unsigned int count, len, prt = num, rem = num;
	int piece = 0;

	/*establish number of digits*/
	for (count = 0; rem > 0; count++)
	{
		rem /= 10;
	}


	for (len = count; len > 0; len--)
	{
		piece = _pow(10, len);
		buffer[*start_pt] = (prt / piece + '0');
		prt = prt % piece;
		(*start_pt)++;
	}

	return (0);
}
