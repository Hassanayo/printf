#include "main.h"
#include <stdlib.h>

unsigned char handle_flags(const char *flag, char *index);
/**
 * check_for_specifiers - checks for valid format specifier
 * @format: possible format specifier
 * Return: pointer to valid function or NULL
 */
static int (*check_for_specifiers(const char *format))(va_list)
{
    unsigned int i;
    print_t p[] = {
        {"c", print_c},
        {"s", print_s},
        {"i", print_i},
        {"d", print_d},
        {"o", print_o},
        {"b", print_b},
        {"u", print_u},
        {"x", print_x},
        {"X", print_X},
        {"p", print_p},
        {"S", print_S},
        {"r", print_r},
        {"R", print_R},
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
 * handle_flags - Matches flags with corresponding values.
 * @flag: A pointer to a potential string of flags.
 * @index: An index counter for the original format string.
 *
 * Return: If flag characters are matched - a corresponding value.
 *         Otherwise - 0.
 */
unsigned char handle_flags(const char *flag, char *index)
{
	int i, j;
	unsigned char ret = 0;
	flag_t flags[] = {
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEG},
		{0, 0}
	};

	for (i = 0; flag[i]; i++)
	{
		for (j = 0; flags[j].flag != 0; j++)
		{
			if (flag[i] == flags[j].flag)
			{
				(*index)++;
				if (ret == 0)
					ret = flags[j].value;
				else
					ret |= flags[j].value;
				break;
			}
		}
		if (flags[j].value == 0)
			break;
	}

	return (ret);
}


/**
 * _printf - prints anything
 * @format: arguments passed to the function
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
    char tmp;
    unsigned char flags;
	va_list valist;
	int (*f)(va_list, unsigned char);

	if (format == NULL)
		return (-1);
	va_start(valist, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
        tmp = 0;
        flags = handle_flags(format + i + 1, &tmp);
		f = check_for_specifiers(&format[i + 1]);
		if (f != NULL)
		{
			count += f(valist, flags);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(valist);
	return (count);
}