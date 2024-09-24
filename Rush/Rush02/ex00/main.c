/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:17:58 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/22 22:51:56 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

char	**check_file_format(char *file_name)
{
	char	*buf;
	char	**lines;

	buf = read_file(file_name);
	if (buf == NULL)
		return (NULL);
	lines = read_lines(buf);
	if (lines == NULL)
	{
		free(buf);
		return (NULL);
	}
	if (!check_dict_format(lines))
	{
		free(buf);
		free_2d_all((void **)lines);
		ft_putstr("Dict Error\n");
		return (NULL);
	}
	free(buf);
	return (lines);
}

void	main_process(char **lines, char *num)
{
	t_dict_elem	*dict;

	dict = ft_comvert_to_dict(lines, get_line_countl(lines));
	if (dict == NULL)
	{
		free_2d_all((void **)lines);
		return ;
	}
	ft_sort_dict(dict);
	if (!ft_is_duplication(dict))
	{
		free_2d_all((void **)lines);
		free_dict_arr_all(dict);
		ft_putstr("Dict Error\n");
		return ;
	}
	ft_result(num, dict);
	free_2d_all((void **)lines);
	free_dict_arr_all(dict);
}

int	main(int argc, char **argv)
{
	char	**lines;

	if (argc == 2)
	{
		if (is_integer(argv[1]))
		{
			lines = check_file_format("numbers.dict");
			if (lines != NULL)
				main_process(lines, argv[1]);
		}
		else
			ft_putstr("Error\n");
	}
	else if (argc == 3)
	{
		if (is_integer(argv[2]))
		{
			lines = check_file_format(argv[1]);
			if (lines != NULL)
				main_process(lines, argv[2]);
		}
		else
			ft_putstr("Error\n");
	}
}
