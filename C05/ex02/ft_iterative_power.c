/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:54:51 by kishino           #+#    #+#             */
/*   Updated: 2024/09/13 22:13:24 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	if (nb >= 0 && power == 0)
		return (1);
	if (nb < 0 || power < 0)
		return (0);
	else
	{
		nb *= i;
		power--;
	}
	return (nb);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%i", ft_iterative_power(0, 9));
// }
