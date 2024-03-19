/*
** EPITECH PROJECT, 2023
** DAY04
** File description:
** task02
*/

#include <unistd.h>
#include "printf.h"
#include <stddef.h>
#include <stdarg.h>

int my_count_putstr(va_list ap)
{
    char const *str = va_arg(ap, char *);

    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return my_strlen(str);
}
