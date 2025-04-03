/*
 * GameObject.cpp
 *
 *  Created on: 2 de abr. de 2025
 *      Author: giuli
 */

#include "GameObject.h"

void GameObject::Update(float dt) {
	for(const auto &element : this->components) {
		element->Update(dt);
	}
}

void GameObject::Render() {
	for(const auto &element : this->components) {
		element->Render();
	}

}

bool GameObject::IsDead() {
	return this->isDead;
}

void GameObject::RequestDelete(){
	this->isDead = true;
}

void GameObject::AddComponent(Component* cpt){
	for(std::vector<Component*>::iterator i = this->components.begin(); i<this->components.end(); i++) {
		if(*i == cpt)
			return;
	}
	this->components.push_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
	for(std::vector<Component*>::iterator i = this->components.begin(); i<this->components.end(); i++) {
		if(*i == cpt) {
			i = this->components.erase(i);
		}
	}
}

Component* GameObject::GetComponent(std::string type){
	for(std::vector<Component*>::iterator i = this->components.begin(); i<this->components.end(); i++) {
		Component* buff = *i;
		if(buff->Is(type)) {
			return buff;
		}
	}
	return nullptr;

}


GameObject::~GameObject() {
	// TODO Auto-generated destructor stub
	for (std::vector<Component*>::iterator i = this->components.end(); i<this->components.begin(); i--) {
		delete *i;
	}
	this->components.clear();
}

