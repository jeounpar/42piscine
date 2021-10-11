/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:39:46 by marvin            #+#    #+#             */
/*   Updated: 2021/10/11 17:13:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	use_upper;
	int	a_to_z;
	int	aa_to_zz;

	i = 0;
	use_upper = 1;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			use_upper = 1;
		if (str[i] >= 'a' && str[i] <= 'z')
			a_to_z = 1;
		if (str[i] >= 'A' && str[i] <= 'Z')
			aa_to_zz = 1;
		if (use_upper > 0 && a_to_z > 0)
		{
			use_upper = -1;
			str[i] = str[i] - ('a' - 'A');
		}
		if (use_upper < 0 && (a_to_z > 0 || aa_to_zz > 0))
			str[i] = str[i] + ('a' - 'A');
		i++;
	}
	return (str);
}
