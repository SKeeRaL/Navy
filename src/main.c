/*
** EPITECH PROJECT, 2023
** navy
** File description:
** main.c
*/

#include "../includes/my.h"

int count_usr1 = 0;
players_t *players;
hop_t sprites_boats;
game_t *game;
hip_t missed[49];
hip_t hit[13];
hip_t hit_enemy[13];
hip_t missed_enemy[49];

static void print_info(void)
{
    my_printf("USAGE\n");
    my_printf("     ./navy [first_player_pid] navy_positions\n");
    my_printf("\nDESCRIPTION\n");
    my_printf("     first_player_pid: only for the 2nd player.");
    my_printf(" pid of the first player.\n     navy_positions: ");
    my_printf("file representing the positions of the ships.\n");
}

static void get_pid_e(__attribute__((unused)) int signum, __attribute__((unused)) siginfo_t *flags, __attribute__((unused)) void *context)
{
    players->p1.pid_e = flags->si_pid;
    game->stat = ig_p1;
    sfText_setString(players->text_player, "Player 1");
    sfSprite_setPosition(game->spr_logo, (sfVector2f) { 1792 / 2 - 175, -10});
    sfSprite_setScale(game->spr_logo, (sfVector2f) {0.2, 0.2});
    sfText_setString(game->text_menu, " A   B   C    D    E    F   G   H\t\t\t   A   B   C    D    E    F   G   H");
    sfText_setPosition(game->text_menu, (sfVector2f) {110, 80});
    sfText_setColor(players->text_player, sfColor_fromRGBA(106, 245, 164, 200));
    game->action = att;
}

int init_players(int ac, char **av)
{
    if (ac == 2) {
        players->p1.fd = open(av[1], O_RDONLY);
        if (players->p1.fd <= 0)
            return 84;
        players->p1.fp = my_strdup(av[1]);
        players->p1.pid = getpid();
        players->p1.pid_str = malloc(count_nums(players->p1.pid) + 1);
        players->p1.pid_str[count_nums(players->p1.pid)] = '\0';
        sprintf(players->p1.pid_str, "%d", players->p1.pid);
        players->player = 1;
        players->p1.sa.sa_sigaction = get_pid_e;
        players->p1.sa.sa_flags = SA_SIGINFO;
        sigemptyset(&(players->p1.sa.sa_mask));
        return 0;
    }
    return 84;
}

int arguments_handling(int ac, char **av)
{
    if (ac < 2 || ac > 3)
        return 84;
    if (my_strcmp("-h", av[1]) == 0) {
        print_info();
        return 1;
    }
    if (init_players(ac, av) != 0)
        return 84;
    return 0;
}

// CSFML PART

static void menu_mouse_clik(game_t *game)
{
    sfVector2i mousepos;
    sfFloatRect but_play = sfSprite_getGlobalBounds(game->spr_play);
    sfFloatRect but_play2 = sfSprite_getGlobalBounds(game->spr_play2);
    sfFloatRect but_exit = sfSprite_getGlobalBounds(game->spr_exit);

    if (game->event.type == sfEvtMouseButtonPressed) {
        mousepos = sfMouse_getPositionRenderWindow(game->win);
        if (sfFloatRect_contains(&but_play, mousepos.x, mousepos.y)) {
            sfClock_restart(game->clock_menu);
            game->stat = menu_p1;
        }
        if (sfFloatRect_contains(&but_play2, mousepos.x, mousepos.y))
            game->stat = menu_p2;
        if (sfFloatRect_contains(&but_exit, mousepos.x, mousepos.y))
            sfRenderWindow_close(game->win);
    }
}

static void menu_join_input(game_t *game)
{
    sfVector2i mousepos;
    sfFloatRect but_back = sfSprite_getGlobalBounds(game->spr_back);

    if (game->event.type == sfEvtTextEntered) {
        if (game->event.text.unicode >= '0' && game->event.text.unicode <= '9')
            sprintf(game->inputBuffer, "%s%c", game->inputBuffer, game->event.text.unicode);
        if (my_strlen(game->inputBuffer) > 0 && game->event.text.unicode == 8)
            game->inputBuffer[my_strlen(game->inputBuffer) - 1] = '\0';
        if (game->event.text.unicode == 13) {
            players->p1.pid_e = atoi(game->inputBuffer);
            if (kill(players->p1.pid_e, SIGUSR1) != -1) {
                game->stat = ig_p2;
                sfText_setString(players->text_player, "Player 2");
                sfText_setString(game->text_menu, " A   B   C    D    E    F   G   H\t\t\t   A   B   C    D    E    F   G   H");
                sfText_setPosition(game->text_menu, (sfVector2f) {110, 80});
                game->action = def;
                sfSprite_setPosition(game->spr_logo, (sfVector2f) { 1792 / 2 - 175, -10});
                sfSprite_setScale(game->spr_logo, (sfVector2f) {0.2, 0.2});
            } else
                game->inputBuffer[0] = '\0';
        }
        sfText_setString(game->inputText, game->inputBuffer);
    }
    if (game->event.type == sfEvtMouseButtonPressed) {
        mousepos = sfMouse_getPositionRenderWindow(game->win);
        if (sfFloatRect_contains(&but_back, mousepos.x, mousepos.y))
            game->stat = menu;
    }
}

static void menu_create_game(game_t *game)
{
    sfVector2i mousepos;
    sfFloatRect but_back = sfSprite_getGlobalBounds(game->spr_back);

    if (game->event.type == sfEvtMouseButtonPressed) {
        mousepos = sfMouse_getPositionRenderWindow(game->win);
        if (sfFloatRect_contains(&but_back, mousepos.x, mousepos.y))
            game->stat = menu;
    }
}

static void handle_mouse_click(game_t *game)
{
    if (game->stat == menu)
        menu_mouse_clik(game);
    if (game->stat == menu_p1)
        menu_create_game(game);
    if (game->stat == menu_p2)
        menu_join_input(game);
    if ((game->stat == ig_p1 || game->stat == ig_p2) && game->action == att)
        if (game->event.type == sfEvtTextEntered) {
            sprintf(sprites_boats.attack_buffer, "%s%c", sprites_boats.attack_buffer, game->event.text.unicode);
            if (my_strlen(sprites_boats.attack_buffer) > 0 && game->event.text.unicode == 8)
                sprites_boats.attack_buffer[0] = '\0';
            if (game->event.text.unicode == 13) {
                players->p1.x_attack = sprites_boats.attack_buffer[0] - 65;
                players->p1.y_attack = sprites_boats.attack_buffer[1] - 49;
                sprites_boats.attack_buffer[0] = '\0';
            }
            sfText_setString(sprites_boats.attack_input, sprites_boats.attack_buffer);
        }
    if (game->stat == ig_p1 || game->stat == ig_p2) {
        sfVector2i mousepos;
        sfFloatRect but_logo = sfSprite_getGlobalBounds(game->spr_logo);
        if (game->event.type == sfEvtMouseButtonPressed) {
        mousepos = sfMouse_getPositionRenderWindow(game->win);
            if (sfFloatRect_contains(&but_logo, mousepos.x, mousepos.y))
                players->boat_disp = players->boat_disp == true ? false : true;
        }
        if (game->event.type == sfEvtKeyPressed && game->event.key.code == sfKeyH) {
            players->p1.hit = 14;
        }
    }
}

void analyse_event(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->win, &game->event)) {
        if (game->event.type == sfEvtClosed || (game->event.type == sfEvtKeyPressed && game->event.key.code == sfKeyEscape)) {
            kill(players->p1.pid_e, 3);
            sfRenderWindow_close(game->win);
        }
        handle_mouse_click(game);
    }
}

int game_loop(game_t *game)
{
    int state = 2;

    while (sfRenderWindow_isOpen(game->win)) {
        sfRenderWindow_clear(game->win, sfBlack);
        analyse_event(game);
        if (game->stat == menu) {
            display_menu(game);
        }
        if (game->stat == menu_p1) {
            display_menu_p1(game);
            sigaction(SIGUSR1, &(players->p1.sa), NULL);
        }
        if (game->stat == menu_p2) {
            display_menu_p2(game);
        }
        if (game->stat == ig_p1) {
            ingame_p1(game);
            print_cross();
            if (game->action == att)
                attack_p();
            print_cross();
            if (players->p1.destroy == 14) {
                state = 1;
                break;
            }
            if (players->p1.hit == 14) {
                state = 0;
                game->stat = over1;
                sprites_boats.clock = sfClock_create();
            }
            if (game->action == def)
                defense_p();
            print_cross();
            if (players->p1.destroy == 14) {
                state = 1;
                break;
            }
            if (players->p1.hit == 14) {
                state = 0;
                game->stat = over1;
                sprites_boats.clock = sfClock_create();
            }
        }
        if (game->stat == ig_p2) {
            ingame_p1(game);
            if (game->action == def)
                defense_p();
            print_cross();
            if (players->p1.destroy == 14) {
                state = 1;
                break;
            }
            if (players->p1.hit == 14) {
                state = 0;
                game->stat = over1;
                sprites_boats.clock = sfClock_create();
            }
            if (game->action == att)
                attack_p();
            print_cross();
            if (players->p1.destroy == 14) {
                state = 1;
                break;
            }
            if (players->p1.hit == 14) {
                state = 0;
                game->stat = over1;
                sprites_boats.clock = sfClock_create();
            }
        }
        if (game->stat == over1) {
            display_over1(game);
        }
        sfRenderWindow_display(game->win);
    }
    sfRenderWindow_close(game->win);
    destroy(game);
    return state;
}

int main(int ac, char **av)
{
    game = malloc(sizeof(game_t));
    players = malloc(sizeof(players_t));
    int error = arguments_handling(ac, av);

    if (error != 0) {
        if (error == 1)
            return 0;
        write(2, "Please enter a valid file or try ./my_navy -h !\n", 49);
        return 84;
    }
    init(game);
    return game_loop(game);
}
