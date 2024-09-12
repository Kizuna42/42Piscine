/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:44:21 by kishino           #+#    #+#             */
/*   Updated: 2024/09/12 17:35:39 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

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
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\n' || base[i] == '\t' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r')
			return (0);
		while (base[z])
			if (base[i] == base[z++])
				return (0);
		i++;
	}
	return (1);
}

int	base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_convert_base(char *str, char *base, int size_base, int neg)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (base_index(str[i], base) != -1)
	{
		num = num * size_base + base_index(str[i], base);
		i++;
	}
	return (num * neg);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	size_base;
	int	result;

	i = 0;
	neg = 1;
	size_base = 0;
	if (!check_base(base))
		return (0);
	while (base[size_base])
		size_base++;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	if (base_index(str[i], base) == -1)
		// return (0);
	result = ft_convert_base(&str[i], base, size_base, neg);
	return (result);
}

// #include<stdio.h>

// int main(void)
// {
// 	// テストケース
// 	char str1[] = "1010"; // 10進数では 10
// 	char base1[] = "01";  // 2進数

// 	char str2[] = "1A";   // 10進数では 26
// 	char base2[] = "0123456789ABCDEF"; // 16進数

// 	char str3[] = "123";  // 10進数では 123
// 	char base3[] = "0123456789"; // 10進数

// 	char str4[] = "-1A";   // 10進数では -26
// 	char base4[] = "0123456789ABCDEF"; // 16進数

// 	// 結果表示
// 	char buf[100];

// 	// テストケース1
// 	write(1, "Result 1: ", 10);
// 	int len = sprintf(buf, "%d\n", ft_atoi_base(str1, base1));
// 	write(1, buf, len);  // 期待される出力: 10

// 	// テストケース2
// 	write(1, "Result 2: ", 10);
// 	len = sprintf(buf, "%d\n", ft_atoi_base(str2, base2));
// 	write(1, buf, len);  // 期待される出力: 26

// 	// テストケース3
// 	write(1, "Result 3: ", 10);
// 	len = sprintf(buf, "%d\n", ft_atoi_base(str3, base3));
// 	write(1, buf, len);  // 期待される出力: 123

// 	// テストケース4
// 	write(1, "Result 4: ", 10);
// 	len = sprintf(buf, "%d\n", ft_atoi_base(str4, base4));
// 	write(1, buf, len);  // 期待される出力: -26

// 	return 0;
// }