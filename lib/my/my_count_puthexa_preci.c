/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_putnbr_base.c
*/

#include <stdio.h>
#include "printf.h"

int my_count_puthexa_preci(va_list ap)
{
    int count = 0;

    my_putnbr_base(va_arg(ap, int), &count, "0123456789ABCDEF");
    return count;
}
