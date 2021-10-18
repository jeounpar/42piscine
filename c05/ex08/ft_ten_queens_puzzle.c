/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:44:22 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/19 00:44:25 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	solve_10queens(int row);
int	g_arr[10][10] = {0, };
int	g_col[10] = {0, };
int	g_dig[20] = {0, };
int	g_dig2[20] = {0, };

int	check(int row, int col)
{
	if (g_col[col])
		return (0);
	if (g_dig[row + col])
		return (0);
	if (g_dig2[row - col + 10])
		return (0);
	return (1);
}

void	check_all(int row, int col, int *ans)
{
	while (col < 10)
	{
		if (check(row, col))
		{
			g_dig[row + col] = 1;
			g_dig2[row - col + 10] = 1;
			g_col[col] = 1;
			g_arr[row][col] = 1;
			*ans += solve_10queens(row + 1);
			g_dig[row + col] = 0;
			g_dig2[row - col + 10] = 0;
			g_col[col] = 0;
			g_arr[row][col] = 0;
		}
		col++;
	}
}

void	print_arr(void)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (g_arr[j][i] == 1)
			{
				c = j + 48;
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	solve_10queens(int row)
{
	int	ans;

	if (row == 10)
	{
		print_arr();
		return (1);
	}
	ans = 0;
	check_all(row, 0, &ans);
	return (ans);
}

int	ft_ten_queens_puzzle(void)
{
	int	ans;

	ans = solve_10queens(0);
	return (ans);
}
