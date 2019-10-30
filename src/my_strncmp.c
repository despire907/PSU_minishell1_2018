/*
** EPITECH PROJECT, 2018
** task06
** File description:
** task06
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int papa = 0;

    while (s1[papa] == s2[papa] && s1[papa] && s2[papa] && (papa < n || n < 0)){
        ++papa;
    }
    if (papa == n && papa > 0)
        return (s1[papa - 1] - s2[papa - 1]);
    return ( s1[papa] - s2[papa]);
}
