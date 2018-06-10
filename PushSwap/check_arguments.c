/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:55:10 by emaune            #+#    #+#             */
/*   Updated: 2018/06/08 15:42:04 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		arguments_are_integers(int argc, char **argv, int ais)
{
	int			i;

	if (ais)
		i = 1;
	else
		i = 0;
	while (i < argc)
	{
		if (!ft_isnum(argv[i]))
			return (0);
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

void			check_if_args_are_ints(int argc, char	**argv, int ais)
{
	if (!arguments_are_integers(argc, argv, ais))
	{
		ft_puterror("Error");
		exit(0);
	}
}
