/*
 * Game.cpp
 *
 *  Created on: 29 de mar. de 2025
 *      Author: giuli
 */

#include "SDL_image.h"
#include "SDL_mixer.h"

#include "Game.h"
#include <iostream>

// Literally this took me forever to figure out ._.
Game* Game::instance = NULL;

Game::Game(char* title, int width, int height) {
	// TODO Auto-generated constructor stub
	try {
	if(instance != nullptr) {
		//Indicar erro
		throw -1;
	}
	instance = this;

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)!= 0) {
		std::cout << SDL_GetError();
	}
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF);
	Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_AllocateChannels(32);

	this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, width, height, 0);
	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	this->state = new State();
	}
	catch(int e) {
		std::cout << "Game logic error: double game instance";
	}

}

Game& Game::GetInstance() {
	if(instance != nullptr) {
		return *instance;
	}
	char name[30] = "GiuliaGiannetti_190013745";
	instance = new Game(name, 1200, 900);
	return *instance;
}

State& Game::GetState() {
	return *this->state;
}

SDL_Renderer* Game::GetRenderer() {
	return this->renderer;
}

// Funcao que contem o loop do jogo
void Game::Run() {
	while(!this->state->QuitRequested()) {
		SDL_Delay(33);
		this->state->Update(0);
		this->state->Render();
		SDL_RenderPresent(this->renderer);
		 // Aproximadamente 30fps
	}
}

Game::~Game() {
	// TODO Auto-generated destructor stub
	delete state;
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

