/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declaration.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:41:48 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/22 23:39:38 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECLARATION_H
# define DECLARATION_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # define DEBUG

// 真偽値
typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

// 辞書の要素型
typedef struct s_dict_elem
{
	char	*p_int;
	char	*str;
}			t_dict_elem;

// ft_file_io.c
char		*read_file(char *file_name);
int			get_file_size(char *file_name);
char		**read_lines(char *buf);
int			get_line_count(char *buf);
int			get_line_countl(char **lines);

// ft_split.c
// char		*ft_substr(char *str, int start, int len);
// int			ft_c_is_charset(char c, char *charset);
// int			find_start_end(char *str, char *charset, int *j,
// 				int flag);
int			ft_strs_count(char *str, char *charset);
char		**ft_split(char *str, char *charset);

// ft_strlen.c
int			ft_strlen(char *s);

// ft_strcpy.c
char		*ft_strcpy(char *dest, char *src);

// ft_strcmp.c
int			ft_strcmp(char *s1, char *s2);

// ft_strcmp_len.c
int			ft_strcmp_len(char *s1, char *s2);

// ft_advanced_sort_string_tab.c
// void		ft_swap(t_dict_elem *a, t_dict_elem *b);
void		ft_sort_dict_tab(t_dict_elem *dict, int (*cmp)(char *, char *));

// ft_substr.c
char		*ft_substr(char *str, int start, int len);

// ft_free.c
void		free_2d(void **arr, int i);
void		free_2d_all(void **arr);
void		free_3d(void ***arr, int i, int j);
void		free_dict_arr(t_dict_elem *dict, int i);
void		free_dict_arr_all(t_dict_elem *dict);

// ft_dict.c
t_bool		check_dict_format(char **lines);
t_bool		ft_is_duplication(t_dict_elem *dict);
t_dict_elem	*ft_comvert_to_dict(char **lines, int line_nums);
void		ft_sort_dict(t_dict_elem *dict);

// ft_valid_type.c
t_bool		is_integer(char *str);

// ft_strwith.c
t_bool		ft_startwith_int(char *str);
t_bool		ft_endwith_pa(char *str);

// ft_putstr.c
void		ft_putstr(char *str);

// ft_search.c
void		ft_result(char *words, t_dict_elem *dict);
int			ft_search(char *words, char **result, t_dict_elem *dict);
int			ft_place_search(int place, char *words, char **result,
				t_dict_elem *dict);

// ft_arg_split.c
// void	ft_arg_cpy(char **a, int sepa, int digit, char *c);
// void	ft_sepalate(char **a, int sepa);
char		**ft_arg_strlen(char *c);

// ft_searchX.c
void	print_result(char ***result, int b, int *count);
int	process_word(int i, char *word, char ***result, t_dict_elem *dict);
char	***allocate_result(char **a);
void	ft_result(char *words, t_dict_elem *dict);
int	ft_search(char *words, char **result, t_dict_elem *dict);
int	handle_zero_case(char *words, char **result);
void	search_single_digit(char *words, char **result, t_dict_elem *dict);
void	search_hundreds_place(char *words, char **result, t_dict_elem *dict);
void	handle_teens_case(char *words, char **result, t_dict_elem *dict,
		char *tensplace);
void	print_inner_result(char ***result, int b, int *count);
void	print_separated_result(char ***result, int b);
void	print_zero(t_dict_elem *dict);
void	search_tens_and_units_place(char *words, char **result,
		t_dict_elem *dict, char *tensplace);
void	handle_tens_and_units(char *words, char **result, t_dict_elem *dict,
		char *tensplace);
char	*create_search_string(int place);
int	process_dict(char **result, t_dict_elem *dict, char *searchs);
int	ft_place_search(int place, char *words, char **result, t_dict_elem *dict);

#endif