/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:39:30 by emaune            #+#    #+#             */
/*   Updated: 2018/07/29 13:19:40 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int			number_at_bottom(t_stack *stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack->num);
}

void		sort_stack(t_main *var)
{
	int		flag;

	print_stack(var->a);
	while (1)
	{
		flag = 0;
		if (is_sorted(var->a) && !stack_len(var->b))
		{
			ft_putendl("\x1b[32;mSorted");
			break	;
		}
		else if (is_sorted(var->a) && stack_len(var->b))
		{
			if (stack_len(var->b) == 1)
			{
				ft_putendl("pa");
				push_a(var);
				print_stack(var->a);
				print_stack(var->b);
				flag = 1;
			//	if (var->b == NULL) ft_putendl("NULL");
				continue ;
			}
			if (is_nsorted(var->b, 2) && !flag)
			{
				ft_putendl("sb");
				var->b = swap_b(var->b);
				print_stack(var->a);
				print_stack(var->b);
				flag = 1;
			}
			if (var->b->num < number_at_bottom(var->b) && !flag)
			{
				ft_putendl("rb");
				rotate_b(var);
				print_stack(var->a);
				print_stack(var->b);
				flag = 1;
			}
			if (var->b->num < number_at_bottom(var->b) && !flag)
			{
				ft_putendl("rrb");
				rev_rotate_b(var);
				print_stack(var->a);
				print_stack(var->b);
				flag = 1;
			}
			if (!flag)
			{
				ft_putendl("pa");
				push_a(var);
				print_stack(var->a);
				print_stack(var->b);
				flag = 1;
			}
		}
		if (var->a->num > number_at_bottom(var->a) &&
				var->a->num > var->a->next->num &&
				!flag)
		{
			ft_putendl("ra");
			rotate_a(var);
			print_stack(var->a);
			print_stack(var->b);
			flag = 1;
		}
		if (var->a->num > number_at_bottom(var->a) &&	!flag)
		{
			ft_putendl("rra");
			rev_rotate_a(var);
			print_stack(var->a);
			print_stack(var->b);
			flag = 1;
		}
		if (stack_len(var->b) > 1 && is_nsorted(var->b, 2) && is_nsorted_descending(var->a, 2) && !flag)
		{
			ft_putendl("ss");
			sa_and_sb(var,var->a, var->b);
			print_stack(var->a);
			print_stack(var->b);
			flag = 1;
		}
		if (is_nsorted_descending(var->a, 2) && !flag)
		{
			ft_putendl("sa");
			var->a = swap_a(var->a);
			print_stack(var->a);
			print_stack(var->b);
			flag = 1;
		}
		if (stack_len(var->b) > 1 &&
				var->a->num > number_at_bottom(var->a) &&
				var->a->num > var->a->next->num &&
				var->b->num < number_at_bottom(var->b) &&
				var->b->num < var->b->next->num &&
				!flag)
		{
			ft_putendl("rr");
			ra_and_rb(var);
			print_stack(var->a);
			print_stack(var->b);
			flag = 1;
		}
		if (stack_len(var->b) > 1 &&
				var->a->num > number_at_bottom(var->a) &&
				var->b->num < number_at_bottom(var->b) &&
				!flag)
		{
			ft_putendl("rrr");
			rra_and_rrb(var);
			print_stack(var->a);
			print_stack(var->b);
			flag = 1;
		}
		if (!flag)
		{
			ft_putendl("pb");
			push_b(var);
			print_stack(var->a);
			print_stack(var->b);
			flag = 1;
		}
	}
}
