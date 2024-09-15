/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishino <kishino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:43:05 by yossasak          #+#    #+#             */
/*   Updated: 2024/09/15 14:20:20 by kishino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define S 5

void	solve(int arr[4][S]);
void	print_criteria(int arr[S][S]);
void	init_grid(int arr[4][S], int grid[S][S]);
int		recursion(int grid[S][S], int arr[4][S], int r, int c);
int		row_leftright(int check, int *attr, int grid[S][S], int arr[4][S]);
int		col_updown(int check, int *attr, int grid[S][S], int arr[4][S]);
int		rightleft(int check, int *attr, int grid[S][S], int arr[4][S]);
int		downup(int check, int *attr, int grid[S][S], int arr[4][S]);

int	is_valid(int grid[S][S], int arr[4][S], int *attr)
{
	grid[attr[0]][attr[1]] = attr[2];
	if (row_leftright(0, attr, grid, arr) == 1)
		return (1);
	if (col_updown(0, attr, grid, arr) == 1)
		return (1);
	if (rightleft(0, attr, grid, arr) == 1)
		return (1);
	if (downup(0, attr, grid, arr) == 1)
		return (1);
	return (0);
}

int	condition(int arr[4][S], int r, int c)
{
	if ((r == 0) && (arr[0][c] == 2 || arr[0][c] == 3 || arr[0][c] == 4))
		return (1);
	if ((r == S - 1) && (arr[1][c] == 2 || arr[1][c] == 3 || arr[1][c] == 4))
		return (1);
	if ((c == 0) && (arr[2][r] == 2 || arr[2][r] == 3 || arr[2][r] == 4))
		return (1);
	if ((c == S - 1) && (arr[3][r] == 2 || arr[3][r] == 3 || arr[3][r] == 4))
		return (1);
	return (0);
}

int	condition_loop(int *i, int *attr, int arr[4][S], int grid[S][S])
{
	int	r;
	int	c;

	r = attr[0];
	c = attr[1];
	while (++*i < S + 1)
	{
		if (*i == S && (attr[0] == 0 || attr[1] == 0 || attr[0] == S - 1
				|| attr[1] == S - 1))
		{
			if (condition(arr, r, c) == 1)
				continue ;
		}
		attr[2] = *i;
		if (is_valid(grid, arr, attr) == 0)
		{
			if (recursion(grid, arr, r, c + 1) == 0)
				return (0);
			grid[r][c] = -1;
		}
		else
			grid[r][c] = -1;
	}
	return (1);
}

int	recursion(int grid[S][S], int arr[4][S], int r, int c)
{
	int	i;
	int	attr[3];

	i = 0;
	attr[0] = r;
	attr[1] = c;
	if (r == S)
		return (0);
	else if (c == S)
		return (recursion(grid, arr, r + 1, 0));
	else if (grid[r][c] != -1)
		return (recursion(grid, arr, r, c + 1));
	else
	{
		if (condition_loop(&i, attr, arr, grid) == 0)
			return (0);
		else
			return (1);
	}
}

void	solve(int arr[4][S])
{
	int	grid[S][S];
	int	i;
	int	j;
	int	ans;

	i = -1;
	while (++i < S)
	{
		j = -1;
		while (++j < S)
			grid[i][j] = -1;
	}
	init_grid(arr, grid);
	ans = recursion(grid, arr, 0, 0);
	if (ans == 0)
		print_criteria(grid);
	else
		write(1, "Error\n", 6);
}
