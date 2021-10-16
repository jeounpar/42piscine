/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 01:23:42 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 01:58:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include "check_input.h"
# include "wr_arr.h"
# include <stdlib.h>
# include <unistd.h>

int	get_maxnum(char *str);
int	*get_nums(char *str);
int	**make_arr(int num);

#endif
