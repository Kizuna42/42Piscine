/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:55:44 by kishino           #+#    #+#             */
/*   Updated: 2024/09/13 22:14:01 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (nb >= 0 && power == 0)
		return (1);
	if (nb < 0 || power < 0)
		return (0);
	return (nb * ft_recursive_power(nb, power -1));
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%i", ft_recursive_power(3, 4));
// }
