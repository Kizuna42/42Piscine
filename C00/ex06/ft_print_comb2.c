/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:56:53 by kishino           #+#    #+#             */
/*   Updated: 2024/09/07 22:48:20 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	o;

	if (nb >= 10)
	{
		ft_putchar(nb / 10 + 48);
		o = nb % 10;
		ft_putchar(o + 48);
	}
	else
	{
		ft_putchar('0');
		ft_putchar(nb + 48);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_putnbr(i);
			ft_putchar(' ');
			ft_putnbr(j);
			if (i < 98 || j < 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			j++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	ft_print_comb2();
// 	return (0);
// }
