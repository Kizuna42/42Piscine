/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidler <jidler@student.42tokyo.jp >        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-15 13:46:41 by jidler            #+#    #+#             */
/*   Updated: 2024-09-15 13:46:41 by jidler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define S 5

void	solve_puzzle(int arr[4][S]);
void	print_field(int arr[S][S]);
void	init_grid(int arr[4][S], int grid[S][S]);
int		solve_recursion(int grid[S][S], int arr[4][S], int r, int c);
int		row_left_right(int check, int *attr, int grid[S][S], int arr[4][S]);
int		col_up_down(int check, int *attr, int grid[S][S], int arr[4][S]);
int		right_left(int check, int *attr, int grid[S][S], int arr[4][S]);
int		down_up(int check, int *attr, int grid[S][S], int arr[4][S]);

int	check_validity(int grid[S][S], int arr[4][S], int *attr)
{
	grid[attr[0]][attr[1]] = attr[2];
	if (row_left_right(0, attr, grid, arr) == 1)
		return (1);
	if (col_up_down(0, attr, grid, arr) == 1)
		return (1);
	if (right_left(0, attr, grid, arr) == 1)
		return (1);
	if (down_up(0, attr, grid, arr) == 1)
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

int	backtracking_condition_loop(int *i, int *attr, int arr[4][S],
		int grid[S][S])
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
		if (check_validity(grid, arr, attr) == 0)
		{
			if (solve_recursion(grid, arr, r, c + 1) == 0)
				return (0);
			grid[r][c] = -1;
		}
		else
			grid[r][c] = -1;
	}
	return (1);
}

int	solve_recursion(int grid[S][S], int arr[4][S], int r, int c)
{
	int	i;
	int	attr[3];

	i = 0;
	attr[0] = r;
	attr[1] = c;
	if (r == S)
		return (0);
	else if (c == S)
		return (solve_recursion(grid, arr, r + 1, 0));
	else if (grid[r][c] != -1)
		return (solve_recursion(grid, arr, r, c + 1));
	else
	{
		if (backtracking_condition_loop(&i, attr, arr, grid) == 0)
			return (0);
		else
			return (1);
	}
}

void	solve_puzzle(int arr[4][S])
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
	ans = solve_recursion(grid, arr, 0, 0);
	if (ans == 0)
		print_field(grid);
	else
		write(1, "Error\n", 6);
}
