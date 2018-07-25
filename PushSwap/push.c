/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:40:21 by emaune            #+#    #+#             */
/*   Updated: 2018/07/23 15:24:54 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_a(t_main *var)
{
	t_stack	*temp;

	temp = var->b;
	var->b = var->b->next;
	var->b->prev = NULL;
	var-a->prev = temp;
	temp->next = var->a;
	var->a = temp;
}

void	push_b(t_main *var)
{
	t_stack	*temp;

	temp = var->a;
	var->a = var->a->next;
	var->a->prev = NULL;
	var-b->prev = temp;
	temp->next = var->a;
	var->a = temp;
}
