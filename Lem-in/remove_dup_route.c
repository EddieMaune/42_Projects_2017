/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:47:31 by emaune            #+#    #+#             */
/*   Updated: 2017/11/30 16:46:22 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


static int		is_dup(char *s1, char *s2)
{
	char	*temp;
	char	*f1;
	char	*f2;
	char	c;

	c = *ft_strchr(s1, '-');
	temp = ft_strchr(s1, '-');
	*temp = '\0';
	f1 = ft_strdup(s1);
	*temp = c;
	c = *ft_strchr(s2, '-');
	temp = ft_strchr(s2, '-');
	*temp = '\0';
	f2 = ft_strdup(s2);
	*temp = c;
	if ((!ft_strcmp(f1, f2) && !ft_strcmp(ft_strchr(s1, '-') + 1, ft_strchr(s2, '-') + 1))
					|| (!ft_strcmp(f1, ft_strchr(s2, '-') + 1)
					&& !ft_strcmp(f2, ft_strchr(s1, '-') + 1)))
	{

		free(f1);
		free(f2);
		return (1);
	}
	free(f1);
	free(f2);
	return (0);
}

void			remove_dup_route(t_main *var)
{
	t_route	*x;
	t_route	*y;
	t_route *temp;

	var->r = var->rh;
	y = var->r;
	while (y && y->next)
	{
		x = y->next;
		while (x && x->next)
		{
			if (is_dup(x->room, y->room))
			{

			//	ft_putendl("\x1b[34;1mFOUND DUP.");
			//	ft_putendl(x->room);
			//	ft_putendl(y->room);
			//	ft_putstr("\x1b[0m");
			//	exit(EXIT_FAILURE)	;
				temp = x->next;
			//ft_putstr("Current:");	ft_putendl(x->next->room);
				if (x->prev)
					x = x->prev;
			//	if (&(x->next))
			//		free(x->next);
			//	ft_putstr("New Current:");ft_putendl(x->next->room);
				x->next = temp;
			}
			x = x->next;
		}
		y = y->next;
	}
}
