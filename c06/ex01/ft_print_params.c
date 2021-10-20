/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:52:40 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/20 11:52:42 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*str;
	int		i;
	int		idx;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			str = argv[i];
			idx = 0;
			while (str[idx] != '\0')
			{
				write (1, &str[idx], 1);
				idx++;
			}
			write (1, "\n", 1);
			i++;
		}
	}
	return (0);
}
