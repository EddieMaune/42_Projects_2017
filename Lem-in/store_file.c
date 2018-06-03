/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:31:44 by emaune            #+#    #+#             */
/*   Updated: 2017/11/30 17:48:54 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_input	*init_line(t_input *file, t_input *temp, char *line)
{
	file->line = ft_strdup(line);
	temp = file;
	file->next = (t_input*)malloc(sizeof(t_input));
	file = file->next;
	file->prev = temp;
	temp = NULL;
	file->line_number = file->prev->line_number + 1;
	return (file);
}

static void		*print_err(t_input *file)
{
	free(file);
	ft_putendl("\x1b[31mError: File is empty\x1b[0m");
	exit(EXIT_FAILURE);
}

t_input			*store_file(int fd, char *line, t_input *file)
{
	t_input		*temp;
	int			is_empty;

	is_empty = 1;
	while (get_next_line(0, &line))
	{
		is_empty = 0;
		if (is_comment(line))
		{
			free(line);
			continue	;
		}
		file = init_line(file, temp, line);
		free(line);
	}
	if (is_empty)
		print_err(file);
	file = file->prev;
	free(file->next);
	file->next = NULL;
	while (file->prev)
		file = file->prev;
	return (file);
}
