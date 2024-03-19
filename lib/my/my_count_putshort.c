/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_count_putshort.c
*/

#include "printf.h"

void putshort(signed short int n, int *count)
{
    if (n < 0) {
        n = n * -1;
        my_putchar('-');
        *count += 1;
    }
    if (n > 9) {
        putshort(n / 10, count);
    }
    my_putchar(n % 10 + '0');
    *count += 1;
}

int my_count_putshort(va_list ap)
{
    int count = 0;

    putshort(va_arg(ap, int), &count);
    return count;
}

void putshortu(unsigned short int n, int *count)
{
    if (n > 9) {
        putshort(n / 10, count);
    }
    my_putchar(n % 10 + '0');
    *count += 1;
}

int my_count_putshortu(va_list ap)
{
    int count = 0;

    putshortu(va_arg(ap, int), &count);
    return count;
}
