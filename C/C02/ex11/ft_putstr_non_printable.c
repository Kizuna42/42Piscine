/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:23:43 by kishino           #+#    #+#             */
/*   Updated: 2024/09/20 19:19:29 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	tmp;
	unsigned char	*cursor;
	char			*hex_symbols;

	hex_symbols = "0123456789abcdef";
	cursor = (unsigned char *)str;
	while (*cursor != '\0')
	{
		if (*cursor >= ' ' && *cursor <= '~')
			write(1, cursor, 1);
		else
		{
			ft_putchar('\\');
			tmp = *cursor / 16;
			ft_putchar(hex_symbols[tmp]);
			tmp = *cursor % 16;
			ft_putchar(hex_symbols[tmp]);
		}
		cursor++;
	}
}

// #include <unistd.h>
// #include <stdio.h>

// void print_hex(int np);
// void ft_putstr_non_printable(char *str);

// int main() {
//     char *test1 = "Hello, World!";
//     char *test2 = "Hello\tWorld\n";  // タブと改行を含む
//     char *test3 = "Non-printable: \x01\x02\x03\x04";  // 非表示文字

//     printf("Test 1:\n");
//     ft_putstr_non_printable(test1);
//     write(1, "\n", 1);

//     printf("Test 2:\n");
//     ft_putstr_non_printable(test2);
//     write(1, "\n", 1);

//     printf("Test 3:\n");
//     ft_putstr_non_printable(test3);
//     write(1, "\n", 1);
//     return 0;
// }
