#include <windows.h>
#include <cctype>
#include <iostream>
#include <format>
#include <filesystem>
#include <chrono>
#include "Game.hpp"
#include "File.hpp"
#include "../Input/Input.hpp"
#include "../Renderer/Renderer.hpp"
std::map<std::string,Level> Game::levels;
void Game::Start(){
	Game::levelsPath = "Levels/";
	for(auto& file : std::filesystem::directory_iterator(this->levelsPath)){
		auto level = Level();
		if(!level.LoadFromFile(file.path().string())){continue;}
		this->levels.emplace(level);
	}
}
void Game::Update(){
	//Board board = Board();
		if(Input::getPressed("Escape")){
			std::cout << "Closing Programm" << std::endl;
			exit(0);
			return;
		}
		if(Input::getPressed("r")){
			//board.initialize();
		}
}
