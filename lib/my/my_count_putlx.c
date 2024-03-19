/*
** EPITECH PROJECT, 2023
** cworkshop
** File description:
** my_putnbr_base.c
*/

#include <stdio.h>
#include "printf.h"

int my_putnbr_baselx(unsigned long nbr, int *count, const char *base)
{
    unsigned long div = nbr / my_strlen(base);
    unsigned long rest = nbr % my_strlen(base);

    if (nbr < (unsigned long int)my_strlen(base)) {
        my_putchar(base[nbr]);
        *count += 1;
        return 0;
    }
    my_putnbr_baselx(div, count, base);
    my_putchar(base[rest]);
    *count += 1;
    return 0;
}

int my_count_putlx(va_list ap)
{
    int count = 0;

    my_putnbr_baselx(va_arg(ap, unsigned long), &count, "0123456789abcdef");
    return count;
}
