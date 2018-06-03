/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:59:08 by emaune            #+#    #+#             */
/*   Updated: 2017/12/01 15:45:05 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_links(t_main *var)
{
	t_link	*temp;

	temp = var->l_head;
	while (temp)
	{
		free(temp->room1);
		free(temp->room2);
		if (temp->next)
		{
			temp = temp->next;
			free(temp->prev);
		}
		else
			break ;
	}
	free(temp);
}
