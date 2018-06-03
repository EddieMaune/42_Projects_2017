/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_rooms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:50:54 by emaune            #+#    #+#             */
/*   Updated: 2017/11/30 16:35:47 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		error_check_room(t_main *var)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (var->r_index)
	{
		if (var->r_index->is_start)
			start = 1;
		if (var->r_index->is_end)
			end = 1;
		var->r_index = var->r_index->next;
	}
	if (start && end)
		return (1);
	ft_putstr("\x1b[31mError: start/end room is missing");
	free_input(&var->input_head);
	free_rooms(var);
	exit(EXIT_FAILURE);
}
