/*
** EPITECH PROJECT, 2023
** navy
** File description:
** defense.c
*/

#include "../../includes/my.h"

void is_touch(player_t *p)
{
    char attack = p->map[p->y_attack][p->x_attack];

    my_printf("result: %c%d:", p->x_attack + '0' + 17, p->y_attack + 1);
    if (attack >= '2' && attack <= '5') {
        p->map[p->y_attack][p->x_attack] = 'x';
        p->destroy += 1;
        my_printf("hit\n\n");
        usleep(1000);
        kill(p->pid_e, SIGUSR2);
        return;
    }
    if (p->map[p->y_attack][p->x_attack] == '.') {
        p->map[p->y_attack][p->x_attack] = 'o';
        my_printf("missed\n\n");
        usleep(1000);
        kill(p->pid_e, SIGUSR1);
        return;
    }
    kill(p->pid_e, SIGUSR1);
    my_printf("missed\n\n");
}

static void defense_handler(__attribute__((unused)) int signum, __attribute__((unused)) siginfo_t *flags, __attribute__((unused)) void *context)
{
    if (signum == 10)
        count_usr1++;
}

void defense(player_t *p)
{
    my_printf("waiting for enemy's attack...\n\n");
    p->sa.sa_sigaction = defense_handler;
    sigaction(10, &(p->sa), NULL);
    sigaction(12, &(p->sa), NULL);
    count_usr1 = 0;
    for (int i = 0; i != 8; i++)
        while (pause() != -1);
    p->x_attack = count_usr1;
    count_usr1 = 0;
    for (int i = 0; i != 8; i++)
        while (pause() != -1);
    p->y_attack = count_usr1;
    count_usr1 = 0;
    is_touch(p);
}
