/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 12:16:33 by emaune            #+#    #+#             */
/*   Updated: 2018/08/10 12:17:42 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int      get_index(t_stack *stack, int num)
{
	int         i;

	i = 0;
	while (stack)
	{
		if (stack->num == num)
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}
