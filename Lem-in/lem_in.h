/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:29:39 by emaune            #+#    #+#             */
/*   Updated: 2017/12/01 18:21:02 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_input
{
	char			*line;
	int				line_number;
	struct s_input	*next;
	struct s_input	*prev;
}					t_input;

typedef	struct		s_rooms
{
	char			*room_name;
	int				total_links;
	int				i;
	int				flag;
	int				is_start;
	int				is_end;
	int				ants;
	char			*ant_name;
	t_point			p;
	struct s_rooms	**links;
	struct s_rooms	*next;
	struct s_rooms	*prev;
}					t_rooms;

typedef struct		s_link
{
	char			*room1;
	char			*room2;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_route
{
	char			*room;
	struct s_route	*next;
	struct s_route	*prev;
}					t_route;

typedef struct		s_main
{
	char			*line;
	char			*end_room;
	int				fd;
	int				total_ants;
	t_input			*input_head;
	t_input			*index;
	t_rooms			*room_head;
	t_rooms			*r_index;
	t_rooms			*start;
	t_rooms			*end;
	t_link			*l_head;
	t_link			*l_index;
	t_link			*temp;
	t_route			*route_head;
	t_route			*r;
	t_route			*rh;
	int				total_routes;
}					t_main;

typedef struct		s_c
{
	t_rooms			*e;
	t_rooms			*s;
	t_rooms			*from;
	t_rooms			*prev;
	t_rooms			*start;
	t_rooms			*to;
	int				*ans;
	char			*pstr;
	char			*temp;
	t_route			*r;
	t_route			*route_head;
}					t_c;

typedef struct		s_march
{
	int				i;
	int				ants;
	int				j;
	int				ans;
	char			c;
	char			*temp;
	char			*from;
	char			*to;
	t_rooms			*f;
	t_rooms			*t;
}					t_march;

typedef struct		s_rte
{
	t_rooms			*e;
	t_rooms			*s;
	t_route			**routes;
	t_rooms			*temp;
	t_rooms			*from;
	t_rooms			*to;
	t_rooms			*prev;
	int				*ans;
	int				i;
}					t_rte;

void				read_file(t_main *var);
void				error_check_file(t_input *file);
t_input				*store_file(int fd, char *line, t_input *file);
t_main				*init_store(t_main *var);
int					print_file(t_input *file);
int					check_ants(int line_number, char *line);
int					is_room(char *line);
int					is_comment(char *line);
int					is_link(char *line);
t_input				*err_check_1(t_input *file);
t_input				*err_check_2(t_input *file);
int					is_valid_start_end(t_input *file);
void				print_error(t_input *file);
int					free_split(char **split);
int					free_input(t_input **file);
void				create_rooms(t_main *var);
void				print_rooms(t_rooms *room);
t_rooms				*init_room(t_main *var, char **room, int *s, int *e);
void				store_links(t_main *var);
void				link_rooms(t_main *var);
void				print_links(t_main *var);
void				error_check_links(t_main *var);
int					error_check_room(t_main *var);
int					count_routes(t_rooms *rooms, t_main *m);
int					links_have_dup(t_link *links);
void				*store_routes(t_main *var);
int					room_leads_to_end(t_rooms *rooms, char *check);
void				reset_flag(t_rooms *room);
void				march_ants(t_main *var);
t_rooms				*room_to_route(t_rooms *room, char *r);
void				remove_dup_route(t_main *var);
int					goes_back(t_main *var, t_route *r);
void				free_routes(t_route	*head);
void				free_rooms(t_main *var);
void				free_links(t_main *var);
void				loop_2(t_main *var, t_rooms *temp, int *room_exists);
void				loop_3(t_main *var, t_rooms *temp, int *room_exists);
void				loop(t_rooms *from, t_c *var, int i);
int					count_paths_to_end(t_rooms *from, t_c *var);
int					leads_to_end(t_rooms *from, t_rte *x, t_rooms *link);
int					loop_graph(t_rooms *from, t_rte *x, t_rooms *link, int i);

#endif
