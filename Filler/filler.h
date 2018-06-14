/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:53:45 by emaune            #+#    #+#             */
/*   Updated: 2018/06/14 11:22:57 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct				s_dimensions
{
	int						rows;
	int						columns;
}							t_dimensions;

typedef struct				s_coordinates
{
	int						x;
	int						y;
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
void						find_valid_moves(t_main *var);
void						place_piece(t_main *var);
#endif
