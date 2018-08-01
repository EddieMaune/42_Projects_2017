/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:22:44 by emaune            #+#    #+#             */
/*   Updated: 2018/07/31 13:57:15 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void     sort_small_stack(t_main *var)
{
	int     flag;

	//  print_stack(var->a);
	while (1)
	{
		flag = 0;
		rr_rrr(var, &flag);
		ra_rra(var, &flag);
		sa_ss(var, &flag);
		if (is_sorted(var->a) && !stack_len(var->b))
		{
			//ft_putendl("\x1b[32;mSorted");
			break   ;
		}
		else if (is_sorted(var->a) && stack_len(var->b))
		{
			if (stack_len(var->b) == 1)
			{
				ft_putendl("pa");
				push_a(var);
				flag = 1;
				continue ;
			}
			sb_rb(var, &flag);
			rrb_pa(var, &flag);
		}
		if (!flag)
		{
			ft_putendl("pb");
			push_b(var);
			flag = 1;
		}
	}
}
