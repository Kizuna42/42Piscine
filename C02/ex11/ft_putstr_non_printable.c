/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:23:43 by kishino           #+#    #+#             */
/*   Updated: 2024/09/09 17:43:33 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_hex(int np)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (np >= 16)
	{
		print_hex(np / 16);
		print_hex(np % 16);
	}
	else
	{
		write(1, &hex[np], 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 32 && str[i] >= 0) || str[i] == 127)
		{
			write(1, "\\", 1);
			if (str[i] < 16)
				write(1, "0", 1);
			print_hex(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
