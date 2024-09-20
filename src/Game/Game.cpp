#include <chrono>
#include <filesystem>
#include "../Input/Input.hpp"
#include "Game.hpp"
#include "File.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include "Cannon.hpp"
#include "../Renderer/Renderer.hpp"
Cannon cannon;
std::string Game::levelsPath;
std::vector<Level> Game::levels;
void Game::Start(){
	Game::levelsPath = "Levels/";
	for(auto& file : std::filesystem::directory_iterator(this->levelsPath)){
		auto path = file.path().string();
		auto level = Level();
		if(!level.LoadFromFile(file.path().string())){continue;}
		this->levels.push_back(level);
	}
	cannon.Start();
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
	if (this->levels[current_level].bricks.empty()){
		// check click
		if(Input::getPressed("LeftClick")){
			this-> current_level++;
			this->levels[current_level].Setup();
		}
	}
	cannon.Update();
	for(auto& ball : cannon.ballPool){
		ball.Update();
	}
	for (auto& brick : this->levels[current_level].bricks){
		brick.Update();
	}
	for (auto& brick : this->levels[current_level].bricks){
		Renderer::draw(brick.imageName,brick);
	}
	auto baseTransform = Transform2D();
	baseTransform.position = cannon.position;
	baseTransform.scale = cannon.scale;
	Renderer::draw(cannon.imageName,cannon,Vector2(0.45,1));
	Renderer::draw("CannonBase",baseTransform,Vector2(0.5,0.5));
	for(auto ball : cannon.ballPool){
		Renderer::draw(ball.imageName,ball,Vector2(0.5,0.5));
	}
}