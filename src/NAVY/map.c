/*
** EPITECH PROJECT, 2023
** navy
** File description:
** map.c
*/

#include "../../includes/my.h"

static int check_size(int size, char **line)
{
    int count = 0;

    if (line[1][0] == line[2][0]) {
        while (line[1][1] + count < line[2][1])
            count += 1;
    }
    if (line[1][1] == line[2][1]) {
        while (line[1][0] + count < line[2][0])
            count += 1;
    }
    return size - (count + 1);
}

static int find_boat(player_t *p, char **line)
{
    bool exist = false;
    int i = 0;

    for (; i != 4; i++)
        if (line[0][0] - '0' == p->boats[i].size && p->boats[i].on == false) {
            p->boats[i].on = true;
            exist = true;
            break;
        }
    if (exist == false || check_size(p->boats[i].size, line) != 0) {
        write(2, "The size of the boats does not conform!\n", 41);
        return 84;
    }
    return i;
}

static int place_boat_map(player_t *p, char **line, int boat_index)
{
    int y = line[1][1] - 1 - '0';
    int x = line[1][0] - 17 - '0';
    int y_end = line[2][1] - 1 - '0';
    int x_end = line[2][0] - 17 - '0';

    p->boats[boat_index].horizontal = true;
    p->boats[boat_index].pos = (sfVector2f) {100 + x * 90 + p->boats[boat_index].size * 5, 150 + y * 90};
    while (x <= x_end && y == y_end) {
        if (p->map[y][x] != p->boats[boat_index].size + '0' &&
        p->map[y][x] != '.')
            return 84;
        p->map[y][x] = p->boats[boat_index].size + '0';
        x += 1;
    }
    while (x == x_end && y <= y_end) {
        p->boats[boat_index].horizontal = false;
        if (p->map[y][x] != p->boats[boat_index].size + '0' &&
        p->map[y][x] != '.')
            return 84;
        p->map[y][x] = p->boats[boat_index].size + '0';
        y += 1;
    }
    return 0;
}

static int place_boat(player_t *p, char **line)
{
    int boat_index = find_boat(p, line);

    if (boat_index == 84)
        return 84;
    if (place_boat_map(p, line, boat_index) == 84)
        return 84;
    return 0;
}

void init_boat(player_t *p)
{
    p->boats = malloc(sizeof(boat_t) * 4);
    for (int i = 0; i != 4; i++) {
        p->boats[i].on = false;
        p->boats[i].size = 2 + i;
    }
}

static int parthing_map(player_t *p, char *fp)
{
    char **file = load_2d_arr_from_file(fp);
    char **line;
    int error = 0;

    init_boat(p);
    for (int i = 0; i != 4; i++) {
        if (my_strlen(file[i]) > 8) {
            write(2, "Invalid file !\n", 16);
            return 84;
        }
        if (file[i] == NULL)
            break;
        line = split_string(file[i]);
        error += place_boat(p, line);
        if (error != 0) {
            write(2, "Invalid file !\n", 16);
            return 84;
        }
    }
    return 0;
}

// free tous les mallocs après
int init_map(player_t *p)
{
    p->map = malloc(sizeof(char *) * 9);
    p->map_e = malloc(sizeof(char *) * 9);
    p->map[8] = NULL;
    p->map_e[8] = NULL;
    p->destroy = 0;
    p->hit = 0;
    for (int i = 0; i != 8; i++) {
        p->map[i] = malloc(10);
        p->map_e[i] = malloc(10);
        for (int j = 0; j != 8; j++) {
            p->map[i][j] = '.';
            p->map_e[i][j] = '.';
        }
        p->map[i][9] = '\0';
        p->map_e[i][9] = '\0';
    }
    return parthing_map(p, p->fp);
}

void print_map(player_t *p)
{
    my_printf("my navy:\n |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i != 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j != 8; j++)
            my_printf("%c ", p->map[i][j]);
        my_putchar('\n');
    }
    my_printf("\nenemy navy:\n |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i != 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j != 8; j++)
            my_printf("%c ", p->map_e[i][j]);
        my_putchar('\n');
    }
    my_putchar('\n');
}
