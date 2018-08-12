/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowest_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:39:02 by emaune            #+#    #+#             */
/*   Updated: 2018/08/01 11:58:09 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			lowest_distance(t_stack *stack)
{
	t_stack	*x;
	t_stack	*y;
	int		min;

	x = stack;
	min = x->num;
	while (x)
	{
		y = x->next;
		while (y)
		{
			if (y->num < min)
				min = y->num;
			y = y->next;	
		}
	}
	return (min);
}
