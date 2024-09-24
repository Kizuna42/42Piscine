/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:36:26 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/22 23:36:38 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

void	print_inner_result(char ***result, int b, int *count)
{
	int	j;
	int	k;

	j = 0;
	while (result[b][j] != NULL)
	{
		k = 0;
		while (result[b][j][k] != '\0')
		{
			if (*count != 0 && k == 0)
				write(1, " ", 1);
			write(1, &result[b][j][k], 1);
			(*count)++;
			k++;
		}
		j++;
	}
}

void	print_separated_result(char ***result, int b)
{
	int	j;
	int	k;

	j = 0;
	while (result[b + 1][j] != NULL)
	{
		k = 0;
		write(1, " ", 1);
		while (result[b + 1][j][k] != '\0')
		{
			write(1, &result[b + 1][j][k], 1);
			k++;
		}
		j++;
	}
}

void	print_zero(t_dict_elem *dict)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i].p_int != NULL)
	{
		if (dict[i].p_int[0] == '0')
		{
			j = 0;
			while (dict[i].str[j] != '\0')
			{
				write(1, &dict[i].str[j], 1);
				j++;
			}
		}
		i++;
	}
}
