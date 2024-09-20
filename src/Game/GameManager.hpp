#ifndef GAMEMANAGER_HEADER
#define GAMEMANAGER_HEADER
#include <string>
#include <chrono>
#include "Game.hpp"
#include "../Physics/Collider2D.hpp"
#include "../Renderer/RenderObject2D.hpp"
class GameManager{
	private:
		static std::chrono::high_resolution_clock::time_point lastFrameTick;
	public:
		static float deltaTime;
		static std::string texturesPath;
		static std::string fontsPath;
		static Game game;
		static void Start();
		static void Update();
};
#endif