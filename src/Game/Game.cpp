#include <chrono>
#include <filesystem>
#include <cmath>
#include "../Input/Input.hpp"
#include "Game.hpp"
#include "GameManager.hpp"
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
	for(auto& file : std::filesystem::directory_iterator(Game::levelsPath)){
		auto path = file.path().string();
		auto level = Level();
		if(!level.LoadFromFile(file.path().string())){continue;}
		Game::levels.push_back(level);
	}
	cannon.Start();
	if(Game::levels.size() < 1){
		exit(0);
	}
	Game::levels[0].Start();
}
void Game::Update(){
	auto& currentLevel = Game::levels[this->current_level];
	if(Input::getPressed("Escape")){
		std::cout << "Closing Program" << std::endl;
		exit(0);
		return;
	}
	if(Input::getPressed("r")){
		if(this->current_level < Game::levels.size()){
			currentLevel.Start();
		}
		cannon.Start();
	}
	currentLevel.Update();
	if(currentLevel.empty){
		auto message = this->current_level + 1 >= Game::levels.size() ? "Congratulations! Click or press R to restart the game!" : "Level finished! Click to start the next level!";
		if(Input::getPressed("LeftClick")){
			this->current_level = (this->current_level + 1) % Game::levels.size();
			Game::levels[this->current_level].Start();
			return;
		}
		Renderer::drawText(message,"arial",20,Renderer::getResolution() / 2);
	}
	//Script updates
	cannon.Update();
	for(auto& ball : cannon.ballPool){
		ball.Update();
	}
	//Physics updates
	for(auto& ball : cannon.ballPool){
		auto radius = ball.scale.x / 2;
		//Circle to Box
		for(auto& brick : currentLevel.bricks){
			if(brick.health < 1){continue;}
			auto nearest = ball.position.Clamp(brick.bounds.minimums,brick.bounds.maximums);
			auto nearestDirection = nearest - ball.position;
			auto overlap = radius - nearestDirection.Magnitude();
			if(std::isnan(overlap)){overlap = 0;}
			if(overlap <= 0){continue;}
			auto hit = Hit();
			hit.direction = nearestDirection.Normalize();
			//hit.other = brick; //Uncomment when some flavor of Collider2D is inherited by entities
			ball.position = ball.position - hit.direction * overlap;
			ball.OnHitEnter(hit);
			brick.OnHitEnter(Hit()); //Instance should be properly populated, but the content doesn't matter for this project.
		}
		//Circle to Circle
		for(auto& otherBall: cannon.ballPool){
			if(&ball == &otherBall){continue;}
			auto otherRadius = otherBall.scale.x / 2;
			if(ball.position.DistanceFrom(otherBall.position) < radius + otherRadius){
				auto hitA = Hit();
				auto hitB = Hit();
				hitA.direction = (otherBall.position - ball.position).Normalize();
				hitB.direction = (ball.position - otherBall.position).Normalize();
				//hitA.other = otherBall; //Uncomment when some flavor of Collider2D is inherited by entities
				//hitB.other = ball; //Uncomment when some flavor of Collider2D is inherited by entities
				ball.OnHitEnter(hitA);
				otherBall.OnHitEnter(hitB);
			}
		}
	}
	//Rendering updates
	auto baseTransform = Transform2D();
	baseTransform.position = cannon.position;
	baseTransform.scale = cannon.scale;
	for(auto& brick : currentLevel.bricks){
		if(brick.health < 1){continue;}
		Renderer::draw(brick.imageName,brick,Vector2(0,0));
	}
	for(auto& ball : cannon.ballPool){
		Renderer::draw(ball.imageName,ball,Vector2(0.5,0.5));
	}
	Renderer::draw(cannon.imageName,cannon,Vector2(0.45,1));
	Renderer::draw("CannonBase",baseTransform,Vector2(0.5,0.5));
}