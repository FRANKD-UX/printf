#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct printHandler

{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

int _printf(const char *format, ...);

#endif /* MAIN_H */

