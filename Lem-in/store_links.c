/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:56:30 by emaune            #+#    #+#             */
/*   Updated: 2017/11/30 18:00:19 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char			*get_room(char *link, int side)
{
	char			**rooms;
	char			*result;

	rooms = ft_strsplit(link, '-');
	if (side == 1)
	{
		result = ft_strdup(rooms[0]);
	}
	else if (side == 2)
	{
		result = ft_strdup(rooms[1]);
	}
	free_split(rooms);
	rooms = NULL;
	return (result);
}

void				store_links(t_main *var)
{
	var->l_head = NULL;
	while (var->index)
	{
		if (is_link(var->index->line))
		{
			if (!var->l_head)
			{
				var->l_head = (t_link*)malloc(sizeof(t_link));
				var->l_index = var->l_head;
			}
			var->l_index->room1 = get_room(var->index->line, 1);
			var->l_index->room2 = get_room(var->index->line, 2);
			var->l_index->next = (t_link*)malloc(sizeof(t_link));
			var->temp = var->l_index;
			var->l_index = var->l_index->next;
			var->l_index->prev = var->temp;
			var->temp = NULL;
		}
		var->index = var->index->next;
	}
	var->l_index = var->l_index->prev;
	free(var->l_index->next);
	var->l_index->next = NULL;
	var->l_index = var->l_head;
}
