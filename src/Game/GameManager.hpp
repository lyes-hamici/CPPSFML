#ifndef GAMEMANAGER_HEADER
#define GAMEMANAGER_HEADER
#include <string>
#include <unordered_set>
#include <functional>
#include <chrono>
#include "Game.hpp"
class GameManager{
	private:
		static std::chrono::high_resolution_clock::time_point lastFrameTick;
	public:
		static std::unordered_set<std::function<void(void)>> entityStarts;
		static std::unordered_set<std::function<void(void)>> entityUpdates;
		static float deltaTime;
		static std::string texturesPath;
		static std::string fontsPath;
		static Game game;
		static void Start();
		static void Update();
};
#endif