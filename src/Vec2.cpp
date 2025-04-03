/*
 * Vec2.cpp
 *
 *  Created on: 31 de mar. de 2025
 *      Author: giuli
 */

#include "Vec2.h"
#include <cmath>

void Vec2::escalarMult(float escalar) {
	this->x = x*escalar;
	this->y = y*escalar;
}

float Vec2::magnitude() {
	return std::sqrt(std::pow(this->x,2) +  std::pow(this->y,2));
}

Vec2 Vec2::normalize() {
	float mag = this->magnitude();
	return Vec2(this->x/mag, this->y/mag);
}

float Vec2::xAngle() {
	const float pi =3.14159265358;
	float degrees = std::atan2(this->y, this->x);
	return degrees * (180.0/pi);
}

void Vec2::rotate(float angle) {
	const float pi =3.14159265358;
	float rads = angle * (pi/180);
	this->x = (std::cos(rads)*this->x) + (std::sin(rads)*this->y);
	this->y = (std::cos(rads)*this->y)- (std::sin(rads)*this->x);
}

float Vec2::vectDistance(Vec2 vetor1, Vec2 vetor2) {
	Vec2 sub = vetor1-vetor2;
	return sub.magnitude();
}

float Vec2::lineAngle(Vec2 vetor1, Vec2 vetor2) {
	Vec2 sub = vetor1 - vetor2;
	return sub.xAngle();
}

Vec2::~Vec2() {
	// TODO Auto-generated destructor stub
}

// Inclui testes unitários

