/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:36:36 by emaune            #+#    #+#             */
/*   Updated: 2018/06/10 16:39:46 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_main
{
	t_stack			*a;
	t_stack			*b;
	char			**args;
	int				ac;
	int				arg_is_string;
}					t_main;

void				init_stacks(int argc, char **argv, t_main *var);
void				check_if_args_are_ints(int argc, char **argv, int ais);
void				print_stack(t_stack *stack);
t_stack				*store_arguments(t_stack *a, int argc, char **argv, int ais);

#endif
