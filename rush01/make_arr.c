/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 00:57:26 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 01:14:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**make_arr(int num)
{
	int	**arr;
	int	i;
	int	j;

	i = 0;
	arr = (int **)malloc((num + 2) * sizeof(int *));
	while (i < num + 2)
	{
		arr[i] = (int *)malloc((num + 2) * sizeof(int));
		i++;
	}
	i = 0;
	while (i < num + 2)
	{
		j = 0;
		while (j < num + 2)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (arr);
}
