/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:34:32 by emaune            #+#    #+#             */
/*   Updated: 2018/06/07 16:36:51 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*store_arguments(t_stack *a, int argc, char **argv)
{
	t_stack	*index;
	t_stack *temp;
	int		i;

	a = (t_stack*)malloc(sizeof(t_stack));
	a->prev = NULL;
	index = a;
	i = 1;
	while (i < argc - 1)
	{
		index->next = (t_stack*)malloc(sizeof(t_stack));
		temp = index;
		index = index->next;
		index->prev = temp;
		index->next = NULL;
		i++;
	}
	i = 1;
	while (index)
	{
		index->num = ft_atoi(argv[i]);
		i++;
		index = index->prev;
	}
	return (a);
}
