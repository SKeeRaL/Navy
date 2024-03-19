/*
** EPITECH PROJECT, 2023
** DAY06
** File description:
** task01
*/

#include "printf.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = my_strlen(src);

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
