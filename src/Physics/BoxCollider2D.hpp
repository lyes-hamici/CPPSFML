#ifndef BOXCOLLIDER2D_HEADER
#define BOXCOLLIDER2D_HEADER
#include "../Core/Vector2.hpp"
#include "Collider2D.hpp"
#include "Bounds2D.hpp"
class BoxCollider2D : public Collider2D{
    public:
        Vector2 size; //Property; will affect bounds
        Bounds2D bounds;
};
#endif