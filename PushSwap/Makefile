# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaune <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 16:42:04 by emaune            #+#    #+#              #
#    Updated: 2018/06/06 15:18:38 by emaune           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

PUSH_SWAP = push_swap

SRC_1 = checker.c

SRC_2 = push_swap.c

CC = gcc

LINKER = -Llibft -lft

CFLAGS = -Wall -Werror -Wextra

all:	$(CHECKER) $(PUSH_SWAP)

$(CHECKER):
	@make -C libft
	@$(CC)  $(SRC_1) $(LINKER) -o $(CHECKER)

$(PUSH_SWAP):
	@$(CC) $(SRC_2) $(LINKER) -o $(PUSH_SWAP)

clean:
	@rm -f $(NAME)

re:	clean
	@make

