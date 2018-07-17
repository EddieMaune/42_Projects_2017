/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_best_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:33:38 by emaune            #+#    #+#             */
/*   Updated: 2018/07/17 09:02:31 by emaune           ###   ########.fr       */
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

t_coordinates				*o_algo_small_medium_board(t_main *var)
{
	t_coordinates			*best_move;

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

t_coordinates				*o_algo_large_board(t_main *var)
{
	t_coordinates			*best_move;

	if (var->board[var->board_dimensions.rows - 1][0] != 'O')
		best_move = go_southwest(var);
	else if (!ft_strchr(var->board[var->board_dimensions.rows / 2], 'O'))
		best_move = go_northeast(var);
	else if (var->board[var->board_dimensions.rows / 2][0] != 'O')
		best_move = min_x(var);
	else
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

t_coordinates				*x_algo_small_medium_board(t_main *var)
{
	t_coordinates			*best_move;
	static int				i = 1;

	best_move = lowest_distance(var);
	if (!reached_border(var))
	{
		if (i % 2 == 0 && best_move->distance >= 15)
			best_move = min_x(var);
	}
	else if (i % 2 == 0 && best_move->distance >= 10)
		best_move = go_northeast(var);
	i++;
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

t_coordinates				*x_algo_large_board(t_main *var)
{
	t_coordinates			*best_move;

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

t_coordinates				*select_best_move(t_main *var)
{
	if (var->token == 'O' && var->board_dimensions.columns <= 40)
		return (o_algo_small_medium_board(var));
	else if (var->token == 'O' && var->board_dimensions.columns > 40)
		return (o_algo_large_board(var));
	if (var->token == 'X' && var->board_dimensions.columns <= 40)
		return (x_algo_small_medium_board(var));
	else if (var->token == 'X' && var->board_dimensions.columns > 40)
		return (x_algo_large_board(var));
	return (NULL);
}
