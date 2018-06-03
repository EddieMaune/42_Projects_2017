/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:46:13 by emaune            #+#    #+#             */
/*   Updated: 2017/11/23 09:16:34 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		error_check_file(t_input *file)
{
	while (file)
	{
		if (file->line_number == 1)
		{
			file = err_check_1(file);
			continue	;
		}
		else
		{
			file = err_check_2(file);
			continue	;
		}
		file = file->next;
	}
}
