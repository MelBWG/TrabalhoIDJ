/*
 * GameObject.h
 *
 *  Created on: 2 de abr. de 2025
 *      Author: giuli
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <iostream>
#include <vector>
#include "Rect.h"

#include "Component.h"

class GameObject {
private:
	std::vector<Component *> components;
	bool isDead;
public:
	Rect box;
	GameObject() : isDead{false} {}
	virtual ~GameObject();

	void Update(float dt);
	void Render();
	bool IsDead();
	void RequestDelete();
	void AddComponent(Component* cpt);
	void RemoveComponent(Component* cpt);
	Component* GetComponent(std::string type);


};

#endif /* GAMEOBJECT_H_ */
