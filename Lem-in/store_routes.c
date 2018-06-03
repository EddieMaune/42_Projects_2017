/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_routes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:24:10 by emaune            #+#    #+#             */
/*   Updated: 2017/12/01 16:33:35 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_route	*init_path(t_main *var, t_route *path, t_route *temp, char *t)
{
	path->room = ft_strdup(var->r->room);
	t = path->room;
	var->r = var->r->next;
	path->room = ft_strjoin(t, "-");
	free(t);
	t = path->room;
	path->room = ft_strjoin(t, var->r->room);
	free(t);
	t = NULL;
	temp = path;
	path->next = (t_route*)malloc(sizeof(t_route));
	path = path->next;
	path->prev = temp;
	var->r = var->r->next;
	return (path);
}

t_route			*get_route(t_main *var, t_route *path)
{
	t_route		*temp;
	t_route		*phead;
	char		*t;

	path = (t_route*)malloc(sizeof(t_route));
	phead = path;
	phead->prev = NULL;
	while (var->r)
	{
		path = init_path(var, path, temp, t);
	}
	path = path->prev;
	free(path->next);
	path->next = NULL;
	path = phead;
	return (phead);
}

void			*store_routes(t_main *var)
{
	t_route		*routes;
	t_route		*temp;
	t_rooms		*rooms;
	int			i;

	i = 0;
	while (var->r_index)
	{
		if (var->r_index->is_start)
		{
			var->start = var->r_index;
			break ;
		}
		var->r_index = var->r_index->next;
	}
	var->r_index = var->room_head;
	routes = get_route(var, NULL);
	free_routes(var->rh);
	var->r = routes;
	var->rh = routes;
	routes = NULL;
	return (NULL);
}
