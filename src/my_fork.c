/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** mysh
*/

#include "mysh.h"

void my_segfault(int status)
{
    int sig = WIFSIGNALED(status);

    if (sig == 1) {
        my_putstr(strsignal(11));
        my_putchar('\n');
    }
}

void my_fork(char *path, char **lil, char **env)
{
    pid_t pid;
    int i =  0;
    int status;
    pid = fork();

    if (pid == -1){
        perror(NULL);
        exit (84);
    }else if (pid == 0){
        printf("%s\n%s\n", path, lil[0]);
        i = execve(path, &lil[0], env);
        if (i == -1)
            exit (2);
    }else {
        waitpid(pid, &status, 0);
        my_segfault(status);
    }
}