/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:37:00 by emaune            #+#    #+#             */
/*   Updated: 2018/08/12 15:55:13 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_stack(t_stack *stack)
{
	stack = NULL;/*
	ft_putstr("\t");
	if (!stack) 
		ft_putstr("Empty");
	while (stack)
	{
		ft_putnbr(stack->num);
//		ft_putchar('.');
//		ft_putnbr(stack->a_dist);
		ft_putchar(' ');
		stack = stack->next;
	}
	ft_putendl("\n");*/
}

void			rev_print_stack(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	while (stack)
	{
		ft_putnbr(stack->num);
		ft_putchar('\n');
		stack = stack->prev;
	}
}
