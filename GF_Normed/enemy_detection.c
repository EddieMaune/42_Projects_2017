/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_detection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:09:35 by emaune            #+#    #+#             */
/*   Updated: 2018/07/17 10:09:16 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			radar(t_main *var, t_coordinates *vector, t_ed *v)
{
	while ((vector->x + v->radius < var->board_dimensions.columns ||
				vector->y + v->radius < var->board_dimensions.rows) ||
			(vector->x - v->radius > 0 || vector->y - v->radius > 0))
	{
		v->y = vector->y - v->radius;
		if (v->y < 0)
			v->y = 0;
		while (v->y <= vector->y + v->radius && v->y <
				var->board_dimensions.rows)
		{
			v->x = vector->x - v->radius;
			if (v->x < 0)
				v->x = 0;
			while (v->x <= vector->x + v->radius && v->x <
					var->board_dimensions.columns)
				if (var->board[v->y][v->x] != '.' && var->board[v->y][v->x]
						!= var->token)
					return (v->radius);
				else
					v->x++;
			v->y++;
		}
		v->radius++;
	}
	return (v->radius);
}

int			enemy_detection(t_main *var, t_coordinates *vector)
{
	t_ed	v;

	v.radius = 1;
	return (radar(var, vector, &v));
}
