/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** count_float.c
*/

#include "printf.h"
#include <stdbool.h>

bool veriffloat(double number)
{
    bool inte = false;
    int value = number;

    if (number - value == 0)
        inte = true;
    return inte;
}

int count_float(double number)
{
    int x = 0;
    int decimal = number * 1000000;

    decimal %= 1000000;
    if (veriffloat(number))
        return count_nums(number);
    for (int i = 0; i != 6; i++)
        if (decimal % 10 == 0) {
            decimal /= 10;
            x++;
        }
    return count_nums(number) + (6 - x);
}
