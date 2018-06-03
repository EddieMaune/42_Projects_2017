/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_start_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:06:51 by emaune            #+#    #+#             */
/*   Updated: 2017/11/30 14:30:45 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_valid_start_end(t_input *file)
{
	if (!ft_strcmp(file->line, "##start"))
	{
		file = file->next;
		if (!is_room(file->line))
		{
			ft_putstr("\x1b[31mError: Start room invalid\x1b[0m");
			exit(EXIT_FAILURE);
		}
		else
			return (1);
	}
	else if (!ft_strcmp(file->line, "##end"))
	{
		file = file->next;
		if (!is_room(file->line))
		{
			ft_putstr("\x1b[31mError: End room invalid\x1b[0m");
			exit(EXIT_FAILURE);
		}
		else
			return (1);
	}
	return (0);
}
