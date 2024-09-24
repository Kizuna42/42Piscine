/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:41:28 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/22 22:50:01 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 辞書のフォーマットが正しいかどうかテストする関数
 * @param lines ファイルバッファを行ごとに区切った文字列配列
 * @return 正しかったらTRUE、間違ってたらFALSE
 * @note フォーマット：[数字][0以上の空白]:[0以上の空白][出力可能文字列]LF
 */
t_bool	check_dict_format(char **lines)
{
	int	i;
	int	c;

	i = 0;
	while (lines[i] != NULL)
	{
		c = ft_strs_count(lines[i], ":");
		if (c != 2)
			return (FALSE);
		if (!ft_startwith_int(lines[i]))
			return (FALSE);
		if (!ft_endwith_pa(lines[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/**
 * @fn
 * dictのキーが重複しているかチェックする
 * @param dict t_dict_elem型配列
 * @return 重複ありかなしかをt_boolで返す
 */
t_bool	ft_is_duplication(t_dict_elem *dict)
{
	int	i;

	i = 0;
	while (dict[i + 1].str != NULL)
	{
		if (ft_strcmp(dict[i].p_int, dict[i + 1].p_int) == 0)
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

/**
 * @fn
 * ファイルから読み込んだ内容を行ごとにdict型に変換する関数
 * @param lines ファイルバッファを行ごとに区切った文字列配列
 * @param line_nums 行数
 * @return 各行の内容が入ったt_dict_elem型の配列
 * @attention メモリ確保(malloc)ができなかった場合はNULLが返る
 */
t_dict_elem	*ft_comvert_to_dict(char **lines, int line_nums)
{
	t_dict_elem	*ret_val;
	int			i;
	char		**r;

	ret_val = (t_dict_elem *)malloc((line_nums + 1) * sizeof(t_dict_elem));
	if (ret_val == NULL)
		return (NULL);
	i = 0;
	while (i < line_nums)
	{
		r = ft_split(lines[i], ": \t\n\v\f\r");
		ret_val[i].p_int = (char *)malloc((ft_strlen(r[0]) + 1) * sizeof(char));
		ret_val[i].str = (char *)malloc((ft_strlen(r[1]) + 1) * sizeof(char));
		if (ret_val[i].p_int == NULL || ret_val[i].str == NULL)
		{
			free_dict_arr(ret_val, i);
			return (NULL);
		}
		ft_strcpy(ret_val[i].p_int, r[0]);
		ft_strcpy(ret_val[i].str, r[1]);
		i++;
	}
	ret_val[i].str = NULL;
	return (ret_val);
}

/**
 * @fn
 * p_int順にdictをソートする関数
 * @param dict ソート対象のt_dict_elem型配列
 */
void	ft_sort_dict(t_dict_elem *dict)
{
	ft_sort_dict_tab(dict, ft_strcmp_len);
}
