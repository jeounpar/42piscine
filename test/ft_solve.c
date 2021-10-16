/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:30:02 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 21:30:14 by marvin           ###   ########.fr       */
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
    if (pos == 0){
        write (1, "Error\n", 6);
    }
	arr[x][y] = 0;
	return (0);
}