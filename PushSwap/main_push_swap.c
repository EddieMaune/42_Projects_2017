/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:34:51 by emaune            #+#    #+#             */
/*   Updated: 2018/07/27 15:12:07 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_main	var;

	if (argc >= 2)
	{
		push_arguments_to_stack(&var, argc, argv);
		error_check_stack(&var);
	//	if (is_sorted(var.a->next))
	//		ft_putendl("sorted");
		sort_stack(&var);
		
	}
	return (0);
}
