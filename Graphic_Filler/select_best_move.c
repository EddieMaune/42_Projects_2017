/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_best_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:33:38 by emaune            #+#    #+#             */
/*   Updated: 2018/06/26 15:07:42 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


void						print_pm(t_main *var)
{
	t_coordinates			*a;

	a = var->possible_moves;
	while (a)
	{
		ft_putnbr_fd(a->y, var->fd);
		ft_putstr_fd(" ", var->fd);
		ft_putnbr_fd(a->x, var->fd);
		ft_putstr_fd(" ", var->fd);
		ft_putnbr_fd(a->distance, var->fd);
		ft_putendl_fd("", var->fd);
		a = a->next;
	}
}

static t_coordinates		*lowest_distance(t_main *var)
{
	t_coordinates			*a;
	t_coordinates			*b;
	t_coordinates			*min;

	a = var->possible_moves;
	min = a;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (b->distance < a->distance && b->distance < min->distance)
				min = b;
			b = b->next;
		}
		a = a->next;
	}
	return (min);
}

t_coordinates				*select_best_move(t_main *var)
{
	t_coordinates			*best_move;

	best_move = NULL;
	if (var->token == 'O' && var->board_dimensions.columns <= 40)
	{
	/*	if (var->board[2][var->board_dimensions.columns - 1] != var->token)
		{
			best_move = go_northeast(var);
		}
		else
			best_move = max_x(var);
		if (var->board[var->board_dimensions.rows - 1][var->board_dimensions.columns - 1] == var->token)
			best_move = min_x(var);*/
		best_move = lowest_distance(var);
		print_pm(var);
		var->placement.x = best_move->x;
		var->placement.y = best_move->y;
		ft_putstr_fd("Best Move: ", var->fd);
		ft_putnbr_fd(best_move->y, var->fd);
		ft_putstr_fd(" ", var->fd);
		ft_putnbr_fd(best_move->x, var->fd);
		ft_putendl_fd("", var->fd);
		return (best_move);
	}
	else if (var->token == 'O' && var->board_dimensions.columns > 40)
	{
		if (ft_strchr(var->board[0], 'O'))
			best_move = lowest_distance(var);
		else
		best_move = min_y(var);
	//	if (ft_strchr(var->board[var->board_dimensions.rows - 1], 'O'))
	//		best_move = lowest_distance(var);
		print_pm(var);
		var->placement.x = best_move->x;
		var->placement.y = best_move->y;
		ft_putstr_fd("Best Move: ", var->fd);
		ft_putnbr_fd(best_move->y, var->fd);
		ft_putstr_fd(" ", var->fd);
		ft_putnbr_fd(best_move->x, var->fd);
		ft_putendl_fd("", var->fd);
		return (best_move);

	}
	if (var->token == 'X' && var->board_dimensions.columns <= 40)
	{
	//	if (ft_strchr(var->board[0], 'X'))
	//		best_move = min_x(var);
	//	else
	//		best_move = min_y(var);
		best_move = lowest_distance(var);
		print_pm(var);
		var->placement.x = best_move->x;
		var->placement.y = best_move->y;
		ft_putstr_fd("Best Move: ", var->fd);
		ft_putnbr_fd(best_move->y, var->fd);
		ft_putstr_fd(" ", var->fd);
		ft_putnbr_fd(best_move->x, var->fd);
		ft_putendl_fd("", var->fd);
		return (best_move);
	}
	else if (var->token == 'X' && var->board_dimensions.columns > 40)
	{
/*		if (var->board[2][var->board_dimensions.columns - 1] != var->token)
		{
			best_move = go_northeast(var);
		}
	:	else
			best_move = max_x(var);*/
	//	if (var->board[var->board_dimensions.rows - 1][var->board_dimensions.columns - 1] == var->token)
	//		best_move = min_x(var);
		best_move = lowest_distance(var);
		print_pm(var);
		var->placement.x = best_move->x;
		var->placement.y = best_move->y;
		ft_putstr_fd("Best Move: ", var->fd);
		ft_putnbr_fd(best_move->y, var->fd);
		ft_putstr_fd(" ", var->fd);
		ft_putnbr_fd(best_move->x, var->fd);
		ft_putendl_fd("", var->fd);
		return (best_move);

	}
	return (best_move);	
}
