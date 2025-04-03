/*
 * Animator.cpp
 *
 *  Created on: 3 de abr. de 2025
 *      Author: giuli
 */

#include "Animator.h"
#include "SpriteRenderer.h"

Animator::Animator(GameObject& associated) : Component(associated) {
	this->frameStart = 0;
	this->frameEnd = 0;
	this->frameTime = 0.0;
	this->currentFrame = 0;
	this->timeElapsed = 0.0;
}

void Animator::Update(float dt) {
	if(frameTime != 0.0) {++timeElapsed;}
	if (timeElapsed>frameTime) {
		++currentFrame; timeElapsed-=frameTime;
		SpriteRenderer* renderer = (SpriteRenderer*) this->associated.GetComponent("SpriteRenderer");
		renderer->SetFrame(currentFrame);
	}
	if(currentFrame>frameEnd) {
		currentFrame = frameStart;
		SpriteRenderer* renderer = (SpriteRenderer*) this->associated.GetComponent("SpriteRenderer");
		renderer->SetFrame(currentFrame);
	}
}

void Animator::Render() {

}

bool Animator::Is(std::string type) {
	if(type == "Animator")
		return true;
	else
		return false;
}

void Animator::SetAnimation(std::string name) {
	if(this->animations.find(name) != this->animations.end()) {
		this->frameStart = this->animations[name].frameStart;
		this->frameEnd = this->animations[name].frameEnd;
		this->frameTime = this->animations[name].frameTime;
		this->currentFrame = this->frameStart;
		this->timeElapsed = 0;
		SpriteRenderer* renderer = (SpriteRenderer*) this->associated.GetComponent("SpriteRenderer");
		renderer->SetFrame(currentFrame);

	}
}

void Animator::AddAnimation(std::string name, Animation anim) {
	if(this->animations.find(name) == this->animations.end())
		this->animations.insert(std::pair<std::string, Animation>(name, anim));

}

