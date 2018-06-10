/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:34:38 by emaune            #+#    #+#             */
/*   Updated: 2018/06/07 12:45:21 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnum(char *number)
{
	int		i;

	i = 0;
	if (ft_isdigit(number[i]) || number[i] == '-')
	{
		i++;
		while (number[i])
		{
			if (!ft_isdigit(number[i]))
				return (0);
			i++;
		}
		return (1);
	}
	else
		return (0);
}
