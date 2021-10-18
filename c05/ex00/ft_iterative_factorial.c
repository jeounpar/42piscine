/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:23:55 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/19 00:25:27 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;

	n = 1;
	if (nb < 0)
		return (0);
	else if (nb <= 1)
		return (1);
	else
	{
		while (nb > 0)
		{
			n *= nb;
			nb--;
		}
	}
	return (n);
}
