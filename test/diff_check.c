/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_col_diff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:59:55 by ibae              #+#    #+#             */
/*   Updated: 2021/10/16 14:34:17 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_row_diff_check(int arr[6][6])
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			if (arr[i][j] == 0)
				return (1);
			k = j + 1;
			while (k < 5)
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

int	ft_col_diff_check(int arr[6][6])
{
	int	i;
	int	j;
	int	k;

	j = 1;
	while (j < 5)
	{
		i = 1;
		while (i < 5)
		{
			if (arr[i][j] == 0)
				return(1);
			k = i + 1;
			while (k < 5)
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
