/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:35:33 by emaune            #+#    #+#             */
/*   Updated: 2018/07/25 14:10:51 by emaune           ###   ########.fr       */
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
		print_stack(var.a);
		ft_putendl("");
	//	sa_and_sb(&var, var.a, var.b);
		push_b(&var);
		push_b(&var);
	//	push_a(&var);
		print_stack(var.a);
		ft_putendl("");
		swap_b(var.b);
		print_stack(var.b);
	//	rev_print_stack(var.b);
	//	rev_print_stack(var.a);
	}
	return (0);
}
