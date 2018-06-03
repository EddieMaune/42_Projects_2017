/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:01:49 by emaune            #+#    #+#             */
/*   Updated: 2017/11/22 17:44:31 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_input		*err_check_2(t_input *file)
{
	if (is_room(file->line))
	{
		file = file->next;
		return (file);
	}
	else if (is_comment(file->line))
	{
		file = file->next;
		return (file);
	}
	if (is_valid_start_end(file))
	{
		file = file->next;
		return (file);
	}
	else if (is_link(file->line))
	{
		file = file->next;
		return (file);
	}
	else
	{
		print_error(file);
	}
	return (NULL);
}
