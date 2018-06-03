/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_rooms_loop_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:56:34 by emaune            #+#    #+#             */
/*   Updated: 2017/11/30 19:01:18 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		loop_2(t_main *var, t_rooms *temp, int *room_exists)
{
	var->r_index = var->room_head;
	while (var->r_index)
	{
		if (!ft_strcmp(var->r_index->room_name, var->l_index->room1))
		{
			inner_loop_1(var, temp, room_exists);
			if (!*room_exists)
				print_err(var, 1);
			else
			{
				*room_exists = 0;
				break   ;
			}
		}
		var->r_index = var->r_index->next;
	}
}
