/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_dups.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:03:54 by emaune            #+#    #+#             */
/*   Updated: 2018/07/23 10:06:18 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			has_dups(t_stack *stack)
{
	t_stack	*a;
	t_stack	*b;

	a = stack;
	while (a)
	{
		b = a->next;
		while(b)
		{
			if (a->num == b->num)
				return (1);
			b = b->next;
		}
		a = a->next;
	}
	return (0);
}
