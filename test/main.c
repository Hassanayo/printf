#include "../main.h"
#include <stdio.h>

/**
 * main - test out printf function
 * 
 * Return: always 0
 */

int main(void)
{
    int n = 0;

    n = _printf("%%\n");
    printf("n: %d\n", n);

    
    n = printf("%%\n");
    printf("n: %d\n", n);
    return (0);
}