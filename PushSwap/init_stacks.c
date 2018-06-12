/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:34:06 by emaune            #+#    #+#             */
/*   Updated: 2018/06/10 16:34:14 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_stacks(int argc, char **argv, t_main *var)
{
	var->a = NULL;
	var->b = NULL;
	var->args = argv;
	var->arg_is_string = 0;
	var->ac = argc;
	if (argc > 1)
	{
		if (ft_strchr(var->args[1], ' '))
		{
			var->args = ft_strsplit(var->args[1], ' ');
			var->ac = ft_count_split(var->args);
			var->arg_is_string = 1;
		}
		check_if_args_are_ints(var->ac, var->args, var->arg_is_string);
		var->a = store_arguments(var->a, var->ac,  var->args, var->arg_is_string);
	}
	else
		exit(0);
}
