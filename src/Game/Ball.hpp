#include "../Renderer/RenderObjects2D.hpp"
#include "../Physics/CircleCollider2D.hpp"
#include "../Core/Vector2.hpp"
#include "Entity.hpp"
class Ball : public Entity, RenderObject2D, CircleCollider2D{
    public:
        Vector2 velocity;
        //Override Entity functions
        //Override hit events
}