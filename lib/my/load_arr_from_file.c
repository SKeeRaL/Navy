/*
** EPITECH PROJECT, 2023
** navy
** File description:
** load_arr_from_file.c
*/

#include "printf.h"
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

static int get_rows(char *buff)
{
    int result = 0;

    for (int i = 0; buff[i]; i++) {
        if (buff[i] == '\n')
            result += 1;
    }
    return result + 1;
}

static int get_cols(char *buff)
{
    int result = 0;

    for (; buff[result] != '\n' && buff[result]; result++);
    return result + 1;
}

static int *count_cols(int nb_rows, char *buff)
{
    int *cols_per_row = malloc(sizeof(int) * nb_rows);
    int start = 0;

    for (int j = 0; j < nb_rows; j++) {
        cols_per_row[j] = get_cols(buff + start);
        start += cols_per_row[j];
    }
    return cols_per_row;
}

int get_file_size(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff = 0; 
    int size = 0;

    while (read(fd, &buff, 1) > 0)
        size += 1;
    close(fd);
    return size;
}

static char *load_file_in_mem(char const *filepath)
{
    int size = get_file_size(filepath);
    int fd = open(filepath, O_RDONLY);
    char *buff = malloc(size + 1);
    
    read(fd, buff, size);
    close(fd);
    buff[size] = '\0';
    return buff;
}

char **load_2d_arr_from_file(char const *filepath)
{
    char *buff = load_file_in_mem(filepath);
    int nb_rows = get_rows(buff);
    int *cols_per_row = count_cols(nb_rows, buff);
    char **str = malloc(sizeof(char *) * (nb_rows + 1));
    int i = 0;

    for (int start = 0; i < nb_rows; i++) {
        str[i] = malloc(cols_per_row[i] + 1);
        my_strncpy(str[i], buff + start, cols_per_row[i]);
        str[i][cols_per_row[i]] = '\0';
        start += cols_per_row[i];
    }
    str[i] = NULL;
    free(buff);
    free(cols_per_row);
    return str;
}
