/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:18:34 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/19 00:14:39 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	invalid_char(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == '+' || c == '-')
		return (1);
	return (0);
}

int	valid_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[i] == '\0' || ft_strlen(str) < 2)
		return (0);
	while (str[i] != '\0')
	{
		if (invalid_char(str[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < ft_strlen(str))
	{
		j = i + 1;
		while (j < ft_strlen(str))
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_recur(int n, int len, char *base)
{
	if (n == -2147483648)
	{
		ft_putnbr_recur(n / len, len, base);
		write (1, &base[(n % len) * -1], 1);
		return ;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		ft_putnbr_recur(n * -1, len, base);
		return ;
	}
	if (n > len - 1)
		ft_putnbr_recur(n / len, len, base);
	write (1, &base[n % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = ft_strlen(base);
	if (!valid_base(base))
		return ;
	ft_putnbr_recur(nbr, len, base);
}
