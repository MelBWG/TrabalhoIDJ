/*
 * State.h
 *
 *  Created on: 29 de mar. de 2025
 *      Author: giuli
 */

#ifndef STATE_H_
#define STATE_H_

#include "Sprite.h"
#include "Music.h"

// A principio funciona como os estados de uma maquina de estados
class State {
private:
	bool quitRequested; // Indica que jogo deve ser encerrado
	Sprite bg;
	Music music;

public:
	State();
	bool QuitRequested();
	void LoadAssets();
	void Update(float dt);
	void Render();
};

#endif /* STATE_H_ */
