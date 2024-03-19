/*
** EPITECH PROJECT, 2023
** B-BOO-101-MPL-1-1-phoenixd04-noah.ney
** File description:
** duplicate_string.c
*/

#include "printf.h"

char *my_strdup(char const *src)
{
    char *new = malloc(my_strlen(src) + 1);
    int i = 0;

    for (; src[i]; i++)
        new[i] = src[i];
    new[i] = '\0';
    return new;
}
