/*
 * Sprite.h
 *
 *  Created on: 29 de mar. de 2025
 *      Author: giuli
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "SDL_image.h"

class Sprite {
private:
	SDL_Texture* texture;
	int width = 0;
	int height = 0;
	SDL_Rect clipRect;

public:
	Sprite();
	Sprite(char* file);
	virtual ~Sprite();

	void Open(char* file);
	void SetClip(int x, int y, int w, int h);
	void Render(int x, int y);
	int GetWidth();
	int GetHeight();
	bool IsOpen();

};

#endif /* SPRITE_H_ */
