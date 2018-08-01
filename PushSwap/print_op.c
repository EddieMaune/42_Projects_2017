/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 11:28:29 by emaune            #+#    #+#             */
/*   Updated: 2018/07/31 11:38:45 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void     sb_rb(t_main *var, int *f)
{
    int         flag;

    flag = *f;

    if (is_nsorted(var->b, 2) && !flag)
    {
        ft_putendl("sb");
        var->b = swap_b(var->b);
        //  print_stack(var->a);
        //  print_stack(var->b);
        *f = 1;
    }
    if (var->b->num < number_at_bottom(var->b) && !flag)
    {
        ft_putendl("rb");
        rotate_b(var);
        //  print_stack(var->a);
        //  print_stack(var->b);
        *f = 1;
    }
}

void     rrb_pa(t_main *var, int *f)
{
    int         flag;

    flag = *f;
    if (var->b->num < number_at_bottom(var->b) && !flag)
    {
        ft_putendl("rrb");
        rev_rotate_b(var);
        //  print_stack(var->a);
        //  print_stack(var->b);
        *f = 1;
    }
    if (!flag)
    {
        ft_putendl("pa");
        push_a(var);
        //  print_stack(var->a);
        //  print_stack(var->b);
        *f = 1;
    }
}

void     ra_rra(t_main *var, int *f)
{
    int         flag;

    flag = *f;
    if (var->a->num > number_at_bottom(var->a) &&
            var->a->num > var->a->next->num &&
            !flag)
    {
        ft_putendl("ra");
        rotate_a(var);
        //  print_stack(var->a);
        //  print_stack(var->b);
        *f = 1;
    }
    if (var->a->num > number_at_bottom(var->a) &&   !flag)
    {
        ft_putendl("rra");
        rev_rotate_a(var);
        //  print_stack(var->a);
        //  print_stack(var->b);
        *f = 1;
    }
}

void     rr_rrr(t_main *var, int *f)
{
    int         flag;

    flag = *f;
    if (stack_len(var->b) > 1 &&
            var->a->num > number_at_bottom(var->a) &&
            var->a->num > var->a->next->num &&
            var->b->num < number_at_bottom(var->b) &&
            var->b->num < var->b->next->num &&
            !flag)
    {
        ft_putendl("rr");
        ra_and_rb(var);
        //  print_stack(var->a);
        //  print_stack(var->b);
        flag = 1;
    }
    if (stack_len(var->b) > 1 &&
            var->a->num > number_at_bottom(var->a) &&
            var->b->num < number_at_bottom(var->b) &&
            !flag)
    {
        ft_putendl("rrr");
        rra_and_rrb(var);
        //  print_stack(var->a);
        //  print_stack(var->b);
        flag = 1;
    }
}

void         sa_ss(t_main *var, int *f)
{
    int             flag;

    flag = *f;
    if (stack_len(var->b) > 1 && is_nsorted(var->b, 2) && is_nsorted_descending(var->a, 2) && !flag)
    {
        ft_putendl("ss");
        sa_and_sb(var,var->a, var->b);
        //  print_stack(var->a);
        //  print_stack(var->b);
        flag = 1;
    }
    if (is_nsorted_descending(var->a, 2) && !flag)
    {
        ft_putendl("sa");
        var->a = swap_a(var->a);
        //  print_stack(var->a);
        //  print_stack(var->b);
        flag = 1;
    }
}
