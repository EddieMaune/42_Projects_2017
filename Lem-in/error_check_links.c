/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_links.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:34:36 by emaune            #+#    #+#             */
/*   Updated: 2017/11/30 18:01:53 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		link_room_exists(char *room, t_rooms *r)
{
	while (r)
	{
		if (!ft_strcmp(r->room_name, room))
		{
			return (1);
		}
		r = r->next;
	}
	return (0);
}

void			error_check_links(t_main *var)
{
	var->l_index = var->l_head;
	while (var->l_index)
	{
		var->r_index = var->room_head;
		if (!link_room_exists(var->l_index->room1, var->r_index)
				|| !link_room_exists(var->l_index->room2, var->r_index))
		{
			ft_putstr("\x1b[31mError: Linked room does not exist\n");
			ft_putstr(var->l_index->room1);
			ft_putchar('-');
			ft_putstr(var->l_index->room2);
			free_input(&var->input_head);
			free_rooms(var);
			free_links(var);
			exit(EXIT_FAILURE);
		}
		var->l_index = var->l_index->next;
	}
}
