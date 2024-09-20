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
	this->cooldown = 0.25f;
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
		auto now = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::duration<float>>(now - this->lastShot).count();
		if(elapsed < this->cooldown){return;}
		for(auto& ball : this->ballPool){
			auto thickness = ball.scale / 2;
			if(ball.position.y < screenHeight + thickness.y){continue;}
			ball.position = this->position;
			ball.velocity = Input::GetCursorPosition(true) - this->position;
			ball.velocity = ball.velocity.Normalize();
			break;
		}
		this->lastShot = now;
	}
	this->angle = std::clamp(this->angle,-65.0f,65.0f);
}