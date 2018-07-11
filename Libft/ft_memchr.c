/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 07:55:52 by emaune            #+#    #+#             */
/*   Updated: 2018/06/28 10:54:38 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *str, unsigned int c, unsigned int n)
{
	unsigned int	i;
	char			*nstr;

	i = 0;
	nstr = (char*)str;
	while (i < n)
	{
		if (*(nstr + i) == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
