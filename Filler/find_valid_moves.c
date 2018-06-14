/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:37:35 by emaune            #+#    #+#             */
/*   Updated: 2018/06/13 16:42:26 by emaune           ###   ########.fr       */
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

static int			is_valid(int y, int x, t_main *var)
{
	int				covered_cells;
	int				xb;
	int				yb;
	int				xp;
	int				yp;

	yb = y;
	yp = 0;
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

void		find_valid_moves(t_main *var)
{
	int		y;
	int		x;

	y = 0;
	while (y < var->board_dimensions.rows - var->piece_dimensions.rows + 1)
	{
		x = 0;
		while (x < var->board_dimensions.columns - var->piece_dimensions.columns + 1)
		{
			if (is_valid(y, x, var))
			{
				var->placement.x = x;
				var->placement.y = y;
			}
			x++;
		}
		y++;
	}		
}
