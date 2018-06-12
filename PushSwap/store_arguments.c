/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:34:32 by emaune            #+#    #+#             */
/*   Updated: 2018/06/10 16:32:25 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_stack(t_stack *a, int argc, char **argv, int ais)
{
	int			i;
	t_stack		*index;
	t_stack		*temp;

	a = (t_stack*)malloc(sizeof(t_stack));
	a->prev = NULL;
	a->next = NULL;
	index = a;
	if (ais)
		i = 0;
	else
		i = 1;
	while (i < argc - 1)
	{
		index->next = (t_stack*)malloc(sizeof(t_stack));
		temp = index;
		index = index->next;
		index->next = NULL;
		i++;
	}
	return (a);
}

t_stack			*store_arguments(t_stack *a, int argc, char **argv, int ais)
{
	t_stack		*index;
	t_stack		*temp;
	int			i;

	if (ais)
		i = 0;
	else
		i = 1;
	a = init_stack(a, argc, argv, ais);
	index = a;
	while (index)
	{
		index->num = ft_atoi(argv[i]);
		i++;
		index = index->next;
	}
	return (a);
}
