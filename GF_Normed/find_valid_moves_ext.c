/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid_moves_ext.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:38:02 by emaune            #+#    #+#             */
/*   Updated: 2018/07/17 09:05:44 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					piece_rows_readjustment(t_main *var)
{
	int				y;

	y = 0;
	while (y < var->piece_dimensions.rows)
	{
		if (ft_strchr(var->piece[y], '*'))
			break ;
		y++;
	}
	return (y);
}

int					piece_columns_readjustment(t_main *var)
{
	int				y;
	int				x;

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

int					piece_rows_readjustment_2(t_main *var)
{
	int				size;
	int				y;

	size = 0;
	y = var->piece_dimensions.rows - 1;
	while (y >= 0)
	{
		if (ft_strchr(var->piece[y], '*'))
			break ;
		size++;
		y--;
	}
	return (size);
}

int					piece_columns_readjustment_2(t_main *var)
{
	int				x;
	int				y;
	int				size;

	size = 0;
	x = var->piece_dimensions.columns - 1;
	while (x >= 0)
	{
		y = 0;
		while (y < var->piece_dimensions.rows)
		{
			if (var->piece[y][x] == '*')
				return (size);
			y++;
		}
		size++;
		x--;
	}
	return (size);
}
