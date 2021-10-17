/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:38:49 by marvin            #+#    #+#             */
/*   Updated: 2021/10/17 10:17:58 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	val_rowright(int **arr, int m, int p)
{
	int	max;
	int	ct;
	int	col;
	int	row;

	row = 1;
	while (row < m + 1)
	{
		col = m;
		ct = 0;
		max = 0;
		while (col > 0)
		{
			if (arr[row][col] > max)
			{
				max = arr[row][col];
				ct++;
			}
			col--;
		}
		if (p / m == (row - 1) && p % m == m - 1 && ct != arr[row][m + 1])
			return (0);
		row++;
	}
	return (1);
}

int	val_rowleft(int **arr, int mx, int pos)
{
	int	max;
	int	count;
	int	col;
	int	row;

	row = 1;
	while (row < (mx + 1))
	{
		col = 1;
		count = 0;
		max = 0;
		while (col < (mx + 1))
		{
			if (arr[row][col] > max)
			{
				max = arr[row][col];
				count++;
			}
			col++;
		}
		if (pos / mx == (row - 1) && pos % mx == mx - 1 && count != arr[row][0])
			return (0);
		row++;
	}
	return (1);
}

int	val_colup(int **arr, int mx, int pos)
{
	int	max;
	int	count;
	int	col;
	int	row;

	col = 1;
	while (col < (mx + 1))
	{
		row = 1;
		count = 0;
		max = 0;
		while (row < (mx + 1))
		{
			if (arr[row][col] > max)
			{
				max = arr[row][col];
				count++;
			}
			row++;
		}
		if (pos % mx == (col - 1) && pos / mx == mx - 1 && count != arr[0][col])
			return (0);
		col++;
	}
	return (1);
}

int	val_coldown(int **arr, int m, int p)
{
	int	max;
	int	ct;
	int	col;
	int	row;

	col = 1;
	while (col < (m + 1))
	{
		row = m;
		ct = 0;
		max = 0;
		while (row > 0)
		{
			if (arr[row][col] > max)
			{
				max = arr[row][col];
				ct++;
			}
			row--;
		}
		if (p % m == (col - 1) && p / m == m - 1 && ct != arr[m + 1][col])
			return (0);
		col++;
	}
	return (1);
}
