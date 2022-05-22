#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
/**
 *struct print - struct to print out different types
 * 
 * @t: type to be printed
 * @f: function to be printed
 */
typedef struct print
{
    char *t;
    int (*f)(va_list);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list c);
int print_s(va_list s);

#endif /* _MAIN_H_ */