/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_graphic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 14:21:32 by emaune            #+#    #+#             */
/*   Updated: 2018/06/24 15:41:34 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		update_graphic(SDL_Renderer *ren, t_main *var)
{
	int		x;
	int		y;
	double		x2;
	double		y2;

	y = 0;
	y2 = 0;
	while (y < var->board_dimensions.rows)
	{
		x = 0;
		x2 = 0;
		while (x < var->board_dimensions.columns)
		{
			if (var->board[y][x] == 'O' || var->board[y][x] == 'o')
			{
				SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
				fill_rect(ren, x2, y2, 700/var->board_dimensions.columns, 900/var->board_dimensions.rows);

			}
			if (var->board[y][x] == 'X' || var->board[y][x] == 'x')
			{
				SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
				fill_rect(ren, x2, y2, 700/var->board_dimensions.columns, 900/var->board_dimensions.rows);
			}
			x++;
			x2 += 700/var->board_dimensions.columns;
		}
		y++;
		y2 += 900/var->board_dimensions.rows;
	}
}
