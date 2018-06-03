/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_routes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:27:20 by emaune            #+#    #+#             */
/*   Updated: 2017/12/01 18:11:51 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				loop_graph(t_rooms *from, t_rte *x, t_rooms *link, int i)
{
	i = 0;
	if (!from)
		return (0);
	if (from == x->e)
	{
		if (link->flag)
			*x->ans += 1;
		return (0);
	}
	if (from->total_links)
		while (i < from->total_links)
		{
			x->to = from->links[i];
			if (x->to == x->prev)
			{
				i++;
				x->to = from->links[i];
			}
			if (from != x->e)
				if (x->to)
					if (!x->to->flag || x->to == x->e)
						leads_to_end(x->to, x, link);
			i++;
		}
	return (1);
}

int				leads_to_end(t_rooms *from, t_rte *x, t_rooms *link)
{
	int			result;
	int			i;

	result = 0;
	if (!from->flag)
	{
		if (!from->is_end)
			from->flag = 1;
		if (!loop_graph(from, x, link, i))
			return (result);
	}
	else
		return (0);
	from->flag = 0;
	return (result);
}

static void		init_start_end_room(t_rte *x)
{
	while (x->e)
	{
		if (x->e->is_end)
			break ;
		x->e = x->e->next;
	}
	while (x->s)
	{
		if (x->s->is_start)
			break ;
		x->s = x->s->next;
	}
	x->from = x->s;
}

static int		begin_search_for_end(t_rooms *rooms, char *check, t_rte *x)
{
	if (!ft_strcmp(x->e->room_name, check))
	{
		free(x->ans);
		return (1);
	}
	if (rooms != x->e)
		leads_to_end(x->s, x, room_to_route(rooms, check));
	if (!*x->ans)
	{
		free(x->ans);
		return (0);
	}
	if (*x->ans > 0)
	{
		free(x->ans);
		x->ans = NULL;
		return (1);
	}
	free(x->ans);
	x->ans = NULL;
	return (0);
}

int				room_leads_to_end(t_rooms *rooms, char *check)
{
	t_rte		x;

	x.e = rooms;
	x.s = rooms;
	x.temp = rooms;
	x.i = 0;
	x.ans = (int*)malloc(sizeof(int));
	*x.ans = 0;
	init_start_end_room(&x);
	return (begin_search_for_end(rooms, check, &x));
}
