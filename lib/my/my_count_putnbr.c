/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_count_putnbr.c
*/

#include <unistd.h>
#include "printf.h"
#include <stdarg.h>
#include <limits.h>

void count_number(int n, int *count)
{
    if (n == INT_MIN) {
        my_putstr("-2147483648");
        *count += 11;
        return;
    }
    if (n < 0) {
        n = n * -1;
        my_putchar('-');
        *count += 1;
    }
    if (n > 9) {
        count_number(n / 10, count);
    }
    my_putchar(n % 10 + '0');
    *count += 1;
}

int my_count_putnbr(va_list ap)
{
    int count = 0;

    count_number(va_arg(ap, int), &count);
    return count;
}
