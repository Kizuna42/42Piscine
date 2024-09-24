/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:24:33 by hnagashi          #+#    #+#             */
/*   Updated: 2024/09/22 22:46:01 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 引数として渡された2つのt_dict_elemの値を交換する
 * @param a 交換対象のt_dict_elemのポインタ
 * @param b 交換対象のt_dict_elemのポインタ
 */
void	ft_swap(t_dict_elem *a, t_dict_elem *b)
{
	t_dict_elem	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * @fn
 * 配列dictにある各t_dict_elem型変数のp_intメンバーをcmp関数に与え、
 * その戻り値に応じて配列を並び替える関数。
 * 配列内のポインタお交換することにより並べ替えが実行される。
 * @param dict ソート対象のt_dict_elem型配列
 * @param cmp 比較用の関数ポインタ
 */
void	ft_sort_dict_tab(t_dict_elem *dict, int (*cmp)(char *, char *))
{
	int	i;
	int	count;

	if (!dict)
		return ;
	count = 0;
	while (count == 0)
	{
		count = 1;
		i = 0;
		while (dict[i + 1].str)
		{
			if (cmp(dict[i].p_int, dict[i + 1].p_int) > 0)
			{
				ft_swap(&dict[i], &dict[i + 1]);
				count = 0;
			}
			i++;
		}
	}
}
