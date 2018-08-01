/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 12:28:29 by emaune            #+#    #+#             */
/*   Updated: 2018/07/31 13:57:07 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				get_min(t_stack *stack)
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*min;

	a = stack;
	min = a;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (min->num > b->num)
			{
				min = b;
			}
			b = b->next;
		}
		a = a->next;
	}
	return (min->num);
}

int				min_index(t_stack *stack)
{
	int			i;
	int			min;

	i = 0;
	min = get_min(stack);
	while (stack)
	{
		if (stack->num == min)
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}

void			sort_big_stack(t_main *var)
{
	while (1)
	{
		if (!stack_len(var->b) && is_sorted(var->a))
		{
			break ;
		}
		if (is_sorted(var->a))
		{
			ft_putendl("pa");
			push_a(var);
//	print_stack(var->a);
//					print_stack(var->b);

		}
		else
		{
			while (var->a->num != get_min(var->a))
			{
				if (min_index(var->a) > stack_len(var->a) / 2)
				{
					ft_putendl("rra");
					rev_rotate_a(var);	
				//	print_stack(var->a);
				//	print_stack(var->b);
				}
				else
				{
					ft_putendl("ra");
					rotate_a(var);
				//	print_stack(var->a);
				//	print_stack(var->b);
				}
			}
			if (!is_sorted(var->a))
			{
				ft_putendl("pb");
				push_b(var);
			}
		}
		if (!is_sorted(var->a))
		{
		//	print_stack(var->a);
		//	print_stack(var->b);
		}
	}
}
