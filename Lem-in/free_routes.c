/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_routes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:59:04 by emaune            #+#    #+#             */
/*   Updated: 2017/11/30 16:13:36 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_routes(t_route	*head)
{
	t_route		*temp;
	
	temp = head;
	while (temp)
	{
		free(temp->room);
		temp->room = NULL;
		if (temp->next)
		temp = temp->next;
		else
			break	;
		free(temp->prev);
	}
	free(temp);
	temp = NULL;
}
