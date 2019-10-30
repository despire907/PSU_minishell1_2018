/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** mysh
*/

#include "mysh.h"

char *my_realloc_str(char *str, int nb)
{
    int len = nb + my_strlen(str);
    char *cpy = malloc(sizeof(char) * len);
    int i = 0;

    while (str[i]) {
        cpy[i] = str[i];
        ++i;
    }
    cpy[len - 1] = '\0';
    free(str);
    return cpy;
}

void controle_c(int c)
{
    (void)c;
    my_putstr("\n");
    my_putstr("[$]{*}(%)==>");
}

void my_cd(char **lil, char **env)
{
    char *str = getcwd(NULL, 0);
    char **ptr = my_getpath(env, "HOME=");
    int test = 0;
    int test2 = 0;

    if (lil[1] == NULL) {
        if ((test = chdir(ptr[0])) == -1)
            perror(NULL);
        my_free(ptr);
        free(str);
    }
    else {
        str = link_path_cd(lil);
        if ((test2 = chdir(str)) == -1)
            perror(NULL);
        free(str);
        my_free(ptr);
    }
}

int run_2(char *test, char **env)
{
    char **lil;
    char *path;

    if ((lil = my_str_to_wordtab(test)) != 0) {
        if (!my_strcmp(lil[0], "exit")) {
            my_putstr("exit\n");
            my_free(lil);
            return 0;
        }else if (!my_strcmp(lil[0], "cd")){
            my_cd(lil, env);
            my_free(lil);
        }else {
            path = get_path(env, lil);
            my_fork(path, lil, env);
            free(path);
            my_free(lil);
        }
    }
    return 1;
}

int main(int argc, char **argv, char **env)
{
    (void)argv;

    if (argc == 1 && env[0] != NULL) {
        run(env);
    }else
        return 84;
    return 0;
}