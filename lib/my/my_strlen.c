/*
** EPITECH PROJECT, 2023
** DAY04
** File description:
** task03
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int result = 0;

    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i += 1)
        result += 1;
    return (result);
}
