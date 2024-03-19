/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** .h for all function use in the project my_printf
*/

#pragma once
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct crazyprinter_s {
    char c;
    int(*pf)(va_list ap);
} crazyprinter_t;
typedef struct crazytwoprinter_s {
    char *c;
    int(*pf2)(va_list ap);
} crazytwoprinter_t;
typedef struct crazyprecision_s {
    char c;
    int(*pfp)(va_list ap, const char *);
} crazyprecision_t;
typedef struct flagformat_s {
    char c;
    int(*pff)(va_list ap, int, const char *);
} flagformat_t;
typedef struct flagformatdb_s {
    char c;
    int(*pfdb)(va_list ap, int, const char *, int);
} flagformatdb_t;
int my_strlen(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_printf(const char *format, ...);
int count_nums(int x);
int my_putnbr_base(int nbr, int *count, const char *base);
int my_count_putchar(va_list ap);
int my_count_putnbr(va_list ap);
int my_count_puthexamin(va_list ap);
int my_count_puthexa(va_list ap);
int my_count_putoct(va_list ap);
int my_count_putstr(va_list ap);
int my_count_putfloat(va_list ap);
int my_count_putu(va_list ap);
int my_count_putaddress(va_list ap);
int my_count_putepower(va_list ap);
int my_count_putepowermaj(va_list ap);
char *my_strcpy(char *dest, char const *src);
int my_count_putshort(va_list ap);
int my_count_putshortu(va_list ap);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
bool flag2_verif(va_list ap, const char *format, int i, int *count);
int my_count_putli(va_list ap);
int my_count_puthd(va_list ap);
int my_count_shorter(va_list ap);
int my_count_putprecision(va_list ap, const char *format);
int my_getnbr(char const *str);
int my_count_puthexamin_preci(int nbr_arg);
void intsup0(long *entier, int *nb, double *value, long *decimal);
void decimalinf(long *decimal, double *value, long *entier);
void numbercond(double *number, bool *inf, int *nb, int *count);
int count_float(double number);
bool veriffloat(double number);
int my_count_putoct_preci(int nbr_arg);
int my_count_shortermaj(va_list ap);
int my_count_floatprecision(double value, int lendec, int precision);
int my_compute_power_rec(int nb, int p);
int count_deci(double number);
void case_test_s(int i, long nbr, char *str_arg, const char *format);
int putprecision_s(va_list ap, const char *format);
int my_count_putspace(va_list ap, const char *format);
void cond(int *i, const char *format, int *nbr);
int my_count_puthash(va_list ap, const char *format);
int my_count_putlx(va_list ap);
int my_putnbr_baselx(unsigned long nbr, int *count, const char *base);
int my_count_putnum(va_list ap, const char *format);
int countplusminus(const char *format, int i);
int my_count_putb(va_list ap);
int condplusminus(const char *format, int *i, bool *plus, bool *pos);
int getnumchar(const char *format, bool *plus, bool *pos);
void space(int *countnum, int value, int nbr);
int flagd(va_list ap, int nbr, const char *format);
int flago(va_list ap, int nbr, const char *format);
int flagc(va_list ap, int nbr, const char *format);
int flagx(va_list ap, int nbr, const char *format);
int flags(va_list ap, int nbr, const char *format);
int my_countnbr_base(int nbr, int nbr_conv, const char *base);
int flagb(va_list ap, int nbr, const char *format, int);
int flagpointx(va_list ap, int nbr, const char *format, int);
int flagpointd(va_list ap, int nbr, const char *format, int);
char *my_int_to_str(int nb);
char *my_strdup(char const *src);
char **load_2d_arr_from_file(char const *filepath);
char *my_strncpy(char *dest, char *src, int number);
char **split_string(char const *str);
