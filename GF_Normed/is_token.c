/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:08:50 by emaune            #+#    #+#             */
/*   Updated: 2018/07/17 10:19:02 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				is_token(char cell, t_main *var)
{
	if (cell == var->token || cell == ft_tolower(var->token))
		return (1);
	return (0);
}

int				is_opponents_token(char cell, t_main *var)
{
	if (!is_token(cell, var) && cell != '.')
		return (1);
	return (0);
}
