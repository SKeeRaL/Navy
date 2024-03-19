/*
** EPITECH PROJECT, 2023
** navy
** File description:
** navy.c
*/

#include "../../includes/my.h"

int check_win(player_t *p)
{
    if (p->hit == 14) {
        print_map(p);
        my_printf("I won\n");
        return 0;
    }
    if (p->destroy == 14) {
        print_map(p);
        my_printf("Enemy won\n");
        return 1;
    }
    return 2;
}

int player_one(players_t *players)
{
    int state = 2;

    if (init_map(&(players->p1)) != 0)
        return 84;
    connection(&(players->p1), 1);
    while (state == 2) {
        print_map(&(players->p1));
        attack(&(players->p1));
        state = check_win(&(players->p1));
        if (state != 2)
            break;
        defense(&(players->p1));
        state = check_win(&(players->p1));
    }
    return state;
}

void free_all(player_t *p)
{
    free(p->fp);
    for (int i = 0; p->map[i]; i++) {
        free(p->map[i]);
        free(p->map_e[i]);
    }
    free(p->boats);
    free(p->map);
    free(p->map_e);
}

int player_two(players_t *players)
{
    int state = 2;

    if (init_map(&(players->p2)) != 0)
        return 84;
    if (connection(&(players->p2), 2) != 0) {
        write(2, "The PID is incorrect ! Try ./my_navy -h\n", 41);
        return 84;
    }
    while (state == 2) {
        print_map(&(players->p2));
        defense(&(players->p2));
        state = check_win(&(players->p2));
        if (state != 2)
            break;
        attack(&(players->p2));
        state = check_win(&(players->p2));
    }
    free_all(&(players->p2));
    return state;
}

int navy(players_t *players)
{
    my_printf("my_pid: %d\n\n", getpid());
    if (players->player == 1)
        return player_one(players);
    if (players->player == 2)
        return player_two(players);
    return 0;
}
