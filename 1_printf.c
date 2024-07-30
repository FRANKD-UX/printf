#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
			{
				char c = (char) va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (*ptr == 's')
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					write(1, str, 1);
					str++;
					count++;
				}
			}
			else if (*ptr == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				write(1, "%", 1);
				write(1, ptr, 1);
				count += 2;
			}
		}
		else
		{
			write(1, ptr, 1);
			count++;
		}
	}

	va_end(args);
	return (count);
}

