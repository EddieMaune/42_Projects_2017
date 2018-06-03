# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaune <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 16:42:04 by emaune            #+#    #+#              #
#    Updated: 2017/11/30 18:58:19 by emaune           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c read_file.c store_file.c print_file.c init_store.c free_split.c\
	  error_check_file.c check_ants.c is_room.c is_comment.c is_link.c\
	  err_check_1.c err_check_2.c is_valid_start_end.c print_error.c\
	  free_input.c create_rooms.c print_rooms.c init_room.c store_links.c\
	  link_rooms.c print_links.c error_check_links.c error_check_rooms.c\
	  count_routes.c links_have_dup.c store_routes.c\
	  reset_flag.c march_ants.c room_to_route.c room_leads_to_end.c\
	  remove_dup_route.c goes_back.c free_routes.c free_rooms.c free_links.c\
	  loop_2.c

CC = gcc

LINKER = -Llibft -lft

CFLAGS = -g -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):
	@make -C libft
	@$(CC)  $(SRC) $(LINKER) -o $(NAME)

clean:
	@rm -f $(NAME)

re:	clean
	@make
