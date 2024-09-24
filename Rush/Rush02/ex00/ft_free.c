/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:20:50 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/22 22:39:59 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 2次元配列のメモリ確保を全てフリーする
 * @param arr 対象の配列
 */
void	free_2d_all(void **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

/**
 * @fn
 * t_dict_elem型配列の各要素を全てフリーする
 * @param dict 対象のt_dict_elem型配列のポインタ
 */
void	free_dict_arr_all(t_dict_elem *dict)
{
	int	i;

	i = 0;
	while (dict[i].str != NULL)
	{
		free(dict[i].p_int);
		free(dict[i].str);
		i++;
	}
	free(dict);
}

/**
 * @fn
 * 三次元配列をフリーする(確保中用)
 * @param arr 対象の三次元配列
 * @param i インデックス1
 * @param j インデックス2
 */
void	free_3d(void ***arr, int i, int j)
{
	int	k;

	k = i - 1;
	while (k >= 0)
		free_2d(arr[k--], j);
	free(arr);
}

/**
 * @fn
 * 二次元配列をフリーする(確保中用)
 * @param arr 対象の二次元配列
 * @param i インデックス1
 */
void	free_2d(void **arr, int i)
{
	int	k;

	k = i - 1;
	while (k >= 0)
		free(arr[k--]);
	free(arr);
}

/**
 * @fn
 * t_dict_elem型配列の各要素をフリーする(確保中用)
 * @param dict 対象のt_dict_elem型配列のポインタ
 * @param i インデックス1
 */
void	free_dict_arr(t_dict_elem *dict, int i)
{
	int	k;

	k = i - 1;
	while (k >= 0)
	{
		if (dict->p_int != NULL)
			free(dict->p_int);
		if (dict->str != NULL)
			free(dict->str);
	}
	free(dict);
}
