#include "../SDL/include/SDL.h"
#pragma comment(lib,"../SDL/libx86/SDL2.lib")
#pragma comment(lib,"../SDL/libx86/SDL2main.lib")
#include <iostream>



int main(int argv, char *argc[])
{
	bool bulletExists = false;
	bool moveRight = false;
	bool moveLeft = false;
	bool moveDown = false;
	bool moveUp = false;
	int c = 0;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Red Square", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	SDL_Rect rambo;
	rambo.x = 240;
	rambo.y = 180;
	rambo.w = 80;
	rambo.h = 80;
	SDL_Rect bullet[5];
	for (int i = 0; i < 5; i++) {
		bullet[i].x = NULL;
		bullet[i].y = NULL;
		bullet[i].w = NULL;
		bullet[i].h = NULL;
	}
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
	SDL_RenderClear(renderer);

	bool loop = true;

	while (loop)
	{
		SDL_Event event;
		if (SDL_PollEvent(&event) != 0)
		{

			if (event.type == SDL_QUIT) {
				loop = false;
			}
			if (event.type == SDL_KEYDOWN) {

				if (event.key.keysym.sym == SDLK_UP) {
					moveUp = true;
				}
				if (event.key.keysym.sym == SDLK_DOWN) {
					moveDown = true;
				}
				if (event.key.keysym.sym == SDLK_LEFT) {
					moveLeft = true;
				}
				if (event.key.keysym.sym == SDLK_RIGHT) {
					moveRight = true;
				}
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					loop = false;
				}
				if (event.key.keysym.sym == SDLK_SPACE) {

					switch (c) {
					case 0:
						bulletExists = true;
						bullet[c].x = rambo.x + 80;
						bullet[c].y = rambo.y + 35;
						bullet[c].w = 40;
						bullet[c].h = 10;
						c++;
						break;
					case 1:
						bulletExists = true;
						bullet[c].x = rambo.x + 80;
						bullet[c].y = rambo.y + 35;
						bullet[c].w = 40;
						bullet[c].h = 10;
						c++;
						break;
					case 2:
						bulletExists = true;
						bullet[c].x = rambo.x + 80;
						bullet[c].y = rambo.y + 35;
						bullet[c].w = 40;
						bullet[c].h = 10;
						c++;
						break;
					case 3:
						bulletExists = true;
						bullet[c].x = rambo.x + 80;
						bullet[c].y = rambo.y + 35;
						bullet[c].w = 40;
						bullet[c].h = 10;
						c++;
						break;
					case 4:
						bulletExists = true;
						bullet[c].x = rambo.x + 80;
						bullet[c].y = rambo.y + 35;
						bullet[c].w = 40;
						bullet[c].h = 10;
						c = 0;
						break;
					}


				}
			}
				if (event.type == SDL_KEYUP) {
					if (event.key.keysym.sym == SDLK_UP) {
						moveUp = false;
					}
					if (event.key.keysym.sym == SDLK_DOWN) {
						moveDown = false;
					}
					if (event.key.keysym.sym == SDLK_LEFT) {
						moveLeft = false;
					}
					if (event.key.keysym.sym == SDLK_RIGHT) {
						moveRight = false;
					}

				}
			
		}
				if (rambo.x < 0) {
					rambo.x = 0;
				}
				if (rambo.x > 1200) {
					rambo.x = 1200;
				}
				if (rambo.y < 0) {
					rambo.y = 0;
				}
				if (rambo.y > 640) {
					rambo.y = 640;
				}
				
				
			
		if (moveDown == true) {
			rambo.y += 10;
		}
		if (moveUp == true) {
			rambo.y -= 10;
		}
		if (moveLeft == true) {
			rambo.x -= 10;
		}
		if (moveRight == true) {
			rambo.x += 10;
		}
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			SDL_RenderFillRect(renderer, &rambo);
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			if (bulletExists = true) {
				for (int i = 0; i < 5; i++) {
					SDL_RenderFillRect(renderer, &bullet[i]);
					bullet[i].x += 15;
				}
			}
			SDL_RenderPresent(renderer);

			SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
			SDL_RenderClear(renderer);
			SDL_Delay(8);

		}
		return 0;
	}