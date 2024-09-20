#ifndef CIRCLECOLLIDER2D_HEADER
#define CIRCLECOLLIDER2D_HEADER
#include "Collider2D.hpp"
class CircleCollider2D : public Collider2D{
    public:
        float radius;
        void OnHitEnter(Hit hit) override; //Hit stores collision info
        void OnHitStay(Hit hit) override; //May not be needed
        void OnHitExit(Hit hit) override; //May not be needed
        void OnOverlapEnter(Collider2D other) override; //May not be needed
        void OnOverlapStay(Collider2D other) override; //May not be needed
        void OnOverlapExit(Collider2D other) override; //May not be needed
};
#endif