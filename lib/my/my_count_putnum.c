/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_count_putnum.c
*/

#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

flagformat_t flagarray[] = {
    {'d', flagd},
    {'o', flago},
    {'c', flagc},
    {'x', flagx},
    {'s', flags},
    {0, NULL},
};

flagformatdb_t flagdb[] = {
    {'b', flagb},
    {'x', flagpointx},
    {'d', flagpointd},
    {0, NULL},
};

static void ifcond(int *countnum, int value, bool pos)
{
    if (value == 0) {
        my_printf("+");
        *countnum += 1;
    }
    if (pos && value > 0) {
        my_printf("+");
        *countnum += 1;
    }
    if (value < 0)
        *countnum += 1;
}

static int flagdpm(va_list ap, int nbr, const char *format)
{
    int value = (va_arg(ap, int));
    bool plus = false;
    bool pos = false;
    int countnum = count_nums(value);
    int number = getnumchar(format, &plus, &pos);

    nbr = nbr;
    ifcond(&countnum, value, pos);
    if (plus || number == 0 || number < 0) {
        my_printf("%d", value);
        for (int i = 0; i < number - countnum; i++) {
            my_putchar(' ');
        }
        return 0;
    }
    return 0;
}

int flagd(va_list ap, int nbr, const char *format)
{
    int value = (va_arg(ap, int));
    bool plus = false;
    bool pos = false;
    int countnum = count_nums(value);
    int number = getnumchar(format, &plus, &pos);

    nbr = nbr;
    ifcond(&countnum, value, pos);
    if (plus || number == 0 || number < 0) {
        my_printf("%d", value);
        for (int i = 0; i < (number* - 1) - countnum; i++) {
            my_putchar(' ');
        }
        return 0;
    }
    space(&countnum, value, number);
    return 0;
}

static void iffpoint(const char *format, va_list ap, int lennum, int i)
{
    int countplus = countplusminus(format, i);
    int number = my_getnbr(format + i + countplus + lennum + 1);
    int entier = my_getnbr(format + i + countplus + lennum - 1);

    for (int y = 0; flagdb[y].c != 0; y++) {
        if (format[i + countplus + lennum + 2 + count_nums(number)]
        == flagdb[y].c) {
            flagdb[y].pfdb(ap, number, format, entier);
        }
        if (format[i + countplus + lennum + 1 + count_nums(number)]
        == flagdb[y].c) {
            flagdb[y].pfdb(ap, number, format, entier);
        }
    }
}

static void cond94(const char *format, int i, int *countplus)
{
    if (format[i - 1] == '%' && format[i] == '-' && format[i + 1] == 'd')
        *countplus -= 1;
}

int condition1(const char *format, int i, int countplus)
{
    if (format[i] == '-')
        countplus += 1;
    return countplus;
}

int condition2(const char *format, int i, int nbr, int lennum)
{
    if (nbr == 0 && format[i + 1] == 'd' && format[i] == '+')
        lennum -= 1;
    return lennum;
}

void condition(va_list ap, const char *format, int nbr, int i)
{
    int lennum = count_nums(nbr);
    int countplus = countplusminus(format, i);

    cond94(format, i, &countplus);
    countplus = condition1(format, i, countplus);
    lennum = condition2(format, i, nbr, lennum);
    for (int j = 0; flagarray[j].c != 0; j++) {
        if (format[i + countplus + lennum + 1] == '%') {
            my_printf("%");
            break;
        }
        if (format[i + countplus + lennum] == '.') {
            iffpoint(format, ap, lennum, i);
            break;
        }
        if (format[i + countplus + lennum] == flagarray[j].c)
            flagarray[j].pff(ap, nbr, format);
    }
}

static void callstruct(int nbr, int i, va_list ap, const char *format)
{
    int countplus = countplusminus(format, i);

    cond94(format, i, &countplus);
    if (format[i] == '+' && format[i + 1] == '-' && format[i + 4] == 'd') {
        flagdpm(ap, nbr, format);
        return;
    }
    condition(ap, format, nbr, i);
}

int my_count_putnum(va_list ap, const char *format)
{
    bool plus = false;
    bool pos = false;
    int nbr = getnumchar(format, &plus, &pos);
    int i = 0;

    for (i = 0; format[i]; i++) {
        if (format[i] == '%') {
            callstruct(nbr, i + 1, ap, format);
            break;
        }
    }
    return 0;
}
