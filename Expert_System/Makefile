# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaune <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 16:42:04 by emaune            #+#    #+#              #
#    Updated: 2018/05/24 12:26:10 by emaune           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = expert_system

SRC = main.cpp store_input.cpp free_store_input.cpp split_rule.cpp check_rule_validity.cpp\
	  init_facts.cpp init_known_facts.cpp check_brackets.cpp is_fact.cpp\
	  standardize_string.cpp get_lhs.cpp get_rhs.cpp infix_to_postfix.cpp\
	  postfix_to_bit.cpp inference_engine.cpp rpn_calc.cpp put_hr.cpp get_rule.cpp\
	  logo.cpp remove_rule.cpp

CC = g++

LINKER = -Llibft -lft

CFLAGS = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):
	@make -C libft
	@$(CC)  $(SRC) $(LINKER) -o $(NAME)

clean:
	@rm -f $(NAME)

re:	clean
	@make

