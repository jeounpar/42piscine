/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_view_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:11:40 by ibae              #+#    #+#             */
/*   Updated: 2021/10/16 14:59:45 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_view_up_check(int arr[6][6], int pos)
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
		if (pos % 4 == (col - 1) && pos / 4 == 3 && count != arr[0][col])
			return (0);
		col++;
	}
	return (1);
}

int	ft_view_down_check(int arr[6][6], int pos)
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
		if (pos % 4 == (col - 1) && pos / 4 == 3 && count != arr[5][col])
			return (0);
		col++;
	}
	return (1);
}

int	ft_view_left_check(int arr[6][6], int pos)
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
		if (pos / 4 == (row - 1) && pos % 4 == 3 && count != arr[row][0])
			return (0);
		row++;
	}
	return (1);
}

int	ft_view_right_check(int arr[6][6], int pos)
{
	int	max;
	int	count;
	int	col;
	int	row;

	row = 1;
	while (row < 5)
	{
		col = 4;
		count = 0;
		max = 0;
		while (col > 0)
		{
			if (arr[row][col] > max)
			{
				max = arr[row][col];
				count++;
			}
			col--;
		}
		if (pos / 4 == (row - 1) && pos % 4 == 3 && count != arr[row][5])
			return (0);
		row++;
	}
	return (1);
}
