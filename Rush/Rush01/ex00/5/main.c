/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidler <jidler@student.42tokyo.jp >        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-15 13:46:32 by jidler            #+#    #+#             */
/*   Updated: 2024-09-15 13:46:32 by jidler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define S 5

void	solve_puzzle(int arr[4][S]);

void	initialize(char *str, int *attr, int arr[4][S])
{
	if (attr[1] == S)
	{
		attr[1] = 0;
		attr[2] += 1;
	}
	arr[attr[2]][attr[1]] = str[attr[0]] - '0';
	attr[1]++;
	attr[0]++;
}

int	input_to_arr(char *str, int *attr, int arr[4][S])
{
	while (str[attr[0]] != '\0')
	{
		if (str[attr[0]] >= '1' && str[attr[0]] <= '0' + S)
			initialize(str, attr, arr);
		else if (str[attr[0]] == ' ')
			++attr[0];
		else
		{
			write(1, "Error\n", 6);
			return (1);
		}
	}
	if (attr[0] != S * 4 * 2 - 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	arr[4][S];
	int	attr[3];

	if (argc == 2)
	{
		i = -1;
		while (i++ < 3)
			attr[i] = 0;
		arr[3][S - 1] = -1;
		if (input_to_arr(argv[1], attr, arr) == 1)
			return (0);
		if (arr[3][S - 1] == -1)
			write(1, "Error\n", 6);
		if (arr[3][S - 1] == -1)
			return (0);
		solve_puzzle(arr);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
