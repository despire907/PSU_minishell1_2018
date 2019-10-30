/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** getnextline
*/

#include "mysh.h"

int my_strlen(char const *str)
{
    int bobo;

    bobo = 0;
    while (str[bobo] != '\0'){
        bobo = bobo + 1;
    }
    return (bobo);
}

static char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n < i)
        dest[i] = '\0';
    return dest;
}

static char *look_first_line(char *ptr, int j, char *buff, int *start)
{
    char *str;
    int i;

    if (ptr != 0)
        i = my_strlen(ptr);
    else
        i = 0;
    str = malloc((i + j + 1) * sizeof(*str));
    if (ptr != 0)
        my_strncpy(str, ptr, i);
    else
        my_strncpy(str, "", i);
    str[i + j] = 0;
    my_strncpy(str + i, buff + *start, j);
    if (ptr)
        free(ptr);
    *start = *start + (j + 1);
    return str;
}

char *get_next_line(int fd)
{
    static char buff[MEM_SIZE];
    static int i = 0;
    static int start;
    int j = 0;
    char *ptr = 0;

    while (1 == 1) {
        if (i <= start) {
            start = 0;
            if (!(i = read(fd, buff, MEM_SIZE)))
                return ptr;
            if (i == -1)
                return NULL;
            j = 0;
        }if (buff[start + j] == '\n')
            return (ptr = look_first_line(ptr, j, buff, &start));
        if (start + j == i - 1)
            ptr = look_first_line(ptr, j + 1, buff, &start);
        j = j + 1;
    }
}
