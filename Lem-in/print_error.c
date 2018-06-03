/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:56:47 by emaune            #+#    #+#             */
/*   Updated: 2017/11/30 17:56:41 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_error(t_input *file)
{
	ft_putstr("\x1b[31mError: Line-");
	ft_putnbr(file->line_number);
	ft_putstr("\nInvalid line - \"");
	ft_putstr(file->line);
	ft_putstr("\"\x1b[0m");
	while (file->prev)
	{
		file = file->prev;
	}
	free_input(&file);
	exit(EXIT_FAILURE);
}
