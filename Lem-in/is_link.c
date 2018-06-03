/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:29:30 by emaune            #+#    #+#             */
/*   Updated: 2017/11/30 14:25:44 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_link(char *line)
{
	char *temp;

//	ft_putendl(line);
	if (*line == '#')
		return (0);
	if ((temp = ft_strchr(line, '-')))
	{
		temp++;
		if (!ft_strchr(temp, '-'))
		{
			return (1);
		}
	}
	return (0);
}
