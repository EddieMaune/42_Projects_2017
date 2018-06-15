/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:53:36 by emaune            #+#    #+#             */
/*   Updated: 2018/06/14 12:25:37 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	t_main	var;

	var.fd = open("text", O_RDWR);
	var.board = NULL;
	var.piece = NULL;
	var.read_board = 0;
	var.read_piece = 0;
	var.possible_moves = NULL;
	set_token(&var);
	read_and_play(&var);
	return (0);
}
