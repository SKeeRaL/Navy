/*
** EPITECH PROJECT, 2023
** navy
** File description:
** my.h
*/

#include "printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <time.h>
#include <math.h>

#pragma once

//structures
typedef enum state_es {
    menu,
    menu_p1,
    menu_p2,
    ig_p1,
    att,
    def,
    ig_p2,
    over1,
    over2,
    black,
    black2
} state_e;

typedef struct boat_s {
    int size;
    sfVector2f pos;
    bool horizontal;
    bool on;
} boat_t;

typedef struct player_s {
    int pid_e;
    char **map;
    char **map_e;
    boat_t *boats;
    int fd;
    char *fp;
    int pid;
    char *pid_str;
    struct sigaction sa;
    int x_attack;
    int y_attack;
    int hit;
    int hit_e;
    int miss;
    int miss_e;
    int destroy;
} player_t;

typedef struct players_s {
    player_t p1;
    player_t p2;
    int player;
    bool one_time;
    int stop;
    bool boat_disp;
    sfText *text_player;
} players_t;

typedef struct hop_s {
    sfTexture *tex_ship_2;
    sfSprite *ship_2;
    sfTexture *tex_ship_3;
    sfSprite *ship_3;
    sfTexture *tex_ship_4;
    sfSprite *ship_4;
    sfTexture *tex_ship_5;
    sfSprite *ship_5;
    sfTexture *rect_wood;
    sfSprite *spr_rect;
    sfText *text_def;
    char *attack_buffer;
    sfText *attack_input;
    sfTexture *tex_swords;
    sfSprite *spr_swords;
    sfTexture *tex_swords2;
    sfSprite *spr_swords2;
    sfSprite *spr_shields;
    sfSprite *spr_shields2;
    sfTexture *tex_shields;
    sfTexture *tex_missed;
    sfSprite *spr_missed;
    sfTexture *tex_hit;
    sfSprite *spr_hit;
    sfText *text_win;
    sfClock *clock;
} hop_t;

typedef struct hip_s {
    sfSprite *result_attack;
    bool off;
} hip_t;

typedef struct game_s {
    sfRenderWindow *win;
    sfEvent event;
    state_e stat;
    state_e action;
    sfTexture *tex_logo;
    sfSprite *spr_logo;
    sfTexture *tex_menu;
    sfSprite *spr_menu;
    sfTexture *tex_menu_ig;
    sfSprite *spr_menu_ig;
    sfTexture *tex_play;
    sfSprite *spr_play;
    sfTexture *tex_play2;
    sfSprite *spr_play2;
    sfTexture *tex_play9;
    sfSprite *spr_play9;
    sfTexture *tex_exit;
    sfSprite *spr_exit;
    sfTexture *tex_pid;
    sfSprite *spr_pid;
    sfText *text_menu;
    sfText *text_second;
    sfClock *clock_menu;
    sfFont *font;
    int pid;
    char *inputBuffer;
    sfText *inputText;
    sfTexture *tex_back;
    sfSprite *spr_back;
    sfMusic *music;
    sfTexture *tex_grille;
    sfSprite *spr_grille;
    sfTexture *tex_grille2;
    sfSprite *spr_grille2;
    sfText *text_1;
    sfText *text_2;
    sfText *text_3;
    sfText *text_4;
    sfText *text_5;
    sfText *text_6;
    sfText *text_7;
    sfText *text_8;
    hop_t sprites_boats;
} game_t;

// fonctions
extern hip_t missed[49];
extern hip_t hit[13];
extern hip_t missed_enemy[49];
extern hip_t hit_enemy[13];
extern players_t *players;
extern hop_t sprites_boats;
extern int count_usr1;
extern game_t *game;
int navy(players_t *players);
int connection(player_t *p, int player);
int init_map(player_t *p);
void print_map(player_t *p);
void attack(player_t *p);
void defense(player_t *p);
int check_win(player_t *p);

//fonctions CSFML
void init(game_t *game);
void destroy(game_t *game);
void display_menu(game_t *game);
void display_menu_p1(game_t *game);
void display_menu_p2(game_t *game);
void display_game(game_t *game);
void ingame_p1(game_t *game);
void attack_p();
void defense_p();
void defense_handle(__attribute__((unused)) int signum, __attribute__((unused)) siginfo_t *flags, __attribute__((unused)) void *context);
void attack_handle(__attribute__((unused)) int signum, __attribute__((unused)) siginfo_t *flags, __attribute__((unused)) void *context);
void print_cross();
void draw_numbers(game_t *game);
void display_over1(game_t *game);