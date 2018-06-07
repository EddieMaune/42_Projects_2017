/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:35:33 by emaune            #+#    #+#             */
/*   Updated: 2018/06/07 16:26:27 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		check_if_args_are_ints(argc, argv);
		a = store_arguments(a, argc, argv);
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
