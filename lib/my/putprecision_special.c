/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_count_putprecision for special case
*/

#include <stdio.h>
#include "printf.h"

void case_test_s(int i, long nbr, char *str_arg, const char *format)
{
    int len_num = count_nums(nbr);
    int len_arg = my_strlen(str_arg);

    if (nbr == 0 && format[i] == 's')
        return;
    if (nbr > len_arg)
        nbr = len_arg;
    if (format[i + len_num] == 's'){
        for (int j = 0; j < nbr; j++)
            my_putchar(str_arg[j]);
    }
}

int putprecision_s(va_list ap, const char *format)
{
    int i = 0;
    long nbr = 0;
    char *str_arg = (va_arg(ap, char *));

    for (i = 0; format[i]; i++) {
        if (format[i] == '%' && format[i + 1] == '.') {
            i += 2;
            nbr = my_getnbr(format + i);
            break;
        }
    }
    case_test_s(i, nbr, str_arg, format);
    return nbr;
}
