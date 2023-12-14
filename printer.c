#include <sys/types.h>
#include <unistd.h>
#include "main.h"



/**
 * post - puts the characters on the buffer on the screen
 * @buffer: the string of characters
 * Return: number of char printed
 */

int post(char *buffer)
{
	return (write(1, buffer, _strlen(buffer)));
}
