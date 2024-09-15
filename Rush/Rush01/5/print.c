/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:42:43 by yossasak          #+#    #+#             */
/*   Updated: 2024/09/15 14:20:18 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define S 5

void	print_criteria(int arr[S][S])
{
	int		i;
	int		j;
	char	ans;

	i = -1;
	while (++i < S)
	{
		j = -1;
		while (++j < S - 1)
		{
			ans = arr[i][j] + '0';
			write(1, &ans, 1);
			write(1, " ", 1);
		}
		ans = arr[i][j] + '0';
		write(1, &ans, 1);
		write(1, "\n", 1);
	}
}
