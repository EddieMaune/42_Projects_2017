/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:28:58 by emaune            #+#    #+#             */
/*   Updated: 2018/06/14 12:15:47 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		place_piece(t_main *var)
{
	char	*coordinates;
	char	*x;
	char	*y;
	char	*temp;

	coordinates = ft_strnew(0);
	x = ft_itoa(var->placement.x);
	y = ft_itoa(var->placement.y);
	temp = coordinates;
	coordinates = ft_strjoin(temp, y);
	free(temp);
	temp = coordinates;
	coordinates = ft_strjoin(temp, " ");
	free(temp);
	temp = coordinates;
	coordinates = ft_strjoin(temp, x);
	free(temp);
	ft_putendl(coordinates);
	free(coordinates);
}
