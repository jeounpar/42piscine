/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:12:27 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 18:34:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	val_rowright(int **arr, int mx, int pos);
int	val_rowleft(int **arr, int mx, int pos);
int	val_colup(int **arr, int mx, int pos);
int	val_coldown(int **arr, int mx, int pos);
int	val_row(int **arr, int mx);
int	val_col(int **arr, int mx);

int	val_all(int **arr, int mx, int pos)
{
	if (!val_row(arr, mx) || !val_col(arr, mx)
			|| !val_rowright(arr, mx, pos)
			|| !val_rowleft(arr, mx, pos)
			|| !val_coldown(arr, mx, pos)
			|| !val_colup(arr, mx, pos))
			return (0);
	return (1);
}

int	val_row(int **arr, int mx)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < mx + 1)
	{
		j = 1;
		while (j < mx + 1)
		{
			if (arr[i][j] == 0)
				return (1);
			k = j + 1;
			while (k < mx + 1)
			{
				if (arr[i][j] == arr[i][k])
					return (0);
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	val_col(int **arr, int mx)
{
	int	i;
	int	j;
	int	k;

	j = 1;
	while (j < mx + 1)
	{
		i = 1;
		while (i < mx + 1)
		{
			if (arr[i][j] == 0)
				return(1);
			k = i + 1;
			while (k < mx + 1)
			{
				if (arr[i][j] == arr[k][j])
					return (0);
				k++;
			}
			i++;
		}
		j++;
	}
	return (1);
}

void	ft_print_solution(int **arr, int mx)
{
	int	row;
	int	col;
	char c;

	row = 1;
	while (row < mx + 1)
	{
		col = 1;
		while (col < mx + 1)
		{
			c = arr[row][col] + '0';
			write (1, &c, 1);
			if (col != mx)
				write (1, " ", 1);
			col++;
		}
		write (1, "\n", 1);
		row++;
	}
}

int	ft_solve(int **arr, int mx, int pos)
{
	int	i;
	int	x;
	int	y;

	if (pos == mx * mx)
	{
		ft_print_solution(arr, mx);
		return (1);
	}
	i = 1;
	x = (pos / mx) + 1;
	y = (pos % mx) + 1;
	while (i <= mx)
	{
		arr[x][y] = i;
		if (val_all(arr, mx, pos))
		{
			if (ft_solve(arr, mx, pos + 1))
				return (1);
		}
		i++;
	}
	arr[x][y] = 0;
	return (0);
}
