#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

// Write %s

int		ft_putstr(char *str)
{
	int i = 0;
	
    if (!str)
    {
        write(1, "(null)", 6);
        return (6);
    }
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

// Write %d

int	cifre(int n)
{
	int i = 0;

	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nl = n;
	int		len = cifre(n);
	char	*str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);

	if (nl == 0)
		str[0] = '0';
	str[len] = '\0';
	if (nl < 0)
	{
		str[0] = '-';
		nl = -nl;
	}
	len--;
	while (nl != 0)
	{
		str[len] = nl % 10 + 48;
		nl /= 10;
		len--;
	}
	return (str);
}

int	ft_putnbr(int n)
{
	char	*s = ft_itoa(n);
	int		len = ft_putstr(s);
	free(s);
	return (len);
}

// Write %x

void ft_char(char c)
{
	write(1, &c, 1);
}

int len_hex(unsigned int n)
{
	int i = 0;

	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	write_hex(unsigned int n)
{
	if (n >= 16)
	{
		write_hex(n / 16);
		write_hex(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_char(n + 48);
		else
			ft_char(n - 10 + 'a');
	}
}

int	ft_puthex(unsigned int n)
{
	int len = len_hex(n);
	if (!n)
	{
		ft_char('0');
		return (1);
	}
	else
		write_hex(n);
	return (len);
}

// Printf function

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_specifier(const char c, va_list ap)
{
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(ap, unsigned int)));
	return (0);
}

int ft_printf(const char *str, ...)
{
	int	i = 0;
	int len = 0;
	va_list	ap;

	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_specifier(str[i + 1], ap);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
