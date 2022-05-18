#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - prints out anything
 * @format: argument tpes that are passed to the function
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int n_displayed = 0;
    int i = 0, k = 0;
    char *str = NULL;

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
                _putchar(va_arg(args, int));
                n_displayed++;
                i++;
            }
            else if (format[i+1] == 's')
            {
                i++;
                str = va_arg(args, char *);
                k = 0;
                while (str[k] != '\0')
                {
                    _putchar(str[k]);
                    n_displayed++;
                    k++;
                }
            }
            else if (format[i+1 == '%'])
            {
                i++;
                _putchar('%');
            }
        }

        i++;
    }
    
    va_end(args);
    return (n_displayed);
}