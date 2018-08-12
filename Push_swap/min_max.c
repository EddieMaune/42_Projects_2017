/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:35:17 by emaune            #+#    #+#             */
/*   Updated: 2018/08/12 10:54:23 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     	 max_num(t_stack *stack)
{
    t_stack     *a;
    t_stack     *max;

    a = stack;
    max = a;
    while (a)
    {
        if (max->num < a->num)
            max = a;
        a = a->next;
    }
	if (max)
    	return (max->num);
	return (0);
}

int			min_num(t_stack *stack)
{
	t_stack	*a;
	t_stack	*min;

	a = stack;
	min = a;
	while (a)
	{
		if (min->num > a->num)
			min = a;
		a = a->next;
	}
	if (min)
		return (min->num);
	return (0);
}

t_stack		*max_ptr(t_stack *stack)
{
	int		max;
	t_stack	*b;

	max = max_num(stack);
	b = stack;
	while (b)
	{	
		if (b->num == max)
			break ;
		b = b->next;
	}
	return (b);
}




