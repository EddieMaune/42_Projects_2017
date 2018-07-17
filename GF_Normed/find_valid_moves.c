/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:37:35 by emaune            #+#    #+#             */
/*   Updated: 2018/07/17 09:32:28 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		add_possible_move(t_main *var, int x, int y)
{
	if (!var->possible_moves)
	{
		var->possible_moves =
			(t_coordinates*)malloc(sizeof(t_coordinates));
		var->index = var->possible_moves;
		var->possible_moves->prev = NULL;
		var->possible_moves->next = NULL;
		var->possible_moves->x = x;
		var->possible_moves->y = y;
		var->possible_moves->distance =
			enemy_detection(var, var->possible_moves);
	}
	else
	{
		var->index->next =
			(t_coordinates*)malloc(sizeof(t_coordinates));
		var->temp = var->index;
		var->index = var->index->next;
		var->index->prev = var->temp;
		var->index->x = x;
		var->index->y = y;
		var->index->distance = enemy_detection(var, var->index);
		var->index->next = NULL;
	}
}

void		check_and_add(t_main *var, int *x, int y, int *moves)
{
	if (is_valid(y, *x, var))
	{
		add_possible_move(var, *x, y);
		var->placement.x = *x;
		var->placement.y = y;
		*moves += 1;
	}
	*x += 1;
}

int			find_valid_moves(t_main *var)
{
	int		y;
	int		x;
	int		moves;

	y = 0;
	moves = 0;
	y -= piece_rows_readjustment(var);
	var->empty_piece_columns = piece_columns_readjustment_2(var);
	var->empty_piece_rows = piece_rows_readjustment_2(var);
	while (y < var->board_dimensions.rows - var->piece_dimensions.rows +
			var->empty_piece_rows + 1)
	{
		x = 0;
		x -= piece_columns_readjustment(var);
		while (x < var->board_dimensions.columns -
				var->piece_dimensions.columns + var->empty_piece_columns + 1)
		{
			check_and_add(var, &x, y, &moves);
		}
		y++;
	}
	var->index = var->possible_moves;
	return (moves);
}
