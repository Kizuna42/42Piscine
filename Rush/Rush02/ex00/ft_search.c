/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:03:32 by hnagashi          #+#    #+#             */
/*   Updated: 2024/09/22 23:37:33 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

void	ft_result(char *words, t_dict_elem *dict)
{
	char	**a;
	char	***result;
	int		count;
	int		i;
	int		b;

	count = 0;
	i = 0;
	a = ft_arg_strlen(words);
	if (!a)
		return ;
	result = allocate_result(a);
	if (!result)
		return ;
	while (a[i] != NULL)
	{
		if (!process_word(i, a[i], result, dict))
			return ;
		i++;
	}
	b = (i - 1) * 2;
	print_result(result, b, &count);
	if (count == 0)
		print_zero(dict);
	write(1, "\n", 1);
}

char	***allocate_result(char **a)
{
	int		i;
	char	***result;

	i = 0;
	while (a[i] != NULL)
		i++;
	result = malloc((i * 2 + 1) * sizeof(char **));
	if (!result)
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	result[i * 2] = NULL;
	return (result);
}

int	process_word(int i, char *word, char ***result, t_dict_elem *dict)
{
	result[i * 2] = malloc(5 * sizeof(char *));
	if (!result[i * 2])
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!ft_search(word, result[i * 2], dict))
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	result[i * 2 + 1] = malloc(2 * sizeof(char *));
	if (!result[i * 2 + 1])
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!ft_place_search(i, word, result[i * 2 + 1], dict))
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	return (1);
}

void	print_result(char ***result, int b, int *count)
{
	while (b >= 0)
	{
		print_inner_result(result, b, count);
		print_separated_result(result, b);
		b -= 2;
	}
}
