/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid_moves_ext.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:38:02 by emaune            #+#    #+#             */
/*   Updated: 2018/06/19 10:08:23 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int       		   piece_rows_readjustment(t_main *var)
{
	int             y;

	y = 0;
	while (y < var->piece_dimensions.rows)
	{
		if (ft_strchr(var->piece[y], '*'))
			break   ;
		y++;
	}
	return (y);
}

int				piece_columns_readjustment(t_main *var)
{
	int			y;
	int			x;

	x = 0;
	while (x < var->piece_dimensions.columns)
	{
		y = 0;
		while (y < var->piece_dimensions.rows)
		{
			if (var->piece[y][x] == '*')
				return (x);
			y++;
		}
		x++;
	}
	return (x);
}
