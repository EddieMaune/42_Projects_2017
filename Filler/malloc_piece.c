/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 09:37:17 by emaune            #+#    #+#             */
/*   Updated: 2018/06/13 11:11:32 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		**malloc_piece(t_main *var)
{
	char	**index;
	int		i;

	var->piece = (char**)malloc(sizeof(char*) * var->piece_dimensions.rows + 1);
	var->piece[var->piece_dimensions.rows] = NULL;
	index = var->piece;
	i = 0;
	while (i < var->piece_dimensions.rows)
	{
		index[i] = (char*)malloc(sizeof(char) * var->piece_dimensions.columns
				+ 1);
		index[i][var->piece_dimensions.columns] = '\0';
		i++;
	}
	return (var->piece);
}
