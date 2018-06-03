/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goes_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:28:14 by emaune            #+#    #+#             */
/*   Updated: 2017/11/30 12:43:08 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				goes_back(t_main *var, t_route	*r)
{
	t_route	*temp;
	t_route	*temp2;

	char	*t;
	char	*t2;
	char	*t3;
	char	c;
	int		i;

	temp = var->rh;
//	ft_putstr("\x1b[32;1m");
//	ft_putendl(r->room);
//	ft_putstr("\x1b[0m");
	while (temp)
	{
		if (!ft_strcmp(r->room, temp->room))
		{
		//	ft_putstr(r->room);
		//	ft_putstr("==");
		//	ft_putendl(temp->room);
			t = ft_strchr(r->room,'-') + 1;
			temp = temp->next;
			while (temp)
			{
				i = 0;
				while (temp->room[i])
				{
					if (temp->room[i] == '-')
					{
						c = temp->room[i];
						temp->room[i] = '\0';
						break	;
					}
					i++;
				}
				t2 = ft_strdup(temp->room);
				temp->room[i] = c;
				if (!ft_strcmp(t, t2))
				{
					t = ft_strchr(temp->room, '-') + 1;
				//	ft_putendl(t);
				//	ft_putendl(temp->room);
					temp2 = var->rh;
					while (temp2)
					{
						if (ft_strstr(temp2->room, t2))
						{
							return (1);
						}
						t3 = ft_strchr(temp2->room, '-') + 1;
						if (!ft_strcmp(t3, t))
						{
						//	ft_putendl("\x1b[34;1mok\x1b[0m");
							return (0);
						}
						temp2 = temp2->next;
					}
				}
				free(t2);
				temp = temp->next;
			}
			break	;
		}
		temp = temp->next;
	}
	//ft_putendl("back");
	return (1);
}	
