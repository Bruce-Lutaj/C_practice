/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:47:10 by brulutaj          #+#    #+#             */
/*   Updated: 2024/05/09 11:52:15 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

char	*ft_itoa(int nbr)
{
	char	*str;
	int		len = 0;
	int		n = nbr;
	
	if (nbr == -2147483648)
		return ("-2147483648");
	n = nbr;
	if (nbr <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		str[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (str);
}

int main(void)
{
	char *str;

	str = ft_itoa(123);
	printf("%s", str);
}