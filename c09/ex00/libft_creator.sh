# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 22:46:56 by jeounpar          #+#    #+#              #
#    Updated: 2021/10/24 00:54:52 by jeounpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

gcc -c -Wall -Wextra -Werror ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
ranlib libft.a
rm ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
