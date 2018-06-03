/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   march_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:15:30 by emaune            #+#    #+#             */
/*   Updated: 2017/12/01 18:28:37 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static void		phase_1(t_main *var, t_march *a)
{
	var->r_index = var->room_head;
	a->temp = var->r->room;
	a->j = 0;
	while (a->temp[a->j])
	{
		if (a->temp[a->j] == '-')
		{
			a->c = a->temp[a->j];
			a->temp[a->j] = '\0';
			break ;
		}
		a->j++;
	}
	a->from = ft_strdup(a->temp);
	a->temp[a->j] = a->c;
	a->to = ft_strdup(ft_strchr(var->r->room, '-') + 1);
	a->f = room_to_route(var->r_index, a->from);
	var->r_index = var->room_head;
	a->t = room_to_route(var->r_index, a->to);
}

static void		phase_2_1(t_main *var, t_march *a)
{
	if (a->f == var->start)
	{
		a->t->ant_name = ft_itoa(a->ants);
		a->ants++;
	}
	else
	{
		a->t->ant_name = a->f->ant_name;
		a->f->ant_name = NULL;
	}
	a->f->ants--;
	a->t->ants++;
	ft_putstr("L");
	ft_putstr(a->t->ant_name);
	ft_putchar('-');
	ft_putstr(a->t->room_name);
	ft_putstr(" (");
	ft_putstr(var->r->room);
	ft_putstr(")-");
	ft_putstr("-(ants=");
	ft_putnbr(a->t->ants);
	ft_putendl(")");
}

static void		phase_2_2(t_main *var, t_march *a)
{
	if (!a->f->ant_name)
	{
		a->t->ant_name = ft_itoa(a->ants);
		a->ants++;
	}
	else
		a->t->ant_name = a->f->ant_name;
	a->f->ant_name = NULL;
	a->f->ants--;
	a->t->ants++;
	ft_putstr("L");
	ft_putstr(a->t->ant_name);
	ft_putchar('-');
	ft_putstr(a->t->room_name);
	ft_putstr(" (");
	ft_putstr(var->r->room);
	ft_putstr(")-");
	ft_putstr("-(ants=");
	ft_putnbr(a->t->ants);
	ft_putendl(")");
	free(a->t->ant_name);
	a->t->ant_name = NULL;
}

static void		loop_body(t_main *var, t_march *a)
{
	var->r_index = var->room_head;
	reset_flag(var->r_index);
	a->temp = var->r->room;
	a->ans = room_leads_to_end(var->r_index, ft_strchr(a->temp, '-') + 1);
	if (a->ans)
	{
		phase_1(var, a);
		if (a->f->ants)
		{
			if (!a->t->ants && a->t != var->end)
				phase_2_1(var, a);
			else if (a->t == var->end)
				phase_2_2(var, a);
		}
		free(a->from);
		free(a->to);
		a->from = NULL;
		a->to = NULL;
	}
}

void			march_ants(t_main *var)
{
	t_march		a;

	a.i = 0;
	a.ants = 1;
	remove_dup_route(var);
	while (1)
	{
		loop_body(var, &a);
		var->r = var->r->next;
		if (!var->r)
		{
			var->r = var->rh;
			a.i++;
		}
		if (var->end->ants == var->total_ants)
			break ;
	}
}
