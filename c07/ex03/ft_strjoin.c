/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:09:25 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/20 17:09:26 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_all_len(char **strs, int sep_size, int size)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = 0;
	while (i < size)
	{
		tmp = strs[i];
		len += ft_strlen(tmp);
		i++;
	}
	return (len + sep_size * (size - 1) + 1);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_join(int size, char **strs, char *sep, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(len * sizeof(char));
	if (size <= 0)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	str[0] = '\0';
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		sep_size;
	int		all_len;
	char	*str;

	if (size <= 0)
    {
        str = (char *)malloc(sizeof(char));
        if (str == NULL)
            return (0);
        str[0] = '\0';
		return (str);
    }
	sep_size = ft_strlen(sep);
	all_len = ft_all_len(strs, sep_size, size);
	str = ft_join(size, strs, sep, all_len);
	return (str);
}
