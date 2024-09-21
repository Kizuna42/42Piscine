/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:33:17 by kishino           #+#    #+#             */
/*   Updated: 2024/09/18 13:46:27 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_get_len_and_neg(int nbr, int s_base_to, int *neg)
{
	int	len;

	len = 1;
	*neg = 0;
	if (nbr < 0)
	{
		*neg = 1;
		nbr = -nbr;
		len++;
	}
	while (nbr / s_base_to > 0)
	{
		nbr /= s_base_to;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int nbr, char *base_to, int s_base_to)
{
	char	*result;
	int		len;
	int		neg;

	len = ft_get_len_and_neg(nbr, s_base_to, &neg);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr < 0)
		nbr = -nbr;
	while (len--)
	{
		result[len] = base_to[nbr % s_base_to];
		nbr /= s_base_to;
	}
	if (neg)
		result[0] = '-';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		s_base_from;
	int		s_base_to;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	s_base_from = ft_strlen(base_from);
	s_base_to = ft_strlen(base_to);
	nb = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(nb, base_to, s_base_to));
}

// #include <stdio.h>

// int main(void)
// {
//     char *nbr;
//     char *result;

//     // 2進数 -> 10進数
//     nbr = "1010";
//     result = ft_convert_base(nbr, "01", "0123456789");
//     printf("Binary 1010 to Decimal: %s\n", result);
//     free(result);

//     // 10進数 -> 2進数
//     nbr = "10";
//     result = ft_convert_base(nbr, "0123456789", "01");
//     printf("Decimal 10 to Binary: %s\n", result);
//     free(result);

//     // 16進数 -> 10進数
//     nbr = "1A";
//     result = ft_convert_base(nbr, "0123456789ABCDEF", "0123456789");
//     printf("Hexadecimal 1A to Decimal: %s\n", result);
//     free(result);

//     // 10進数 -> 16進数
//     nbr = "26";
//     result = ft_convert_base(nbr, "0123456789", "0123456789ABCDEF");
//     printf("Decimal 26 to Hexadecimal: %s\n", result);
//     free(result);

//     // 10進数 -> 8進数
//     nbr = "83";
//     result = ft_convert_base(nbr, "0123456789", "01234567");
//     printf("Decimal 83 to Octal: %s\n", result);
//     free(result);

//     return 0;
// }
