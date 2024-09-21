/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:56:25 by kishino           #+#    #+#             */
/*   Updated: 2024/09/17 15:51:12 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

// #include <stddef.h> // size_t型を使うために必要

// int	main(void)
// {
// 	// テストケース
// 	int test_cases[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81,100, 121, 144,
// 					169, 196,2147483647 / 2 + 1, -1, -16, 17, 20, 300};
// 	size_t i; // size_t型に変更
// 	int result;

// 	printf("Testing ft_sqrt function:\n");
// 	for (i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
// 	{
// 		result = ft_sqrt(test_cases[i]);
// 		printf("ft_sqrt(%d) = %d\n", test_cases[i], result);
// 	}

// 	return (0);
// }
