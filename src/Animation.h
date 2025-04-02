/*
 * Animation.h
 *
 *  Created on: 1 de abr. de 2025
 *      Author: giuli
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

class Animation {
public:
	int frameStart;
	int frameEnd;
	int frameTime;
	Animation(int frameStart, int frameEnd, float frameTime) : frameStart{}, frameEnd{}, frameTime{} {}
	virtual ~Animation();
};

#endif /* ANIMATION_H_ */
