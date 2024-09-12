/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:56:59 by kishino           #+#    #+#             */
/*   Updated: 2024/09/12 13:42:37 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_array(char *v, int size, int last)
{
	int	i;

	i = 0;
	if (v[0] == last)
	{
		while (i < size)
			ft_putchar(v[i++]);
		return ;
	}
	while (i < size)
		ft_putchar(v[i++]);
	write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	int		flag;
	int		base;
	int		i;
	char	v[10];
	char	v_max[10];

	if (n <= 0 || n > 10)
		return ;
	i = -1;
	while (i++ < n)
	{
		v[i] = i + 48;
		v_max[i] = (10 - n) + i + 48;
	}
	print_array(v, n, v_max[0]);
	while (v[0] != v_max[0])
	{
		flag = n - 1;
		while (v[flag] == v_max[flag])
			--flag;
		base = ++(v[flag]);
		while (flag < n)
			v[++flag] = ++base;
		print_array(v, n, v_max[0]);
	}
}

// int	main(void)
// {
// 	ft_print_combn(4);
// }
