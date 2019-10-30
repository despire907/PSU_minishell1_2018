/*
** EPITECH PROJECT, 2018
** task03
** File description:
** task03
*/

#include "mysh.h"

int my_strlentab(char **path)
{
    int i = 0;

    while (path[i] != NULL)
        i++;

    return i;
}

char *link_path_pwd(char **lil)
{
    char *path = getcwd(NULL, 0);
    int cont;
    int l = 1;
    int y = 0;

    cont = my_strlen(path);
    path = my_realloc_str(path, my_strlen(lil[0]) + 2);
    path[cont] = '/';

    while ((lil[0][y])) {
        path[cont + l] = lil[0][y];
        l++;
        y++;
    }
    return path;
}

char *link_path_home(char **lil, char **env)
{
    char **path = my_getpath(env, "HOME=");
    int cont;
    int l = 1;
    int y = 0;

    cont = my_strlen(path[0]);
    path[0] = my_realloc_str(path[0], my_strlen(lil[0]) + 2);
    path[0][cont] = '/';

    while ((lil[0][y])) {
        path[0][cont + l] = lil[0][y];
        l++;
        y++;
    }
    return path[0];
}

char *link_path_cd(char **lil)
{
    char *path = getcwd(NULL, 0);
    int cont;
    int l = 1;
    int y = 0;

    cont = my_strlen(path);
    path = my_realloc_str(path, my_strlen(lil[1]) + 2);
    path[cont] = '/';

    while ((lil[1][y])) {
        path[cont + l] = lil[1][y];
        l++;
        y++;
    }
    return path;
}
