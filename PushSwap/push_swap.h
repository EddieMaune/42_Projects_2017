/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:36:36 by emaune            #+#    #+#             */
/*   Updated: 2018/07/31 15:42:20 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_stack
{
	int				num;
	int				dist;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_main
{
	t_stack			*a;
	t_stack			*b;
	char			**args;
	int				ac;
	int				is_split;
	char			*line;
}					t_main;

/*
** Initialize stack a and error check arguments/stack
*/

int					count_args(char **args);
void				check_if_args_are_ints(t_main *var, int argc, char **argv);
t_stack				*store_arguments(t_stack *a, int argc, char **argv);
void				init_stacks(t_main *var);
void				push_arguments_to_stack(t_main *var, int argc, char **argv);
int					has_dups(t_stack *stack);
void				free_stack(t_stack *stack);
void				error_check_stack(t_main *var);

/*
**	Operations
*/

int					stack_len(t_stack *stack);
t_stack				*swap_a(t_stack *a);
t_stack				*swap_b(t_stack *b);
void				sa_and_sb(t_main *var, t_stack *a, t_stack *b);
void				push_a(t_main *var);
void				push_b(t_main *var);
void				rotate_a(t_main *var);
void				rotate_b(t_main *var);
void				rev_rotate_a(t_main *var);
void				rev_rotate_b(t_main *var);
void				ra_and_rb(t_main *var);
void				rra_and_rrb(t_main *var);
int					is_sorted(t_stack *stack);
int					is_nsorted(t_stack *stack, int len);
int					is_sorted_descending(t_stack *stack);
int					is_nsorted_descending(t_stack *stack, int len);
void				print_stack(t_stack *stack);
void				rev_print_stack(t_stack *stack);
void				read_instructions(t_main *var);
void				sort_stack(t_main *var);
void				sort_small_stack(t_main *var);
void				sort_big_stack(t_main *var);
int					number_at_bottom(t_stack *stack);
void				sb_rb(t_main *var, int *f);
void				rrb_pa(t_main *var, int *f);
void				ra_rra(t_main *var, int *f);
void				sa_ss(t_main *var, int *f);
void				rr_rrr(t_main *var, int *f);
t_stack				*link_at_bottom(t_stack *stack);
int					dist_to_top(t_stack *stack, int num);
void				update_dist(t_main *var);
int					dist_to_sort(t_stack *stack, int num);
int					lowest_distance(t_stack *stack);

#endif
