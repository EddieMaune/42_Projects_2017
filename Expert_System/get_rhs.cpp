/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rhs.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 15:55:10 by emaune            #+#    #+#             */
/*   Updated: 2018/05/24 11:13:52 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

char		*get_rhs(char	**rule)
{
	int		i;
	char	*rhs;
	char	*temp;

	i = 0;
	rhs = ft_strnew(0);
	while (rule[i])
	{
		if (!ft_strcmp(rule[i], "<=>") || !ft_strcmp(rule[i], "=>"))
		{
			i++;
			while (rule[i])
			{
				temp = rhs;
				rhs = ft_strjoin(temp, rule[i]);
				free(temp);
				i++;	
			}
			break	;
		}
		i++;
	}
	return (rhs);
}
