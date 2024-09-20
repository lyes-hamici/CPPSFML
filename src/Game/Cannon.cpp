#include "Cannon.hpp"
#include "../Input/Input.hpp"
#include "GameManager.hpp"
#include <algorithm>
//void Cannon::SetEnabled(bool enabled){
//	auto& renderManager = RenderObject2D::all;
//	Entity::SetEnabled(enabled);
//	if(enabled && !renderManager.contains(this->name)){
//		renderManager[this->name] = *this;
//	}
//	else{
//		renderManager.erase(this->name);
//	}
//}

Cannon::Cannon(){}

void Cannon::Start(){
	//Entity::Start();
	auto resolution = Renderer::getResolution();
	this->position = Vector2(resolution.x / 2,resolution.y - 20);
	this->scale.Set(100,100);
	this->imageName = "CannonNose";
	for(auto& ball : this->ballPool){
		ball.Start();
	}
}
void Cannon::Update(){
	//Entity::Update();
	if(Input::getHeld("Left")){
		this->angle -= 100 * GameManager::deltaTime;
	}
	else if(Input::getHeld("Right")){
		this->angle += 100 * GameManager::deltaTime;
	}
	else{
		auto direction = Input::GetCursorPosition(true) - this->position;
		this->angle = Vector2::SignedAngle(Vector2(0,-1),direction.Normalize());
	}
	if(Input::getPressed("LeftClick")){
		auto screenHeight = Renderer::getResolution().y;
		for(auto& ball : this->ballPool){
			if(ball.position.y < screenHeight + 20){continue;}
			ball.position = this->position;
			ball.velocity = Input::GetCursorPosition(true) - this->position;
			ball.velocity = ball.velocity.Normalize();
		}
	}
	this->angle = std::clamp(this->angle,-65.0f,65.0f);
}