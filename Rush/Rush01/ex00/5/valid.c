/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidler <jidler@student.42tokyo.jp >        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-15 13:46:47 by jidler            #+#    #+#             */
/*   Updated: 2024-09-15 13:46:47 by jidler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define S 5

int	row_left_right(int check, int *attr, int grid[S][S], int arr[4][S])
{
	int	i;
	int	highest;
	int	count;

	i = -1;
	highest = 0;
	count = 0;
	while (++i < S)
	{
		if (attr[2] == grid[attr[0]][i] && i != attr[1])
			return (1);
		if (grid[attr[0]][i] > highest)
		{
			highest = grid[attr[0]][i];
			count++;
		}
		if (grid[attr[0]][i] == -1)
			check = 1;
	}
	if (count > arr[2][attr[0]] && check == 0)
		return (1);
	if (check == 0 && count != arr[2][attr[0]])
		return (1);
	return (0);
}

int	col_up_down(int check, int *attr, int grid[S][S], int arr[4][S])
{
	int	i;
	int	highest;
	int	count;

	count = 0;
	i = -1;
	highest = 0;
	while (++i < S)
	{
		if (attr[2] == grid[i][attr[1]] && i != attr[0])
			return (1);
		if (grid[i][attr[1]] > highest)
		{
			highest = grid[i][attr[1]];
			count++;
		}
		if (grid[i][attr[1]] == -1)
			check = 1;
	}
	if (count > arr[0][attr[1]] && check == 0)
		return (1);
	if (check == 0 && count != arr[0][attr[1]])
		return (1);
	return (0);
}

int	right_left(int check, int *attr, int grid[S][S], int arr[4][S])
{
	int	count;
	int	highest;
	int	i;

	count = 0;
	highest = 0;
	i = S;
	while (--i > -1)
	{
		if (grid[attr[0]][i] > highest)
		{
			highest = grid[attr[0]][i];
			count++;
		}
		if (grid[attr[0]][i] == -1)
			check = 1;
	}
	if (count > arr[3][attr[0]] && check == 0)
		return (1);
	if (check == 0 && count != arr[3][attr[0]])
		return (1);
	return (0);
}

int	down_up(int check, int *attr, int grid[S][S], int arr[4][S])
{
	int	count;
	int	highest;
	int	i;

	count = 0;
	highest = 0;
	i = S;
	while (--i > -1)
	{
		if (grid[i][attr[1]] > highest)
		{
			highest = grid[i][attr[1]];
			count++;
		}
		if (grid[i][attr[1]] == -1)
			check = 1;
	}
	if (count > arr[1][attr[1]] && check == 0)
		return (1);
	if (check == 0 && count != arr[1][attr[1]])
		return (1);
	return (0);
}
