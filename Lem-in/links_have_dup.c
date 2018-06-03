/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_have_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 10:29:02 by emaune            #+#    #+#             */
/*   Updated: 2017/12/01 15:42:35 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_l(t_link *links, t_link *temp)
{
	ft_putstr(links->room1);
	ft_putchar('-');
	ft_putendl(links->room2);
	ft_putstr(temp->room1);
	ft_putchar('-');
	ft_putendl(temp->room2);
}

int			links_have_dup(t_link *links)
{
	t_link	*temp;

	while (links)
	{
		temp = links->next;
		while (temp)
		{
			if (!ft_strcmp(links->room1, temp->room1)
					&& !ft_strcmp(links->room2, temp->room2))
			{
				print_l(links, temp);
				return (1);
			}
			if (!ft_strcmp(links->room1, temp->room2)
					&& !ft_strcmp(links->room2, temp->room1))
			{
				print_l(links, temp);
				return (1);
			}
			temp = temp->next;
		}
		links = links->next;
	}
	return (0);
}
