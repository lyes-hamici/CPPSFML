#ifndef BOXCOLLIDER2D_HEADER
#define BOXCOLLIDER2D_HEADER
#include "../Core/Vector2.hpp"
#include "Collider2D.hpp"
#include "Bounds2D.hpp"
class BoxCollider2D : public Collider2D{
    public:
        Vector2 size; //Property; will affect bounds
        Bounds2D bounds;
        void OnHitEnter(Hit hit) override; //Hit stores collision info
        void OnHitStay(Hit hit) override; //May not be needed
        void OnHitExit(Hit hit) override; //May not be needed
        void OnOverlapEnter(Collider2D other) override; //May not be needed
        void OnOverlapStay(Collider2D other) override; //May not be needed
        void OnOverlapExit(Collider2D other) override; //May not be needed
};
#endif