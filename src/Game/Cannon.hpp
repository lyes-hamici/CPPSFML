#ifndef CANNON_HEADER
#define CANNON_HEADER
#include "Entity.hpp"
#include "../Renderer/RenderObjects2D.hpp"
class Cannon : public Entity, RenderObject2D{
    public:
        float turnSpeed; //Keyboard only
        //Override Entity functions
        void Start() override;
        void Update() override;
        void SetEnabled(bool enabled) override;
};
#endif