/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 09:25:30 by emaune            #+#    #+#             */
/*   Updated: 2017/11/30 16:43:40 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms		*init_room(t_main *var, char **room, int *s, int *e)
{
	t_rooms *temp;

	if (!var->r_index)
	{
		var->r_index = var->room_head;
	}
	room = ft_strsplit(var->index->line, ' ');
	var->r_index->room_name = ft_strdup(room[0]);
	var->r_index->p.x = ft_atoi(room[1]);
	var->r_index->p.y = ft_atoi(room[2]);
	var->r_index->flag = 0;
	if (*s)
	{
		var->r_index->is_start = 1;
		var->r_index->ants = var->total_ants;
		*s = 0;
	}
	if (*e)
	{
		var->r_index->is_end = 1;
		*e = 0;
	}
	var->r_index->next = (t_rooms*)malloc(sizeof(t_rooms));
	temp = var->r_index;
	var->r_index = var->r_index->next;
	var->r_index->prev = temp;
	temp = NULL;
	free_split(room);
	return (var->r_index);
}
