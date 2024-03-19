/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_count_putchar.c
*/

#include "printf.h"
#include <unistd.h>
#include <stdarg.h>

int my_count_putchar(va_list ap)
{
    char c = (char) va_arg(ap, int);

    write(1, &c, 1);
    if (c == '\0')
        return 0;
    return 1;
}
