/*
** EPITECH PROJECT, 2023
** B-BOO-101-MPL-1-1-phoenixd04-noah.ney
** File description:
** split_string.c
*/

#include "printf.h"

int is_alphanum(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
    || (c >= 'A' && c <= 'Z'))
        return 0;
    return 1;
}

int count_words(char const *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        count += is_alphanum(str[i]);
    return count + 1;
}

char **split_string(char const *str)
{
    char **new;
    int nb_words = 0;
    int len_word = 0;
    int j = 0;

    nb_words += count_words(str);
    new = malloc(sizeof(char *) * (nb_words + 1));
    for (int i = 0; i != nb_words; i++) {
        for (int k = 0; str[k] && is_alphanum(str[k]); str++);
        for (len_word = 0; is_alphanum(str[len_word]) == 0; len_word++);
        new[i] = malloc(len_word + 1);
        for (j = 0; j != len_word; j++)
            new[i][j] = str[j];
        new[i][j] = '\0';
        str += len_word;
    }
    new[nb_words] = NULL;
    return new;
}
