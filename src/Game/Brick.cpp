#include "Brick.hpp"
Brick::Brick(){}
void Brick::Start(){
    this->imageName = "ToughGreen";
    this->bounds.minimums = this->position;
    this->bounds.maximums = this->position + this->scale;
}
void Brick::OnHitEnter(Hit hitInfo){
    if(this->health < 1){return;}
    this->health = std::max(0,this->health - 1);
}