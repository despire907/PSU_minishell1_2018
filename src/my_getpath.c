/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** mysh
*/

#include "mysh.h"

int	count_dots(char *path_str)
{
    int	idx = 0;
    int	dots = 0;

    while (path_str[idx])
    {
        if (path_str[idx] == ':')
            dots += 1;
        idx += 1;
    }
    return (dots + 1);
}

int	dir_size(char *path_str, int idx)
{
    int	size = 0;

    while (path_str[idx] && path_str[idx] != ':')
    {
        size += 1;
        idx += 1;
    }
    return (size);
}

char *get_column(char *path_str, int *idx_str)
{
    char *column;
    int	idx_col = 0;
    int	size = dir_size(path_str, *idx_str);

    if ((column = malloc(sizeof(char) * (size + 1))) == NULL)
        my_putstr_error("ERROR: Out of memory! malloc() failed\n");
    while (idx_col < size) {
        column[idx_col] = path_str[*idx_str];
        *idx_str += 1;
        idx_col += 1;
    }
    column[idx_col] = '\0';
    *idx_str += 1;
    if (access(column, X_OK) == -1) {
        free(column);
        return (NULL);
    }
    return (column);
}

char **my_getpath(char **env, char *str)
{
    char *path_str;
    char **path_tab;
    int dots;
    int idx_line = 0;
    int	idx_str = 0;

    path_str = my_getenv(env, str);
    dots = count_dots(path_str);
    if ((path_tab = malloc(sizeof(char *) * (dots + 1))) == NULL)
        my_putstr_error("ERROR: Out of memory! malloc() failed\n");
    while (idx_line < dots) {
        if ((path_tab[idx_line] = get_column(path_str, &idx_str)) == NULL)
            dots -= 1;
        else
            idx_line += 1;
    }
    path_tab[idx_line] = NULL;
    return (path_tab);
}

char **link_path(char **env, char **lil)
{
    char **path = my_getpath(env, "PATH=");
    int j = 0;
    int cont;
    int i;
    int k;

    while (path[j] != NULL) {
        cont = my_strlen(path[j]);
        path[j] = my_realloc_str(path[j], my_strlen(lil[0]) + 2);
        path[j][cont] = '/';
        i = 0;
        k = 1;
        while (lil[0][i] != '\0') {
            path[j][cont + k] = lil[0][i];
            i++;
            k++;
        }
        j++;
    }
    return path;
}