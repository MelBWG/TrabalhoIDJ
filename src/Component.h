/*
 * Component.h
 *
 *  Created on: 2 de abr. de 2025
 *      Author: giuli
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <iostream>

class GameObject;

class Component {
protected:
	GameObject& associated;

public:
	Component(GameObject& associated) : associated{associated} {};
	virtual ~Component() {}

	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	virtual bool Is(std::string type) = 0;
};


#endif /* COMPONENT_H_ */
