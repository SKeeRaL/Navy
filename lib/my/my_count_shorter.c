/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_count_shorter.c
*/

#include <stdarg.h>
#include "printf.h"

int count_deci(double number)
{
    int entier = number;
    int decimal;
    int x = 0;
    int count = 0;

    number -= entier;
    decimal = number * 10000000;
    if (decimal % 10 == 9)
        decimal += 10;
    decimal /= 10;
    while (decimal % 10 == 0) {
        decimal /= 10;
        x += 1;
    }
    while (count_nums(decimal) + count != 6 - x)
        count += 1;
    return count_nums(decimal) + count;
}

static void eminus(bool inf)
{
    if (inf)
        my_printf("e-");
    else {
        my_printf("e+");
    }
}

void decimalinf2(long *decimal)
{
    if (*decimal < 0)
        *decimal *= -1;
}

void intsup2(long *entier, int *nb, double *value, long *decimal)
{
    if (*entier < 0) {
        my_printf("-");
        *entier *= -1;
        *value *= -1;
        *nb += 1;
    }
    *value -= *entier;
    *decimal = *value * 1000000;
    *decimal += 5;
    *decimal /= 10;
}

int putfloat(double value)
{
    int nb = 7;
    long entier = value;
    long decimal = 0;
    int lenfloat = count_deci(value) + count_nums(value);
    int lendeci = count_deci(value);

    intsup2(&entier, &nb, &value, &decimal);
    decimalinf2(&decimal);
    my_printf("%d.", entier);
    while (decimal % 10 == 0)
        decimal /= 10;
    for (; lenfloat > 6; lenfloat--)
        decimal /= 10;
    while (lendeci > count_nums(decimal)) {
        lendeci--;
        my_printf("0");
    }
    my_printf("%d", decimal);
    return 0;
}

static void putfloat6max(double value)
{
    int nb = 7;
    long entier = value;
    long decimal = 0;
    int lendeci = count_deci(value);

    intsup2(&entier, &nb, &value, &decimal);
    decimalinf2(&decimal);
    if (lendeci == 6)
        lendeci -= 1;
    my_printf("%d.", entier);
    for (; lendeci != count_nums(decimal); lendeci--)
        my_printf("0");
    while (decimal % 10 == 0)
        decimal /= 10;
    my_printf("%d", decimal);
    if (entier == 0) {
        decimal = value * 1000000;
        my_printf("%d", decimal % 10);
    }
}

static int epower(double value)
{
    int count = 0;
    double number = value;
    bool inf = false;
    int nb = 0;

    numbercond(&number, &inf, &nb, &count);
    putfloat6max(number);
    eminus(inf);
    if (count < 10) {
        my_putchar('0');
        my_put_nbr(count);
    } else {
        my_put_nbr(count);
    }
    return 12 + nb;
}

static void maths(double *value, int *decimal, int integer)
{
    *value -= integer;
    *decimal = (*value) * 1000000;
    *decimal += 5;
    *decimal /= 10;
}

int my_count_shorter(va_list ap)
{
    double number = va_arg(ap, double);
    double value = number;
    int integer = number;
    int decimal = 0;

    maths(&value, &decimal, integer);
    if (integer + decimal == 0) {
        my_printf("0");
        return 0;
    }
    if (veriffloat(number) == false) {
        putfloat(number);
        return 0;
    }
    if (count_float(number) > 7) {
        epower(number);
        return 0;
    } else if (veriffloat(number))
        my_printf("%d", integer);
    return 0;
}
