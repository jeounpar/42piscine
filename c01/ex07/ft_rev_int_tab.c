/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:52:09 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/10 19:10:41 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	idx;
	int	tmp;

	idx = 0;
	while (idx <= (size - 1) / 2)
	{
		tmp = tab[idx];
		tab[idx] = tab[size - 1 - idx];
		tab[size - 1 - idx] = tmp;
		idx++;
	}
}
