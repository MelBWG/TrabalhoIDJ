/*
 * Zombie.h
 *
 *  Created on: 3 de abr. de 2025
 *      Author: giuli
 */

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <iostream>
#include "GameObject.h"

class Zombie : public Component{
private:
	int hitpoints;
public:
	Zombie(GameObject& associated);
	void Damage(int damage);
	void Update(float dt);
	void Render();
	bool Is(std::string type);

};

#endif /* ZOMBIE_H_ */
