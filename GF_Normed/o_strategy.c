/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   O_strategy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:20:23 by emaune            #+#    #+#             */
/*   Updated: 2018/07/17 10:33:15 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coordinates		*go_northeast(t_main *var)
{
	t_coordinates	*a;
	t_coordinates	*b;
	t_coordinates	*ne;

	a = var->possible_moves;
	ne = a;
	b = a->next;
	while (b)
	{
		if (a->y == b->y)
		{
			ne = b;
		}
		else
			break ;
		b = b->next;
	}
	return (ne);
}

t_coordinates		*max_x(t_main *var)
{
	t_coordinates	*a;
	t_coordinates	*b;
	t_coordinates	*max;

	a = var->possible_moves;
	max = a;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (a->x > b->x)
				max = a;
			else
				max = b;
			b = b->next;
		}
		a = a->next;
	}
	return (max);
}

t_coordinates		*max_y(t_main *var)
{
	t_coordinates	*a;

	a = var->possible_moves;
	while (a->next)
		a = a->next;
	return (a);
}
