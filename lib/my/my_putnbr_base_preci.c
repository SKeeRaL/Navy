/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_putnbr_base_preci.c
*/

#include <stdio.h>
#include "printf.h"

static int my_putnbr_base2(int nbr, const char *base)
{
    int div = nbr / my_strlen(base);
    int rest = nbr % my_strlen(base);

    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * - 1;
    }
    if (nbr < my_strlen(base)) {
        my_putchar(base[nbr]);
        return 0;
    }
    my_putnbr_base2(div, base);
    my_putchar(base[rest]);
    return 0;
}

int my_count_puthexamin_preci(int nbr_arg)
{
    int count = 0;

    my_putnbr_base2(nbr_arg, "0123456789abcdef");
    return count;
}

int my_count_putoct_preci(int nbr_arg)
{
    int count = 0;

    my_putnbr_base2(nbr_arg, "01234567");
    return count;
}
