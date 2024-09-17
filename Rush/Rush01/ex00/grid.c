/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidler <jidler@student.42tokyo.jp >        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-15 13:45:56 by jidler            #+#    #+#             */
/*   Updated: 2024-09-15 13:45:56 by jidler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_field(int arr[4][4]);

void	handle_four(int grid[4][4], int constant,
						int roworcolumn, int inc_or_dec)
{
	int	z;

	if (inc_or_dec == 0)
	{
		z = -1;
		while (++z < 4)
		{
			if (roworcolumn == 0)
				grid[constant][z] = z + 1;
			else
				grid[z][constant] = z + 1;
		}
	}
	else
	{
		z = 4;
		while (--z > -1)
		{
			if (roworcolumn == 0)
				grid[constant][z] = 4 - z;
			else
				grid[z][constant] = 4 - z;
		}
	}
}

void	handle_one(int grid[4][4], int i, int j)
{
	if (i == 0)
		grid[0][j] = 4;
	else if (i == 1)
		grid[3][j] = 4;
	else if (i == 2)
		grid[j][0] = 4;
	else
		grid[j][3] = 4;
}

void	helper_function(int grid[4][4], int *i, int *j, int arr[4][4])
{
	int	z;

	z = -1;
	if (arr[*i][*j] == 1)
		handle_one(grid, *i, *j);
	else if (*i == 0)
		handle_four(grid, *j, 1, 0);
	else if (*i == 1)
		handle_four(grid, *j, 1, 1);
	else if (*i == 2)
		handle_four(grid, *j, 0, 0);
	else
		handle_four(grid, *j, 0, 1);
}

void	check_four_and_one(int arr[4][4], int grid[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (arr[i][j] == 4 || arr[i][j] == 1)
			{
				helper_function(grid, &i, &j, arr);
			}
		}
	}
}
