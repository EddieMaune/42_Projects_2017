/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_detection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:09:35 by emaune            #+#    #+#             */
/*   Updated: 2018/06/27 09:14:10 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			enemy_detection(t_main *var, t_coordinates	*vector)
{
	int		radius;
	int		x;
	int		y;
	int		flag;

	radius = 1;
	while ((vector->x + radius < var->board_dimensions.columns || vector->y + radius < var->board_dimensions.rows) || (vector->x - radius > 0 || vector->y - radius > 0))
	{
		flag = 0;
		y = vector->y - radius;
		if (y < 0)
			y = 0;
		while (y <= vector->y + radius && y < var->board_dimensions.rows)
		{
			x = vector->x - radius;
			if (x < 0)
				x = 0;
			while (x <= vector->x + radius && x < var->board_dimensions.columns)
			{
				if (var->board[y][x] != '.' && var->board[y][x] != var->token)
					return (radius);
				x++;
			}
			y++;
		}
		radius++;
	}
	return (radius);
}
