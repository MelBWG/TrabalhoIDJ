#include "Game.h"
#include <iostream>
#include <thread>
#include <chrono>

int main (int argc, char** argv) {
	Game instance = Game::GetInstance();
	instance.Run();

	//Sprite* estado = new Sprite();
	//std::this_thread::sleep_for(std::chrono::seconds(5));
	return 1;
}
