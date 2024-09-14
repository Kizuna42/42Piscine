/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:42:43 by yossasak          #+#    #+#             */
/*   Updated: 2024/09/14 15:42:45 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_criteria(int arr[4][4])
{
	int		i;
	int		j;
	char	ans;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
		{
			ans = arr[i][j] + 48;
			write(1, &ans, 1);
			write(1, " ", 1);
		}
		ans = arr[i][j] + 48;
		write(1, &ans, 1);
		write(1, "\n", 1);
	}
}
