/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:17:20 by emaune            #+#    #+#             */
/*   Updated: 2017/11/22 17:36:50 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_room(char *line)
{
	char	**room;
	int		i;

	i = 0;
	room = ft_strsplit(line, ' ');
	while (room[i])
		i++;
	if (i != 3)
	{
		free_split(room);
		return (0);
	}
	if (*room[0] != 'L' && *room[0] != '#'
			&& ft_isnumber(room[1])
			&& ft_isnumber(room[2]))
	{
		free_split(room);
		return (1);
	}
	free_split(room);
	return (0);
}
