/*
** EPITECH PROJECT, 2023
** navy
** File description:
** menu.c
*/

#include "../../includes/my.h"

void print_waiting(game_t *game)
{
    sfTime time_elapse = sfClock_getElapsedTime(game->clock_menu);
    int time = sfTime_asMilliseconds(time_elapse) / 500;
    if (time % 4 == 0)
        sfText_setString(game->text_menu, "Waiting for enemy connection");
    if (time % 4 == 1)
        sfText_setString(game->text_menu, "Waiting for enemy connection.");
    if (time % 4 == 2)
        sfText_setString(game->text_menu, "Waiting for enemy connection..");
    if (time % 4 == 3)
        sfText_setString(game->text_menu, "Waiting for enemy connection...");
}

void display_menu_p2(game_t *game)
{
    sfText_setString(game->text_menu, "Enter a room code:");
    sfRenderWindow_drawSprite(game->win, game->spr_menu_ig, NULL);
    sfRenderWindow_drawSprite(game->win, game->spr_pid, NULL);
    sfRenderWindow_drawText(game->win, game->text_menu, NULL);
    sfRenderWindow_drawText(game->win, game->inputText, NULL);
    sfRenderWindow_drawSprite(game->win, game->spr_back, NULL);
}

void display_menu_p1(game_t *game)
{
    print_waiting(game);
    sfText_setString(game->text_second, players->p1.pid_str);
    sfRenderWindow_drawSprite(game->win, game->spr_menu_ig, NULL);
    sfRenderWindow_drawText(game->win, game->text_menu, NULL);
    sfRenderWindow_drawSprite(game->win, game->spr_pid, NULL);
    sfRenderWindow_drawText(game->win, game->text_second, NULL);
    sfRenderWindow_drawSprite(game->win, game->spr_back, NULL);
}

void display_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->win, game->spr_menu, NULL);
    sfRenderWindow_drawSprite(game->win, game->spr_play, NULL);
    sfRenderWindow_drawSprite(game->win, game->spr_play2, NULL);
    sfRenderWindow_drawSprite(game->win, game->spr_exit, NULL);
    sfRenderWindow_drawSprite(game->win, game->spr_logo, NULL);
}

void display_over1(game_t *game)
{
    // Tableau des couleurs
    sfColor colors[] = {
        sfColor_fromRGB(255, 105, 180),    // Rouge
        sfColor_fromRGB(255, 0, 0),        // Vert
        sfColor_fromRGB(255, 142, 0),
        sfColor_fromRGB(255, 255, 0),
        sfColor_fromRGB(0, 142, 0),
        sfColor_fromRGB(0, 192, 192),
        sfColor_fromRGB(64, 0, 152),
        sfColor_fromRGB(142, 0, 142)
    };
    static int colorIndex = 0;
    sfTime elapsed = sfClock_getElapsedTime(sprites_boats.clock);

    if (elapsed.microseconds > 300000)
    {
        sfText_setColor(sprites_boats.text_win, colors[colorIndex]);
        if (colorIndex == 8)
            colorIndex = 0;
        else
            colorIndex += 1;
        sfClock_restart(sprites_boats.clock);
    }
    sfRenderWindow_drawSprite(game->win, game->spr_menu, NULL);
    sfRenderWindow_drawText(game->win, sprites_boats.text_win, NULL);
}
