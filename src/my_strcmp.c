/*
** EPITECH PROJECT, 2018
** task05
** File description:
** task05
*/

int my_strcmp(char const *s1, char const *s2)
{
    int papa = 0;

    while (s1[papa] == s2[papa] && s1[papa] && s2[papa]) {
        ++papa;
    }
    return (s1[papa] - s2[papa]);
}
