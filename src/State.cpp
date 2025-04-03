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
	GameObject* backgroundGameObject = new GameObject();
	SpriteRenderer* backgroundSpriteRenderer = new SpriteRenderer(*backgroundGameObject, "./Assets/Sprites/Background.png");
	backgroundGameObject->AddComponent(backgroundSpriteRenderer);
	this->AddObject(backgroundGameObject);
	GameObject* zombieGameObject = new GameObject();
	zombieGameObject->box.x = 600;
	zombieGameObject->box.y = 450;
	Zombie* zombie = new Zombie(*zombieGameObject);
	zombieGameObject->AddComponent(zombie);
	this->AddObject(zombieGameObject);
	char pathMsc[50] = "./Assets/Music/BGM.wav";
	std::cout << pathMsc << std::endl;
	Music* msc_buffer = new Music(pathMsc);
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
	for(auto&& i : this->objectArray) {
		i->Update(dt);
	}
	if(SDL_QuitRequested() == true) {
		std::cout << "requested quit";
		this->quitRequested=true;
	}
	for (int i = 0; i<objectArray.size(); i++) {
		if(objectArray.at(i)->IsDead()) {
			this->objectArray.erase(this->objectArray.begin()+i);
		}
	}
}

void State::Render() {
	for(auto&& i : this->objectArray) {
		i->Render();
	}
}

void State::AddObject(GameObject* go) {
	this->objectArray.emplace_back(go);
}


bool State::QuitRequested() {
	return this->quitRequested;
}


State::~State() {
	this->objectArray.clear();
}

