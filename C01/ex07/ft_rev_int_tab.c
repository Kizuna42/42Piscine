/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:57:44 by kishino           #+#    #+#             */
/*   Updated: 2024/09/06 21:53:01 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	c;

	index = 0;
	while (index < (size / 2))
	{
		c = tab[index];
		tab[index] = tab[size - 1 - index];
		tab[size - 1 - index] = c;
		index++;
	}
}
