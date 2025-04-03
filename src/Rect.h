/*
 * Rect.h
 *
 *  Created on: 31 de mar. de 2025
 *      Author: giuli
 */

#ifndef RECT_H_
#define RECT_H_

#include "Vec2.h"

class Rect {
public:
	float x, y;
	float w ,h;
	Rect(float x=0, float y=0, float w=0, float h=0) : x{x}, y{y}, w{w}, h{h} {}
	virtual ~Rect();

	Rect vectorSum(Vec2 vector);
	Vec2 center();

	static float recsCenterDistance(Rect rect1, Rect rect2);

	Rect& operator = (const Rect& rect) {
		if(this != &rect) {
			x = rect.x;
			y = rect.y;
			w = rect.w;
			h = rect.h;
		}
		return *this;
	}

};

#endif /* RECT_H_ */
