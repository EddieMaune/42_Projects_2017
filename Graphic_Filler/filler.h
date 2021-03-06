/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:53:45 by emaune            #+#    #+#             */
/*   Updated: 2018/07/12 12:14:19 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "include/header.h"

typedef struct				s_dimensions
{
	int						rows;
	int						columns;
}							t_dimensions;

typedef struct				s_coordinates
{
	int						x;
	int						y;
	int						distance;
	struct s_coordinates	*next;
	struct s_coordinates	*prev;
}							t_coordinates;

typedef struct				s_main
{
	char					*line;
	int						fd;
	char					token;
	char					**board;
	char					**piece;
	t_dimensions			board_dimensions;
	t_dimensions			piece_dimensions;
	t_coordinates			placement;
	int						read_board;
	int						read_piece;
	t_coordinates			*possible_moves;
	t_coordinates			*index;
	t_coordinates			*temp;
	SDL_Renderer			*ren;
	SDL_Event				event;
	int						quit;
	int						empty_piece_columns;
	int						empty_piece_rows;
}							t_main;

void						set_token(t_main *var);
void						read_and_play(t_main *var);
void						read_board(t_main *var);
void						read_piece(t_main *var);
t_dimensions				get_board_dimensions(char *line);
char						**malloc_board(t_main *var);
char						**update_board(t_main *var);
t_dimensions				get_piece_dimensions(char *line);
char						**malloc_piece(t_main *var);
char						**update_piece(t_main *var);
int							find_valid_moves(t_main *var);
int							piece_rows_readjustment(t_main *var);
int							piece_columns_readjustment(t_main *var);
int							piece_rows_readjustment_2(t_main *var);
int							piece_columns_readjustment_2(t_main *var);
void						place_piece(t_main *var);
int							enemy_detection(t_main *var, t_coordinates *vector);
t_coordinates				*select_best_move(t_main *var);
t_coordinates				*go_northeast(t_main *var);
t_coordinates				*go_southwest(t_main *var);
t_coordinates				*min_y(t_main *var);
t_coordinates				*min_x(t_main *var);
t_coordinates				*max_x(t_main *var);
t_coordinates				*lowest_distance(t_main *var);
void						update_graphic(SDL_Renderer *ren, t_main *var);
void						fill_rect(SDL_Renderer *ren, int x, int y, int w, int h);

#endif
