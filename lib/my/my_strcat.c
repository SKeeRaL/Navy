/*
** EPITECH PROJECT, 2023
** day07
** File description:
** task02
*/

#include <stdio.h>
#include "printf.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}
