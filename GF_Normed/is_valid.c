/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:12:43 by emaune            #+#    #+#             */
/*   Updated: 2018/07/17 09:48:25 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					traverse_board(t_main *var, t_valid *v, int x)
{
	while (v->yp < var->piece_dimensions.rows - var->empty_piece_rows)
	{
		v->xb = x;
		v->xp = 0;
		if (v->xb < 0)
		{
			v->xp = v->xp + v->xb * (-1);
			v->xb = 0;
		}
		while (v->xp < var->piece_dimensions.columns - var->empty_piece_columns)
		{
			if (is_token(var->board[v->yb][v->xb], var) &&
					var->piece[v->yp][v->xp] == '*')
				v->covered_cells++;
			if (is_opponents_token(var->board[v->yb][v->xb], var) &&
					var->piece[v->yp][v->xp] == '*')
				return (0);
			v->xb++;
			v->xp++;
		}
		v->yb++;
		v->yp++;
	}
	return (1);
}

int					is_valid(int y, int x, t_main *var)
{
	t_valid			v;

	v.yb = y;
	v.yp = 0;
	if (v.yb < 0)
	{
		v.yp = v.yp + v.yb * (-1);
		v.yb = 0;
	}
	v.covered_cells = 0;
	if (!traverse_board(var, &v, x))
		return (0);
	if (v.covered_cells == 1)
		return (1);
	return (0);
}
