#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...)
{
    int num_arg = strlen(format);

    va_list args;
    va_start(args, format);
    
    int i;

    for (i = 0;i < num_arg; i++)
    {
        if (format[i] == '%' && format[i + 1] == 'c')
        {
            i++;
            char size;
            size = va_arg(args, int);
            printf("%c", size);
        }
        else if (format[i] == '%' && format[i + 1] == 's')
        {
            i++;
            char *r = va_arg(args, char*);
            printf("%s", r);
        }
        
        else
        {
            printf("%c", format[i]);
        }
    }
    va_end(args);
}
