/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_dist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 14:45:29 by emaune            #+#    #+#             */
/*   Updated: 2018/08/12 15:07:57 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		rightful_index(t_stack *stack, int num)
{
	int			i;
	t_stack		*b;
	int			max_index;

	max_index = get_index(stack, max_num(stack));
	i = max_index;
	b = max_ptr(stack);
	if (b)
	{
		if (b->num < num)
		{
			//	ft_putendl("sss");
			return (i);
		}
		while (b)
		{
			if (b->num < num)
				return (i);
			if (!b->next)
				break ;
			i++;
			b = b->next;
		}
		if (num < b->num && num > stack->num)
			return (0);
		i = 0;
		b = max_ptr(stack);
		while (stack && stack != b)
		{
			if (stack->num < num)
				break ;
			i++;
			stack = stack->next;
		}
	}
	return (i);
}

void			update_dist(t_main *var)
{
	t_stack		*a;
	t_stack		*b;
	int			i;


	i = 0;
	a = var->a;
	b = var->b;
	while (a)
	{

		a->ri = rightful_index(var->b, a->num);
		a->a_dist = dist_to_top(var->a, a->num);
		a->b_dist = dist_to_sort(var->b, a->ri);
		a->dist = a->a_dist + a->b_dist + 1;
		if (i < stack_len(var->a) / 2 + 1)
			a->a_dir = 'N';
		else
			a->a_dir = 'S';
		if (var->b)
		{
			if (a->ri < stack_len(var->b) / 2 + 1)
				a->b_dir = 'N';
			else
				a->b_dir = 'S';
		}
		a = a->next;
		i++;
	}
	i = 0;
	while (b)
	{
		b->a_dist = 0;
		b->b_dist = 0;
		b->dist = 0;
		b = b->next;
	}
}
