/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 12:11:14 by emaune            #+#    #+#             */
/*   Updated: 2018/06/13 16:01:41 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		set_token(t_main *var)
{
	get_next_line(0, &var->line);
	if (ft_strstr(var->line, "$$$"))
	{
		if (ft_strstr(var->line, "p1"))
			var->token = 'O';
		else
			var->token = 'X';
	}
	free(var->line);
	var->line = NULL;
}
