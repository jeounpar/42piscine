/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:41:45 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/23 13:41:46 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	open_dict(void)
{
	int		fd;
	int		len;
	char	str[3000];

	fd = open("./numbers.dic", O_RDONLY);
	if (fd == -1)
		return ;
	len = 
}
