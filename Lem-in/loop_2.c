/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_rooms_loop_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:56:34 by emaune            #+#    #+#             */
/*   Updated: 2017/12/01 16:16:28 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_err(t_main *var, int err)
{
	if (err == 1)
	{
		ft_putstr("\x1b[31mLinking Error: room ");
		ft_putstr(var->l_index->room2);
		ft_putendl(" does not exist");
		free(var->input_head);
		exit(EXIT_FAILURE);
	}
	if (err == 2)
	{
		ft_putstr("\x1b[31mLinking Error: room ");
		ft_putstr(var->l_index->room1);
		ft_putendl(" does not exist");
		free(var->input_head);
		exit(EXIT_FAILURE);
	}
}

static void		inner_loop_1(t_main *var, t_rooms *temp, int *room_exists)
{
	if (var->r_index->total_links > 0)
	{
		if (!var->r_index->links)
			var->r_index->links = (t_rooms**)malloc(sizeof(t_rooms)
					* var->r_index->total_links + 1);
		temp = var->room_head;
		while (temp)
		{
			if (!ft_strcmp(temp->room_name, var->l_index->room2))
			{
				var->r_index->links[var->r_index->i] = temp;
				var->r_index->i++;
				*room_exists = 1;
				break ;
			}
			temp = temp->next;
		}
	}
}

static void     inner_loop_2(t_main *var, t_rooms *temp, int *room_exists)
{ 
	if (var->r_index->total_links > 0)
	{
		if (!var->r_index->links)
			var->r_index->links = (t_rooms**)malloc(sizeof(t_rooms) * var->r_index->total_links);
		temp = var->room_head;
		while (temp)
		{
			if (!ft_strcmp(temp->room_name, var->l_index->room1))
			{
				var->r_index->links[var->r_index->i] = temp;
				var->r_index->i++;
				*room_exists = 1;
				break   ;
			}
			temp = temp->next;
		}
	}

}

void			loop_2(t_main *var, t_rooms *temp, int *room_exists)
{
	var->r_index = var->room_head;
	while (var->r_index)
	{
		if (!ft_strcmp(var->r_index->room_name, var->l_index->room1))
		{
			inner_loop_1(var, temp, room_exists);
			if (!room_exists)
				print_err(var, 1);
			else
			{
				room_exists = 0;
				break ;
			}
		}
		var->r_index = var->r_index->next;
	}
}

void			loop_3(t_main *var, t_rooms *temp, int *room_exists)
{
	var->r_index = var->room_head;
	while (var->r_index)
	{
		if (!ft_strcmp(var->r_index->room_name, var->l_index->room2))
		{
			inner_loop_2(var, temp, room_exists);
			if (!room_exists)
				print_err(var, 2);
			else
			{
				room_exists = 0;
				break   ;
			}
		}
		var->r_index = var->r_index->next;
	}
}
