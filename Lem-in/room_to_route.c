/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_to_route.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:33:05 by emaune            #+#    #+#             */
/*   Updated: 2017/11/29 11:52:35 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms			*room_to_route(t_rooms *room, char	*r)
{
	while (room)
	{
		if (!ft_strcmp(room->room_name, r))
		{
		//	ft_putendl(room->room_name);
			return (room);
		}
		room = room->next;
	}
	return (NULL);
}
