/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 10:30:17 by emaune            #+#    #+#             */
/*   Updated: 2018/07/26 11:24:32 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			rotate_a(t_main *var)
{
	t_stack		*a;

	a = var->a;
	if (stack_len(a) > 1)
	{
		if (stack_len(a) == 2)
			var->a = swap_a(a);
		else
		{
			var->a = a->next;
			while (a->next)
				a = a->next;
			a->next = var->a->prev;
			a->next->prev = a;
			a->next->next = NULL;
			var->a->prev = NULL;
		}
	}
}

void			rotate_b(t_main *var)
{
	t_stack		*b;

	b = var->b;
	if (stack_len(b) > 1)
	{
		if (stack_len(b) == 2)
			var->b = swap_b(b);
		else
		{
			var->b = b->next;
			while (b->next)
				b = b->next;
			b->next = var->b->prev;
			b->next->prev = b;
			b->next->next = NULL;
			var->b->prev = NULL;
		}
	}
}

void			ra_and_rb(t_main *var)
{
	rotate_a(var);
	rotate_b(var);
}
