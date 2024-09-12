/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:46:07 by kishino           #+#    #+#             */
/*   Updated: 2024/09/08 12:14:39 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char value);

void	rush_end(int x)
{
	int	i;
	int	k;

	i = 0;
	k = x - 2;
	ft_putchar('A');
	while (i < k)
	{
		ft_putchar('B');
		i++;
	}
	if (x >= 2)
		ft_putchar('C');
	ft_putchar('\n');
}

void	rush_middle(int x, int y, int z)
{
	int	i;
	int	j;
	int	count;

	j = y - 2;
	count = 0;
	while (count < j)
	{
		i = 0;
		ft_putchar('B');
		while (i < z)
		{
			ft_putchar(' ');
			i++;
		}
		if (x > 1)
			ft_putchar('B');
		ft_putchar('\n');
		count++;
	}
}

void	rush(int x, int y)
{
	int	i;
	int	z;

	i = 0;
	z = x - 2;
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	ft_putchar('A');
	while (i < z)
	{
		ft_putchar('B');
		i++;
	}
	if (x > 1)
		ft_putchar('C');
	ft_putchar('\n');
	if (y > 2)
		rush_middle(x, y, z);
	if (y > 1)
		rush_end(x);
}
