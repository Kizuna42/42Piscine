/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidler <jidler@student.42tokyo.jp >        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-15 13:46:08 by jidler            #+#    #+#             */
/*   Updated: 2024-09-15 13:46:08 by jidler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	solve_puzzle(int arr[4][4]);
void	print_field(int field[4][4]);
void	check_four_and_one(int arr[4][4], int grid[4][4]);
int		solve_recursion(int grid[4][4], int arr[4][4], int r, int c);
int		row_left_right(int check, int *attr, int grid[4][4], int arr[4][4]);
int		col_up_down(int check, int *attr, int grid[4][4], int arr[4][4]);
int		right_left(int check, int *attr, int grid[4][4], int arr[4][4]);
int		down_up(int check, int *attr, int grid[4][4], int arr[4][4]);

int	check_validity(int grid[4][4], int arr[4][4], int *attr)
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

int	condition(int arr[4][4], int r, int c)
{
	if ((r == 0) && (arr[0][c] == 2 || arr[0][c] == 3))
		return (1);
	if ((r == 3) && (arr[1][c] == 2 || arr[1][c] == 3))
		return (1);
	if ((c == 0) && (arr[2][r] == 2 || arr[2][r] == 3))
		return (1);
	if ((c == 3) && (arr[3][r] == 2 || arr[3][r] == 3))
		return (1);
	return (0);
}

int	backtracking_condition_loop(int *i, int *attr, int arr[4][4],
		int grid[4][4])
{
	int	r;
	int	c;

	r = attr[0];
	c = attr[1];
	while (++*i < 5)
	{
		if (*i == 4 && (attr[0] == 0 || attr[1] == 0 || attr[0] == 3
				|| attr[1] == 3))
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

int	solve_recursion(int grid[4][4], int arr[4][4], int r, int c)
{
	int	i;
	int	attr[3];

	i = 0;
	attr[0] = r;
	attr[1] = c;
	if (r == 4)
		return (0);
	else if (c == 4)
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

void	solve_puzzle(int arr[4][4])
{
	int	grid[4][4];
	int	i;
	int	j;
	int	ans;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			grid[i][j] = -1;
	}
	check_four_and_one(arr, grid);
	ans = solve_recursion(grid, arr, 0, 0);
	if (ans == 0)
		print_field(grid);
	else
		write(1, "Error", 5);
}
