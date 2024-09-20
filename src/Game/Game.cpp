#include <chrono>
#include <filesystem>
#include "../Input/Input.hpp"
#include "Game.hpp"
#include "File.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include "Cannon.hpp"

Ball balls[10];
Cannon cannon;
std::string Game::levelsPath;
std::vector<Level> Game::levels;
void Game::Start(){
	Game::levelsPath = "Levels/";
	for(auto& file : std::filesystem::directory_iterator(this->levelsPath)){
		auto level = Level();
		auto path = file.path().string();
		if(!level.LoadFromFile(file.path().string())){continue;}
		this->levels.push_back(level);
	}
	cannon.Start();
	for(auto ball : balls){
		ball.Start();
	}
	this->levels[current_level].Setup();
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

	if (this->levels[current_level].bricks.empty())
	{
		// check click
		if (Input::getPressed("LeftClick"))
		{
			this-> current_level++;
			this->levels[current_level].Setup();
		}
		
	}
	

	cannon.Update();
	for(auto ball : balls){
		ball.Update();
	}

	for (auto brick : this->levels[current_level].bricks)
	{
		brick.Update();
	}
	
}