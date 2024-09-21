/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:57:44 by kishino           #+#    #+#             */
/*   Updated: 2024/09/14 20:46:21 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int s)
{
	int	index;
	int	c;

	index = 0;
	while (index < (s / 2))
	{
		c = tab[index];
		tab[index] = tab[s - 1 - index];
		tab[s - 1 - index] = c;
		index++;
	}
}
