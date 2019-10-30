/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** mysh.h
*/

#ifndef EPITECH_PROJECT_MYSH_H
#define EPITECH_PROJECT_MYSH_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <signal.h>
#include <string.h>

#define MEM_SIZE 4096

void my_free(char **lil);
void controle_c(int c);
void run(char **env);
int run_2(char *test, char **env);
int my_strlentab(char **path);
char *link_path_cd(char **lil);
char *link_path_pwd(char **lil);
char *link_path_home(char **lil, char **env);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_line(int fd, char *buff, int red);
char *my_realloc_str(char *str, int nb);
char *get_next_line(const int fd);
char **my_str_to_wordtab(char *str);
int countchar(char *str);
int count_word(char *str);
void my_putchar(char c);
char *my_getenv(char **env, char const *to_find);
char **my_getpath(char **env, char *str);
char *get_column(char *path_str, int *idx_str);
int dir_size(char *path_str, int idx);
int count_dots(char *path_str);
void my_putstr_error(char const *str);
void my_putstr(char const *str);
void my_putchar_error(char c);
void my_putchar(char c);
char **link_path(char **env, char **lil);
char *get_path(char **env, char **lil);
char *my_realloc(char *str);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
void my_fork (char *path, char **lil, char **env);

#endif //EPITECH_PROJECT_MYSH_H
