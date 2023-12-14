#include "main.h"

/**
 * print_s - puts characters on the screen
 *
 * @str: string to be printed
 *
 * @buffer: storage buffer
 *
 * @start_pt: buffer tracker
 *
 * Return: the number of characters printed.
 */

int print_s(const char *str, char *buffer, int *start_pt)
{
	unsigned int looper;

	for (looper = 0; str[looper] != '\0'; looper++)
	{
		buffer[*start_pt] = (str[looper]);
		(*start_pt)++;
	}
	return (0);
}
