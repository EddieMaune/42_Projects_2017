/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:50:38 by emaune            #+#    #+#             */
/*   Updated: 2017/11/30 17:27:43 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_main			*init_store(t_main *var)
{
	var->input_head = (t_input*)malloc(sizeof(t_input));
	var->index = var->input_head;
	var->index->line_number = 1;
	var->index->line = NULL;
	var->index->prev = NULL;
	var->index->next = NULL;
	return (var);
}
