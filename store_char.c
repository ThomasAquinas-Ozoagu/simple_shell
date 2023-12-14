#include "main.h"

/**
 * store_char - puts characters on the screen
 *
 * @str: string to be printed
 *
 * @buffer: storage buffer
 *
 * @start_pt: buffer tracker
 *
 * Return: the number of characters printed.
 */

int store_char(char str, char *buffer, int *start_pt)
{

		buffer[*start_pt] = str;
		(*start_pt)++;

	return (0);
}
