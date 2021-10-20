/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:36:24 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/20 21:36:25 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str);
int	valid_base(char *str, int len);

int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	get_len(int n, char *base)
{
	int	cnt;
	int	len;

	cnt = 0;
	len = ft_strlen(base);
	if (n < 0)
		cnt++;
	while (1)
	{
		cnt++;
		if (n / len == 0)
			break ;
		n /= len;
	}
	return (cnt);
}

void	str_base_to(int n, char *base, int len, char *str)
{
	int	i;
	int	size;
	int	neg;
	int tmp;

	i = 0;
	neg = 1;
	size = get_len(n, base);
	if (n < 0)
	{
		neg = 0;
		str[i] = '-';
		i = 1;
	}
	while (i < size)
	{
		tmp = n % len;
		if (tmp < 0)
			tmp *= -1;
		str[size - i - neg] = base[tmp];
		n = n / len;
		i++;
	}
	str[i] = '\0';
}