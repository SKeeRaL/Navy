/*
** EPITECH PROJECT, 2023
** bonus
** File description:
** att_def.c
*/

#include "../../includes/my.h"

void wait_att()
{
    sfTime time_elapse = sfClock_getElapsedTime(game->clock_menu);
    int time = sfTime_asMilliseconds(time_elapse) / 500;
    if (time % 4 == 0)
        sfText_setString(sprites_boats.text_def, "  Waiting for\nenemy's attack");
    if (time % 4 == 1)
        sfText_setString(sprites_boats.text_def, "  Waiting for\nenemy's attack.");
    if (time % 4 == 2)
        sfText_setString(sprites_boats.text_def, "  Waiting for\nenemy's attack..");
    if (time % 4 == 3)
        sfText_setString(sprites_boats.text_def, "  Waiting for\nenemy's attack...");
}

void send_signal2(player_t *p)
{
    for (int i = 0; i != 8; i++) {
        usleep(10000);
        if (i >= p->x_attack) {
            kill(p->pid_e, SIGUSR2);
            break;
        } else
            kill(p->pid_e, SIGUSR1);
    }
    for (int i = 0; i != 8; i++) {
        usleep(10000);
        if (i >= p->y_attack) {
            kill(p->pid_e, SIGUSR2);
            break;
        } else
            kill(p->pid_e, SIGUSR1);
    }
}

void attack_handle(__attribute__((unused)) int signum, __attribute__((unused)) siginfo_t *flags, __attribute__((unused)) void *context)
{
    if (signum == 10) {
        count_usr1 = 2;
    }
    if (signum == 12) {
        count_usr1 = 1;
    }
}

void attack_p()
{
    sfRenderWindow_drawSprite(game->win, sprites_boats.spr_swords, NULL);
    sfRenderWindow_drawSprite(game->win, sprites_boats.spr_swords2, NULL);
    sfRenderWindow_drawText(game->win, sprites_boats.attack_input, NULL);
    if (players->p1.x_attack == -1)
        return;
    if ((players->p1.x_attack < 0 || players->p1.x_attack > 7) || (players->p1.y_attack < 0 || players->p1.y_attack > 7))
        return;
    players->p1.sa.sa_sigaction = attack_handle;
    sigaction(10, &(players->p1.sa), NULL);
    sigaction(12, &(players->p1.sa), NULL);
    send_signal2(&(players->p1));
    while (pause() != -1);
    if (count_usr1 == 1) {
        if (players->p1.map_e[players->p1.y_attack][players->p1.x_attack] == 'x');
        else {
            players->p1.map_e[players->p1.y_attack][players->p1.x_attack] = 'x';
            sfSprite_setPosition(hit[players->p1.hit].result_attack, (sfVector2f) {players->p1.x_attack * 90 + 95 + 898, players->p1.y_attack * 90 + 157});
            hit[players->p1.hit].off = false;
            players->p1.hit += 1;
        }
    }
    if (count_usr1 == 2) {
        players->p1.map_e[players->p1.y_attack][players->p1.x_attack] = (players->p1.map_e[players->p1.y_attack][players->p1.x_attack] == '.') ? 'o' : 'x';
        sfSprite_setPosition(missed[players->p1.miss].result_attack, (sfVector2f) {players->p1.x_attack * 90 + 95 + 897, players->p1.y_attack * 90 + 143});
        missed[players->p1.miss].off = false;
        players->p1.miss += 1;
    }
    players->p1.x_attack = -1;
    players->p1.y_attack = -1;
    players->stop = 0;
    count_usr1 = 0;
    players->one_time = false;
    game->action = def;
}

void defense_handle(__attribute__((unused)) int signum, __attribute__((unused)) siginfo_t *flags, __attribute__((unused)) void *context)
{
    if (signum == 10) {
        count_usr1 += 1;
    }
    if (signum == 12) {
        players->stop += 1;
    }
}

void defense_p()
{
    wait_att();
    sfRenderWindow_drawSprite(game->win, sprites_boats.spr_shields, NULL);
    sfRenderWindow_drawSprite(game->win, sprites_boats.spr_shields2, NULL);
    sfRenderWindow_drawText(game->win, sprites_boats.text_def, NULL);
    if (players->one_time == false) {
        players->p1.sa.sa_sigaction = defense_handle;
        sigaction(10, &(players->p1.sa), NULL);
        sigaction(12, &(players->p1.sa), NULL);
        players->one_time = true;
        players->stop = 0;
    }
    if (players->stop == 1) {
        players->p1.x_attack = count_usr1;
        count_usr1 = 0;
    }
    while (players->stop == 1)
        pause();
    if (players->stop == 2) {
        players->p1.y_attack = count_usr1;
        count_usr1 = 0;
        players->stop = 0;
        if (players->p1.map[players->p1.y_attack][players->p1.x_attack] != '.' &&
        players->p1.map[players->p1.y_attack][players->p1.x_attack] != 'o') {
            kill(players->p1.pid_e, SIGUSR2);
            players->p1.destroy += 1;
            players->p1.map[players->p1.y_attack][players->p1.x_attack] = 'x';
            sfSprite_setPosition(hit_enemy[players->p1.hit_e].result_attack, (sfVector2f) {players->p1.x_attack * 90 + 95, players->p1.y_attack * 90 + 157});
            hit_enemy[players->p1.hit_e].off = false;
            players->p1.hit_e += 1;
        } else {
            kill(players->p1.pid_e, SIGUSR1);
            players->p1.map[players->p1.y_attack][players->p1.x_attack] = 'o';
            sfSprite_setPosition(missed_enemy[players->p1.miss_e].result_attack, (sfVector2f) {players->p1.x_attack * 90 + 93, players->p1.y_attack * 90 + 143});
            missed_enemy[players->p1.miss_e].off = false;
            players->p1.miss_e += 1;
        }
        players->p1.x_attack = -1;
        players->p1.y_attack = -1;
        players->one_time = false;
        game->action = att;
    }

}