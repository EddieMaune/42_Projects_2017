# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaune <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 16:42:04 by emaune            #+#    #+#              #
#    Updated: 2018/06/15 13:00:10 by emaune           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = main.c set_token.c get_board_dimensions.c malloc_board.c update_board.c\
	 get_piece_dimensions.c malloc_piece.c update_piece.c read_board.c\
	 read_piece.c find_valid_moves.c select_best_move.c place_piece.c\
	  read_and_play.c\
	 O_strategy.c X_strategy.c

CC = gcc

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

