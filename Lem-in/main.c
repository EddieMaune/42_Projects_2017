/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:15:24 by emaune            #+#    #+#             */
/*   Updated: 2017/12/01 16:33:58 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	march_and_free(t_main *var)
{
	var->r_index = var->room_head;
	if (count_routes(var->r_index, var))
	{
		var->r_index = var->room_head;
		store_routes(var);
		var->index = var->input_head;
		print_file(var->index);
		march_ants(var);
	}
	free(var->end_room);
	free_input(&var->input_head);
	free_routes(var->rh);
	free_rooms(var);
	free_links(var);
}

int		main(int argc, char **argv)
{
	t_main	var;

	read_file(&var);
	error_check_file(var.index);
	create_rooms(&var);
	if (!var.room_head)
	{
		free_input(&var.input_head);
		return (0);
	}
	error_check_room(&var);
	store_links(&var);
	error_check_links(&var);
	link_rooms(&var);
	if (links_have_dup(var.l_head))
	{
		ft_putstr("\x1b[31mError: Duplicate link found\x1b[0m");
		free_rooms(&var);
		free_links(&var);
		free_input(&var.input_head);
		return (0);
	}
	march_and_free(&var);
	return (0);
}
