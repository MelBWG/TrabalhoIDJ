/*
 * Sprite.h
 *
 *  Created on: 29 de mar. de 2025
 *      Author: giuli
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include <iostream>
#include "SDL_image.h"

class Sprite {
private:
	SDL_Texture* texture;
	int width = 0;
	int height = 0;
	SDL_Rect clipRect;
	int frameCountW;
	int frameCountH;

public:
	Sprite();
	Sprite(std::string file, int frameCountW=1, int frameCountH=1);
	virtual ~Sprite();

	void Open(std::string file);
	void SetClip(int x, int y, int w, int h);
	void Render(int x, int y, int w, int h);
	int GetWidth();
	int GetHeight();
	bool IsOpen();
	void SetFrame(int frame);
	void SetFrameCount(int frameCountW, int frameCountH);

};

#endif /* SPRITE_H_ */
