/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:34:32 by emaune            #+#    #+#             */
/*   Updated: 2018/07/23 09:18:16 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*malloc_stack(t_stack *a, int argc)
{
	int			i;
	t_stack		*index;
	t_stack		*temp;

	a = (t_stack*)malloc(sizeof(t_stack));
	a->prev = NULL;
	a->next = NULL;
	index = a;
	i = 1;
	while (i < argc)
	{
		index->next = (t_stack*)malloc(sizeof(t_stack));
		temp = index;
		index = index->next;
		index->next = NULL;
		index->prev = temp;
		i++;
	}
	return (a);
}

t_stack			*store_arguments(t_stack *a, int argc, char **argv)
{
	t_stack		*index;
	int			i;

	i = 0;
	a = malloc_stack(a, argc);
	index = a;
	while (index)
	{
		index->num = ft_atoi(argv[i]);
		i++;
		index = index->next;
	}
	return (a);
}
