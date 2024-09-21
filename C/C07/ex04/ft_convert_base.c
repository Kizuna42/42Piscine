/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:33:15 by kishino           #+#    #+#             */
/*   Updated: 2024/09/18 13:22:39 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

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

int	ft_convert(char *str, char *base, int s_base, int neg)
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
	return (ft_convert(&str[i], base, s_base, neg));
}
