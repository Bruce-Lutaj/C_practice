#include <unistd.h>

int ft_atoi(char *str)
{
    int res = 0;
    int i = 0;
    while (str[i])
    {
        res = res * 10 + (str[i] - 48);
        i++;
    }
        return(res);
}

int check_prime(int n)
{
    int i = 2;

    if (n <= 1)
        return (0);
    while(i * i <= n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

void ft_numbr(int n)
{
    char num;

    num = n % 10 + 48;
    if (n >= 10)
        ft_numbr(n / 10);
    write(1, &num, 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = ft_atoi(av[1]);
        int sum = 0;
        while(i > 0)
        {
            if (check_prime(i))
                sum += i;
            i--;
        }
        ft_numbr(sum);
    }
    else
        write(1, "0\n", 2);
    return(0);
}