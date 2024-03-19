/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_strncpy.c
*/

#include "printf.h"

char *my_strncpy(char *dest, char *src, int number)
{
    int i = my_strlen(src);

    for (i = 0; src[i] != '\0' && i != number; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
