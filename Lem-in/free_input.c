/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:38:28 by emaune            #+#    #+#             */
/*   Updated: 2017/11/22 18:08:23 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			free_input(t_input **file)
{
	t_input *index;

	index = *file;
	while (index->next)
	{
		free(index->line);
		index->line = NULL;
		index = index->next;
		free(index->prev);
		index->prev = NULL;
	}
	free(index->line);
	index->line = NULL;
	free(index);
	index = NULL;
	return (1);
}
