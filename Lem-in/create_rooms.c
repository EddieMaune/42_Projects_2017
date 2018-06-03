/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 09:45:14 by emaune            #+#    #+#             */
/*   Updated: 2017/11/30 16:44:33 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	t_input			*sort_data(t_main *var, char **room, int *s, int *e)
{
	if (var->index->line_number == 1)
		var->total_ants = ft_atoi(var->index->line);
	if (!ft_strcmp(var->index->line, "##start"))
	{
		*s = 1;
		var->index = var->index->next;
		return (var->index);
	}
	else if (!ft_strcmp(var->index->line, "##end"))
	{
		*e = 1;
		var->index = var->index->next;
		return (var->index);
	}
	if (is_room(var->index->line))
	{
		var->r_index = init_room(var, room, s, e);
	}
	var->index = var->index->next;
	return (var->index);
}

void					create_rooms(t_main *var)
{
	char				**room;
	int					start;
	int					end;

	start = 0;
	end = 0;
	var->room_head = (t_rooms*)malloc(sizeof(t_rooms));
	var->index = var->input_head;
	var->r_index = NULL;
	while (var->index)
	{
		var->index = sort_data(var, room, &start, &end);
	}
	if (!var->r_index)
	{
		ft_putendl("\x1b[31mError: File has no rooms");
		exit(EXIT_FAILURE);
	}
	var->r_index = var->r_index->prev;
	free(var->r_index->next);
	var->r_index->next = NULL;
	var->r_index = var->room_head;
	var->index = var->input_head;
}
