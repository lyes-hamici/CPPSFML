#ifndef HIT_HEADER
#define HIT_HEADER
#include "../Core/Vector2.hpp"
//#include "Collider2D.hpp"
struct Hit{
    public:
        Vector2 direction;
        //Collider2D other; //Will cause circular dependency. Needs to be fixed.
};
#endif