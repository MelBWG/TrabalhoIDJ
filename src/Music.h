/*
 * Music.h
 *
 *  Created on: 29 de mar. de 2025
 *      Author: giuli
 */

#ifndef MUSIC_H_
#define MUSIC_H_

#include <iostream>
#include "SDL_mixer.h"

class Music {
private:
	Mix_Music* music;
public:
	Music();
	Music(std::string file);
	virtual ~Music();

	void Play(int times = 1);
	void Stop(int msToStop = 1500);
	void Open(std::string file);
	bool IsOpen();
};

#endif /* MUSIC_H_ */
