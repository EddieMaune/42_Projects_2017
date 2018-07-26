/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 11:37:34 by emaune            #+#    #+#             */
/*   Updated: 2018/07/26 11:42:12 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				is_sorted(t_stack *stack)
{
	t_stack		*i;
	t_stack		*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->num > j->num)
				return (0);
			j = j->next;	
		}
		i = i->next;
	}
	return (1);
}
