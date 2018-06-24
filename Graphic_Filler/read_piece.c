/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:56:25 by emaune            #+#    #+#             */
/*   Updated: 2018/06/14 10:55:56 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			read_piece(t_main *var)
{
	if (ft_strstr(var->line, "Piece"))
	{
		var->piece_dimensions = get_piece_dimensions(var->line);
		malloc_piece(var);
		free(var->line);
		update_piece(var);
		var->read_piece = 1;
	}
}
