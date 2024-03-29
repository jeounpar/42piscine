/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maxnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 23:08:33 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 13:15:48 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	get_maxnum(char *str)
{
	int	i;
	int	max_num;

	i = 0;
	max_num = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i] - '0' >= max_num)
				max_num = str[i] - '0';
		}
		i++;
	}
	return (max_num);
}
