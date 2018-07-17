#include <header.h>
#include <unistd.h>
#include <stdio.h>

SDL_Renderer	*init(char *title)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *win = SDL_CreateWindow(title, 100, 100, 500, 700, SDL_WINDOW_SHOWN);
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderClear(ren);
	SDL_RenderPresent(ren);
	return (ren);
}

int	main(void)
{
	SDL_Renderer	*ren = init("My world");
	SDL_Event		event;
	int				quit;
	int				x;
	int				y;

	quit = 0;
	while (!quit)
	{
		/* Check for new events */
		while(SDL_PollEvent(&event))
		{
			SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
			SDL_RenderClear(ren);
			SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
			draw_grid(ren, 24, 40);
			SDL_RenderPresent(ren);
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
				SDL_RenderClear(ren);
				SDL_GetMouseState(&x, &y);
				SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
				//draw_line(ren, 320, 240, x, y);
				//draw_square(ren, x, y, 30);
				//draw_grid(ren, 24);

				SDL_RenderPresent(ren);
			}
			/* If a quit event has been sent */
			if (event.type == SDL_QUIT)
			{
				/* Quit the application */
				quit = 1;
			}
		}
	}
	SDL_Quit();
	return (0);
}
