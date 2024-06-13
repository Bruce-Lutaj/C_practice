/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:04:50 by brulutaj          #+#    #+#             */
/*   Updated: 2024/05/06 18:29:25 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int *array;
	int len;
	int i = 0;

	len = 0;
	if (end > start)
        len = end - start;
    else if (start > end)
	{
        len = start - end;
	}
	array = (int *)malloc(len * sizeof(int));
	if (!array)
		return (NULL);
	while (i <= len)
	{
		if (start >= end)
		{
			array[i] = end;
			end++;
			i++;
		}
		else if (start <= end)
		{
			array[i] = end;
			end--;
			i++;
		}
	}
	return(array);
}

int main(void)
{
    int *k;
    int i = 0;
    k = ft_rrange(0, -3);
    while (i < 4)
    {
        printf("%d\n", k[i]);
        i++;
    }
    return (0);
}