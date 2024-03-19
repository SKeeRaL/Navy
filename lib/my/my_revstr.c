/*
** EPITECH PROJECT, 2023
** DAY06
** File description:
** task03
*/

#include "printf.h"

char *my_revstr(char *str)
{
    int a = 0;
    char str2[my_strlen(str)];

    for (int i = 0; str[i] != '\0'; i++) {
        str2[i] = str[i];
    }
    for (int i = my_strlen(str) - 1; i >= 0; i--) {
        str[i] = str2[a];
        a++;
    }
    return str;
}
