/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** count_nums.c
*/

#include <stdio.h>

int count_nums(int x)
{
    int count = 0;

    if (x < 0)
        x = x * -1;
    for (int i = 0; x >= 10; i++) {
        count++;
        x = x / 10;
    }
    return count + 1;
}
