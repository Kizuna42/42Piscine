/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:55:44 by kishino           #+#    #+#             */
/*   Updated: 2024/09/16 18:46:53 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	return (nb * ft_recursive_power(nb, power -1));
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%i\n", ft_recursive_power(2, 3));  // 結果は 8
// 	printf("%i\n", ft_recursive_power(5, 0));  // 結果は 1
// 	printf("%i\n", ft_recursive_power(3, 2));  // 結果は 9
// 	printf("%i\n", ft_recursive_power(-2, 3)); // 結果は -8
// }
