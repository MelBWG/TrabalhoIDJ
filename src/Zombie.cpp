/*
 * Zombie.cpp
 *
 *  Created on: 3 de abr. de 2025
 *      Author: giuli
 */

#include "Zombie.h"
#include "SpriteRenderer.h"
#include "Animator.h"

Zombie::Zombie(GameObject& associated) : Component(associated) {
	this->hitpoints = 100;
	SpriteRenderer* zombieRenderer = new SpriteRenderer(associated, "./Assets/Sprites/Enemy.png", 3, 2);
	this->associated.AddComponent(zombieRenderer);
	Animator* zombieAnimator = new Animator(associated);
	this->associated.AddComponent(zombieAnimator);
	zombieAnimator->AddAnimation("walking", Animation(0,3,10));
	zombieAnimator->AddAnimation("dead", Animation(5,5,0));
	zombieAnimator->SetAnimation("walking");


}

void Zombie::Damage(int damage) {
	this->hitpoints -= damage;
	if(this->hitpoints<=0) {
		Animator* renderer = (Animator*) associated.GetComponent("Animator");
		renderer->SetAnimation("dead");
	}
}

void Zombie::Update(float dt) {
	this->Damage(1);
}

void Zombie::Render() {

}

bool Zombie::Is(std::string type) {
	if(type == "Zombie")
		return true;
	else
		return false;
}



