/*
 * SpriteRenderer.cpp
 *
 *  Created on: 2 de abr. de 2025
 *      Author: giuli
 */

#include "SpriteRenderer.h"
#include <iostream>

SpriteRenderer::SpriteRenderer(GameObject& associated, std::string file, int frameCountW, int frameCountH) : Component(associated) {
	// TODO Auto-generated constructor stub
	Sprite* temporary = new Sprite(file, frameCountW, frameCountH);
	this->sprite = *temporary;
	this->associated.box.h= this->sprite.GetHeight();
	this->associated.box.w = this->sprite.GetWidth();
	this->SetFrame(0);
}

void SpriteRenderer::Open(std::string file) {
	this->sprite.Open(file);
	this->associated.box.h = this->sprite.GetWidth();
	this->associated.box.w = this->sprite.GetHeight();
}

void SpriteRenderer::SetFrameCount(int frameCountW, int frameCountH) {
	this->sprite.SetFrameCount(frameCountW, frameCountH);
}

void SpriteRenderer::SetFrame(int frame) {
	this->sprite.SetFrame(frame);;
}

void SpriteRenderer::Update(float dt) {

}

void SpriteRenderer::Render() {
	this->sprite.Render(this->associated.box.x, this->associated.box.y, this->associated.box.w, this->associated.box.h);
}

bool SpriteRenderer::Is(std::string type) {
	if(type == "SpriteRenderer")
		return true;
	else
		return false;

}


