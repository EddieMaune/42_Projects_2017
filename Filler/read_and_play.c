/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_play.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:24:18 by emaune            #+#    #+#             */
/*   Updated: 2018/06/14 11:04:12 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		read_and_play(t_main *var)
{
	while (get_next_line(0, &var->line) > 0)
	{
		read_board(var);
		read_piece(var);
		if (var->read_board && var->read_piece)
		{
			find_valid_moves(var);
			place_piece(var);
			var->read_board = 0;
			var->read_piece = 0;
		}
	//	var->read_board = 0;
	//	var->read_piece = 0;
	}
}