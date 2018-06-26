# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaune <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 16:42:04 by emaune            #+#    #+#              #
#    Updated: 2018/06/25 13:19:53 by emaune           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = main.c set_token.c get_board_dimensions.c malloc_board.c update_board.c\
	 get_piece_dimensions.c malloc_piece.c update_piece.c read_board.c\
	 read_piece.c find_valid_moves.c find_valid_moves_ext.c\
	 select_best_move.c place_piece.c enemy_detection.c\
	 read_and_play.c\
	 O_strategy.c X_strategy.c update_graphic.c\
	 draw_stuff.c misc.c

CC = gcc

LINKER = -Llibft -lft

CFLAGS = -Wall -Werror -Wextra -lSDL2 -I include/ -I include/SDL2/ -L ~/lib

all:	$(NAME)

$(NAME):
	@make -C libft
	gunzip -c SDL2-2.0.7.tar.gz | tar xf -
	cd SDL2-2.0.7; \
	mkdir build; \
	cd build; \
	../configure; \
	make
	mkdir -p ~/lib/
	cp SDL2-2.0.7/build/build/.libs/libSDL2-2.0.0.dylib ~/lib/
	ln -F -s ~/lib/libSDL2-2.0.0.dylib ~/lib/libSDL2.dylib
	mkdir -p include/SDL2
	cp SDL2-2.0.7/include/*.h include/SDL2/
	@$(CC) $(CFLAGS) $(SRC) $(LINKER) -o $(NAME)

fclean:
	rm -rf $(NAME)
	rm -rf include/SDL2
	rm -rf SDL2-2.0.7

clean:
	@rm -f $(NAME)

re:	clean
	@make

co:
	@$(CC) $(SRC) $(CFLAGS) $(LINKER) -o $(NAME)

