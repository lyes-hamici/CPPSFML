#ifndef GAMEMANAGER_HEADER
#define GAMEMANAGER_HEADER
#include <string>
#include <unordered_set>
#include <functional>
#include <chrono>
#include "Game.hpp"
#include "Entity.hpp"
#include "../Physics/Collider2D.hpp"
#include "../Renderer/RenderObject2D.hpp"
class GameManager{
	private:
		static std::chrono::high_resolution_clock::time_point lastFrameTick;
	public:
		static std::unordered_set<Entity> activeEntities;
		static std::unordered_set<Collider2D> activeColliders;
		static std::unordered_set<RenderObject2D> activeRenderObjects;
		static float deltaTime;
		static std::string texturesPath;
		static std::string fontsPath;
		static Game game;
		static void Start();
		static void Update();
};
#endif