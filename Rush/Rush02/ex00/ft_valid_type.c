/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:10:43 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/22 22:29:55 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 文字列が正の整数かどうか判定する関数
 * @param str ヌル終端文字列
 * @return 文字列が整数だった場合はTRUE、それ以外はFALSEを返す
 */
t_bool	is_integer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
