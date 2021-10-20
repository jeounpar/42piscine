/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:08:29 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/14 15:42:07 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_base_16[16] = "0123456789abcdef";

void	print_pre_mr(void)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		write (1, "0", 1);
		i++;
	}
	write (1, "1", 1);
}

void	print_memory_addr(unsigned int mr)
{
	unsigned int	i;
	unsigned int	cnt;
	char			mr_arr[8];

	cnt = 0;
	print_pre_mr();
	while (mr > 0)
	{
		mr_arr[8 - 1 - cnt] = g_base_16[mr % 16];
		mr = mr / 16;
		cnt++;
	}
	i = 0;
	while (i < 8 - cnt)
	{
		mr_arr[i] = '0';
		i++;
	}
	i = 0;
	while (i < 8)
	{
		write (1, &mr_arr[i], 1);
		i++;
	}
	write (1, ": ", 2);
}

void	ft_print_16base(char c)
{
	int	mod;

	mod = c - 0;
	write (1, &g_base_16[mod / 16], 1);
	write (1, &g_base_16[mod % 16], 1);
}

void	print_str_16(char *str, unsigned int idx, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	j = idx + 1;
	if (j > size)
	{
		while (j < (size / 16 + 1) * 16)
		{
			write (1, " ", 1);
			j++;
		}
	}
	write (1, " ", 1);
	if (idx < 0)
		i = 0;
	else
		i = idx - idx % 16;
	while (i <= idx)
	{
		write (1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

void	ft_print_memory(void *addr, unsigned int size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)addr;
	while (i <= size)
	{
		if (i % 16 == 0)
			print_memory_addr((unsigned int)&str[i]);
		if ((i + 1) % 2 == 1)
			write (1, " ", 1);
		if (str[i] < 32 || str[i] > 126)
		{
			ft_print_16base(str[i]);
			str[i] = '.';
		}
		else
			ft_print_16base(str[i]);
		if (i % 16 == 15 || i == size)
			print_str_16(str, i, size);
		i++;
	}
}
