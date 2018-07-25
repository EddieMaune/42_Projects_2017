/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_arguments_to_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:07:40 by emaune            #+#    #+#             */
/*   Updated: 2018/07/23 10:23:53 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_arguments_to_stack(t_main *var, int argc, char **argv)
{
	if (argc == 2)
	{
		var->args = ft_strsplit(argv[1], ' ');
		var->ac = count_args(var->args);
		var->is_split = 1;
	}
	else
	{
		var->args = &argv[1];
		var->ac = argc - 1;
		var->is_split = 0;
	}
	check_if_args_are_ints(var, var->ac, var->args);
	init_stacks(var);
	if (var->is_split)
		ft_free_split(var->args);
}
