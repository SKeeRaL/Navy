/*
** EPITECH PROJECT, 2023
** navy
** File description:
** attack.c
*/

#include "../../includes/my.h"

static void attack_handler(__attribute__((unused)) int signum, __attribute__((unused)) siginfo_t *flags, __attribute__((unused)) void *context)
{
    if (signum == 10)
        my_printf("missed\n\n");
    if (signum == 12) {
        count_usr1 = 1;
        my_printf("hit\n\n");
    }
}

char *get_attack(void)
{
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, stdin);
    return line;
}

int check_pos(player_t *p, char *pos)
{
    if (my_strlen(pos) != 3 || !(pos[0] >= 'A' && pos[0] <= 'H') ||
    !(pos[1] >= '1' && pos[1] <= '8'))
        return 1;
    pos[2] = '\0';
    p->y_attack = pos[1] - 1 - '0';
    p->x_attack = pos[0] - 17 - '0';
    return 0;
}

static void attack_to_str(player_t *p)
{
    char *pos_attack;

    while (1) {
        my_printf("attack: ");
        pos_attack = get_attack();
        if (check_pos(p, pos_attack) != 0)
            my_printf("\nwrong position\n\n");
        else {
            my_printf("\nresult: %s:", pos_attack);
            break;
        }
    }
    free(pos_attack);
}

void send_signal(player_t *p)
{
    for (int i = 0; i != 8; i++) {
        usleep(1000);
        if (i >= p->x_attack)
            kill(p->pid_e, SIGUSR2);
        else
            kill(p->pid_e, SIGUSR1);
    }
    for (int i = 0; i != 8; i++) {
        usleep(1000);
        if (i >= p->y_attack)
            kill(p->pid_e, SIGUSR2);
        else
            kill(p->pid_e, SIGUSR1);
    }
}

void attack(player_t *p)
{
    attack_to_str(p);
    send_signal(p);
    count_usr1 = 0;
    p->sa.sa_sigaction = attack_handler;
    sigaction(10, &(p->sa), NULL);
    sigaction(12, &(p->sa), NULL);
    while (pause() != -1);
    if (count_usr1 == 1) {
        p->map_e[p->y_attack][p->x_attack] = 'x';
        p->hit += 1;
    } else if (p->map_e[p->y_attack][p->x_attack] == '.')
        p->map_e[p->y_attack][p->x_attack] = 'o';
}
