/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X_strategy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:48:20 by emaune            #+#    #+#             */
/*   Updated: 2018/06/15 13:10:30 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coordinates        *min_y(t_main *var)
{
	t_coordinates           *a;
	t_coordinates           *b;
	t_coordinates           *min;

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
	return (min);
}

t_coordinates        *min_x(t_main *var)
{
	t_coordinates           *a;
	t_coordinates           *b;
	t_coordinates           *min;

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

