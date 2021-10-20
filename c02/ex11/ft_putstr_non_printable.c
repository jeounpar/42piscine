/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_non_printable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:48:16 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/14 15:53:50 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_base_16[16] = "0123456789abcdef";

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	cur_str;

	i = 0;
	while (1)
	{
		cur_str = str[i];
		if (cur_str == '\0')
			break ;
		if (cur_str >= 32 && cur_str <= 126)
			ft_putchar(cur_str);
		else
		{
			ft_putchar('\\');
			ft_putchar(g_base_16[cur_str / 16]);
			ft_putchar(g_base_16[cur_str % 16]);
		}
		i++;
	}
}
