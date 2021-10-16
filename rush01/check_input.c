/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 23:29:07 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 01:19:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	check_input(char *str, int max_num)
{
	int		i;
	char	max_num_c;

	i = 0;
	max_num_c = max_num + '0';
	while (str[i] != '\0')
		i++;
	if (i > (max_num * max_num * 2 - 1)
		|| i < (max_num * max_num * 2 - 1))
		return (false);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			;
		else if (str[i] < '0' || str[i] > '9' || str[i] > max_num_c)
			return (false);
		i++;
	}
	return (true);
}
