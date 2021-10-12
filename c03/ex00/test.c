/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:44:01 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/12 19:46:09 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		printf("%c %c@@\n", s1[i], s2[i]);
		if (s1[i] > s2[i])
			return (s1[i] - s2[i] + 0);
		if (s2[i] > s1[i])
			return (s2[i] - s1[i] + 0);
		i++;
	}
	return (0);
}

int main(void)
{
	char s1[]="abc";
	char s2[]="abcd";

	char ss1[]="abc";
	char ss2[]="abcd";
	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d\n", strcmp(ss1, ss2));

	return 0;
}
