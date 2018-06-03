/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:22:40 by emaune            #+#    #+#             */
/*   Updated: 2017/12/01 15:43:30 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_rooms(t_main *var)
{
	t_rooms			*rh;

	rh = var->room_head;
	while (rh)
	{
		free(rh->room_name);
		if (rh->ant_name)
			free(rh->ant_name);
		if (rh->links)
			free(rh->links);
		if (rh->next)
		{
			rh = rh->next;
			free(rh->prev);
		}
		else
			break ;
		rh = rh->next;
	}
	free(rh);
}
