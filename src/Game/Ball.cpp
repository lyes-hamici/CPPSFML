#include "Ball.hpp"
#include "GameManager.hpp"
#include <algorithm>
#include <iostream>
Ball::Ball(){}
void Ball::Start(){
	auto resolution = Renderer::getResolution();
	this->position = Vector2(resolution.x / 2,resolution.y + 100);
	this->scale = Vector2(35,35);
	this->imageName = "Ball";
}
void Ball::Update(){
	auto resolution = Renderer::getResolution();
	auto thickness = this->scale / 2;
	if(this->position.y - thickness.y > resolution.y){return;}
	this->position = this->position + (this->velocity * 1000 * GameManager::deltaTime);
	if(this->position.x + thickness.x > resolution.x){
		this->velocity.x = -this->velocity.x;
	}
	else if(this->position.x - thickness.x < 0){
		this->velocity.x = -this->velocity.x;
	}
	else if(this->position.y - thickness.y < 0){
		this->velocity.y = -this->velocity.y;
	}
	this->position.x = std::clamp(this->position.x,0 + thickness.x,resolution.x - thickness.x);
	this->position.y = std::max(0 + thickness.y,this->position.y);
}
void Ball::SetEnabled(bool enabled){}