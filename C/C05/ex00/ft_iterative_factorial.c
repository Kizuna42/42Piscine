/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:43:07 by kishino           #+#    #+#             */
/*   Updated: 2024/09/12 16:56:28 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i++ < nb)
		result *= i;
	return (result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	nb = 5;
// 	int	factorial;
// 	factorial = ft_iterative_factorial(nb);
// 	printf("Factorial of %d is %d\n", nb, factorial);
// 	return (0);
// }
