/*
 * Vec2.h
 *
 *  Created on: 31 de mar. de 2025
 *      Author: giuli
 */

#ifndef VEC2_H_
#define VEC2_H_

class Vec2 {
public:
	float x;
	float y;
	Vec2(float x=0, float y=0) : x{x}, y{y} {}
	virtual ~Vec2();

	void escalarMult(float escalar);
	float magnitude();
	Vec2 normalize();
	float xAngle();
 	void rotate(float angle);

	static float vectDistance(Vec2 vetor1, Vec2 vetor2);
	static float lineAngle(Vec2 vetor1, Vec2 vetor2);

	// Nesse caso fica implicito que esse operador é invocado pelo primeiro argumento
	Vec2 operator + (Vec2 vetor) {
		return Vec2(this->x + vetor.x, this->y + vetor.y);
	}
	Vec2 operator - (Vec2 vetor) {
		return Vec2(this->x - vetor.x, this->y - vetor.y);
	}

	Vec2& operator = (const Vec2& vetor) {
		if(this != &vetor) {
			x = vetor.x;
			y=vetor.y;
		}
		return *this;
	}


};

#endif /* VEC2_H_ */
