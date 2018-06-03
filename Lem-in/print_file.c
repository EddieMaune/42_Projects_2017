/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:50:51 by emaune            #+#    #+#             */
/*   Updated: 2017/11/29 14:09:25 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		print_file(t_input *file)
{
	if (!file)
	{
		ft_putstr("\x1b[31mError: File could not be printed\x1b[0m");
		return (-1);
	}
	while (file)
	{
		if (file->line)
			ft_putendl(file->line);
		else
		{
			ft_putstr("\x1b[31;1mError - Line: ");
			ft_putnbr(file->line_number);
			ft_putchar('\n');
			ft_putendl("Link-list is invalid - File cannot be printed.\x1b[0m");
			return (-1);
		}
		file = file->next;
	}
	ft_putendl("\n\n");
	return (0);
}
