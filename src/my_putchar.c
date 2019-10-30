/*
** EPITECH PROJECT, 2018
** put_char
** File description:
** put_char
*/

#include "../include/mysh.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_error(char c)
{
    write(2, &c, 1);
}
