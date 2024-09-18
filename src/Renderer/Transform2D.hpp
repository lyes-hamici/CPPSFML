#ifndef TRANSFORM2D_HEADER
#define TRANSFORM2D_HEADER
#include "../Core/Vector2.hpp"
class Transform2D{ //Basic form, no matrices
    public:
        Vector2 position;
        Vector2 scale;
        float angle;
};
#endif