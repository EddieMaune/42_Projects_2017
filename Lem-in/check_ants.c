/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:01:09 by emaune            #+#    #+#             */
/*   Updated: 2017/11/22 17:24:02 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_ants(int line_number, char *line)
{
	int		i;

	i = 0;
	if (line_number == 1)
	{
		while (line[i])
		{
			if (ft_isdigit(line[i]))
			{
				i++;
				continue	;
			}
			else
				return (1);
		}
		return (0);
	}
	else
	{
		return (0);
	}
}
