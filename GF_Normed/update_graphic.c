/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_graphic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 14:21:32 by emaune            #+#    #+#             */
/*   Updated: 2018/07/17 10:57:00 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				add_colors(SDL_Renderer *ren, t_main *var,
		t_coordinates *p1, t_coordinates *p2)
{
	while (p1->x < var->board_dimensions.columns)
	{
		if (var->board[p1->y][p1->x] == 'O' || var->board[p1->y][p1->x] == 'o')
		{
			SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
			fill_rect(ren, *p2, 700 / var->board_dimensions.columns, 900 /
					var->board_dimensions.rows);
		}
		if (var->board[p1->y][p1->x] == 'X' || var->board[p1->y][p1->x] == 'x')
		{
			SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
			fill_rect(ren, *p2, 700 / var->board_dimensions.columns,
					900 / var->board_dimensions.rows);
		}
		p1->x++;
		p2->x += 700 / var->board_dimensions.columns;
	}
}

void				update_graphic(SDL_Renderer *ren, t_main *var)
{
	t_coordinates	p1;
	t_coordinates	p2;

	p1.y = 0;
	p2.y = 0;
	while (p1.y < var->board_dimensions.rows)
	{
		p1.x = 0;
		p2.x = 0;
		add_colors(ren, var, &p1, &p2);
		p1.y++;
		p2.y += 900 / var->board_dimensions.rows;
	}
}
