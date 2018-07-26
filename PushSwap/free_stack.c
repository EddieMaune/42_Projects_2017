/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:17:48 by emaune            #+#    #+#             */
/*   Updated: 2018/07/26 11:55:10 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_stack(t_stack *stack)
{
	while (stack->next)
	{
		stack = stack->next;
		free(stack->prev);
	}
	free(stack);
}
