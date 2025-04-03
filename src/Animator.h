/*
 * Animator.h
 *
 *  Created on: 3 de abr. de 2025
 *      Author: giuli
 */

#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include <iostream>
#include <unordered_map>
#include "Animation.h"
#include "GameObject.h"

class Animator : public Component {
private:
	std::unordered_map<std::string, Animation> animations;
	int frameStart;
	int frameEnd;
	float frameTime;
	int currentFrame;
	float timeElapsed;

public:
	Animator(GameObject& associated);
	void Update(float dt);
	void Render();
	bool Is(std::string type);
	void SetAnimation(std::string name);
	void AddAnimation(std::string name, Animation anim);
};

#endif /* ANIMATOR_H_ */
