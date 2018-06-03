/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn-calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:22:08 by mmpofu            #+#    #+#             */
/*   Updated: 2018/05/25 10:55:20 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "rpn_calc.h"

static int		ft_isnum(char c)
{
    if (c >= '0' && c <= '1')
        return (1);
    return (0);
}

static char	*ft_strnum(char *str, int index)
{
    int		len;
    int		sign;
    char	*strnum;
    
    len = 1;
    sign = 0;
    if (str[index] == '-')
    {
        sign = 1;
        index++;
    }
    while (ft_isnum(str[index]))
    {
        len++;
        index++;
    }
    strnum = (char*)malloc(sizeof(*strnum) * len + sign);
    strnum[len + sign] = '\0';
    while (len--)
        strnum[len + sign] = str[index--];
    if (sign)
        strnum[0] = '-';
    return (strnum);
}

static void	ft_addnum(int nbr)
{
    temp = head;
    if (temp == NULL)
    {
        new_nbr = (struct rpn*)malloc(sizeof(*new_nbr));
        new_nbr->next = NULL;
        head = new_nbr;
        head->prev = NULL;
        head->nbr = nbr;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        new_nbr = (struct rpn*)malloc(sizeof(*new_nbr));
        new_nbr->next = NULL;
        temp->next = new_nbr;
        new_nbr->prev = temp;
        new_nbr->nbr = nbr;
    }
}

int		ft_issign(char c)
{
    if (c == '+' || c == '|' || c == '^')
        return (1);
    return (0);
}

void	ft_remove()
{
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void	ft_domath(char sign)
{
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (sign == '+')
        temp->prev->nbr = temp->prev->nbr &	temp->nbr;
    if (sign == '|')
        temp->prev->nbr = temp->prev->nbr |	temp->nbr;
    if (sign == '^')
        temp->prev->nbr = temp->prev->nbr ^ temp->nbr;
    ft_remove();
}

int		ft_count()
{
    int		count;
    
    count = 0;
    if (head == NULL)
        return (0);
    if (head->next == NULL)
        return (1);
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return (count);
}

char	*my_converter(char *s)
{
	int		i;
	int		k;
	int		len;
	char	*str;

	i = 0;
	k = 0;
	len = 0;
	while (s[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len));
	while (s[i])
	{
		if (s[i] == '!' && s[i - 2] == '1')
		{
			 s[i - 2] = '0';
		}
		else if (s[i] == '!' && s[i - 2] == '0')
		{
			s[i - 2] = '1';
		}
		i++;
	}
	i  = 0;
	while (s[i])
	{
		if (s[i] != '!')
		{
			str[k] = s[i];
			k++;
		}
		i++;
	}
	return(str);
}

int			rpn_calc(char *s)
{
	 int		num;
        int		index;
		int		len;
        int		numcheck;
		int		ret;
		char	*str;
        
		len = ft_strlen(s);
		str = (char*)malloc(sizeof(char) * len);
        head = NULL;
        numcheck = 0;
        index = 0;
		str = my_converter(s);
        while (str[index])
        {
            if (head != NULL)
            {
                temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                numcheck = temp->nbr;
            }
            if (ft_isnum(str[index]))
            {
                num = ft_atoi(ft_strnum(str, index));
                if (num > 2147483647)
                {
                    printf("Error\n");
                    return (-1);
                }
                ft_addnum(num);
                while (ft_isnum(str[index]))
                    index++;
            }
            if (ft_issign(str[index]))
            {
                if (ft_count() < 2 || ((str[index] == '/' || str[index] == '%') && numcheck == 0))
                {
                    printf("Error\n");
                    return (-1);
                }
                ft_domath(str[index]);
                index++;
            }
            if (str[index] == ' ')
               index++;
			else
				index++;

        }
        if (ft_count() != 1)
        {
			printf("%d\n", head->nbr);
            printf("Error\n");
            return (-1);
        }
		ret = head->nbr;
		free(head);
		return (ret);
}
