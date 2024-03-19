/*
** EPITECH PROJECT, 2023
** getnbr
** File description:
** nbr
*/

#include <stdbool.h>
#include "printf.h"
#include <limits.h>

int my_getnbr(char const *str)
{
    bool init = false;
    int res = 0;
    int count = 0;

    for (int i = 0; str[i]; i++) {
        count += str[i] == '-' ? 1 : 0;
        if ('0' <= str[i] && str[i] <= '9') {
            init = true;
            res = (res * 10) + (str[i] - '0');
            continue;
        }
        if (init)
            break;
        count = str[i] == '+' || str[i] == '-' ? count : 0;
    }
    return count % 2 ? -res : res;
}
