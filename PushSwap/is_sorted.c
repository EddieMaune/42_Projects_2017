/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 11:37:34 by emaune            #+#    #+#             */
/*   Updated: 2018/07/29 11:46:26 by emaune           ###   ########.fr       */
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

int				is_nsorted(t_stack *stack, int len)
{
	t_stack		*i;
	t_stack		*j;
	int			size_1;
	int			size_2;

	i = stack;
	size_1 = 0;
	while (i && size_1 < len)
	{
		j = i->next;
		size_2 = size_1 + 1;
		while (j && size_2 < len)
		{
			if (i->num > j->num)
				return (0);
			j = j->next;
			size_2++;
		}
		i = i->next;
		size_1++;
	}
	return (1);
}

int				is_sorted_descending(t_stack *stack)
{
	t_stack		*i;
	t_stack		*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->num < j->num)
				return (0);
			j = j->next;	
		}
		i = i->next;
	}
	return (1);
}

int				is_nsorted_descending(t_stack *stack, int len)
{
	t_stack		*i;
	t_stack		*j;
	int			size_1;
	int			size_2;

	i = stack;
	size_1 = 0;
	while (i && size_1 < len)
	{
		j = i->next;
		size_2 = size_1 + 1;
		while (j && size_2 < len)
		{
			if (i->num < j->num)
				return (0);
			j = j->next;
			size_2++;
		}
		i = i->next;
		size_1++;
	}
	return (1);
}

