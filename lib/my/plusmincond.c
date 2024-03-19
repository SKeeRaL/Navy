/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** plusmincond.c
*/

#include "printf.h"

int countplusminus(const char *format, int i)
{
    int number = 0;

    if (format[i] == '-')
        return 0;
    while (format[i] == '+' || format[i] == '-') {
        i += 1;
        number += 1;
    }
    return number;
}

static void whilenumber(const char *format, int *i, bool *plus)
{
    while (format[*i + 1] == '+' || format[*i + 1] == '-')
        *i += 1;
    *plus = true;
}

int condplusminus(const char *format, int *i, bool *plus, bool *pos)
{
    int number = 0;

    if (format[*i + 1] == '+') {
        while (format[*i + 1] == '+' || format[*i + 1] == '-')
            *i += 1;
        *pos = true;
        *plus = true;
    } else if (format[*i + 1] == '-') {
        whilenumber(format, i, plus);
    }
    number = my_getnbr(format + (*i) + 1);
    return number;
}

void neg(int i, bool *isneg, const char *format)
{
    if (format[i + 1] == '-'
    && format[i + 2] >= '0'
    && format[i + 2] <= '9')
        *isneg = true;
}

int getnumchar(const char *format, bool *plus, bool *pos)
{
    int i = 0;
    int nbr = 0;
    bool isneg = false;

    for (i = 0; format[i] != 0; i++)
        if (format[i] == '%') {
            neg(i, &isneg, format);
            nbr = condplusminus(format, &i, plus, pos);
        }
    if (isneg)
        nbr *= -1;
    return nbr;
}

void space(int *countnum, int value, int nbr)
{
    while (nbr -(*countnum) > 0) {
        my_printf(" ");
        nbr -= 1;
    }
    my_printf("%d", value);
}
