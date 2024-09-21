/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:57:47 by kishino           #+#    #+#             */
/*   Updated: 2024/09/14 20:46:21 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int s)
{
	int	index;
	int	n;
	int	c;

	index = 0;
	c = 0;
	while (index < s)
	{
		n = index + 1;
		while (n < s)
		{
			if (tab[index] > tab[n])
			{
				c = tab[n];
				tab[n] = tab[index];
				tab[index] = c;
			}
			n++;
		}
		index++;
	}
}
