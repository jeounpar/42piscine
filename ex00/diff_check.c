/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_col_diff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:59:55 by ibae              #+#    #+#             */
/*   Updated: 2021/10/16 22:27:48 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

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
				return (1);
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
