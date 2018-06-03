/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_routes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:27:20 by emaune            #+#    #+#             */
/*   Updated: 2017/12/01 16:25:32 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			get_path(t_c *var, t_rooms *from, t_route *temp)
{
	var->temp = var->pstr;
	var->pstr = ft_strjoin(var->temp, from->room_name);
	temp = var->r;
	var->r->room = ft_strdup(from->room_name);
	var->r->next = (t_route*)malloc(sizeof(t_route));
	var->r = var->r->next;
	var->r->prev = temp;
	free(var->temp);
	var->temp = NULL;
	var->temp = var->pstr;
	var->pstr = ft_strjoin(var->temp, var->to->room_name);
	temp = var->r;
	var->r->room = ft_strdup(var->to->room_name);
	var->r->next = (t_route*)malloc(sizeof(t_route));
	var->r = var->r->next;
	var->r->prev = temp;
	free(var->temp);
	var->temp = NULL;
	var->prev = from;
}

void				loop(t_rooms *from, t_c *var, int i)
{
	t_route			*temp;

	i = 0;
	while (i < from->total_links)
	{
		var->to = from->links[i];
		if (var->to == var->prev)
		{
			i++;
			var->to = from->links[i];
		}
		if (var->to)
		{
			if (!var->r)
			{
				var->r = (t_route*)malloc(sizeof(t_route));
				var->route_head = var->r;
				var->route_head->prev = NULL;
			}
			get_path(var, from, temp);
			if (!var->to->flag || var->to == var->e)
				count_paths_to_end(var->to, var);
		}
		i++;
	}
}

int					count_paths_to_end(t_rooms *from, t_c *var)
{
	int				result;
	int				i;
	t_route			*temp;

	from->flag = 1;
	i = 0;
	result = 0;
	if (!from)
	{
		return (result);
	}
	if (from == var->e)
	{
		*var->ans += 1;
		return (result);
	}
	if (from->total_links)
		loop(from, var, i);
	return (result);
}

static void			c_routes(t_rooms *rooms, t_main *m, t_c *var)
{
	var->from = var->s;
	var->prev = var->s;
	var->start = var->s;
	count_paths_to_end(var->from, var);
	if (!*var->ans)
	{
		ft_putstr("\x1b[31mError: There are no routes to end\x1b[0m");
		free(var->ans);
		exit(EXIT_FAILURE);
	}
	var->r = var->r->prev;
	free(var->r->next);
	var->r->next = NULL;
	m->route_head = var->route_head;
	m->end_room = ft_strdup(var->e->room_name);
	m->r = m->route_head;
	m->total_routes = *var->ans;
	free(var->ans);
}

int					count_routes(t_rooms *rooms, t_main *m)
{
	t_c				var;

	var.pstr = ft_strnew(0);
	var.e = rooms;
	var.r = NULL;
	var.s = rooms;
	var.ans = (int*)malloc(sizeof(int));
	*var.ans = 0;
	while (var.e)
	{
		if (var.e->is_end)
			break ;
		var.e = var.e->next;
	}
	m->end = var.e;
	while (var.s)
	{
		if (var.s->is_start)
			break ;
		var.s = var.s->next;
	}
	c_routes(rooms, m, &var);
	return (m->total_routes);
}
