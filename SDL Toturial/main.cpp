#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[]){
	SDL_Surface *imageSurface = NULL;
	SDL_Surface *windowSurface = NULL;
	
	
	if(SDL_Init(SDL_INIT_EVERYTHING)<0)
	{
		std::cout << "SDL could not init" << std::endl;
	}
	
	SDL_Window *window = SDL_CreateWindow("Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	windowSurface = SDL_GetWindowSurface(window);
	
	if (NULL == window)
	{
		std::cout << "Could not create window" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	
	SDL_Event windowEvent;
	imageSurface = SDL_LoadBMP("man.bmp");
	
	if (imageSurface == NULL )
	{
		std::cout<< "Could not load the image. SDL Error: " << SDL_GetError() << std::endl;
	}
	
	while (true){
		if (SDL_PollEvent(&windowEvent))
			if(SDL_QUIT == windowEvent.type)
				break;
		SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
		SDL_UpdateWindowSurface(window);
	}
	
	SDL_FreeSurface(imageSurface);
	SDL_FreeSurface(windowSurface);
	imageSurface = NULL;
	windowSurface = NULL;
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return EXIT_SUCCESS;
}
