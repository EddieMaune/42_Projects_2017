/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_at_bottom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:24:10 by emaune            #+#    #+#             */
/*   Updated: 2018/07/31 15:24:59 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int         number_at_bottom(t_stack *stack)
{
    while (stack->next)
    {
        stack = stack->next;
    }
    return (stack->num);
}

t_stack		*link_at_bottom(t_stack *stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}
