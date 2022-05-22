#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * check_for_specifiers = checks if there is a valid format specifier
 * @format: possible format specifier
 * 
 * Return: pointer to valid function or null
 */

static int (*check_for_specifiers(const char *format))(va_list)
{
    unsigned int i;
    print_t p[] = {
        {"c", print_c},
        {"s", print_s},
        {NULL, NULL}
    };

    for (i = 0; p[i].t != NULL; i++)
    {
        if (*(p[i].t) == *format)
        {
            break;
        }
    }
    return (p[i].f);

}

/**
 * _printf - prints out anything
 * @format: argument tpes that are passed to the function
 * 
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
<<<<<<< HEAD
    unsigned int i = 0, count = 0;
    va_list valist;
    int (*f)(va_list);
=======
    va_list args;
    int n_displayed = 0;
    int i = 0;
>>>>>>> ddd28b31ff944ec6b25b02210369d51c6a9333b2

    if (format == NULL)
    {
        return (-1);
    }
    va_start(valist, format);
    while (format[i])
    {
        for (; format[i] != '%' && format[i]; i++)
        {
            _putchar(format[i]);
            count++;
        }
        if (!format[i])
        {
<<<<<<< HEAD
            return (count);
        }
        f = check_for_specifiers(&format[i + 1]);
        if (f != NULL)
        {
            count += f(valist);
            i += 2;
            continue;
        }
        if (!format[i + 1])
        {
            return (-1);
        }
        _putchar(format[i]);
        count++;
        if (format[i + 1] == '%')
        {
            i += 2;
        }
        else{
            i++;
=======
            
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
>>>>>>> ddd28b31ff944ec6b25b02210369d51c6a9333b2
        }
    }
    va_end(valist);
    return (count);
}