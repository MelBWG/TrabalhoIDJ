/*
 * Music.cpp
 *
 *  Created on: 29 de mar. de 2025
 *      Author: giuli
 */

#include "Music.h"

Music::Music() {
	// TODO Auto-generated constructor stub
	this->music = nullptr;
}

Music::Music(std::string file) {
	// TODO Auto-generated constructor stub
	Open(file);
}

void Music::Play(int times) {
	Mix_PlayMusic(this->music, times);
}

void Music::Stop(int msToStop) {
	Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file) {
	try {
		std::cout << file << std::endl;
		Mix_Music* musica = Mix_LoadMUS(file.c_str());
		this->music = musica;
		if(this->music == nullptr) {
			throw -1;
		}
	}
	catch(int e) {
		std::cout << "SDL_mixer failed to load music in ";
		std::cout << file << std::endl;
		std::cout << SDL_GetError();
	}
}

bool Music::IsOpen() {
	if(this->music != nullptr)
		return true;
	return false;
}

Music::~Music() {
	this->Stop(100);
	Mix_FreeMusic(this->music);
}

