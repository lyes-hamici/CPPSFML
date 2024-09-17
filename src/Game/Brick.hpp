#include "Entity.hpp"
#include "../Renderer/RenderObjects2D.hpp"
#include "../Physics/BoxCollider2D.hpp"
class Brick : public Entity, RenderObject2D, BoxCollider2D{
    public:
        int health;
        //Override Entity functions
        //Override hit events
};