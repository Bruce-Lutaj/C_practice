/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:51:09 by brulutaj          #+#    #+#             */
/*   Updated: 2024/05/08 11:19:43 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	i;

    i = 0;
    if (a == 0 || b == 0)
		return (0);
	if (a > b)
		i = a;
	else
		i = b;
	while (1)
	{
		if (((i % a) == 0) && ((i % b) == 0))
			return (i);
		i++;
	}   
}

int main(void)
{
	unsigned int j;
	j = lcm (9, 10);
	printf("%i\n", j);
}