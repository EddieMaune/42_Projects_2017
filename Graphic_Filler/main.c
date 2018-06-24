/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:53:36 by emaune            #+#    #+#             */
/*   Updated: 2018/06/24 15:43:50 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

SDL_Renderer    	*init(char *title)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *win = SDL_CreateWindow(title, 100, 100, 700, 900, SDL_WINDOW_SHOWN);
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);
    return (ren);
}

int					main(void)
{
	t_main			var;

	var.ren = init("Filler");
	SDL_SetRenderDrawColor(var.ren, 255, 255, 255, 255);
	SDL_RenderClear(var.ren);
	SDL_RenderPresent(var.ren);
	usleep(2000000);
	var.fd = open("text", O_RDWR);
	var.board = NULL;
	var.piece = NULL;
	var.read_board = 0;
	var.read_piece = 0;
	var.possible_moves = NULL;
	set_token(&var);
	read_and_play(&var);
	sleep(5);
	return (0);
}
