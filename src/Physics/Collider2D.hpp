#ifndef COLLIDER2D_HEADER
#define COLLIDER2D_HEADER
#include "Hit.hpp"
class Collider2D{
    public:
        bool colliderEnabled; //Property; may call events and perform changes
        bool isStatic;
        int layer; //Flags
        virtual void OnHitEnter(Hit hit); //Hit stores collision info
        virtual void OnHitStay(Hit hit); //May not be needed
        virtual void OnHitExit(Hit hit); //May not be needed
        virtual void OnOverlapEnter(Collider2D other); //May not be needed
        virtual void OnOverlapStay(Collider2D other); //May not be needed
        virtual void OnOverlapExit(Collider2D other); //May not be needed
};
#endif