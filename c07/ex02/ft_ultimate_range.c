/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:31:38 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/20 16:31:39 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*tmp;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = max - min;
	tmp = (int *)malloc(size * sizeof(int));
	if (tmp == NULL)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	while (i < size)
	{
		tmp[i] = min;
		min++;
		i++;
	}
	*range = tmp;
	return (size);
}
