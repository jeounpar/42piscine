/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:27:41 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/17 22:27:44 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

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

void	print_error(int pos)
{
	if (pos == 0)
		write (1, "Error\n", 6);
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
	print_error(pos);
	arr[x][y] = 0;
	return (0);
}
