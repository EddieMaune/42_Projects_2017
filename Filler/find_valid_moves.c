/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:37:35 by emaune            #+#    #+#             */
/*   Updated: 2018/06/15 12:33:18 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			is_token(char cell, t_main *var)
{
	if (cell == var->token || cell == ft_tolower(var->token))
		return (1);
	return (0);
}
static int			is_opponents_token(char cell, t_main *var)
{
	if (!is_token(cell, var) && cell != '.')
		return (1);
	return (0);
}

static int			piece_rows_readjustment(t_main *var)
{
	int				i;

	i = 0;
	while (i < var->piece_dimensions.rows)
	{
		if (ft_strchr(var->piece[i], '*'))
				break	;
		i++;
	}
	return (i);
}

static int			is_valid(int y, int x, t_main *var)
{
	int				covered_cells;
	int				xb;
	int				yb;
	int				xp;
	int				yp;

	yb = y;
	yp = 0;
	if (yb < 0)
	{
		yp = yp + yb * (-1);
		yb = 0;
	}
	covered_cells = 0;
	while (yp < var->piece_dimensions.rows)
	{
		xb = x;
		xp = 0;
		while (xp < var->piece_dimensions.columns)
		{
			if (is_token(var->board[yb][xb], var) && var->piece[yp][xp] == '*')
			   	covered_cells++;
			if (is_opponents_token(var->board[yb][xb], var) && var->piece[yp][xp] == '*')
				return (0);
			xb++;
			xp++;
		}
		yb++;
		yp++;
	}
	if (covered_cells == 1)
		return (1);
	return (0);
}

int			find_valid_moves(t_main *var)
{
	int		y;
	int		x;
	int		moves;

	y = 0;
	moves = 0;
	y -= piece_rows_readjustment(var);
	while (y < var->board_dimensions.rows - var->piece_dimensions.rows + 1)
	{
		x = 0;
		while (x < var->board_dimensions.columns - var->piece_dimensions.columns + 1)
		{
			if (is_valid(y, x, var))
			{
				if (!var->possible_moves)
				{
					var->possible_moves = (t_coordinates*)malloc(sizeof(t_coordinates));
					var->index = var->possible_moves;
					var->possible_moves->prev = NULL;
					var->possible_moves->next = NULL;
					var->possible_moves->x = x;
					var->possible_moves->y = y;
				}
				else
				{
					var->index->next = (t_coordinates*)malloc(sizeof(t_coordinates));
					var->temp = var->index;
					var->index = var->index->next;
					var->index->prev = var->temp;
					var->index->x = x;
					var->index->y = y;
					var->index->next = NULL;
				}
				var->placement.x = x;
				var->placement.y = y;
				moves++;
			}
			x++;
		}
		y++;
	}
	var->index = var->possible_moves;
	return (moves);
}
