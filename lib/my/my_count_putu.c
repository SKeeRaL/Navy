/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_count_putu.c
*/

#include "printf.h"
#include <limits.h>

int my_print_u(unsigned int n, int *count)
{
    if (n > 9) {
        my_print_u(n / 10, count);
    }
    my_putchar(n % 10 + '0');
    *count += 1;
    return 0;
}

int my_count_putu(va_list ap)
{
    int count = 0;

    my_print_u(va_arg(ap, unsigned int), &count);
    return count;
}
