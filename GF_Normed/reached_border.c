/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reached_border.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:42:26 by emaune            #+#    #+#             */
/*   Updated: 2018/07/17 10:33:53 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			reached_border(t_main *var)
{
	int		y;

	y = 0;
	while (y < var->board_dimensions.rows)
	{
		if (var->board[y][0] == var->token)
			return (1);
		y++;
	}
	return (0);
}
