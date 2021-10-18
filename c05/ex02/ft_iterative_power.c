/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:26:39 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/19 00:27:31 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	n;

	n = nb;
	if (nb < 0)
		return (0);
	if (power == 0 || (nb == 0 && power == 0))
		return (1);
	while (power > 1)
	{
		n *= nb;
		power--;
	}
	return (n);
}
