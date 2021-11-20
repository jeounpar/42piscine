/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:58:27 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/25 00:58:28 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		ft_putchar(str[idx]);
		idx++;
	}
}

void	ft_printmap(t_map *arr)
{
	int	i;

	i = 0;
	while (i < arr->info.line)
	{
		ft_putstr(arr->map[i]);
		ft_putchar('\n');
		i++;
	}
}
