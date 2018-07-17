/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:30:32 by emaune            #+#    #+#             */
/*   Updated: 2018/07/17 10:32:23 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		**malloc_board(t_main *var)
{
	int		i;

	var->board = (char**)malloc(sizeof(char*) * var->board_dimensions.rows + 1);
	var->board[var->board_dimensions.rows] = NULL;
	i = 0;
	while (i < var->board_dimensions.rows)
	{
		var->board[i] = (char*)malloc(sizeof(char) *
				var->board_dimensions.columns + 1);
		var->board[i][var->board_dimensions.columns] = '\0';
		i++;
	}
	return (var->board);
}
