/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:44:21 by kishino           #+#    #+#             */
/*   Updated: 2024/09/14 20:46:21 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\n' || base[i] == '\t' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r')
			return (0);
		z = i + 1;
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

int	ft_convert_base(char *str, char *base, int s_base, int neg)
{
	int	num;
	int	base_value;

	num = 0;
	while (*str)
	{
		base_value = base_index(*str, base);
		if (base_value == -1)
			break ;
		num = num * s_base + base_value;
		str++;
	}
	return (num * neg);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	s_base;

	i = 0;
	s_base = 0;
	if (!check_base(base))
		return (0);
	while (base[s_base])
		s_base++;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	neg = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	return (ft_convert_base(&str[i], base, s_base, neg));
}

// #include <stdio.h>
// #include <limits.h>

// void test_case(char *str, char *base)
// {
// 	int result = ft_atoi_base(str, base);
// 	printf("Input: \"%s\", Base: \"%s\", Result: %d\n", str, base, result);
// }

// int	main(void)
// {
// 	// Valid cases
// 	test_case("1234", "0123456789");       // Decimal
// 	test_case("-1234", "0123456789");      // Decimal negative
// 	test_case("10011010010", "01");        // Binary
// 	test_case("-10011010010", "01");       // Binary negative
// 	test_case("4D2", "0123456789ABCDEF");  // Hexadecimal
// 	test_case("-4D2", "0123456789ABCDEF"); // Hexadecimal negative
// 	test_case("nenn", "poneyvif");         // Octal
// 	test_case("-nenn", "poneyvif");        // Octal negative

// 	// Invalid cases
// 	test_case("1234", "");                 // Invalid base (empty)
// 	test_case("1234", "1");                // Invalid base (s 1)
// 	test_case("1234", "0123456789+");      // Invalid base (contains '+')
// 	test_case("1234", "0123456789-");      // Invalid base (contains '-')
// 	test_case("1234", "01234 6789");       // Invalid base (contains space)
// 	test_case("1234", "01234\n6789");      // Invalid base (contains newline)

// 	// Edge cases
// 	test_case("2147483647", "0123456789"); // INT_MAX
// 	test_case("-2147483648", "0123456789"); // INT_MIN

// 	return (0);
// }
