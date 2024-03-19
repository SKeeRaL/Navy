/*
** EPITECH PROJECT, 2023
** navy
** File description:
** connection.c
*/

#include "../../includes/my.h"
#include <asm-generic/signal-defs.h>

static void connect_p1(__attribute__((unused)) int signum, __attribute__((unused)) siginfo_t *flags, __attribute__((unused)) void *context)
{
    struct sigaction leave;

    leave.sa_sigaction = NULL;
    leave.sa_flags = SA_SIGINFO;
    kill(flags->si_pid, SIGUSR1);
    count_usr1 = flags->si_pid;
    sigaction(SIGUSR1, &leave, NULL);
}

static void connect_p2(__attribute__((unused)) int signum, __attribute__((unused)) siginfo_t *flags, __attribute__((unused)) void *context)
{
    struct sigaction leave;

    leave.sa_sigaction = NULL;
    leave.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &leave, NULL);
}

void get_pid(player_t *p)
{
    p->pid = getpid();
    p->sa.sa_flags = SA_SIGINFO;
    sigemptyset(&(p->sa.sa_mask));
}

int connection(player_t *p, int player)
{
    get_pid(p);
    if (player == 1) {
        p->sa.sa_sigaction = connect_p1;
        sigaction(10, &(p->sa), NULL);
        sigaction(12, &(p->sa), NULL);
        my_printf("waiting for enemy connection...\n\n");
        while (pause() != -1);
        p->pid_e = count_usr1;
        count_usr1 = 0;
        my_printf("enemy connected\n\n");
    }
    if (player == 2) {
        p->pid = getpid();
        p->sa.sa_sigaction = connect_p2;
        if (kill(p->pid_e, SIGUSR1) == -1)
            return 84;
        sigaction(10, &(p->sa), NULL);
        while (pause() != -1);
        my_printf("successfully connected\n\n");
    }
    return 0;
}
