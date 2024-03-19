/*
** EPITECH PROJECT, 2023
** navy
** File description:
** game.c
*/

#include "../../includes/my.h"

void display_game(game_t *game)
{
    sfRenderWindow_drawSprite(game->win, game->spr_menu_ig, NULL);
    sfRenderWindow_drawSprite(game->win, game->spr_grille, NULL);
    sfRenderWindow_drawSprite(game->win, game->spr_grille2, NULL);
    sfText_setString(game->text_menu, " A   B   C    D    E    F   G   H\t\t\t   A   B   C    D    E    F   G   H");
    sfText_setPosition(game->text_menu, (sfVector2f) {110, 80});
    draw_numbers(game);
    sfRenderWindow_drawSprite(game->win, game->spr_logo, NULL);

}
