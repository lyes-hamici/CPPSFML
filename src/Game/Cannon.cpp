#include "Cannon.hpp"
#include "GameManager.hpp"
#include "Game.hpp"
#include "../Input/Input.hpp"
#include "../Renderer/Renderer.hpp"
void Cannon::SetEnabled(bool enabled){
	auto& renderManager = GameManager::activeRenderObjects;
	Entity::SetEnabled(enabled);
	if(enabled && !renderManager.contains(*this)){
		renderManager.emplace(*this);
	}
	else{
		renderManager.erase(*this);
	}
}
void Cannon::Start(){
	Entity::Start();
	auto resolution = Renderer::getResolution();
	this->position = Vector2(resolution.x / 2,resolution.y + 20);
	this->imageName = "CannonNose";
}
void Cannon::Update(){
	Entity::Update();
	if(Input::getPressed("Left")){
		
	}
	else if(Input::getPressed("Right")){
		
	}
}