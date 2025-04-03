/*
 * Sprite.cpp
 *
 *  Created on: 29 de mar. de 2025
 *      Author: giuli
 */

#include "Sprite.h"
#include "Game.h"
#include <fstream>
#include <iostream>

Sprite::Sprite() {
	// TODO Auto-generated constructor stub
	this->texture = nullptr;
	this->frameCountH = 0;
	this->frameCountW = 0;

}

Sprite::Sprite(std::string file, int frameCountW, int frameCountH) {
	this->texture = nullptr;
	this->frameCountW = frameCountW;
	this->frameCountH = frameCountH;
	this->Open(file.c_str());
}

Sprite::~Sprite() {
	// OBS: Nunca usar delete ou free para texturas SDL
	if(this->texture != nullptr)
		SDL_DestroyTexture(this->texture);
}

void Sprite::Open(std::string file) {
	// IMG_LoadTexture causa o crash do jogo se der erro
	if(this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
	}
	else {
		try {
			SDL_Renderer* renderer = Game::GetInstance().GetRenderer();
			this->texture = IMG_LoadTexture(renderer, file.c_str());
			if(this->texture == nullptr) {
				throw -1;
			}
			// é por causa dessa funcao que precisamos que width
			// e height sejam dados da classe.
			if(SDL_QueryTexture(this->texture, nullptr, nullptr, &this->width, &this->height)!=0) {
				std::cout << SDL_GetError();
				throw -1;
			}
			this->SetClip(0, 0, this-> width, this->height);

		}
		catch (int e) {
			std::cout << "SDL failed to load the texture in" + (std::string) file;
			std::cout << SDL_GetError();
		}
	}

}

void Sprite::SetFrame(int frame) {
	int frameW = this->width/this->frameCountW;
	int frameH = this->height/this->frameCountH;
	Vec2 frameCorner((frame%this->frameCountW)*frameW,(frame/this->frameCountW)*frameH);
	this->SetClip(frameCorner.x, frameCorner.y, frameW, frameH);
}

void Sprite::SetFrameCount(int frameCountW, int frameCountH) {
	this->frameCountW = frameCountW;
	this->frameCountH = frameCountH;
}

void Sprite::SetClip(int x, int y, int w, int h) {
	this->clipRect.x = x;
	this->clipRect.y = y;
	this->clipRect.w = w;
	this->clipRect.h = h;

}

//Wrapper para SDL_RenderCopy
void Sprite::Render(int x, int y, int w, int h) {
	/* SDL_Rect srcrect - retangulo de clipagem da textura, porque as vezes usamos so parte dela
	* SDL_Rect dstrect - posicao na tela onde a textura sera renderizada
	*/
	SDL_Rect* dstrect = new SDL_Rect();
	dstrect->x = x;
	dstrect->y = y;
	dstrect->w = w;
	dstrect->h = h;
	if(SDL_RenderCopy(Game::GetInstance().GetRenderer(), this->texture, &this->clipRect, dstrect)!=0) {
		std::cout<<"Render copy error"<< std::endl;
		std::cout<< SDL_GetError()<<std::endl<<std::endl;
	}

}

int Sprite::GetWidth() {
	return this->width/this->frameCountW;
}

int Sprite::GetHeight() {
	return this->height/this->frameCountH;
}

bool Sprite::IsOpen() {
	if(this->texture != nullptr)
		return true;
	return false;
}


