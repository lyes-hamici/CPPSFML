#include "GameManager.hpp"
#include "Game.hpp"
#include "../Input/Input.hpp"
#include "../Renderer/Renderer.hpp"
#include <filesystem>
#include <thread>
#include <chrono>
std::unordered_set<std::function<void(void)>> GameManager::entityStarts;
std::unordered_set<std::function<void(void)>> GameManager::entityUpdates;
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
	GameManager::game = Game();
	GameManager::game.Start();
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
    Renderer::display();
}