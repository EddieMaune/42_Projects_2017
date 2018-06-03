/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:58:05 by emaune            #+#    #+#             */
/*   Updated: 2017/12/01 15:31:42 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		loop_1(t_main *var)
{
	while (var->r_index)
	{
		var->r_index->total_links = 0;
		var->l_index = var->l_head;
		while (var->l_index)
		{
			if (!ft_strcmp(var->l_index->room1, var->r_index->room_name))
				var->r_index->total_links++;
			var->l_index = var->l_index->next;
		}
		var->l_index = var->l_head;
		while (var->l_index)
		{
			if (!ft_strcmp(var->l_index->room2, var->r_index->room_name))
				var->r_index->total_links++;
			var->l_index = var->l_index->next;
		}
		var->r_index->i = 0;
		var->r_index->links = NULL;
		var->r_index = var->r_index->next;
	}
}

void			link_rooms(t_main *var)
{
	int			count_links;
	int			room_exists;
	t_rooms		*temp;

	room_exists = 0;
	loop_1(var);
	var->l_index = var->l_head;
	while (var->l_index)
	{
		loop_2(var, temp, &room_exists);
		loop_3(var, temp, &room_exists);
		var->r_index->links[var->r_index->i] = NULL;
		var->l_index = var->l_index->next;
	}
}
