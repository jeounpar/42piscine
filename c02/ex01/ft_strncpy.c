/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:56:05 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/10 20:08:40 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	cur_idx;

	cur_idx = 0;
	if (n != 0)
	{
		while ((cur_idx < n) && (src[cur_idx] != '\0'))
		{
			dest[cur_idx] = src[cur_idx];
			cur_idx++;
		}
		while (cur_idx < n)
		{
			dest[cur_idx] = '\0';
			cur_idx++;
		}
	}
	return (dest);
}
