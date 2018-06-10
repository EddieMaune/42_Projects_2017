/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:35:33 by emaune            #+#    #+#             */
/*   Updated: 2018/06/08 15:46:21 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		**args;
	int			ac;
	int			arg_is_string;

	a = NULL;
	b = NULL;
	args = argv;
	arg_is_string = 0;
	if (argc > 1)
	{
		if (ft_strchr(args[1], ' '))
		{
			args = ft_strsplit(args[1], ' ');
			ac = ft_count_split(args);
			arg_is_string = 1;
		}
		check_if_args_are_ints(ac, args, arg_is_string);
		a = store_arguments(a, ac,  args, arg_is_string);
		while (a)
		{
			printf("%d\n", a->num);
			a = a->next;
		}
	}
	else
		return (0);
	return (0);
}
