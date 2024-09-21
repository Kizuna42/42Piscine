/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:44:11 by kishino           #+#    #+#             */
/*   Updated: 2024/09/18 17:44:39 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	is_delimiter(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(const char *str, char *charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_delimiter(str[i], charset)
			&& (is_delimiter(str[i + 1], charset) || str[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	write_word(char *dest, const char *from, char *charset)
{
	int	i;

	i = 0;
	while (from[i] != '\0' && !is_delimiter(from[i], charset))
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	write_split(char **split, const char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_delimiter(str[i], charset))
			i++;
		else
		{
			j = 0;
			while (str[i + j] != '\0' && !is_delimiter(str[i + j], charset))
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!split[word])
				return (-1);
			write_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
	split[word] = NULL;
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		words;

	if (!str || !charset)
		return (NULL);
	words = count_words(str, charset);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	if (write_split(split, str, charset) == -1)
		return (NULL);
	return (split);
}
