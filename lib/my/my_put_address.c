/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_put_address.c the goal is to print adress of a variable
*/

#include "printf.h"

void rm_zero(char *str)
{
    char res[my_strlen(str) + 1];
    int i = 2;
    int j = 2;

    res[0] = '0';
    res[1] = 'x';
    while (str[i] == '0') {
        i++;
    }
    while (str[i] != '\0') {
        res[j] = str[i];
        i++;
        j++;
    }
    res[j] = '\0';
    my_putstr(res);
}

void put_address(void *address, char *str)
{
    unsigned char *b = (unsigned char *)&address;
    char shexa[2 * sizeof(void *) + 3];
    int j = 0;
    unsigned char byte = 0;

    shexa[j] = '0';
    j++;
    shexa[j] = 'x';
    j++;
    for (int i = sizeof(void *) - 1; i >= 0; i--) {
        byte = b[i];
        shexa[j] = "0123456789abcdef"[byte >> 4];
        j++;
        shexa[j] = "0123456789abcdef"[byte & 0x0F];
        j++;
    }
    shexa[j] = '\0';
    my_strcpy(str, shexa);
    rm_zero(str);
}

int my_count_putaddress(va_list ap)
{
    int count = 14;
    char str[25];

    put_address(va_arg(ap, void *), str);
    return count;
}
