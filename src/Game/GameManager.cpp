#include "GameManager.hpp"
#include "Game.hpp"
#include "../Input/Input.hpp"
#include "../Renderer/Renderer.hpp"
#include "../Renderer/RenderObject2D.hpp"
#include <filesystem>
#include <thread>
#include <chrono>
std::unordered_set<Entity> GameManager::activeEntities;
std::unordered_set<Collider2D> GameManager::activeColliders;
std::unordered_set<RenderObject2D> GameManager::activeRenderObjects;
void GameManager::Start(){
	GameManager::texturesPath = "Images/";
	GameManager::fontsPath = "Fonts/";
	GameManager::lastFrameTick = std::chrono::high_resolution_clock::now();
	for(auto& file : std::filesystem::directory_iterator(GameManager::texturesPath)){
		Renderer::loadTexture(file.path().string());
	}
	for(auto& file : std::filesystem::directory_iterator(GameManager::fontsPath)){
		Renderer::loadFont(file.path().string());
	}
	auto game = GameManager::game = Game();
	game.Start();
    while(true){
		auto now = std::chrono::high_resolution_clock::now();
		GameManager::deltaTime = std::chrono::duration_cast<std::chrono::duration<float>>(now - GameManager::lastFrameTick).count();
		GameManager::lastFrameTick = now;
		GameManager::Update();
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}
}
void GameManager::Update(){
	Renderer::clear();
	GameManager::game.Update();
	for(auto entity : GameManager::activeEntities){entity.Update();}
	for(auto collider : GameManager::activeColliders){}
	for(auto renderObject : GameManager::activeRenderObjects){Renderer::draw(renderObject.imageName);}
    Renderer::display();
}