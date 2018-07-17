#include <header.h>

void		draw_line(SDL_Renderer *ren, int x1, int y1, int x2, int y2)
{
	double	slope;
	double	offset;
	int		iterate;
	int		*a;
	int		*b;

	slope = 0;
	offset = 0;
	if (abs(x1 - x2) >= abs(y1 - y2))
	{
		a = &x1;
		b = &y1;
	}
	else
	{
		swap(&x1, &y1);
		swap(&x2, &y2);
		a = &y1;
		b = &x1;
	}
	iterate = -1 + (2 * (x1 < x2));
	slope = ((double)abs(y1 - y2) / (double)abs(x1 - x2)) * (-1 + (2 * (y1 < y2)));
	while (x1 != x2)
	{
		if (offset >= 0.49999 || offset <= -0.5)
		{
			offset -= -1 + (2 * (y1 < y2));
			y1 += -1 + (2 * (y1 < y2));
		}
		SDL_RenderDrawPoint(ren, *a, *b);
		x1 += iterate;
		offset += slope;
	}
}

void		draw_rect(SDL_Renderer *ren, int x, int y, int w, int h)
{
	draw_line(ren, x, y, x + w, y);
	y += h;
	draw_line(ren, x, y, x + w, y);
	y -= h;
	draw_line(ren, x, y, x, y + h );
	x += w;
	draw_line(ren, x, y, x, y + h);
}

void		fill_rect(SDL_Renderer *ren, int x, int y, int w, int h)
{
	int     x2;
	x2 = x + 3;
	while (x2 <= x + w - 3)
	{
		draw_line(ren, x2, y + 3, x2, y + h - 3);
		x2++;
	}
}

void	draw_grid(SDL_Renderer *ren, double rows, double columns)
{
	double		x;
	double		y;

	y = 0;
	while (y < 700)
	{
		x = 0;
				while (x < 500)
		{
			SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
			draw_rect(ren, x + 2, y + 2, 500/columns - 4, 700/rows - 4);
			x += 500 / columns;
		}
		y += 700 / rows;
	}
}
