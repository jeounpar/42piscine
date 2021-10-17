/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:27:22 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/17 22:27:30 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_wspc(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	chk_other(char *str, int cnt)
{
	int	i;
	int	mx;

	mx = cnt / 4;
	i = 0;
	if (mx * 4 != cnt)
		return (1);
	while (str[i] != '\0')
	{
		if (is_wspc(str[i]))
			;
		else if (str[i] < '1' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_input(char *str, int *mx)
{
	int	i;
	int	cnt;
	int	flag;

	i = 0;
	cnt = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (is_wspc(str[i]))
			flag = 1;
		if ((flag > 0) && (str[i] >= '1' && str[i] <= '9'))
		{
			cnt++;
			flag = 0;
		}
		i++;
	}
	if (cnt == 0 || cnt % 4 != 0)
		return (0);
	if (chk_other(str, cnt))
		return (0);
	*mx = cnt / 4;
	return (1);
}
