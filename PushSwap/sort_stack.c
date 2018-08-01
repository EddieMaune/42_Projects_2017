/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:39:30 by emaune            #+#    #+#             */
/*   Updated: 2018/07/31 15:30:55 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


	
void			sort_stack(t_main *var)
{
//	if (stack_len(var->a) <= 5)
//		sort_small_stack(var);
//	else
//		sort_big_stack(var);
	push_b(var);
	push_b(var);
	push_b(var);
	update_dist(var);
	print_stack(var->a);
	print_stack(var->b);
}
