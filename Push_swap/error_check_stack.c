/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:41:02 by emaune            #+#    #+#             */
/*   Updated: 2018/07/23 10:46:50 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		error_check_stack(t_main *var)
{
	if (has_dups(var->a))
	{
		free_stack(var->a);
		ft_putstr("Error");
		exit(-1);
	}
}