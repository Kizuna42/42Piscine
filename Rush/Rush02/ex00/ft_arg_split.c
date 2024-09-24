/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:41:00 by hnagashi          #+#    #+#             */
/*   Updated: 2024/09/22 22:28:53 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

void	ft_arg_cpy(char **a, int sepa, int digit, char *c)
{
	int	i;
	int	j;

	i = 0;
	digit--;
	while (i < sepa)
	{
		j = 0;
		while (j < 3)
		{
			if (digit >= 0)
			{
				a[i][2 - j] = c[digit];
				digit--;
			}
			else
				a[i][2 - j] = '0';
			j++;
		}
		a[i][3] = '\0';
		i++;
	}
}

void	ft_sepalate(char **a, int sepa)
{
	int	i;

	i = 0;
	while (i < sepa)
	{
		a[i] = malloc(4 * sizeof(char));
		if (!a[i])
		{
			while (i-- > 0)
				free(a[i]);
			free(a);
			return ;
		}
		i++;
	}
}

char	**ft_arg_strlen(char *c)
{
	char	**a;
	int		digit;
	int		sepa;

	digit = 0;
	while (c[digit] != '\0')
		digit++;
	if (digit % 3 != 0)
		sepa = digit / 3 + 1;
	else
		sepa = digit / 3;
	a = malloc((sepa + 1) * sizeof(char *));
	if (!a)
		return (NULL);
	a[sepa] = NULL;
	ft_sepalate(a, sepa);
	ft_arg_cpy(a, sepa, digit, c);
	return (a);
}

// int	main(int argc, char *argv[])
// {
// 	char	**a;
// 	int		i;
// 	int		j;

// 	if (argc != 2)
// 		return (0);
// 	a = ft_arg_strlen(argv[1]);
// 	if (!a)
// 		return (1);
// 	i = 0;
// 	while (a[i] != NULL)
// 	{
// 		j = 0;
// 		while (a[i][j] != '\0')
// 		{
// 			write(1, &a[i][j], 1);
// 			j++;
// 		}
// 		write(1, "\n", 1);
// 		i++;
// 	}
// 	i = 0;
// 	while (a[i] != NULL)
// 	{
// 		free(a[i]);
// 		i++;
// 	}
// 	free(a);
// 	return (0);
// }
