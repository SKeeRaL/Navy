/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** main file of my_printf project
** on doit faire une nouvelle struct pour le point avec :
** typedef struct stringtwoprinter_s {
**    char *c;
**    int(*pf2)(va_list ap, ...); ou int(*pf2)(val_list ap, const char *);
** la deuxieme option c'est si on recupere format, sinon les ... pour
** envoyer l'arg.
** gerer les erreurs quand on donne le mauvais type ex:
** my_printf("%s", 10)
** on doit return 84 ( déduction rien de certain)
*/

#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

crazyprecision_t array3[] = {
    {'.', my_count_putprecision},
    {' ', my_count_putspace},
    {'#', my_count_puthash},
    {'-', my_count_putnum},
    {'+', my_count_putnum},
    {'0', my_count_putnum},
    {'1', my_count_putnum},
    {'2', my_count_putnum},
    {'3', my_count_putnum},
    {'4', my_count_putnum},
    {'5', my_count_putnum},
    {'6', my_count_putnum},
    {'7', my_count_putnum},
    {'8', my_count_putnum},
    {'9', my_count_putnum},
    {0, NULL},
};

crazytwoprinter_t array2[] = {
    {"hi", my_count_putshort},
    {"hu", my_count_putshortu},
    {"hd", my_count_puthd},
    {"li", my_count_putli},
    {"lx", my_count_putlx},
    {0, NULL},
};

crazyprinter_t array[] = {
    {'c', my_count_putchar},
    {'d', my_count_putnbr},
    {'i', my_count_putnbr},
    {'s', my_count_putstr},
    {'x', my_count_puthexamin},
    {'X', my_count_puthexa},
    {'f', my_count_putfloat},
    {'F', my_count_putfloat},
    {'o', my_count_putoct},
    {'e', my_count_putepower},
    {'E', my_count_putepowermaj},
    {'u', my_count_putu},
    {'p', my_count_putaddress},
    {'g', my_count_shorter},
    {'G', my_count_shortermaj},
    {'b', my_count_putb},
    {0, NULL},
};

static void ifneed(int *i, int *nbr, int *len_num, const char *format)
{
    bool space = false;

    if ((format[*i] == '%' && format[*i + 1] == ' ')
    && (format[*i + 2] >= '0' && format[*i + 2] <= '9'))
        space = true;
    (*i) += 2;
    (*nbr) = my_getnbr(format + ((*i) - 1));
    (*len_num) = count_nums(*nbr);
    (*len_num) += countplusminus(format, (*i) - 1);
    if (space)
        *len_num += 1;
}

static void ifpoint(const char *format, int i, int *len_num)
{
    if (format[i + 1] == '.') {
        *len_num += 1 + count_nums(my_getnbr(format + i + 2));
    }
}

static int number_of_nbr(const char *format, int i, int len_num)
{
    int nbr = 0;

    for (i = 0; format[i]; i++)
        if ((format[i] == '%' && format[i + 1] == '.') ||
        (format[i] == '%' && format[i + 1] == '#') ||
        (format[i] == '%' && format[i + 1] == ' ') ||
        ((format[i] == '%' && format[i + 1] >= '0') ||
        (format[i] == '%' && format[i + 1] <= '9')) ||
        (format[i] == '%' && format[i + 1] >= '-') ||
        (format[i] == '%' && format[i + 1] >= '+')) {
            ifneed(&i, &nbr, &len_num, format);
            break;
        }
    if (nbr >= 0)
        len_num -= 1;
    if (countplusminus(format, i - 1) > 0)
        return len_num - 1;
    ifpoint(format, i, &len_num);
    return len_num;
}

int flag_precision(va_list ap, const char *format, int i, int *count)
{
    int ver = -1;
    int fnc = 0;
    int len_num = 0;

    for (int j = 0; array3[j].c != 0; j++) {
        if (format[i + 1] == array3[j].c) {
            fnc = array3[j].pfp(ap, (const char *)format);
            *count += fnc;
            ver = number_of_nbr(format, i, len_num);
        }
    }
    if (format[i + 2 + ver] == '.')
        ver += count_nums(my_getnbr(format + i + 3 + ver)) + 1;
    return ver;
}

bool flag2_verif(va_list ap, const char *format, int i, int *count)
{
    bool tf = false;
    int res = 0;
    char cat[3];

    for (int j = 0; array2[j].c != 0; j++) {
        cat[0] = format[i + 1];
        cat[1] = format[i + 2];
        res = my_strcmp(array2[j].c, cat);
        if (res == 0) {
            *count += array2[j].pf2(ap);
            tf = true;
        }
    }
    return tf;
}

int flag_verif(va_list ap, const char *format, int i, int *count)
{
    bool v = false;

    for (int j = 0; array[j].c != 0; j++) {
        if (format[i + 1] == array[j].c) {
            *count += array[j].pf(ap);
            v = true;
        }
    }
    return v;
}

int call_verif(va_list ap, char const *format, int i, int *count)
{
    int a = 0;

    if (format[i + 1] == '%') {
        my_putchar('%');
        *count += 1;
        return 0;
    }
    a = flag_precision(ap, format, i, count);
    if (a >= 0)
        return a + 1;
    if (flag2_verif(ap, format, i, count)) {
        return 1;
    } else if (flag_verif(ap, format, i, count) == false) {
        my_putchar(format[i]);
        return -1;
    } else {
        return 0;
    }
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int count = 0;

    va_start(ap, format);
    for (int i = 0; i != my_strlen(format); i++) {
        if (format[i] == '%') {
            i += call_verif(ap, format, i, &count);
            i += 1;
            continue;
        }
        my_putchar(format[i]);
        count += 1;
    }
    va_end(ap);
    return count;
}
