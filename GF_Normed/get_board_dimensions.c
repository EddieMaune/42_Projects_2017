/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board_dimensions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:36:23 by emaune            #+#    #+#             */
/*   Updated: 2018/07/17 10:13:28 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int					get_rows(char *rows)
{
	int						i;
	int						y;

	i = 0;
	y = 0;
	while (rows[i])
	{
		if (rows[i] == ' ')
		{
			rows[i] = '\0';
			y = ft_atoi(rows);
			rows[i] = ' ';
			break ;
		}
		i++;
	}
	return (y);
}

static int					get_columns(char *columns)
{
	int						i;
	int						x;

	i = 0;
	x = 0;
	while (columns[i])
	{
		if (columns[i] == ':')
		{
			columns[i] = '\0';
			x = ft_atoi(columns);
			columns[i] = ':';
			break ;
		}
		i++;
	}
	return (x);
}

t_dimensions				get_board_dimensions(char *line)
{
	char					*rows;
	char					*columns;
	t_dimensions			dimensions;

	rows = ft_strchr(line, ' ');
	rows++;
	columns = ft_strchr(rows, ' ');
	columns++;
	dimensions.rows = get_rows(rows);
	dimensions.columns = get_columns(columns);
	return (dimensions);
}
