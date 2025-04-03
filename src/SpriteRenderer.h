/*
 * SpriteRenderer.h
 *
 *  Created on: 2 de abr. de 2025
 *      Author: giuli
 */

#ifndef SPRITERENDERER_H_
#define SPRITERENDERER_H_

#include "GameObject.h"
#include "Sprite.h"

class SpriteRenderer : public Component {
private:
	Sprite sprite;
public:
	SpriteRenderer() : Component(associated) {}
	SpriteRenderer(GameObject& associated, std::string file, int frameCountW=1, int frameCountH=1);
	void Open(std::string file);
	void SetFrameCount(int frameCountW, int frameCountH);
	void Update(float dt);
	void Render();
	bool Is(std::string type);
	void SetFrame(int frame);
};

#endif /* SPRITERENDERER_H_ */
