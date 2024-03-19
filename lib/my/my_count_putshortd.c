/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_count_putshortd.c
*/

#include "printf.h"


void putshortd(short int n, int *count)
{
    if (n < 0) {
        n = n * -1;
        my_putchar('-');
        *count += 1;
    }
    if (n > 9) {
        putshortd(n / 10, count);
    }
    my_putchar(n % 10 + '0');
    *count += 1;
}

int my_count_puthd(va_list ap)
{
    int count = 0;

    putshortd(va_arg(ap, int), &count);
    return count;
}
