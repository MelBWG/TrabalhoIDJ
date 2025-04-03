/*
 * State.h
 *
 *  Created on: 29 de mar. de 2025
 *      Author: giuli
 */

#ifndef STATE_H_
#define STATE_H_

#include "Music.h"
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "Zombie.h"
#include <memory>

// A principio funciona como os estados de uma maquina de estados
class State {
private:
	bool quitRequested; // Indica que jogo deve ser encerrado
	Music music;
	std::vector<std::unique_ptr<GameObject>> objectArray;

public:
	State();
	~State();
	bool QuitRequested();
	void LoadAssets();
	void Update(float dt);
	void Render();
	void AddObject(GameObject* go);
};

#endif /* STATE_H_ */
