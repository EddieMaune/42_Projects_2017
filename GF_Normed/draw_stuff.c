/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:55:10 by emaune            #+#    #+#             */
/*   Updated: 2018/07/16 10:48:25 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				assign_var(t_coordinates *p1, t_coordinates *p2,
		int **a, int **b)
{
	if (abs(p1->x - p2->x) >= abs(p1->y - p2->y))
	{
		*a = &p1->x;
		*b = &p1->y;
	}
	else
	{
		swap(&p1->x, &p1->y);
		swap(&p2->x, &p2->y);
		*a = &p1->y;
		*b = &p1->x;
	}
}

void				draw_line(SDL_Renderer *ren, t_coordinates p1,
		t_coordinates p2)
{
	double			slope;
	double			offset;
	int				iterate;
	int				*a;
	int				*b;

	slope = 0;
	offset = 0;
	a = NULL;
	b = NULL;
	assign_var(&p1, &p2, &a, &b);
	iterate = -1 + (2 * (p1.x < p2.x));
	slope = ((double)abs(p1.y - p2.y) / (double)abs(p1.x - p2.x)) *
		(-1 + (2 * (p1.y < p2.y)));
	while (p1.x != p2.x)
	{
		if (offset >= 0.49999 || offset <= -0.5)
		{
			offset -= -1 + (2 * (p1.y < p2.y));
			p1.y += -1 + (2 * (p1.y < p2.y));
		}
		SDL_RenderDrawPoint(ren, *a, *b);
		p1.x += iterate;
		offset += slope;
	}
}

void				draw_rect(SDL_Renderer *ren, t_coordinates p, int w, int h)
{
	t_coordinates	p2;

	p2.x = p.x + w;
	p2.y = p.y;
	draw_line(ren, p, p2);
	p.y += h;
	draw_line(ren, p, p2);
	p.y -= h;
	p2.y += h;
	draw_line(ren, p, p2);
	p.x += w;
	draw_line(ren, p, p2);
}

void				fill_rect(SDL_Renderer *ren, t_coordinates p, int w, int h)
{
	int				x2;
	int				l;
	t_coordinates	p2;

	x2 = p.x + 1;
	p.y++;
	p2.y = p.y + h - 2;
	l = p.x + w - 2;
	while (x2 <= l)
	{
		p.x = x2;
		p2.x = x2;
		draw_line(ren, p, p2);
		x2++;
	}
}

void				draw_grid(SDL_Renderer *ren, double rows, double columns)
{
	t_coordinates	p1;
	t_coordinates	p2;

	p1.y = 0;
	p2.y = 0;
	while (p1.y < 900 && p2.y < rows)
	{
		p1.x = 0;
		p2.x = 0;
		while (p1.x < 700 && p2.x < columns)
		{
			SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
			draw_rect(ren, p1, 700 / columns, 900 / rows);
			SDL_SetRenderDrawColor(ren, 195, 195, 195, 255);
			fill_rect(ren, p1, 700 / columns, 900 / rows);
			p1.x += 700 / columns;
			p2.x++;
		}
		p2.y++;
		p1.y += 900 / rows;
	}
}
