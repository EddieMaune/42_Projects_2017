/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lhs.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 10:03:26 by emaune            #+#    #+#             */
/*   Updated: 2018/05/24 11:12:05 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

char	*get_lhs(char **rule)
{
	int		i;
	char	*lhs;
	char	*temp;

	i = 0;
	lhs = ft_strnew(0);
	while (rule[i])
	{
		if (!ft_strcmp(rule[i], "=>") || !ft_strcmp(rule[i], "<=>"))
			break	;
		else
		{
			temp = lhs;
			lhs = ft_strjoin(temp, rule[i]);
			free(temp);
		}
		i++;
	}
	return (lhs);
}
