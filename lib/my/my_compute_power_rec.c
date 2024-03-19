/*
** EPITECH PROJECT, 2023
** Task04
** File description:
** power (rec)
*/

#include <stdio.h>
#include <limits.h>

int my_compute_power_rec(int nb, int p)
{
    int resultat = nb;

    if (p == 1) {
        return nb;
    }
    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    resultat = resultat + my_compute_power_rec(nb, (p - 1)) * nb;
    if (resultat > INT_MAX)
        return 0;
    resultat = resultat - nb;
    return resultat;
}
