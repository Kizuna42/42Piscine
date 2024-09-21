/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:21:27 by kishino           #+#    #+#             */
/*   Updated: 2024/09/21 16:50:32 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	c;

	c = 0;
	result = (int *)malloc(sizeof(int) * length);
	while (c < length)
	{
		result[c] = f(tab[c]);
		c++;
	}
	return (result);
}
