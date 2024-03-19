/*
** EPITECH PROJECT, 2023
** cworkshop
** File description:
** my_putnbr_base.c
*/

#include <stdio.h>
#include "printf.h"

int my_putnbr_base(int nbr, int *count, const char *base)
{
    int div = nbr / my_strlen(base);
    int rest = nbr % my_strlen(base);

    if (nbr < 0) {
        my_putchar('-');
        *count += 1;
        nbr = nbr * - 1;
    }
    if (nbr < my_strlen(base)) {
        my_putchar(base[nbr]);
        *count += 1;
        return 0;
    }
    my_putnbr_base(div, count, base);
    my_putchar(base[rest]);
    *count += 1;
    return 0;
}

int my_count_puthexamin(va_list ap)
{
    int count = 0;

    my_putnbr_base(va_arg(ap, int), &count, "0123456789abcdef");
    return count;
}

int my_count_puthexa(va_list ap)
{
    int count = 0;

    my_putnbr_base(va_arg(ap, int), &count, "0123456789ABCDEF");
    return count;
}

int my_count_putoct(va_list ap)
{
    int count = 0;

    my_putnbr_base(va_arg(ap, int), &count, "01234567");
    return count;
}

int my_count_putb(va_list ap)
{
    int count = 0;

    my_putnbr_base(va_arg(ap, int), &count, "01");
    return count;
}
