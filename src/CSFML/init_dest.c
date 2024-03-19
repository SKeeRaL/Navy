/*
** EPITECH PROJECT, 2023
** navy
** File description:
** init_dest.c
*/

#include "../../includes/my.h"

static void init_win(game_t *game)
{
    sfVideoMode mode = {1792, 1024, 32};

    game->win = sfRenderWindow_create(mode, "My Navy",
    sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(game->win, 120);
}

static void init_struct(game_t *game)
{
    game->stat = menu;
    game->action = att;
    game->clock_menu = sfClock_create();
    players->p1.hit = 0;
    players->p1.hit_e = 0;
    players->p1.destroy = 0;
    players->p1.miss = 0;
    players->p1.miss_e = 0;
    players->boat_disp = true;
    game->music = sfMusic_createFromFile("tex/music.ogg");
    players->p1.y_attack = -1;
    players->p1.x_attack = -1;
    players->one_time = false;
    players->stop = 0;
    sfMusic_play(game->music);
}

static void init_sprite_menu(game_t *game)
{
    // Background
    game->tex_menu = sfTexture_createFromFile("tex/menu.png", NULL);
    game->spr_menu = sfSprite_create();
    sfSprite_setTexture(game->spr_menu, game->tex_menu, sfTrue);

    // Blurred Background
    game->tex_menu_ig = sfTexture_createFromFile("tex/ig_menu.png", NULL);
    game->spr_menu_ig = sfSprite_create();
    sfSprite_setTexture(game->spr_menu_ig, game->tex_menu_ig, sfTrue);

    // Logo
    game->tex_logo = sfTexture_createFromFile("tex/logo.png", NULL);
    game->spr_logo = sfSprite_create();
    sfSprite_setTexture(game->spr_logo, game->tex_logo, sfTrue);
    sfSprite_setPosition(game->spr_logo, (sfVector2f){410, -50});

    // Create Game
    game->tex_play = sfTexture_createFromFile("tex/play1.png", NULL);
    game->spr_play = sfSprite_create();
    sfSprite_setTexture(game->spr_play, game->tex_play, sfTrue);
    sfSprite_setScale(game->spr_play, (sfVector2f){0.72, 0.72});
    sfSprite_setPosition(game->spr_play, (sfVector2f){110, 125});

    // Join Game
    game->tex_play2 = sfTexture_createFromFile("tex/play2.png", NULL);
    game->spr_play2 = sfSprite_create();
    sfSprite_setTexture(game->spr_play2, game->tex_play2, sfTrue);
    sfSprite_setScale(game->spr_play2, (sfVector2f){0.72, 0.72});
    sfSprite_setPosition(game->spr_play2, (sfVector2f){500, 125});

    // Exit Game
    game->tex_exit = sfTexture_createFromFile("tex/exit.png", NULL);
    game->spr_exit = sfSprite_create();
    sfSprite_setTexture(game->spr_exit, game->tex_exit, sfTrue);
    sfSprite_setScale(game->spr_exit, (sfVector2f){0.6, 0.6});
    sfSprite_setPosition(game->spr_exit, (sfVector2f){190, 550});

    // PID display boat
    game->tex_pid = sfTexture_createFromFile("tex/PID.png", NULL);
    game->spr_pid = sfSprite_create();
    sfSprite_setTexture(game->spr_pid, game->tex_pid, sfTrue);
    sfSprite_setScale(game->spr_pid, (sfVector2f){0.72, 0.72});
    sfSprite_setPosition(game->spr_pid, (sfVector2f){510, 125});

    // Return back to menu
    game->tex_back = sfTexture_createFromFile("tex/back.png", NULL);
    game->spr_back = sfSprite_create();
    sfSprite_setTexture(game->spr_back, game->tex_back, sfTrue);
    sfSprite_setScale(game->spr_back, (sfVector2f){0.4, 0.4});
    sfSprite_setPosition(game->spr_back, (sfVector2f){1605, -20});

    // ship 2
    sprites_boats.tex_ship_2 = sfTexture_createFromFile("tex/ship2.png", NULL);
    sprites_boats.ship_2 = sfSprite_create();
    sfSprite_setTexture(sprites_boats.ship_2, sprites_boats.tex_ship_2, sfTrue);
    sfSprite_setScale(sprites_boats.ship_2, (sfVector2f){2.5, 2.5});
    if (players->p1.boats[0].horizontal == false) {
        players->p1.boats[0].pos.x += 68;
        players->p1.boats[0].pos.y += 10;
        sfSprite_rotate(sprites_boats.ship_2, 90);
    }
    sfSprite_setPosition(sprites_boats.ship_2, players->p1.boats[0].pos);

    // ship 3
    sprites_boats.tex_ship_3 = sfTexture_createFromFile("tex/ship3.png", NULL);
    sprites_boats.ship_3 = sfSprite_create();
    sfSprite_setTexture(sprites_boats.ship_3, sprites_boats.tex_ship_3, sfTrue);
    sfSprite_setScale(sprites_boats.ship_3, (sfVector2f){2.5, 2.5});
    if (players->p1.boats[1].horizontal == false) {
        players->p1.boats[1].pos.x += 63;
        players->p1.boats[1].pos.y += 15;
        sfSprite_rotate(sprites_boats.ship_3, 90);
    }
    sfSprite_setPosition(sprites_boats.ship_3, players->p1.boats[1].pos);

    // ship 4
    sprites_boats.tex_ship_4 = sfTexture_createFromFile("tex/ship_4.png", NULL);
    sprites_boats.ship_4 = sfSprite_create();
    sfSprite_setTexture(sprites_boats.ship_4, sprites_boats.tex_ship_4, sfTrue);
    sfSprite_setScale(sprites_boats.ship_4, (sfVector2f){2.5, 2.5});
    if (players->p1.boats[2].horizontal == false) {
        players->p1.boats[2].pos.x += 58;
        players->p1.boats[2].pos.y += 20;
        sfSprite_rotate(sprites_boats.ship_4, 90);
    }
    sfSprite_setPosition(sprites_boats.ship_4, players->p1.boats[2].pos);

    // ship 5
    sprites_boats.tex_ship_5 = sfTexture_createFromFile("tex/ship_5.png", NULL);
    sprites_boats.ship_5 = sfSprite_create();
    sfSprite_setTexture(sprites_boats.ship_5, sprites_boats.tex_ship_5, sfTrue);
    sfSprite_setScale(sprites_boats.ship_5, (sfVector2f){2.5, 2.5});
    if (players->p1.boats[3].horizontal == false) {
        players->p1.boats[3].pos.x += 54;
        players->p1.boats[3].pos.y += 25;
        sfSprite_rotate(sprites_boats.ship_5, 90);
    }
    sfSprite_setPosition(sprites_boats.ship_5, players->p1.boats[3].pos);

    // rect wood for input
    sprites_boats.rect_wood = sfTexture_createFromFile("tex/rect.png", NULL);
    sprites_boats.spr_rect = sfSprite_create();
    sfSprite_setTexture(sprites_boats.spr_rect, sprites_boats.rect_wood, sfTrue);
    sfSprite_setScale(sprites_boats.spr_rect, (sfVector2f){0.40, 0.40});
    sfSprite_setPosition(sprites_boats.spr_rect, (sfVector2f){700, 750});

    // sword 1
    sprites_boats.tex_swords = sfTexture_createFromFile("tex/att.png", NULL);
    sprites_boats.spr_swords = sfSprite_create();
    sfSprite_setTexture(sprites_boats.spr_swords, sprites_boats.tex_swords, sfTrue);
    sfSprite_setScale(sprites_boats.spr_swords, (sfVector2f){0.07, 0.07});
    sfSprite_setPosition(sprites_boats.spr_swords, (sfVector2f){580, 885});

    // sword 2
    sprites_boats.spr_swords2 = sfSprite_create();
    sfSprite_setTexture(sprites_boats.spr_swords2, sprites_boats.tex_swords, sfTrue);
    sfSprite_setScale(sprites_boats.spr_swords2, (sfVector2f){0.07, 0.07});
    sfSprite_setPosition(sprites_boats.spr_swords2, (sfVector2f){1085, 885});

    // shield 1
    sprites_boats.tex_shields = sfTexture_createFromFile("tex/shield.png", NULL);
    sprites_boats.spr_shields = sfSprite_create();
    sfSprite_setTexture(sprites_boats.spr_shields, sprites_boats.tex_shields, sfTrue);
    sfSprite_setScale(sprites_boats.spr_shields, (sfVector2f){0.07, 0.07});
    sfSprite_setPosition(sprites_boats.spr_shields, (sfVector2f){570, 855});

    // shield 2
    sprites_boats.spr_shields2 = sfSprite_create();
    sfSprite_setTexture(sprites_boats.spr_shields2, sprites_boats.tex_shields, sfTrue);
    sfSprite_setScale(sprites_boats.spr_shields2, (sfVector2f){0.07, 0.07});
    sfSprite_setPosition(sprites_boats.spr_shields2, (sfVector2f){1070, 855});

    // missed_shot
    sprites_boats.tex_missed = sfTexture_createFromFile("tex/missed.png", NULL);
    for (int i = 0; i < 50; i++) {
        missed[i].off = true;
        missed[i].result_attack = sfSprite_create();
        sfSprite_setTexture(missed[i].result_attack, sprites_boats.tex_missed, sfTrue);
        sfSprite_setScale(missed[i].result_attack, (sfVector2f){0.08, 0.08});
        sfSprite_setPosition(missed[i].result_attack, (sfVector2f){95, 140});
    }

    // missed_shot enemy
    for (int i = 0; i < 50; i++) {
        missed_enemy[i].off = true;
        missed_enemy[i].result_attack = sfSprite_create();
        sfSprite_setTexture(missed_enemy[i].result_attack, sprites_boats.tex_missed, sfTrue);
        sfSprite_setScale(missed_enemy[i].result_attack, (sfVector2f){0.08, 0.08});
        sfSprite_setPosition(missed_enemy[i].result_attack, (sfVector2f){95, 140});
    }

    // hit shot
    sprites_boats.tex_hit = sfTexture_createFromFile("tex/croix.png", NULL);
    for (int i = 0; i < 14; i++) {
        hit[i].off = true;
        hit[i].result_attack = sfSprite_create();
        sfSprite_setTexture(hit[i].result_attack, sprites_boats.tex_hit, sfTrue);
        sfSprite_setScale(hit[i].result_attack, (sfVector2f){0.15, 0.15});
        sfSprite_setPosition(hit[i].result_attack, (sfVector2f){95, 160});
    }

    // hit shot enemy
    for (int i = 0; i < 14; i++) {
        hit_enemy[i].off = true;
        hit_enemy[i].result_attack = sfSprite_create();
        sfSprite_setTexture(hit_enemy[i].result_attack, sprites_boats.tex_hit, sfTrue);
        sfSprite_setScale(hit_enemy[i].result_attack, (sfVector2f){0.15, 0.15});
        sfSprite_setPosition(hit_enemy[i].result_attack, (sfVector2f){95, 160});
    }
}

static void create_num_text(game_t *game)
{
    //text 1
    game->text_1 = sfText_create();
    game->font = sfFont_createFromFile("tex/font.ttf");
    sfText_setFont(game->text_1, game->font);
    sfText_setColor(game->text_1, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(game->text_1, (sfVector2f) {50, 150});
    sfText_setCharacterSize(game->text_1, 60);
    sfText_setString(game->text_1, "1\t\t\t\t\t\t\t\t\t\t\t\t\t   1");

    //text 2
    game->text_2 = sfText_create();
    game->font = sfFont_createFromFile("tex/font.ttf");
    sfText_setFont(game->text_2, game->font);
    sfText_setColor(game->text_2, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(game->text_2, (sfVector2f) {50, 240});
    sfText_setCharacterSize(game->text_2, 60);
    sfText_setString(game->text_2, "2\t\t\t\t\t\t\t\t\t\t\t\t\t   2");

    //text 3
    game->text_3 = sfText_create();
    game->font = sfFont_createFromFile("tex/font.ttf");
    sfText_setFont(game->text_3, game->font);
    sfText_setColor(game->text_3, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(game->text_3, (sfVector2f) {50, 330});
    sfText_setCharacterSize(game->text_3, 60);
    sfText_setString(game->text_3, "3\t\t\t\t\t\t\t\t\t\t\t\t\t   3");

    //text 4
    game->text_4 = sfText_create();
    game->font = sfFont_createFromFile("tex/font.ttf");
    sfText_setFont(game->text_4, game->font);
    sfText_setColor(game->text_4, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(game->text_4, (sfVector2f) {50, 415});
    sfText_setCharacterSize(game->text_4, 60);
    sfText_setString(game->text_4, "4\t\t\t\t\t\t\t\t\t\t\t\t\t   4");


    //text 5
    game->text_5 = sfText_create();
    game->font = sfFont_createFromFile("tex/font.ttf");
    sfText_setFont(game->text_5, game->font);
    sfText_setColor(game->text_5, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(game->text_5, (sfVector2f) {50, 515});
    sfText_setCharacterSize(game->text_5, 60);
    sfText_setString(game->text_5, "5\t\t\t\t\t\t\t\t\t\t\t\t\t   5");

    //text 6
    game->text_6 = sfText_create();
    game->font = sfFont_createFromFile("tex/font.ttf");
    sfText_setFont(game->text_6, game->font);
    sfText_setColor(game->text_6, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(game->text_6, (sfVector2f) {50, 605});
    sfText_setCharacterSize(game->text_6, 60);
    sfText_setString(game->text_6, "6\t\t\t\t\t\t\t\t\t\t\t\t\t   6");

    //text 7
    game->text_7 = sfText_create();
    game->font = sfFont_createFromFile("tex/font.ttf");
    sfText_setFont(game->text_7, game->font);
    sfText_setColor(game->text_7, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(game->text_7, (sfVector2f) {50, 695});
    sfText_setCharacterSize(game->text_7, 60);
    sfText_setString(game->text_7, "7\t\t\t\t\t\t\t\t\t\t\t\t\t   7");

    //text 8
    game->text_8 = sfText_create();
    game->font = sfFont_createFromFile("tex/font.ttf");
    sfText_setFont(game->text_8, game->font);
    sfText_setColor(game->text_8, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(game->text_8, (sfVector2f) {50, 780});
    sfText_setCharacterSize(game->text_8, 60);
    sfText_setString(game->text_8, "8\t\t\t\t\t\t\t\t\t\t\t\t\t   8");
}

// init input et textes des menus
static void init_text_menu(game_t *game)
{
    // principal text
    game->text_menu = sfText_create();
    game->font = sfFont_createFromFile("tex/font.ttf");
    sfText_setFont(game->text_menu, game->font);
    sfText_setColor(game->text_menu, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(game->text_menu, (sfVector2f) {20, 15});
    sfText_setCharacterSize(game->text_menu, 60);

    // second text
    game->text_second = sfText_create();
    sfText_setFont(game->text_second, game->font);
    sfText_setColor(game->text_second, sfColor_fromRGB(76, 76, 76));
    sfText_setCharacterSize(game->text_second, 155);
    sfText_setPosition(game->text_second, (sfVector2f) {642, 400});

    // input
    game->inputBuffer = malloc(sizeof(char)* 7);
    game->inputBuffer[0] = '\0';
    game->inputText = sfText_create();
    sfText_setPosition(game->inputText, (sfVector2f){642, 400});
    sfText_setFont(game->inputText, game->font);
    sfText_setCharacterSize(game->inputText, 155);
    sfText_setFillColor(game->inputText, sfColor_fromRGB(76, 76, 76));

    //grille p1
    game->tex_grille = sfTexture_createFromFile("tex/grille.png", NULL);
    game->spr_grille = sfSprite_create();
    sfSprite_setTexture(game->spr_grille, game->tex_grille, sfTrue);
    sfSprite_setScale(game->spr_grille, (sfVector2f){0.70, 0.70});
    sfSprite_setPosition(game->spr_grille, (sfVector2f){100, 150});

    //grille p2
    game->tex_grille2 = sfTexture_createFromFile("tex/grille2.png", NULL);
    game->spr_grille2 = sfSprite_create();
    sfSprite_setTexture(game->spr_grille2, game->tex_grille2, sfTrue);
    sfSprite_setScale(game->spr_grille2, (sfVector2f){0.70, 0.70});
    sfSprite_setPosition(game->spr_grille2, (sfVector2f){1000, 150});

    create_num_text(game);

    // input attack
    sprites_boats.attack_buffer = malloc(sizeof(char)* 7);
    sprites_boats.attack_buffer[0] = '\0';
    sprites_boats.attack_input = sfText_create();
    sfText_setPosition(sprites_boats.attack_input, (sfVector2f){875, 895});
    sfText_setFont(sprites_boats.attack_input, game->font);
    sfText_setCharacterSize(sprites_boats.attack_input, 70);
    sfText_setFillColor(sprites_boats.attack_input, sfColor_fromRGB(85, 85, 85));

    // defense text
    sprites_boats.text_def = sfText_create();
    sfText_setFont(sprites_boats.text_def, game->font);
    sfText_setColor(sprites_boats.text_def, sfColor_fromRGB(85, 85, 85));
    sfText_setPosition(sprites_boats.text_def, (sfVector2f) {760, 890});
    sfText_setCharacterSize(sprites_boats.text_def, 48);

    // player text
    players->text_player = sfText_create();
    sfText_setFont(players->text_player, game->font);
    sfText_setColor(players->text_player, sfColor_fromRGBA(245, 106, 178, 200));
    sfText_setPosition(players->text_player, (sfVector2f) {60, 920});
    sfText_setCharacterSize(players->text_player, 60);

    // win screen
    sprites_boats.text_win = sfText_create();
    sfText_setFont(sprites_boats.text_win, game->font);
    sfText_setColor(sprites_boats.text_win, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(sprites_boats.text_win, (sfVector2f) {1792/2 - 250, 1024/ 2 - 100});
    sfText_setCharacterSize(sprites_boats.text_win, 150);
    sfText_setString(sprites_boats.text_win, "YOU WON");
}

static void init_menu(game_t *game)
{
    init_sprite_menu(game);
    init_text_menu(game);
}

// initialision
void init(game_t *game)
{
    srand(time(NULL));
    init_map(&(players->p1));
    init_struct(game);
    init_win(game);
    init_menu(game);
}

// destroy de tout ce qui est possible
void destroy(game_t *game)
{
    sfRenderWindow_destroy(game->win);
    sfTexture_destroy(game->tex_menu);
    sfTexture_destroy(game->tex_menu_ig);
    sfTexture_destroy(game->tex_play);
    sfTexture_destroy(game->tex_exit);
    sfSprite_destroy(game->spr_menu);
    sfSprite_destroy(game->spr_menu_ig);
    sfSprite_destroy(game->spr_play);
    sfSprite_destroy(game->spr_exit);
    sfText_destroy(game->text_menu);
    sfFont_destroy(game->font);
    sfMusic_destroy(game->music);
}
