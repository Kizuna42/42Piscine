/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:34:17 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/22 23:40:36 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

void	search_tens_and_units_place(char *words, char **result,
		t_dict_elem *dict, char *tensplace)
{
	if (tensplace[0] == '1')
		handle_teens_case(words, result, dict, tensplace);
	else
		handle_tens_and_units(words, result, dict, tensplace);
}

void	handle_tens_and_units(char *words, char **result, t_dict_elem *dict,
		char *tensplace)
{
	int	i;

	i = 0;
	while (dict[i].str != NULL)
	{
		if (ft_strcmp(dict[i].p_int, tensplace) == 0 && words[1] != '0')
		{
			result[2] = malloc((ft_strlen(dict[i].p_int) + 1) * sizeof(char));
			if (result[2])
				ft_strcpy(result[2], dict[i].str);
		}
		else if (ft_strlen(dict[i].p_int) == 1 && dict[i].p_int[0] == words[2]
			&& words[2] != '0')
		{
			result[3] = malloc((ft_strlen(dict[i].p_int) + 1) * sizeof(char));
			if (result[3])
				ft_strcpy(result[3], dict[i].str);
		}
		i++;
	}
}

char	*create_search_string(int place)
{
	char	*searchs;
	int		i;

	searchs = malloc((place * 3 + 2) * sizeof(char));
	if (!searchs)
		return (NULL);
	searchs[0] = '1';
	i = 1;
	while (i < place * 3 + 1)
	{
		searchs[i] = '0';
		i++;
	}
	searchs[place * 3 + 1] = '\0';
	return (searchs);
}

int	process_dict(char **result, t_dict_elem *dict, char *searchs)
{
	int	i;

	i = 0;
	while (dict[i].p_int != NULL)
	{
		if (ft_strcmp(dict[i].p_int, searchs) == 0)
		{
			result[0] = malloc((ft_strlen(dict[i].str) + 1) * sizeof(char));
			if (!result[0])
			{
				free(searchs);
				return (FALSE);
			}
			ft_strcpy(result[0], dict[i].str);
			free(searchs);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int	ft_place_search(int place, char *words, char **result, t_dict_elem *dict)
{
	char	*searchs;
	int		found;

	searchs = create_search_string(place);
	if (!searchs)
		return (FALSE);
	result[0] = NULL;
	result[1] = NULL;
	if (ft_strcmp(words, "000") == 0 || place == 0)
	{
		free(searchs);
		return (TRUE);
	}
	found = process_dict(result, dict, searchs);
	if (!found)
		free(searchs);
	return (found);
}
