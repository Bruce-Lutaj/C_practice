#include <unistd.h>

int ft_check(int c, char *str, int ind)
{
    int i = 0;
    while (i < ind)
    {
        if (str[i] == c)
            return(1);
        i++;
    }
    return(0);
}

int main(int ac, char **av)
{
    int i = 0;
    int j = 0;
    int k = 0;
    if (ac == 3)
    {
        while(av[1][i])
            i++;
        while (av[2][j])
        {
            av[1][i] = av[2][j];
            j++;
            i++;
        }
        i--;
        while(k <= i)
        {
            if(!ft_check(av[1][k], av[1], k))
                write(1, &av[1][k], 1);
            k++;
        }
    }
    write(1, "\n", 1);
}