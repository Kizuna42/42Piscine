/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:41:53 by yossasak          #+#    #+#             */
/*   Updated: 2024/09/15 14:20:04 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define S 5

void	print_criteria(int arr[S][S]);

void	inc_asign(int grid[S][S], int constant, int roworcolumn, int inc_or_dec)
{
	int	z;

	if (inc_or_dec == 0)
	{
		z = -1;
		while (++z < S)
		{
			if (roworcolumn == 0)
				grid[constant][z] = z + 1;
			else
				grid[z][constant] = z + 1;
		}
	}
	else
	{
		z = S;
		while (--z > -1)
		{
			if (roworcolumn == 0)
				grid[constant][z] = S - z;
			else
				grid[z][constant] = S - z;
		}
	}
}

void	asign_one(int grid[S][S], int i, int j)
{
	if (i == 0)
		grid[0][j] = S;
	else if (i == 1)
		grid[S - 1][j] = S;
	else if (i == 2)
		grid[j][0] = S;
	else
		grid[j][S - 1] = S;
}

void	asign(int grid[S][S], int *i, int *j, int arr[4][S])
{
	int	z;

	z = -1;
	if (arr[*i][*j] == 1)
		asign_one(grid, *i, *j);
	else if (*i == 0)
		inc_asign(grid, *j, 1, 0);
	else if (*i == 1)
		inc_asign(grid, *j, 1, 1);
	else if (*i == 2)
		inc_asign(grid, *j, 0, 0);
	else
		inc_asign(grid, *j, 0, 1);
}

void	init_grid(int arr[4][S], int grid[S][S])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < S)
		{
			if (arr[i][j] == S || arr[i][j] == 1)
			{
				asign(grid, &i, &j, arr);
			}
		}
	}
}
