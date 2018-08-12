# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaune <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 16:42:04 by emaune            #+#    #+#              #
#    Updated: 2018/08/12 11:30:15 by emaune           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

PUSH_SWAP = push_swap

SRC_1 = main_checker.c check_arguments.c init_stacks.c store_arguments.c\
		print_stack.c count_args.c push_arguments_to_stack.c free_stack.c\
		has_dups.c error_check_stack.c stack_len.c swap.c push.c rotate.c\
		rev_rotate.c is_sorted.c read_instructions.c

SRC_2 = main_push_swap.c check_arguments.c init_stacks.c store_arguments.c\
		print_stack.c count_args.c push_arguments_to_stack.c free_stack.c\
	   	has_dups.c error_check_stack.c stack_len.c is_sorted.c sort_stack.c\
		swap.c rotate.c rev_rotate.c push.c number_at_bottom.c\
	   	sort_small_stack.c print_op.c sort_big_stack.c dist_to_sort.c\
	   	update_dist.c lowest_distance.c min_max.c get_index.c

CC = gcc 

LINKER = -Llibft -lft

CFLAGS = -Wall -Werror -Wextra

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER):
	@$(MAKE) -C libft
	@$(CC)  $(SRC_1) $(LINKER) $(CFLAGS) -o $(CHECKER)

$(PUSH_SWAP):
	@$(MAKE) -C libft
	@$(CC) $(SRC_2) $(LINKER) $(CFLAGS) -o $(PUSH_SWAP)

clean:
	@rm -f $(CHECKER)
	@rm -f $(PUSH_SWAP)

re:	clean
	@make

