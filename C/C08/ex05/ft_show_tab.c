/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:22:43 by kishino           #+#    #+#             */
/*   Updated: 2024/09/17 20:21:43 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + '0');
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		i++;
	}
}

// int	main(void)
// {
// 	char	*strings[] = {
// 		"Hello",
// 		"World",
// 		"42",
// 		"C Programming"
// 	};

// 	// s_stock_str の配列を作成
// 	struct s_stock_str *stock = ft_strs_to_tab(4, strings);

// 	// 配列を表示
// 	ft_show_tab(stock);

// 	// メモリの解放
// 	int i = 0;
// 	while (stock[i].str)
// 	{
// 		free(stock[i].copy);
// 		i++;
// 	}
// 	free(stock);
// 	return (0);
// }
