/*
** EPITECH PROJECT, 2023
** strcmp
** File description:
** str
*/

int my_strcmp(char const *s1, char const *s2)
{
    int sub = 0;
    int i = 0;

    while (s1[i] || s2[i]) {
        sub = s1[i] - s2[i];
        i += 1;
        if (sub == 0) {
            continue;
        }
        if (sub > 0) {
            return 1;
        }
        return -1;
    }
    return 0;
}
