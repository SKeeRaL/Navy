/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** nbr
*/

#include <unistd.h>
#include "printf.h"

int my_put_nbr(int nb)
{
    long n = nb;

    if (n < 0) {
        n = n * -1;
        my_putchar('-');
    }
    if (n > 9) {
        my_put_nbr(n / 10);
    }
    my_putchar(n % 10 + '0');
    return 0;
}
