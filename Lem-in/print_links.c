/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:45:57 by emaune            #+#    #+#             */
/*   Updated: 2017/11/25 11:20:28 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_links(t_main *var)
{
	int		i;

	i = 0;
	var->r_index = var->room_head;
	while (var->r_index)
	{
		i = 0;
		ft_putstr("\x1b[34;1mRoom \x1b[36;1m");
		ft_putstr(var->r_index->room_name);
		ft_putendl("\x1b[34;1m is linked to: \x1b[0m");
		while (i < var->r_index->total_links)
		{
			ft_putstr("\x1b[36m");
			ft_putstr(var->r_index->links[i]->room_name);
			ft_putchar(',');
			i++;
			ft_putstr("\x1b[0m");
		}
		ft_putendl("");
		var->r_index = var->r_index->next;
	}
}
