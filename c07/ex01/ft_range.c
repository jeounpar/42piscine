/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:02:04 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/20 16:02:05 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	size = max - min;
	if (min >= max)
		return (0);
	arr = (int *)malloc(size * sizeof(int));
	if (arr == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
