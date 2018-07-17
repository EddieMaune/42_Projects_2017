/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:46:51 by emaune            #+#    #+#             */
/*   Updated: 2018/06/14 10:56:18 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			read_board(t_main *var)
{
	if (ft_strstr(var->line, "Plateau"))
		var->board_dimensions = get_board_dimensions(var->line);
	if (!var->board)
		malloc_board(var);
	if (var->line[0] == ' ')
	{
		free(var->line);
		update_board(var);
		var->read_board = 1;
	}
}
