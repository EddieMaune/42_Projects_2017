/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_play.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:24:18 by emaune            #+#    #+#             */
/*   Updated: 2018/07/17 10:37:13 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <time.h>

void			ft_delay(int number_of_seconds)
{
	int			milli_seconds;
	clock_t		start_time;

	milli_seconds = 1000 * number_of_seconds;
	start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}

void			read_and_play(t_main *var)
{
	while (get_next_line(0, &var->line) > 0)
	{
		read_board(var);
		read_piece(var);
		if (var->read_board && var->read_piece)
		{
			if (find_valid_moves(var) > 1)
				select_best_move(var);
			SDL_SetRenderDrawColor(var->ren, 0, 0, 0, 255);
			SDL_RenderClear(var->ren);
			SDL_SetRenderDrawColor(var->ren, 0, 0, 0, 255);
			draw_grid(var->ren, var->board_dimensions.rows,
					var->board_dimensions.columns);
			update_graphic(var->ren, var);
			SDL_RenderPresent(var->ren);
			place_piece(var);
			var->read_board = 0;
			var->read_piece = 0;
			var->possible_moves = NULL;
		}
	}
}
