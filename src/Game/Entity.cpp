#include "Entity.hpp"
#include "GameManager.hpp"
Entity::Entity(){this->Start();}
Entity::~Entity(){this->SetEnabled(false);}
void Entity::SetEnabled(bool enabled){
    auto& manager = GameManager::activeEntities;
    if(enabled && !manager.contains(*this)){manager.emplace(*this);}
    else{manager.erase(*this);}
}
bool Entity::IsEnabled(){return GameManager::activeEntities.contains(*this);}