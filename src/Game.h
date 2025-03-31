/*
 * Game.h
 *
 *  Created on: 29 de mar. de 2025
 *      Author: giuli
 */

#ifndef GAME_H_
#define GAME_H_

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "State.h"

class Game {
private:
	Game(char* title, int width, int height);

	SDL_Window* window;
	SDL_Renderer* renderer;
	State* state;
	static Game* instance;

public:
	virtual ~Game();

	void Run();
	SDL_Renderer* GetRenderer();
	State& GetState();
	static Game& GetInstance();
};

#endif /* GAME_H_ */
