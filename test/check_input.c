/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 23:29:07 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 13:15:34 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_input(char *str, int max_num)
{
	int		i;
	int		cnt;
	char	max_num_c;

	i = 0;
	cnt = 0;
	max_num_c = max_num + '0';
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '9')
			cnt++;
		i++;
	}
	if (cnt != max_num * max_num)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			;
		else if (str[i] < '1' || str[i] > '9' || str[i] > max_num_c)
			return (0);
		i++;
	}
	return (1);
}