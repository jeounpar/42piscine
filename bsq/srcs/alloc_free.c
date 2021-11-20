/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:57:47 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/28 00:49:52 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	alloc_free(t_map **maps, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < maps[i]->info.line)
		{
			free(maps[i]->map[j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < argc)
	{
		free(maps[i]);
		i++;
	}
}

void	int_malloc_free(int **arr, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
