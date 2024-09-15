/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:44:23 by kishino           #+#    #+#             */
/*   Updated: 2024/09/14 20:46:21 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	convert_to_base(long nbr, char *base, int s_base)
{
	if (nbr >= s_base)
		convert_to_base(nbr / s_base, base, s_base);
	ft_putchar(base[nbr % s_base]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		s_base;
	long	lnbr;

	if (!check_base(base))
		return ;
	s_base = 0;
	while (base[s_base])
		s_base++;
	lnbr = nbr;
	if (lnbr < 0)
	{
		ft_putchar('-');
		lnbr = -lnbr;
	}
	convert_to_base(lnbr, base, s_base);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// テストケース 1: 10進数
// 	printf("10進数 (正の数): ");
// 	ft_putnbr_base(1234, "0123456789");
// 	printf("\n");

// 	// テストケース 2: 10進数（負の数）
// 	printf("10進数 (負の数): ");
// 	ft_putnbr_base(-1234, "0123456789");
// 	printf("\n");

// 	// テストケース 3: 2進数
// 	printf("2進数 (正の数): ");
// 	ft_putnbr_base(1234, "01");
// 	printf("\n");

// 	// テストケース 4: 2進数（負の数）
// 	printf("2進数 (負の数): ");
// 	ft_putnbr_base(-1234, "01");
// 	printf("\n");

// 	// テストケース 5: 16進数
// 	printf("16進数 (正の数): ");
// 	ft_putnbr_base(1234, "0123456789ABCDEF");
// 	printf("\n");

// 	// テストケース 6: 16進数（負の数）
// 	printf("16進数 (負の数): ");
// 	ft_putnbr_base(-1234, "0123456789ABCDEF");
// 	printf("\n");

// 	// テストケース 7: 8進数（カスタムベース）
// 	printf("8進数 (カスタムベース, 正の数): ");
// 	ft_putnbr_base(1234, "poneyvif");
// 	printf("\n");

// 	// テストケース 8: 8進数（カスタムベース、負の数）
// 	printf("8進数 (カスタムベース, 負の数): ");
// 	ft_putnbr_base(-1234, "poneyvif");
// 	printf("\n");

// 	// テストケース 9: INT_MIN (10進数)
// 	printf("INT_MIN (10進数): ");
// 	ft_putnbr_base(INT_MIN, "0123456789");
// 	printf("\n");

// 	// テストケース 10: INT_MIN (16進数)
// 	printf("INT_MIN (16進数): ");
// 	ft_putnbr_base(INT_MIN, "0123456789ABCDEF");
// 	printf("\n");

// 	// 無効なベース
// 	printf("無効なベース (+含む): ");
// 	ft_putnbr_base(1234, "012+3456789");
// 	printf("\n");

// 	// 無効なベース（1文字）
// 	printf("無効なベース (1文字): ");
// 	ft_putnbr_base(1234, "0");
// 	printf("\n");

// 	// 無効なベース（空のベース）
// 	printf("無効なベース（空のベース）: ");
// 	ft_putnbr_base(1234, "");
// 	printf("\n");

// 	return (0);
// }
