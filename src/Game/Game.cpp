#include <chrono>
#include <filesystem>
#include "../Input/Input.hpp"
#include "../Renderer/Renderer.hpp"
#include "Game.hpp"
#include "File.hpp"
std::string Game::levelsPath;
std::map<std::string,Level> Game::levels;
void Game::Start(){
	Game::levelsPath = "Levels/";
	for(auto& file : std::filesystem::directory_iterator(this->levelsPath)){
		auto level = Level();
		auto path = file.path().string();
		auto lastScope = std::max(path.find_last_of('/'),path.find_last_of('\\'));
		auto name = path.substr(lastScope,path.find_last_of('.'));
		if(!level.LoadFromFile(file.path().string())){continue;}
		this->levels.emplace(name,level);
	}
	this->cannon = Cannon("Cannon");
}
void Game::Update(){
	//Board board = Board();
		if(Input::getPressed("Escape")){
			std::cout << "Closing Program" << std::endl;
			exit(0);
			return;
		}
		if(Input::getPressed("r")){
			//board.initialize();
		}
}