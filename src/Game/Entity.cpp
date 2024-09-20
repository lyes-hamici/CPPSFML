#include <iostream>
#include "Entity.hpp"
int Entity::count;
std::map<std::string,Entity> Entity::all;
Entity::Entity(){
    this->name = "Entity"+std::to_string(Entity::count);
    Entity::count += 1;
    this->Start();
}
Entity::Entity(std::string name){
    this->name = name;
    if(Entity::all.contains(this->name)){
        std::cout << "[Entity::Entity()] Warning: an entity with the same name already exists. This is undefined behavior." << std::endl;
    }
}
Entity::~Entity(){this->SetEnabled(false);}
void Entity::SetEnabled(bool enabled){
    auto& manager = Entity::all;
    if(enabled && !manager.contains(this->name)){manager[this->name] = *this;}
    else{manager.erase(this->name);}
}
bool Entity::IsEnabled(){return Entity::all.contains(this->name);}
void Entity::Start(){}
void Entity::Update(){}