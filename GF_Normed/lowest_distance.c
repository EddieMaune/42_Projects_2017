/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowest_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:24:09 by emaune            #+#    #+#             */
/*   Updated: 2018/07/17 10:21:26 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coordinates				*lowest_distance(t_main *var)
{
	t_coordinates			*a;
	t_coordinates			*b;
	t_coordinates			*min;

	a = var->possible_moves;
	min = a;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (b->distance < a->distance && b->distance < min->distance)
				min = b;
			b = b->next;
		}
		a = a->next;
	}
	return (min);
}
