/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:44:13 by kishino           #+#    #+#             */
/*   Updated: 2024/09/12 18:32:20 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<limits.h>
#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

// int main()
// {
//     int number = 2147483647;
//     ft_putnbr(number);
//     write(1, "\n", 1);
//     return 0;
// }