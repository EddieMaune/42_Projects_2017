/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_rule.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:01:26 by emaune            #+#    #+#             */
/*   Updated: 2018/05/24 15:34:14 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"


int				rule_has_initial_fact(t_facts *facts, char **rule)
{
	t_facts		*index;
	char		*lhs;
	int			i;

	i = 0;
	lhs = get_lhs(rule);

	while (lhs[i])
	{
		index = facts;
		if (ft_isupper(lhs[i]))
		{
			while (index)
			{
				if (index->fact == lhs[i])
					if (index->condition)
					{
						free(lhs);
						return (1);
					}
				index = index->next;
			}
		}
		i++;
	}
	free(lhs);
	return (0);
}

int				has_dup_rule(t_input *input)
{
	t_input		*x;
	t_input		*y;
	char		*rhs_x;
	char		*rhs_y;

	x = input;
	while (x)
	{
		if (x->rule)
		{
			rhs_x = get_rhs(x->rule);
			y = x->next;
			if (y->rule)
			{
				rhs_y = get_rhs(y->rule);
				if (!ft_strcmp(rhs_x, rhs_y))
					return (1);
				break	;
			}
		}
		x = x->next;
	}
	return (0);
}

t_input			*remove_dup_rule(t_input *input, t_facts *facts)
{
	t_input		*index;
	int			ruleset_has_init_fact;

	index = input;
	ruleset_has_init_fact = 0;
	if (has_dup_rule(input))
	{
		while (index)
		{
			if (index->rule)
			{
				if (rule_has_initial_fact(facts, index->rule))
				{
					ruleset_has_init_fact = 1;
					break	;
				}
			}
			index = index->next;
		}
		if (ruleset_has_init_fact)
		{
			index = input;
			while (index)
			{
				if (index->rule)
				{
					if (!rule_has_initial_fact(facts, index->rule))
					{
						free_rule(index->rule);
						index->rule = NULL;
						break	;
					}
				}
				index = index->next;
			}
		}
	}
	return (input);
}
