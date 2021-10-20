/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 08:58:43 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/18 17:09:49 by jeounpar         ###   ########.fr       */
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

int	valid_base(char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	if (str[i] == '\0' || len < 2)
		return (0);
	while (str[i] != '\0')
	{
		if (invalid_char(str[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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

int	ft_atoi_base(char *str, char *base)
{
	int	num;
	int	len;
	int	neg;
	int	result;

	result = 0;
	neg = 1;
	len = ft_strlen(base);
	if (!valid_base(base, len))
		return (0);
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg *= -1;
	num = is_in_base(*str, base);
	while (num != -1)
	{
		result = result * len + num;
		str++;
		num = is_in_base(*str, base);
	}
	return (result * neg);
}
