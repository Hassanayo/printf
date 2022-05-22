#include "main.h"
#include <stdlib.h>

/**
 * print_c - prints a character
 * @c: character to print
 *  
 * Return: returns 1
 */

int print_c(va_list c)
{
    char ch = (char)va_arg(c, int);

    _putchar(ch);
    return (1);
}

/**
 * print_s = prints a string
 * @s: a string to print
 * 
 * Return: the number of characters printed
 */

int print_s(va-list s)
{
    int count;
    char *str = va_arg(s, char *);

    if(str == NULL)
    str = "(null)";
    for (count = 0; str[count]; count++)
    {
       _putchar(str[count]);
    }

    return (count);
}