/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:37:00 by emaune            #+#    #+#             */
/*   Updated: 2018/07/29 12:38:32 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_stack(t_stack *stack)
{
	ft_putstr("\t");
	if (!stack)
		ft_putstr("Empty");
	while (stack)
	{
		ft_putnbr(stack->num);
		ft_putchar(' ');
		stack = stack->next;
	}
	ft_putendl("");
}

void			rev_print_stack(t_stack *stack)
{
	ft_putstr("b: ");
	while (stack->next)
		stack = stack->next;
	while (stack)
	{
		ft_putnbr(stack->num);
		ft_putchar('\n');
		stack = stack->prev;
	}
}
