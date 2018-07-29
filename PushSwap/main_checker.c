/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:35:33 by emaune            #+#    #+#             */
/*   Updated: 2018/07/29 13:14:37 by emaune           ###   ########.fr       */
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
		read_instructions(&var);
	}
	ft_putendl("KO");
	return (0);
}
