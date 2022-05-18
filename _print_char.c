#include "main.h"
#include <stdarg.h>

/**
 * _print_char: replaces 'c' with a character
 * @args: the argument to replace 'c'
 * 
 * Return: returns the character 
 */

int _print_char(va_list args)
{
    char c = va_arg(args, int);
    return (_putchar(c));
}