#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

int _printf(const char *format, ...)
{
    int num_arg = strlen(format);
    int i, j;
    char size;
     char *r;

    va_list args;
    va_start(args, format);
    for (i = 0;i < num_arg; i++)
    {
        if (format[i] == '%' && format[i + 1] == 'c')
        {
            i++;
            size = va_arg(args, int);
            printf("%c", size);
        }
        else if (format[i] == '%' && format[i + 1] == 's')
        {
            i++;
            r = va_arg(args, char*);
            printf("%s", r);
        }
	else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
	{
		i++;
		j = va_arg(args, int);
		printf("%d", j);
	}
	else if (format[i] == '%' && format[i + 1] == '%')
	{
		i++;
		printf("%");
	}
        else
        {
            printf("%c", format[i]);
        }
    }
    va_end(args);
    return (0);
}
