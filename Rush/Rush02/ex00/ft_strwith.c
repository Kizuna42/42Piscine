/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwith.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:17:24 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/22 22:33:52 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 文字列strが数字で開始されてるかどうか
 * @param str 対象の文字列
 * @return ブール値
 */
t_bool	ft_startwith_int(char *str)
{
	if (str[0] < '0' || '9' < str[0])
		return (FALSE);
	return (TRUE);
}

/**
 * @fn
 * 文字列strが表示可能文字で終了されてるかどうか
 * @param str 対象の文字列
 * @return ブール値
 */
t_bool	ft_endwith_pa(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[0] < ' ' || '~' < str[0])
		return (FALSE);
	return (TRUE);
}
