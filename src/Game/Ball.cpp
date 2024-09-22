#include "Ball.hpp"
#include "GameManager.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>
#include "../Input/Input.hpp"
Ball::Ball(){}
void Ball::Start(){
	auto resolution = Renderer::getResolution();
	this->position.Set(0,9999999999999999);
	this->scale.Set(35,35);
	this->imageName = "Ball";
}
void Ball::Update(){
	auto resolution = Renderer::getResolution();
	auto thickness = this->scale / 2;
	if(this->position.y - thickness.y > resolution.y){
		this->position.Set(0,9999999999999999);
		this->velocity.Clear();
		return;
	}
	if(Input::getPressed("Space")){
		this->velocity.y = -std::fabs(this->velocity.y);
	}
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
void Ball::OnHitEnter(Hit hit){
	auto absolute = hit.direction.Absolute();
	auto directionAxis = absolute.x > absolute.y ? hit.direction.x : hit.direction.y;
	auto& velocityAxis = absolute.x > absolute.y ? this->velocity.x : this->velocity.y;
	velocityAxis = directionAxis > 0 && velocityAxis < 0 || directionAxis < 0 && velocityAxis > 0 ? velocityAxis : -velocityAxis;
}