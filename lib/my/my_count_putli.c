/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_count_putli.c
*/

#include "printf.h"

void putlong(long int n, int *count)
{
    if (n < 0) {
        n = n * -1;
        my_putchar('-');
        *count += 1;
    }
    if (n > 9) {
        putlong(n / 10, count);
    }
    my_putchar(n % 10 + '0');
    *count += 1;
}

int my_count_putli(va_list ap)
{
    int count = 0;

    putlong(va_arg(ap, long), &count);
    return count;
}
