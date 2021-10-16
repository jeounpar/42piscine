/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:38:49 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 21:38:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	val_rowright(int **arr, int mx, int pos)
{
	int	max;
	int	count;
	int	col;
	int row;

	row = 1;
	while (row < mx)
	{
		col = mx;
		count = 0;
		max = 0;
		while (col > 0)
		{
			if (arr[row][col] >  max)
			{
				max = arr[row][col];
				count++;
			}
			col--;
		}
		if (pos / mx == (row - 1) && pos % mx == mx - 1 && count != arr[row][mx + 1])
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
	while (row < 5)
	{
		col = 1;
		count = 0;
		max = 0;
		while (col < 5)
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
	while (col < 5)
	{
		row = 1;
		count = 0;
		max = 0;
		while (row < 5)
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

int	val_coldown(int **arr, int mx, int pos)
{
	int	max;
	int	count;
	int	col;
	int	row;

	col = 1;
	while (col < 5)
	{
		row = 4;
		count = 0;
		max = 0;
		while (row > 0)
		{
			if (arr[row][col] > max)
			{
				max = arr[row][col];
				count++;
			}
			row--;
		}
		if (pos % mx == (col - 1) && pos / mx == mx - 1 && count != arr[mx + 1][col])
			return (0);
		col++;
	}
	return (1);
}