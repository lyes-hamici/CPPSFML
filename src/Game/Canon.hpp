#include "Entity.hpp"
#include "../Renderer/RenderObjects2D.hpp"
class Canon : public Entity, RenderObject2D{
    public:
        float turnSpeed; //Keyboard only
        //Override Entity functions
};