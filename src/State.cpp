/*
 * State.cpp
 *
 *  Created on: 29 de mar. de 2025
 *      Author: giuli
 */
#include <iostream>
#include <string>
#include "State.h"
#include "SDL.h"

State::State() {
	this->quitRequested = false;
	char pathMsc[50] = "./Assets/Music/BGM.wav";
	std::cout << pathMsc << std::endl;
	char pathTxt[50] = "./Assets/Sprites/Background.png";
	Sprite* spr_buffer = new Sprite(pathTxt);
	Music* msc_buffer = new Music(pathMsc);
	this->bg = *spr_buffer;
	this->music = *msc_buffer;
	music.Play();
}

// Carregar assets antes do state para evitar problemas
// Ex: this->music = (instancia de Music)
void State::LoadAssets() {

}

// Atualiza estados de entidade, roda teste de colisões
// Checagem do encerramento do jogo.
void State::Update(float dt) {
	if(SDL_QuitRequested() == true) {
		std::cout << "requested quit";
		this->quitRequested=true;
	}
}

void State::Render() {
	this->bg.Render(0,0);
}

bool State::QuitRequested() {
	return this->quitRequested;
}



