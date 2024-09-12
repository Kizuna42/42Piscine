/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:35:39 by kishino           #+#    #+#             */
/*   Updated: 2024/09/11 19:52:54 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0' && argc)
			ft_putchar(argv[j][i++]);
		ft_putchar('\n');
		j++;
	}
	return (0);
}
