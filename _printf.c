#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - prints out anything
 * @format: argument tpes that are passed to the function
 * 
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int n_displayed = 0;
    int i = 0;

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            _putchar(format[i]);
            n_displayed++;
        }
        else
        {
            
            if (format[i+1] == 'c')
            {
                _print_char(args);
                n_displayed++;
                i++;
            }
            else if (format[i+1] == 's')
            {
                i++;
                _print_str(args);
                n_displayed++;
            }
            else if (format[i+1] == '%')
            {
                i++;
                _putchar('%');
                n_displayed++;
            }
        }

        i++;
    }
    
    va_end(args);
    return (n_displayed);
}