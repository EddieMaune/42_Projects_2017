/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 11:55:25 by emaune            #+#    #+#             */
/*   Updated: 2018/07/29 13:14:46 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		execute_instruction(char *line, t_main *var)
{
	if (ft_strequ(line, "sa"))
		var->a = swap_a(var->a);
	else if (ft_strequ(line, "sb"))
		var->b = swap_b(var->b);
	else if (ft_strequ(line, "ss"))
		sa_and_sb(var, var->a, var->b);
	else if (ft_strequ(line, "pa"))
		push_a(var);
	else if (ft_strequ(line, "pb"))
		push_b(var);
	else if (ft_strequ(line, "ra"))
		rotate_a(var);
	else if (ft_strequ(line, "rb"))
		rotate_b(var);
	else if (ft_strequ(line, "rr"))
		ra_and_rb(var);
	else if (ft_strequ(line, "rra"))
		rev_rotate_a(var);
	else if (ft_strequ(line, "rrb"))
		rev_rotate_b(var);
	else if (ft_strequ(line, "rrr"))
		rra_and_rrb(var);
	else
	{
		ft_putendl("Error");
		exit(-1);
	}
}

void			read_instructions(t_main *var)
{
	if (is_sorted(var->a) && !stack_len(var->b))
	{
		ft_strdel(&var->line);
		ft_putendl("OK");
		exit(0);
	}
	while ((!is_sorted(var->a) || stack_len(var->b)) && get_next_line(0, &var->line))
	{
		execute_instruction(var->line, var);
		if (is_sorted(var->a) && !stack_len(var->b))
		{
			ft_strdel(&var->line);
			ft_putendl("OK");
			exit(0);
		}
		ft_strdel(&var->line);
	}
}
