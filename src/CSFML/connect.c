/*
** EPITECH PROJECT, 2023
** bonus
** File description:
** connect.c
*/

#include "../../includes/my.h"

void draw_numbers(game_t *game)
{
    sfRenderWindow_drawText(game->win, game->text_menu, NULL);
    sfRenderWindow_drawText(game->win, game->text_1, NULL);
    sfRenderWindow_drawText(game->win, game->text_2, NULL);
    sfRenderWindow_drawText(game->win, game->text_3, NULL);
    sfRenderWindow_drawText(game->win, game->text_4, NULL);
    sfRenderWindow_drawText(game->win, game->text_5, NULL);
    sfRenderWindow_drawText(game->win, game->text_6, NULL);
    sfRenderWindow_drawText(game->win, game->text_7, NULL);
    sfRenderWindow_drawText(game->win, game->text_8, NULL);
}

void ingame_p1(game_t *game)
{
    sfRenderWindow_drawSprite(game->win, game->spr_menu_ig, NULL);
    sfRenderWindow_drawSprite(game->win, game->spr_grille, NULL);
    sfRenderWindow_drawSprite(game->win, game->spr_grille2, NULL);
    sfRenderWindow_drawText(game->win, players->text_player, NULL);
    draw_numbers(game);
    if (players->boat_disp) {
        sfRenderWindow_drawSprite(game->win, sprites_boats.ship_2, NULL);
        sfRenderWindow_drawSprite(game->win, sprites_boats.ship_3, NULL);
        sfRenderWindow_drawSprite(game->win, sprites_boats.ship_4, NULL);
        sfRenderWindow_drawSprite(game->win, sprites_boats.ship_5, NULL);
    }
    sfRenderWindow_drawSprite(game->win, sprites_boats.spr_rect, NULL);
    sfRenderWindow_drawSprite(game->win, game->spr_logo, NULL);
}

void print_cross()
{
    for (int i = 0; hit[i].off == false; i++) {
        sfRenderWindow_drawSprite(game->win, hit[i].result_attack, NULL);
    }
    for (int i = 0; missed[i].off == false; i++) {
        sfRenderWindow_drawSprite(game->win, missed[i].result_attack, NULL);
    }
    for (int i = 0; hit_enemy[i].off == false; i++) {
        sfRenderWindow_drawSprite(game->win, hit_enemy[i].result_attack, NULL);
    }
    for (int i = 0; missed_enemy[i].off == false; i++) {
        sfRenderWindow_drawSprite(game->win, missed_enemy[i].result_attack, NULL);
    }
}