/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 12:28:29 by emaune            #+#    #+#             */
/*   Updated: 2018/08/12 15:57:11 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int             is_sorted_before_max(t_stack *b)
{
	t_stack     *i;
	t_stack     *j;

	i = b;
	while (i)
	{
		j = i->next;
		if (j)
			if (j->num == max_num(b))
				break ;
		while (j && j->num != max_num(b))
		{
			if (j->num > i->num)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}
/*
   int				get_min(t_stack *stack)
   {
   t_stack		*a;
   t_stack		*b;
   t_stack		*min;

   a = stack;
   min = a;
   while (a)
   {
   b = a->next;
   while (b)
   {
   if (min->num > b->num)
   {
   min = b;
   }
   b = b->next;
   }
   a = a->next;
   }
   return (min->num);
   }

   int				min_index(t_stack *stack)
   {
   int			i;
   int			min;

   i = 0;
   min = get_min(stack);
   while (stack)
   {
   if (stack->num == min)
   break ;
   i++;
   stack = stack->next;
   }
   return (i);
   }

   void			sort_big_stack(t_main *var)
   {
   while (1)
   {
   if (!stack_len(var->b) && is_sorted(var->a))
   {
   break ;
   }
   if (is_sorted(var->a))
   {
   ft_putendl("pa");
   push_a(var);
//	print_stack(var->a);
//					print_stack(var->b);

}
else
{
while (var->a->num != get_min(var->a))
{
if (min_index(var->a) > stack_len(var->a) / 2)
{
ft_putendl("rra");
rev_rotate_a(var);	
//	print_stack(var->a);
//	print_stack(var->b);
}
else
{
ft_putendl("ra");
rotate_a(var);
//	print_stack(var->a);
//	print_stack(var->b);
}
}
if (!is_sorted(var->a))
{
	ft_putendl("pb");
	push_b(var);
}
}
if (!is_sorted(var->a))
{
	//	print_stack(var->a);
	//	print_stack(var->b);
}
}
}*/

static t_stack		*get_min_dist(t_stack *stack)
{
	t_stack		*a;
	t_stack		*min;

	a = stack;
	min = a;
	while (a)
	{
		if (min->dist > a->dist)
			min = a;
		a = a->next;
	}
	return (min);
}

/*static int		max_num(t_stack *stack)
  {
  t_stack		*a;
  t_stack		*max;

  a = stack;
  max = a;
  while (a)
  {
  if (max->num < a->num)
  max = a;
  a = a->next;
  }
  return (max->num);
  }*/

void			max_to_top(t_main *var)
{
	t_stack		*b;

	b = var->b;
	if (get_index(b, max_num(b)) > stack_len(b) / 2 + 1)
	{
		while (var->b->num != max_num(var->b))
		{
			ft_putendl("rrb");
			rev_rotate_b(var);
			print_stack(var->a);
			print_stack(var->b);
		}
	}
	else
	{
		while (var->b->num != max_num(var->b))
		{
			ft_putendl("rb");
			rotate_b(var);
			print_stack(var->a);
			print_stack(var->b);
		}
	}
}

void			sort_big_stack(t_main *var)
{
	int		i;
	int		j;
	int		a_dist;
	int		b_dist;
	//int		k;
	int		x;
	t_stack		*min;

	i = 0;
	update_dist(var);
	print_stack(var->a);
	print_stack(var->b);
	x = 0;
	while (1)
	{
		update_dist(var);
		if (stack_len(var->b) && (!is_sorted_before_max(var->b) || !is_sorted_descending(max_ptr(var->b))))
		{
			ft_putendl("--------BROKEN------");
			exit(1);
		}
		if (x++ == 1000)
			break ;
		if (is_sorted(var->a) && !stack_len(var->b))
		{
			ft_putendl("Sorted");
			break ;
		}
		if (!stack_len(var->a)/*is_sorted(var->a) && stack_len(var->b) && stack_len(var->a) > 1*/)
		{
		//	ft_putendl("Stack B is sorted and stack A is empty");
			while (var->b->num != max_num(var->b))
			{
				if (get_index(var->b, max_num(var->b)) > stack_len(var->b) / 2 + 1)
				{
					ft_putendl("rrb");
					rev_rotate_b(var);
					print_stack(var->a);
					print_stack(var->b);
				}
				else
				{
					ft_putendl("rb");
					rotate_b(var);
					print_stack(var->a);
					print_stack(var->b);
								}
			}
			while (var->b)
			{
				ft_putendl("pa");
				push_a(var);
				print_stack(var->a);
				print_stack(var->b);
			}
			continue ;
		}
		min = get_min_dist(var->a);
		if (min)
		{
			if (!min->a_dist)
			{
			//	ft_putnbr(min->num);
			//	ft_putendl("");
			//	ft_putendl("Min already at top");
				if (!min->ri)
				{
					ft_putendl("pb");
					push_b(var);
					print_stack(var->a);
					print_stack(var->b);
					continue ;
				}
				if (min->ri == 1)
				{
					ft_putendl("pb");
					push_b(var);
					print_stack(var->a);
					print_stack(var->b);
					ft_putendl("sb");
					var->b = swap_b(var->b);
					update_dist(var);
					print_stack(var->a);
					print_stack(var->b);
					continue ;				
				}/*
					if (min->num < number_at_bottom(var->b))
					{
					ft_putendl("pb");
					push_b(var);
					print_stack(var->a);
					print_stack(var->b);
					ft_putendl("rb");
					rotate_b(var);
					print_stack(var->a);
					print_stack(var->b);
					continue ;	
					}*/
				i = 0;
			//	ft_putendl("Rotating Stack B");
				while (i < min->b_dist)
				{
					if (min->ri > stack_len(var->b) / 2)
					{
						ft_putendl("rrb");
						rev_rotate_b(var);
						print_stack(var->a);
						print_stack(var->b);
					}
					else
					{
						ft_putendl("rb");
						rotate_b(var);
						print_stack(var->a);
						print_stack(var->b);
					}
					i++;
				}
				continue ;
			}
		//	ft_putendl("");
			update_dist(var);
		//	ft_putnbr(min->num);
		//	ft_putchar('.');
		//	ft_putnbr(min->ri);
		//	ft_putendl("");
		//	ft_putendl("Lowest not on top of stack A");
			i = 0;
			j = 0;
			a_dist = min->a_dist;
			b_dist = min->b_dist;
			//if (min->a_dir == 'S')
			while (i < a_dist)
			{
				update_dist(var);
				if (min->a_dir == 'N' && min->ri != 0 && min->b_dir == 'N')
				{
					ft_putendl("rr");
					ra_and_rb(var);
					print_stack(var->a);
					print_stack(var->b);
					//	min->b_dist--;
					j++;
					i++;
					continue ;
				}
				if (min->a_dir == 'S' && min->b_dir == 'S' && min->ri != stack_len(var->b) && j < min->b_dist)
				{
					ft_putendl("rrr");
					rra_and_rrb(var);
					print_stack(var->a);
					print_stack(var->b);
					//min->b_dist--;
					j++;
					i++;
					continue ;
				}
				if (min->a_dir == 'N')
				{
					ft_putendl("ra");
					rotate_a(var);
					print_stack(var->a);
					print_stack(var->b);
				}
				if (min->a_dir == 'S')
				{
					ft_putendl("rra");
					rev_rotate_a(var);
					print_stack(var->a);
					print_stack(var->b);
				}
				i++;
			}
			update_dist(var);
			if (!min->ri && j == b_dist)
			{
				ft_putendl("pb");
				push_b(var);
				print_stack(var->a);
				print_stack(var->b);
				continue ;
			}
			if (min->ri == 1)
			{
				ft_putendl("pb");
				push_b(var);
				print_stack(var->a);
				print_stack(var->b);
				ft_putendl("sb");
				var->b = swap_b(var->b);
				update_dist(var);
				print_stack(var->a);
				print_stack(var->b);
				continue ;				
			}
		/*	if (min->ri == stack_len(var->b))
			{
				ft_putendl("pb");
				push_b(var);
				print_stack(var->a);
				print_stack(var->b);
				ft_putendl("rb");
				rotate_b(var);
				print_stack(var->a);
				print_stack(var->b);
				continue ;	
			}*/
//	ft_putendl("Altern Rotating Stack B");
				while (i < min->b_dist)
				{
					if (min->ri > stack_len(var->b) / 2)
					{
						ft_putendl("rrb");
						rev_rotate_b(var);
						print_stack(var->a);
						print_stack(var->b);
					}
					else
					{
						ft_putendl("rb");
						rotate_b(var);
						print_stack(var->a);
						print_stack(var->b);
					}
					i++;
				}
				continue ;
/*
			i = 0;
			k = 0;
			ft_putendl("Shifting Stack B");
			while (i < min->b_dist - j)
			{
				if (min->ri > stack_len(var->b) / 2)
				{
					ft_putendl("rrb");
					rev_rotate_b(var);
					print_stack(var->a);
					print_stack(var->b);
					k = 1;
				}
				else
				{
					ft_putendl("rb");

					rotate_b(var);
					print_stack(var->a);
					print_stack(var->b);
				}
				i++;
				if (i == min->b_dist - j)
				{
					ft_putendl("pb");
					push_b(var);
					print_stack(var->a);
					print_stack(var->b);
					i = 0;
					while (i < min->b_dist + k)
					{
						if (min->ri > stack_len(var->b) / 2 + 1)
						{
							ft_putendl("rb");
							rotate_b(var);
							print_stack(var->a);
							print_stack(var->b);	
						}
						else
						{
							ft_putendl("rrb");
							rev_rotate_b(var);
							print_stack(var->a);
							print_stack(var->b);
						}
						i++;
					}
				}
			}*/

		}
	}
}
