/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_count_putprecision.c
*/

#include <stdio.h>
#include "printf.h"

static void case_test_x(int i, long nbr, int nbr_arg, const char *format)
{
    int len_num = count_nums(nbr);
    int len_arg = count_nums(nbr_arg);
    int count = 0;

    if (len_arg > 5)
        count = 1;
    if (len_arg > 8)
        count = 2;
    if (nbr == 0 && format[i] == 'x')
        my_count_puthexamin_preci(nbr_arg);
    if (format[i + len_num] == 'x'){
        for (int j = 0; j < nbr - len_arg + count; j++)
            my_putchar('0');
        my_count_puthexamin_preci(nbr_arg);
    }
}

static void case_test_o(int i, long nbr, int nbr_arg, const char *format)
{
    int len_num = count_nums(nbr);
    int len_arg = count_nums(nbr_arg);
    int count = 0;

    if (len_arg > 9)
        count = 1;
    if (nbr == 0 && format[i] == 'o')
        my_count_putoct_preci(nbr_arg);
    if (format[i + len_num] == 'o'){
        for (int j = 0; j < nbr - len_arg - count; j++)
            my_putchar('0');
        my_count_putoct_preci(nbr_arg);
    }
}

static void case_test_f(int i, long nbr, double nbr_arg, const char *format)
{
    int len_num = count_nums(nbr);
    int lendec = 0;

    if (format[i + len_num] == 'f') {
        my_count_floatprecision(nbr_arg, lendec, nbr);
    }
}

static void case_test_c(int i, long nbr, int nbr_arg, const char *format)
{
    int len_num = count_nums(nbr);

    if (nbr == 0 && format[i] == 'c')
        my_putchar(nbr_arg);
    if (format[i + len_num] == 'c'){
        my_putchar(nbr_arg);
    }
}

int putprecision(va_list ap, const char *format)
{
    int i = 0;
    long nbr = 0;
    int nbr_arg = (va_arg(ap, int));

    for (i = 0; format[i]; i++) {
        if (format[i] == '%' && format[i + 1] == '.') {
            i += 2;
            nbr = my_getnbr(format + i);
            break;
        }
    }
    case_test_x(i, nbr, nbr_arg, format);
    case_test_o(i, nbr, nbr_arg, format);
    case_test_c(i, nbr, nbr_arg, format);
    return nbr;
}

int putprecision_f(va_list ap, const char *format)
{
    int i = 0;
    long nbr = 0;
    double nbr_arg = (va_arg(ap, double));

    for (i = 0; format[i]; i++) {
        if (format[i] == '%' && format[i + 1] == '.') {
            i += 2;
            nbr = my_getnbr(format + i);
            break;
        }
    }
    case_test_f(i, nbr, nbr_arg, format);
    return nbr;
}

void cond(int *i, const char *format, int *nbr)
{
    for ((*i) = 0; format[(*i)]; (*i)++) {
        if (format[(*i)] == '%' && format[(*i + 1)] == '.') {
            (*i) += 2;
            (*nbr) = my_getnbr(format + (*i));
            break;
        }
    }
}

int special_format_verif(int i, int len_num, va_list ap, const char *format)
{
    int a = 0;

    if (format[i + len_num] == 'f') {
        a = putprecision_f(ap, format);
    } else if (format[i + len_num] == 's') {
        a = putprecision_s(ap, format);
    } else {
        a = putprecision(ap, format);
    }
    return a;
}

int my_count_putprecision(va_list ap, const char *format)
{
    int a = 0;
    int i = 0;
    int nbr = 0;
    int value = 0;
    int len_num = 0;

    cond(&i, format, &nbr);
    len_num = count_nums(nbr);
    if (nbr == 0 && format[i] == 'f') {
        value = va_arg(ap, double);
        my_printf("%d", value);
    }
    a = special_format_verif(i, len_num, ap, format);
    return a;
}
