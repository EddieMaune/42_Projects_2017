/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_dist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 14:45:29 by emaune            #+#    #+#             */
/*   Updated: 2018/07/31 15:27:30 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			update_dist(t_main *var)
{
	t_stack		*a;

	a = var->a;
	while (a)
	{
		a->dist = dist_to_top(var->a, a->num) + 1 + dist_to_sort(var->b, a->num);
		a = a->next;
	}
}
