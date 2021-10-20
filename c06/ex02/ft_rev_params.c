/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:37:35 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/20 12:37:37 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		idx;
	char	*str;

	i = argc - 1;
	while (i > 0)
	{
		idx = 0;
		str = argv[i];
		while (str[idx] != '\0')
		{
			write (1, &str[idx], 1);
			idx++;
		}
		write (1, "\n", 1);
		i--;
	}
	return (0);
}
