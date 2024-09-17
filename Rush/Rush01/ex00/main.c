/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidler <jidler@student.42tokyo.jp >        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-15 13:46:00 by jidler            #+#    #+#             */
/*   Updated: 2024-09-15 13:46:00 by jidler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	solve_puzzle(int input[4][4]);

void	print_field(int arr[4][4])
{
	int		counter_x;
	int		counter_y;
	char	temp;

	counter_x = 0;
	while (counter_x < 4)
	{
		counter_y = 0;
		while (counter_y < 4)
		{
			temp = arr[counter_x][counter_y] + '0';
			write(1, &temp, 1);
			if (counter_y < 3)
			{
				write(1, " ", 1);
			}
			counter_y++;
		}
		write(1, "\n", 1);
		counter_x++;
	}
}

void	convert_input(int input[4][4], char *string)
{
	int	counter_string;
	int	counter_x;
	int	counter_y;

	counter_string = 0;
	counter_x = 0;
	while (counter_x < 4)
	{
		counter_y = 0;
		while (counter_y < 4)
		{
			input[counter_x][counter_y] = string[counter_string * 2] - '0';
			counter_string++;
			counter_y++;
		}
		counter_x++;
	}
}

int	check_input_error(char *string)
{
	int	counter;

	counter = 0;
	while (string[counter] != '\0')
	{
		if (!((string[counter] >= '1' && string[counter] <= '4')
				|| string[counter] == ' '))
		{
			return (1);
		}
		counter++;
	}
	if (counter != 31)
	{
		return (1);
	}
	return (0);
}

int	check_conversion_error(int input[4][4])
{
	if (input[3][3] == -1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	main(int argc, char **argv)
{
	int	input[4][4];

	if (argc == 2)
	{
		if (check_input_error(argv[1]) == 1)
		{
			write(1, "Error", 5);
			return (1);
		}
		input[3][3] = -1;
		convert_input(input, argv[1]);
		if (check_conversion_error(input) == 1)
		{
			write(1, "Error", 5);
			return (1);
		}
		solve_puzzle(input);
	}
}
