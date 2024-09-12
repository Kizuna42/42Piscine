/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:44:23 by kishino           #+#    #+#             */
/*   Updated: 2024/09/12 19:27:46 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

void	handle_negative(int *nbr)
{
	if (*nbr == INT_MIN)
	{
		ft_putchar('-');
		ft_putchar('2');
		*nbr = 147483648;
	}
	else if (*nbr < 0)
	{
		*nbr = -*nbr;
		ft_putchar('-');
	}
}

void	convert_to_base(int nbr, char *base, int size_base)
{
	int	nbr_final[1024];
	int	i;

	i = 0;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	while (--i >= 0)
		ft_putchar(base[nbr_final[i]]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size_base;

	size_base = 0;
	if (check_base(base) == 1)
	{
		while (base[size_base])
			size_base++;
		handle_negative(&nbr);
		convert_to_base(nbr, base, size_base);
	}
	return ;
}

#include <stdio.h>


int	main(void)
{
	// テストケース 1: 10進数
	printf("abv");
	ft_putnbr_base(1234, "0123456789");
	printf("\n");

	// テストケース 2: 10進数（負の数）

	ft_putnbr_base(-1234, "0123456789");
	printf("\n");

	// テストケース 3: 2進数

	ft_putnbr_base(1234, "01");
	printf("\n");

	// テストケース 4: 2進数（負の数）

	ft_putnbr_base(-1234, "01");
	printf("\n");

	// テストケース 5: 16進数

	ft_putnbr_base(1234, "0123456789ABCDEF");
	printf("\n");

	// テストケース 6: 16進数（負の数）

	ft_putnbr_base(-1234, "0123456789ABCDEF");
	printf("\n");

	// テストケース 7: 8進数（カスタムベース）

	ft_putnbr_base(1234, "poneyvif");
	printf("\n");

	// テストケース 8: 8進数（カスタムベース、負の数）

	ft_putnbr_base(-1234, "poneyvif");
	printf("\n");

	// テストケース 9: INT_MIN

	ft_putnbr_base(-2147483648, "0123456789");
	printf("\n");

	// 無効なベース

	ft_putnbr_base(1234, "012+3456789");
	printf("\n");

	// 無効なベース（1文字）

	ft_putnbr_base(1234, "0");
	printf("\n");

	// 無効なベース（空のベース）
	ft_putnbr_base(1234, "");
	printf("\n");

	return (0);
}
