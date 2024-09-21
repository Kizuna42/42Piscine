/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:54:51 by kishino           #+#    #+#             */
/*   Updated: 2024/09/16 18:46:01 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	i = 0;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	result = 1;
	while (i++ < power)
		result *= nb;
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%i", ft_iterative_power(2, 5));
// }
