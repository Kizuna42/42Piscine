/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:35:16 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/22 23:38:08 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

int	ft_search(char *words, char **result, t_dict_elem *dict)
{
	char	tensplace[3];

	if (handle_zero_case(words, result) == FALSE)
		return (FALSE);
	tensplace[0] = words[1];
	tensplace[1] = '0';
	tensplace[2] = '\0';
	search_single_digit(words, result, dict);
	search_hundreds_place(words, result, dict);
	search_tens_and_units_place(words, result, dict, tensplace);
	return (TRUE);
}

int	handle_zero_case(char *words, char **result)
{
	if (words[0] - '0' == 0)
	{
		result[0] = "\0";
		result[1] = "\0";
	}
	if (words[1] == '0')
		result[2] = "\0";
	if (words[2] == '0')
		result[3] = "\0";
	result[4] = NULL;
	return (TRUE);
}

void	search_single_digit(char *words, char **result, t_dict_elem *dict)
{
	int	i;

	i = 0;
	while (dict[i].str != NULL)
	{
		if (ft_strlen(dict[i].p_int) == 1 && dict[i].p_int[0] == words[0]
			&& words[0] != '0')
		{
			result[0] = malloc((ft_strlen(dict[i].p_int) + 1) * sizeof(char));
			if (result[0])
				ft_strcpy(result[0], dict[i].str);
		}
		i++;
	}
}

void	search_hundreds_place(char *words, char **result, t_dict_elem *dict)
{
	int	i;

	i = 0;
	while (dict[i].str != NULL)
	{
		if (ft_strcmp(dict[i].p_int, "100") == 0 && words[0] != '0')
		{
			result[1] = malloc((ft_strlen(dict[i].p_int) + 1) * sizeof(char));
			if (result[1])
				ft_strcpy(result[1], dict[i].str);
		}
		i++;
	}
}

void	handle_teens_case(char *words, char **result, t_dict_elem *dict,
		char *tensplace)
{
	int	i;

	i = 0;
	tensplace[1] = words[2];
	while (dict[i].str != NULL)
	{
		if (ft_strcmp(dict[i].p_int, tensplace) == 0)
		{
			result[2] = malloc((ft_strlen(dict[i].p_int) + 1) * sizeof(char));
			if (result[2])
				ft_strcpy(result[2], dict[i].str);
			result[3] = NULL;
			break ;
		}
		i++;
	}
}
