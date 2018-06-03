/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:40:04 by emaune            #+#    #+#             */
/*   Updated: 2017/11/23 09:14:32 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_input			*err_check_1(t_input *file)
{
	if (check_ants(file->line_number, file->line))
	{
		ft_putstr("\x1b[31;1mError:\nNumber of ants is unspecified\x1b[0m");
		free_input(&file);
		exit(EXIT_FAILURE);
	}
	else if (!check_ants(file->line_number, file->line)
			&& file->line_number == 1)
	{
		file = file->next;
	}
	return (file);
}
