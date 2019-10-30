/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** mysh
*/

#include "../include/mysh.h"

int count_word(char *str)
{
    int i = 0;
    int j = 1;

    while (str[i] != '\0' && str[i] != '\n')
    {
        if (str[i] == ' ' && str[i + 1] != '\0')
            j++;
        i++;
    }
    return (j);
}

int countchar(char *str)
{
    int i = 0;

    while ((str[i] != ' ') && (str[i] != '\0') && (str[i] != '\n'))
        i++;
    i += 1;
    return (i);
}

char **my_str_to_wordtab(char *str)
{
    char **tab;
    int i = 0;
    int j = 0;
    int k = 0;

    tab = malloc(sizeof(*tab) * ((count_word(str) + 2)));
    while (str[i] != '\t' && str[i] != '\0') {
        if (str[i] == comp || str[i] == '\n') {
            j = j + 1;
            k = 0;
        }
        tab[j] = malloc(sizeof(**tab) * ((countchar(str + i) + 1)));
        while ((str[i] != comp)  && (str[i] != '\n') && (str[i] != '\0'))
            tab[j][k++] = str[i++];
        tab[j][k] = '\0';
    }free(str);
    tab[j + 1] = 0;
    return (tab);
}

char *get_path(char **env, char **lil)
{
    char **path = link_path(env, lil);
    char *path2 = link_path_pwd(lil);
    int i = 0;
    int check;
    int j = my_strlentab(path);

    path[j] = path2;
    while (path[i]) {
        if ((check = access(path[i], F_OK)) == 0) {
            if ((check = access(path[i], X_OK)) == -1) {
                perror(NULL);
            }
            return path[i];
        }
        i++;
    }
    return NULL;
}