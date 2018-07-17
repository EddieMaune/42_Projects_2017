/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:02:56 by emaune            #+#    #+#             */
/*   Updated: 2018/06/22 11:21:13 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_H
# define SDL_H

/*
**	Global includes:
*/

#include <SDL.h>

/*
**	Drawing functions:
*/

void	draw_line(SDL_Renderer *ren, int x1, int y1, int x2, int y2);
void	draw_rect(SDL_Renderer *ren, int x, int y, int w, int h);
void	draw_grid(SDL_Renderer *ren, double rows, double columns);
/*
**	Miscelaneous functions:
*/

int		abs(int n);
void	swap(int *n1, int *n2);

#endif
