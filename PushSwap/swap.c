/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:51:17 by emaune            #+#    #+#             */
/*   Updated: 2018/07/26 10:26:28 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*swap_a(t_stack *a)
{
	t_stack *temp;

	if (stack_len(a) > 1)
	{
		temp = a;
		a = a->next;
		temp->next = a->next;
		a->next = temp;
		a->prev = NULL;
		if (temp->next)
			temp->next->prev = temp;
		temp->prev = a;
	}
	return (a);
}

t_stack		*swap_b(t_stack *b)
{
	t_stack *temp;

	if (stack_len(b) > 1)
	{
		temp = b;
		b = b->next;
		temp->next = b->next;
		b->next = temp;
		b->prev = NULL;
		if (temp->next)
			temp->next->prev = temp;
		temp->prev = b;
	}
	return (b);

}

void	sa_and_sb(t_main *var, t_stack *a, t_stack *b)
{
	var->a = swap_a(a);
	var->b = swap_b(b);
}
