/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X_strategy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:48:20 by emaune            #+#    #+#             */
/*   Updated: 2018/07/17 10:50:26 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coordinates		*min_y(t_main *var)
{
	t_coordinates	*a;
	t_coordinates	*b;
	t_coordinates	*min;

	a = var->possible_moves;
	min = a;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (a->y < b->y && a->y < min->y && a->y < b->y)
				min = a;
			else if (a->y > b->y)
				min = b;
			b = b->next;
		}
		a = a->next;
	}
	return (var->possible_moves);
}

t_coordinates		*min_x(t_main *var)
{
	t_coordinates	*a;
	t_coordinates	*b;
	t_coordinates	*min;

	a = var->possible_moves;
	min = a;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (a->x < b->x && a->x < min->x)
				min = a;
			else if (a->y > b->y)
				min = b;
			b = b->next;
		}
		a = a->next;
	}
	return (min);
}

t_coordinates		*go_southwest(t_main *var)
{
	t_coordinates	*a;
	t_coordinates	*b;
	t_coordinates	*sw;

	a = var->possible_moves;
	sw = a;
	b = a->next;
	while (b)
	{
		if (b->y >= a->y && sw->y >= a->y)
			sw = b;
		b = b->next;
	}
	while (a)
	{
		if (a->y == sw->y)
		{
			sw = a;
			break ;
		}
		a = a->next;
	}
	return (sw);
}
