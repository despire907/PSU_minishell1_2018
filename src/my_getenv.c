/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** mysh
*/

#include "../include/mysh.h"

char *my_getenv(char **env, char const *to_find)
{
    unsigned int i = 0;
    char *elem = NULL;

    while (env != NULL && env[i]) {
        if (!my_strncmp(env[i], to_find, my_strlen(to_find)))
            elem = env[i] + my_strlen(to_find);
        i++;
    }
    return (elem);
}

void run(char **env)
{
    char *test;
    int i = 0;
    int j = 1;

    while (j == 1) {
        my_putstr("[$]{*}(%)==>");
        signal(SIGINT, controle_c);
        test = get_next_line(0);
        if (test != NULL && (my_strlen(test)) && test[0] != ' ' &&
        test[0] != '\t') {
            i = run_2(test, env);
            if (i == 0)
                j = 0;
        }else if (test == NULL){
            my_putstr("exit\n");
            j = 0;
        }
    }
}

void my_free(char **lil)
{
    int i = 0;

    if (lil != NULL){
        while (lil[i] != NULL)
            free(lil[i++]);
        free(lil);
    }
}
