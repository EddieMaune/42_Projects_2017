/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:53:36 by emaune            #+#    #+#             */
/*   Updated: 2018/06/11 16:47:33 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	char	*line;
	int		fd;
	t_input	*input_head;
	t_input	*input_index;
	t_input *input_temp;

	fd = open("text", O_RDWR);
	input_head = (t_input*)malloc(sizeof(t_input));
	input_index = input_head;
	input_index->prev = NULL;
	input_index->next = NULL;
	while (get_next_line(0, &line) > 0)
	{
		input_index->line = ft_strdup(line);
		input_index->next = (t_input*)malloc(sizeof(t_input));
		input_temp = input_index;
		input_index = input_index->next;
		input_index->prev = input_temp;
		ft_putendl_fd(line, fd);
		free(line);
	}
	ft_putendl("8 2");
	input_index->next = NULL;
	input_index = input_head;
	while (input_index)
	{
		ft_putendl(input_index->line);
		input_index = input_index->next;
	}
	return (0);
}
