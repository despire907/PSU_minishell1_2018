/*
** EPITECH PROJECT, 2018
** task02
** File description:
** task02
*/

#include "../include/mysh.h"

void my_putstr(char const *str)
{
    int bobo = 0;

    while (str[bobo] != '\0'){
        my_putchar(str[bobo]);
        bobo++;
    }
}

void my_putstr_error(char const *str)
{
    int bobo = 0;

    while (str[bobo] != '\0'){
        my_putchar_error(str[bobo]);
        bobo++;
    }
}
