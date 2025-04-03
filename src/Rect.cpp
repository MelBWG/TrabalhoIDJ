/*
 * Rect.cpp
 *
 *  Created on: 31 de mar. de 2025
 *      Author: giuli
 */

#include "Rect.h"

Rect Rect::vectorSum(Vec2 vector) {
	return Rect(this->x+vector.x, this->y+vector.y, this->w, this->h);
}

Vec2 Rect::center() {
	float xCenter = this->x + (this->w/2);
	float yCenter = this->y + (this->h/2);
	return Vec2(xCenter, yCenter);
}

float Rect::recsCenterDistance(Rect rect1, Rect rect2) {
	Vec2 center1 = rect1.center();
	Vec2 center2 = rect2.center();
	return Vec2::vectDistance(center1, center2);
}

Rect::~Rect() {
	// TODO Auto-generated destructor stub
}

