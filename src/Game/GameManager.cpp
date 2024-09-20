#include "GameManager.hpp"
#include "../Input/Input.hpp"
#include "../Renderer/Renderer.hpp"
#include <filesystem>
#include <thread>
#include <chrono>
std::chrono::high_resolution_clock::time_point GameManager::lastFrameTick;
std::string GameManager::texturesPath;
std::string GameManager::fontsPath;
float GameManager::deltaTime;
Game GameManager::game;
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
	for(auto entity : Entity::all){entity.second.Update();}
	for(auto collider : Collider2D::all){}
	for(auto renderObject : RenderObject2D::all){Renderer::draw(renderObject.second.imageName);}
    Renderer::display();
}