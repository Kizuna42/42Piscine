/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidler <jidler@student.42tokyo.jp >        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-15 13:46:37 by jidler            #+#    #+#             */
/*   Updated: 2024-09-15 13:46:37 by jidler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define S 5

void	print_field(int arr[S][S])
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
