#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/**
 * _printf - a function that produces output according to a format
 * @format: The format of the output
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list my_vars;
	unsigned int itr, count = 0;
	char *buf;
	int *str;

	buf = malloc(sizeof(char) * 1024);
	if (buf == NULL)
		return (-1);
	str = malloc(sizeof(int));
	if (str == NULL)
		return (-1);
	*str = 0, va_start(my_vars, format);
	for (itr = 0; format[itr] != '\0'; itr++)
	{
		if (format[itr] == '%')
		{
			if (format[itr + 1] == 'b')
				int_bin(va_arg(my_vars, int), buf, str);
			if (format[itr + 1] == 'c')
				store_char(va_arg(my_vars, int), buf, str);
			if (format[itr + 1] == 'd')
				print_int(va_arg(my_vars, int), buf, str);
			if (format[itr + 1] == 'i')
				print_inti(va_arg(my_vars, int), buf, str);
			if (format[itr + 1] == 'o')
				print_o(va_arg(my_vars, unsigned int), buf, str);
			if (format[itr + 1] == 's')
				print_s(va_arg(my_vars, const char*), buf, str);
			if (format[itr + 1] == 'u')
				print_u(va_arg(my_vars, unsigned int), buf, str);
			if (format[itr + 1] == 'x')
				print_x(va_arg(my_vars, unsigned int), buf, str);
			if (format[itr + 1] == 'X')
				print_xx(va_arg(my_vars, unsigned int), buf, str);
			if (format[itr + 1] == '%')
				store_char('%', buf, str);
			itr++;	}		else
			store_char(format[itr], buf, str);
	}	va_end(my_vars), count = (*str), post(buf), free(buf), free(str);
	return (count);
}
