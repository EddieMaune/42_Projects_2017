/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 11:03:21 by emaune            #+#    #+#             */
/*   Updated: 2018/07/26 11:27:02 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			rev_rotate_a(t_main *var)
{
	t_stack		*a;

	a = var->a;
	if (stack_len(a) > 1)
	{
		if (stack_len(a) == 2)
			var->a = swap_a(a);
		else
		{
			while(a->next)
				a = a->next;
			a->prev->next = NULL;
			a->prev = NULL;
			a->next = var->a;
			var->a->prev = a;
			var->a = a;
		}
	}
}

void			rev_rotate_b(t_main *var)
{
	t_stack		*b;

	b = var->b;
	if (stack_len(b) > 1)
	{
		if (stack_len(b) == 2)
			var->b = swap_b(b);
		else
		{
			while(b->next)
				b = b->next;
			b->prev->next = NULL;
			b->prev = NULL;
			b->next = var->b;
			var->b->prev = b;
			var->b = b;
		}
	}
}

void			rra_and_rrb(t_main *var)
{
	rev_rotate_a(var);
	rev_rotate_b(var);
}
