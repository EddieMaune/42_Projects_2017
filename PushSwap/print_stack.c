/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:37:00 by emaune            #+#    #+#             */
/*   Updated: 2018/06/10 16:39:15 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr(stack->num);
		ft_putchar('\n');
		stack = stack->next;
	}
}
