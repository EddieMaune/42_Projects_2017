/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:54:54 by emaune            #+#    #+#             */
/*   Updated: 2018/07/31 15:37:22 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int             num_index(t_stack *stack, int num)
{
	int         i;
 
	i = 0;
	while (stack)
	{
		if (stack->num == num)
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}

int			dist_to_top(t_stack *stack, int num)
{
	int		i;
	t_stack	*a;

	if (num_index(stack, num) < stack_len(stack) / 2 + 1)
	{
		i = 0;
		a = stack;
		while (a)
		{
			if (a->num == num)
				break ;
			i++;
			a = a->next;
		}
	}
	else
	{
		i = 1;
		a = link_at_bottom(stack);
		while (a)
		{
			if (a->num == num)
				break ;
			i++;
			a = a->prev;
		}
	}
	return (i);
}

int			dist_to_sort(t_stack *stack, int num)
{
	int		i;
	int		j;
	t_stack	*b1;
	t_stack	*b2;
	
	if (stack)
	{
		if (stack->num < num)
			return (0);
		if (stack->num > num && number_at_bottom(stack) > num)
			return (1);
		i = 0;
		b1 = stack;
		while (b1)
		{
			if (b1->num < num)
				break ;
			i++;
			b1 = b1->next;
		}
		b2 = link_at_bottom(stack);
		j = 1;
		while (b2)
		{
			if (b2->num > num)
				break ;
			j++;
			b2 = b2->next;
		}
	}
	else
		return (0);
	return (i < j ? i : j);
}
