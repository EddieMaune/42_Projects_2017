/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:40:21 by emaune            #+#    #+#             */
/*   Updated: 2018/07/29 11:41:40 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_a(t_main *var)
{
	t_stack	*temp;

	if (var->b)
	{
		temp = var->b;
		var->b = var->b->next;
		if (var->b)
			var->b->prev = NULL;
		if (!var->a)
		{
			var->a = temp;
			var->a->next = NULL;
			var->a->prev = NULL;
		}
		else
		{
			var->a->prev = temp;
			temp->next = var->a;
			var->a = temp;
			var->a->prev = NULL;
		}
	}

}

void	push_b(t_main *var)
{
	t_stack	*temp;


	if (var->a)
	{
		temp = var->a;
		var->a = var->a->next;
		if (var->a)
			var->a->prev = NULL;
		if (!var->b)
		{
			var->b = temp;
			var->b->next = NULL;
			var->b->prev = NULL;
		}
		else
		{
			var->b->prev = temp;
			temp->next = var->b;
			var->b = temp;
			var->b->prev = NULL;
		}
	}
}
