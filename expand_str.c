#include <unistd.h>

int is_alpha(int c)
{
    if (c >= 33 && c <= 126)
        return (1);
    return (0);
}

int is_space(int c)
{
    if  (c == 32 || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    int i = 0;
    if (ac == 2)
    {
        while (is_space(av[1][i]))
            i++;
        while (av[1][i])
        {
            if (is_alpha(av[1][i]))
                write(1, &av[1][i], 1);
            else if (is_space(av[1][i]) && is_alpha(av[1][i + 1]))
                write(1, "   ", 3);
            i++;
        }
    }
    write(1, "\n", 1);
}