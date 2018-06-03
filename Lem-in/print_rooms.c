/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 08:59:04 by emaune            #+#    #+#             */
/*   Updated: 2017/11/23 09:07:38 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_rooms(t_rooms *room)
{
	while (room)
	{
		if (room->is_start)
			ft_putstr("\x1b[35mstart\x1b[0m\n");
		if (room->is_end)
			ft_putstr("\x1b[35mend\x1b[0m\n");
		ft_putstr("Room Name: ");
		ft_putendl(room->room_name);
		ft_putstr("Ants in room: ");
		ft_putnbr(room->ants);
		ft_putendl("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		room  = room->next;
	}
}
